/** @file

cktables.hpp

Semantic tables.

*/

#ifndef cktables_hpp_
#define cktables_hpp_

#include "ckir.hpp"

#include <memory>
#include <functional>
#include <type_traits>
#include <unordered_set>
#include <unordered_map>
#include <optional>

namespace cecko
{

	/// Line number in the compiled source file
	using loc_t = unsigned;

	class CIAbstractType;

	/// Pointer to a type descriptor (CIAbstractType)
	using CKTypeObs = const CIAbstractType *; // use something smarter for safety

	class CKVoidType;
	/// Safe pointer to a type descriptor (CIAbstractType)
	using CKTypeSafeObs = safe_ptr<const CIAbstractType, safe_default<const CKVoidType>>; // use something smarter for safety

	struct CKTypeRefPack;

	/// @cond INTERNAL
	template <typename... TL>
	inline std::size_t compute_hash(TL &&...l)
	{
		return (0 ^ ... ^ std::hash<std::remove_cv_t<std::remove_reference_t<TL>>>{}(std::forward<TL>(l)));
	}

	inline bool compute_equal()
	{
		return true;
	}

	template <typename TA, typename TB, typename... TL>
	inline bool compute_equal(TA &&a, TB &&b, TL &&...l)
	{
		return a == b && compute_equal(std::forward<TL>(l)...);
	}
	/// @endcond
}

/// @cond INTERNAL
template <>
class std::hash<cecko::CKIRAPInt>
{
public:
	std::size_t operator()(const cecko::CKIRAPInt &a) const
	{
		return cecko::CKHashValue(a);
	}
};

template <>
class std::hash<cecko::CKTypeObs>
{
public:
	std::size_t operator()(const cecko::CKTypeObs &a) const;
};

template <>
class std::hash<cecko::CKTypeRefPack>
{
public:
	std::size_t operator()(const cecko::CKTypeRefPack &a) const;
};
///  @endcond

namespace cecko
{
	// DUMP OSTREAM

	/// @cond INTERNAL
	using CIOStream = std::ostream;

	inline CIOStream &(*CIEndl)(CIOStream &) = &std::endl;

	// IMMOVABLE CLASS HELPER

	class CIImmovable
	{
	public:
		// COPYING AND MOVING DENIED
		CIImmovable() = default;
		CIImmovable(const CIImmovable &) = delete;
		CIImmovable(CIImmovable &&) = delete;
		CIImmovable &operator=(const CIImmovable &) = delete;
		CIImmovable &operator=(CIImmovable &&) = delete;
	};

	// HASHED STORAGE

	template <typename T>
	class CIHashedStorage : CIImmovable
	{
	public:
		template <typename... TL>
		const T *emplace(TL &&...l)
		{
			auto rv = data_.emplace(std::forward<TL>(l)...);
			return &*rv.first;
		}

		template <typename F>
		void for_each(F &&f) const
		{
			for (auto &&a : data_)
			{
				f(&a);
			}
		}

	private:
		struct hasher_t
		{
			std::size_t operator()(const T &a) const { return a.hash(); }
		};
		/*
			struct comparator_t {
				bool operator()(const T& a, const T& b) const { return a == b; }
			};
		*/
		using container_type_ = std::unordered_set<T, hasher_t>;
		container_type_ data_;
	};

	/// @endcond

	// NAMED STORAGE

	/// Identifier as represented in the attribute of a IDF/TYPEIDF token
	using CIName = std::string;

	/// @cond INTERNAL

	template <typename T>
	class CINamedStorage : CIImmovable
	{
	public:
		template <typename... TL>
		T *try_emplace(const CIName &n, TL &&...l)
		{
			auto rv = data_.try_emplace(n, std::forward<TL>(l)...);
			rv.first->second.set_name_ptr(&rv.first->first);
			return &rv.first->second;
		}

		T *find(const CIName &n)
		{
			auto it = data_.find(n);
			return it == data_.end() ? nullptr : &it->second;
		}

		const T *find(const CIName &n) const
		{
			auto it = data_.find(n);
			return it == data_.end() ? nullptr : &it->second;
		}

		template <typename F>
		void for_each(F &&f) const
		{
			using container_pair_obs = const std::pair<const CIName, T> *;
			auto pair_less = [](auto a, auto b)
			{
				return a->first < b->first;
			};
			using ordering_set = std::vector<container_pair_obs>;
			ordering_set os(data_.size(), nullptr);
			std::transform(data_.begin(), data_.end(), os.begin(),
						   [](auto &&a)
						   {
							   return &a;
						   });
			std::sort(os.begin(), os.end(), pair_less);
			for (auto &&p : os)
			{
				f(&p->second);
			}
		}

	private:
		using container_type_ = std::unordered_map<CIName, T>;
		container_type_ data_;
	};
	/// @endcond

	/// The common base for all named objects
	class CINamePtr
	{
	public:
		/// @cond INTERNAL
		CINamePtr(loc_t def_loc)
			: name_ptr_(nullptr), def_loc_(def_loc)
		{
		}
		/// @endcond

		/// The name of the object
		const CIName &get_name() const
		{
			assert(!!name_ptr_);
			return *name_ptr_;
		}
		/// @cond INTERNAL
		std::string get_dump_name() const;
		void set_def_loc(loc_t def_loc) { def_loc_ = def_loc; }
		/// @endcond
	private:
		void set_name_ptr(const CIName *p)
		{
			name_ptr_ = p;
		}

		const CIName *name_ptr_;
		loc_t def_loc_;

		template <typename T>
		friend class CINamedStorage;
	};

	// MANGLER

	/// @cond INTERNAL
	using CITypeMangle = std::string;

	using CIDecl = std::string;
	/// @endcond

	// TYPES

	class CKStructElement;

	/// Pointer to a struct element descriptor (CKStructElement)
	using CKStructElementObs = const CKStructElement *;
	/// Safe pointer to a struct element descriptor (CKStructElement)
	using CKStructElementSafeObs = safe_ptr<const CKStructElement>;

	/// Type descriptor with optional "const" flag
	struct CKTypeRefPack
	{

		/// Construct as null
		CKTypeRefPack()
			: type(nullptr), is_const(false)
		{
		}

		/// Construct from the arguments
		CKTypeRefPack(CKTypeObs t, bool is_c)
			: type(t), is_const(is_c)
		{
		}
		CKTypeObs type; ///< The type
		bool is_const;	///< Indicates the presence of the *const* flag
	};

	/// Type descriptor with optional "const" flag
	struct CKTypeRefSafePack
	{

		/// Construct as null
		CKTypeRefSafePack()
			: type(nullptr), is_const(false)
		{
		}

		/// Construct from the arguments
		CKTypeRefSafePack(CKTypeObs t, bool is_c)
			: type(t), is_const(is_c)
		{
		}
		/// Convert from unsafe pack
		explicit CKTypeRefSafePack(const CKTypeRefPack &tp)
			: type(tp.type), is_const(tp.is_const)
		{
		}
		/// Convert to unsafe pack
		operator CKTypeRefPack() const
		{
			return CKTypeRefPack(type, is_const);
		}
		CKTypeSafeObs type; ///< The type
		bool is_const;		///< Indicates the presence of the *const* flag
	};

	/// Abstract type descriptor
	class CIAbstractType : CIImmovable
	{
	public:
		/// @cond INTERNAL
		virtual ~CIAbstractType() {}
		virtual std::size_t hash() const = 0;
		/// @endcond

		/// Get LLVM type descriptor
		virtual CKIRTypeObs get_ir() const = 0;

		/// Get LLVM null value
		virtual CKIRConstantObs get_null_value() const;

		/// @name Determining the kind of the type
		/// @{

		virtual bool is_void() const { return false; }	   ///< Built-in "void" type
		virtual bool is_bool() const { return false; }	   ///< Built-in "_Bool" type
		virtual bool is_char() const { return false; }	   ///< Built-in "char" type
		virtual bool is_int() const { return false; }	   ///< Built-in "int" type
		virtual bool is_enum() const { return false; }	   ///< Enumeration type
		virtual bool is_array() const { return false; }	   ///< Array type
		virtual bool is_function() const { return false; } ///< Function type
		virtual bool is_pointer() const { return false; }  ///< Pointer type
		virtual bool is_struct() const { return false; }   ///< Struct type
		/// @}

		/// @name Pointer properties
		/// @{

		/// The (optionally const) type a pointer type points to
		virtual CKTypeRefSafePack get_pointer_points_to() const
		{
			assert(0);
			return {nullptr, false};
		}
		/// @}

		/// @name Function properties
		/// @{

		/// The return type of a function type
		virtual CKTypeSafeObs get_function_return_type() const
		{
			assert(0);
			return nullptr;
		}
		/// The selected argument type of a function type
		virtual CKTypeSafeObs get_function_arg_type(std::size_t ix) const { return nullptr; }
		/// The number of arguments of a function type
		virtual std::size_t get_function_arg_count() const { return 0; }
		/// Check whether a function type is variadic
		virtual bool is_function_variadic() const { return false; }
		/// @}

		/// @name Array properties
		/// @{

		/// The element type of an array
		virtual CKTypeSafeObs get_array_element_type() const
		{
			assert(0);
			return nullptr;
		}
		/// The size of an array
		virtual CKIRConstantIntObs get_array_size() const
		{
			assert(0);
			return nullptr;
		}
		/// @}

		/// @name Struct properties
		/// @{

		/// Find a struct type element by name
		virtual CKStructElementSafeObs find_struct_element(const CIName &) const
		{
			assert(0);
			return nullptr;
		}
		/// @}

		/// @cond INTERNAL
		virtual CITypeMangle mangle() const = 0;
		virtual CIDecl declaration(bool is_const, const CIDecl &dtor = "") const = 0;
		/// @endcond
	};

	/// @cond INTERNAL
	inline bool operator==(const CKTypeRefPack &a, const CKTypeRefPack &b)
	{
		return compute_equal(a.type, b.type, a.is_const, b.is_const);
	}
	/// @endcond

	/// The built-in "void" type
	class CKVoidType : public CIAbstractType
	{
	public:
		/// @cond INTERNAL
		CKVoidType()
			: irt_(nullptr)
		{
		}
		CKVoidType(CKIRContextRef Context)
			: irt_(CKGetVoidType(Context))
		{
		}
		virtual std::size_t hash() const override { return 0; }
		virtual CKIRTypeObs get_ir() const override { return irt_; }
		virtual bool is_void() const override { return true; }
		virtual CITypeMangle mangle() const override { return "V"; }
		virtual CIDecl declaration(bool is_const, const CIDecl &dtor) const override;
		/// @endcond
	private:
		CKIRTypeObs irt_;
	};

	/// The built-in "_Bool" type
	class CKBoolType : public CIAbstractType
	{
	public:
		/// @cond INTERNAL
		CKBoolType()
			: irt_(nullptr)
		{
		}
		CKBoolType(CKIRContextRef Context)
			: irt_(CKGetInt1Type(Context))
		{
		}
		virtual std::size_t hash() const override { return 1; }
		virtual CKIRTypeObs get_ir() const override { return irt_; }
		virtual bool is_bool() const override { return true; }
		// virtual bool is_signed() const { return false; }
		virtual CITypeMangle mangle() const override { return "B"; }
		virtual CIDecl declaration(bool is_const, const CIDecl &dtor) const override;
		/// @endcond
	private:
		CKIRTypeObs irt_;
	};

	/// The built-in "char" type
	class CKCharType : public CIAbstractType
	{
	public:
		/// @cond INTERNAL
		CKCharType()
			: irt_(nullptr)
		{
		}
		CKCharType(CKIRContextRef Context)
			: irt_(CKGetInt8Type(Context))
		{
		}
		virtual std::size_t hash() const override { return 8; }
		virtual CKIRTypeObs get_ir() const override { return irt_; }
		virtual bool is_char() const override { return true; }
		// virtual bool is_signed() const { return false; }
		virtual CITypeMangle mangle() const override { return "X"; }
		virtual CIDecl declaration(bool is_const, const CIDecl &dtor) const override;
		/// @endcond
	private:
		CKIRTypeObs irt_;
	};

	/// The built-in "int" type
	class CKIntType : public CIAbstractType
	{
	public:
		/// @cond INTERNAL
		CKIntType()
			: irt_(nullptr)
		{
		}
		CKIntType(CKIRContextRef Context)
			: irt_(CKGetInt32Type(Context))
		{
		}
		virtual std::size_t hash() const override { return 32; }
		virtual CKIRTypeObs get_ir() const override { return irt_; }
		virtual bool is_int() const override { return true; }
		// virtual bool is_signed() const override { return true; }
		virtual CITypeMangle mangle() const override { return "I"; }
		virtual CIDecl declaration(bool is_const, const CIDecl &dtor) const override;
		/// @endcond
	private:
		CKIRTypeObs irt_;
	};

	/// Pointer type descriptor
	class CKPtrType : public CIAbstractType
	{
	public:
		/// @cond INTERNAL
		CKPtrType()
			: points_to_(nullptr, false), irt_(nullptr)
		{
		}

		explicit CKPtrType(const CKTypeRefPack &points_to)
			: points_to_(points_to), irt_(CKGetPtrType(points_to.type->get_ir()->getContext()))
		{
		}

		virtual std::size_t hash() const override { return compute_hash(points_to_); }
		virtual CKIRTypeObs get_ir() const override { return irt_; }
		bool operator==(const CKPtrType &b) const
		{
			return compute_equal(points_to_, b.points_to_);
		}

		virtual bool is_pointer() const override { return true; }
		virtual CKTypeRefSafePack get_pointer_points_to() const override { return CKTypeRefSafePack(points_to_); }

		virtual CITypeMangle mangle() const override { return (points_to_.is_const ? "pc" : "p") + points_to_.type->mangle(); }
		virtual CIDecl declaration(bool is_const, const CIDecl &dtor) const override;
		/// @endcond
	private:
		CKTypeRefPack points_to_;
		CKIRTypeObs irt_;
	};

	/// Array type descriptor
	class CKArrayType : public CIAbstractType
	{
	public:
		/// @cond INTERNAL
		CKArrayType()
			: element_type_(nullptr), size_(nullptr), irt_(nullptr)
		{
		}
		CKArrayType(CKTypeObs element_type, CKIRConstantIntObs size)
			: element_type_(element_type), size_(size), irt_(CKGetArrayType(element_type->get_ir(), size))
		{
		}

		virtual std::size_t hash() const override { return compute_hash(element_type_, size_->getValue()); }
		virtual CKIRTypeObs get_ir() const override { return irt_; }
		bool operator==(const CKArrayType &b) const
		{
			return compute_equal(element_type_, b.element_type_, size_->getValue(), b.size_->getValue());
		}

		virtual bool is_array() const override { return true; }
		virtual CKTypeSafeObs get_array_element_type() const override { return CKTypeSafeObs(element_type_); }
		virtual CKIRConstantIntObs get_array_size() const override { return size_; }

		virtual CITypeMangle mangle() const override { return "a" + std::to_string(size_->getValue().getZExtValue()) + element_type_->mangle(); }
		virtual CIDecl declaration(bool is_const, const CIDecl &dtor) const override;
		/// @endcond
	private:
		CKTypeObs element_type_;
		CKIRConstantIntObs size_;
		CKIRTypeObs irt_;
	};

	/// Struct element descriptor
	class CKStructElement : public CINamePtr, CIImmovable
	{
	public:
		/// @cond INTERNAL
		explicit CKStructElement()
			: CINamePtr(0), pack_(nullptr, false), idx_(0)
		{
		}
		explicit CKStructElement(const CKTypeRefPack &pack, unsigned int idx, loc_t def_loc)
			: CINamePtr(def_loc), pack_(pack), idx_(idx)
		{
		}
		/// @endcond
		/// The (optionally const) type of a struct element
		const CKTypeRefPack &get_type_pack() const { return pack_; }
		/// LLVM index of a struct element
		unsigned int get_idx() const { return idx_; }

	private:
		CKTypeRefPack pack_;
		unsigned int idx_;
	};

	using CKStructElementObs = const CKStructElement *;

	/// Temporary struct element descriptor
	struct CKStructItem
	{
		/// Construct from arguments
		CKStructItem(const CKTypeRefPack &p, CIName nm, loc_t l)
			: pack(p), name(std::move(nm)), loc(l)
		{
		}
		/// The (optionally const) type of a struct element
		CKTypeRefPack pack;
		/// Name of a struct element
		CIName name;
		/// Definition line number
		loc_t loc;
	};

	/// A temporary array of struct element descriptors (CKStructItem)
	using CKStructItemArray = std::vector<CKStructItem>;

	/// Struct type descriptor
	class CKStructType : public CIAbstractType, public CINamePtr
	{
	public:
		/// @cond INTERNAL
		CKStructType()
			: CINamePtr(0), decl_loc_(0), defined_(false), irt_(nullptr)
		{
		}
		CKStructType(CKIRContextRef Context, const CIName &n, loc_t decl_loc)
			: CINamePtr(0), decl_loc_(decl_loc), defined_(false), irt_(CKCreateStructType(Context, n))
		{
		}
		void finalize(const CKStructItemArray &items);

		virtual std::size_t hash() const override { return std::hash<CIName>{}(get_name()); }
		virtual CKIRTypeObs get_ir() const override { return irt_; }
		virtual bool is_struct() const override { return true; }
		/// @endcond

		/// Check whether the struct type is already defined
		bool is_defined() const { return defined_; }

		/// @cond INTERNAL
		virtual CKStructElementSafeObs find_struct_element(const CIName &n) const override
		{
			assert(defined_);
			return CKStructElementSafeObs(elements_.find(n));
		}

		virtual CITypeMangle mangle() const override { return "S" + get_name() + '$'; }
		virtual CIDecl declaration(bool is_const, const CIDecl &dtor) const override;
		void dump(CIOStream &os, const std::string &indent) const;
		/// @endcond
	private:
		using element_storage_type = CINamedStorage<CKStructElement>;
		loc_t decl_loc_;
		bool defined_;
		element_storage_type elements_;
		std::vector<CKStructElementObs> elements_ordered_;
		CKIRStructTypeObs irt_;
	};

	class CKConstant;

	/// Pointer to an enumeration constant descriptor (CKConstant)
	using CKConstantConstObs = const CKConstant *;
	/// Safe pointer to an enumeration constant descriptor (CKConstant)
	using CKConstantConstSafeObs = safe_ptr<const CKConstant>;

	/// Temporary vector of enumeration constant descriptors (CKConstantConstObs)
	using CKConstantObsVector = std::vector<CKConstantConstObs>;

	/// Enumeration type descriptor
	class CKEnumType : public CIAbstractType, public CINamePtr
	{
	public:
		/// @cond INTERNAL
		CKEnumType()
			: CINamePtr(0), decl_loc_(0), defined_(false), base_type_(nullptr)
		{
		}
		CKEnumType(CKTypeObs base_type, loc_t decl_loc)
			: CINamePtr(0), decl_loc_(decl_loc), defined_(false), base_type_(base_type)
		{
		}
		void finalize(CKConstantObsVector items);

		virtual std::size_t hash() const override { return std::hash<CIName>{}(get_name()); }
		virtual bool is_enum() const override { return true; }
		/// @endcond

		/// Check whether the type is already defined
		bool is_defined() const { return defined_; }

		/// @cond INTERNAL
		virtual CITypeMangle mangle() const override { return "E" + get_name() + '$'; }
		virtual CIDecl declaration(bool is_const, const CIDecl &dtor) const override;
		virtual CKIRTypeObs get_ir() const override { return base_type_->get_ir(); }
		void dump(CIOStream &os, const std::string &indent) const;
		/// @endcond
	private:
		loc_t decl_loc_;
		bool defined_;
		CKTypeObs base_type_;
		CKConstantObsVector elements_ordered_;
	};

	/// Array of (function argument) type descriptors (CKTypeObs)
	using CKTypeObsArray = std::vector<CKTypeObs>;

	/// Function type descriptor
	class CKFunctionType : public CIAbstractType
	{
	public:
		/// @cond INTERNAL
		CKFunctionType()
			: ret_type_(nullptr), variadic_(false), irt_(nullptr)
		{
		}
		CKFunctionType(CKTypeObs ret_type, CKTypeObsArray arg_types, bool variadic = false);

		bool operator==(const CKFunctionType &b) const;

		virtual std::size_t hash() const override;

		virtual CKIRTypeObs get_ir() const override { return irt_; }
		CKIRFunctionTypeObs get_function_ir() const { return irt_; }
		virtual bool is_function() const override { return true; }
		virtual CKTypeSafeObs get_function_return_type() const override { return CKTypeSafeObs(ret_type_); }
		virtual CKTypeSafeObs get_function_arg_type(std::size_t ix) const override { return CKTypeSafeObs(arg_types_[ix]); }
		virtual std::size_t get_function_arg_count() const override { return arg_types_.size(); }
		virtual bool is_function_variadic() const override { return variadic_; }

		virtual CITypeMangle mangle() const override;
		virtual CIDecl declaration(bool is_const, const CIDecl &dtor) const override;
		/// @endcond
	private:
		CKTypeObs ret_type_;
		CKTypeObsArray arg_types_;
		bool variadic_;
		CKIRFunctionTypeObs irt_;
	};

	/// Built-in "void" type descriptor (CKVoidType)
	using CKVoidTypeObs = const CKVoidType *;
	/// Built-in "void" type descriptor (CKVoidType)
	using CKVoidTypeSafeObs = safe_ptr<const CKVoidType>;
	/// Built-in "_Bool" type descriptor (CKBoolType)
	using CKBoolTypeObs = const CKBoolType *;
	/// Built-in "_Bool" type descriptor (CKBoolType)
	using CKBoolTypeSafeObs = safe_ptr<const CKBoolType>;
	/// Built-in "char" type descriptor (CKCharType)
	using CKCharTypeObs = const CKCharType *;
	/// Built-in "char" type descriptor (CKCharType)
	using CKCharTypeSafeObs = safe_ptr<const CKCharType>;
	/// Built-in "int" type descriptor (CKIntType)
	using CKIntTypeObs = const CKIntType *;
	/// Built-in "int" type descriptor (CKIntType)
	using CKIntTypeSafeObs = safe_ptr<const CKIntType>;
	/// @cond INTERNAL
	using CKPtrTypeObs = const CKPtrType *;
	using CKArrayTypeObs = const CKArrayType *;
	/// @endcond
	/// Pointer type descriptor (CKPtrType)
	using CKPtrTypeSafeObs = safe_ptr<const CKPtrType>;
	/// Array type descriptor (CKArrayType)
	using CKArrayTypeSafeObs = safe_ptr<const CKArrayType>;
	/// Function type descriptor (CKFunctionType)
	using CKFunctionTypeObs = const CKFunctionType *;
	/// Function type descriptor (CKFunctionType)
	using CKFunctionTypeSafeObs = safe_ptr<const CKFunctionType>;
	/// Struct type descriptor (CKStructType)
	using CKStructTypeObs = CKStructType *;
	/// Struct type descriptor (CKStructType)
	using CKStructTypeSafeObs = safe_ptr<CKStructType>;
	/// Enumeration type descriptor (CKEnumType)
	using CKEnumTypeObs = CKEnumType *;
	/// Enumeration type descriptor (CKEnumType)
	using CKEnumTypeSafeObs = safe_ptr<CKEnumType>;

	/// @cond INTERNAL
	class CKTypeTable : CIImmovable
	{
	public:
		CKTypeTable(CKIRContextRef Context)
			: voit_(Context), boot_(Context), chrt_(Context), intt_(Context)
		{
		}
		CKVoidTypeObs get_void_type() const { return &voit_; }
		CKBoolTypeObs get_bool_type() const { return &boot_; }
		CKCharTypeObs get_char_type() const { return &chrt_; }
		CKIntTypeObs get_int_type() const { return &intt_; }
		CKPtrTypeObs get_pointer_type(const CKTypeRefPack &pack) { return ptrts_.emplace(pack); }
		CKArrayTypeObs get_array_type(CKTypeObs element_type, CKIRConstantIntObs size) { return arrts_.emplace(element_type, size); }
		CKFunctionTypeObs get_function_type(CKTypeObs ret_type, CKTypeObsArray arg_types, bool variadic = false) { return fncts_.emplace(ret_type, std::move(arg_types), variadic); }
		void dump(CIOStream &os) const;

	private:
		CKVoidType voit_;
		CKBoolType boot_;
		CKCharType chrt_;
		CKIntType intt_;
		CIHashedStorage<CKPtrType> ptrts_;
		CIHashedStorage<CKArrayType> arrts_;
		CIHashedStorage<CKFunctionType> fncts_;
	};
	/// @endcond

	/// Abstract named-object (constant, variable, or function) descriptor
	class CKAbstractNamed : public CINamePtr, CIImmovable
	{
	public:
		/// @cond INTERNAL
		CKAbstractNamed(loc_t def_loc)
			: CINamePtr(def_loc)
		{
		}
		virtual ~CKAbstractNamed() {}
		/// @endcond
		/// @name Determining the kind of the object
		/// @{
		// virtual bool is_typedef() const { return false; }

		/// Global or local variable
		virtual bool is_var() const { return false; }
		/// Function
		virtual bool is_function() const { return false; }
		/// Enumeration constant
		virtual bool is_constant() const { return false; }
		/// @}

		/// @name Object type
		/// @{

		/// Type of the named object
		virtual CKTypeSafeObs get_type() const = 0;
		/// Optional "const" flag on a variable
		virtual bool is_const() const { return false; }
		/// @}

		/// @name Object representation in LLVM IR
		/// @{

		/// The address of a variable, the value of a constant
		virtual CKIRValueObs get_ir() const { return nullptr; };
		/// The address of a function
		virtual CKIRFunctionObs get_function_ir() const { return nullptr; };
		/// @}
	};

	/// Pointer to a named-object (constant, variable, or function) descriptor (CKAbstractNamed)
	using CKNamedObs = CKAbstractNamed *;
	/// Safe pointer to a named-object (constant, variable, or function) descriptor (CKAbstractNamed)
	using CKNamedSafeObs = safe_ptr<CKAbstractNamed, safe_default<CKConstant>>;

	/// Typedef descriptor
	class CKTypedef : public CINamePtr, CIImmovable
	{
	public:
		/// @cond INTERNAL
		CKTypedef()
			: CINamePtr(0), type_pack_(nullptr, false)
		{
		}
		CKTypedef(CKTypeRefPack type_pack, loc_t def_loc)
			: CINamePtr(def_loc), type_pack_(type_pack)
		{
		}
		/// @endcond
		// virtual bool is_typedef() const { return true; }
		// CKTypeObs get_type() const { return type_pack_.type; }
		// bool is_const() const { return type_pack_.is_const; }

		/// The type and the optional "const" represented by the typedef
		CKTypeRefSafePack get_type_pack() const { return CKTypeRefSafePack(type_pack_); }

		/// @cond INTERNAL
		void dump(CIOStream &os) const;
		/// @endcond
	private:
		CKTypeRefPack type_pack_;
	};

	/// Typedef descriptor (CKTypedef)
	using CKTypedefConstObs = const CKTypedef *;
	/// Typedef descriptor (CKTypedef)
	using CKTypedefConstSafeObs = safe_ptr<const CKTypedef>;

	/// Enumeration constant descriptor
	class CKConstant : public CKAbstractNamed
	{
	public:
		/// @cond INTERNAL
		CKConstant()
			: CKAbstractNamed(0), type_pack_(nullptr, true), value_(nullptr)
		{
		}
		CKConstant(CKTypeObs type, CKIRConstantIntObs value, loc_t def_loc)
			: CKAbstractNamed(def_loc), type_pack_(type, true), value_(value)
		{
		}
		virtual bool is_constant() const override { return true; }
		virtual CKTypeSafeObs get_type() const override { return CKTypeSafeObs(type_pack_.type); }
		virtual bool is_const() const override { return type_pack_.is_const; }
		// const CKTypeRefPack& get_type_pack() const { return type_pack_; }
		/// @endcond

		/// LLVM value of the enumeration constant
		CKIRConstantIntObs get_constant_value() const { return value_; }
		/// @cond INTERNAL
		virtual CKIRValueObs get_ir() const override { return value_; }
		std::string declaration() const;
		/// @endcond
	private:
		CKTypeRefPack type_pack_;
		CKIRConstantIntObs value_;
	};

	/// Common base of variable descriptors
	class CKVar : public CKAbstractNamed
	{
	public:
		/// @cond INTERNAL
		CKVar(CKTypeRefPack type_pack, loc_t def_loc)
			: CKAbstractNamed(def_loc), type_pack_(type_pack)
		{
		}
		/// @endcond
		virtual bool is_var() const override { return true; }
		virtual CKTypeSafeObs get_type() const override { return CKTypeSafeObs(type_pack_.type); }
		virtual bool is_const() const override { return type_pack_.is_const; }
		// const CKTypeRefPack& get_type_pack() const { return type_pack_; }
		/// @cond INTERNAL
		void dump(CIOStream &os, const std::string &indent) const;
		/// @endcond
	private:
		CKTypeRefPack type_pack_;
	};

	/// Global variable descriptor
	class CKGlobalVar : public CKVar
	{
	public:
		/// @cond INTERNAL
		CKGlobalVar(CKTypeRefPack type_pack, CKIRConstantObs address, loc_t def_loc)
			: CKVar(type_pack, def_loc), address_(address)
		{
		}
		virtual CKIRValueObs get_ir() const override { return address_; }
		CKIRConstantObs get_address() const { return address_; }
		/// @endcond
	private:
		CKIRConstantObs address_;
	};

	/// @cond INTERNAL
	using CKGlobalVarObs = CKGlobalVar *;
	/// @endcond

	/// Optional (function argument) name
	using CINameOpt = std::optional<CIName>;

	/// Temporary additional function argument descriptor
	struct CKFunctionFormalPack
	{
		/// Construct from arguments
		CKFunctionFormalPack(CINameOpt nm, bool c, loc_t loc)
			: name(std::move(nm)), is_const(c), loc(loc)
		{
		}
		/// Optional name of the argument
		CINameOpt name;
		/// Optional "const" flag
		bool is_const;
		/// Definition line number
		loc_t loc;
	};

	/// @cond INTERNAL
	class CKLocalTable;

	using CKLocalTableOwner = std::unique_ptr<CKLocalTable>;
	using CKLocalTableObs = CKLocalTable *;

	class CKAbstractScope : CIImmovable
	{
	public:
		virtual ~CKAbstractScope() {}
		virtual CKStructTypeObs find_struct_type(const CIName &n) = 0;
		virtual CKEnumTypeObs find_enum_type(const CIName &n) = 0;
		virtual CKTypedefConstObs find_typedef(const CIName &n) const = 0;
		virtual CKNamedObs find(const CIName &n) = 0;
		virtual CKLocalTableObs get_local();
	};

	using CKAbstractScopeObs = CKAbstractScope *;
	/// @endcond

	/// Temporary array of additional function argument descriptors (CKFunctionFormalPack)
	using CKFunctionFormalPackArray = std::vector<CKFunctionFormalPack>;

	/// Function descriptor
	class CKFunction : public CKAbstractNamed
	{
	public:
		/// @cond INTERNAL
		CKFunction(CKIRModuleObs M, CKFunctionTypeObs type, const CIName &irname, loc_t def_loc)
			: CKAbstractNamed(def_loc), type_(type), irf_(CKCreateFunction(type->get_function_ir(), irname, M))
		{
		}
		virtual bool is_function() const override { return true; }

		/// Check whether the function is already defined
		bool is_defined() const { return !!loctab_; }

		virtual CKTypeSafeObs get_type() const override { return CKTypeSafeObs(type_); }
		CKFunctionTypeObs get_function_type() const { return type_; }
		virtual CKIRValueObs get_ir() const override { return irf_; }
		virtual CKIRFunctionObs get_function_ir() const override { return irf_; }
		const CKFunctionFormalPack &get_formal_pack(std::size_t ix) const { return formal_packs_[ix]; }
		CKLocalTableObs define(CKAbstractScopeObs parent, CKIRBuilderRef builder, CKFunctionFormalPackArray formal_packs);
		void dump(CIOStream &os) const;
		/// @endcond
	private:
		CKFunctionTypeObs type_;
		CKIRFunctionObs irf_;
		CKFunctionFormalPackArray formal_packs_;
		CKLocalTableOwner loctab_;
	};

	/// @cond INTERNAL
	class CKUniversalTable : public CKAbstractScope
	{
	public:
		CKStructTypeObs declare_struct_type_here(const CIName &n, CKIRContextRef Context, loc_t decl_loc)
		{
			return strts_.try_emplace(n, Context, n, decl_loc);
		}
		CKStructTypeObs find_struct_type_here(const CIName &n) { return strts_.find(n); }
		CKEnumTypeObs declare_enum_type_here(const CIName &n, CKTypeObs base_type, loc_t decl_loc)
		{
			return enmts_.try_emplace(n, base_type, decl_loc);
		}
		CKEnumTypeObs find_enum_type_here(const CIName &n) { return enmts_.find(n); }
		CKTypedefConstObs declare_typedef(const CIName &name, const CKTypeRefPack &type_pack, loc_t def_loc);
		CKConstantConstObs declare_constant(const CIName &name, CKTypeObs type, CKIRConstantIntObs value, loc_t def_loc);
		CKTypedefConstObs find_typedef_here(const CIName &n) const;
		CKNamedObs find_constant_here(const CIName &n);
		bool conflicting_tag_enum(const std::string &name);
		bool conflicting_tag_struct(const std::string &name);
		bool find_idf_here_universal(const CIName &n);
		void dump_universal(CIOStream &os, const std::string &indent) const;

	private:
		CINamedStorage<CKStructType> strts_;
		CINamedStorage<CKEnumType> enmts_;
		CINamedStorage<CKTypedef> typedefs_;
		CINamedStorage<CKConstant> constants_;
	};
	/// @endcond

	/// Function descriptor (CKFunction)
	using CKFunctionObs = CKFunction *;
	/// Function descriptor (CKFunction)
	using CKFunctionSafeObs = safe_ptr<CKFunction>;

	/// @cond INTERNAL
	using CKFunctionConstObs = const CKFunction *;

	class CKGlobalTable : public CKUniversalTable
	{
	public:
		CKGlobalTable()
		{
		}
		CKGlobalVarObs varDefine(CKIRModuleObs M, const CIName &name, const CKTypeRefPack &type_pack, loc_t def_loc);
		CKGlobalVarObs declare_extern_variable(CKIRModuleObs M, const CIName &name, const CKTypeRefPack &type_pack);
		CKStructTypeObs declare_struct_type(const CIName &n, CKIRContextRef Context, loc_t decl_loc)
		{
			return declare_struct_type_here(n, Context, decl_loc);
		}
		virtual CKStructTypeObs find_struct_type(const CIName &n) override { return find_struct_type_here(n); }
		CKEnumTypeObs declare_enum_type(const CIName &n, CKTypeObs base_type, loc_t decl_loc)
		{
			return declare_enum_type_here(n, base_type, decl_loc);
		}
		virtual CKEnumTypeObs find_enum_type(const CIName &n) override { return find_enum_type_here(n); }
		CKFunctionObs declare_function(const CIName &n, CKIRModuleObs M, CKFunctionTypeObs type, loc_t decl_loc);
		CKFunctionObs declare_function(const CIName &n, CKIRModuleObs M, CKFunctionTypeObs type, const CIName &irname);
		CKFunctionObs find_function(const CIName &n);
		CKFunctionConstObs find_function(const CIName &n) const;
		virtual CKTypedefConstObs find_typedef(const CIName &n) const override;
		virtual CKNamedObs find(const CIName &n) override;
		CKNamedObs find_here(const CIName &n);
		bool conflicting_idf(const CIName &n);
		bool conflicting_idf_function(const CIName &n, CKFunctionTypeObs type);

		void dump(CIOStream &os) const;

	private:
		CINamedStorage<CKFunction> fncs_;
		CINamedStorage<CKGlobalVar> vars_;
	};
	/// @endcond

	/// Local variable descriptor
	class CKLocalVar : public CKVar
	{
	public:
		/// @cond INTERNAL
		CKLocalVar(CKTypeRefPack type_pack, CKIRAllocaInstObs address, loc_t def_loc, bool is_arg)
			: CKVar(type_pack, def_loc), address_(address), is_arg_(is_arg)
		{
		}
		virtual CKIRValueObs get_ir() const override { return address_; }
		CKIRAllocaInstObs get_address() const { return address_; }
		bool is_arg() const { return is_arg_; }
		/// @endcond
	private:
		CKIRAllocaInstObs address_;
		bool is_arg_;
	};

	/// @cond INTERNAL
	using CKLocalVarObs = CKLocalVar *;

	class CKLocalTable : public CKUniversalTable
	{
	public:
		CKLocalTable(CKAbstractScopeObs parent)
			: parent_scope_(parent)
		{
		}

		CKStructTypeObs declare_struct_type(const CIName &n, CKIRContextRef Context, loc_t decl_loc);
		virtual CKStructTypeObs find_struct_type(const CIName &n) override;
		CKEnumTypeObs declare_enum_type(const CIName &n, CKTypeObs base_type, loc_t decl_loc);
		virtual CKEnumTypeObs find_enum_type(const CIName &n) override;

		void varsFromArgs(CKIRBuilderRef builder, CKFunctionObs f, const CKFunctionFormalPackArray &formal_packs);

		CKLocalVarObs varDefine(CKIRBuilderRef builder, const CIName &name, const CKTypeRefPack &type_pack, loc_t def_loc);

		virtual CKTypedefConstObs find_typedef(const CIName &n) const override;
		virtual CKNamedObs find(const CIName &n) override;
		CKNamedObs find_here(const CIName &n);
		bool conflicting_idf(const CIName &n);

		void dump(CIOStream &os, const std::string &indent) const;

		virtual CKLocalTableObs get_local() override;

		CKLocalTableObs create_block();
		CKLocalTableObs parent_block() const;

	private:
		CKAbstractScopeObs parent_scope_;
		CINamedStorage<CKLocalVar> vars_;
		std::vector<CKLocalTableOwner> block_scopes_;
	};
	/// @endcond

	// CONTEXT

	/// @cond INTERNAL
	using CKTypeTableObs = CKTypeTable *;
	using CKGlobalTableObs = CKGlobalTable *;
	using CKGlobalTableConstObs = const CKGlobalTable *;

	struct CKTables
	{
		CKTables(CKIREnvironmentObs irenv);

		CKIRModuleObs module() const
		{
			return module_;
		}

		CKTypeTableObs typetable()
		{
			return &typetable_;
		}

		CKGlobalTableObs globtable()
		{
			return &globtable_;
		}

		CKGlobalTableConstObs globtable() const
		{
			return &globtable_;
		}

		void dump_tables(std::ostream &os) const;

		void dump_ir_module(std::ostream &os) const;

		std::error_code write_bitcode_module(const std::string &fname) const;

		CKIRDataLayoutObs data_layout() const
		{
			return data_layout_;
		}

	private:
		void declare_library();

		CKIREnvironmentObs irenv_;
		CKIRModuleObs module_;
		CKIRDataLayoutObs data_layout_;

		CKTypeTable typetable_;
		CKGlobalTable globtable_;
	};

	using CKTablesObs = CKTables *;
	/// @endcond

	class context;

	/// Semantic layer of compiler context
	struct CKContext
	{
		/// @cond INTERNAL
		CKContext(CKTablesObs tab);
		/// @endcond

		/// @name Scope control
		/// @{

		/// Signalize entering of the compound statement of the definition of the function f
		void enter_function(CKFunctionObs f, CKFunctionFormalPackArray pack, loc_t loc);
		/// Signalize exiting of the compound statement of the definition of a function
		void exit_function();
		/// Signalize entering of a compound statement other than a function definition
		void enter_block();
		/// Signalize exiting of a compound statement other than a function definition
		void exit_block();
		/// The return type of the current function
		CKTypeSafeObs current_function_return_type();
		/// @}

		/// @name Built-in types
		/// @{

		/// The built-in "void" type descriptor
		CKVoidTypeSafeObs get_void_type() const { return CKVoidTypeSafeObs(typetable_->get_void_type()); }
		/// The built-in "_Bool" type descriptor
		CKBoolTypeSafeObs get_bool_type() const { return CKBoolTypeSafeObs(typetable_->get_bool_type()); }
		/// The built-in "char" type descriptor
		CKCharTypeSafeObs get_char_type() const { return CKCharTypeSafeObs(typetable_->get_char_type()); }
		/// The built-in "int" type descriptor
		CKIntTypeSafeObs get_int_type() const { return CKIntTypeSafeObs(typetable_->get_int_type()); }
		/// @}

		/// @name Creating unnamed types
		/// @{

		/// A pointer type descriptor
		CKPtrTypeSafeObs get_pointer_type(const CKTypeRefPack &pack) { return CKPtrTypeSafeObs(typetable_->get_pointer_type(pack)); }
		/// An array type descriptor
		CKArrayTypeSafeObs get_array_type(CKTypeObs element_type, CKIRConstantIntObs size);
		/// A function type descriptor
		CKFunctionTypeSafeObs get_function_type(CKTypeObs ret_type, CKTypeObsArray arg_types, bool variadic = false);
		/// @}

		/// @name Named struct types
		/// @{

		/// Reference or declare a struct type
		CKStructTypeSafeObs declare_struct_type(const CIName &n, loc_t loc);
		/// Signalize entering the definition of the struct type named n
		CKStructTypeSafeObs define_struct_type_open(const CIName &n, loc_t loc);
		/// Signalize exiting the definition of the struct type type
		void define_struct_type_close(CKStructTypeObs type, const CKStructItemArray &items);
		/// @}

		/// @name Named enum types
		/// @{

		/// Reference or declare an enum type
		CKEnumTypeSafeObs declare_enum_type(const CIName &n, loc_t loc);
		/// Signalize entering the definition of the enum type named n
		CKEnumTypeSafeObs define_enum_type_open(const CIName &n, loc_t loc);
		/// Signalize exiting the definition of the enum type type
		void define_enum_type_close(CKEnumTypeObs type, CKConstantObsVector items);
		/// @}

		/// @name Variables
		/// @{

		/// Define a global or local variable
		void define_var(const CIName &name, const CKTypeRefPack &type_pack, loc_t loc);
		/// @}

		/// @name Typedefs
		/// @{

		/// Define a typedef
		CKTypedefConstSafeObs define_typedef(const CIName &name, const CKTypeRefPack &type_pack, loc_t loc);
		/// @}

		/// @name Enumeration constants
		/// @{

		/// Define an enumeration constant
		CKConstantConstSafeObs define_constant(const CIName &name, CKIRConstantIntObs value, loc_t loc);
		/// @}

		/// @name Functions
		/// @{

		/// Declare a function (with or without body)
		CKFunctionSafeObs declare_function(const CIName &n, CKTypeObs type, loc_t loc);
		/// @}

		/// @name Finding named objects
		/// @{

		/// Find a named (constant, variable, or function) object
		CKNamedSafeObs find(const CIName &n);

		/// Find a typedef
		CKTypedefConstSafeObs find_typedef(const CIName &n) const;
		/// @}

		/// @name Determination of typedefs in lexer
		/// @{

		/// Check whether the name is a typedef (for the lexer)
		bool is_typedef(const CIName &n) const;
		/// @}

		/// @name Direct access to LLVM types
		/// @{

		/// LLVM representation of C-types "int64_t" and "uint64_t"
		CKIRTypeObs get_ir_int64()
		{
			return llvm::Type::getInt64Ty(builder_.getContext());
		}
		/// @}

		/// @name Representation of integer constants
		/// @{

		/// LLVM constant of type "char"
		CKIRConstantIntObs get_int8_constant(std::int_fast32_t v)
		{
			return CKGetInt8Constant(builder_.getContext(), v);
		}

		/// LLVM constant of type "int"
		CKIRConstantIntObs get_int32_constant(std::int_fast32_t v)
		{
			return CKGetInt32Constant(builder_.getContext(), v);
		}

		CKIRNull get_null_constant(CKPtrTypeObs type)
		{
			return CKGetNull(type->get_ir());
		}

		/// @}

		/// @name Basic blocks
		/// @{

		/// Create a new basic block in the current function
		CKIRBasicBlockObs create_basic_block(const std::string &name)
		{
			if (!current_function_ir_)
				return nullptr;
			return CKCreateBasicBlock(name, current_function_ir_);
		}
		/// @}

		/// @name Active code builder
		/// @{

		/// The active builder for the currently open basic block (or inactive)
		CKIRBuilderObs builder()
		{
			return &builder_;
		}
		CKIRModuleObs module()
		{
			return module_;
		}

		/// @}

		/// @name Type properties
		/// @{

		/// Size of a type in bytes
		CKIRConstantIntObs get_type_size(CKTypeObs type) const
		{
			return CKGetInt32Constant(builder_.getContext(), CKGetTypeSize(data_layout_, type->get_ir()));
		}
		/// @}

		/// @cond INTERNAL
		CKIRDataLayoutObs data_layout() const
		{
			return data_layout_;
		}

		bool conflicting_idf(const std::string &name);
		bool conflicting_idf_function(const std::string &name, CKFunctionTypeObs type);
		bool conflicting_tag_enum(const std::string &name);
		bool conflicting_tag_struct(const std::string &name);
		/// @endcond
	private:
		CKTypeTableObs typetable_;
		CKGlobalTableObs globtable_;
		CKIRModuleObs module_;
		CKLocalTableObs loctable_;
		std::unique_ptr<CKLocalTable> dummy_loctable_;

		CKFunctionObs current_function_;
		CKIRFunctionObs current_function_ir_;
		CKIRBuilder alloca_builder_;
		CKIRBuilder builder_;
		CKIRBasicBlockObs start_bb_;
		CKIRDataLayoutObs data_layout_;

		context *get_ctx();
	};
}

/// @cond INTERNAL
inline std::size_t std::hash<cecko::CKTypeObs>::operator()(const cecko::CKTypeObs &a) const
{
	return cecko::compute_hash(a->hash());
}

inline std::size_t std::hash<cecko::CKTypeRefPack>::operator()(const cecko::CKTypeRefPack &a) const
{
	return cecko::compute_hash(a.type, a.is_const);
}
/// @endcond

#endif

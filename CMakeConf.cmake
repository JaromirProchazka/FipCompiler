#cmake_minimum_required (VERSION 3.15)
#cmake_policy(SET CMP0076 NEW)
#cmake_policy(SET CMP0092 NEW)

if(CMAKE_GENERATOR MATCHES "Ninja")
	# avoid parallel linking
	set_property(GLOBAL APPEND PROPERTY JOB_POOLS link_job_pool=1)	
	set(CMAKE_JOB_POOL_LINK link_job_pool)
endif()

find_package(BISON 3.4)
find_package(FLEX 2.6.4)

find_package(LLVM 19.1.0 QUIET CONFIG)
if(NOT DEFINED LLVM_PACKAGE_VERSION)
	find_package(LLVM 18.0.0 QUIET CONFIG)
endif()
if(NOT DEFINED LLVM_PACKAGE_VERSION)
	find_package(LLVM 17.0.0 QUIET CONFIG)
endif()
if(NOT DEFINED LLVM_PACKAGE_VERSION)
	find_package(LLVM 16.0.0 QUIET CONFIG)
endif()
if(NOT DEFINED LLVM_PACKAGE_VERSION)
	find_package(LLVM 15.0.0 REQUIRED CONFIG)
endif()
	
if(NOT DEFINED LLVM_PACKAGE_VERSION)
	if(NOT DEFINED LLVM_OBJ_ROOT)
		file(TO_CMAKE_PATH "${CMAKE_SOURCE_DIR}/../llvm-build" LLVM_OBJ_ROOT_DEFAULT)
		set(LLVM_OBJ_ROOT ${LLVM_OBJ_ROOT_DEFAULT} CACHE FILEPATH "The LLVM install folder")
		message("LLVM_OBJ_ROOT was not defined, defaulting to ${LLVM_OBJ_ROOT}")
	endif()
else()
	message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
	message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

	include_directories(${LLVM_INCLUDE_DIRS})
	# add_definitions(${LLVM_DEFINITIONS})
	separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
	add_definitions(${LLVM_DEFINITIONS_LIST})

	llvm_map_components_to_libnames(LLVM_LIBS_USED core mcjit nativecodegen)	# executionengine interpreter mc support x86codegen
endif()

if(NOT DEFINED MAKE_DOXYGEN)
	set(MAKE_DOXYGEN FALSE CACHE BOOL "Generate doxygen")
	message("MAKE_DOXYGEN was not defined, defaulting to FALSE")
endif()

if(NOT DEFINED DOXYGEN_OUTPUT_DIRECTORY)
	set(DOXYGEN_OUTPUT_DIRECTORY "." CACHE FILEPATH "Doxygen output directory (relative to <build>/fmwk)")
endif()

if(MAKE_DOXYGEN)
	find_package(Doxygen REQUIRED dot)
endif()

set(THREADS_PREFER_PTHREAD_FLAG True)
find_package(Threads REQUIRED)

function(SET_TARGET_OPTIONS TARGET OPT_GCC OPT_MSVC)
	if(MSVC)
		target_compile_options(${TARGET} PUBLIC ${OPT_MSVC})
	else()
		target_compile_options(${TARGET} PUBLIC ${OPT_GCC})
	endif()
endfunction()

function(SET_TARGET_LINK_OPTIONS TARGET OPT_GCC OPT_MSVC)
	if(MSVC)
		target_link_options(${TARGET} PUBLIC ${OPT_MSVC})
	else()
		target_link_options(${TARGET} PUBLIC ${OPT_GCC})
	endif()
endfunction()

function(COMMON_OPTIONS TARGET)
	set_property(TARGET ${TARGET} PROPERTY CXX_STANDARD 20)
	if(NOT DEFINED LLVM_PACKAGE_VERSION)
		target_include_directories(${TARGET} PUBLIC "${LLVM_OBJ_ROOT}/include")
	else()
		# message("LLVM_LIBS_USED = ${LLVM_LIBS_USED}")
		target_link_libraries(${TARGET} PUBLIC ${LLVM_LIBS_USED})
	endif()	
	SET_TARGET_OPTIONS(${TARGET} "-Wall" "/W4")

	SET_TARGET_OPTIONS(${TARGET} "" "/we5038")

	SET_TARGET_OPTIONS(${TARGET} "" "/D_CRT_SECURE_NO_WARNINGS")
	SET_TARGET_OPTIONS(${TARGET} "" "/D_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING")
	SET_TARGET_OPTIONS(${TARGET} "" "/D_SILENCE_CXX20_CISO646_REMOVED_WARNING")
	SET_TARGET_OPTIONS(${TARGET} "" "/wd4005")
	SET_TARGET_OPTIONS(${TARGET} "" "/wd4100")
	SET_TARGET_OPTIONS(${TARGET} "" "/wd4127")
	SET_TARGET_OPTIONS(${TARGET} "" "/wd4141")
	SET_TARGET_OPTIONS(${TARGET} "" "/wd4146")
	SET_TARGET_OPTIONS(${TARGET} "" "/wd4244")
	SET_TARGET_OPTIONS(${TARGET} "" "/wd4245")
	SET_TARGET_OPTIONS(${TARGET} "" "/wd4267")
	SET_TARGET_OPTIONS(${TARGET} "" "/wd4310")
	SET_TARGET_OPTIONS(${TARGET} "" "/wd4324")
	SET_TARGET_OPTIONS(${TARGET} "" "/wd4456")
	SET_TARGET_OPTIONS(${TARGET} "" "/wd4458")
	SET_TARGET_OPTIONS(${TARGET} "" "/wd4459")
	SET_TARGET_OPTIONS(${TARGET} "" "/wd4624")

	SET_TARGET_LINK_OPTIONS(${TARGET} "" "/IGNORE:4099")	# missing pdb

	SET_TARGET_LINK_OPTIONS(${TARGET} "-rdynamic" "")	# for self-references to ckrt_printf etc

endfunction()

function(CREATE_TARGET TARGET)
	add_executable (${TARGET})
	COMMON_OPTIONS(${TARGET})

	if(NOT DEFINED LLVM_PACKAGE_VERSION)
		message("LLVM_PACKAGE_VERSION was not defined, trying to enumerate libraries explicitly")
		target_link_directories(${TARGET} PUBLIC "${LLVM_OBJ_ROOT}/lib")
		target_link_libraries(${TARGET} PUBLIC "LLVMCore" "LLVMInterpreter" "LLVMMC" "LLVMMCJIT" "LLVMSupport" "LLVMX86CodeGen" "LLVMX86Desc" "LLVMX86Info" "LLVMRuntimeDyld" "LLVMMCDisassembler" "LLVMAsmPrinter" "LLVMDebugInfoDWARF" "LLVMCFGuard" "LLVMGlobalISel" "LLVMSelectionDAG" "LLVMCodeGen" "LLVMTarget" "LLVMBitWriter" "LLVMScalarOpts" "LLVMAggressiveInstCombine" "LLVMInstCombine" "LLVMTransformUtils" "LLVMAnalysis" "LLVMObject" "LLVMBitReader" "LLVMMCParser" "LLVMMC" "LLVMDebugInfoCodeView" "LLVMDebugInfoMSF" "LLVMTextAPI" "LLVMProfileData" "LLVMCore" "LLVMBinaryFormat" "LLVMRemarks" "LLVMBitstreamReader" "LLVMX86Utils" "LLVMSupport" "LLVMDemangle" "LLVMExecutionEngine")
	endif()	

	target_link_libraries(${TARGET} PRIVATE Threads::Threads)
endfunction()

function(MAKE_TARGET TARGET_MACRO_SUFFIX TARGET)
	set("TARGET_${TARGET_MACRO_SUFFIX}" ${TARGET} PARENT_SCOPE)
	CREATE_TARGET(${TARGET})
	add_dependencies(${TARGET} "${SOL_PREFIX}solution")
	target_link_libraries(${TARGET} PUBLIC "${SOL_PREFIX}solution")
endfunction()

function(MAKE_TARGET_DUMP TARGET_MACRO_SUFFIX TARGET)
	set("TARGET_${TARGET_MACRO_SUFFIX}" ${TARGET} PARENT_SCOPE)
	CREATE_TARGET(${TARGET})
	add_dependencies(${TARGET} "${SOL_PREFIX}solution_dump")
	target_link_libraries(${TARGET} PUBLIC "${SOL_PREFIX}solution_dump")
endfunction()

function(DEFINE_FLEX_SOURCE TARGET LEXFNAME LEXCPP YHPP)
	SET_TARGET_OPTIONS(${TARGET} "" "/wd4624")
	SET_TARGET_OPTIONS(${TARGET} "" "/wd4065")

	target_sources(${TARGET} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/${LEXCPP})
	set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/${LEXCPP} PROPERTIES COMPILE_DEFINITIONS "BISON_HEADER=${YHPP}")
endfunction()

function(DEFINE_BISON_SOURCE TARGET YFNAME YCPP YHPP)
	SET_TARGET_OPTIONS(${TARGET} "" "/wd4624")
	SET_TARGET_OPTIONS(${TARGET} "" "/wd4065")

	target_sources(${TARGET} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/${YCPP})
	target_sources(${TARGET} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/${YHPP})	# PUBLIC does not work here
	# THIS PATCH DOES NOT WORK EITHER: set_property(SOURCE ${CMAKE_CURRENT_BINARY_DIR}/${YHPP} TARGET_DIRECTORY .. PROPERTY GENERATED 1)
	target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
endfunction()

function(FLEX_BISON_SOURCE TARGET LEXFNAME YFNAME LEXCPP YCPP YHPP)

	get_filename_component(LEXFNAME_PATH "${LEXFNAME}" ABSOLUTE) 
	get_filename_component(YFNAME_PATH "${YFNAME}" ABSOLUTE) 

	set(YFLAGS_BASE "-Werror=all -Wno-empty-rule")
	if("${BISON_VERSION}" VERSION_GREATER_EQUAL "3.7.0")
		set(YFLAGS "${YFLAGS_BASE} -Wcounterexamples")
	else()
		set(YFLAGS "${YFLAGS_BASE}")
	endif()

	FLEX_TARGET("${LEXCPP}" "${LEXFNAME_PATH}" "${CMAKE_CURRENT_BINARY_DIR}/${LEXCPP}")
	BISON_TARGET("${YCPP}" "${YFNAME_PATH}" "${CMAKE_CURRENT_BINARY_DIR}/${YCPP}" COMPILE_FLAGS "${YFLAGS}" DEFINES_FILE "${CMAKE_CURRENT_BINARY_DIR}/${YHPP}" VERBOSE REPORT_FILE "${CMAKE_CURRENT_BINARY_DIR}/${YFNAME}.output")
	ADD_FLEX_BISON_DEPENDENCY("${LEXCPP}" "${YCPP}")

	DEFINE_FLEX_SOURCE("${TARGET}" "${LEXFNAME}" "${LEXCPP}" "${YHPP}")
	DEFINE_BISON_SOURCE("${TARGET}" "${YFNAME}" "${YCPP}" "${YHPP}")
endfunction()

function(FLEX_SOURCE TARGET LEXFNAME LEXCPP YHPP)

	get_filename_component(LEXFNAME_PATH "${LEXFNAME}" ABSOLUTE) 

	FLEX_TARGET("${LEXCPP}" "${LEXFNAME_PATH}" "${CMAKE_CURRENT_BINARY_DIR}/${LEXCPP}")

	DEFINE_FLEX_SOURCE("${TARGET}" "${LEXFNAME}" "${LEXCPP}" "${YHPP}")
endfunction()

function(BISON_SOURCE TARGET YFNAME YCPP YHPP)

	get_filename_component(YFNAME_PATH "${YFNAME}" ABSOLUTE) 

	BISON_TARGET("${YCPP}" "${YFNAME_PATH}" "${CMAKE_CURRENT_BINARY_DIR}/${YCPP}" DEFINES_FILE "${CMAKE_CURRENT_BINARY_DIR}/${YHPP}")

	DEFINE_BISON_SOURCE("${TARGET}" "${YFNAME}" "${YCPP}" "${YHPP}")
endfunction()

function(SOLUTION_LIBRARY TARGET FRAMEWORK)
	add_library("${TARGET}")
	COMMON_OPTIONS("${TARGET}")

	add_dependencies("${TARGET}" ${FRAMEWORK})
	target_link_libraries("${TARGET}" PUBLIC ${FRAMEWORK})
endfunction()

function(SOLUTION_LIBRARY_DUMP TARGET FRAMEWORK FRAMEWORK_DUMP)
	add_library("${TARGET}")
	COMMON_OPTIONS("${TARGET}")

	add_dependencies("${TARGET}" ${FRAMEWORK})
	target_link_libraries("${TARGET}" PUBLIC ${FRAMEWORK})

	add_dependencies("${TARGET}" ${FRAMEWORK_DUMP})
	target_link_libraries("${TARGET}" PUBLIC ${FRAMEWORK_DUMP})
endfunction()

function(DOXYGEN TARGET)
	if(MAKE_DOXYGEN)
		set(DOXYGEN_DOT_IMAGE_FORMAT svg)
		#set(DOXYGEN_GENERATE_TAGFILE "fmwk.tag")
		doxygen_add_docs("${TARGET}" ${ARGN} ALL)
	endif()
endfunction()
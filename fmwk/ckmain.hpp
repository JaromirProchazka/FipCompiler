#ifndef ckmain_hpp_
#define ckmain_hpp_

#include "ckcontext.hpp"
#include "ckbisonflex.hpp"

#include <string>
#include <ostream>
#include <fstream>
#include <iostream>
#include <sstream>

namespace cecko
{

	/// @cond INTERNAL
	class main_state_lexer
	{
	public:
		CKIREnvironment irenv;
		CKTables the_tables;

		main_state_lexer()
			: irenv(), the_tables(&irenv)
		{
		}
	};

	class main_state_parser : public main_state_lexer
	{
	public:
		std::string input_fname;
		std::string covname;
		std::string covlinename;

		main_state_parser() : outp_(&std::cout) {}

		template <class the_parser>
		bool parse()
		{
			context ctx(&the_tables, &out(), &cd_);

			FILE *iff = fopen(input_fname.c_str(), "r");
			if (iff == nullptr)
			{
				ctx.message(cecko::errors::NOFILE, 0, input_fname);
				return false;
			}

			auto scn = lexer_init(iff);

			the_parser prs(scn, &ctx);

			prs.parse();

			lexer_shutdown(scn);
			return true;
		}

		bool dump_tables() const;

		bool dump_coverage() const;

		std::ostream &out() const { return *outp_; }

	protected:
		std::ostream *outp_;
		std::unique_ptr<std::ofstream> outp_owner_;

		coverage::coverage_data cd_;
	};

	class main_state_code : public main_state_parser
	{
	public:
		std::string oname;	  // binary output
		std::string aname;	  // assembly output
		bool a_to_out = true; // assembly to out()
		int app_argc = 0;
		char **app_argv = nullptr;

		main_state_code() : app_argc(0), app_argv(nullptr) {}

		bool setup(int argc, char **argv);

		bool dump_code() const;

		bool run_code();
	};
	/// @endcond
}

#endif

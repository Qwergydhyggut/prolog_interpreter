#ifndef __ANALYSIS_INCLUDE__
#define __ANALYSIS_INCLUDE__
#include "token.h"
#include <vector>
#include <string>
#include <map>
/* #include <mutex> */


namespace analysis_mod
{
  typedef enum{Atom,OP,Addr} type_e;
  class csz_stack
  {
  public:
    struct cz
    {
      type_e type;
      std::string str;
      token_class::token *tok;
    };
    struct sql_shuju
    {
      std::string table;
      std::vector<std::string> list;
    };
    static cz exp;
    static std::vector<cz> do_st;
    static std::map<std::string,sql_shuju> sql;
  };
    
  class analysis_read
  {
  public:
    /* static czs_stack cs_st; */
    static void do_the_that(token_class::bnf_token bt);

    
  };
  
  
}

#endif

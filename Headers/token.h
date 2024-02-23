#ifndef __TOKEN_INCLUDE__
#define __TOKEN_INCLUDE__
#include <locale>
#include <string>
//#include "lexer.h"
#define ENABLE_TOKEN_OBJ Atom_t,Inter_t,Var_t,Ter_t,Rkh_t,Lkh_t,OP_t,AND_t,OR_t,Addr
#define ENABLE_BNF_TOKEN S,E,T,Ter,ID,Lkh,Rkh,E1,T1,OP,E2,T2,F


namespace token_class
{
  class token
  {
  public:
    token(int i):addr(i){};
    token(){};
    int token_exp=0;
    std::string str="mdzz";
    enum{Atom,Inter,Var,Ter} token_type;
    typedef enum{ENABLE_TOKEN_OBJ} Stat;
    Stat true_type;
    int addr;
    // lexer_mod::lexer_read *prev;
    
    
  };

  struct bnf_token
  {
    token is_ter;
    typedef enum {ENABLE_BNF_TOKEN} Stat;
    Stat stat;
    bnf_token(Stat rcs);
    bool operator<(const bnf_token &rkh) const;
  };

  
}

#endif

#ifndef __TOKEN_INCLUDE__
#define __TOKEN_INCLUDE__
#include <string>
//#include "lexer.h"
#define ENABLE_TOKEN_OBJ Atom_t,Inter_t,Var_t,Ter_t,Rkh_t,Lkh_t,OP_t,AND_t,OR_t


namespace token_class
{
  class token
  {
  public:
    int token_exp=0;
    std::string str="mdzz";
    enum{Atom,Inter,Var,Ter} token_type;
    typedef enum{ENABLE_TOKEN_OBJ} Stat;
    Stat true_type;
    // lexer_mod::lexer_read *prev;
    
    
  };
  
  
}

#endif

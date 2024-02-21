#ifndef __TOKEN_INCLUDE__
#define __TOKEN_INCLUDE__
#include <string>
//#include "lexer.h"


namespace token_class
{
  class token
  {
  public:
    int token_exp=0;
    std::string str="mdzz";
    enum{Atom,Inter,Var,Ter} token_type;
    // lexer_mod::lexer_read *prev;
    
    
  };
  
  
}

#endif

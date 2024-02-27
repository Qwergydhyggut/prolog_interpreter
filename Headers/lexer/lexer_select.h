#ifndef __LEXER_CHOOSE_INCLUDE__
#define __LEXER_CHOOSE_INCLUDE__
#include "token.h"
#include "lexer.h"
#include <string>
#define ENABLE_OBJ_INPUT {'+','-','*','/','='}
#define ENABLE_TER_INPUT {'.',';',',','(',')'}


struct select_token_class
{    
  static bool select_token_fun_ptr(char c,char c1);
  static void select_set_token_ptr(token_class::token &tok);
private:
  static bool is_atom_var(char c);
  static bool is_atom_obj(char c);
  static bool is_ter(char c);
  static bool is_inter(char c);
  public:
  typedef enum{Atom_obj,Atom_var,Var,Inter,Init,Ter} Stat;
  static Stat stat;
};

struct get_token_next
{
  get_token_next(std::string str);
  token_class::token *operator()();
  ~get_token_next();
private:
  std::string str;
  lexer_mod::lexer_read *tok;
  int i;
};   

#endif

// void test();
#ifndef __LEXER_INCLUDE__
#define __LEXER_INCLUDE__
#include "token.h"
#include <string>


namespace lexer_mod
{
  class lexer_read
  {
    class lexer_node
    {
      lexer_node *next_node[256];
      lexer_node *prev_node;
      int count;
      int terminal;
      token_class::token token;
      std::string str;

    public:
      lexer_node(lexer_node *ptr);
      ~lexer_node();
      lexer_node *add_node(char c);
      token_class::token set_node(int ter);
      lexer_node *get_next_node(char c);
      void set_terminal(int ter);
      int get_terminal();
      token_class::token get_token();

      
    };

  public:
    lexer_read();
    ~lexer_read();
    token_class::token operator()(char c);

  private:
    lexer_node *first_node;
    lexer_node *this_node;
    lexer_node *last_node;
    token_class::token null_token;
    int ter_save;


  };
  
};

#endif

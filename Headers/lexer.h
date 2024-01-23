//void test();
#include "token.h"


namespace lexer_mod
{
  class lexer_read
  {
    class lexer_node
    {
      lexer_node *next_node[100];
      int terminal;
      token_class::token *token;

    public:
      lexer_node();
      ~lexer_node();
      lexer_node *add_node(char c);
      token_class::token *set_node();
      lexer_node *get_next_node(char c);
      void set_terminal();
      int get_terminal();
      token_class::token *get_token();

      
    };

  public:
    lexer_read();
    ~lexer_read();
    token_class::token *operator()(char c);

  private:
    lexer_node *first_node;
    lexer_node *this_node;
    lexer_node *last_node;


  };
  
};

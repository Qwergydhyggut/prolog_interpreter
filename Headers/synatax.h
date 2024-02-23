#ifndef __SYNATAX_INCLUDE__
#define __SYNATAX_INCLUDE__
#include "token.h"
#include "synatax_tree.h"
#include <vector>
#include <functional>
#include <map>


/* void test_syna(); */
namespace synatax_mod
{
  class synatax_read
  {
    static std::vector<token_class::bnf_token> init_ret_fun(token_class::bnf_token bt,token_class::token tok);
    static synatax_tree_class::synatax_tree init_do_stack_fun(std::vector<token_class::bnf_token> &bnf_stack,std::vector<token_class::token> &tok_stack,std::vector<token_class::token> &op_stack);
  public:
    synatax_read(std::function<std::vector<token_class::bnf_token>(token_class::bnf_token,token_class::token)> ptr=init_ret_fun, std::function<synatax_tree_class::synatax_tree(std::vector<token_class::bnf_token>&,std::vector<token_class::token>&,std::vector<token_class::token>&)> ptr1=init_do_stack_fun);
    synatax_tree_class::synatax_tree operator()(token_class::token tok);
    
  private:
    std::function<std::vector<token_class::bnf_token>(token_class::bnf_token,token_class::token)> ret_fun;
    std::function<synatax_tree_class::synatax_tree(std::vector<token_class::bnf_token>&,std::vector<token_class::token>&,std::vector<token_class::token>&)> do_stack_fun;
    std::vector<token_class::bnf_token> bnf_stack;
    std::vector<token_class::token> tok_stack;
    std::vector<token_class::token> op_stack;
    
  };
  
  
};


#endif

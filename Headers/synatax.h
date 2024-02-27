#ifndef __SYNATAX_INCLUDE__
#define __SYNATAX_INCLUDE__
#include "token.h"
#include "synatax_tree.h"
#include <vector>
#include <functional>
#include <map>
#include "synatax/synatax_ptr.h"
#define RET_FUN_TYPE std::function<std::vector<token_class::bnf_token>(token_class::bnf_token,token_class::token)>
#define DO_STACK_FUN std::function<synatax_tree_class::synatax_tree(std::vector<token_class::bnf_token>&,std::vector<token_class::token*>&,std::vector<token_class::token*>&)>


/* void test_syna(); */
namespace synatax_mod
{
  class synatax_read
  {
    // static std::vector<token_class::bnf_token> init_ret_fun(token_class::bnf_token bt,token_class::token tok);
    // static synatax_tree_class::synatax_tree init_do_stack_fun(std::vector<token_class::bnf_token> &bnf_stack,std::vector<token_class::token*> &tok_stack,std::vector<token_class::token*> &op_stack);
  public:
    static synatax_tree_class::synatax_tree null_sy_tree;
    synatax_read();

    void operator()(synatax_ptr_f *spf);
    static std::vector<token_class::bnf_token> next_bnf_list(token_class::bnf_token bt,synatax_ptr_f *spf);
    // std::vector<token_class::bnf_token> do_that(std::vector<token_class::bnf_token> bnf_st={token_class::bnf_token::S},std::vector<token_class::token*> op_st={});
    // static token_class::token *test_fun();
    
  private:
    // RET_FUN_TYPE ret_fun;
    // DO_STACK_FUN do_stack_fun;

    synatax_ptr_f *spf;
    // std::vector<token_class::bnf_token> bnf_stack;
    // std::vector<token_class::token*> tok_stack;
    // std::vector<token_class::token*> op_stack;
    
  };
  
  
};


#endif

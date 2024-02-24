#ifndef __SYNATAX_PTR_INCLUDE__
#define __SYNATAX_PTR_INCLUDE__
#include <atomic>
#include <vector>
#include "token.h"
#include "synatax_tree.h"


struct synatax_ptr_class
{
  static synatax_tree_class::synatax_tree D_sy_tree;
  static std::vector<token_class::bnf_token> ret_ptr(token_class::bnf_token bt,token_class::token tok);
  static synatax_tree_class::synatax_tree do_stack_ptr(std::vector<token_class::bnf_token> &bnf_stack,std::vector<token_class::token*> &tok_stack,std::vector<token_class::token*> &op_stack);
};    


#endif

#ifndef __SYNATAX_PTR_INCLUDE__
#define __SYNATAX_PTR_INCLUDE__
// #include <atomic>
#include <vector>
#include "token.h"
#include "synatax_tree.h"
#include <functional>
#define VEC_BNF_TOK std::vector<token_class::bnf_token>
#define VEC_TOK_PTR std::vector<token_class::token*>


struct synatax_ptr_class
{
  // static synatax_tree_class::synatax_tree D_sy_tree;
  static std::vector<token_class::bnf_token> ret_ptr(token_class::bnf_token bt,token_class::token *tok);
  // static synatax_tree_class::synatax_tree do_stack_ptr(std::vector<token_class::bnf_token> &bnf_stack,std::vector<token_class::token*> &tok_stack,std::vector<token_class::token*> &op_stack);
};

struct synatax_ptr_f
{
  virtual VEC_BNF_TOK do_that(VEC_BNF_TOK bnf_st={token_class::bnf_token::S},VEC_TOK_PTR op_st={})=0;
  virtual VEC_BNF_TOK ret_fun(token_class::bnf_token bt,token_class::token *tok)=0;
  virtual token_class::token *ret_next_token()=0;
  std::function<VEC_BNF_TOK(token_class::bnf_token,synatax_ptr_f*)> next_bnf_list;
};

struct synatax_ptr_sql : synatax_ptr_f
{
  VEC_BNF_TOK do_that(VEC_BNF_TOK bnf_st={token_class::bnf_token::S},VEC_TOK_PTR op_st={});
  VEC_BNF_TOK ret_fun(token_class::bnf_token bt,token_class::token *tok);
  token_class::token *ret_next_token();
};

#endif

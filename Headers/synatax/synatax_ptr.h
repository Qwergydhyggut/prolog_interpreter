#ifndef __SYNATAX_PTR_INCLUDE__
#define __SYNATAX_PTR_INCLUDE__
// #include <atomic>
#include <vector>
#include "token.h"
#include "synatax_tree.h"
#include <functional>
#include <cstdio>
#include "lexer/lexer_select.h"
#define VEC_BNF_TOK std::vector<token_class::bnf_token>
#define VEC_TOK_PTR std::vector<token_class::token*>


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

struct synatax_ptr_text : synatax_ptr_sql
{
  token_class::token *ret_next_token();
  FILE *fp;
};                             

#endif

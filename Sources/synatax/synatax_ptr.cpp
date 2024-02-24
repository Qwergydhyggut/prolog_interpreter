#include "synatax/synatax_ptr.h"
#include <vector>
#include <map>
#include "token.h"
#include "debug.h"
#include "synatax.h"


std::vector<token_class::bnf_token> synatax_ptr_class::ret_ptr(token_class::bnf_token bt,token_class::token tok)
{
  std::vector<token_class::bnf_token> mdzz;
  static token_class::bnf_token T(token_class::bnf_token::T);
  static token_class::bnf_token T1(token_class::bnf_token::T1);
  static token_class::bnf_token T2(token_class::bnf_token::T2);
  static token_class::bnf_token E(token_class::bnf_token::E);
  static token_class::bnf_token E1(token_class::bnf_token::E1);
  static token_class::bnf_token E2(token_class::bnf_token::E2);
  static token_class::bnf_token S(token_class::bnf_token::S);
  static token_class::bnf_token F(token_class::bnf_token::F);
  static token_class::bnf_token OP(token_class::bnf_token::OP);
  static token_class::bnf_token Ter(token_class::bnf_token::Ter);
  static token_class::bnf_token Lkh(token_class::bnf_token::Lkh);
  static token_class::bnf_token Rkh(token_class::bnf_token::Rkh);
  static token_class::bnf_token ID(token_class::bnf_token::ID);

  static std::map<token_class::bnf_token,std::map<token_class::token::Stat,std::vector<token_class::bnf_token>>> synatax_bnf=
    {{S,{{token_class::token::Inter_t,{E,Ter}},
	 {token_class::token::Lkh_t,{E,Ter}}}},
     {E,{{token_class::token::Inter_t,{F,E2}},
	 {token_class::token::Lkh_t,{F,E2}}}},
     {F,{{token_class::token::Inter_t,{ID,E2}},
	 {token_class::token::Lkh_t,{Lkh,E,Rkh}}}}, //Ter E2 E2 ID
     {E2,{{token_class::token::Ter_t,{Ter}},
	  // {token_class::token::OR_t,{OP,E}},
	  {token_class::token::OP_t,{OP,E}}}},
     {ID,{{token_class::token::Inter_t,{Ter,ID}}}},
     {Lkh,{{token_class::token::Lkh_t,{Ter,Lkh}}}},
     {Rkh,{{token_class::token::Rkh_t,{Ter,Rkh}}}},
     {OP,{//{token_class::token::AND_t,{Ter,OP}},
	  {token_class::token::OP_t,{Ter,OP}}}}};
  debug;

  return synatax_bnf[bt][tok.true_type];

  
}

synatax_tree_class::synatax_tree synatax_ptr_class::do_stack_ptr(std::vector<token_class::bnf_token> &bnf_stack,std::vector<token_class::token*> &tok_stack,std::vector<token_class::token*> &op_stack)
{
  static int i=1;
  synatax_tree_class::synatax_tree ret_sy;

  bnf_stack.pop_back();
  ret_sy=synatax_mod::synatax_read::null_sy_tree;
  switch(bnf_stack[bnf_stack.size()-1].stat)
  {
  case token_class::bnf_token::ID:
    debug;
    if(!op_stack.empty()&&!(op_stack[op_stack.size()-1]->true_type-token_class::token::OP_t))
    {
      ret_sy.addr=i;
      ret_sy.car=op_stack[op_stack.size()-1];
      ret_sy.args={tok_stack[tok_stack.size()-1],tok_stack[tok_stack.size()-2]};
      op_stack.pop_back();
      tok_stack.pop_back();
      tok_stack.pop_back();
      tok_stack.push_back(new token_class::token(i++));

      break;
	
    }
    ret_sy.addr=i;
    ret_sy.car=tok_stack[tok_stack.size()-1];
    tok_stack.pop_back();
    tok_stack.push_back(new token_class::token(i++));
    debug;
    printf("%d %d\n",tok_stack[tok_stack.size()-1]->true_type,tok_stack[tok_stack.size()-1]->addr);
    break;
  case token_class::bnf_token::OP:
    debug;
    op_stack.push_back(tok_stack[tok_stack.size()-1]);
    tok_stack.pop_back();
    break;
  case token_class::bnf_token::Rkh:
    op_stack.pop_back();
    break;
  case token_class::bnf_token::Lkh:
    op_stack.push_back(tok_stack[tok_stack.size()-1]);
    tok_stack.pop_back();
    break;

  // default:ret_sy=null_sy_tree;//bnf_stack.pop_back();
    
  }
  bnf_stack.pop_back();

  debug;
  return ret_sy;

  
}

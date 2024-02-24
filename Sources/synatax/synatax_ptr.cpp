#include "synatax/synatax_ptr.h"
#include <vector>
#include <map>
#include "token.h"
#include "debug.h"
#include "synatax.h"
#include "lexer.h"


synatax_tree_class::synatax_tree synatax_ptr_class::D_sy_tree=synatax_tree_class::synatax_tree(-1);

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
	 {token_class::token::Atom_t,{E,Ter}},
	 {token_class::token::OP_t,{E,Ter}},
	 {token_class::token::Lkh_t,{E,Ter}}}},
     {E,{{token_class::token::Inter_t,{F,E2}},
	 {token_class::token::Atom_t,{F,E2}},
	 {token_class::token::OP_t,{F,E2}},
	 {token_class::token::Lkh_t,{F,E2}}}},
     {F,{{token_class::token::Inter_t,{ID}},
	 {token_class::token::Atom_t,{ID}},
	 {token_class::token::OP_t,{Ter,T2,Lkh,E,E1,F}}, //函数处理
	 {token_class::token::Lkh_t,{Lkh,E,Rkh}}}}, //Ter E2 E2 ID
     {E1,{{token_class::token::D_t,{Ter,T1,E,E1}},
	  {token_class::token::Rkh_t,{Ter}}}},
     {E2,{{token_class::token::Ter_t,{Ter,T}},        //Ter E2 E2 Rkh E2 E2 
	  {token_class::token::D_t,{OP,E}},
	  {token_class::token::OP_t,{OP,E}}}},
     {ID,{{token_class::token::Inter_t,{Ter,ID}},
	  {token_class::token::Atom_t,{Ter,ID}}}},
     {Lkh,{{token_class::token::Lkh_t,{Ter,Lkh}}}},
     {Rkh,{{token_class::token::Rkh_t,{Ter,Rkh}}}},
     {OP,{{token_class::token::OP_t,{Ter,OP}},
	  {token_class::token::D_t,{Ter,OP}}}},
     {T,{{token_class::token::Ter_t,{Ter,T}}}}};
  debug;

  return synatax_bnf[bt][tok.true_type];

  
}

synatax_tree_class::synatax_tree synatax_ptr_class::do_stack_ptr(std::vector<token_class::bnf_token> &bnf_stack,std::vector<token_class::token*> &tok_stack,std::vector<token_class::token*> &op_stack)
{
  static int i=1;
  static token_class::bnf_token ID(token_class::bnf_token::ID);
  synatax_tree_class::synatax_tree ret_sy;

  bnf_stack.pop_back();
  ret_sy=synatax_mod::synatax_read::null_sy_tree;

here:  
  switch(bnf_stack[bnf_stack.size()-1].stat)
  {
  case token_class::bnf_token::ID:
    debug;
    if(!op_stack.empty()&&!(op_stack[op_stack.size()-1]->true_type-token_class::token::OP_t))
    {
      if(op_stack.size()>1)
      {
	token_class::token *op_v=op_stack[op_stack.size()-1];
	token_class::token *op_v1=op_stack[op_stack.size()-2];
	if(!(op_v1->true_type-token_class::token::OP_t)&&op_v->pri>=op_v1->pri)
	// if(true)
	{
	  debug;
	  ret_sy.addr=i;
	  ret_sy.car=op_stack[op_stack.size()-1];
	  token_class::token *tok_v=tok_stack[tok_stack.size()-1];
	  ret_sy.args={tok_stack[tok_stack.size()-2],tok_stack[tok_stack.size()-3]};
	  op_stack.pop_back();
	  op_stack.pop_back();
	  op_stack.push_back(op_v);
	  tok_stack.pop_back();
	  tok_stack.pop_back();
	  tok_stack.pop_back();
	  tok_stack.push_back(new token_class::token(i++));
	  tok_stack.push_back(tok_v);
	  
	  break;

	}

	debug;
	
      }
	
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
    debug;
    op_stack.pop_back();
    tok_stack.pop_back();
    bnf_stack.pop_back();
    bnf_stack.push_back(ID);
    goto here;
    break;
  case token_class::bnf_token::Lkh:
    op_stack.push_back(tok_stack[tok_stack.size()-1]);
    tok_stack.pop_back();
    break;

  case token_class::bnf_token::T:
    printf("%d\n",op_stack.size());
    debug;
    if(op_stack.empty()) break;
    //if(op_stack.empty())
    else
    {
      tok_stack.pop_back();
      ret_sy.addr=i;
      ret_sy.car=op_stack[op_stack.size()-1];
      //  token_class::token *tok_v=tok_stack[tok_stack.size()-1];
      ret_sy.args={tok_stack[tok_stack.size()-1],tok_stack[tok_stack.size()-2]};
      op_stack.pop_back();
      //op_stack.push_back(op_v);
      tok_stack.pop_back();
      tok_stack.pop_back();
      // op_stack.pop_back();
      //tok_stack.pop_back();
      tok_stack.push_back(new token_class::token(i++));
      //tok_stacn.push_back(tok_v);
      
      debug;
      if(op_stack.empty()) break;

    }
    debug;
    
    // tok_stack.pop_back();
    bnf_stack.push_back(ID);
    for(int i=bnf_stack.size()-1;i>=0;i--) printf("qqqq,%d\n",bnf_stack[i].stat);
    break;
    // goto here;

  case token_class::bnf_token::T1:
    ret_sy=D_sy_tree;
    break;

  case token_class::bnf_token::T2:
    op_stack.push_back(tok_stack[tok_stack.size()-1]);
    tok_stack.pop_back();
    tok_stack.push_back(&lexer_mod::lexer_read::null_token);
    break;
    
  case token_class::bnf_token::F:
    // bnf_stack.pop_back();
    op_stack.pop_back();
    ret_sy.addr=i;
    ret_sy.car=op_stack[op_stack.size()-1];
    for(;tok_stack[tok_stack.size()-1]->token_exp;tok_stack.pop_back())
      ret_sy.args.push_back(tok_stack[tok_stack.size()-1]);
    tok_stack.pop_back();
    tok_stack.push_back(new token_class::token(i++));
    op_stack.pop_back();
    break;
    

  // default:ret_sy=null_sy_tree;debug;//bnf_stack.pop_back();
    
  }
  bnf_stack.pop_back();

  debug;
  return ret_sy;

  
}

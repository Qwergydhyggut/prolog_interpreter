#include "lexer/lexer_select.h"
#include <iostream>
#include "token.h"
#include "debug.h"
#include <vector>
#include <cctype>


// enum{atom_obj,atom_var,var,Inter,Init} select_token_class::stat=Init;
// enum{Atom_obj,Atom_var,Var,Inter,Init} select_token_class::stat=Init;
select_token_class::Stat select_token_class::stat=Init;
bool select_token_class::select_token_fun_ptr(char c, char c1)
{
  // printf("lll\n");
  // debug;
here:  
  switch(stat)
  {
  case Init:
    if(is_inter(c)) stat=Inter;
    else if(is_ter(c)) stat=Ter;
    else if(isupper(c)||!(c-'_')) stat=Var;
    else if(is_atom_obj(c)) stat=Atom_obj;
    else if(is_atom_var(c)) stat=Atom_var;
    else if(!(c-' ')||!(c-'\n')) break;
    goto here;

  case Ter:
    // debug;
    return true;
    
  case Atom_obj:
    if(is_atom_obj(c1)) return false;
    //stat=Init;
    break;
    
  case Atom_var:
    // debug;
    if(is_atom_var(c1)) return false;
    //stat=Init;
    break;
    
  case Var:
    if(is_atom_var(c1)) return false;
    //stat=Init;
    break;
    
  case Inter:
    if(is_inter(c1)) return false;
    //stat=Init;
    break;

    //default:  
    
  }  

  return true;
  
  
}  

void select_token_class::select_set_token_ptr(token_class::token &tok)
{
  // printf("aaa\n");
  // debug;
  switch(stat)
  {
  case Atom_var:  
  case Atom_obj: tok.token_type=token_class::token::Atom; break;
  case Var:tok.token_type=token_class::token::Var; break;
  case Inter:tok.token_type=token_class::token::Inter; break;  
  case Ter:tok.token_type=token_class::token::Ter;break;  
    
  }

  stat=Init;
  
  
}  

bool select_token_class::is_atom_var(char c)
{
  if(c<='z'&&c>='a') return true;
  if(c<='Z'&&c>='A') return true;
  if(c>47&&c<58) return true;
  if(!(c-'_')) return true;
  
  return false;
  
  
}
  
bool select_token_class::is_atom_obj(char c)
{
  static std::vector<char> enable_obj(ENABLE_OBJ_INPUT);

  for(int i=0;i<enable_obj.size();i++) if(!(c-enable_obj[i])) return true;
  
  return false;

  
}
  
bool select_token_class::is_ter(char c)
{
  static std::vector<char> ter_obj(ENABLE_TER_INPUT);

  for(int i=0;i<ter_obj.size();i++) if(!(c-ter_obj[i])) return true;
  // std::cout<<c<<'\t'<<ter_obj[1]<<std::endl;
  // std::cin;

  return false;
  
  
}
  
bool select_token_class::is_inter(char c)
{
  if(c>47&&c<58) return true;
  
  return false;

  
}  

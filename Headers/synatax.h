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


namespace synatax_mod
{
  class synatax_read
  {
  public:
    static synatax_tree_class::synatax_tree null_sy_tree;
    synatax_read();
    synatax_read(synatax_ptr_f *spf);

    void operator()(synatax_ptr_f *spf);
    void operator()();
    static std::vector<token_class::bnf_token> next_bnf_list(token_class::bnf_token bt,synatax_ptr_f *spf);
    
  private:

    synatax_ptr_f *spf;
    
  };
  
  
};


#endif

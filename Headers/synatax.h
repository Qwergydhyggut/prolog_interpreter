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
  public:
    static std::map<token_class::token,std::vector<token_class::token>> synatax_dnf;
    synatax_read();
    std::vector<synatax_tree_class::synatax_tree> operator()(token_class::token);
    
  private:
    //std::
    
  };
  
  
};


#endif

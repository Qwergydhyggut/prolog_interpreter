#ifndef __SYNATAX_TREE_INCLUDE__
#define __SYNATAX_TEEE_INCLUDE__
#include <vector>
#include "token.h"


namespace synatax_tree_class
{
  struct synatax_tree
  {
    token_class::token car;
    std::vector<token_class::token> args;
    int addr;
  };
  
  
};

#endif

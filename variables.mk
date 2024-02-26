gcc=x86_64-pc-linux-gnu-g++
link=-std=gnu++20

a=$^ $c-o $@
b=$< $c-o $@

mb=prolog
jg=a
test=test
cs=cs
test-command=test.pr

lo=yuan.o
zj=zj

ycmode_lexer=lexer_main.cpp token_num.cpp lexer_select.cpp
ycmode_synatax=synatax_main.cpp synatax_ptr.cpp
ycmode_analysis=analysis_main.cpp
yc=yuan.cpp $(ycmode_lexer) $(ycmode_synatax) $(ycmode_analysis)
yhmode_lexer=lexer/token_num.h lexer/lexer_select.h
yhmode_synatax=synatax.h synatax_tree.h synatax/meta_map.hpp synatax/synatax_ptr.h
yhmode_analysis=analysis.h
yh=lexer.h token.h debug.h $(yhmode_lexer) $(yhmode_synatax) $(yhmode_analysis)
#yhmode_lexer=lexer/token_num.h lexer/lexer_select.h
#yhmode_synatax=synatax.h synatax_tree.h synatax/meta_map.hpp synatax/synatax_ptr.h
#yrc=
#yo=

ljc=Sources Sources/lexer Sources/synatax Sources/analysis
ljh=Headers
#ljr=Resources
#ljo=Others

SRCS:=$(yc)
GPATH=$(ljc):$(ljr)
VPATH=$(ljo)
vpath %.cpp $(ljc)
vpath %.hpp $(ljh)
vpath %.o $(ljc)
vpath %.h $(ljh)
#vpath %.rc $(ljr)
#vpath %.res $(ljr)
$(jg):c=$(link) 
$(mb):c=$(link) 
# $(lo):c=
# $(zj).i:c=-I$(ljh) 
%.i:c=-I$(ljh) 


.SUFFIXES:
.PHONY:all $(test) test_all

define del
rm -f *.i
rm -f *.s
./$< $(test-command)
endef

define delfirst
        $(wordlist 2,$(words $1),$1)
endef

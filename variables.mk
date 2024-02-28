gcc=x86_64-pc-linux-gnu-g++
link=-std=gnu++20 -O2 -lmysqlclient

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
ycmode_mysql=mysql_connect.cpp
ycmode_source_read=source_read.cpp
yc=yuan.cpp $(ycmode_lexer) $(ycmode_synatax) $(ycmode_analysis) $(ycmode_mysql) $(ycmode_source_read)
yhmode_lexer=lexer/token_num.h lexer/lexer_select.h
yhmode_synatax=synatax.h synatax_tree.h synatax/meta_map.hpp synatax/synatax_ptr.h
yhmode_analysis=analysis.h
yhmode_mysql=mysql_connect.h
yhmode_source_read=source_read.cpp
yh=lexer.h token.h debug.h $(yhmode_lexer) $(yhmode_synatax) $(yhmode_analysis) $(yhmode_mysql) $(yhmode_source_read)
#yhmode_lexer=lexer/token_num.h lexer/lexer_select.h
#yhmode_synatax=synatax.h synatax_tree.h synatax/meta_map.hpp synatax/synatax_ptr.h
#yrc=
#yo=

ljc=Sources Sources/lexer Sources/synatax Sources/analysis Sources/mysql_connect Sources/source_read
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

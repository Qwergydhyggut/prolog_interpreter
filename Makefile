gcc=x86_64-pc-linux-gnu-g++
link=

a=$^ $c-o $@
b=$< $c-o $@ 

mb=prolog
jg=a
cs=cs
test-command=test.pr

lo=yuan.o
zj=zj

yc=yuan.cpp lexer_main.cpp
yh=lexer.h token.h debug.h
#yrc=
#yo=

ljc=Sources Sources/lexer
ljh=Headers
#ljr=Resources
#ljo=Others

SRCS:=$(yc)
GPATH=$(ljc):$(ljr)
VPATH=$(ljo)
vpath %.cpp $(ljc)
vpath %.o $(ljc)
vpath %.h $(ljh)
#vpath %.rc $(ljr)
#vpath %.res $(ljr)
$(jg):c=$(link)
$(mb):c=$(link)
# $(lo):c=
# $(zj).i:c=-I$(ljh) 
%.i:c=-I$(ljh) 

all:$(jg)
	$(del)

$(jg):$(SRCS:.cpp=.o)
	$(gcc) $a

%.o:%.s
	$(gcc) -c $a

%.s:%.i
	$(gcc) -S $a

%.i:%.cpp $(yh)
	$(gcc) -E $b

$(cs):$(mb)
	del $(jg)
	$(del)


$(mb):$(lo)
	$(gcc) $a

.SUFFIXES:
.PHONY:all

define del
rm -f *.i
rm -f *.s
./$< $(test-command)
endef

include ../variables.mk


#gcc=x86_64-pc-linux-gnu-g++
#link=

#a=$^ $c-o $@
#b=$< $c-o $@ 

#mb=prolog
test_jg=test_$(jg)
#cs=cs
#test-command=test.pr

#lo=yuan.o
#zj=zj

test_yc=$(call delfirst,$(yc)) lexer_test.cpp
#yh=
#yrc=
#yo=

#test_ljc=../Sources/lexer
test_ljc=$(addprefix ../,$(call delfirst,$(ljc))) #$(wordlist 2,$(words $(ljc)),$(ljc)))
test_ljh=$(addprefix ../,$(ljh)) #$(wordlist 2,$(words $(ljh)),$(ljh)))
#ljr=Resources
#ljo=Others

SRCS=$(test_yc)
#GPATH=$(ljc):$(ljr)
#VPATH=$(ljo)
#vpath %.cpp $(test_ljc)
vpath %.o $(test_ljc) #../Sources/lexer
vpath %.h $(test_ljh)
#vpath %.o ../Sources/lexer
#vpath %.rc $(ljr)
#vpath %.res $(ljr)
#$(jg):c=$(link)
#$(mb):c=$(link)
# $(lo):c=
# $(zj).i:c=-I$(ljh) 
%.i:c=-I$(test_ljh) 

test_all:$(test_jg)
#	echo "aaaaaaaaaa"
#	$(info $(SRCS))
#	$(info $(SRCS:.cpp=.o))
#	echo $<
	$(del)

$(test_jg):$(SRCS:.cpp=.o)
#	echo "llllllllllll"
#	echo $(SRCS)
#	echo "ooooo"
#	echo $(yc:.cpp=.o)
#        $(info $(SRCS))
#        $(info $(SRCS:.cpp=.o))
#	echo $(call delfirst,$(ljc))
#	echo $(test_ljc)
#	echo $(SRCS:.cpp:.o)
#	echo "ttttttt"
#	echo $(addprefix ../,$(test_yc))
#	echo $^
#	echo $@
	$(gcc) $a

%.o:%.s
	$(gcc) -c $a

%.s:%.i
	$(gcc) -S $a

%.i:%.cpp $(test_yh)
	$(gcc) -E $b

#$(cs):$(mb)
#	del $(jg)
#	$(del)


#$(mb):$(lo)
#	$(gcc) $a

#.SUFFIXES:
#.PHONY:test_all

#define del
#rm -f *.i
#rm -f *.s
#./$< $(test-command)
#endef

define delfirst
	$(wordlist 2,$(words $1),$1)
endef


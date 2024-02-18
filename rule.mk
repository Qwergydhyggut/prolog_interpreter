all:$(jg)
#	include debug/Makefile
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

$(test):
	make -C debug


$(mb):$(lo)
	$(gcc) $a

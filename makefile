CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g -O3
LDFLAGS=-g -O3

SRCS=randmst.cpp graphs.cpp binaryheap.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: randmst

randmst: $(OBJS)
	$(CXX) $(LDFLAGS) -o randmst $(OBJS)

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) *~ .depend

include: .depend
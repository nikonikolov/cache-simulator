CPPFLAGS += -W -Wall -g
CPPFLAGS += -I include

CFLAGS	 += -std=c99
CXXFLAGS += -std=c++11
CXXFLAGS += -w

# Force the inclusion of C++ standard libraries
LDLIBS += -lstdc++

CACHE_SRCS = \
    $(wildcard mem_sim_*.cpp) 
    
CACHE_OBJECTS = $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(CACHE_SRCS)))

mem_sim : mem_sim.cpp $(CACHE_OBJECTS)

clean:
	$(RM) $(CACHE_OBJECTS)
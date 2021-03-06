#==========================================================================
#                         Directories and names 
# ==========================================================================

LIMBO_ROOT_DIR = /home/jumper/Documents/PDA/limbo
OBJDIR = ../obj
MKDIR = if [ ! -d $(@D) ]; then mkdir -p $(@D); fi

VPATH = .

#==========================================================================
#                         Compilation Flags
# ==========================================================================

# default DBG is off
DBG = 0

# include environmental configurations 
include $(LIMBO_ROOT_DIR)/Include.mk

ifeq ($(DBG), 1)
	CXXFLAGS = $(CXXFLAGS_DEBUG) -DDEBUG_DEFPARSER -DDEBUG_LEFPARSER #-Wl,--no-as-needed -std=c++11 -pthread
else
	CXXFLAGS = $(CXXFLAGS_RELEASE) #-Wl,--no-as-needed -std=c++11 -pthread
endif

#==========================================================================
#                         Special Library
# ==========================================================================

INCLUDE = -I $(realpath .) \
		  -I $(LIMBO_ROOT_DIR) \
		  -I $(LEX_INCLUDE_DIR) \
		  -I $(BOOST_DIR)/include

# ==========================================================================
#                         Standard Setting
# ==========================================================================

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)
DEPS = $(OBJS:%.o=%.d) 	# one dependency file for each source

all: jumper_read

# Compile dependency 

$(OBJDIR)/%.d: %.cpp
	@$(MKDIR)
	$(CXX) $(CXXFLAGS) $< -MM -MT $(@:%.d=%.o) >$@ $(INCLUDE)

-include $(DEPS)

# Implicit rule to compile c++ files

$(OBJDIR)/%.o: %.cpp
	@$(MKDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(INCLUDE) 

# Link executable
jumper_read: $(OBJDIR)/main.o $(OBJDIR)/data_structure.o 
	$(CXX) $(CXXFLAGS) -o $@ $(OBJDIR)/main.o $(OBJDIR)/data_structure.o -I $(LIMBO_ROOT_DIR)/include -L $(LIMBO_ROOT_DIR)/lib -llefparseradapt -L$(LIMBO_ROOT_DIR)/lib -ldefparseradapt


.PHONY: clean
clean: cleandep
	rm -f jumper_read
	rm -f $(OBJS)

.PHONY: cleandep
cleandep:
	rm -f $(DEPS)

.PHONY: extraclean
extraclean: clean
	rm -rf $(OBJDIR)

# Compiler settings
CC = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = 

# Makefile settings
APPNAME = tree
EXT = .cpp
SRCDIR = .
OBJDIR = obj

SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(patsubst $(SRCDIR)/%$(EXT),$(OBJDIR)/%.o,$(SRC))
DEP = $(OBJ:.o=.d)

RM = rm -f
MKDIR_P = mkdir -p

all: $(APPNAME) clean-objdir

# Builds the app
$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Creates the dependency rules
$(OBJDIR)/%.d: $(SRCDIR)/%$(EXT)
	@$(MKDIR_P) $(OBJDIR)
	@$(CC) $(CXXFLAGS) $< -MM -MT $(@:%.d=%.o) >$@

# Includes all dependency files
-include $(DEP)

# Building rule for .o files and its .cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	@$(MKDIR_P) $(OBJDIR)
	$(CC) $(CXXFLAGS) -o $@ -c $<

# Removes the obj directory after the build
.PHONY: clean-objdir
clean-objdir:
	$(RM) -r $(OBJDIR)

# Cleans complete project
.PHONY: clean
clean:
	$(RM) $(OBJ) $(DEP) $(APPNAME)

# Cleans only all files with the extension .d
.PHONY: cleandep
cleandep:
	$(RM) $(DEP)

CC=gcc
RM=rm -vf
INCDIR=$(CURDIR)/include
LIBDIR=$(CURDIR)/lib
OBJDIR=$(CURDIR)/obj
TESTDIR=$(CURDIR)/testes
CFLAGS=-Wall       \
       -Wextra     \
       -Werror     \
       -pedantic   \
       -I$(INCDIR) \
       -g
LIBS=fila lista pilha
TESTS=$(LIBS:%=teste-%)

export CC RM INCDIR LIBDIR OBJDIR CFLAGS LIBS

.PHONY: all
all: $(LIBS) $(TESTS)

$(LIBDIR):
	@mkdir -pv $@

$(OBJDIR):
	@mkdir -pv $@

$(LIBDIR)/lib%.a: $(LIBDIR) $(OBJDIR)
	$(MAKE) -C src/$*

.PHONY: $(LIBS)
$(LIBS): %: $(LIBDIR)/lib%.a

.PHONY: $(TESTS)
$(TESTS): teste-%: $(TESTDIR)/teste-%

$(TESTDIR)/teste-%: $(LIBDIR)/lib%.a
	$(MAKE) -C $(TESTDIR) teste-$*
	$(TESTDIR)/teste-$*

.PHONY: clean
clean:
	-@$(RM) -r $(OBJDIR)
	$(MAKE) -C $(TESTDIR) clean

.PHONY: mrproper
mrproper: clean
	-@$(RM) -r $(LIBDIR)
	$(MAKE) -C $(TESTDIR) mrproper

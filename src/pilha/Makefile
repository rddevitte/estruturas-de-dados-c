OBJS=$(addprefix $(OBJDIR)/,pilha.o nodopilha.o)

.PHONY: all
all: pilha

$(OBJDIR)/%.o: %.c
	$(CC) -c $^ -o $@ $(CFLAGS)

$(LIBDIR)/libpilha.a: $(OBJS)
	ar rcs $@ $^

.PHONY: pilha
pilha: $(LIBDIR)/libpilha.a

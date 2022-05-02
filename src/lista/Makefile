OBJS=$(addprefix $(OBJDIR)/,lista.o nodolista.o)

.PHONY: all
all: lista

$(OBJDIR)/%.o: %.c
	$(CC) -c $^ -o $@ $(CFLAGS)

$(LIBDIR)/liblista.a: $(OBJS)
	ar rcs $@ $^

.PHONY: lista
lista: $(LIBDIR)/liblista.a

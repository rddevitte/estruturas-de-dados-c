OBJS=$(addprefix $(OBJDIR)/,fila.o nodofila.o)

.PHONY: all
all: fila

$(OBJDIR)/%.o: %.c
	$(CC) -c $^ -o $@ $(CFLAGS)

$(LIBDIR)/libfila.a: $(OBJS)
	ar rcs $@ $^

.PHONY: fila
fila: $(LIBDIR)/libfila.a

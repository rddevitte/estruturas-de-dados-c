.PHONY: all
all: $(TESTS)

letra.o: letra/letra.c
	$(CC) -c $< -o $@ $(CFLAGS)

nums.o: nums/nums.c
	$(CC) -c $< -o $@ $(CFLAGS)

teste-%.o: teste-%.c
	$(CC) -c $< -o $@ $(CFLAGS)

teste-%: teste-%.o letra.o nums.o
	$(CC) $^ -o $@ -L$(LIBDIR) -l$*

.PHONY: clean
clean:
	-@$(RM) *.o

.PHONY: mrproper
mrproper: clean
	-@$(RM) $(TESTS)

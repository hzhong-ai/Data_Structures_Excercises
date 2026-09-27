CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -Wno-unused-parameter -g

SRCS = $(wildcard *.c)
BINS = $(SRCS:.c=)

.PHONY: all test valgrind clean

all: $(BINS)

%: %.c Node.h
	$(CC) $(CFLAGS) $< -o $@

test: all
	@echo "=== EJECUTANDO SUITE DE PRUEBAS ==="
	@for bin in $(BINS); do \
		echo "-> Corriendo $$bin..."; \
		./$$bin || exit 1; \
	done
	@echo "==================================="
	@echo "¡Todos los tests pasaron con éxito!"

valgrind: all
	@echo "=== VERIFICANDO MEMORIA CON VALGRIND ==="
	@for bin in $(BINS); do \
		echo "-> Analizando $$bin..."; \
		valgrind --leak-check=full --errors-for-leak-kinds=all --error-exitcode=1 ./$$bin > /dev/null 2>&1 || exit 1; \
	done
	@echo "========================================"
	@echo "0 leaks detectados."

clean:
	rm -f $(BINS) *.o

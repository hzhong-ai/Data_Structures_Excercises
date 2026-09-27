CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -g

SRCS = $(wildcard *.cpp)
BINS = $(SRCS:.cpp=)

.PHONY: all test clean

all: $(BINS)

%: %.cpp
	$(CC) $(CFLAGS) $< -o $@

test: all
	@for bin in $(BINS); do \
		echo "Running $$bin..."; \
		./$$bin || exit 1; \
	done
	@echo "All tests passed!"

clean:
	rm -f $(BINS)

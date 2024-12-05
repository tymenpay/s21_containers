G++ = g++ -std=c++17
CFLAGS= -Wall -Wextra -Werror
TEST_LIBS = -lgtest -pthread
TEST_SRC = vector/test_vector.cc list/test_list.cc stack/test_stack.cc queue/test_queue.cc set/test_set.cc map/test_map.cc
TEST_NAME = test

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
    OS_FLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib -L/usr/local/lib
else
    OS_FLAGS = 
endif

all: $(TEST_NAME)

$(TEST_NAME): 
	$(G++) $(CFLAGS) $(OS_FLAGS) $(TEST_SRC) -o $(TEST_NAME) $(TEST_LIBS) -g
	./$(TEST_NAME) --gtest_break_on_failure

memmory: test
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(TEST_NAME)

format:
	clang-format -i *.cc *.h in_addition/*.cc *.h

clean: 
	rm -rf $(TEST_NAME) *.o *.a test.dSYM

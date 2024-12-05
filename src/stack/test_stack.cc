#include <gtest/gtest.h>

#include <stack>
#include <string>

#include "s21_stack.h"

TEST(TestStackConstruct, TestStackConstruct1) {
  s21::stack<int> a;
  std::stack<int> b;
  EXPECT_EQ(a.empty(), b.empty());
}
TEST(TestStackConstruct, TestStackConstruct2) {
  s21::stack<double> a;
  std::stack<double> b;
  EXPECT_EQ(a.empty(), b.empty());
}
TEST(TestStackConstruct, TestStackConstruct3) {
  s21::stack<char> a;
  std::stack<char> b;
  EXPECT_EQ(a.empty(), b.empty());
}

TEST(TeststackConstruct, TeststackConstructInit1) {
  s21::stack<int> our_stack = {1, 2, 3};
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  EXPECT_EQ(our_stack.top(), std_stack.top());
}

TEST(TestStackConstruct, TestStackConstructInit2) {
  s21::stack<double> our_stack{1.23, 12.5, 13.37, 0.556};
  std::stack<double> std_stack;
  std_stack.push(1.23);
  std_stack.push(12.5);
  std_stack.push(13.37);
  std_stack.push(0.556);
  EXPECT_EQ(our_stack.top(), std_stack.top());
}
TEST(TestStackConstruct, TestStackConstructInit3) {
  s21::stack<char> our_stack{'p', 'i', 'x', 'a', 'r'};
  std::stack<char> std_stack;
  std_stack.push('p');
  std_stack.push('i');
  std_stack.push('x');
  std_stack.push('a');
  std_stack.push('r');
  EXPECT_EQ(our_stack.top(), std_stack.top());
}
TEST(TestStackConstruct, TestStackConstructInit4) {
  s21::stack<std::string> our_stack{"world", "wild", "empty"};
  std::stack<std::string> std_stack;
  std_stack.push("world");
  std_stack.push("wild");
  std_stack.push("empty");
  EXPECT_EQ(our_stack.top(), std_stack.top());
}

TEST(Stack, Constructor_Copy1) {
  s21::stack<int> our_stack = {1, 2, 3};
  s21::stack<int> our_copy(our_stack);
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  std::stack<int> std_copy(std_stack);
  EXPECT_EQ(our_copy.top(), std_copy.top());
}
TEST(Stack, Constructor_Copy2) {
  s21::stack<double> our_stack = {1.23, 12.5, 13.37, 0.556};
  s21::stack<double> our_copy(our_stack);
  std::stack<double> std_stack;
  std_stack.push(1.23);
  std_stack.push(12.5);
  std_stack.push(13.37);
  std_stack.push(0.556);
  std::stack<double> std_copy(std_stack);
  EXPECT_EQ(our_copy.top(), std_copy.top());
}
TEST(Stack, Constructor_Copy3) {
  s21::stack<char> our_stack = {'p', 'i', 'x', 'a', 'r'};
  s21::stack<char> our_copy(our_stack);
  std::stack<char> std_stack;
  std_stack.push('p');
  std_stack.push('i');
  std_stack.push('x');
  std_stack.push('a');
  std_stack.push('r');
  std::stack<char> std_copy(std_stack);
  EXPECT_EQ(our_copy.top(), std_copy.top());
}
TEST(Stack, Constructor_Copy4) {
  s21::stack<std::string> our_stack{"world", "wild", "empty"};
  s21::stack<std::string> our_copy(our_stack);
  std::stack<std::string> std_stack;
  std_stack.push("world");
  std_stack.push("wild");
  std_stack.push("empty");
  std::stack<std::string> std_copy(std_stack);
  EXPECT_EQ(our_copy.top(), std_copy.top());
}

TEST(Stack, Operator_Copy1) {
  s21::stack<int> our_stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  s21::stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  our_stack_empty = our_stack_int;
  std_stack_empty = std_stack_int;
  EXPECT_EQ(our_stack_empty.top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}
TEST(Stack, Operator_Copy2) {
  s21::stack<double> our_stack_int = {1.23, 12.5, 13.37, 0.556};
  std::stack<double> std_stack_int;
  std_stack_int.push(1.23);
  std_stack_int.push(12.5);
  std_stack_int.push(13.37);
  std_stack_int.push(0.556);
  s21::stack<double> our_stack_empty;
  std::stack<double> std_stack_empty;
  our_stack_empty = our_stack_int;
  std_stack_empty = std_stack_int;
  EXPECT_EQ(our_stack_empty.top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}
TEST(Stack, Operator_Copy3) {
  s21::stack<char> our_stack_int = {'p', 'i', 'x', 'a', 'r'};
  std::stack<char> std_stack_int;
  std_stack_int.push('p');
  std_stack_int.push('i');
  std_stack_int.push('x');
  std_stack_int.push('a');
  std_stack_int.push('r');
  s21::stack<char> our_stack_empty;
  std::stack<char> std_stack_empty;
  our_stack_empty = our_stack_int;
  std_stack_empty = std_stack_int;
  EXPECT_EQ(our_stack_empty.top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}
TEST(Stack, Operator_Copy4) {
  s21::stack<std::string> our_stack_int = {"world", "wild", "empty"};
  std::stack<std::string> std_stack_int;
  std_stack_int.push("world");
  std_stack_int.push("wild");
  std_stack_int.push("empty");
  s21::stack<std::string> our_stack_empty;
  std::stack<std::string> std_stack_empty;
  our_stack_empty = our_stack_int;
  std_stack_empty = std_stack_int;
  EXPECT_EQ(our_stack_empty.top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}

TEST(Stack, Constructor_Move1) {
  s21::stack<int> our_stack = {1, 2, 3};
  s21::stack<int> our_move(std::move(our_stack));
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  std::stack<int> std_move(std::move(std_stack));
  EXPECT_EQ(our_move.top(), std_move.top());
  EXPECT_EQ(our_stack.empty(), std_stack.empty());
}
TEST(Stack, Constructor_Move2) {
  s21::stack<double> our_stack = {1.23, 12.5, 13.37, 0.556};
  s21::stack<double> our_move(std::move(our_stack));
  std::stack<double> std_stack;
  std_stack.push(1.23);
  std_stack.push(12.5);
  std_stack.push(13.37);
  std_stack.push(0.556);
  std::stack<double> std_move(std::move(std_stack));
  EXPECT_EQ(our_move.top(), std_move.top());
  EXPECT_EQ(our_stack.empty(), std_stack.empty());
}
TEST(Stack, Constructor_Move3) {
  s21::stack<char> our_stack = {'p', 'i', 'x', 'a', 'r'};
  s21::stack<char> our_move(std::move(our_stack));
  std::stack<char> std_stack;
  std_stack.push('p');
  std_stack.push('i');
  std_stack.push('x');
  std_stack.push('a');
  std_stack.push('r');
  std::stack<char> std_move(std::move(std_stack));
  EXPECT_EQ(our_move.top(), std_move.top());
  EXPECT_EQ(our_stack.empty(), std_stack.empty());
}
TEST(Stack, Constructor_Move4) {
  s21::stack<std::string> our_stack = {"world", "wild", "empty"};
  s21::stack<std::string> our_move(std::move(our_stack));
  std::stack<std::string> std_stack;
  std_stack.push("world");
  std_stack.push("wild");
  std_stack.push("empty");
  std::stack<std::string> std_move(std::move(std_stack));
  EXPECT_EQ(our_move.top(), std_move.top());
  EXPECT_EQ(our_stack.empty(), std_stack.empty());
}

TEST(Stack, Operator_Move1) {
  s21::stack<int> our_stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  s21::stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  our_stack_empty = std::move(our_stack_int);
  std_stack_empty = std::move(std_stack_int);
  EXPECT_EQ(our_stack_empty.top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}
TEST(Stack, Operator_Move2) {
  s21::stack<double> our_stack_int = {1.23, 12.5, 13.37, 0.556};
  std::stack<double> std_stack_int;
  std_stack_int.push(1.23);
  std_stack_int.push(12.5);
  std_stack_int.push(13.37);
  std_stack_int.push(0.556);
  s21::stack<double> our_stack_empty;
  std::stack<double> std_stack_empty;
  our_stack_empty = std::move(our_stack_int);
  std_stack_empty = std::move(std_stack_int);
  EXPECT_EQ(our_stack_empty.top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}
TEST(Stack, Operator_Move3) {
  s21::stack<char> our_stack_int = {'p', 'i', 'x', 'a', 'r'};
  std::stack<char> std_stack_int;
  std_stack_int.push('p');
  std_stack_int.push('i');
  std_stack_int.push('x');
  std_stack_int.push('a');
  std_stack_int.push('r');
  s21::stack<char> our_stack_empty;
  std::stack<char> std_stack_empty;
  our_stack_empty = std::move(our_stack_int);
  std_stack_empty = std::move(std_stack_int);
  EXPECT_EQ(our_stack_empty.top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}
TEST(Stack, Operator_Move4) {
  s21::stack<std::string> our_stack_int = {"world", "wild", "empty"};
  std::stack<std::string> std_stack_int;
  std_stack_int.push("world");
  std_stack_int.push("wild");
  std_stack_int.push("empty");
  s21::stack<std::string> our_stack_empty;
  std::stack<std::string> std_stack_empty;
  our_stack_empty = std::move(our_stack_int);
  std_stack_empty = std::move(std_stack_int);
  EXPECT_EQ(our_stack_empty.top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}

TEST(Stack, Top) {
  s21::stack<int> our_stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  s21::stack<double> our_stack_double = {1.23, 12.5, 13.37, 0.556};
  std::stack<double> std_stack_double;
  std_stack_double.push(1.23);
  std_stack_double.push(12.5);
  std_stack_double.push(13.37);
  std_stack_double.push(0.556);
  s21::stack<char> our_stack_char = {'p', 'i', 'x', 'a', 'r'};
  std::stack<char> std_stack_char;
  std_stack_char.push('p');
  std_stack_char.push('i');
  std_stack_char.push('x');
  std_stack_char.push('a');
  std_stack_char.push('r');
  s21::stack<std::string> our_stack_string = {"world", "wild", "empty"};
  std::stack<std::string> std_stack_string;
  std_stack_string.push("world");
  std_stack_string.push("wild");
  std_stack_string.push("empty");
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
  EXPECT_EQ(our_stack_double.top(), std_stack_double.top());
  EXPECT_EQ(our_stack_char.top(), std_stack_char.top());
  EXPECT_EQ(our_stack_string.top(), std_stack_string.top());
}

TEST(Stack, Empty1) {
  s21::stack<int> our_stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
  s21::stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  EXPECT_EQ(our_stack_empty.empty(), std_stack_empty.empty());
}
TEST(Stack, Empty2) {
  s21::stack<double> our_stack_int = {1.23, 12.5, 13.37, 0.556};
  std::stack<double> std_stack_int;
  std_stack_int.push(1.23);
  std_stack_int.push(12.5);
  std_stack_int.push(13.37);
  std_stack_int.push(0.556);
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
  s21::stack<double> our_stack_empty;
  std::stack<double> std_stack_empty;
  EXPECT_EQ(our_stack_empty.empty(), std_stack_empty.empty());
}
TEST(Stack, Empty3) {
  s21::stack<char> our_stack_int = {'p', 'i', 'x', 'a', 'r'};
  std::stack<char> std_stack_int;
  std_stack_int.push('p');
  std_stack_int.push('i');
  std_stack_int.push('x');
  std_stack_int.push('a');
  std_stack_int.push('r');
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
  s21::stack<char> our_stack_empty;
  std::stack<char> std_stack_empty;
  EXPECT_EQ(our_stack_empty.empty(), std_stack_empty.empty());
}
TEST(Stack, Empty4) {
  s21::stack<std::string> our_stack_int = {"world", "wild", "empty"};
  std::stack<std::string> std_stack_int;
  std_stack_int.push("world");
  std_stack_int.push("wild");
  std_stack_int.push("empty");
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
  s21::stack<std::string> our_stack_empty;
  std::stack<std::string> std_stack_empty;
  EXPECT_EQ(our_stack_empty.empty(), std_stack_empty.empty());
}

TEST(Stack, Size1) {
  s21::stack<int> our_stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  EXPECT_EQ(our_stack_int.size(), std_stack_int.size());
  s21::stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  EXPECT_EQ(our_stack_empty.size(), std_stack_empty.size());
}
TEST(Stack, Size2) {
  s21::stack<double> our_stack_int = {1.23, 12.5, 13.37, 0.556};
  std::stack<double> std_stack_int;
  std_stack_int.push(1.23);
  std_stack_int.push(12.5);
  std_stack_int.push(13.37);
  std_stack_int.push(0.556);
  EXPECT_EQ(our_stack_int.size(), std_stack_int.size());
  s21::stack<double> our_stack_empty;
  std::stack<double> std_stack_empty;
  EXPECT_EQ(our_stack_empty.size(), std_stack_empty.size());
}
TEST(Stack, Size3) {
  s21::stack<char> our_stack_int = {'p', 'i', 'x', 'a', 'r'};
  std::stack<char> std_stack_int;
  std_stack_int.push('p');
  std_stack_int.push('i');
  std_stack_int.push('x');
  std_stack_int.push('a');
  std_stack_int.push('r');
  EXPECT_EQ(our_stack_int.size(), std_stack_int.size());
  s21::stack<char> our_stack_empty;
  std::stack<char> std_stack_empty;
  EXPECT_EQ(our_stack_empty.size(), std_stack_empty.size());
}
TEST(Stack, Size4) {
  s21::stack<std::string> our_stack_int = {"world", "wild", "empty"};
  std::stack<std::string> std_stack_int;
  std_stack_int.push("world");
  std_stack_int.push("wild");
  std_stack_int.push("empty");
  EXPECT_EQ(our_stack_int.size(), std_stack_int.size());
  s21::stack<std::string> our_stack_empty;
  std::stack<std::string> std_stack_empty;
  EXPECT_EQ(our_stack_empty.size(), std_stack_empty.size());
}

TEST(Stack, Push1) {
  s21::stack<int> our_stack_int;
  our_stack_int.push(1);
  our_stack_int.push(2);
  our_stack_int.push(3);
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
}
TEST(Stack, Push2) {
  s21::stack<double> our_stack_int;
  our_stack_int.push(1.23);
  our_stack_int.push(12.5);
  our_stack_int.push(13.37);
  our_stack_int.push(0.556);
  std::stack<double> std_stack_int;
  std_stack_int.push(1.23);
  std_stack_int.push(12.5);
  std_stack_int.push(13.37);
  std_stack_int.push(0.556);
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
}
TEST(Stack, Push3) {
  s21::stack<char> our_stack_int;
  our_stack_int.push('p');
  our_stack_int.push('i');
  our_stack_int.push('x');
  our_stack_int.push('a');
  our_stack_int.push('r');
  std::stack<char> std_stack_int;
  std_stack_int.push('p');
  std_stack_int.push('i');
  std_stack_int.push('x');
  std_stack_int.push('a');
  std_stack_int.push('r');
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
}
TEST(Stack, Push4) {
  s21::stack<std::string> our_stack_int;
  our_stack_int.push("world");
  our_stack_int.push("wild");
  our_stack_int.push("empty");
  std::stack<std::string> std_stack_int;
  std_stack_int.push("world");
  std_stack_int.push("wild");
  std_stack_int.push("empty");
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
}

TEST(Stack, Pop1) {
  s21::stack<int> our_stack_int;
  our_stack_int.push(1);
  our_stack_int.push(2);
  our_stack_int.push(3);
  our_stack_int.pop();
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  std_stack_int.pop();
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
  our_stack_int.pop();
  our_stack_int.pop();
  std_stack_int.pop();
  std_stack_int.pop();
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}
TEST(Stack, Pop2) {
  s21::stack<double> our_stack_int;
  our_stack_int.push(1.23);
  our_stack_int.push(12.5);
  our_stack_int.push(13.37);
  our_stack_int.push(0.556);
  our_stack_int.pop();
  std::stack<double> std_stack_int;
  std_stack_int.push(1.23);
  std_stack_int.push(12.5);
  std_stack_int.push(13.37);
  std_stack_int.push(0.556);
  std_stack_int.pop();
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
  our_stack_int.pop();
  our_stack_int.pop();
  std_stack_int.pop();
  std_stack_int.pop();
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}
TEST(Stack, Pop3) {
  s21::stack<char> our_stack_int;
  our_stack_int.push('p');
  our_stack_int.push('i');
  our_stack_int.push('x');
  our_stack_int.push('a');
  our_stack_int.push('r');
  our_stack_int.pop();
  std::stack<char> std_stack_int;
  std_stack_int.push('p');
  std_stack_int.push('i');
  std_stack_int.push('x');
  std_stack_int.push('a');
  std_stack_int.push('r');
  std_stack_int.pop();
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
  our_stack_int.pop();
  our_stack_int.pop();
  std_stack_int.pop();
  std_stack_int.pop();
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}
TEST(Stack, Pop4) {
  s21::stack<std::string> our_stack_int;
  our_stack_int.push("world");
  our_stack_int.push("wild");
  our_stack_int.push("empty");
  our_stack_int.pop();
  std::stack<std::string> std_stack_int;
  std_stack_int.push("world");
  std_stack_int.push("wild");
  std_stack_int.push("empty");
  std_stack_int.pop();
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
  our_stack_int.pop();
  our_stack_int.pop();
  std_stack_int.pop();
  std_stack_int.pop();
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}

TEST(Stack, Swap1) {
  s21::stack<int> our_stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  s21::stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  our_stack_empty.swap(our_stack_int);
  std_stack_empty.swap(std_stack_int);
  EXPECT_EQ(our_stack_empty.top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}
TEST(Stack, Swap2) {
  s21::stack<double> our_stack_int = {1.23, 12.5, 13.37, 0.556};
  std::stack<double> std_stack_int;
  std_stack_int.push(1.23);
  std_stack_int.push(12.5);
  std_stack_int.push(13.37);
  std_stack_int.push(0.556);
  s21::stack<double> our_stack_empty;
  std::stack<double> std_stack_empty;
  our_stack_empty.swap(our_stack_int);
  std_stack_empty.swap(std_stack_int);
  EXPECT_EQ(our_stack_empty.top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}
TEST(Stack, Swap3) {
  s21::stack<char> our_stack_int = {'p', 'i', 'x', 'a', 'r'};
  std::stack<char> std_stack_int;
  std_stack_int.push('p');
  std_stack_int.push('i');
  std_stack_int.push('x');
  std_stack_int.push('a');
  std_stack_int.push('r');
  s21::stack<char> our_stack_empty;
  std::stack<char> std_stack_empty;
  our_stack_empty.swap(our_stack_int);
  std_stack_empty.swap(std_stack_int);
  EXPECT_EQ(our_stack_empty.top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}
TEST(Stack, Swap4) {
  s21::stack<std::string> our_stack_int = {"world", "wild", "empty"};
  std::stack<std::string> std_stack_int;
  std_stack_int.push("world");
  std_stack_int.push("wild");
  std_stack_int.push("empty");
  s21::stack<std::string> our_stack_empty;
  std::stack<std::string> std_stack_empty;
  our_stack_empty.swap(our_stack_int);
  std_stack_empty.swap(std_stack_int);
  EXPECT_EQ(our_stack_empty.top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}

TEST(StackString, FrontAndBack) {
  s21::stack<int> our_stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  s21::stack<double> our_stack_double = {1.23, 12.5, 13.37, 0.556};
  std::stack<double> std_stack_double;
  std_stack_double.push(1.23);
  std_stack_double.push(12.5);
  std_stack_double.push(13.37);
  std_stack_double.push(0.556);
  s21::stack<char> our_stack_char = {'p', 'i', 'x', 'a', 'r'};
  std::stack<char> std_stack_char;
  std_stack_char.push('p');
  std_stack_char.push('i');
  std_stack_char.push('x');
  std_stack_char.push('a');
  std_stack_char.push('r');
  s21::stack<std::string> our_stack_string = {"world", "wild", "empty"};
  std::stack<std::string> std_stack_string;
  std_stack_string.push("world");
  std_stack_string.push("wild");
  std_stack_string.push("empty");
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
  EXPECT_EQ(our_stack_double.top(), std_stack_double.top());
  EXPECT_EQ(our_stack_char.top(), std_stack_char.top());
  EXPECT_EQ(our_stack_string.top(), std_stack_string.top());
}

TEST(Stack, InsertManyFront1) {
  s21::stack<int> our_stack_int;
  our_stack_int.insert_many_back(1, 2, 3);
  EXPECT_EQ(our_stack_int.top(), 3);
  our_stack_int.pop();
  EXPECT_EQ(our_stack_int.top(), 2);
  our_stack_int.insert_many_back(4, 5, 6);
  EXPECT_EQ(our_stack_int.top(), 6);
  our_stack_int.pop();
  EXPECT_EQ(our_stack_int.top(), 5);
}
TEST(Stack, InsertManyFront2) {
  s21::stack<double> our_stack_int;
  our_stack_int.insert_many_back(1.23, 12.5, 13.37, 0.556);
  EXPECT_EQ(our_stack_int.top(), 0.556);
  our_stack_int.pop();
  EXPECT_EQ(our_stack_int.top(), 13.37);
  our_stack_int.insert_many_back(9.25, 31.13, 166.7);
  EXPECT_EQ(our_stack_int.top(), 166.7);
  our_stack_int.pop();
  EXPECT_EQ(our_stack_int.top(), 31.13);
}
TEST(Stack, InsertManyFront3) {
  s21::stack<char> our_stack_int;
  our_stack_int.insert_many_back('p', 'i', 'x', 'a', 'r');
  EXPECT_EQ(our_stack_int.top(), 'r');
  our_stack_int.pop();
  EXPECT_EQ(our_stack_int.top(), 'a');
  our_stack_int.insert_many_back('m', 't', 'v');
  EXPECT_EQ(our_stack_int.top(), 'v');
  our_stack_int.pop();
  EXPECT_EQ(our_stack_int.top(), 't');
}
TEST(Stack, InsertManyFront4) {
  s21::stack<std::string> our_stack_int;
  our_stack_int.insert_many_back("world", "wild", "empty");
  EXPECT_EQ(our_stack_int.top(), "empty");
  our_stack_int.pop();
  EXPECT_EQ(our_stack_int.top(), "wild");
  our_stack_int.insert_many_back("block", "chain", "morning");
  EXPECT_EQ(our_stack_int.top(), "morning");
  our_stack_int.pop();
  EXPECT_EQ(our_stack_int.top(), "chain");
}

#include <gtest/gtest.h>

#include <list>
#include <string>
#include <vector>

#include "s21_list.h"

TEST(TestListConstruct, TestListConstruct1) {
  s21::list<int> a;
  std::list<int> b;
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListConstruct, TestListConstruct2) {
  s21::list<double> a;
  std::list<double> b;
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListConstruct, TestListConstruct3) {
  s21::list<char> a;
  std::list<char> b;
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestListConstruct, TestListConstructSize1) {
  s21::list<int> a(5);
  std::list<int> b(5);
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListConstruct, TestListConstructSize2) {
  s21::list<double> a(5);
  std::list<double> b(5);
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListConstruct, TestListConstructSize3) {
  s21::list<char> a(5);
  std::list<char> b(5);
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestListConstruct, TestListConstructInit1) {
  s21::list<int> a{1, 2, 3, 4, 5};
  std::list<int> b{1, 2, 3, 4, 5};
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListConstruct, TestListConstructInit2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  std::list<double> b{1.23, 12.5, 13.37, 0.556};
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListConstruct, TestListConstructInit3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b{'p', 'i', 'x', 'a', 'r'};
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListConstruct, TestListConstructInit4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  std::list<std::string> b{"world", "wild", "empty"};
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestListConstruct, TestListConstructCopy1) {
  s21::list<int> a{1, 2, 3, 4, 5};
  s21::list<int> b(a);
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListConstruct, TestListConstructCopy2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  s21::list<double> b(a);
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListConstruct, TestListConstructCopy3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  s21::list<char> b(a);
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListConstruct, TestListConstructCopy4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  s21::list<std::string> b(a);
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestListConstruct, TestListConstructMove1) {
  s21::list<int> a{1, 2, 3, 4, 5};
  s21::list<int> b(std::move(a));
  std::list<int> c{1, 2, 3, 4, 5};
  std::list<int> d(std::move(c));
  int num = 1;
  for (auto i1 : b) {
    ASSERT_EQ(i1, num);
    ++num;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestListConstruct, TestListConstructMove2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  s21::list<double> b(std::move(a));
  std::list<double> c{1.23, 12.5, 13.37, 0.556};
  std::list<double> d(std::move(c));
  auto iter = d.begin();
  for (auto i1 : b) {
    ASSERT_EQ(i1, *iter);
    ++iter;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestListConstruct, TestListConstructMove3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  s21::list<char> b(std::move(a));
  std::list<char> c{'p', 'i', 'x', 'a', 'r'};
  std::list<char> d(std::move(c));
  auto iter = d.begin();
  for (auto i1 : b) {
    ASSERT_EQ(i1, *iter);
    ++iter;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestListConstruct, TestListConstructMove4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  s21::list<std::string> b(std::move(a));
  std::list<std::string> c{"world", "wild", "empty"};
  std::list<std::string> d(std::move(c));
  auto iter = d.begin();
  for (auto i1 : b) {
    ASSERT_EQ(i1, *iter);
    ++iter;
  }
  ASSERT_EQ(b.size(), d.size());
}

TEST(TestListOperatorCopy, TestListOperator1) {
  s21::list<int> a{1, 2, 3, 4, 5};
  s21::list<int> b;
  b = a;
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListOperatorCopy, TestListOperator2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  s21::list<double> b;
  b = a;
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListOperatorCopy, TestListOperator3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  s21::list<char> b;
  b = a;
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListOperatorCopy, TestListOperator4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  s21::list<std::string> b;
  b = a;
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestListOperatorMove, TestListOperator1) {
  s21::list<int> a{1, 2, 3, 4, 5};
  s21::list<int> b;
  std::list<int> c{1, 2, 3, 4, 5};
  std::list<int> d;
  d = std::move(c);
  b = std::move(a);
  int num = 1;
  for (auto i1 : b) {
    ASSERT_EQ(i1, num);
    ++num;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestListOperatorMove, TestListOperator2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  s21::list<double> b;
  std::list<double> c{1.23, 12.5, 13.37, 0.556};
  std::list<double> d;
  d = std::move(c);
  b = std::move(a);
  auto iter = d.begin();
  for (auto i1 : b) {
    ASSERT_EQ(i1, *iter);
    ++iter;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestListOperatorMove, TestListOperator3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  s21::list<char> b;
  std::list<char> c{'p', 'i', 'x', 'a', 'r'};
  std::list<char> d;
  d = std::move(c);
  b = std::move(a);
  auto iter = d.begin();
  for (auto i1 : b) {
    ASSERT_EQ(i1, *iter);
    ++iter;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestListOperatorMove, TestListOperator4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  s21::list<std::string> b;
  std::list<std::string> c{"world", "wild", "empty"};
  std::list<std::string> d;
  d = std::move(c);
  b = std::move(a);
  auto iter = d.begin();
  for (auto i1 : b) {
    ASSERT_EQ(i1, *iter);
    ++iter;
  }
  ASSERT_EQ(b.size(), d.size());
}

TEST(TestListMethodFront, TestListMethodFront1) {
  s21::list<int> a{1, 2, 3, 4, 5};
  std::list<int> b{1, 2, 3, 4, 5};
  ASSERT_EQ(a.front(), b.front());
}
TEST(TestListMethodFront, TestListMethodFront2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  std::list<double> b{1.23, 12.5, 13.37, 0.556};
  ASSERT_EQ(a.front(), b.front());
}
TEST(TestListMethodFront, TestListMethodFront3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b{'p', 'i', 'x', 'a', 'r'};
  ASSERT_EQ(a.front(), b.front());
}
TEST(TestListMethodFront, TestListMethodFront4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  std::list<std::string> b{"world", "wild", "empty"};
  ASSERT_EQ(a.front(), b.front());
}

TEST(TestListMethodBack, TestListMethodBack1) {
  s21::list<int> a{1, 2, 3, 4, 5};
  std::list<int> b{1, 2, 3, 4, 5};
  ASSERT_EQ(a.back(), b.back());
}
TEST(TestListMethodBack, TestListMethodBack2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  std::list<double> b{1.23, 12.5, 13.37, 0.556};
  ASSERT_EQ(a.back(), b.back());
}
TEST(TestListMethodBack, TestListMethodBack3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b{'p', 'i', 'x', 'a', 'r'};
  ASSERT_EQ(a.back(), b.back());
}
TEST(TestListMethodBack, TestListMethodBack4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  std::list<std::string> b{"world", "wild", "empty"};
  ASSERT_EQ(a.back(), b.back());
}

TEST(TestListMethodEmpty, TestListMethodEmptyTrue1) {
  s21::list<int> a;
  std::list<int> b;
  ASSERT_EQ(a.empty(), b.empty());
}
TEST(TestListMethodEmpty, TestListMethodEmptyTrue2) {
  s21::list<double> a;
  std::list<double> b;
  ASSERT_EQ(a.empty(), b.empty());
}
TEST(TestListMethodEmpty, TestListMethodEmptyTrue3) {
  s21::list<char> a;
  std::list<char> b;
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(TestListMethodEmpty, TestListMethodEmptyFalse1) {
  s21::list<int> a{1, 2, 3};
  std::list<int> b{1, 2, 3};
  ASSERT_EQ(a.empty(), b.empty());
}
TEST(TestListMethodEmpty, TestListMethodEmptyFalse2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  std::list<double> b{1.23, 12.5, 13.37, 0.556};
  ASSERT_EQ(a.empty(), b.empty());
}
TEST(TestListMethodEmpty, TestListMethodEmptyFalse3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b{'p', 'i', 'x', 'a', 'r'};
  ASSERT_EQ(a.empty(), b.empty());
}
TEST(TestListMethodEmpty, TestListMethodEmptyFalse4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  std::list<std::string> b{"world", "wild", "empty"};
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(TestListMethodSize, TestListMethodEmptySize1) {
  s21::list<int> a{1, 2, 3};
  std::list<int> b{1, 2, 3};
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodSize, TestListMethodEmptySize2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  std::list<double> b{1.23, 12.5, 13.37, 0.556};
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodSize, TestListMethodEmptySize3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b{'p', 'i', 'x', 'a', 'r'};
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodSize, TestListMethodEmptySize4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  std::list<std::string> b{"world", "wild", "empty"};
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestListMethodMaxSize, TestListMethodMaxSize1) {
  s21::list<int> a{1, 2, 3};
  std::list<int> b{1, 2, 3};
  ASSERT_EQ(a.max_size(), b.max_size());
}
TEST(TestListMethodMaxSize, TestListMethodMaxSize2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  std::list<double> b{1.23, 12.5, 13.37, 0.556};
  ASSERT_EQ(a.max_size(), b.max_size());
}
TEST(TestListMethodMaxSize, TestListMethodMaxSize3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b{'p', 'i', 'x', 'a', 'r'};
  ASSERT_EQ(a.max_size(), b.max_size());
}
TEST(TestListMethodMaxSize, TestListMethodMaxSize4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  std::list<std::string> b{"world", "wild", "empty"};
  ASSERT_EQ(a.max_size(), b.max_size());
}

TEST(TestListMethodClear, TestListMethodClear1) {
  s21::list<int> a{1, 2, 3};
  std::list<int> b{1, 2, 3};
  a.clear();
  b.clear();
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodClear, TestListMethodClear2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  std::list<double> b{1.23, 12.5, 13.37, 0.556};
  a.clear();
  b.clear();
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodClear, TestListMethodClear3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b{'p', 'i', 'x', 'a', 'r'};
  a.clear();
  b.clear();
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodClear, TestListMethodClear4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  std::list<std::string> b{"world", "wild", "empty"};
  a.clear();
  b.clear();
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestListMethodInsert, TestListMethodInsert1_1) {
  s21::list<int> a{1, 2, 3};
  std::list<int> b{1, 2, 3};
  a.insert(a.begin(), 5);
  b.insert(b.begin(), 5);
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodInsert, TestListMethodInsert1_2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  std::list<double> b{1.23, 12.5, 13.37, 0.556};
  a.insert(a.begin(), 5.21);
  b.insert(b.begin(), 5.21);
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodInsert, TestListMethodInsert1_3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b{'p', 'i', 'x', 'a', 'r'};
  a.insert(a.begin(), 'y');
  b.insert(b.begin(), 'y');
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodInsert, TestListMethodInsert1_4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  std::list<std::string> b{"world", "wild", "empty"};
  a.insert(a.begin(), "high");
  b.insert(b.begin(), "high");
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestListMethodInsert, TestListMethodInsert2_1) {
  s21::list<int> a{1, 2, 3};
  std::list<int> b{1, 2, 3};
  a.insert(--a.end(), 5);
  b.insert(b.end()--, 5);
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodInsert, TestListMethodInsert2_2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  std::list<double> b{1.23, 12.5, 13.37, 0.556};
  a.insert(a.end()--, 5.21);
  b.insert(b.end()--, 5.21);
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodInsert, TestListMethodInsert2_3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b{'p', 'i', 'x', 'a', 'r'};
  a.insert(a.end()--, 'y');
  b.insert(b.end()--, 'y');
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodInsert, TestListMethodInsert2_4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  std::list<std::string> b{"world", "wild", "empty"};
  a.insert(a.end()--, "high");
  b.insert(b.end()--, "high");
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestListMethodInsert, TestListMethodInsert3_1) {
  s21::list<int> a{1, 2, 3};
  std::list<int> b{1, 2, 3};
  a.insert(++a.begin(), 5);
  b.insert(++b.begin(), 5);
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodInsert, TestListMethodInsert3_2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  std::list<double> b{1.23, 12.5, 13.37, 0.556};
  a.insert(++a.begin(), 5.21);
  b.insert(++b.begin(), 5.21);
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodInsert, TestListMethodInsert3_3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b{'p', 'i', 'x', 'a', 'r'};
  a.insert(++a.begin(), 'y');
  b.insert(++b.begin(), 'y');
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodInsert, TestListMethodInsert3_4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  std::list<std::string> b{"world", "wild", "empty"};
  a.insert(++a.begin(), "high");
  b.insert(++b.begin(), "high");
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestListMethodErase, TestListMethodErase1_1) {
  s21::list<int> a{1, 2, 3};
  std::list<int> b{1, 2, 3};
  a.erase(a.begin());
  b.erase(b.begin());
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodErase, TestListMethodErase2_1) {
  s21::list<int> a{1, 2, 3};
  std::list<int> b{1, 2, 3};
  a.erase(--a.end());
  b.erase(--b.end());
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodErase, TestListMethodErase3_1) {
  s21::list<int> a{1, 2, 3};
  std::list<int> b{1, 2, 3};
  a.erase(++a.begin());
  b.erase(++b.begin());
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodErase, TestListMethodErase1_2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  std::list<double> b{1.23, 12.5, 13.37, 0.556};
  a.erase(a.begin());
  b.erase(b.begin());
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodErase, TestListMethodErase2_2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  std::list<double> b{1.23, 12.5, 13.37, 0.556};
  a.erase(--a.end());
  b.erase(--b.end());
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodErase, TestListMethodErase3_2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  std::list<double> b{1.23, 12.5, 13.37, 0.556};
  a.erase(++a.begin());
  b.erase(++b.begin());
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodErase, TestListMethodErase1_3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b{'p', 'i', 'x', 'a', 'r'};
  a.erase(a.begin());
  b.erase(b.begin());
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodErase, TestListMethodErase2_3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b{'p', 'i', 'x', 'a', 'r'};
  a.erase(--a.end());
  b.erase(--b.end());
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodErase, TestListMethodErase3_3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b{'p', 'i', 'x', 'a', 'r'};
  a.erase(++a.begin());
  b.erase(++b.begin());
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodErase, TestListMethodErase1_4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  std::list<std::string> b{"world", "wild", "empty"};
  a.erase(a.begin());
  b.erase(b.begin());
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodErase, TestListMethodErase2_4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  std::list<std::string> b{"world", "wild", "empty"};
  a.erase(--a.end());
  b.erase(--b.end());
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodErase, TestListMethodErase3_4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  std::list<std::string> b{"world", "wild", "empty"};
  a.erase(++a.begin());
  b.erase(++b.begin());
  auto i2 = b.begin();
  for (auto i1 : a) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestListMethodPushFront, TestListMethodPushFront1) {
  s21::list<int> a{1, 2, 3};
  std::list<int> b{1, 2, 3};
  a.push_front(4);
  b.push_front(4);
  ASSERT_EQ(*a.begin(), *b.begin());
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodPushFront, TestListMethodPushFront2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  std::list<double> b{1.23, 12.5, 13.37, 0.556};
  a.push_front(5.21);
  b.push_front(5.21);
  ASSERT_EQ(*a.begin(), *b.begin());
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodPushFront, TestListMethodPushFront3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b{'p', 'i', 'x', 'a', 'r'};
  a.push_front('y');
  b.push_front('y');
  ASSERT_EQ(*a.begin(), *b.begin());
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodPushFront, TestListMethodPushFront4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  std::list<std::string> b{"world", "wild", "empty"};
  a.push_front("high");
  b.push_front("high");
  ASSERT_EQ(*a.begin(), *b.begin());
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestListMethodPushBack, TestListMethodPushBack1) {
  s21::list<int> a{1, 2, 3};
  std::list<int> b{1, 2, 3};
  a.push_back(4);
  b.push_back(4);
  ASSERT_EQ(*(--a.end()), *(--b.end()));
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodPushBack, TestListMethodPushBack2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  std::list<double> b{1.23, 12.5, 13.37, 0.556};
  a.push_back(5.21);
  b.push_back(5.21);
  ASSERT_EQ(*(--a.end()), *(--b.end()));
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodPushBack, TestListMethodPushBack3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b{'p', 'i', 'x', 'a', 'r'};
  a.push_back('y');
  b.push_back('y');
  ASSERT_EQ(*(--a.end()), *(--b.end()));
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodPushBack, TestListMethodPushBack4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  std::list<std::string> b{"world", "wild", "empty"};
  a.push_back("high");
  b.push_back("high");
  ASSERT_EQ(*(--a.end()), *(--b.end()));
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestListMethodPopFront, TestListMethodPopFront1) {
  s21::list<int> a{1, 2, 3};
  std::list<int> b{1, 2, 3};
  a.pop_front();
  b.pop_front();
  ASSERT_EQ(*a.begin(), *b.begin());
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodPopFront, TestListMethodPopFront2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  std::list<double> b{1.23, 12.5, 13.37, 0.556};
  a.pop_front();
  b.pop_front();
  ASSERT_EQ(*a.begin(), *b.begin());
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodPopFront, TestListMethodPopFront3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b{'p', 'i', 'x', 'a', 'r'};
  a.pop_front();
  b.pop_front();
  ASSERT_EQ(*a.begin(), *b.begin());
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodPopFront, TestListMethodPopFront4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  std::list<std::string> b{"world", "wild", "empty"};
  a.pop_front();
  b.pop_front();
  ASSERT_EQ(*a.begin(), *b.begin());
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestListMethodPopBack, TestListMethodPopBack1) {
  s21::list<int> a{1, 2, 3};
  std::list<int> b{1, 2, 3};
  a.pop_back();
  b.pop_back();
  ASSERT_EQ(*(--a.end()), *(--b.end()));
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodPopBack, TestListMethodPopBack2) {
  s21::list<double> a{1.23, 12.5, 13.37, 0.556};
  std::list<double> b{1.23, 12.5, 13.37, 0.556};
  a.pop_back();
  b.pop_back();
  ASSERT_EQ(*(--a.end()), *(--b.end()));
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodPopBack, TestListMethodPopBack3) {
  s21::list<char> a{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b{'p', 'i', 'x', 'a', 'r'};
  a.pop_back();
  b.pop_back();
  ASSERT_EQ(*(--a.end()), *(--b.end()));
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestListMethodPopBack, TestListMethodPopBack4) {
  s21::list<std::string> a{"world", "wild", "empty"};
  std::list<std::string> b{"world", "wild", "empty"};
  a.pop_back();
  b.pop_back();
  ASSERT_EQ(*(--a.end()), *(--b.end()));
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestListMethodSwap, TestListMethodSwap1) {
  s21::list<int> a_s21{1, 2, 3};
  s21::list<int> b_s21{4, 5, 6};
  std::list<int> a_std{1, 2, 3};
  std::list<int> b_std{4, 5, 6};
  a_s21.swap(b_s21);
  a_std.swap(b_std);
  auto i2 = b_std.begin();
  for (auto i1 : b_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  auto i4 = a_std.begin();
  for (auto i3 : a_s21) {
    ASSERT_EQ(i3, *i4);
    ++i4;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}
TEST(TestListMethodSwap, TestListMethodSwap2) {
  s21::list<double> a_s21{1.23, 12.5, 13.37, 0.556};
  s21::list<double> b_s21{4.2, 5.32, 61.2, 66.5, 324.1};
  std::list<double> a_std{1.23, 12.5, 13.37, 0.556};
  std::list<double> b_std{4.2, 5.32, 61.2, 66.5, 324.1};
  a_s21.swap(b_s21);
  a_std.swap(b_std);
  auto i2 = b_std.begin();
  for (auto i1 : b_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  auto i4 = a_std.begin();
  for (auto i3 : a_s21) {
    ASSERT_EQ(i3, *i4);
    ++i4;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}
TEST(TestListMethodSwap, TestListMethodSwap3) {
  s21::list<char> a_s21{'p', 'i', 'x', 'a', 'r'};
  s21::list<char> b_s21{'z', 't', 'e'};
  std::list<char> a_std{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b_std{'z', 't', 'e'};
  a_s21.swap(b_s21);
  a_std.swap(b_std);
  auto i2 = b_std.begin();
  for (auto i1 : b_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  auto i4 = a_std.begin();
  for (auto i3 : a_s21) {
    ASSERT_EQ(i3, *i4);
    ++i4;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}
TEST(TestListMethodSwap, TestListMethodSwap4) {
  s21::list<std::string> a_s21{"world", "wild", "empty"};
  s21::list<std::string> b_s21{"high"};
  std::list<std::string> a_std{"world", "wild", "empty"};
  std::list<std::string> b_std{"high"};
  a_s21.swap(b_s21);
  a_std.swap(b_std);
  auto i2 = b_std.begin();
  for (auto i1 : b_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  auto i4 = a_std.begin();
  for (auto i3 : a_s21) {
    ASSERT_EQ(i3, *i4);
    ++i4;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}

TEST(TestListMethodMerge, TestListMethodMerge1) {
  s21::list<int> a_s21{1, 2, 3};
  s21::list<int> b_s21{4, 5, 6};
  std::list<int> a_std{1, 2, 3};
  std::list<int> b_std{4, 5, 6};
  a_s21.merge(b_s21);
  a_std.merge(b_std);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodMerge, TestListMethodMerge2) {
  s21::list<double> a_s21{1.23, 12.5, 13.37, 0.556};
  s21::list<double> b_s21{4.2, 5.32, 61.2, 66.5, 324.1};
  std::list<double> a_std{1.23, 12.5, 13.37, 0.556};
  std::list<double> b_std{4.2, 5.32, 61.2, 66.5, 324.1};
  // a_s21.sort();
  // a_std.sort();
  // b_s21.sort();
  // b_std.sort();
  a_s21.merge(b_s21);
  a_std.merge(b_std);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodMerge, TestListMethodMerge3) {
  s21::list<char> a_s21{'p', 'i', 'x', 'a', 'r'};
  s21::list<char> b_s21{'z', 't', 'e'};
  std::list<char> a_std{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b_std{'z', 't', 'e'};
  a_s21.merge(b_s21);
  a_std.merge(b_std);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodMerge, TestListMethodMerge4) {
  s21::list<std::string> a_s21{"world", "wild", "empty"};
  s21::list<std::string> b_s21{"high"};
  std::list<std::string> a_std{"world", "wild", "empty"};
  std::list<std::string> b_std{"high"};
  a_s21.merge(b_s21);
  a_std.merge(b_std);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}

TEST(TestListMethodSplice, TestListMethodSplice1_1) {
  s21::list<int> a_s21{1, 2, 3};
  s21::list<int> b_s21{4, 5, 6};
  std::list<int> a_std{1, 2, 3};
  std::list<int> b_std{4, 5, 6};
  a_s21.splice(a_s21.begin(), b_s21);
  a_std.splice(a_std.begin(), b_std);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodSplice, TestListMethodSplice1_2) {
  s21::list<double> a_s21{1.23, 12.5, 13.37, 0.556};
  s21::list<double> b_s21{4.2, 5.32, 61.2, 66.5, 324.1};
  std::list<double> a_std{1.23, 12.5, 13.37, 0.556};
  std::list<double> b_std{4.2, 5.32, 61.2, 66.5, 324.1};
  a_s21.splice(a_s21.begin(), b_s21);
  a_std.splice(a_std.begin(), b_std);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodSplice, TestListMethodSplice1_3) {
  s21::list<char> a_s21{'p', 'i', 'x', 'a', 'r'};
  s21::list<char> b_s21{'z', 't', 'e'};
  std::list<char> a_std{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b_std{'z', 't', 'e'};
  a_s21.splice(a_s21.begin(), b_s21);
  a_std.splice(a_std.begin(), b_std);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodSplice, TestListMethodSplice1_4) {
  s21::list<std::string> a_s21{"world", "wild", "empty"};
  s21::list<std::string> b_s21{"high"};
  std::list<std::string> a_std{"world", "wild", "empty"};
  std::list<std::string> b_std{"high"};
  a_s21.splice(a_s21.begin(), b_s21);
  a_std.splice(a_std.begin(), b_std);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}

TEST(TestListMethodSplice, TestListMethodSplice2_1) {
  s21::list<int> a_s21{1, 2, 3};
  s21::list<int> b_s21{4, 5, 6};
  std::list<int> a_std{1, 2, 3};
  std::list<int> b_std{4, 5, 6};
  a_s21.splice(++a_s21.begin(), b_s21);
  a_std.splice(++a_std.begin(), b_std);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodSplice, TestListMethodSplice2_2) {
  s21::list<double> a_s21{1.23, 12.5, 13.37, 0.556};
  s21::list<double> b_s21{4.2, 5.32, 61.2, 66.5, 324.1};
  std::list<double> a_std{1.23, 12.5, 13.37, 0.556};
  std::list<double> b_std{4.2, 5.32, 61.2, 66.5, 324.1};
  a_s21.splice(++a_s21.begin(), b_s21);
  a_std.splice(++a_std.begin(), b_std);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodSplice, TestListMethodSplice2_3) {
  s21::list<char> a_s21{'p', 'i', 'x', 'a', 'r'};
  s21::list<char> b_s21{'z', 't', 'e'};
  std::list<char> a_std{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b_std{'z', 't', 'e'};
  a_s21.splice(a_s21.begin(), b_s21);
  a_std.splice(a_std.begin(), b_std);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodSplice, TestListMethodSplice2_4) {
  s21::list<std::string> a_s21{"world", "wild", "empty"};
  s21::list<std::string> b_s21{"high"};
  std::list<std::string> a_std{"world", "wild", "empty"};
  std::list<std::string> b_std{"high"};
  a_s21.splice(++a_s21.begin(), b_s21);
  a_std.splice(++a_std.begin(), b_std);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}

TEST(TestListMethodSplice, TestListMethodSplice3_1) {
  s21::list<int> a_s21{1, 2, 3};
  s21::list<int> b_s21{4, 5, 6};
  std::list<int> a_std{1, 2, 3};
  std::list<int> b_std{4, 5, 6};
  a_s21.splice(--a_s21.end(), b_s21);
  a_std.splice(--a_std.end(), b_std);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodSplice, TestListMethodSplice3_2) {
  s21::list<double> a_s21{1.23, 12.5, 13.37, 0.556};
  s21::list<double> b_s21{4.2, 5.32, 61.2, 66.5, 324.1};
  std::list<double> a_std{1.23, 12.5, 13.37, 0.556};
  std::list<double> b_std{4.2, 5.32, 61.2, 66.5, 324.1};
  a_s21.splice(--a_s21.end(), b_s21);
  a_std.splice(--a_std.end(), b_std);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodSplice, TestListMethodSplice3_3) {
  s21::list<char> a_s21{'p', 'i', 'x', 'a', 'r'};
  s21::list<char> b_s21{'z', 't', 'e'};
  std::list<char> a_std{'p', 'i', 'x', 'a', 'r'};
  std::list<char> b_std{'z', 't', 'e'};
  a_s21.splice(--a_s21.end(), b_s21);
  a_std.splice(--a_std.end(), b_std);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodSplice, TestListMethodSplice3_4) {
  s21::list<std::string> a_s21{"world", "wild", "empty"};
  s21::list<std::string> b_s21{"high"};
  std::list<std::string> a_std{"world", "wild", "empty"};
  std::list<std::string> b_std{"high"};
  a_s21.splice(--a_s21.end(), b_s21);
  a_std.splice(--a_std.end(), b_std);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}

TEST(TestListMethodReverse, TestListMethodReverse1) {
  s21::list<int> a_s21{1, 2, 3};
  std::list<int> a_std{1, 2, 3};
  a_s21.reverse();
  a_std.reverse();
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodReverse, TestListMethodReverse2) {
  s21::list<double> a_s21{1.23, 12.5, 13.37, 0.556};
  std::list<double> a_std{1.23, 12.5, 13.37, 0.556};
  a_s21.reverse();
  a_std.reverse();
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodReverse, TestListMethodReverse3) {
  s21::list<char> a_s21{'p', 'i', 'x', 'a', 'r'};
  std::list<char> a_std{'p', 'i', 'x', 'a', 'r'};
  a_s21.reverse();
  a_std.reverse();
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodReverse, TestListMethodReverse4) {
  s21::list<std::string> a_s21{"world", "wild", "empty"};
  std::list<std::string> a_std{"world", "wild", "empty"};
  a_s21.reverse();
  a_std.reverse();
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}

TEST(TestListMethodUnique, TestListMethodUnique1) {
  s21::list<int> a_s21{1, 2, 2, 2, 3};
  std::list<int> a_std{1, 2, 2, 2, 3};
  a_s21.unique();
  a_std.unique();
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodUnique, TestListMethodUnique2) {
  s21::list<double> a_s21{1.23, 12.5, 12.5, 13.37, 13.37, 0.556};
  std::list<double> a_std{1.23, 12.5, 12.5, 13.37, 13.37, 0.556};
  a_s21.unique();
  a_std.unique();
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodUnique, TestListMethodUnique3) {
  s21::list<char> a_s21{'p', 'i', 'i', 'i', 'r'};
  std::list<char> a_std{'p', 'i', 'i', 'i', 'r'};
  a_s21.unique();
  a_std.unique();
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodUnique, TestListMethodUnique4) {
  s21::list<std::string> a_s21{"world", "wild", "wild", "wild", "empty"};
  std::list<std::string> a_std{"world", "wild", "wild", "wild", "empty"};
  a_s21.unique();
  a_std.unique();
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}

TEST(TestListMethodSort, TestListMethodSort1) {
  s21::list<int> a_s21{3, 7, 1, 5};
  std::list<int> a_std{3, 7, 1, 5};
  a_s21.sort();
  a_std.sort();
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodSort, TestListMethodSort2) {
  s21::list<double> a_s21{1.23, 12.5, 13.37, 0.556};
  std::list<double> a_std{1.23, 12.5, 13.37, 0.556};
  a_s21.sort();
  a_std.sort();
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodSort, TestListMethodSort3) {
  s21::list<char> a_s21{'p', 'i', 'x', 'a', 'r'};
  std::list<char> a_std{'p', 'i', 'x', 'a', 'r'};
  a_s21.sort();
  a_std.sort();
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodSort, TestListMethodSort4) {
  s21::list<std::string> a_s21{"world", "wild", "empty"};
  std::list<std::string> a_std{"world", "wild", "empty"};
  a_s21.sort();
  a_std.sort();
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}

TEST(TestListMethodBonusInsMany, TestListMethodBonusInsMany1) {
  s21::list<int> a_s21{1, 2, 3, 4};
  std::list<int> a_std{1, 2, 3, 4};
  auto it = a_std.begin();
  int num = 7;
  while (num > 4) {
    it = a_std.insert(it, num);
    --num;
  }
  a_s21.insert_many(a_s21.begin(), 5, 6, 7);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodBonusInsMany, TestListMethodBonusInsMany2) {
  s21::list<double> a_s21{1.23, 12.5, 13.37, 0.556};
  std::list<double> a_std{1.23, 12.5, 13.37, 0.556};
  auto it = a_std.begin();
  double num = 7.2;
  while (num > 4.2) {
    it = a_std.insert(it, num);
    num -= 1;
  }
  a_s21.insert_many(a_s21.begin(), 5.2, 6.2, 7.2);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodBonusInsMany, TestListMethodBonusInsMany3) {
  s21::list<char> a_s21{'p', 'i', 'x', 'a', 'r'};
  std::list<char> a_std{'p', 'i', 'x', 'a', 'r'};
  std::vector<char> temp{'v', 'v', 's'};
  auto it = a_std.begin();
  for (auto iter : temp) {
    char abc = iter;
    it = a_std.insert(it, abc);
  }
  a_s21.insert_many(a_s21.begin(), 's', 'v', 'v');
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodBonusInsMany, TestListMethodBonusInsMany4) {
  s21::list<std::string> a_s21{"world", "wild", "empty"};
  std::list<std::string> a_std{"world", "wild", "empty"};
  std::vector<std::string> temp{"ssd", "high"};
  auto it = a_std.begin();
  for (auto iter : temp) {
    std::string abc = iter;
    it = a_std.insert(it, abc);
  }
  a_s21.insert_many(a_s21.begin(), "high", "ssd");
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}

TEST(TestListMethodBonusInsBackMany, TestListMethodBonusInsBackMany1) {
  s21::list<int> a_s21{1, 2, 3, 4};
  std::list<int> a_std{1, 2, 3, 4};
  int num = 5;
  while (num < 8) {
    a_std.insert(a_std.end(), num);
    ++num;
  }
  a_s21.insert_many_back(5, 6, 7);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodBonusInsBackMany, TestListMethodBonusInsBackMany2) {
  s21::list<double> a_s21{1.23, 12.5, 13.37, 0.556};
  std::list<double> a_std{1.23, 12.5, 13.37, 0.556};
  double num = 5.1;
  while (num < 8.1) {
    a_std.insert(a_std.end(), num);
    num += 1;
  }
  a_s21.insert_many_back(5.1, 6.1, 7.1);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodBonusInsBackMany, TestListMethodBonusInsBackMany3) {
  s21::list<char> a_s21{'p', 'i', 'x', 'a', 'r'};
  std::list<char> a_std{'p', 'i', 'x', 'a', 'r'};
  std::vector<char> temp{'v', 'v', 's'};
  for (auto iter : temp) {
    char abc = iter;
    a_std.insert(a_std.end(), abc);
  }
  a_s21.insert_many_back('v', 'v', 's');
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodBonusInsBackMany, TestListMethodBonusInsBackMany4) {
  s21::list<std::string> a_s21{"world", "wild", "empty"};
  std::list<std::string> a_std{"world", "wild", "empty"};
  std::vector<std::string> temp{"ssd", "high"};
  for (auto iter : temp) {
    std::string abc = iter;
    a_std.insert(a_std.end(), abc);
  }
  a_s21.insert_many_back("ssd", "high");
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}

TEST(TestListMethodBonusInsFrontMany, TestListMethodBonusInsFrontMany1) {
  s21::list<int> a_s21{1, 2, 3, 4};
  std::list<int> a_std{1, 2, 3, 4};
  int num = 5;
  while (num < 8) {
    a_std.insert(a_std.begin(), num);
    ++num;
  }
  a_s21.insert_many_front(5, 6, 7);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodBonusInsFrontMany, TestListMethodBonusInsFrontMany2) {
  s21::list<double> a_s21{1.23, 12.5, 13.37, 0.556};
  std::list<double> a_std{1.23, 12.5, 13.37, 0.556};
  double num = 5.1;
  while (num < 8.1) {
    a_std.insert(a_std.begin(), num);
    ++num;
  }
  a_s21.insert_many_front(5.1, 6.1, 7.1);
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodBonusInsFrontMany, TestListMethodBonusInsFrontMany3) {
  s21::list<char> a_s21{'p', 'i', 'x', 'a', 'r'};
  std::list<char> a_std{'p', 'i', 'x', 'a', 'r'};
  std::vector<char> temp{'v', 'v', 's'};
  for (auto iter : temp) {
    char abc = iter;
    a_std.insert(a_std.begin(), abc);
  }
  a_s21.insert_many_front('v', 'v', 's');
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}
TEST(TestListMethodBonusInsFrontMany, TestListMethodBonusInsFrontMany4) {
  s21::list<std::string> a_s21{"world", "wild", "empty"};
  std::list<std::string> a_std{"world", "wild", "empty"};
  std::vector<std::string> temp{"ssd", "high"};
  for (auto iter : temp) {
    std::string abc = iter;
    a_std.insert(a_std.begin(), abc);
  }
  a_s21.insert_many_front("ssd", "high");
  auto i2 = a_std.begin();
  for (auto i1 : a_s21) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
  ASSERT_EQ(a_s21.size(), a_std.size());
}

TEST(TestListOperator, TestListOperator1) {
  s21::list<int> a_s21{1, 2, 3, 4};
  std::list<int> a_std{1, 2, 3, 4};
  auto i2 = a_s21.begin();
  for (auto i1 : a_std) {
    ASSERT_EQ(i1, *i2);
    ++i2;
  }
}
TEST(TestListOperator, TestListOperator2) {
  s21::list<int> a_s21{1, 2, 3, 4};
  std::list<int> a_std{1, 2, 3, 4};
  auto i1_s21 = a_s21.begin();
  auto i2_std = a_std.begin();
  ASSERT_EQ(i1_s21 == i1_s21++, i2_std == i2_std++);
}
TEST(TestListOperator, TestListOperator3) {
  s21::list<int> a_s21{1, 2, 3, 4};
  std::list<int> a_std{1, 2, 3, 4};
  auto i1_s21 = a_s21.begin();
  auto i2_std = a_std.begin();
  ASSERT_EQ(i1_s21 != i1_s21++, i2_std != i2_std++);
}
TEST(TestListOperator, TestListOperator4) {
  s21::list<int> a_s21{1, 2, 3, 4};
  std::list<int> a_std{1, 2, 3, 4};
  auto i2 = a_s21.end();
  auto i1 = a_std.end();
  for (size_t a = 0; a < a_std.size(); ++a) {
    --i2;
    --i1;
    ASSERT_EQ(*i1, *i2);
  }
}
TEST(TestListOperator, TestListOperator5) {
  s21::list<int> a_s21{1, 2, 3, 4};
  std::list<int> a_std{1, 2, 3, 4};
  auto i2 = a_s21.begin();
  auto i1 = a_std.begin();
  ASSERT_EQ(*(i1++), *(i2++));
}
TEST(TestListOperator, TestListOperator6) {
  s21::list<int> a_s21{1, 2, 3, 4};
  std::list<int> a_std{1, 2, 3, 4};
  auto i2 = a_s21.end();
  auto i1 = a_std.end();
  --i1;
  --i2;
  ASSERT_EQ(*(i1--), *(i2--));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
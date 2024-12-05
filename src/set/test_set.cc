#include <gtest/gtest.h>

#include <set>
#include <string>

#include "s21_set.h"

TEST(TestSetConstruct, TestSetConstruct1) {
  s21::set<int> a;
  std::set<int> b;
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestSetConstruct, TestSetConstruct2) {
  s21::set<char> a;
  std::set<char> b;
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestSetConstruct, TestSetConstruct3) {
  s21::set<std::string> a;
  std::set<std::string> b;
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestSetConstruct, TestSetConstruct4) {
  s21::set<double> a;
  std::set<double> b;
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestSetConstructInit, TestSetConstruct1) {
  s21::set<int> a{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  std::set<int> b{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestSetConstructInit, TestSetConstruct2) {
  s21::set<char> a{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  std::set<char> b{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  auto iter1 = a.begin();
  for (auto i : b) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestSetConstructInit, TestSetConstruct3) {
  s21::set<std::string> a{"stop", "start", "abcd", "kyky"};
  std::set<std::string> b{"stop", "start", "abcd", "kyky"};
  auto iter1 = a.begin();
  for (auto i : b) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestSetConstructInit, TestSetConstruct4) {
  s21::set<double> a{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  std::set<double> b{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  auto iter1 = a.begin();
  for (auto i : b) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestSetConstructCopy, TestSetConstruct1) {
  s21::set<int> a{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  s21::set<int> b(a);
  std::set<int> c{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  std::set<int> d(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestSetConstructCopy, TestSetConstruct2) {
  s21::set<char> a{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  s21::set<char> b(a);
  std::set<char> c{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  std::set<char> d(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestSetConstructCopy, TestSetConstruct3) {
  s21::set<std::string> a{"stop", "start", "abcd", "kyky"};
  s21::set<std::string> b(a);
  std::set<std::string> c{"stop", "start", "abcd", "kyky"};
  std::set<std::string> d(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestSetConstructCopy, TestSetConstruct4) {
  s21::set<double> a{1.2, 3.4, 7.7, 1.01};
  s21::set<double> b(a);
  std::set<double> c{1.2, 3.4, 7.7, 1.01};
  std::set<double> d(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}

TEST(TestSetConstructMove, TestSetConstruct1) {
  s21::set<int> a{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  s21::set<int> b(std::move(a));
  std::set<int> c{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  std::set<int> d(std::move(c));
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestSetConstructMove, TestSetConstruct2) {
  s21::set<char> a{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  s21::set<char> b(std::move(a));
  std::set<char> c{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  std::set<char> d(std::move(c));
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestSetConstructMove, TestSetConstruct3) {
  s21::set<std::string> a{"stop", "start", "abcd", "kyky"};
  s21::set<std::string> b(std::move(a));
  ;
  std::set<std::string> c{"stop", "start", "abcd", "kyky"};
  std::set<std::string> d(std::move(c));
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestSetConstructMove, TestSetConstruct4) {
  s21::set<double> a{1.2, 3.4, 7.7, 1.01};
  s21::set<double> b(std::move(a));
  std::set<double> c{1.2, 3.4, 7.7, 1.01};
  std::set<double> d(std::move(c));
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestSetOperatorMove, TestSetConstruct1) {
  s21::set<int> a{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  s21::set<int> b;
  b = std::move(a);
  std::set<int> c{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  std::set<int> d;
  d = std::move(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestSetOperatorMove, TestSetConstruct2) {
  s21::set<char> a{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  s21::set<char> b;
  b = std::move(a);
  std::set<char> c{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  std::set<char> d;
  d = std::move(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestSetOperatorMove, TestSetConstruct3) {
  s21::set<std::string> a{"stop", "start", "abcd", "kyky"};
  s21::set<std::string> b;
  b = std::move(a);
  std::set<std::string> c{"stop", "start", "abcd", "kyky"};
  std::set<std::string> d;
  d = std::move(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestSetOperatorMove, TestSetConstruct4) {
  s21::set<double> a{1.2, 3.4, 7.7, 1.01};
  s21::set<double> b;
  b = std::move(a);
  std::set<double> c{1.2, 3.4, 7.7, 1.01};
  std::set<double> d;
  d = std::move(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}

TEST(TestSetMethodEnd, TestSetConstruct1) {
  s21::set<int> a{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  std::set<int> c{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  auto iter1 = a.end();
  --iter1;
  auto iter2 = c.end();
  --iter2;
  ASSERT_EQ((*iter1).first, *iter2);
}
TEST(TestSetMethodEnd, TestSetConstruct2) {
  s21::set<char> a{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  std::set<char> c{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  auto iter1 = a.end();
  --iter1;
  auto iter2 = c.end();
  --iter2;
  ASSERT_EQ((*iter1).first, *iter2);
}
TEST(TestSetMethodEnd, TestSetConstruct3) {
  s21::set<std::string> a{"stop", "start", "abcd", "kyky"};
  std::set<std::string> c{"stop", "start", "abcd", "kyky"};
  auto iter1 = a.end();
  --iter1;
  auto iter2 = c.end();
  --iter2;
  ASSERT_EQ((*iter1).first, *iter2);
}
TEST(TestSetMethodEnd, TestSetConstruct4) {
  s21::set<double> a{1.2, 3.4, 7.7, 1.01};
  std::set<double> c{1.2, 3.4, 7.7, 1.01};
  auto iter1 = a.end();
  --iter1;
  auto iter2 = c.end();
  --iter2;
  ASSERT_EQ((*iter1).first, *iter2);
}

TEST(TestSetMethodBegin, TestSetConstruct1) {
  s21::set<int> a{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  std::set<int> c{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  auto iter1 = a.begin();
  auto iter2 = c.begin();
  ASSERT_EQ((*iter1).first, *iter2);
}
TEST(TestSetMethodBegin, TestSetConstruct2) {
  s21::set<char> a{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  std::set<char> c{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  auto iter1 = a.begin();
  auto iter2 = c.begin();
  ASSERT_EQ((*iter1).first, *iter2);
}
TEST(TestSetMethodBegin, TestSetConstruct3) {
  s21::set<std::string> a{"stop", "start", "abcd", "kyky"};
  std::set<std::string> c{"stop", "start", "abcd", "kyky"};
  auto iter1 = a.begin();
  auto iter2 = c.begin();
  ASSERT_EQ((*iter1).first, *iter2);
}
TEST(TestSetMethodBegin, TestSetConstruct4) {
  s21::set<double> a{1.2, 3.4, 7.7, 1.01};
  std::set<double> c{1.2, 3.4, 7.7, 1.01};
  auto iter1 = a.begin();
  auto iter2 = c.begin();
  ASSERT_EQ((*iter1).first, *iter2);
}
TEST(TestSetMethodEmpty, TestSetConstruct1) {
  s21::set<int> a{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  std::set<int> c{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  ASSERT_EQ(a.empty(), c.empty());
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodEmpty, TestSetConstruct2) {
  s21::set<char> a{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  std::set<char> c{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  ASSERT_EQ(a.empty(), c.empty());
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodEmpty, TestSetConstruct3) {
  s21::set<std::string> a{"stop", "start", "abcd", "kyky"};
  std::set<std::string> c{"stop", "start", "abcd", "kyky"};
  ASSERT_EQ(a.empty(), c.empty());
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodEmpty, TestSetConstruct4) {
  s21::set<double> a{1.2, 3.4, 7.7, 1.01};
  std::set<double> c{1.2, 3.4, 7.7, 1.01};
  ASSERT_EQ(a.empty(), c.empty());
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodEmpty, TestSetConstruct5) {
  s21::set<double> a;
  std::set<double> c;
  ASSERT_EQ(a.empty(), c.empty());
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodEmpty, TestSetConstruct6) {
  s21::set<int> a;
  std::set<int> c;
  ASSERT_EQ(a.empty(), c.empty());
  ASSERT_EQ(a.size(), c.size());
}

TEST(TestSetMethodClear, TestSetConstruct1) {
  s21::set<int> a{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  std::set<int> c{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  a.clear();
  c.clear();
  ASSERT_EQ(a.empty(), c.empty());
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodClear, TestSetConstruct2) {
  s21::set<char> a{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  std::set<char> c{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  a.clear();
  c.clear();
  ASSERT_EQ(a.empty(), c.empty());
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodClear, TestSetConstruct3) {
  s21::set<std::string> a{"stop", "start", "abcd", "kyky"};
  std::set<std::string> c{"stop", "start", "abcd", "kyky"};
  a.clear();
  c.clear();
  ASSERT_EQ(a.empty(), c.empty());
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodClear, TestSetConstruct4) {
  s21::set<double> a{1.2, 3.4, 7.7, 1.01};
  std::set<double> c{1.2, 3.4, 7.7, 1.01};
  a.clear();
  c.clear();
  ASSERT_EQ(a.empty(), c.empty());
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodInsert, TestSetConstruct1) {
  s21::set<int> a{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  std::set<int> c{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  a.insert(8);
  c.insert(8);
  a.insert(12);
  c.insert(12);
  a.insert(999);
  c.insert(999);
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }

  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodInsert, TestSetConstruct2) {
  s21::set<char> a{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  std::set<char> c{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  a.insert('c');
  c.insert('c');
  a.insert('k');
  c.insert('k');
  a.insert('j');
  c.insert('j');
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodInsert, TestSetConstruct3) {
  s21::set<std::string> a{"stop", "start", "abcd", "kyky"};
  std::set<std::string> c{"stop", "start", "abcd", "kyky"};
  a.insert("vvs");
  c.insert("vvs");
  a.insert("qscvfr");
  c.insert("qscvfr");
  a.insert("vhsvhfke");
  c.insert("vhsvhfke");
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodInsert, TestSetConstruct4) {
  s21::set<double> a{1.2, 3.4, 7.7, 1.01};
  std::set<double> c{1.2, 3.4, 7.7, 1.01};
  a.insert(8.99);
  c.insert(8.99);
  a.insert(12.1234);
  c.insert(12.1234);
  a.insert(999.77);
  c.insert(999.77);
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }

  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodSwap, TestSetConstruct1) {
  s21::set<int> a{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  s21::set<int> b{27, 93, 45, 76, 8888, 13};
  std::set<int> c{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  std::set<int> d{27, 93, 45, 76, 8888, 13};
  a.swap(b);
  c.swap(d);
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  auto iter2 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter2).first, i);
    ++iter2;
  }
  ASSERT_EQ(b.size(), d.size());
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodSwap, TestSetConstruct2) {
  s21::set<char> a{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  s21::set<char> b{'f', 'q', 'j'};
  std::set<char> c{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  std::set<char> d{'f', 'q', 'j'};
  a.swap(b);
  c.swap(d);
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  auto iter2 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter2).first, i);
    ++iter2;
  }
  ASSERT_EQ(b.size(), d.size());
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodSwap, TestSetConstruct3) {
  s21::set<std::string> a{"stop", "start", "abcd", "kyky"};
  s21::set<std::string> b{"qaz", "vaz2107", "adsdfg"};
  std::set<std::string> c{"stop", "start", "abcd", "kyky"};
  std::set<std::string> d{"qaz", "vaz2107", "adsdfg"};
  ;
  a.swap(b);
  c.swap(d);
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  auto iter2 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter2).first, i);
    ++iter2;
  }
  ASSERT_EQ(b.size(), d.size());
  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(a.empty(), c.empty());
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodSwap, TestSetConstruct4) {
  s21::set<double> a{1.2, 3.4, 7.7, 1.01};
  s21::set<double> b{12.1, 228.337, 777.888, 1.23, 2.233};
  std::set<double> c{1.2, 3.4, 7.7, 1.01};
  std::set<double> d{12.1, 228.337, 777.888, 1.23, 2.233};
  a.swap(b);
  c.swap(d);
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  auto iter2 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter2).first, i);
    ++iter2;
  }
  ASSERT_EQ(b.size(), d.size());
  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(a.empty(), c.empty());
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodMerge, TestSetConstruct1) {
  s21::set<int> a{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  s21::set<int> b{27, 93, 45, 76, 8888, 13};
  std::set<int> c{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  std::set<int> d{27, 93, 45, 76, 8888, 13};
  a.merge(b);
  c.merge(d);
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodMerge, TestSetConstruct2) {
  s21::set<char> a{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  s21::set<char> b{'f', 'q', 'j'};
  std::set<char> c{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  std::set<char> d{'f', 'q', 'j'};
  a.merge(b);
  c.merge(d);
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodMerge, TestSetConstruct3) {
  s21::set<std::string> a{"stop", "start", "abcd", "kyky"};
  s21::set<std::string> b{"qaz", "vaz2107", "adsdfg"};
  std::set<std::string> c{"stop", "start", "abcd", "kyky"};
  std::set<std::string> d{"qaz", "vaz2107", "adsdfg"};
  ;
  a.merge(b);
  c.merge(d);
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodMerge, TestSetConstruct4) {
  s21::set<double> a{1.2, 3.4, 7.7, 1.01};
  s21::set<double> b{12.1, 228.337, 777.888, 1.23, 2.233};
  std::set<double> c{1.2, 3.4, 7.7, 1.01};
  std::set<double> d{12.1, 228.337, 777.888, 1.23, 2.233};
  a.merge(b);
  c.merge(d);
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).first, i);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestSetMethodContains, TestSetConstruct1) {
  s21::set<int> a{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  s21::set<int> b{27, 93, 45, 76, 8888, 13};
  ASSERT_EQ(a.contains(87), true);
  ASSERT_EQ(a.contains(35), true);
  ASSERT_EQ(a.contains(22), true);
  ASSERT_EQ(a.contains(78), true);
  ASSERT_EQ(a.contains(89), true);
  ASSERT_EQ(a.contains(1), true);
  ASSERT_EQ(a.contains(1000000), false);
  ASSERT_EQ(a.contains(777777), false);

  ASSERT_EQ(b.contains(27), true);
  ASSERT_EQ(b.contains(93), true);
  ASSERT_EQ(b.contains(45), true);
  ASSERT_EQ(b.contains(76), true);
  ASSERT_EQ(b.contains(8888), true);
  ASSERT_EQ(b.contains(13), true);
  ASSERT_EQ(b.contains(1000000), false);
  ASSERT_EQ(b.contains(777777), false);
}
TEST(TestSetMethodContains, TestSetConstruct2) {
  s21::set<char> a{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  s21::set<char> b{'f', 'q', 'j'};
  ASSERT_EQ(a.contains('a'), true);
  ASSERT_EQ(a.contains('b'), true);
  ASSERT_EQ(a.contains('d'), true);
  ASSERT_EQ(a.contains('e'), true);
  ASSERT_EQ(a.contains('v'), true);
  ASSERT_EQ(a.contains('w'), true);
  ASSERT_EQ(a.contains('q'), false);

  ASSERT_EQ(b.contains('f'), true);
  ASSERT_EQ(b.contains('q'), true);
  ASSERT_EQ(b.contains('j'), true);
  ASSERT_EQ(b.contains('a'), false);
}
TEST(TestSetMethodContains, TestSetConstruct3) {
  s21::set<std::string> a{"stop", "start", "abcd", "kyky"};
  s21::set<std::string> b{"qaz", "vaz2107", "adsdfg"};
  ASSERT_EQ(a.contains("stop"), true);
  ASSERT_EQ(a.contains("start"), true);
  ASSERT_EQ(a.contains("abcd"), true);
  ASSERT_EQ(a.contains("kyky"), true);
  ASSERT_EQ(a.contains("fafafa"), false);

  ASSERT_EQ(b.contains("qaz"), true);
  ASSERT_EQ(b.contains("vaz2107"), true);
  ASSERT_EQ(b.contains("abcd"), false);
}
TEST(TestSetMethodContains, TestSetConstruct4) {
  s21::set<double> a{1.2, 3.4, 7.7, 1.01};
  s21::set<double> b{12.1, 228.337, 777.888, 1.23, 2.233};
  ASSERT_EQ(a.contains(1.2), true);
  ASSERT_EQ(a.contains(3.4), true);
  ASSERT_EQ(a.contains(7.7), true);
  ASSERT_EQ(a.contains(1.01), true);
  ASSERT_EQ(a.contains(1000000.002), false);
  ASSERT_EQ(a.contains(777777.222), false);

  ASSERT_EQ(b.contains(12.1), true);
  ASSERT_EQ(b.contains(228.337), true);
  ASSERT_EQ(b.contains(777.888), true);
  ASSERT_EQ(b.contains(1.23), true);
  ASSERT_EQ(b.contains(2.233), true);
  ASSERT_EQ(a.contains(1000000.002), false);
  ASSERT_EQ(a.contains(777777.222), false);
}
TEST(TestSetMethodFind, TestSetConstruct1) {
  s21::set<int> a{87, 35, 22, 78, 89, 12, 1, 2, 3, 4, 10, 15};
  s21::set<int> b{27, 93, 45, 76, 8888, 13};
  auto iter1 = a.find(87);
  ASSERT_EQ((*iter1).first, 87);
  auto iter2 = a.find(78);
  ASSERT_EQ((*iter2).first, 78);
  auto iter3 = a.find(89);
  ASSERT_EQ((*iter3).first, 89);

  auto iter4 = b.find(27);
  ASSERT_EQ((*iter4).first, 27);
  auto iter5 = b.find(93);
  ASSERT_EQ((*iter5).first, 93);
  auto iter6 = b.find(45);
  ASSERT_EQ((*iter6).first, 45);
}
TEST(TestSetMethodFind, TestSetConstruct2) {
  s21::set<char> a{'b', 'a', 'd', 'e', 'v', 'w', 'o', 'r', 'l'};
  s21::set<char> b{'f', 'q', 'j'};
  auto iter1 = a.find('b');
  ASSERT_EQ((*iter1).first, 'b');
  auto iter2 = a.find('d');
  ASSERT_EQ((*iter2).first, 'd');
  auto iter3 = a.find('w');
  ASSERT_EQ((*iter3).first, 'w');

  auto iter4 = b.find('f');
  ASSERT_EQ((*iter4).first, 'f');
  auto iter5 = b.find('q');
  ASSERT_EQ((*iter5).first, 'q');
  auto iter6 = b.find('j');
  ASSERT_EQ((*iter6).first, 'j');
}
TEST(TestSetMethodFind, TestSetConstruct3) {
  s21::set<std::string> a{"stop", "start", "abcd", "kyky"};
  s21::set<std::string> b{"qaz", "vaz2107", "adsdfg"};
  auto iter1 = a.find("stop");
  ASSERT_EQ((*iter1).first, "stop");
  auto iter2 = a.find("start");
  ASSERT_EQ((*iter2).first, "start");
  auto iter3 = a.find("abcd");
  ASSERT_EQ((*iter3).first, "abcd");

  auto iter4 = b.find("qaz");
  ASSERT_EQ((*iter4).first, "qaz");
  auto iter5 = b.find("vaz2107");
  ASSERT_EQ((*iter5).first, "vaz2107");
  auto iter6 = b.find("adsdfg");
  ASSERT_EQ((*iter6).first, "adsdfg");
}
TEST(TestSetMethodFind, TestSetConstruct4) {
  s21::set<double> a{1.2, 3.4, 7.7, 1.01};
  s21::set<double> b{12.1, 228.337, 777.888, 1.23, 2.233};
  auto iter1 = a.find(1.2);
  ASSERT_EQ((*iter1).first, 1.2);
  auto iter2 = a.find(3.4);
  ASSERT_EQ((*iter2).first, 3.4);
  auto iter3 = a.find(7.7);
  ASSERT_EQ((*iter3).first, 7.7);

  auto iter4 = b.find(12.1);
  ASSERT_EQ((*iter4).first, 12.1);
  auto iter5 = b.find(777.888);
  ASSERT_EQ((*iter5).first, 777.888);
  auto iter6 = b.find(228.337);
  ASSERT_EQ((*iter6).first, 228.337);
}

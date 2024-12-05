#include <gtest/gtest.h>

#include <queue>
#include <string>

#include "s21_queue.h"

TEST(TestQueueConstruct, TestQueueConstruct1) {
  s21::queue<int> a;
  std::queue<int> b;
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestQueueConstruct, TestQueueConstruct2) {
  s21::queue<char> a;
  std::queue<char> b;
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestQueueConstruct, TestQueueConstruct3) {
  s21::queue<double> a;
  std::queue<double> b;
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestQueueConstruct, TestQueueConstruct4) {
  s21::queue<std::string> a;
  std::queue<std::string> b;
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestQueueConstructInit, TestQueueConstruct1) {
  s21::queue<int> a{1, 2, 3, 4, 5};
  std::queue<int> b;
  size_t j = 1;
  for (int i = 1; j < a.size() + 1; ++i, ++j) {
    b.push(i);
  }
  ASSERT_EQ(a.size(), b.size());
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_EQ(a.front(), b.front());
    a.pop();
    b.pop();
  }
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestQueueConstructInit, TestQueueConstruct2) {
  s21::queue<char> a{'a', 'c', 'd', 'e', 'f', 'g', 'h'};
  std::queue<char> b;
  b.push('a');
  b.push('c');
  b.push('d');
  b.push('e');
  b.push('f');
  b.push('g');
  b.push('h');
  ASSERT_EQ(a.size(), b.size());
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_EQ(a.front(), b.front());
    a.pop();
    b.pop();
  }
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestQueueConstructInit, TestQueueConstruct3) {
  s21::queue<double> a{3.2, 4.7, 5.8, 6.9, 7.0, 8.1};
  std::queue<double> b;
  b.push(3.2);
  b.push(4.7);
  b.push(5.8);
  b.push(6.9);
  b.push(7.0);
  b.push(8.1);
  ASSERT_EQ(a.size(), b.size());
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_EQ(a.front(), b.front());
    a.pop();
    b.pop();
  }
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestQueueConstructInit, TestQueueConstruct4) {
  s21::queue<std::string> a{"vvs",  "qwerty", "zxcvbnm",
                            "2345", "45678",  "abcd"};
  std::queue<std::string> b;
  b.push("vvs");
  b.push("qwerty");
  b.push("zxcvbnm");
  b.push("2345");
  b.push("45678");
  b.push("abcd");
  ASSERT_EQ(a.size(), b.size());
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_EQ(a.front(), b.front());
    a.pop();
    b.pop();
  }
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestQueueConstructCopy, TestQueueConstruct1) {
  s21::queue<int> a{1, 2, 3, 4, 5};
  s21::queue<int> d(a);
  std::queue<int> b;
  size_t j = 1;
  for (int i = 1; j < a.size() + 1; ++i, ++j) {
    b.push(i);
  }
  std::queue<int> c(b);
  ASSERT_EQ(a.size(), b.size());
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_EQ(a.front(), b.front());
    a.pop();
    b.pop();
  }

  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.size(), b.size());

  ASSERT_EQ(d.size(), c.size());
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_EQ(d.front(), c.front());
    d.pop();
    c.pop();
  }

  ASSERT_EQ(d.empty(), c.empty());
  ASSERT_EQ(d.size(), c.size());
}

TEST(TestQueueConstructCopy, TestQueueConstruct2) {
  s21::queue<char> a{'a', 'c', 'd', 'e', 'f', 'g', 'h'};
  s21::queue<char> d(a);
  std::queue<char> b;
  b.push('a');
  b.push('c');
  b.push('d');
  b.push('e');
  b.push('f');
  b.push('g');
  b.push('h');
  std::queue<char> c(b);
  ASSERT_EQ(a.size(), b.size());
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_EQ(a.front(), b.front());
    a.pop();
    b.pop();
  }

  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(d.size(), c.size());

  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_EQ(d.front(), c.front());
    d.pop();
    c.pop();
  }

  ASSERT_EQ(d.empty(), c.empty());
  ASSERT_EQ(d.size(), c.size());
}
TEST(TestQueueConstructCopy, TestQueueConstruct3) {
  s21::queue<double> a{3.2, 4.7, 5.8, 6.9, 7.0, 8.1};
  s21::queue<double> d(a);
  std::queue<double> b;
  b.push(3.2);
  b.push(4.7);
  b.push(5.8);
  b.push(6.9);
  b.push(7.0);
  b.push(8.1);
  std::queue<double> c(b);
  ASSERT_EQ(a.size(), b.size());
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_EQ(a.front(), b.front());
    a.pop();
    b.pop();
  }

  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(d.size(), c.size());

  for (size_t i = 0; i < d.size(); ++i) {
    ASSERT_EQ(d.front(), c.front());
    d.pop();
    c.pop();
  }

  ASSERT_EQ(d.empty(), c.empty());
  ASSERT_EQ(d.size(), c.size());
}
TEST(TestQueueConstructCopy, TestQueueConstruct4) {
  s21::queue<std::string> a{"vvs",  "qwerty", "zxcvbnm",
                            "2345", "45678",  "abcd"};
  s21::queue<std::string> d(a);
  std::queue<std::string> b;
  b.push("vvs");
  b.push("qwerty");
  b.push("zxcvbnm");
  b.push("2345");
  b.push("45678");
  b.push("abcd");
  std::queue<std::string> c(b);
  ASSERT_EQ(a.size(), b.size());
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_EQ(a.front(), b.front());
    a.pop();
    b.pop();
  }

  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(d.size(), c.size());

  for (size_t i = 0; i < d.size(); ++i) {
    ASSERT_EQ(d.front(), c.front());
    d.pop();
    c.pop();
  }

  ASSERT_EQ(d.empty(), c.empty());
  ASSERT_EQ(d.size(), c.size());
}
TEST(TestQueueConstructMove, TestQueueConstruct1) {
  s21::queue<int> a{1, 2, 3, 4, 5};
  s21::queue<int> d(std::move(a));
  std::queue<int> b;
  size_t j = 1;
  for (int i = 1; j < d.size() + 1; ++i, ++j) {
    b.push(i);
  }
  std::queue<int> c(std::move(b));

  for (size_t i = 0; i < d.size(); ++i) {
    ASSERT_EQ(d.front(), c.front());
    d.pop();
    c.pop();
  }

  ASSERT_EQ(d.empty(), c.empty());
  ASSERT_EQ(d.size(), c.size());
}

TEST(TestQueueConstructMove, TestQueueConstruct2) {
  s21::queue<char> a{'a', 'c', 'd', 'e', 'f', 'g', 'h'};
  s21::queue<char> d(std::move(a));
  std::queue<char> b;
  b.push('a');
  b.push('c');
  b.push('d');
  b.push('e');
  b.push('f');
  b.push('g');
  b.push('h');
  std::queue<char> c(std::move(b));

  for (size_t i = 0; i < d.size(); ++i) {
    ASSERT_EQ(d.front(), c.front());
    d.pop();
    c.pop();
  }

  ASSERT_EQ(d.empty(), c.empty());
  ASSERT_EQ(d.size(), c.size());
}
TEST(TestQueueConstructMove, TestQueueConstruct3) {
  s21::queue<double> a{3.2, 4.7, 5.8, 6.9, 7.0, 8.1};
  s21::queue<double> d(std::move(a));
  std::queue<double> b;
  b.push(3.2);
  b.push(4.7);
  b.push(5.8);
  b.push(6.9);
  b.push(7.0);
  b.push(8.1);
  std::queue<double> c(std::move(b));

  for (size_t i = 0; i < d.size(); ++i) {
    ASSERT_EQ(d.front(), c.front());
    d.pop();
    c.pop();
  }

  ASSERT_EQ(d.empty(), c.empty());
  ASSERT_EQ(d.size(), c.size());
}
TEST(TestQueueConstructMove, TestQueueConstruct4) {
  s21::queue<std::string> a{"vvs",  "qwerty", "zxcvbnm",
                            "2345", "45678",  "abcd"};
  s21::queue<std::string> d(std::move(a));
  std::queue<std::string> b;
  b.push("vvs");
  b.push("qwerty");
  b.push("zxcvbnm");
  b.push("2345");
  b.push("45678");
  b.push("abcd");
  std::queue<std::string> c(std::move(b));

  for (size_t i = 0; i < d.size(); ++i) {
    ASSERT_EQ(d.front(), c.front());
    d.pop();
    c.pop();
  }

  ASSERT_EQ(d.empty(), c.empty());
  ASSERT_EQ(d.size(), c.size());
}
TEST(TestQueueOperatorMove, TestQueueConstruct1) {
  s21::queue<int> a{1, 2, 3, 4, 5};
  s21::queue<int> d;
  d = std::move(a);
  std::queue<int> b;
  size_t j = 1;
  for (int i = 1; j < d.size() + 1; ++i, ++j) {
    b.push(i);
  }
  std::queue<int> c;
  c = std::move(b);
  for (size_t i = 0; i < d.size(); ++i) {
    ASSERT_EQ(d.front(), c.front());
    d.pop();
    c.pop();
  }

  ASSERT_EQ(d.empty(), c.empty());
  ASSERT_EQ(d.size(), c.size());
}

TEST(TestQueueOperatorMove, TestQueueConstruct2) {
  s21::queue<char> a{'a', 'c', 'd', 'e', 'f', 'g', 'h'};
  s21::queue<char> d;
  d = std::move(a);
  std::queue<char> b;
  b.push('a');
  b.push('c');
  b.push('d');
  b.push('e');
  b.push('f');
  b.push('g');
  b.push('h');
  std::queue<char> c;
  c = std::move(b);
  for (size_t i = 0; i < d.size(); ++i) {
    ASSERT_EQ(d.front(), c.front());
    d.pop();
    c.pop();
  }

  ASSERT_EQ(d.empty(), c.empty());
  ASSERT_EQ(d.size(), c.size());
}
TEST(TestQueueOperatorMove, TestQueueConstruct3) {
  s21::queue<double> a{3.2, 4.7, 5.8, 6.9, 7.0, 8.1};
  s21::queue<double> d;
  d = std::move(a);
  std::queue<double> b;
  b.push(3.2);
  b.push(4.7);
  b.push(5.8);
  b.push(6.9);
  b.push(7.0);
  b.push(8.1);
  std::queue<double> c;
  c = std::move(b);

  for (size_t i = 0; i < d.size(); ++i) {
    ASSERT_EQ(d.front(), c.front());
    d.pop();
    c.pop();
  }

  ASSERT_EQ(d.empty(), c.empty());
  ASSERT_EQ(d.size(), c.size());
}
TEST(TestQueueOperatorMove, TestQueueConstruct4) {
  s21::queue<std::string> a{"vvs",  "qwerty", "zxcvbnm",
                            "2345", "45678",  "abcd"};
  s21::queue<std::string> d;
  d = std::move(a);
  std::queue<std::string> b;
  b.push("vvs");
  b.push("qwerty");
  b.push("zxcvbnm");
  b.push("2345");
  b.push("45678");
  b.push("abcd");
  std::queue<std::string> c;
  c = std::move(b);

  for (size_t i = 0; i < d.size(); ++i) {
    ASSERT_EQ(d.front(), c.front());
    d.pop();
    c.pop();
  }

  ASSERT_EQ(d.empty(), c.empty());
  ASSERT_EQ(d.size(), c.size());
}
TEST(TestQueueOperatorCopy, TestQueueConstruct1) {
  s21::queue<int> a{1, 2, 3, 4, 5};
  s21::queue<int> d;
  d = a;
  std::queue<int> b;
  size_t j = 1;
  for (int i = 1; j < d.size() + 1; ++i, ++j) {
    b.push(i);
  }
  std::queue<int> c;
  c = b;
  for (size_t i = 0; i < d.size(); ++i) {
    ASSERT_EQ(d.front(), c.front());
    d.pop();
    c.pop();
  }

  ASSERT_EQ(d.empty(), c.empty());
  ASSERT_EQ(d.size(), c.size());
}

TEST(TestQueueOperatorCopy, TestQueueConstruct2) {
  s21::queue<char> a{'a', 'c', 'd', 'e', 'f', 'g', 'h'};
  s21::queue<char> d;
  d = a;
  std::queue<char> b;
  b.push('a');
  b.push('c');
  b.push('d');
  b.push('e');
  b.push('f');
  b.push('g');
  b.push('h');
  std::queue<char> c;
  c = b;
  for (size_t i = 0; i < d.size(); ++i) {
    ASSERT_EQ(d.front(), c.front());
    d.pop();
    c.pop();
  }

  ASSERT_EQ(d.empty(), c.empty());
  ASSERT_EQ(d.size(), c.size());
}
TEST(TestQueueOperatorCopy, TestQueueConstruct3) {
  s21::queue<double> a{3.2, 4.7, 5.8, 6.9, 7.0, 8.1};
  s21::queue<double> d;
  d = a;
  std::queue<double> b;
  b.push(3.2);
  b.push(4.7);
  b.push(5.8);
  b.push(6.9);
  b.push(7.0);
  b.push(8.1);
  std::queue<double> c;
  c = b;

  for (size_t i = 0; i < d.size(); ++i) {
    ASSERT_EQ(d.front(), c.front());
    d.pop();
    c.pop();
  }

  ASSERT_EQ(d.empty(), c.empty());
  ASSERT_EQ(d.size(), c.size());
}
TEST(TestQueueOperatorCopy, TestQueueConstruct4) {
  s21::queue<std::string> a{"vvs",  "qwerty", "zxcvbnm",
                            "2345", "45678",  "abcd"};
  s21::queue<std::string> d;
  d = a;
  std::queue<std::string> b;
  b.push("vvs");
  b.push("qwerty");
  b.push("zxcvbnm");
  b.push("2345");
  b.push("45678");
  b.push("abcd");
  std::queue<std::string> c;
  c = b;

  for (size_t i = 0; i < d.size(); ++i) {
    ASSERT_EQ(d.front(), c.front());
    d.pop();
    c.pop();
  }

  ASSERT_EQ(d.empty(), c.empty());
  ASSERT_EQ(d.size(), c.size());
}

TEST(TestQueueMengodPushPop, TestQueueConstruct1) {
  s21::queue<int> a;
  std::queue<int> b;
  size_t j = 1;
  for (int i = 1; j < 5; ++i, ++j) {
    b.push(i);
    a.push(i);
  }
  ASSERT_EQ(a.size(), b.size());
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_EQ(a.front(), b.front());
    a.pop();
    b.pop();
  }
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestQueueMengodPushPop, TestQueueConstruct2) {
  s21::queue<char> a;
  std::queue<char> b;
  b.push('a');
  b.push('c');
  b.push('d');
  b.push('e');
  b.push('f');
  b.push('g');
  b.push('h');

  a.push('a');
  a.push('c');
  a.push('d');
  a.push('e');
  a.push('f');
  a.push('g');
  a.push('h');

  ASSERT_EQ(a.size(), b.size());
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_EQ(a.front(), b.front());
    a.pop();
    b.pop();
  }
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestQueueMengodPushPop, TestQueueConstruct3) {
  s21::queue<double> a;
  std::queue<double> b;
  b.push(3.2);
  b.push(4.7);
  b.push(5.8);
  b.push(6.9);
  b.push(7.0);
  b.push(8.1);

  a.push(3.2);
  a.push(4.7);
  a.push(5.8);
  a.push(6.9);
  a.push(7.0);
  a.push(8.1);

  ASSERT_EQ(a.size(), b.size());
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_EQ(a.front(), b.front());
    a.pop();
    b.pop();
  }
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestQueueMengodPushPop, TestQueueConstruct4) {
  s21::queue<std::string> a;
  std::queue<std::string> b;
  b.push("vvs");
  b.push("qwerty");
  b.push("zxcvbnm");
  b.push("2345");
  b.push("45678");
  b.push("abcd");

  a.push("vvs");
  a.push("qwerty");
  a.push("zxcvbnm");
  a.push("2345");
  a.push("45678");
  a.push("abcd");

  ASSERT_EQ(a.size(), b.size());
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_EQ(a.front(), b.front());
    a.pop();
    b.pop();
  }
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.size(), b.size());
}

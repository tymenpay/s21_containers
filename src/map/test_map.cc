#include <gtest/gtest.h>

#include <map>
#include <string>

#include "s21_map.h"

TEST(TestMapConstruct, TestMapConstruct1) {
  s21::map<int, int> a;
  s21::map<int, int> b;
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestMapConstruct, TestMapConstruct2) {
  s21::map<char, int> a;
  s21::map<char, int> b;
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestMapConstruct, TestMapConstruct3) {
  s21::map<std::string, int> a;
  s21::map<std::string, int> b;
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestMapConstruct, TestMapConstruct4) {
  s21::map<int, double> a;
  s21::map<int, double> b;
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestMapConstruct, TestMapConstructInit1) {
  s21::map<int, int> a{{2, 1}, {4, 3}};
  std::map<int, int> b{{2, 1}, {4, 3}};
  auto iter1 = a.begin();
  auto iter2 = b.begin();
  ASSERT_EQ(*iter1, *iter2);
  ++iter1;
  ++iter2;
  ASSERT_EQ(*iter1, *iter2);
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestMapConstruct, TestMapConstructInit2) {
  s21::map<int, int> a{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  std::map<int, int> b{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  auto iter1 = a.begin();
  for (auto i : b) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestMapConstruct, TestMapConstructInit3) {
  s21::map<double, int> a{{2.1, 1}, {4.2, 3}};
  std::map<double, int> b{{2.1, 1}, {4.2, 3}};
  auto iter1 = a.begin();
  for (auto i : b) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestMapConstruct, TestMapConstructInit4) {
  s21::map<double, int> a{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  std::map<double, int> b{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  auto iter1 = a.begin();
  for (auto i : b) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestMapConstruct, TestMapConstructInit5) {
  s21::map<char, int> a{{'c', 1}, {'a', 3}};
  std::map<double, int> b{{'c', 1}, {'a', 3}};
  auto iter1 = a.begin();
  for (auto i : b) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestMapConstruct, TestMapConstructInit6) {
  s21::map<char, int> a{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  std::map<char, int> b{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  auto iter1 = a.begin();
  for (auto i : b) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestMapConstruct, TestMapConstructInit7) {
  s21::map<std::string, int> a{{"kak", 1}, {"adad", 3}};
  std::map<std::string, int> b{{"kak", 1}, {"adad", 3}};
  auto iter1 = a.begin();
  for (auto i : b) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestMapConstruct, TestMapConstructInit8) {
  s21::map<std::string, int> a{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  std::map<std::string, int> b{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  auto iter1 = a.begin();
  for (auto i : b) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestMapConstruct, TestMapConstructInit9) {
  s21::map<std::string, char> a{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  std::map<std::string, char> b{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  auto iter1 = a.begin();
  for (auto i : b) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestMapConstruct, TestMapConstructInit10) {
  s21::map<double, std::string> a{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  std::map<double, std::string> b{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  auto iter1 = a.begin();
  for (auto i : b) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestMapConstruct, TestMapConstructCopy1) {
  s21::map<int, int> a{{2, 1}, {4, 3}};
  s21::map<int, int> b(a);
  std::map<int, int> c{{2, 1}, {4, 3}};
  std::map<int, int> d(c);
  auto iter1 = b.begin();
  auto iter2 = d.begin();
  ASSERT_EQ(*iter1, *iter2);
  ++iter1;
  ++iter2;
  ASSERT_EQ(*iter1, *iter2);
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestMapConstruct, TestMapConstructCopy2) {
  s21::map<int, int> a{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  s21::map<int, int> b(a);
  std::map<int, int> c{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  std::map<int, int> d(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapConstruct, TestMapConstructCopy3) {
  s21::map<double, int> a{{2.1, 1}, {4.2, 3}};
  s21::map<double, int> b(a);
  std::map<double, int> c{{2.1, 1}, {4.2, 3}};
  std::map<double, int> d(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapConstruct, TestMapConstructCopy4) {
  s21::map<double, int> a{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  s21::map<double, int> b(a);
  std::map<double, int> c{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  std::map<double, int> d(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapConstruct, TestMapConstructCopy5) {
  s21::map<char, int> a{{'c', 1}, {'a', 3}};
  s21::map<char, int> b(a);
  std::map<char, int> c{{'c', 1}, {'a', 3}};
  std::map<char, int> d(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapConstruct, TestMapConstructCopy6) {
  s21::map<char, int> a{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  s21::map<char, int> b(a);
  std::map<char, int> c{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  std::map<char, int> d(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapConstruct, TestMapConstructCopy7) {
  s21::map<std::string, int> a{{"kak", 1}, {"adad", 3}};
  s21::map<std::string, int> b(a);
  std::map<std::string, int> c{{"kak", 1}, {"adad", 3}};
  std::map<std::string, int> d(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapConstruct, TestMapConstructCopy8) {
  s21::map<std::string, int> a{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  s21::map<std::string, int> b(a);
  std::map<std::string, int> c{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  std::map<std::string, int> d(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapConstruct, TestMapConstructCopy9) {
  s21::map<std::string, char> a{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  s21::map<std::string, char> b(a);
  std::map<std::string, char> c{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  std::map<std::string, char> d(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapConstruct, TestMapConstructCopy10) {
  s21::map<double, std::string> a{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  s21::map<double, std::string> b(a);
  std::map<double, std::string> c{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  std::map<double, std::string> d(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}

TEST(TestMapConstruct, TestMapConstructMove1) {
  s21::map<int, int> a{{2, 1}, {4, 3}};
  s21::map<int, int> b(std::move(a));
  std::map<int, int> c{{2, 1}, {4, 3}};
  std::map<int, int> d(std::move(c));
  auto iter1 = b.begin();
  auto iter2 = d.begin();
  ASSERT_EQ(*iter1, *iter2);
  ++iter1;
  ++iter2;
  ASSERT_EQ(*iter1, *iter2);
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapConstruct, TestMapConstructMove2) {
  s21::map<int, int> a{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  s21::map<int, int> b(std::move(a));
  std::map<int, int> c{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  std::map<int, int> d(std::move(c));
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapConstruct, TestMapConstructMove3) {
  s21::map<double, int> a{{2.1, 1}, {4.2, 3}};
  s21::map<double, int> b(std::move(a));
  std::map<double, int> c{{2.1, 1}, {4.2, 3}};
  std::map<double, int> d(std::move(c));
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapConstruct, TestMapConstructMove4) {
  s21::map<double, int> a{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  s21::map<double, int> b(std::move(a));
  std::map<double, int> c{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  std::map<double, int> d(std::move(c));
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapConstruct, TestMapConstructMove5) {
  s21::map<char, int> a{{'c', 1}, {'a', 3}};
  s21::map<char, int> b(std::move(a));
  std::map<char, int> c{{'c', 1}, {'a', 3}};
  std::map<char, int> d(std::move(c));
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapConstruct, TestMapConstructMove6) {
  s21::map<char, int> a{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  s21::map<char, int> b(std::move(a));
  std::map<char, int> c{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  std::map<char, int> d(std::move(c));
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapConstruct, TestMapConstructMove7) {
  s21::map<std::string, int> a{{"kak", 1}, {"adad", 3}};
  s21::map<std::string, int> b(std::move(a));
  std::map<std::string, int> c{{"kak", 1}, {"adad", 3}};
  std::map<std::string, int> d(std::move(c));
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapConstruct, TestMapConstructMove8) {
  s21::map<std::string, int> a{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  s21::map<std::string, int> b(std::move(a));
  std::map<std::string, int> c{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  std::map<std::string, int> d(std::move(c));
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapConstruct, TestMapConstructMove9) {
  s21::map<std::string, char> a{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  s21::map<std::string, char> b(std::move(a));
  std::map<std::string, char> c{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  std::map<std::string, char> d(std::move(c));
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapConstruct, TestMapConstructMove10) {
  s21::map<double, std::string> a{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  s21::map<double, std::string> b(std::move(a));
  std::map<double, std::string> c{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  std::map<double, std::string> d(std::move(c));
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}

TEST(TestMapOperatorEq, TestMapOperatorEq1) {
  s21::map<int, int> a{{2, 1}, {4, 3}};
  s21::map<int, int> b;
  b = std::move(a);
  std::map<int, int> c{{2, 1}, {4, 3}};
  std::map<int, int> d;
  d = std::move(c);
  auto iter1 = b.begin();
  auto iter2 = d.begin();
  ASSERT_EQ(*iter1, *iter2);
  ++iter1;
  ++iter2;
  ASSERT_EQ(*iter1, *iter2);
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapOperatorEq, TestMapOperatorEq2) {
  s21::map<int, int> a{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  s21::map<int, int> b;
  b = std::move(a);
  std::map<int, int> c{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  std::map<int, int> d;
  d = std::move(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapOperatorEq, TestMapOperatorEq3) {
  s21::map<double, int> a{{2.1, 1}, {4.2, 3}};
  s21::map<double, int> b;
  b = std::move(a);
  std::map<double, int> c{{2.1, 1}, {4.2, 3}};
  std::map<double, int> d;
  d = std::move(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapOperatorEq, TestMapOperatorEq4) {
  s21::map<double, int> a{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  s21::map<double, int> b;
  b = std::move(a);
  std::map<double, int> c{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  std::map<double, int> d;
  d = std::move(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapOperatorEq, TestMapOperatorEq5) {
  s21::map<char, int> a{{'c', 1}, {'a', 3}};
  s21::map<char, int> b;
  b = std::move(a);
  std::map<char, int> c{{'c', 1}, {'a', 3}};
  std::map<char, int> d;
  d = std::move(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapOperatorEq, TestMapOperatorEq6) {
  s21::map<char, int> a{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  s21::map<char, int> b;
  b = std::move(a);
  std::map<char, int> c{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  std::map<char, int> d;
  d = std::move(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapOperatorEq, TestMapOperatorEq7) {
  s21::map<std::string, int> a{{"kak", 1}, {"adad", 3}};
  s21::map<std::string, int> b;
  b = std::move(a);
  std::map<std::string, int> c{{"kak", 1}, {"adad", 3}};
  std::map<std::string, int> d;
  d = std::move(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapOperatorEq, TestMapOperatorEq8) {
  s21::map<std::string, int> a{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  s21::map<std::string, int> b;
  b = std::move(a);
  std::map<std::string, int> c{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  std::map<std::string, int> d;
  d = std::move(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapOperatorEq, TestMapOperatorEq9) {
  s21::map<std::string, char> a{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  s21::map<std::string, char> b;
  b = std::move(a);
  std::map<std::string, char> c{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  std::map<std::string, char> d;
  d = std::move(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapOperatorEq, TestMapOperatorEq10) {
  s21::map<double, std::string> a{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  s21::map<double, std::string> b;
  b = std::move(a);
  std::map<double, std::string> c{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  std::map<double, std::string> d;
  d = std::move(c);
  auto iter1 = b.begin();
  for (auto i : d) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(b.size(), d.size());
}

TEST(TestMapMethodAt, TestMapMethodAt1) {
  s21::map<int, int> a{{2, 1}, {4, 3}};
  std::map<int, int> c{{2, 1}, {4, 3}};
  ASSERT_EQ(a.at(2), c.at(2));
  ASSERT_EQ(a.at(4), c.at(4));
}
TEST(TestMapMethodAt, TestMapMethodAt2) {
  s21::map<int, int> a{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  std::map<int, int> c{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  ASSERT_EQ(a.at(200), c.at(200));
  ASSERT_EQ(a.at(4), c.at(4));
  ASSERT_EQ(a.at(11), c.at(11));
  ASSERT_EQ(a.at(7), c.at(7));
}
TEST(TestMapMethodAt, TestMapMethodAt3) {
  s21::map<double, int> a{{2.1, 1}, {4.2, 3}};
  std::map<double, int> c{{2.1, 1}, {4.2, 3}};
  ASSERT_EQ(a.at(2.1), c.at(2.1));
  ASSERT_EQ(a.at(4.2), c.at(4.2));
}
TEST(TestMapMethodAt, TestMapMethodAt4) {
  s21::map<double, int> a{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  std::map<double, int> c{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  ASSERT_EQ(a.at(2.1), c.at(2.1));
  ASSERT_EQ(a.at(4.2), c.at(4.2));
  ASSERT_EQ(a.at(23.4), c.at(23.4));
  ASSERT_EQ(a.at(77.77), c.at(77.77));
}
TEST(TestMapMethodAt, TestMapMethodAt5) {
  s21::map<char, int> a{{'c', 1}, {'a', 3}};
  std::map<char, int> c{{'c', 1}, {'a', 3}};
  ASSERT_EQ(a.at('c'), c.at('c'));
  ASSERT_EQ(a.at('a'), c.at('a'));
}
TEST(TestMapMethodAt, TestMapMethodAt6) {
  s21::map<char, int> a{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  std::map<char, int> c{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  ASSERT_EQ(a.at('c'), c.at('c'));
  ASSERT_EQ(a.at('a'), c.at('a'));
  ASSERT_EQ(a.at('d'), c.at('d'));
  ASSERT_EQ(a.at('e'), c.at('e'));
  ASSERT_EQ(a.at('v'), c.at('v'));
  ASSERT_EQ(a.at('w'), c.at('w'));
}
TEST(TestMapMethodAt, TestMapMethodAt7) {
  s21::map<std::string, int> a{{"kak", 1}, {"adad", 3}};
  std::map<std::string, int> c{{"kak", 1}, {"adad", 3}};
  ASSERT_EQ(a.at("kak"), c.at("kak"));
  ASSERT_EQ(a.at("adad"), c.at("adad"));
}
TEST(TestMapMethodAt, TestMapMethodAt8) {
  s21::map<std::string, int> a{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  std::map<std::string, int> c{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  ASSERT_EQ(a.at("cnad"), c.at("cnad"));
  ASSERT_EQ(a.at("anfr"), c.at("anfr"));
  ASSERT_EQ(a.at("dovi"), c.at("dovi"));
  ASSERT_EQ(a.at("kdad"), c.at("kdad"));
  ASSERT_EQ(a.at("eyeg"), c.at("eyeg"));
  ASSERT_EQ(a.at("vdeidioe"), c.at("vdeidioe"));
}
TEST(TestMapMethodAt, TestMapMethodAt9) {
  s21::map<std::string, char> a{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  std::map<std::string, char> c{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  ASSERT_EQ(a.at("cnad"), c.at("cnad"));
  ASSERT_EQ(a.at("anfr"), c.at("anfr"));
  ASSERT_EQ(a.at("dovi"), c.at("dovi"));
  ASSERT_EQ(a.at("kdad"), c.at("kdad"));
  ASSERT_EQ(a.at("eyeg"), c.at("eyeg"));
  ASSERT_EQ(a.at("vdeidioe"), c.at("vdeidioe"));
}
TEST(TestMapMethodAt, TestMapMethodAt10) {
  s21::map<double, std::string> a{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  std::map<double, std::string> c{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  ASSERT_EQ(a.at(201.72), c.at(201.72));
  ASSERT_EQ(a.at(172.89), c.at(172.89));
  ASSERT_EQ(a.at(234.67), c.at(234.67));
  ASSERT_EQ(a.at(12.34), c.at(12.34));
  ASSERT_EQ(a.at(2.228), c.at(2.228));
  ASSERT_EQ(a.at(7.77), c.at(7.77));
}

TEST(TestMapOperatorT, TestMapOperatorT1) {
  s21::map<int, int> a{{2, 1}, {4, 3}};
  std::map<int, int> c{{2, 1}, {4, 3}};
  ASSERT_EQ(a[2], c[2]);
  ASSERT_EQ(a[4], c[4]);
}
TEST(TestMapOperatorT, TestMapOperatorT2) {
  s21::map<int, int> a{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  std::map<int, int> c{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  ASSERT_EQ(a[200], c[200]);
  ASSERT_EQ(a[4], c[4]);
  ASSERT_EQ(a[11], c[11]);
  ASSERT_EQ(a[7], c[7]);
}
TEST(TestMapOperatorT, TestMapOperatorT3) {
  s21::map<double, int> a{{2.1, 1}, {4.2, 3}};
  std::map<double, int> c{{2.1, 1}, {4.2, 3}};
  ASSERT_EQ(a[2.1], c[2.1]);
  ASSERT_EQ(a[4.2], c[4.2]);
}
TEST(TestMapOperatorT, TestMapOperatorT4) {
  s21::map<double, int> a{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  std::map<double, int> c{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  ASSERT_EQ(a[2.1], c[2.1]);
  ASSERT_EQ(a[4.2], c[4.2]);
  ASSERT_EQ(a[23.4], c[23.4]);
  ASSERT_EQ(a[77.77], c[77.77]);
}
TEST(TestMapOperatorT, TestMapOperatorT5) {
  s21::map<char, int> a{{'c', 1}, {'a', 3}};
  std::map<char, int> c{{'c', 1}, {'a', 3}};
  ASSERT_EQ(a['c'], c['c']);
  ASSERT_EQ(a['a'], c['a']);
}
TEST(TestMapOperatorT, TestMapOperatorT6) {
  s21::map<char, int> a{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  std::map<char, int> c{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  ASSERT_EQ(a['c'], c['c']);
  ASSERT_EQ(a['a'], c['a']);
  ASSERT_EQ(a['d'], c['d']);
  ASSERT_EQ(a['e'], c['e']);
  ASSERT_EQ(a['v'], c['v']);
  ASSERT_EQ(a['w'], c['w']);
}
TEST(TestMapOperatorT, TestMapOperatorT7) {
  s21::map<std::string, int> a{{"kak", 1}, {"adad", 3}};
  std::map<std::string, int> c{{"kak", 1}, {"adad", 3}};
  ASSERT_EQ(a["kak"], c["kak"]);
  ASSERT_EQ(a["adad"], c["adad"]);
}
TEST(TestMapOperatorT, TestMapOperatorT8) {
  s21::map<std::string, int> a{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  std::map<std::string, int> c{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  ASSERT_EQ(a["cnad"], c["cnad"]);
  ASSERT_EQ(a["anfr"], c["anfr"]);
  ASSERT_EQ(a["dovi"], c["dovi"]);
  ASSERT_EQ(a["kdad"], c["kdad"]);
  ASSERT_EQ(a["eyeg"], c["eyeg"]);
  ASSERT_EQ(a["vdeidioe"], c["vdeidioe"]);
}
TEST(TestMapOperatorT, TestMapOperatorT9) {
  s21::map<std::string, char> a{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  std::map<std::string, char> c{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  ASSERT_EQ(a["cnad"], c["cnad"]);
  ASSERT_EQ(a["anfr"], c["anfr"]);
  ASSERT_EQ(a["dovi"], c["dovi"]);
  ASSERT_EQ(a["kdad"], c["kdad"]);
  ASSERT_EQ(a["eyeg"], c["eyeg"]);
  ASSERT_EQ(a["vdeidioe"], c["vdeidioe"]);
}
TEST(TestMapOperatorT, TestMapOperatorT10) {
  s21::map<double, std::string> a{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  std::map<double, std::string> c{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};

  ASSERT_EQ(a[12.34], c[12.34]);
  ASSERT_EQ(a[2.228], c[2.228]);
  ASSERT_EQ(a[7.77], c[7.77]);
}
TEST(TestMapMethodBegin, TestMapMethodBegin1) {
  s21::map<int, int> a{{2, 1}, {4, 3}};
  std::map<int, int> c{{2, 1}, {4, 3}};
  ASSERT_EQ(*a.begin(), *c.begin());
}
TEST(TestMapMethodBegin, TestMapMethodBegin2) {
  s21::map<int, int> a{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  std::map<int, int> c{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  ASSERT_EQ(*a.begin(), *c.begin());
}
TEST(TestMapMethodBegin, TestMapMethodBegin3) {
  s21::map<double, int> a{{2.1, 1}, {4.2, 3}};
  std::map<double, int> c{{2.1, 1}, {4.2, 3}};
  ASSERT_EQ(*a.begin(), *c.begin());
}
TEST(TestMapMethodBegin, TestMapMethodBegin4) {
  s21::map<double, int> a{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  std::map<double, int> c{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  ASSERT_EQ(*a.begin(), *c.begin());
}
TEST(TestMapMethodBegin, TestMapMethodBegin5) {
  s21::map<char, int> a{{'c', 1}, {'a', 3}};
  std::map<char, int> c{{'c', 1}, {'a', 3}};
  ASSERT_EQ(*a.begin(), *c.begin());
}
TEST(TestMapMethodBegin, TestMapMethodBegin6) {
  s21::map<char, int> a{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  std::map<char, int> c{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  ASSERT_EQ(*a.begin(), *c.begin());
}
TEST(TestMapMethodBegin, TestMapMethodBegin7) {
  s21::map<std::string, int> a{{"kak", 1}, {"adad", 3}};
  std::map<std::string, int> c{{"kak", 1}, {"adad", 3}};
  ASSERT_EQ(*a.begin(), *c.begin());
}
TEST(TestMapMethodBegin, TestMapMethodBegin8) {
  s21::map<std::string, int> a{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  std::map<std::string, int> c{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  ASSERT_EQ(*a.begin(), *c.begin());
}
TEST(TestMapMethodBegin, TestMapMethodBegin9) {
  s21::map<std::string, char> a{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  std::map<std::string, char> c{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  ASSERT_EQ(*a.begin(), *c.begin());
}
TEST(TestMapMethodBegin, TestMapMethodBegin10) {
  s21::map<double, std::string> a{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  std::map<double, std::string> c{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  ASSERT_EQ(*a.begin(), *c.begin());
}
TEST(TestMapMethodEnd, TestMapMethodEnd1) {
  s21::map<int, int> a{{2, 1}, {4, 3}};
  std::map<int, int> c{{2, 1}, {4, 3}};
  ASSERT_EQ(*(--a.end()), *(--c.end()));
}
TEST(TestMapMethodEnd, TestMapMethodEnd2) {
  s21::map<int, int> a{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  std::map<int, int> c{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  ASSERT_EQ(*(--a.end()), *(--c.end()));
}
TEST(TestMapMethodEnd, TestMapMethodEnd3) {
  s21::map<double, int> a{{2.1, 1}, {4.2, 3}};
  std::map<double, int> c{{2.1, 1}, {4.2, 3}};
  ASSERT_EQ(*(--a.end()), *(--c.end()));
}
TEST(TestMapMethodEnd, TestMapMethodEnd4) {
  s21::map<double, int> a{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  std::map<double, int> c{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  ASSERT_EQ(*(--a.end()), *(--c.end()));
}
TEST(TestMapMethodEnd, TestMapMethodEnd5) {
  s21::map<char, int> a{{'c', 1}, {'a', 3}};
  std::map<char, int> c{{'c', 1}, {'a', 3}};
  ASSERT_EQ(*(--a.end()), *(--c.end()));
}
TEST(TestMapMethodEnd, TestMapMethodEnd6) {
  s21::map<char, int> a{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  std::map<char, int> c{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  ASSERT_EQ(*(--a.end()), *(--c.end()));
}
TEST(TestMapMethodEnd, TestMapMethodEnd7) {
  s21::map<std::string, int> a{{"kak", 1}, {"adad", 3}};
  std::map<std::string, int> c{{"kak", 1}, {"adad", 3}};
  ASSERT_EQ(*(--a.end()), *(--c.end()));
}
TEST(TestMapMethodEnd, TestMapMethodEnd8) {
  s21::map<std::string, int> a{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  std::map<std::string, int> c{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  ASSERT_EQ(*(--a.end()), *(--c.end()));
}
TEST(TestMapMethodEnd, TestMapMethodEnd9) {
  s21::map<std::string, char> a{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  std::map<std::string, char> c{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  ASSERT_EQ(*(--a.end()), *(--c.end()));
}
TEST(TestMapMethodEnd, TestMapMethodEnd10) {
  s21::map<double, std::string> a{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  std::map<double, std::string> c{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  ASSERT_EQ(*(--a.end()), *(--c.end()));
}

TEST(TestMapMethodEmpty, TestMapMethodisEmpty1) {
  s21::map<int, int> a;
  std::map<int, int> c;
  ASSERT_EQ(a.empty(), c.empty());
}

TEST(TestMapMethodEmpty, TestMapMethodnoEmpt1y) {
  s21::map<int, int> a{{2, 1}, {4, 3}};
  std::map<int, int> c{{2, 1}, {4, 3}};
  ASSERT_EQ(a.empty(), c.empty());
}

TEST(TestMapMethodSize, TestMapMethodSize1) {
  s21::map<int, int> a{{2, 1}, {4, 3}};
  std::map<int, int> c{{2, 1}, {4, 3}};
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodSize, TestMapMethodSize2) {
  s21::map<int, int> a;
  std::map<int, int> c;
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodSize, TestMapMethodSize3) {
  s21::map<int, int> a{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  std::map<int, int> c{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodSize, TestMapMethodSize4) {
  s21::map<double, int> a{{2.1, 1}, {4.2, 3}};
  std::map<double, int> c{{2.1, 1}, {4.2, 3}};
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodSize, TestMapMethodSize5) {
  s21::map<double, int> a{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  std::map<double, int> c{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodSize, TestMapMethodSize6) {
  s21::map<char, int> a{{'c', 1}, {'a', 3}};
  std::map<char, int> c{{'c', 1}, {'a', 3}};
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodSize, TestMapMethodSize7) {
  s21::map<char, int> a{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  std::map<char, int> c{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodSize, TestMapMethodSize8) {
  s21::map<std::string, int> a{{"kak", 1}, {"adad", 3}};
  std::map<std::string, int> c{{"kak", 1}, {"adad", 3}};
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodSize, TestMapMethodSize9) {
  s21::map<std::string, int> a{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  std::map<std::string, int> c{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodSize, TestMapMethodSize10) {
  s21::map<std::string, char> a{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  std::map<std::string, char> c{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodSize, TestMapMethodSize11) {
  s21::map<double, std::string> a{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  std::map<double, std::string> c{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  ASSERT_EQ(a.size(), c.size());
}

TEST(TestMapMethodClear, TestMapMethodClear1) {
  s21::map<int, int> a{{2, 1}, {4, 3}};
  std::map<int, int> c{{2, 1}, {4, 3}};
  a.clear();
  c.clear();
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodClear, TestMapMethodClear2) {
  s21::map<int, int> a{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  std::map<int, int> c{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  a.clear();
  c.clear();
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodClear, TestMapMethodClear3) {
  s21::map<double, int> a{{2.1, 1}, {4.2, 3}};
  std::map<double, int> c{{2.1, 1}, {4.2, 3}};
  a.clear();
  c.clear();
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodClear, TestMapMethodClear4) {
  s21::map<double, int> a{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  std::map<double, int> c{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  a.clear();
  c.clear();
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodClear, TestMapMethodClear5) {
  s21::map<char, int> a{{'c', 1}, {'a', 3}};
  std::map<char, int> c{{'c', 1}, {'a', 3}};
  a.clear();
  c.clear();
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodClear, TestMapMethodClear6) {
  s21::map<char, int> a{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  std::map<char, int> c{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  a.clear();
  c.clear();
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodClear, TestMapMethodClear7) {
  s21::map<std::string, int> a{{"kak", 1}, {"adad", 3}};
  std::map<std::string, int> c{{"kak", 1}, {"adad", 3}};
  a.clear();
  c.clear();
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodClear, TestMapMethodClear8) {
  s21::map<std::string, int> a{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  std::map<std::string, int> c{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  a.clear();
  c.clear();
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodClear, TestMapMethodClear9) {
  s21::map<std::string, char> a{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  std::map<std::string, char> c{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  a.clear();
  c.clear();
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodClear, TestMapMethodClear10) {
  s21::map<double, std::string> a{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  std::map<double, std::string> c{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  a.clear();
  c.clear();
  ASSERT_EQ(a.size(), c.size());
}

TEST(TestMapMethodInsert, TestMapMethodInsert1) {
  s21::map<int, int> a{{2, 1}, {4, 3}};
  std::map<int, int> c{{2, 1}, {4, 3}};
  a.insert({5, 1});
  c.insert({5, 1});
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodInsert, TestMapMethodInsert2) {
  s21::map<int, int> a{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  std::map<int, int> c{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  a.insert({99, 1});
  c.insert({99, 1});
  a.insert({276, 9090});
  c.insert({276, 9090});
  a.insert({888, 555});
  c.insert({888, 555});
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodInsert, TestMapMethodInsert3) {
  s21::map<double, int> a{{2.1, 1}, {4.2, 3}};
  std::map<double, int> c{{2.1, 1}, {4.2, 3}};
  a.insert({2.7, 4});
  c.insert({2.7, 4});
  ;
  a.insert({276.89, 9090});
  c.insert({276.89, 9090});
  a.insert({8.88, 555});
  c.insert({8.88, 555});
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodInsert, TestMapMethodInsert4) {
  s21::map<double, int> a{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  std::map<double, int> c{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  a.insert({2.7, 4});
  c.insert({2.7, 4});
  ;
  a.insert({276.89, 9090});
  c.insert({276.89, 9090});
  a.insert({8.88, 555});
  c.insert({8.88, 555});
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodInsert, TestMapMethodInsert5) {
  s21::map<char, int> a{{'c', 1}, {'a', 3}};
  std::map<char, int> c{{'c', 1}, {'a', 3}};
  a.insert({'w', 4});
  c.insert({'w', 4});
  a.insert({'g', 88});
  c.insert({'g', 88});
  a.insert({'x', 23});
  c.insert({'x', 23});
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodInsert, TestMapMethodInsert6) {
  s21::map<char, int> a{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  std::map<char, int> c{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  a.insert({'g', 88});
  c.insert({'g', 88});
  a.insert({'q', 23});
  c.insert({'q', 23});
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodInsert, TestMapMethodInsert7) {
  s21::map<std::string, int> a{{"kak", 1}, {"adad", 3}};
  std::map<std::string, int> c{{"kak", 1}, {"adad", 3}};
  a.insert({"vnms", 4});
  c.insert({"vnms", 4});
  a.insert({"qwerty", 13});
  c.insert({"qwerty", 13});
  a.insert({"zxcvb", 456});
  c.insert({"zxcvb", 456});
  a.insert({"vvs", 128});
  c.insert({"vvs", 128});
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodInsert, TestMapMethodInsert8) {
  s21::map<std::string, int> a{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  std::map<std::string, int> c{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  a.insert({"vnms", 4});
  c.insert({"vnms", 4});
  a.insert({"qwerty", 13});
  c.insert({"qwerty", 13});
  a.insert({"zxcvb", 456});
  c.insert({"zxcvb", 456});
  a.insert({"vvs", 128});
  c.insert({"vvs", 128});
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodInsert, TestMapMethodInsert9) {
  s21::map<std::string, char> a{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  std::map<std::string, char> c{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  a.insert({"vnms", 'j'});
  c.insert({"vnms", 'j'});
  a.insert({"qwerty", 'y'});
  c.insert({"qwerty", 'y'});
  a.insert({"zxcvb", 'u'});
  c.insert({"zxcvb", 'u'});
  a.insert({"vvs", 'l'});
  c.insert({"vvs", 'l'});
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodInsert, TestMapMethodInsert10) {
  s21::map<double, std::string> a{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  std::map<double, std::string> c{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  a.insert({334.56, "vnms"});
  c.insert({334.56, "vnms"});
  a.insert({982.56, "qwerty"});
  c.insert({982.56, "qwerty"});
  a.insert({753.234, "zxcvb"});
  c.insert({753.234, "zxcvb"});
  a.insert({5778.89, "vvs"});
  c.insert({5778.89, "vvs"});
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}

TEST(TestMapMethodErase, TestMapMethodErase1) {
  s21::map<int, int> a{{2, 1}, {4, 3}};
  std::map<int, int> c{{2, 1}, {4, 3}};
  a.insert({5, 1});
  c.insert({5, 1});
  a.erase(a.begin());
  c.erase(c.begin());
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodErase, TestMapMethodErase2) {
  s21::map<int, int> a{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  std::map<int, int> c{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  a.erase(a.begin());
  c.erase(c.begin());

  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodErase, TestMapMethodErase3) {
  s21::map<double, int> a{{2.1, 1}, {4.2, 3}};
  std::map<double, int> c{{2.1, 1}, {4.2, 3}};
  a.erase(a.begin());
  c.erase(c.begin());
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodErase, TestMapMethodErase4) {
  s21::map<double, int> a{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  std::map<double, int> c{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  a.erase(a.begin());
  c.erase(c.begin());
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodErase, TestMapMethodErase5) {
  s21::map<char, int> a{{'c', 1}, {'a', 3}};
  std::map<char, int> c{{'c', 1}, {'a', 3}};
  a.erase(a.begin());
  c.erase(c.begin());
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodErase, TestMapMethodErase6) {
  s21::map<char, int> a{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  std::map<char, int> c{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  a.erase(a.begin());
  c.erase(c.begin());
  a.erase(++a.begin());
  c.erase(++c.begin());
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodErase, TestMapMethodErase7) {
  s21::map<std::string, int> a{{"kak", 1}, {"adad", 3}};
  std::map<std::string, int> c{{"kak", 1}, {"adad", 3}};
  a.erase(a.begin());
  c.erase(c.begin());
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodErase, TestMapMethodErase8) {
  s21::map<std::string, int> a{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  std::map<std::string, int> c{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  a.erase(a.begin());
  c.erase(c.begin());
  a.erase(++a.begin());
  c.erase(++c.begin());
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodErase, TestMapMethodErase9) {
  s21::map<std::string, char> a{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  std::map<std::string, char> c{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  a.erase(a.begin());
  c.erase(c.begin());
  a.erase(++a.begin());
  c.erase(++c.begin());
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodErase, TestMapMethodErase10) {
  s21::map<double, std::string> a{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  std::map<double, std::string> c{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  a.erase(a.begin());
  c.erase(c.begin());
  a.erase(++a.begin());
  c.erase(++c.begin());
  auto iter1 = a.begin();
  for (auto i : c) {
    ASSERT_EQ((*iter1).second, i.second);
    ASSERT_EQ((*iter1).first, i.first);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}

TEST(TestMapMethodSwap, TestMapMethodSwap1) {
  s21::map<int, int> a{{2, 1}, {4, 3}};
  s21::map<int, int> b{{1, 3}, {5, 8}};
  std::map<int, int> c{{2, 1}, {4, 3}};
  std::map<int, int> d{{1, 3}, {5, 8}};
  a.swap(b);
  c.swap(d);
  auto iter1 = a.begin();
  for (auto i1 : c) {
    ASSERT_EQ((*iter1).second, i1.second);
    ++iter1;
  }
  auto iter2 = b.begin();
  for (auto i2 : d) {
    ASSERT_EQ((*iter2).second, i2.second);
    ++iter2;
  }

  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapMethodSwap, TestMapMethodSwap2) {
  s21::map<int, int> a{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  s21::map<int, int> b{{1, 3}, {5, 8}};
  std::map<int, int> d{{1, 3}, {5, 8}};
  std::map<int, int> c{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  a.swap(b);
  c.swap(d);
  auto iter1 = a.begin();
  for (auto i1 : c) {
    ASSERT_EQ((*iter1).second, i1.second);
    ++iter1;
  }
  auto iter2 = b.begin();
  for (auto i2 : d) {
    ASSERT_EQ((*iter2).second, i2.second);
    ++iter2;
  }

  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapMethodSwap, TestMapMethodSwap3) {
  s21::map<double, int> a{{2.1, 1}, {4.2, 3}};
  std::map<double, int> c{{2.1, 1}, {4.2, 3}};
  s21::map<double, int> b{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  std::map<double, int> d{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  a.swap(b);
  c.swap(d);
  auto iter1 = a.begin();
  for (auto i1 : c) {
    ASSERT_EQ((*iter1).second, i1.second);
    ++iter1;
  }
  auto iter2 = b.begin();
  for (auto i2 : d) {
    ASSERT_EQ((*iter2).second, i2.second);
    ++iter2;
  }

  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(b.size(), d.size());
}

TEST(TestMapMethodSwap, TestMapMethodSwap4) {
  s21::map<char, int> a{{'c', 1}, {'a', 3}};
  std::map<char, int> c{{'c', 1}, {'a', 3}};
  s21::map<char, int> b{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  std::map<char, int> d{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  a.swap(b);
  c.swap(d);
  auto iter1 = a.begin();
  for (auto i1 : c) {
    ASSERT_EQ((*iter1).second, i1.second);
    ++iter1;
  }
  auto iter2 = b.begin();
  for (auto i2 : d) {
    ASSERT_EQ((*iter2).second, i2.second);
    ++iter2;
  }

  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(b.size(), d.size());
}

TEST(TestMapMethodSwap, TestMapMethodSwap5) {
  s21::map<std::string, int> a{{"kak", 1}, {"adad", 3}};
  std::map<std::string, int> c{{"kak", 1}, {"adad", 3}};
  s21::map<std::string, int> b{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  std::map<std::string, int> d{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  a.swap(b);
  c.swap(d);
  auto iter1 = a.begin();
  for (auto i1 : c) {
    ASSERT_EQ((*iter1).second, i1.second);
    ++iter1;
  }
  auto iter2 = b.begin();
  for (auto i2 : d) {
    ASSERT_EQ((*iter2).second, i2.second);
    ++iter2;
  }

  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(b.size(), d.size());
}

TEST(TestMapMethodSwap, TestMapMethodSwap6) {
  s21::map<std::string, char> a{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  s21::map<std::string, char> b{{"vvs", 's'}, {"wwww", 'w'}};
  std::map<std::string, char> d{{"vvs", 's'}, {"wwww", 'w'}};
  std::map<std::string, char> c{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  a.swap(b);
  c.swap(d);
  auto iter1 = a.begin();
  for (auto i1 : c) {
    ASSERT_EQ((*iter1).second, i1.second);
    ++iter1;
  }
  auto iter2 = b.begin();
  for (auto i2 : d) {
    ASSERT_EQ((*iter2).second, i2.second);
    ++iter2;
  }

  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(b.size(), d.size());
}
TEST(TestMapMethodSwap, TestMapMethodSwap7) {
  s21::map<double, std::string> a{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  s21::map<double, std::string> b{{345.56, "qqqw"}, {228.337, "abs"}};
  std::map<double, std::string> d{{345.56, "qqqw"}, {228.337, "abs"}};
  std::map<double, std::string> c{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  a.swap(b);
  c.swap(d);
  auto iter1 = a.begin();
  for (auto i1 : c) {
    ASSERT_EQ((*iter1).second, i1.second);
    ++iter1;
  }
  auto iter2 = b.begin();
  for (auto i2 : d) {
    ASSERT_EQ((*iter2).second, i2.second);
    ++iter2;
  }

  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(b.size(), d.size());
}

TEST(TestMapMethodMerge, TestMapMethodMerge1) {
  s21::map<int, int> a{{2, 1}, {4, 3}};
  s21::map<int, int> b{{1, 3}, {5, 8}};
  std::map<int, int> c{{2, 1}, {4, 3}};
  std::map<int, int> d{{1, 3}, {5, 8}};
  a.merge(b);
  c.merge(d);
  auto iter1 = a.begin();
  for (auto i1 : c) {
    ASSERT_EQ((*iter1).second, i1.second);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}
TEST(TestMapMethodMerge, TestMapMethodMerge2) {
  s21::map<int, int> a{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  s21::map<int, int> b{{1, 3}, {5, 8}};
  std::map<int, int> d{{1, 3}, {5, 8}};
  std::map<int, int> c{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  a.merge(b);
  c.merge(d);
  auto iter1 = a.begin();
  for (auto i1 : c) {
    ASSERT_EQ((*iter1).second, i1.second);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}

TEST(TestMapMethodMerge, TestMapMethodMerge3) {
  s21::map<std::string, int> a{{"kak", 1}, {"adad", 3}};
  std::map<std::string, int> c{{"kak", 1}, {"adad", 3}};
  s21::map<std::string, int> b{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  std::map<std::string, int> d{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  a.merge(b);
  c.merge(d);
  auto iter1 = a.begin();
  for (auto i1 : c) {
    ASSERT_EQ((*iter1).second, i1.second);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}

TEST(TestMapMethodMerge, TestMapMethodMerge4) {
  s21::map<std::string, char> a{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  s21::map<std::string, char> b{{"vvs", 's'}, {"wwww", 'w'}};
  std::map<std::string, char> d{{"vvs", 's'}, {"wwww", 'w'}};
  std::map<std::string, char> c{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  a.merge(b);
  c.merge(d);
  auto iter1 = a.begin();
  for (auto i1 : c) {
    ASSERT_EQ((*iter1).second, i1.second);
    ++iter1;
  }
  ASSERT_EQ(a.size(), c.size());
}

TEST(TestMapMethodContains, TestMapMethodContains1) {
  s21::map<int, int> a{{2, 1}, {4, 3}};
  ASSERT_EQ(a.contains(2), true);
  ASSERT_EQ(a.contains(4), true);
}
TEST(TestMapMethodContains, TestMapMethodContains2) {
  s21::map<int, int> a{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  ASSERT_EQ(a.contains(200), true);
  ASSERT_EQ(a.contains(4), true);
  ASSERT_EQ(a.contains(11), true);
  ASSERT_EQ(a.contains(7), true);
}
TEST(TestMapMethodContains, TestMapMethodContains3) {
  s21::map<double, int> a{{2.1, 1}, {4.2, 3}};
  ASSERT_EQ(a.contains(2.1), true);
  ASSERT_EQ(a.contains(4.2), true);
}
TEST(TestMapMethodContains, TestMapMethodContains4) {
  s21::map<double, int> a{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  ASSERT_EQ(a.contains(2.1), true);
  ASSERT_EQ(a.contains(4.2), true);
  ASSERT_EQ(a.contains(23.4), true);
  ASSERT_EQ(a.contains(77.77), true);
}
TEST(TestMapMethodContains, TestMapMethodContains5) {
  s21::map<char, int> a{{'c', 1}, {'a', 3}};
  std::map<char, int> c{{'c', 1}, {'a', 3}};
  ASSERT_EQ(a.contains('a'), true);
  ASSERT_EQ(a.contains('c'), true);
}
TEST(TestMapMethodContains, TestMapMethodContains6) {
  s21::map<char, int> a{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  ASSERT_EQ(a.contains('a'), true);
  ASSERT_EQ(a.contains('c'), true);
  ASSERT_EQ(a.contains('d'), true);
  ASSERT_EQ(a.contains('k'), true);
  ASSERT_EQ(a.contains('e'), true);
  ASSERT_EQ(a.contains('v'), true);
}
TEST(TestMapMethodContains, TestMapMethodContains7) {
  s21::map<std::string, int> a{{"kak", 1}, {"adad", 3}};
  ASSERT_EQ(a.contains("kak"), true);
  ASSERT_EQ(a.contains("adad"), true);
}
TEST(TestMapMethodContains, TestMapMethodContains8) {
  s21::map<std::string, int> a{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  ASSERT_EQ(a.contains("cnad"), true);
  ASSERT_EQ(a.contains("anfr"), true);
  ASSERT_EQ(a.contains("bada"), true);
  ASSERT_EQ(a.contains("dovi"), true);
  ASSERT_EQ(a.contains("eyeg"), true);
  ASSERT_EQ(a.contains("vdeidioe"), true);
}
TEST(TestMapMethodContains, TestMapMethodContains9) {
  s21::map<std::string, char> a{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  ASSERT_EQ(a.contains("cnad"), true);
  ASSERT_EQ(a.contains("anfr"), true);
  ASSERT_EQ(a.contains("bada"), true);
  ASSERT_EQ(a.contains("dovi"), true);
  ASSERT_EQ(a.contains("eyeg"), true);
  ASSERT_EQ(a.contains("vdeidioe"), true);
}
TEST(TestMapMethodContains, TestMapMethodContains10) {
  s21::map<double, std::string> a{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  ASSERT_EQ(a.contains(201.72), true);
  ASSERT_EQ(a.contains(172.89), true);
  ASSERT_EQ(a.contains(234.67), true);
}

TEST(TestMapMethodFind, TestMapMethodFind1) {
  s21::map<int, int> a{{2, 1}, {4, 3}};
  auto iter = a.find(2);
  ASSERT_EQ((*iter).second, 1);
}
TEST(TestMapMethodFind, TestMapMethodFind2) {
  s21::map<int, int> a{{200, 33}, {2, 1},  {4, 3},   {33, 15}, {3, 5},
                       {7, 8},    {9, 10}, {11, 24}, {100, 50}};
  auto iter1 = a.find(2);
  auto iter2 = a.find(200);
  ASSERT_EQ((*iter2).second, 33);
  ASSERT_EQ((*iter1).second, 1);
  ++iter1;
  ASSERT_EQ((*iter1).second, 5);
  auto iter3 = a.find(7);
  ASSERT_EQ((*iter3).second, 8);
}
TEST(TestMapMethodFind, TestMapMethodFind3) {
  s21::map<double, int> a{{2.1, 1}, {4.2, 3}};
  auto iter1 = a.find(2.1);
  auto iter2 = a.find(4.2);
  ASSERT_EQ((*iter1).second, 1);
  ASSERT_EQ((*iter2).second, 3);
}
TEST(TestMapMethodFind, TestMapMethodFind4) {
  s21::map<double, int> a{{999.9, 129}, {2.1, 1},    {4.2, 3},
                          {23.4, 8},    {12.5, 7},   {17.8, 12},
                          {1.2, 44},    {77.77, 77}, {5.22, 123}};
  auto iter1 = a.find(2.1);
  auto iter2 = a.find(4.2);
  ASSERT_EQ((*iter1).second, 1);
  ASSERT_EQ((*iter2).second, 3);
  auto iter3 = a.find(23.4);
  auto iter4 = a.find(12.5);
  ASSERT_EQ((*iter3).second, 8);
  ASSERT_EQ((*iter4).second, 7);
}
TEST(TestMapMethodFind, TestMapMethodFind5) {
  s21::map<char, int> a{{'c', 1}, {'a', 3}};
  auto iter1 = a.find('c');
  auto iter2 = a.find('a');
  ASSERT_EQ((*iter1).second, 1);
  ASSERT_EQ((*iter2).second, 3);
}
TEST(TestMapMethodFind, TestMapMethodFind6) {
  s21::map<char, int> a{{'c', 1},  {'a', 3},  {'b', 2},   {'d', 7},
                        {'k', 22}, {'e', 4},  {'v', 228}, {'w', 337},
                        {'z', 12}, {'x', 398}};
  auto iter1 = a.find('c');
  auto iter2 = a.find('a');
  ASSERT_EQ((*iter1).second, 1);
  ASSERT_EQ((*iter2).second, 3);
  auto iter3 = a.find('k');
  auto iter4 = a.find('e');
  ASSERT_EQ((*iter3).second, 22);
  ASSERT_EQ((*iter4).second, 4);
}
TEST(TestMapMethodFind, TestMapMethodFind7) {
  s21::map<std::string, int> a{{"kak", 1}, {"adad", 3}};
  auto iter1 = a.find("kak");
  auto iter2 = a.find("adad");
  ASSERT_EQ((*iter1).second, 1);
  ASSERT_EQ((*iter2).second, 3);
}
TEST(TestMapMethodFind, TestMapMethodFind8) {
  s21::map<std::string, int> a{{"cnad", 1},       {"anfr", 3},
                               {"bada", 2},       {"dovi", 7},
                               {"kdad", 22},      {"eyeg", 4},
                               {"vdeidioe", 228}, {"wdkekemd", 337},
                               {"znandjaod", 12}, {"xdkakdmamd", 398}};
  auto iter1 = a.find("cnad");
  auto iter2 = a.find("anfr");
  ASSERT_EQ((*iter1).second, 1);
  ASSERT_EQ((*iter2).second, 3);
  auto iter3 = a.find("dovi");
  auto iter4 = a.find("kdad");
  ASSERT_EQ((*iter3).second, 7);
  ASSERT_EQ((*iter4).second, 22);
}
TEST(TestMapMethodFind, TestMapMethodFind9) {
  s21::map<std::string, char> a{{"cnad", 'b'},      {"anfr", 'c'},
                                {"bada", 'w'},      {"dovi", 'a'},
                                {"kdad", 'd'},      {"eyeg", 'v'},
                                {"vdeidioe", 'q'},  {"wdkekemd", 'z'},
                                {"znandjaod", 'o'}, {"xdkakdmamd", 'i'}};
  auto iter1 = a.find("cnad");
  auto iter2 = a.find("anfr");
  ASSERT_EQ((*iter1).second, 'b');
  ASSERT_EQ((*iter2).second, 'c');
  auto iter3 = a.find("dovi");
  auto iter4 = a.find("kdad");
  ASSERT_EQ((*iter3).second, 'a');
  ASSERT_EQ((*iter4).second, 'd');
}
TEST(TestMapMethodFind, TestMapMethodFind10) {
  s21::map<double, std::string> a{{201.72, "cnad"},    {172.89, "anfr"},
                                  {234.67, "bada"},    {228.337, "dovi"},
                                  {12.34, "kdad"},     {1.23, "eyeg"},
                                  {2.228, "vdeidioe"}, {451.22, "wdkekemd"},
                                  {7.77, "znandjaod"}, {5.45, "xdkakdmamd"}};
  auto iter1 = a.find(201.72);
  auto iter2 = a.find(172.89);
  ASSERT_EQ((*iter1).second, "cnad");
  ASSERT_EQ((*iter2).second, "anfr");
  auto iter3 = a.find(234.67);
  auto iter4 = a.find(228.337);
  ASSERT_EQ((*iter3).second, "bada");
  ASSERT_EQ((*iter4).second, "dovi");
}

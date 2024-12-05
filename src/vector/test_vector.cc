#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "s21_vector.h"

TEST(TestVectorConstruct, TestVectorConstructEmpty1) {
  s21::vector<int> a;
  std::vector<int> b;
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestVectorConstruct, TestVectorConstructEmpty2) {
  s21::vector<double> a;
  std::vector<double> b;
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestVectorConstruct, TestVectorConstructEmpty3) {
  s21::vector<char> a;
  std::vector<char> b;
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestVectorConstruct, TestVectorConstructEmpty4) {
  s21::vector<std::string> a;
  std::vector<std::string> b;
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestVectorConstruct, TestVectorConstructNum1) {
  s21::vector<int> a(10);
  std::vector<int> b(10);
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestVectorConstruct, TestVectorConstructNum2) {
  s21::vector<double> a(10);
  std::vector<double> b(10);
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestVectorConstruct, TestVectorConstructNum3) {
  s21::vector<char> a(10);
  std::vector<char> b(10);
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestVectorConstruct, TestVectorConstructNum4) {
  s21::vector<std::string> a(10);
  std::vector<std::string> b(10);
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestVectorConstruct, TestVectorConstructInit1) {
  s21::vector<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_EQ(b[0], a[0]);
  ASSERT_EQ(b[1], a[1]);
  ASSERT_EQ(b[2], a[2]);
  ASSERT_EQ(b[3], a[3]);
  ASSERT_EQ(b[4], a[4]);
  ASSERT_EQ(b[5], a[5]);
  ASSERT_EQ(b[6], a[6]);
  ASSERT_EQ(b[7], a[7]);
  ASSERT_EQ(b[8], a[8]);
  ASSERT_EQ(b[9], a[9]);

  ASSERT_EQ(b.size(), a.size());
}
TEST(TestVectorConstruct, TestVectorConstructInit2) {
  s21::vector<double> b{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};
  std::vector<double> a{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};
  ASSERT_EQ(b[0], a[0]);
  ASSERT_EQ(b[1], a[1]);
  ASSERT_EQ(b[2], a[2]);
  ASSERT_EQ(b[3], a[3]);
  ASSERT_EQ(b[4], a[4]);
  ASSERT_EQ(b[5], a[5]);
  ASSERT_EQ(b[6], a[6]);
  ASSERT_EQ(b[7], a[7]);
  ASSERT_EQ(b[8], a[8]);
  ASSERT_EQ(b[9], a[9]);

  ASSERT_EQ(b.size(), a.size());
}
TEST(TestVectorConstruct, TestVectorConstructInit3) {
  s21::vector<char> b{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  std::vector<char> a{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  ASSERT_EQ(b[0], a[0]);
  ASSERT_EQ(b[1], a[1]);
  ASSERT_EQ(b[2], a[2]);
  ASSERT_EQ(b[3], a[3]);
  ASSERT_EQ(b[4], a[4]);
  ASSERT_EQ(b[5], a[5]);
  ASSERT_EQ(b[6], a[6]);
  ASSERT_EQ(b[7], a[7]);
  ASSERT_EQ(b[8], a[8]);
  ASSERT_EQ(b[9], a[9]);

  ASSERT_EQ(b.size(), a.size());
}
TEST(TestVectorConstruct, TestVectorConstructInit4) {
  s21::vector<std::string> b{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};
  std::vector<std::string> a{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};
  ASSERT_EQ(b[0], a[0]);
  ASSERT_EQ(b[1], a[1]);
  ASSERT_EQ(b[2], a[2]);
  ASSERT_EQ(b[3], a[3]);
  ASSERT_EQ(b[4], a[4]);
  ASSERT_EQ(b[5], a[5]);
  ASSERT_EQ(b[6], a[6]);
  ASSERT_EQ(b[7], a[7]);
  ASSERT_EQ(b[8], a[8]);
  ASSERT_EQ(b[9], a[9]);

  ASSERT_EQ(b.size(), a.size());
}

TEST(TestVectorConstruct, TestVectorConstructCop1) {
  s21::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::vector<int> b(a);
  ASSERT_EQ(b[0], a[0]);
  ASSERT_EQ(b[1], a[1]);
  ASSERT_EQ(b[2], a[2]);
  ASSERT_EQ(b[3], a[3]);
  ASSERT_EQ(b[4], a[4]);
  ASSERT_EQ(b[5], a[5]);
  ASSERT_EQ(b[6], a[6]);
  ASSERT_EQ(b[7], a[7]);
  ASSERT_EQ(b[8], a[8]);
  ASSERT_EQ(b[9], a[9]);

  ASSERT_EQ(a.size(), b.size());
}
TEST(TestVectorConstruct, TestVectorConstructCop2) {
  s21::vector<double> a{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};
  s21::vector<double> b(a);
  ASSERT_EQ(b[0], a[0]);
  ASSERT_EQ(b[1], a[1]);
  ASSERT_EQ(b[2], a[2]);
  ASSERT_EQ(b[3], a[3]);
  ASSERT_EQ(b[4], a[4]);
  ASSERT_EQ(b[5], a[5]);
  ASSERT_EQ(b[6], a[6]);
  ASSERT_EQ(b[7], a[7]);
  ASSERT_EQ(b[8], a[8]);
  ASSERT_EQ(b[9], a[9]);

  ASSERT_EQ(a.size(), b.size());
}
TEST(TestVectorConstruct, TestVectorConstructCopy3) {
  s21::vector<char> a{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  s21::vector<char> b(a);
  ASSERT_EQ(b[0], a[0]);
  ASSERT_EQ(b[1], a[1]);
  ASSERT_EQ(b[2], a[2]);
  ASSERT_EQ(b[3], a[3]);
  ASSERT_EQ(b[4], a[4]);
  ASSERT_EQ(b[5], a[5]);
  ASSERT_EQ(b[6], a[6]);
  ASSERT_EQ(b[7], a[7]);
  ASSERT_EQ(b[8], a[8]);
  ASSERT_EQ(b[9], a[9]);

  ASSERT_EQ(a.size(), b.size());
}
TEST(TestVectorConstruct, TestVectorConstructCopy4) {
  s21::vector<std::string> a{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};
  s21::vector<std::string> b(a);
  ASSERT_EQ(b[0], a[0]);
  ASSERT_EQ(b[1], a[1]);
  ASSERT_EQ(b[2], a[2]);
  ASSERT_EQ(b[3], a[3]);
  ASSERT_EQ(b[4], a[4]);
  ASSERT_EQ(b[5], a[5]);
  ASSERT_EQ(b[6], a[6]);
  ASSERT_EQ(b[7], a[7]);
  ASSERT_EQ(b[8], a[8]);
  ASSERT_EQ(b[9], a[9]);

  ASSERT_EQ(a.size(), b.size());
}

TEST(TestVectorConstruct, TestVectorConstructMove1) {
  s21::vector<int> a_s21{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::vector<int> b_s21(std::move(a_s21));
  std::vector<int> a_std{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> b_std(std::move(a_std));

  ASSERT_EQ(b_std[0], b_s21[0]);
  ASSERT_EQ(b_std[1], b_s21[1]);
  ASSERT_EQ(b_std[2], b_s21[2]);
  ASSERT_EQ(b_std[3], b_s21[3]);
  ASSERT_EQ(b_std[4], b_s21[4]);
  ASSERT_EQ(b_std[5], b_s21[5]);
  ASSERT_EQ(b_std[6], b_s21[6]);
  ASSERT_EQ(b_std[7], b_s21[7]);
  ASSERT_EQ(b_std[8], b_s21[8]);
  ASSERT_EQ(b_std[9], b_s21[9]);

  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}
TEST(TestVectorConstruct, TestVectorConstructMove2) {
  s21::vector<double> a_s21{11.2, 21.5, 3.54, 4.1,  5.76,
                            64.3, 7.01, 82.1, 9.99, 10.0};
  s21::vector<double> b_s21(std::move(a_s21));
  std::vector<double> a_std{11.2, 21.5, 3.54, 4.1,  5.76,
                            64.3, 7.01, 82.1, 9.99, 10.0};
  std::vector<double> b_std(std::move(a_std));

  ASSERT_EQ(b_std[0], b_s21[0]);
  ASSERT_EQ(b_std[1], b_s21[1]);
  ASSERT_EQ(b_std[2], b_s21[2]);
  ASSERT_EQ(b_std[3], b_s21[3]);
  ASSERT_EQ(b_std[4], b_s21[4]);
  ASSERT_EQ(b_std[5], b_s21[5]);
  ASSERT_EQ(b_std[6], b_s21[6]);
  ASSERT_EQ(b_std[7], b_s21[7]);
  ASSERT_EQ(b_std[8], b_s21[8]);
  ASSERT_EQ(b_std[9], b_s21[9]);

  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}
TEST(TestVectorConstruct, TestVectorConstructMove3) {
  s21::vector<char> a_s21{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  s21::vector<char> b_s21(std::move(a_s21));
  std::vector<char> a_std{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  std::vector<char> b_std(std::move(a_std));

  ASSERT_EQ(b_std[0], b_s21[0]);
  ASSERT_EQ(b_std[1], b_s21[1]);
  ASSERT_EQ(b_std[2], b_s21[2]);
  ASSERT_EQ(b_std[3], b_s21[3]);
  ASSERT_EQ(b_std[4], b_s21[4]);
  ASSERT_EQ(b_std[5], b_s21[5]);
  ASSERT_EQ(b_std[6], b_s21[6]);
  ASSERT_EQ(b_std[7], b_s21[7]);
  ASSERT_EQ(b_std[8], b_s21[8]);
  ASSERT_EQ(b_std[9], b_s21[9]);

  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}
TEST(TestVectorConstruct, TestVectorConstructMove4) {
  s21::vector<std::string> a_s21{"wish",      "ggwp",     "nope",    "apple",
                                 "crocodile", "elephant", "running", "blame",
                                 "workspace", "moscow"};
  s21::vector<std::string> b_s21(std::move(a_s21));
  std::vector<std::string> a_std{"wish",      "ggwp",     "nope",    "apple",
                                 "crocodile", "elephant", "running", "blame",
                                 "workspace", "moscow"};
  std::vector<std::string> b_std(std::move(a_std));

  ASSERT_EQ(b_std[0], b_s21[0]);
  ASSERT_EQ(b_std[1], b_s21[1]);
  ASSERT_EQ(b_std[2], b_s21[2]);
  ASSERT_EQ(b_std[3], b_s21[3]);
  ASSERT_EQ(b_std[4], b_s21[4]);
  ASSERT_EQ(b_std[5], b_s21[5]);
  ASSERT_EQ(b_std[6], b_s21[6]);
  ASSERT_EQ(b_std[7], b_s21[7]);
  ASSERT_EQ(b_std[8], b_s21[8]);
  ASSERT_EQ(b_std[9], b_s21[9]);

  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}

TEST(TestVectorOperatorMove, TestVectorOperatorMove1) {
  s21::vector<int> a_s21{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::vector<int> b_s21;
  b_s21 = std::move(a_s21);
  std::vector<int> a_std{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> b_std;
  b_std = std::move(a_std);

  ASSERT_EQ(b_std[0], b_s21[0]);
  ASSERT_EQ(b_std[1], b_s21[1]);
  ASSERT_EQ(b_std[2], b_s21[2]);
  ASSERT_EQ(b_std[3], b_s21[3]);
  ASSERT_EQ(b_std[4], b_s21[4]);
  ASSERT_EQ(b_std[5], b_s21[5]);
  ASSERT_EQ(b_std[6], b_s21[6]);
  ASSERT_EQ(b_std[7], b_s21[7]);
  ASSERT_EQ(b_std[8], b_s21[8]);
  ASSERT_EQ(b_std[9], b_s21[9]);

  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}
TEST(TestVectorOperatorMove, TestVectorOperatorMove2) {
  s21::vector<double> a_s21{11.2, 21.5, 3.54, 4.1,  5.76,
                            64.3, 7.01, 82.1, 9.99, 10.0};
  s21::vector<double> b_s21;
  b_s21 = std::move(a_s21);
  std::vector<double> a_std{11.2, 21.5, 3.54, 4.1,  5.76,
                            64.3, 7.01, 82.1, 9.99, 10.0};
  std::vector<double> b_std;
  b_std = std::move(a_std);

  ASSERT_EQ(b_std[0], b_s21[0]);
  ASSERT_EQ(b_std[1], b_s21[1]);
  ASSERT_EQ(b_std[2], b_s21[2]);
  ASSERT_EQ(b_std[3], b_s21[3]);
  ASSERT_EQ(b_std[4], b_s21[4]);
  ASSERT_EQ(b_std[5], b_s21[5]);
  ASSERT_EQ(b_std[6], b_s21[6]);
  ASSERT_EQ(b_std[7], b_s21[7]);
  ASSERT_EQ(b_std[8], b_s21[8]);
  ASSERT_EQ(b_std[9], b_s21[9]);

  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}
TEST(TestVectorOperatorMove, TestVectorOperatorMove3) {
  s21::vector<char> a_s21{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  s21::vector<char> b_s21;
  b_s21 = std::move(a_s21);
  std::vector<char> a_std{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  std::vector<char> b_std;
  b_std = std::move(a_std);

  ASSERT_EQ(b_std[0], b_s21[0]);
  ASSERT_EQ(b_std[1], b_s21[1]);
  ASSERT_EQ(b_std[2], b_s21[2]);
  ASSERT_EQ(b_std[3], b_s21[3]);
  ASSERT_EQ(b_std[4], b_s21[4]);
  ASSERT_EQ(b_std[5], b_s21[5]);
  ASSERT_EQ(b_std[6], b_s21[6]);
  ASSERT_EQ(b_std[7], b_s21[7]);
  ASSERT_EQ(b_std[8], b_s21[8]);
  ASSERT_EQ(b_std[9], b_s21[9]);

  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}
TEST(TestVectorOperatorMove, TestVectorOperatorMove4) {
  s21::vector<std::string> a_s21{"wish",      "ggwp",     "nope",    "apple",
                                 "crocodile", "elephant", "running", "blame",
                                 "workspace", "moscow"};
  s21::vector<std::string> b_s21;
  b_s21 = std::move(a_s21);
  std::vector<std::string> a_std{"wish",      "ggwp",     "nope",    "apple",
                                 "crocodile", "elephant", "running", "blame",
                                 "workspace", "moscow"};
  std::vector<std::string> b_std;
  b_std = std::move(a_std);

  ASSERT_EQ(b_std[0], b_s21[0]);
  ASSERT_EQ(b_std[1], b_s21[1]);
  ASSERT_EQ(b_std[2], b_s21[2]);
  ASSERT_EQ(b_std[3], b_s21[3]);
  ASSERT_EQ(b_std[4], b_s21[4]);
  ASSERT_EQ(b_std[5], b_s21[5]);
  ASSERT_EQ(b_std[6], b_s21[6]);
  ASSERT_EQ(b_std[7], b_s21[7]);
  ASSERT_EQ(b_std[8], b_s21[8]);
  ASSERT_EQ(b_std[9], b_s21[9]);

  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}

TEST(TestVectorOperatorMove, TestVectorOperatorMove5) {
  s21::vector<int> a_s21{1};
  s21::vector<int> b_s21;
  b_s21 = std::move(a_s21);
  std::vector<int> a_std{1};
  std::vector<int> b_std;
  b_std = std::move(a_std);

  ASSERT_EQ(b_std[0], b_s21[0]);

  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}
TEST(TestVectorOperatorMove, TestVectorOperatorMove6) {
  s21::vector<double> a_s21{11.34};
  s21::vector<double> b_s21;
  b_s21 = std::move(a_s21);
  std::vector<double> a_std{11.34};
  std::vector<double> b_std;
  b_std = std::move(a_std);

  ASSERT_EQ(b_std[0], b_s21[0]);

  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}
TEST(TestVectorOperatorMove, TestVectorOperatorMove7) {
  s21::vector<char> a_s21{'G'};
  s21::vector<char> b_s21;
  b_s21 = std::move(a_s21);
  std::vector<char> a_std{'G'};
  std::vector<char> b_std;
  b_std = std::move(a_std);

  ASSERT_EQ(b_std[0], b_s21[0]);

  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}
TEST(TestVectorOperatorMove, TestVectorOperatorMove8) {
  s21::vector<std::string> a_s21{"Apple"};
  s21::vector<std::string> b_s21;
  b_s21 = std::move(a_s21);
  std::vector<std::string> a_std{"Apple"};
  std::vector<std::string> b_std;
  b_std = std::move(a_std);

  ASSERT_EQ(b_std[0], b_s21[0]);

  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}

TEST(TestVectorSwap, TestVectorSwap1) {
  s21::vector<int> a_s21{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::vector<int> b_s21{13, 14, 15};
  a_s21.swap(b_s21);
  std::vector<int> a_std{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> b_std{13, 14, 15};
  a_std.swap(b_std);

  ASSERT_EQ(a_std[0], a_s21[0]);
  ASSERT_EQ(a_std[1], a_s21[1]);
  ASSERT_EQ(a_std[2], a_s21[2]);

  ASSERT_EQ(b_std[0], b_s21[0]);
  ASSERT_EQ(b_std[1], b_s21[1]);
  ASSERT_EQ(b_std[2], b_s21[2]);
  ASSERT_EQ(b_std[3], b_s21[3]);
  ASSERT_EQ(b_std[4], b_s21[4]);
  ASSERT_EQ(b_std[5], b_s21[5]);
  ASSERT_EQ(b_std[6], b_s21[6]);
  ASSERT_EQ(b_std[7], b_s21[7]);
  ASSERT_EQ(b_std[8], b_s21[8]);
  ASSERT_EQ(b_std[9], b_s21[9]);

  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}
TEST(TestVectorSwap, TestVectorSwap2) {
  s21::vector<double> a_s21{11.2, 21.5, 3.54, 4.1,  5.76,
                            64.3, 7.01, 82.1, 9.99, 10.0};
  s21::vector<double> b_s21{13.34, 1.23, 5.44};
  a_s21.swap(b_s21);
  std::vector<double> a_std{11.2, 21.5, 3.54, 4.1,  5.76,
                            64.3, 7.01, 82.1, 9.99, 10.0};
  std::vector<double> b_std{13.34, 1.23, 5.44};
  a_std.swap(b_std);

  ASSERT_EQ(a_std[0], a_s21[0]);
  ASSERT_EQ(a_std[1], a_s21[1]);
  ASSERT_EQ(a_std[2], a_s21[2]);

  ASSERT_EQ(b_std[0], b_s21[0]);
  ASSERT_EQ(b_std[1], b_s21[1]);
  ASSERT_EQ(b_std[2], b_s21[2]);
  ASSERT_EQ(b_std[3], b_s21[3]);
  ASSERT_EQ(b_std[4], b_s21[4]);
  ASSERT_EQ(b_std[5], b_s21[5]);
  ASSERT_EQ(b_std[6], b_s21[6]);
  ASSERT_EQ(b_std[7], b_s21[7]);
  ASSERT_EQ(b_std[8], b_s21[8]);
  ASSERT_EQ(b_std[9], b_s21[9]);

  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}
TEST(TestVectorSwap, TestVectorSwap3) {
  s21::vector<char> a_s21{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  s21::vector<char> b_s21{'v', 'v', 's'};
  a_s21.swap(b_s21);
  std::vector<char> a_std{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  std::vector<char> b_std{'v', 'v', 's'};
  a_std.swap(b_std);

  ASSERT_EQ(a_std[0], a_s21[0]);
  ASSERT_EQ(a_std[1], a_s21[1]);
  ASSERT_EQ(a_std[2], a_s21[2]);

  ASSERT_EQ(b_std[0], b_s21[0]);
  ASSERT_EQ(b_std[1], b_s21[1]);
  ASSERT_EQ(b_std[2], b_s21[2]);
  ASSERT_EQ(b_std[3], b_s21[3]);
  ASSERT_EQ(b_std[4], b_s21[4]);
  ASSERT_EQ(b_std[5], b_s21[5]);
  ASSERT_EQ(b_std[6], b_s21[6]);
  ASSERT_EQ(b_std[7], b_s21[7]);
  ASSERT_EQ(b_std[8], b_s21[8]);
  ASSERT_EQ(b_std[9], b_s21[9]);

  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}
TEST(TestVectorSwap, TestVectorSwap4) {
  s21::vector<std::string> a_s21{"wish",      "ggwp",     "nope",    "apple",
                                 "crocodile", "elephant", "running", "blame",
                                 "workspace", "moscow"};
  s21::vector<std::string> b_s21{"early", "great", "tea"};
  a_s21.swap(b_s21);
  std::vector<std::string> a_std{"wish",      "ggwp",     "nope",    "apple",
                                 "crocodile", "elephant", "running", "blame",
                                 "workspace", "moscow"};
  std::vector<std::string> b_std{"early", "great", "tea"};
  a_std.swap(b_std);

  ASSERT_EQ(a_std[0], a_s21[0]);
  ASSERT_EQ(a_std[1], a_s21[1]);
  ASSERT_EQ(a_std[2], a_s21[2]);

  ASSERT_EQ(b_std[0], b_s21[0]);
  ASSERT_EQ(b_std[1], b_s21[1]);
  ASSERT_EQ(b_std[2], b_s21[2]);
  ASSERT_EQ(b_std[3], b_s21[3]);
  ASSERT_EQ(b_std[4], b_s21[4]);
  ASSERT_EQ(b_std[5], b_s21[5]);
  ASSERT_EQ(b_std[6], b_s21[6]);
  ASSERT_EQ(b_std[7], b_s21[7]);
  ASSERT_EQ(b_std[8], b_s21[8]);
  ASSERT_EQ(b_std[9], b_s21[9]);

  ASSERT_EQ(a_s21.size(), a_std.size());
  ASSERT_EQ(b_s21.size(), b_std.size());
}

TEST(TestVectorMethodAt, TestVectorMethodAt1) {
  s21::vector<int> b_s21{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> b_std{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (size_t i = 0; i < b_s21.size(); ++i) {
    ASSERT_EQ(b_std.at(i), b_s21.at(i));
  }
}
TEST(TestVectorMethodAt, TestVectorMethodAt2) {
  s21::vector<double> b_s21{11.2, 21.5, 3.54, 4.1,  5.76,
                            64.3, 7.01, 82.1, 9.99, 10.0};
  std::vector<double> b_std{11.2, 21.5, 3.54, 4.1,  5.76,
                            64.3, 7.01, 82.1, 9.99, 10.0};
  for (size_t i = 0; i < b_s21.size(); ++i) {
    ASSERT_EQ(b_std.at(i), b_s21.at(i));
  }
}
TEST(TestVectorMethodAt, TestVectorMethodAt3) {
  s21::vector<char> b_s21{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  std::vector<char> b_std{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  for (size_t i = 0; i < b_s21.size(); ++i) {
    ASSERT_EQ(b_std.at(i), b_s21.at(i));
  }
}
TEST(TestVectorMethodAt, TestVectorMethodAt4) {
  s21::vector<std::string> b_s21{"wish",      "ggwp",     "nope",    "apple",
                                 "crocodile", "elephant", "running", "blame",
                                 "workspace", "moscow"};
  std::vector<std::string> b_std{"wish",      "ggwp",     "nope",    "apple",
                                 "crocodile", "elephant", "running", "blame",
                                 "workspace", "moscow"};
  for (size_t i = 0; i < b_s21.size(); ++i) {
    ASSERT_EQ(b_std.at(i), b_s21.at(i));
  }
}

TEST(TestVectorOperatorSquareBrackets, TestVectorOperatorSquareBrackets1) {
  s21::vector<int> b_s21{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> b_std{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (size_t i = 0; i < b_s21.size(); ++i) {
    ASSERT_EQ(b_std[i], b_s21[i]);
  }
}
TEST(TestVectorOperatorSquareBrackets, TestVectorOperatorSquareBrackets2) {
  s21::vector<double> b_s21{11.2, 21.5, 3.54, 4.1,  5.76,
                            64.3, 7.01, 82.1, 9.99, 10.0};
  std::vector<double> b_std{11.2, 21.5, 3.54, 4.1,  5.76,
                            64.3, 7.01, 82.1, 9.99, 10.0};
  for (size_t i = 0; i < b_s21.size(); ++i) {
    ASSERT_EQ(b_std[i], b_s21[i]);
  }
}
TEST(TestVectorOperatorSquareBrackets, TestVectorOperatorSquareBrackets3) {
  s21::vector<char> b_s21{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  std::vector<char> b_std{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  for (size_t i = 0; i < b_s21.size(); ++i) {
    ASSERT_EQ(b_std[i], b_s21[i]);
  }
}
TEST(TestVectorOperatorSquareBrackets, TestVectorOperatorSquareBrackets4) {
  s21::vector<std::string> b_s21{"wish",      "ggwp",     "nope",    "apple",
                                 "crocodile", "elephant", "running", "blame",
                                 "workspace", "moscow"};
  std::vector<std::string> b_std{"wish",      "ggwp",     "nope",    "apple",
                                 "crocodile", "elephant", "running", "blame",
                                 "workspace", "moscow"};
  for (size_t i = 0; i < b_s21.size(); ++i) {
    ASSERT_EQ(b_std[i], b_s21[i]);
  }
}

TEST(TestVectorMethodFront, TestVectorMethodFront1) {
  s21::vector<int> b_s21{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> b_std{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_EQ(b_std.front(), b_s21.front());
}
TEST(TestVectorMethodFront, TestVectorMethodFront2) {
  s21::vector<double> b_s21{11.2, 21.5, 3.54, 4.1,  5.76,
                            64.3, 7.01, 82.1, 9.99, 10.0};
  std::vector<double> b_std{11.2, 21.5, 3.54, 4.1,  5.76,
                            64.3, 7.01, 82.1, 9.99, 10.0};
  ASSERT_EQ(b_std.front(), b_s21.front());
}
TEST(TestVectorMethodFront, TestVectorMethodFront3) {
  s21::vector<char> b_s21{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  std::vector<char> b_std{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  ASSERT_EQ(b_std.front(), b_s21.front());
}
TEST(TestVectorMethodFront, TestVectorMethodFront4) {
  s21::vector<std::string> b_s21{"wish",      "ggwp",     "nope",    "apple",
                                 "crocodile", "elephant", "running", "blame",
                                 "workspace", "moscow"};
  std::vector<std::string> b_std{"wish",      "ggwp",     "nope",    "apple",
                                 "crocodile", "elephant", "running", "blame",
                                 "workspace", "moscow"};
  ASSERT_EQ(b_std.front(), b_s21.front());
}

TEST(TestVectorMethodBack, TestVectorMethodback1) {
  s21::vector<int> b_s21{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> b_std{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_EQ(b_std.back(), b_s21.back());
}
TEST(TestVectorMethodBack, TestVectorMethodback2) {
  s21::vector<double> b_s21{11.2, 21.5, 3.54, 4.1,  5.76,
                            64.3, 7.01, 82.1, 9.99, 10.0};
  std::vector<double> b_std{11.2, 21.5, 3.54, 4.1,  5.76,
                            64.3, 7.01, 82.1, 9.99, 10.0};
  ASSERT_EQ(b_std.back(), b_s21.back());
}
TEST(TestVectorMethodBack, TestVectorMethodback3) {
  s21::vector<char> b_s21{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  std::vector<char> b_std{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  ASSERT_EQ(b_std.back(), b_s21.back());
}
TEST(TestVectorMethodBack, TestVectorMethodback4) {
  s21::vector<std::string> b_s21{"wish",      "ggwp",     "nope",    "apple",
                                 "crocodile", "elephant", "running", "blame",
                                 "workspace", "moscow"};
  std::vector<std::string> b_std{"wish",      "ggwp",     "nope",    "apple",
                                 "crocodile", "elephant", "running", "blame",
                                 "workspace", "moscow"};
  ASSERT_EQ(b_std.back(), b_s21.back());
}

TEST(TestVectorMethodEmpty, TestVectorMethodEmpty1NotEmpty) {
  s21::vector<int> b_s21{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> b_std{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_EQ(b_std.empty(), b_s21.empty());
}
TEST(TestVectorMethodEmpty, TestVectorMethodEmpty2NotEmpty) {
  s21::vector<double> b_s21{11.2, 21.5, 3.54, 4.1,  5.76,
                            64.3, 7.01, 82.1, 9.99, 10.0};
  std::vector<double> b_std{11.2, 21.5, 3.54, 4.1,  5.76,
                            64.3, 7.01, 82.1, 9.99, 10.0};
  ASSERT_EQ(b_std.empty(), b_s21.empty());
}
TEST(TestVectorMethodEmpty, TestVectorMethodEmpty3NotEmpty) {
  s21::vector<char> b_s21{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  std::vector<char> b_std{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  ASSERT_EQ(b_std.empty(), b_s21.empty());
}
TEST(TestVectorMethodEmpty, TestVectorMethodEmpty4NotEmpty) {
  s21::vector<std::string> b_s21{"wish",      "ggwp",     "nope",    "apple",
                                 "crocodile", "elephant", "running", "blame",
                                 "workspace", "moscow"};
  std::vector<std::string> b_std{"wish",      "ggwp",     "nope",    "apple",
                                 "crocodile", "elephant", "running", "blame",
                                 "workspace", "moscow"};
  ASSERT_EQ(b_std.empty(), b_s21.empty());
}

TEST(TestVectorMethodEmpty, TestVectorMethodEmpty1IsEmpty) {
  s21::vector<int> b_s21;
  std::vector<int> b_std;
  ASSERT_EQ(b_std.empty(), b_s21.empty());
}
TEST(TestVectorMethodEmpty, TestVectorMethodEmpty2IsEmpty) {
  s21::vector<double> b_s21;
  std::vector<double> b_std;
  ASSERT_EQ(b_std.empty(), b_s21.empty());
}
TEST(TestVectorMethodEmpty, TestVectorMethodEmpty3IsEmpty) {
  s21::vector<char> b_s21;
  std::vector<char> b_std;
  ASSERT_EQ(b_std.empty(), b_s21.empty());
}
TEST(TestVectorMethodEmpty, TestVectorMethodEmpty4IsEmpty) {
  s21::vector<std::string> b_s21;
  std::vector<std::string> b_std;
  ASSERT_EQ(b_std.empty(), b_s21.empty());
}

TEST(TestVectorMethodSize, TestVectorMethodSizeNull1) {
  s21::vector<int> a;
  std::vector<int> b;
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestVectorMethodSize, TestVectorMethodSizeNull2) {
  s21::vector<double> a;
  std::vector<double> b;
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestVectorMethodSize, TestVectorMethodSizeNull3) {
  s21::vector<char> a;
  std::vector<char> b;
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestVectorMethodSize, TestVectorMethodSizeNull4) {
  s21::vector<std::string> a;
  std::vector<std::string> b;
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestVectorMethodSize, TestVectorMethodSizeTen1) {
  s21::vector<int> a(10);
  std::vector<int> b(10);
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestVectorMethodSize, TestVectorMethodSizeTen2) {
  s21::vector<double> a(10);
  std::vector<double> b(10);
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestVectorMethodSize, TestVectorMethodSizeTen3) {
  s21::vector<char> a(10);
  std::vector<char> b(10);
  ASSERT_EQ(a.size(), b.size());
}
TEST(TestVectorMethodSize, TestVectorMethodSizeTen4) {
  s21::vector<std::string> a(10);
  std::vector<std::string> b(10);
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestVectorMethodSize, TestVectorMethodSizeTenInit1) {
  s21::vector<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  ASSERT_EQ(b.size(), a.size());
}
TEST(TestVectorMethodSize, TestVectorMethodSizeTenInit2) {
  s21::vector<double> b{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};
  std::vector<double> a{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};

  ASSERT_EQ(b.size(), a.size());
}
TEST(TestVectorMethodSize, TestVectorMethodSizeTenInit3) {
  s21::vector<char> b{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  std::vector<char> a{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};

  ASSERT_EQ(b.size(), a.size());
}
TEST(TestVectorMethodSize, TestVectorMethodSizeTenInit4) {
  s21::vector<std::string> b{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};
  std::vector<std::string> a{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};

  ASSERT_EQ(b.size(), a.size());
}

TEST(TestVectorMethodCapicity, TestVectorMethodCapicty1) {
  s21::vector<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  ASSERT_EQ(b.capacity(), a.capacity());
}
TEST(TestVectorMethodCapicity, TestVectorMethodCapicty2) {
  s21::vector<double> b{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};
  std::vector<double> a{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};

  ASSERT_EQ(b.capacity(), a.capacity());
}
TEST(TestVectorMethodCapicity, TestVectorMethodCapicty3) {
  s21::vector<char> b{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  std::vector<char> a{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};

  ASSERT_EQ(b.capacity(), a.capacity());
}
TEST(TestVectorMethodCapicity, TestVectorMethodCapicty4) {
  s21::vector<std::string> b{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};
  std::vector<std::string> a{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};

  ASSERT_EQ(b.capacity(), a.capacity());
}

TEST(TestVectorMethodMaxSize, TestVectorMethodMaxSize1) {
  s21::vector<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  ASSERT_EQ(b.max_size(), a.max_size());
}
TEST(TestVectorMethodMaxSize, TestVectorMethodMaxSize2) {
  s21::vector<double> b{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};
  std::vector<double> a{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};

  ASSERT_EQ(b.max_size(), a.max_size());
}
TEST(TestVectorMethodMaxSize, TestVectorMethodMaxSize3) {
  s21::vector<char> b{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  std::vector<char> a{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};

  //ASSERT_EQ(b.max_size(), a.max_size());
}
TEST(TestVectorMethodMaxSize, TestVectorMethodMaxSize4) {
  s21::vector<std::string> b{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};
  std::vector<std::string> a{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};

  ASSERT_EQ(b.max_size(), a.max_size());
}

TEST(TestVectorMethodShrink, TestVectorMethodShrink1) {
  s21::vector<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_EQ(b.capacity(), a.capacity());
  a.push_back(1);
  b.push_back(1);
  ASSERT_EQ(b.capacity(), a.capacity());
  a.shrink_to_fit();
  b.shrink_to_fit();
  ASSERT_EQ(b.capacity(), a.capacity());
}
TEST(TestVectorMethodShrink, TestVectorMethodShrink2) {
  s21::vector<double> b{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};
  std::vector<double> a{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};
  ASSERT_EQ(b.capacity(), a.capacity());
  a.push_back(3.145);
  b.push_back(3.145);
  ASSERT_EQ(b.capacity(), a.capacity());
  a.shrink_to_fit();
  b.shrink_to_fit();
  ASSERT_EQ(b.capacity(), a.capacity());
}
TEST(TestVectorMethodShrink, TestVectorMethodShrink3) {
  s21::vector<char> b{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  std::vector<char> a{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  ASSERT_EQ(b.capacity(), a.capacity());
  a.push_back('S');
  b.push_back('S');
  ASSERT_EQ(b.capacity(), a.capacity());
  a.shrink_to_fit();
  b.shrink_to_fit();
  ASSERT_EQ(b.capacity(), a.capacity());
}
TEST(TestVectorMethodShrink, TestVectorMethodShrink4) {
  s21::vector<std::string> b{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};
  std::vector<std::string> a{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};
  ASSERT_EQ(b.capacity(), a.capacity());
  a.push_back("hello");
  b.push_back("hello");
  ASSERT_EQ(b.capacity(), a.capacity());
  a.shrink_to_fit();
  b.shrink_to_fit();
  ASSERT_EQ(b.capacity(), a.capacity());
}

TEST(TestVectorMethodInsert, TestVectorMethodInsert1) {
  s21::vector<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_EQ(b.capacity(), a.capacity());
  auto iter_s12 = a.insert(a.end(), 1);
  auto iter_std = b.insert(b.end(), 1);
  ASSERT_EQ(*iter_s12, *iter_std);
}
TEST(TestVectorMethodInsert, TestVectorMethodInsert2) {
  s21::vector<double> b{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};
  std::vector<double> a{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};
  ASSERT_EQ(b.capacity(), a.capacity());
  auto iter_s12 = a.insert(a.end(), 2.44);
  auto iter_std = b.insert(b.end(), 2.44);
  ASSERT_EQ(*iter_s12, *iter_std);
}
TEST(TestVectorMethodInsert, TestVectorMethodInsert3) {
  s21::vector<char> b{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  std::vector<char> a{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  ASSERT_EQ(b.capacity(), a.capacity());
  auto iter_s12 = a.insert(a.end(), 'F');
  auto iter_std = b.insert(b.end(), 'F');
  ASSERT_EQ(*iter_s12, *iter_std);
}
TEST(TestVectorMethodInsert, TestVectorMethodInsert4) {
  s21::vector<std::string> b{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};
  std::vector<std::string> a{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};
  ASSERT_EQ(b.capacity(), a.capacity());
  auto iter_s12 = a.insert(a.end(), "hello");
  auto iter_std = b.insert(b.end(), "hello");
  ASSERT_EQ(*iter_s12, *iter_std);
}

TEST(TestVectorMethodErase, TestVectorMethodErase1) {
  s21::vector<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  auto iter_s12 = a.erase(a.begin());
  auto iter_std = b.erase(b.begin());

  ASSERT_EQ(*iter_s12, *iter_std);
}
TEST(TestVectorMethodErase, TestVectorMethodErase2) {
  s21::vector<double> b{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};
  std::vector<double> a{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};

  auto iter_s12 = a.erase(a.begin());
  auto iter_std = b.erase(b.begin());

  ASSERT_EQ(*iter_s12, *iter_std);
}
TEST(TestVectorMethodErase, TestVectorMethodErase3) {
  s21::vector<char> b{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  std::vector<char> a{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};

  auto iter_s12 = a.erase(a.begin());
  auto iter_std = b.erase(b.begin());

  ASSERT_EQ(*iter_s12, *iter_std);
}
TEST(TestVectorMethodErase, TestVectorMethodErase4) {
  s21::vector<std::string> b{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};
  std::vector<std::string> a{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};

  auto iter_s12 = a.erase(a.begin());
  auto iter_std = b.erase(b.begin());

  ASSERT_EQ(*iter_s12, *iter_std);
}

TEST(TestVectorMethodReserve, TestVectorMethodReserve1) {
  s21::vector<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  a.reserve(15);
  b.reserve(15);
  ASSERT_EQ(a.capacity(), b.capacity());
}
TEST(TestVectorMethodReserve, TestVectorMethodReserve2) {
  s21::vector<double> b{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};
  std::vector<double> a{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};
  a.reserve(15);
  b.reserve(15);
  ASSERT_EQ(a.capacity(), b.capacity());
}
TEST(TestVectorMethodReserve, TestVectorMethodReserve3) {
  s21::vector<char> b{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  std::vector<char> a{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  a.reserve(15);
  b.reserve(15);
  ASSERT_EQ(a.capacity(), b.capacity());
}
TEST(TestVectorMethodReserve, TestVectorMethodReserve4) {
  s21::vector<std::string> b{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};
  std::vector<std::string> a{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};
  a.reserve(15);
  b.reserve(15);
  ASSERT_EQ(a.capacity(), b.capacity());
}

TEST(TestVectorMethodPushBack, TestVectorMethodPushBack1) {
  s21::vector<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  a.push_back(15);
  b.push_back(15);
  ASSERT_EQ(a.back(), b.back());
}
TEST(TestVectorMethodPushBack, TestVectorMethodPushBack2) {
  s21::vector<double> b{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};
  std::vector<double> a{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};
  a.push_back(17.2);
  b.push_back(17.2);
  ASSERT_EQ(a.back(), b.back());
}
TEST(TestVectorMethodPushBack, TestVectorMethodPushBack3) {
  s21::vector<char> b{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  std::vector<char> a{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  a.push_back('F');
  b.push_back('F');
  ASSERT_EQ(a.back(), b.back());
}
TEST(TestVectorMethodPushBack, TestVectorMethodPushBack4) {
  s21::vector<std::string> b{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};
  std::vector<std::string> a{"wish",      "ggwp",     "nope",    "apple",
                             "crocodile", "elephant", "running", "blame",
                             "workspace", "moscow"};
  a.push_back("hello");
  b.push_back("hello");
  ASSERT_EQ(a.back(), b.back());
}

TEST(TestVectorMethodPopBack, TestVectorMethodPopBack1) {
  s21::vector<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  a.pop_back();
  b.pop_back();
  ASSERT_EQ(a.back(), b.back());
}
TEST(TestVectorMethodPopBack, TestVectorMethodPopBack2) {
  s21::vector<double> b{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};
  std::vector<double> a{11.2, 21.5, 3.54, 4.1,  5.76,
                        64.3, 7.01, 82.1, 9.99, 10.0};
  a.pop_back();
  b.pop_back();
  ASSERT_EQ(a.back(), b.back());
}
TEST(TestVectorMethodPopBack, TestVectorMethodPopBack3) {
  s21::vector<char> b{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  std::vector<char> a{'b', 'f', 'h', 'j', 'v', 'a', 's', 'd', 't', 'y'};
  a.pop_back();
  b.pop_back();
  ASSERT_EQ(a.back(), b.back());
}

TEST(TestVectorMethodBonusInsMany, TestVectorMethodBonusInsMany1) {
  s21::vector<int> b{1, 2, 3};
  auto iter = b.insert_many(b.cbegin(), 4, 5, 6);
  --iter;
  ASSERT_EQ(*iter, 6);
  --iter;
  ASSERT_EQ(*iter, 5);
  --iter;
  ASSERT_EQ(*iter, 4);
}
TEST(TestVectorMethodBonusInsMany, TestVectorMethodBonusInsMany2) {
  s21::vector<double> b{5.76, 64.3, 7.01};
  auto iter = b.insert_many(b.cbegin(), 433.1, 5.43, 6.32);
  --iter;
  ASSERT_EQ(*iter, 6.32);
  --iter;
  ASSERT_EQ(*iter, 5.43);
  --iter;
  ASSERT_EQ(*iter, 433.1);
}
TEST(TestVectorMethodBonusInsMany, TestVectorMethodBonusInsMany3) {
  s21::vector<char> b{'v', 'v', 's'};
  auto iter = b.insert_many(b.cbegin(), 'p', 'h', 't');
  --iter;
  ASSERT_EQ(*iter, 't');
  --iter;
  ASSERT_EQ(*iter, 'h');
  --iter;
  ASSERT_EQ(*iter, 'p');
}
TEST(TestVectorMethodBonusInsMany, TestVectorMethodBonusInsMany4) {
  s21::vector<std::string> b{"wish", "ggwp", "nope"};
  auto iter = b.insert_many(b.cbegin(), "hello", "world", "pay");
  --iter;
  ASSERT_EQ(*iter, "pay");
  --iter;
  ASSERT_EQ(*iter, "world");
  --iter;
  ASSERT_EQ(*iter, "hello");
}

TEST(TestVectorMethodBonusInsMany, TestVectorMethodBonusInsMany5) {
  s21::vector<int> b{1, 2, 3};
  auto it = b.cbegin();
  ++it;
  auto iter = b.insert_many(it, 4, 5, 6);
  --iter;
  ASSERT_EQ(*iter, 6);
  --iter;
  ASSERT_EQ(*iter, 5);
  --iter;
  ASSERT_EQ(*iter, 4);
}
TEST(TestVectorMethodBonusInsMany, TestVectorMethodBonusInsMany6) {
  s21::vector<double> b{5.76, 64.3, 7.01};
  auto it = b.cbegin();
  ++it;
  auto iter = b.insert_many(it, 433.1, 5.43, 6.32);
  --iter;
  ASSERT_EQ(*iter, 6.32);
  --iter;
  ASSERT_EQ(*iter, 5.43);
  --iter;
  ASSERT_EQ(*iter, 433.1);
}
TEST(TestVectorMethodBonusInsMany, TestVectorMethodBonusInsMany7) {
  s21::vector<char> b{'v', 'v', 's'};
  auto it = b.cbegin();
  ++it;
  auto iter = b.insert_many(it, 'p', 'h', 't');
  --iter;
  ASSERT_EQ(*iter, 't');
  --iter;
  ASSERT_EQ(*iter, 'h');
  --iter;
  ASSERT_EQ(*iter, 'p');
}
TEST(TestVectorMethodBonusInsMany, TestVectorMethodBonusInsMany8) {
  s21::vector<std::string> b{"wish", "ggwp", "nope"};
  auto it = b.cbegin();
  ++it;
  auto iter = b.insert_many(it, "hello", "world", "pay");
  --iter;
  ASSERT_EQ(*iter, "pay");
  --iter;
  ASSERT_EQ(*iter, "world");
  --iter;
  ASSERT_EQ(*iter, "hello");
}

TEST(TestVectorMethodBonusInsManyBack, TestVectorMethodBonusInsManyBack1) {
  s21::vector<int> b{1, 2, 3};
  b.insert_many_back(7, 8, 9);
  auto iter = b.end();
  --iter;
  ASSERT_EQ(*iter, 9);
  --iter;
  ASSERT_EQ(*iter, 8);
  --iter;
  ASSERT_EQ(*iter, 7);
}
TEST(TestVectorMethodBonusInsManyBack, TestVectorMethodBonusInsManyBack2) {
  s21::vector<double> b{5.76, 64.3, 7.01};
  b.insert_many_back(433.1, 5.43, 6.32);
  auto iter = b.end();
  --iter;
  ASSERT_EQ(*iter, 6.32);
  --iter;
  ASSERT_EQ(*iter, 5.43);
  --iter;
  ASSERT_EQ(*iter, 433.1);
}
TEST(TestVectorMethodBonusInsManyBack, TestVectorMethodBonusInsManyBack3) {
  s21::vector<char> b{'v', 'v', 's'};
  b.insert_many_back('p', 'h', 't');
  auto iter = b.end();
  --iter;
  ASSERT_EQ(*iter, 't');
  --iter;
  ASSERT_EQ(*iter, 'h');
  --iter;
  ASSERT_EQ(*iter, 'p');
}
TEST(TestVectorMethodBonusInsManyBack, TestVectorMethodBonusInsManyBack4) {
  s21::vector<std::string> b{"wish", "ggwp", "nope"};
  b.insert_many_back("hello", "world", "pay");
  auto iter = b.end();
  --iter;
  ASSERT_EQ(*iter, "pay");
  --iter;
  ASSERT_EQ(*iter, "world");
  --iter;
  ASSERT_EQ(*iter, "hello");
}

TEST(TestVectorIterator, Iterator1_1) {
  s21::vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  ASSERT_EQ(it < it2, iter < iter2);
}
TEST(TestVectorIterator, Iterator1_2) {
  s21::vector<double> V = {64.3, 7.01, 82.1, 9.99, 10.0};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  std::vector<double> V2 = {64.3, 7.01, 82.1, 9.99, 10.0};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  ASSERT_EQ(it < it2, iter < iter2);
}
TEST(TestVectorIterator, Iterator1_3) {
  s21::vector<char> V = {'j', 'v', 'a', 's', 'd'};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  std::vector<char> V2 = {'j', 'v', 'a', 's', 'd'};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  ASSERT_EQ(it < it2, iter < iter2);
}
TEST(TestVectorIterator, Iterator1_4) {
  s21::vector<std::string> V = {"apple", "crocodile", "elephant", "running",
                                "blame"};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  std::vector<std::string> V2 = {"apple", "crocodile", "elephant", "running",
                                 "blame"};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  ASSERT_EQ(it < it2, iter < iter2);
}

TEST(TestVectorIterator, Iterator2_1) {
  s21::vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  ASSERT_EQ(it > it2, iter > iter2);
}
TEST(TestVectorIterator, Iterator2_2) {
  s21::vector<double> V = {64.3, 7.01, 82.1, 9.99, 10.0};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  std::vector<double> V2 = {64.3, 7.01, 82.1, 9.99, 10.0};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  ASSERT_EQ(it > it2, iter > iter2);
}
TEST(TestVectorIterator, Iterator2_3) {
  s21::vector<char> V = {'j', 'v', 'a', 's', 'd'};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  std::vector<char> V2 = {'j', 'v', 'a', 's', 'd'};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  ASSERT_EQ(it > it2, iter > iter2);
}
TEST(TestVectorIterator, Iterator2_4) {
  s21::vector<std::string> V = {"apple", "crocodile", "elephant", "running",
                                "blame"};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  std::vector<std::string> V2 = {"apple", "crocodile", "elephant", "running",
                                 "blame"};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  ASSERT_EQ(it > it2, iter > iter2);
}

TEST(TestVectorIterator, Iterator3_1) {
  s21::vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  iter2++;
  ASSERT_EQ(it <= it2, iter < iter2);
}
TEST(TestVectorIterator, Iterator3_2) {
  s21::vector<double> V = {64.3, 7.01, 82.1, 9.99, 10.0};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  it2++;
  std::vector<double> V2 = {64.3, 7.01, 82.1, 9.99, 10.0};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  iter2++;
  ASSERT_EQ(it <= it2, iter < iter2);
}
TEST(TestVectorIterator, Iterator3_3) {
  s21::vector<char> V = {'j', 'v', 'a', 's', 'd'};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  it2++;
  std::vector<char> V2 = {'j', 'v', 'a', 's', 'd'};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  iter2++;
  ASSERT_EQ(it <= it2, iter < iter2);
}
TEST(TestVectorIterator, Iterator3_4) {
  s21::vector<std::string> V = {"apple", "crocodile", "elephant", "running",
                                "blame"};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  it2++;
  std::vector<std::string> V2 = {"apple", "crocodile", "elephant", "running",
                                 "blame"};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  iter2++;
  ASSERT_EQ(it <= it2, iter < iter2);
}

TEST(TestVectorIterator, Iterator4_1) {
  s21::vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  iter2++;
  ASSERT_EQ(it >= it2, iter >= iter2);
}
TEST(TestVectorIterator, Iterator4_2) {
  s21::vector<double> V = {64.3, 7.01, 82.1, 9.99, 10.0};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  it2++;
  std::vector<double> V2 = {64.3, 7.01, 82.1, 9.99, 10.0};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  iter2++;
  ASSERT_EQ(it >= it2, iter >= iter2);
}
TEST(TestVectorIterator, Iterator4_3) {
  s21::vector<char> V = {'j', 'v', 'a', 's', 'd'};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  it2++;
  std::vector<char> V2 = {'j', 'v', 'a', 's', 'd'};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  iter2++;
  ASSERT_EQ(it >= it2, iter >= iter2);
}
TEST(TestVectorIterator, Iterator4_4) {
  s21::vector<std::string> V = {"apple", "crocodile", "elephant", "running",
                                "blame"};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  it2++;
  std::vector<std::string> V2 = {"apple", "crocodile", "elephant", "running",
                                 "blame"};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  iter2++;
  ASSERT_EQ(it >= it2, iter >= iter2);
}

TEST(TestVectorIterator, Iterator5) {
  s21::vector<int> V = {1, 2};
  auto it = V.begin();
  ++it;
  std::vector<int> V2 = {1, 2};
  auto iter = V2.begin();
  ++iter;
  ASSERT_EQ(*it, *iter);
}

TEST(TestVectorIterator, Iterator6) {
  s21::vector<int> V = {1, 2};
  s21::vector<int> V2 = {1, 2};
  auto it = V.begin();
  auto it2 = V2.begin();
  std::vector<int> V3 = {1, 2};
  std::vector<int> V4 = {1, 2};
  auto iter = V3.begin();
  auto iter2 = V4.begin();
  ASSERT_EQ(it != it2, iter != iter2);
}

TEST(TestVectorIterator, Iterator7) {
  s21::vector<int> V = {1, 2};
  s21::vector<int> V2 = {1, 2};
  auto it = V.begin();
  auto it2 = V2.begin();
  std::vector<int> V3 = {1, 2};
  std::vector<int> V4 = {1, 2};
  auto iter = V3.begin();
  auto iter2 = V4.begin();
  ASSERT_EQ(it == it2, iter == iter2);
}

TEST(TestVectorIterator, Iterator8) {
  s21::vector<int> V = {1, 2};
  auto it = V.begin();
  std::vector<int> V2 = {1, 2};
  auto iter = V2.begin();
  ASSERT_EQ(*(it + 1), *(iter + 1));
}

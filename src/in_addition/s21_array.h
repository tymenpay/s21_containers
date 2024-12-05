#ifndef CPP_S21_ARRAY_H
#define CPP_S21_ARRAY_H

namespace s21 {
template <class T, std::size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

 private:
  T *arr_;

 public:
  array() : arr_(new T[N]()) {}

  array(std::initializer_list<value_type> const &items) : arr_(new T[N]()) {
    size_t count = 0;
    for (auto i : items) {
      if (count >= N) break;
      arr_[count++] = i;
    }
  }

  array(const array &a) : arr_(new T[N]) {
    for (size_t i = 0; i < N; ++i) {
      arr_[i] = a.arr_[i];
    }
  }

  array(array &&a) noexcept : arr_(a.arr_) { a.arr_ = nullptr; }

  ~array() { delete[] arr_; }

  array &operator=(const array &a) {
    if (this != &a) {
      delete[] arr_;
      arr_ = new T[N];
      for (size_t i = 0; i < N; ++i) {
        arr_[i] = a.arr_[i];
      }
    }
    return *this;
  }

  array &operator=(array &&a) noexcept {
    if (this != &a) {
      delete[] arr_;
      arr_ = a.arr_;
      a.arr_ = nullptr;
    }
    return *this;
  }

  reference at(size_type pos) {
    if (pos >= N) throw std::out_of_range("Index out of range");
    return arr_[pos];
  }

  reference operator[](size_type pos) {
    if (!arr_ || pos >= N) throw std::out_of_range("Invalid access");
    return arr_[pos];
  }
  const_reference operator[](size_type pos) const {
    if (!arr_ || pos >= N) throw std::out_of_range("Invalid access");
    return arr_[pos];
  }

  const_reference front() const { return arr_[0]; }
  const_reference back() const { return arr_[N - 1]; }
  iterator data() { return arr_; }
  const_iterator data() const { return arr_; }

  iterator begin() { return arr_; }
  iterator end() { return arr_ + N; }
  const_iterator begin() const { return arr_; }
  const_iterator end() const { return arr_ + N; }

  bool empty() const { return N == 0; }
  size_type size() const { return N; }
  size_type max_size() const { return N; }

  void swap(array &other) { std::swap(arr_, other.arr_); }

  void fill(const_reference value) {
    for (size_t i = 0; i < N; ++i) {
      arr_[i] = value;
    }
  }
};
}  // namespace s21

#endif
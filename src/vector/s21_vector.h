#ifndef CPP_S21_VECTOR_H
#define CPP_S21_VECTOR_H

#include <initializer_list>
#include <iostream>
#include <iterator>
#include <memory>
#include <utility>

namespace s21 {
template <typename T, bool is_const>
struct Iterator;

template <typename T, typename Allocator = std::allocator<T>>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using pointer = T *;
  using const_pointer = const T *;
  using size_type = size_t;
  using alloc_traits = std::allocator_traits<Allocator>;
  using iterator = Iterator<T, false>;
  using const_iterator = Iterator<T, true>;

 private:
  size_type size_;
  size_type capacity_;
  pointer arr_;
  Allocator alloc_;

 public:
  vector() : size_(0), capacity_(0), arr_(nullptr), alloc_(Allocator()) {}

  explicit vector(size_type n, const Allocator &alloc = Allocator())
      : size_(n), capacity_(n), arr_(nullptr), alloc_(alloc) {
    arr_ = alloc_traits::allocate(alloc_, size_);
    for (size_type i = 0; i < n; ++i) {
      alloc_traits::construct(alloc_, arr_ + i, value_type());
    }
  }

  vector(std::initializer_list<value_type> const &items,
         const Allocator &alloc = Allocator())
      : size_(items.size()),
        capacity_(items.size()),
        arr_(nullptr),
        alloc_(alloc) {
    arr_ = alloc_traits::allocate(alloc_, items.size());
    std::uninitialized_copy(items.begin(), items.end(), arr_);
  }

  vector(const vector &v)
      : size_(v.size_), capacity_(v.capacity_), alloc_(v.alloc_) {
    arr_ = alloc_traits::allocate(alloc_, capacity_);
    for (size_type i = 0; i < size_; ++i) {
      alloc_traits::construct(alloc_, arr_ + i, v.arr_[i]);
    }
  }

  vector(vector &&v) noexcept
      : size_(v.size_),
        capacity_(v.capacity_),
        arr_(v.arr_),
        alloc_(std::move(v.alloc_)) {
    v.arr_ = nullptr;
    v.size_ = 0;
    v.capacity_ = 0;
  }

  ~vector() {
    for (size_type i = 0; i < size_; ++i) {
      alloc_traits::destroy(alloc_, arr_ + i);
    }
    alloc_traits::deallocate(alloc_, arr_, capacity_);
  }

  vector &operator=(vector &&v) noexcept {
    clear();
    vector new_Vector(std::move(v));
    swap(new_Vector);
    return *this;
  }

  void swap(vector &other) {
    std::swap(alloc_, other.alloc_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
    std::swap(arr_, other.arr_);
  }

  value_type at(size_type i) {
    if (i >= size_) throw std::out_of_range("Index out of range");
    return arr_[i];
  }

  reference operator[](size_type pos) { return arr_[pos]; }
  const_reference front() { return *(arr_); };
  const_reference back() { return *(arr_ + size_ - 1); }
  pointer data() const noexcept { return arr_; };

  iterator begin() noexcept { return iterator(arr_); }
  iterator end() noexcept { return iterator(arr_ + size_); }
  const_iterator cbegin() const noexcept { return const_iterator(arr_); }
  const_iterator cend() const noexcept { return const_iterator(arr_ + size_); }

  bool empty() const noexcept {
    bool res = false;
    if (cbegin() == cend()) {
      res = true;
    }
    return res;
  }
  size_type size() const { return size_; }
  size_type capacity() const { return capacity_; }
  size_type max_size() const noexcept { return alloc_traits::max_size(alloc_); }

  void shrink_to_fit() {
    if (size_ == capacity_) return;
    pointer new_arr = alloc_traits::allocate(alloc_, size_);

    for (size_type i = 0; i < size_; ++i) {
      alloc_traits::construct(alloc_, new_arr + i, std::move(arr_[i]));
    }
    for (size_type i = 0; i < size_; ++i) {
      alloc_traits::destroy(alloc_, arr_ + i);
    }
    alloc_traits::deallocate(alloc_, arr_, capacity_);

    arr_ = new_arr;
    capacity_ = size_;
  }

  void clear() {
    for (size_type i = 0; i < size_; ++i) {
      alloc_traits::destroy(alloc_, arr_ + i);
    }
    size_ = 0;
  }

  iterator insert(iterator pos, const_reference value) {
    size_type index = std::distance(begin(), pos);
    size_type new_size = size_ + 1;
    reserve(new_size);
    std::cout << size_ << '\n';
    for (size_type i = size_; i > index; --i) {
      alloc_traits::construct(alloc_, arr_ + i, std::move(arr_[i - 1]));
      alloc_traits::destroy(alloc_, arr_ + i - 1);
    }
    alloc_traits::construct(alloc_, arr_ + index, value);
    size_ += 1;

    return arr_ + index;
  }

  iterator erase(iterator pos) {
    if (pos == end()) return end();

    if (pos == std::prev(end())) {
      pop_back();
      return end();
    }
    size_type index = std::distance(begin(), pos);
    alloc_traits::destroy(alloc_, arr_ + index);
    for (size_type i = index + 1; i < size_; ++i) {
      alloc_traits::construct(alloc_, arr_ + i - 1, std::move(arr_[i]));
      alloc_traits::destroy(alloc_, arr_ + i);
    }
    size_--;
    return arr_ + index;
  }
  void reserve(size_type new_capacity) {
    if (new_capacity <= capacity_) return;

    pointer new_arr = alloc_traits::allocate(alloc_, new_capacity);
    size_type i = 0;
    try {
      for (i = 0; i < size_; ++i) {
        alloc_traits::construct(alloc_, new_arr + i,
                                std::move_if_noexcept(arr_[i]));
      }
    } catch (...) {
      for (size_type j = 0; j < i; ++j) {
        alloc_traits::destroy(alloc_, new_arr + j);
      }
      alloc_traits::deallocate(alloc_, new_arr, new_capacity);
      throw;
    }  //

    for (size_type i = 0; i < size_; ++i) {
      alloc_traits::destroy(alloc_, arr_ + i);
    }
    alloc_traits::deallocate(alloc_, arr_, capacity_);

    arr_ = new_arr;
    capacity_ = new_capacity;
  }

  void push_back(const_reference value) {
    if (size_ == capacity_) {
      reserve(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    alloc_traits::construct(alloc_, arr_ + size_, value);
    size_++;
  }

  void pop_back() {
    alloc_traits::destroy(alloc_, arr_ + size_);
    size_--;
  }

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args) noexcept {
    size_type index = std::distance(cbegin(), pos);
    size_type new_size = size_ + sizeof...(args);
    reserve(new_size);

    for (size_type i = size_; i > index; --i) {
      alloc_traits::construct(alloc_, arr_ + i + sizeof...(args) - 1,
                              std::move(arr_[i - 1]));
      alloc_traits::destroy(alloc_, arr_ + i - 1);
    }
    (alloc_traits::construct(alloc_, arr_ + index++, std::forward<Args>(args)),
     ...);
    size_ += sizeof...(args);

    return arr_ + index;
  }

  template <typename... Args>
  void insert_many_back(Args &&...args) {
    size_type old_size = size_;
    size_type new_size = size_ + sizeof...(args);
    reserve(new_size);

    (alloc_traits::construct(alloc_, arr_ + old_size++,
                             std::forward<Args>(args)),
     ...);
    size_ += sizeof...(args);
  }
};

template <class T, bool is_const>
struct Iterator {
  using pointer = std::conditional_t<is_const, const T *, T *>;
  using reference = std::conditional_t<is_const, const T &, T &>;
  using difference_type = std::ptrdiff_t;

 private:
  pointer value_;

 public:
  friend class vector<T>;

 public:
  Iterator() : value_(nullptr) {}
  Iterator(pointer value) : value_(value) {}

  Iterator operator+(const Iterator &other) const {
    Iterator temp = *this;
    while (temp != other) {
      ++temp;
    }
    return temp;
  }
  Iterator operator+(int n) const {
    Iterator temp = *this;
    for (int i = 0; i < n; ++i) {
      ++temp;
    }
    return temp;
  }
  Iterator operator-(int n) const {
    Iterator temp = *this;
    for (int i = 0; i < n; ++i) {
      --temp;
    }
    return temp;
  }
  Iterator operator++(int) {
    Iterator temp = *this;
    ++(*this);
    return temp;
  }
  Iterator operator--(int) {
    Iterator temp = *this;
    --(*this);
    return temp;
  }
  Iterator &operator++() {
    value_++;
    return *this;
  }
  Iterator &operator--() {
    value_--;
    return *this;
  }
  Iterator &operator+=(difference_type n) {
    value_ += n;
    return *this;
  }
  difference_type operator-(const Iterator &other) const {
    return value_ - other.value_;
  }
  reference operator*() const { return *value_; }
  pointer operator->() const { return value_; }

  friend bool operator<=(const Iterator &a, const Iterator &b) {
    return (a.value_ <= b.value_);
  };
  friend bool operator>=(const Iterator &a, const Iterator &b) {
    return (a.value_ >= b.value_);
  }
  friend bool operator<(const Iterator &a, const Iterator &b) {
    return (a.value_ < b.value_);
  };
  friend bool operator>(const Iterator &a, const Iterator &b) {
    return (a.value_ > b.value_);
  };
  friend bool operator!=(const Iterator &a, const Iterator &b) {
    return (a.value_ != b.value_);
  };
  friend bool operator==(const Iterator &a, const Iterator &b) {
    return (a.value_ == b.value_);
  };
};
}  // namespace s21
namespace std {
template <typename T, bool is_const>
struct iterator_traits<s21::Iterator<T, is_const>> {
  using difference_type = std::ptrdiff_t;
  using value_type = T;
  using pointer = typename s21::Iterator<T, is_const>::pointer;
  using reference = typename s21::Iterator<T, is_const>::reference;
  using iterator_category = std::random_access_iterator_tag;
};

}  // namespace std
#endif

#ifndef CPP_S21_MAP_H
#define CPP_S21_MAP_H

#include <initializer_list>
#include <iostream>
#include <iterator>
#include <memory>
#include <utility>

#include "s21_rb_tree.h"

namespace s21 {

template <typename Key, typename T, class Compare = std::less<Key>,
          class Allocator = std::allocator<T>>
class map {
 public:
  using value_type = std::pair<const Key, T>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = RBIterator<const Key, T, Compare, false>;
  using const_iterator = RBIterator<Key, T, Compare, true>;
  using size_type = size_t;
  using tree_type = RBTree<const Key, T, Compare, Allocator>;
  using traits = std::allocator_traits<Allocator>;

 public:
  map() noexcept {};
  map(std::initializer_list<value_type> const &items) {
    for (auto i = items.begin(); i < items.end(); ++i) {
      insert(*i);
    }
  }
  map(const map &m)
      : alloc_(traits::select_on_container_copy_construction(m.alloc_)),
        compare_(m.compare_) {
    for (auto i = m.tree_.cbegin(); i != m.tree_.cend(); ++i) {
      insert(*i);
    }
  }
  map(map &&m)
      : tree_(),
        alloc_(traits::select_on_container_copy_construction(m.alloc_)),
        compare_(std::move(m.compare_)) {
    tree_.Move(std::move(m.tree_));
  }
  ~map() noexcept = default;

  map &operator=(map &&m) noexcept {
    if (this != &m) {
      tree_.Move(std::move(m.tree_));
    }
    return *this;
  }
  T &at(const Key &key) {
    if (!contains(key)) {
      throw std::out_of_range("error");
    }
    return (*(find(key))).second;
  }

  T &operator[](const Key &key) noexcept { return (*(find(key))).second; }

  iterator begin() { return tree_.begin(); }
  const_iterator cbegin() { return tree_.cbegin(); }
  iterator end() { return tree_.end(); }
  const_iterator cend() { return tree_.cend(); }

  bool empty() noexcept { return tree_.empty(); }
  size_type size() const noexcept { return tree_.size(); }
  size_type max_size() const noexcept { return traits::max_size(alloc_); }

  void clear() noexcept { tree_.clear(); }
  std::pair<iterator, bool> insert(const value_type &value) {
    iterator it = find(value.first);

    if (it != end()) {
      return std::make_pair<iterator, bool>(iterator(it), false);
    } else {
      return tree_.insert(value.first, value.second);
    }
  }
  void erase(iterator pos) noexcept {
    iterator it = find((*pos).first);

    if (it != end()) {
      tree_.erase(pos);
    }
  }
  void swap(map &other) noexcept { tree_.swap(other.tree_); }
  void merge(map &other) noexcept {
    for (const auto &pair : other) {
      tree_.insert(pair.first, pair.second);
    }
    other.clear();
  }
  bool contains(const Key &key) noexcept { return tree_.contains(key); }

  iterator find(const Key &key) noexcept { return tree_.find(key); };

 private:
  tree_type tree_;
  Allocator alloc_;
  Compare compare_;
};
}  // namespace s21

#endif

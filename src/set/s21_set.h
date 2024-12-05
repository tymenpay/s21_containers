#ifndef CPP_S21_SET_H
#define CPP_S21_SET_H

#include <initializer_list>
#include <iostream>
#include <iterator>
#include <memory>
#include <utility>

#include "../map/s21_rb_tree.h"

namespace s21 {
template <typename Key, class Compare = std::less<Key>,
          class Allocator = std::allocator<Key>>
class set {
 public:
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = RBIterator<Key, Key, Compare, false>;
  using const_iterator = RBIterator<Key, Key, Compare, true>;
  using size_type = size_t;
  using tree_type = RBTree<Key, Key, Compare, Allocator>;
  using traits = std::allocator_traits<Allocator>;

  set() noexcept {};
  set(std::initializer_list<value_type> const &items) {
    for (auto i = items.begin(); i < items.end(); ++i) {
      insert(*i);
    }
  }
  set(const set &s)
      : tree_(s.tree_),
        alloc_(traits::select_on_container_copy_construction(s.alloc_)),
        comp_(s.comp_) {}
  set(set &&s)
      : tree_(),
        alloc_(traits::select_on_container_copy_construction(s.alloc_)),
        comp_(std::move(s.comp_)) {
    tree_.Move(std::move(s.tree_));
  }
  ~set() noexcept = default;

  set &operator=(set &&s) noexcept {
    if (this != &s) {
      tree_.Move(std::move(s.tree_));
    }
    return *this;
  }

  iterator begin() { return tree_.begin(); }
  const_iterator cbegin() { return tree_.cbegin(); }
  iterator end() { return tree_.end(); }
  const_iterator cend() { return tree_.cend(); }

  bool empty() noexcept { return tree_.empty(); }
  size_type size() const noexcept { return tree_.size(); }
  size_type max_size() const noexcept { return traits::max_size(alloc_); }

  void clear() noexcept { tree_.clear(); }
  std::pair<iterator, bool> insert(const value_type &value) {
    iterator it = find(value);

    if (it != end()) {
      return std::make_pair<iterator, bool>(iterator(it), false);
    } else {
      return tree_.insert(value, value);
    }
  }
  void erase(iterator pos) noexcept {
    iterator it = find((*pos).first);

    if (it != end()) {
      tree_.erase(pos);
    }
  }

  void swap(set &other) noexcept { tree_.swap(other.tree_); }

  void merge(set &other) noexcept {
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
  Compare comp_;
};

}  // namespace s21

#endif
#ifndef CPP_S21_STACK_H
#define CPP_S21_STACK_H

#include <initializer_list>
#include <iostream>
#include <iterator>
#include <memory>

namespace s21 {
template <typename T>
struct Node {
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;

  value_type value_;
  Node *next_;

  Node() noexcept : value_(value_type{}), next_(this){};
  explicit Node(const_reference value) noexcept
      : value_(value), next_(nullptr){};
};
template <typename T, class Alloc = std::allocator<T>>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  using NodeType = Node<T>;
  using NodeAllocator =
      typename std::allocator_traits<Alloc>::template rebind_alloc<NodeType>;
  using NodeAllocatorTraits =
      typename std::allocator_traits<Alloc>::template rebind_traits<NodeType>;

  stack() : head_(nullptr), size_(0) {}
  stack(std::initializer_list<value_type> const &items) : stack() {
    for (auto i : items) {
      push(i);
    }
  }
  stack(const stack &s)
      : head_(nullptr),
        size_(0),
        alloc_(NodeAllocatorTraits::select_on_container_copy_construction(
            s.alloc_)) {
    if (s.head_) {
      NodeType *current = s.head_;
      NodeType *last = nullptr;
      while (current) {
        NodeType *new_node = Allocate(current->value_);
        if (!head_) {
          head_ = new_node;
        } else {
          last->next_ = new_node;
        }
        last = new_node;
        current = current->next_;
      }
    }
  }
  stack(stack &&s) noexcept : head_(s.head_), size_(s.size_) {
    s.head_ = nullptr;
    s.size_ = 0;
  }
  ~stack() {
    while (head_ != nullptr) {
      pop();
    }
    size_ = 0;
    head_ = nullptr;
  }

  stack &operator=(const stack &s) {
    if (this != &s) {
      clear();
      if (s.head_) {
        NodeType *current = s.head_;
        NodeType *last = nullptr;
        while (current) {
          NodeType *new_node = Allocate(current->value_);
          if (!head_) {
            head_ = new_node;
          } else {
            last->next_ = new_node;
          }
          last = new_node;
          current = current->next_;
        }
      }
    }
    return *this;
  }
  stack &operator=(stack &&s) noexcept {
    if (this != &s) {
      clear();
      head_ = s.head_;
      size_ = s.size_;
      alloc_ = std::move(s.alloc_);
    }
    s.head_ = nullptr;
    s.size_ = 0;
    return *this;
  }

  void clear() {
    NodeType *current = head_;
    while (current != nullptr) {
      NodeType *next = current->next_;
      NodeAllocatorTraits::destroy(alloc_, current);
      NodeAllocatorTraits::deallocate(alloc_, current, 1);
      current = next;
    }
    head_ = nullptr;
    size_ = 0;
  }

  const_reference top() const { return head_->value_; }
  bool empty() const { return (head_ == nullptr && size_ == 0); }
  size_type size() const { return size_; }

  void push(const_reference value) {
    NodeType *New_node = Allocate(value);
    if (head_ != nullptr) {
      New_node->next_ = head_;
    }
    head_ = New_node;
    ++size_;
  }

  void pop() {
    if (head_ == nullptr)
      return;
    else {
      NodeType *New_node = head_;
      head_ = New_node->next_;
      NodeAllocatorTraits::destroy(alloc_, New_node);
      NodeAllocatorTraits::deallocate(alloc_, New_node, 1);
      --size_;
    }
  }

  void swap(stack &other) noexcept {
    if (this != &other) {
      std::swap(this->size_, other.size_);
      std::swap(this->alloc_, other.alloc_);
      std::swap(this->head_, other.head_);
    }
  }

  void reverse() {
    if (!empty()) {
      NodeType *current = head_;
      NodeType *prev = nullptr;
      NodeType *next = nullptr;

      while (current != nullptr) {
        next = current->next_;
        current->next_ = prev;
        prev = current;
        current = next;
      }

      head_ = prev;
    }
  }

  // bonus part
  template <typename... Args>
  void insert_many_back(Args &&...args) {
    (push(std::forward<Args>(args)), ...);
  }

 private:
  NodeType *head_;
  size_type size_;

  NodeAllocator alloc_;

  NodeType *Allocate(const_reference value) {
    NodeType *node = NodeAllocatorTraits::allocate(alloc_, 1);
    NodeAllocatorTraits::construct(alloc_, node, value);
    return node;
  }
  void Deallocate(NodeType *node) {
    NodeAllocatorTraits::destroy(alloc_, node);
    NodeAllocatorTraits::deallocate(alloc_, node, 1);
  }
};
}  // namespace s21

#endif

#ifndef CPP_S21_QUEUE_H
#define CPP_S21_QUEUE_H

#include <initializer_list>
#include <iostream>
#include <iterator>
#include <memory>
#include <utility>

namespace s21 {
template <typename T>
struct Node {
  using value_type = T;
  using const_reference = const T &;
  value_type value_;
  Node *prev_;
  Node *next_;

  Node() noexcept : value_(value_type{}), prev_(this), next_(this){};
  explicit Node(const_reference value) noexcept
      : value_(value), prev_(nullptr), next_(nullptr){};
};

template <typename T, bool is_const>
class QueueIterator;

template <typename T, class Alloc = std::allocator<T>>
class queue {
  friend class QueueIterator<T, true>;
  friend class QueueIterator<T, false>;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;
  using traits = std::allocator_traits<Alloc>;

  using NodeType = Node<T>;
  using NodeAllocator =
      typename std::allocator_traits<Alloc>::template rebind_alloc<NodeType>;
  using NodeAllocatorTraits =
      typename std::allocator_traits<Alloc>::template rebind_traits<NodeType>;

  queue() : head_(nullptr), tail_(nullptr), size_(0) {}

  queue(std::initializer_list<value_type> const &items) : queue() {
    for (auto &i : items) {
      push(i);
    }
  }

  queue(const queue &q)
      : head_(nullptr),
        tail_(nullptr),
        size_(0),
        alloc_(NodeAllocatorTraits::select_on_container_copy_construction(
            q.alloc_)) {
    NodeType *current = q.head_;
    if (current) {
      do {
        push(current->value_);
        current = current->next_;
      } while (current != q.head_);
    }
  }

  queue(queue &&q) noexcept
      : head_(q.head_),
        tail_(q.tail_),
        size_(q.size_),
        alloc_(std::move(q.alloc_)) {
    q.size_ = 0;
    q.head_ = nullptr;
    q.tail_ = nullptr;
  }

  ~queue() { clear(); }

  queue &operator=(const queue &q) {
    if (this != &q) {
      clear();
      alloc_ =
          NodeAllocatorTraits::select_on_container_copy_construction(q.alloc_);
      NodeType *current = q.head_;
      while (current) {
        push(current->value_);
        current = current->next_;
        if (current == q.head_) break;
      }
    }
    return *this;
  }

  queue operator=(queue &&q) noexcept {
    if (this != &q) {
      clear();

      alloc_ = std::move(q.alloc_);
      head_ = q.head_;
      tail_ = q.tail_;
      size_ = q.size_;

      q.head_ = nullptr;
      q.tail_ = nullptr;
      q.size_ = 0;
    }
    return *this;
  }
  const_reference front() const { return head_->value_; }
  const_reference back() const { return tail_->value_; }

  bool empty() { return (size_ == 0 && head_ == nullptr) ? true : false; }
  size_type size() { return size_; }

  void push(const_reference value) {
    NodeType *node = Allocate(value);
    if (!head_) {
      head_ = tail_ = node;
      node->prev_ = node->next_ = node;
    } else {
      node->prev_ = tail_;
      node->next_ = head_;
      tail_->next_ = node;
      head_->prev_ = node;
      tail_ = node;
    }
    ++size_;
  }

  void pop() {
    if (size_ > 0) {
      NodeType *node = head_;
      if (head_ == tail_) {
        head_ = tail_ = nullptr;
      } else {
        head_ = head_->next_;
      }
      NodeAllocatorTraits::destroy(alloc_, node);
      NodeAllocatorTraits::deallocate(alloc_, node, 1);
      --size_;
    }
  }

  void swap(queue &other) {
    std::swap(size_, other.size_);
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(alloc_, other.alloc_);
  }

 private:
  NodeType *head_;
  NodeType *tail_;
  size_type size_;

  NodeAllocator alloc_;
  NodeType *Allocate(const_reference value) {
    NodeType *node = NodeAllocatorTraits::allocate(alloc_, 1);
    NodeAllocatorTraits::construct(alloc_, node, value);
    return node;
  }

  void clear() {
    if (head_ != nullptr && size_ > 0) {
      while (size_ > 0) {
        pop();
      }
      head_ = tail_ = nullptr;
    }
  }
};

}  // namespace s21

#endif
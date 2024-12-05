#ifndef CPP_S21_LIST_H
#define CPP_S21_LIST_H

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
  Node *prev_;
  Node *next_;

  Node() noexcept : value_(value_type{}), prev_(this), next_(this){};
  explicit Node(const_reference value) noexcept
      : value_(value), prev_(nullptr), next_(nullptr){};
};
template <typename T, bool is_const>
class ListIterator;

template <typename T, class Alloc = std::allocator<T>>
class list {
 private:
  friend class ListIterator<T, true>;
  friend class ListIterator<T, false>;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  using iterator = ListIterator<T, false>;
  using const_iterator = ListIterator<T, true>;

  using NodeType = Node<T>;
  using NodeAllocator =
      typename std::allocator_traits<Alloc>::template rebind_alloc<NodeType>;
  using NodeAllocatorTraits =
      typename std::allocator_traits<Alloc>::template rebind_traits<NodeType>;

  list() : head_(nullptr), tail_(nullptr), size_(0) {}
  explicit list(size_type size) : list() {
    for (size_type i = 0; i < size; ++i) push_back(value_type{});
  }

  list(std::initializer_list<value_type> const &init) : list() {
    for (auto value : init) push_back(value);
  }
  list(const list &l) : list() {
    if (!l.empty()) {
      for (auto value : l) push_back(value);
    }
  }
  list(list &&l) noexcept : head_(l.head_), tail_(l.tail_), size_(l.size_) {
    l.head_ = nullptr;
    l.tail_ = nullptr;
    l.size_ = 0;
  }

  ~list() { clear(); }

  list &operator=(const list &l) {
    if (this != &l) {
      this->clear();
      for (auto value : l) {
        push_back(value);
      }
    }
    return *this;
  }
  list &operator=(list &&l) noexcept {
    if (this != &l) {
      clear();
      head_ = l.head_;
      tail_ = l.tail_;
      size_ = l.size_;
      l.head_ = nullptr;
      l.tail_ = nullptr;
      l.size_ = 0;
    }
    return *this;
  }

  const_reference front() const { return head_->value_; }
  const_reference back() const { return tail_->value_; };

  iterator begin() { return iterator(head_, this); }
  const_iterator begin() const { return const_iterator(head_, this); }

  iterator end() { return iterator(nullptr, this); }
  const_iterator end() const { return const_iterator(nullptr, this); }

  const_iterator cbegin() const { return const_iterator(head_); };
  const_iterator cend() const { return const_iterator(nullptr); };

  bool empty() const { return head_ == nullptr; };
  size_type size() { return size_; };
  size_type max_size() { return NodeAllocatorTraits::max_size(alloc_); };

  void clear() {
    if (!empty()) {
      NodeType *current = head_;
      while (current) {
        NodeType *next = current->next_;
        NodeAllocatorTraits::destroy(alloc_, current);
        NodeAllocatorTraits::deallocate(alloc_, current, 1);
        current = next;
      }
    }
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
  }

  iterator insert(iterator pos, const_reference value) {
    if (pos.getNode() == tail_ || pos.getNode() == nullptr) {
      push_back(value);
      return iterator(tail_);
    }

    NodeType *new_Node = Allocate(value);
    NodeType *temp = pos.getNode();

    new_Node->next_ = temp;

    if (temp->prev_) {
      new_Node->prev_ = temp->prev_;
      temp->prev_->next_ = new_Node;
    } else {
      head_ = new_Node;
    }

    temp->prev_ = new_Node;
    size_++;

    return iterator(new_Node);
  }
  void erase(iterator pos) {
    if (pos.getNode() == tail_) {
      pop_back();
    } else if (pos == begin()) {
      pop_front();
    } else {
      NodeType *old_Node = pos.getNode();
      old_Node->prev_->next_ = old_Node->next_;
      old_Node->next_->prev_ = old_Node->prev_;
      NodeAllocatorTraits::destroy(alloc_, old_Node);
      NodeAllocatorTraits::deallocate(alloc_, old_Node, 1);
      size_--;
    }
  }
  void push_front(const_reference value) {
    NodeType *New_Node = Allocate(value);
    New_Node->prev_ = nullptr;

    if (head_ == nullptr) {
      tail_ = New_Node;
      New_Node->next_ = nullptr;
    } else {
      New_Node->next_ = head_;
      head_->prev_ = New_Node;
    }

    head_ = New_Node;
    size_++;
  }
  void push_back(const_reference value) {
    NodeType *node = Allocate(value);
    if (!head_) {
      head_ = tail_ = node;

    } else {
      node->prev_ = tail_;
      tail_->next_ = node;
      tail_ = node;
    }
    ++size_;
  }
  void pop_front() {
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
  void pop_back() {
    if (size_ > 0) {
      NodeType *node = tail_;
      if (head_ == tail_) {
        head_ = tail_ = nullptr;
      } else {
        tail_ = tail_->prev_;
        tail_->next_ = nullptr;
      }
      NodeAllocatorTraits::destroy(alloc_, node);
      NodeAllocatorTraits::deallocate(alloc_, node, 1);
      --size_;
    }
  }
  void swap(list &other) noexcept {
    if (this != &other) {
      std::swap(this->size_, other.size_);
      std::swap(this->head_, other.head_);
      std::swap(this->tail_, other.tail_);
    }
  }

  void merge(list &other) {
    if (!other.empty()) {
      auto it1 = this->head_;
      auto it2 = other.head_;
      if (!it1) {
        head_ = other.head_;
        tail_ = other.tail_;
        size_ = other.size_;
      } else {
        NodeType *merged_head = nullptr;
        NodeType *merged_tail = nullptr;
        if (it1->value_ <= it2->value_) {
          merged_head = it1;
          it1 = it1->next_;
        } else {
          merged_head = it2;
          it2 = it2->next_;
        }
        merged_tail = merged_head;
        while (it1 && it2) {
          if (it1->value_ <= it2->value_) {
            merged_tail->next_ = it1;
            it1->prev_ = merged_tail;
            it1 = it1->next_;
          } else {
            merged_tail->next_ = it2;
            it2->prev_ = merged_tail;
            it2 = it2->next_;
          }
          merged_tail = merged_tail->next_;
        }
        if (it1) {
          merged_tail->next_ = it1;
          it1->prev_ = merged_tail;
        } else if (it2) {
          merged_tail->next_ = it2;
          it2->prev_ = merged_tail;
        }
        head_ = merged_head;
        tail_ = it1 ? tail_ : other.tail_;
      }

      size_ += other.size_;
      other.head_ = nullptr;
      other.tail_ = nullptr;
      other.size_ = 0;
    }
  }

  void splice(iterator pos, list &other) {
    if (!other.empty()) {
      NodeType *temp = pos.getNode();

      if (this->empty()) {
        this->head_ = other.head_;
        this->tail_ = other.tail_;
      } else if (pos == begin()) {
        other.tail_->next_ = temp;
        temp->prev_ = other.tail_;
        head_ = other.head_;
      } else {
        if (temp->next_ == nullptr) {
          this->tail_ = temp;
        }
        other.head_->prev_ = temp->prev_;
        temp->prev_->next_ = other.head_;
        other.tail_->next_ = temp;
        temp->prev_ = other.tail_;
      }
      this->size_ += other.size_;
      other.head_ = nullptr;
      other.tail_ = nullptr;
      other.size_ = 0;
    }
  }
  void reverse() {
    if (!empty()) {
      NodeType *current = this->head_;
      NodeType *temp = nullptr;

      while (current != nullptr) {
        temp = current->prev_;
        current->prev_ = current->next_;
        current->next_ = temp;

        current = current->prev_;  // current->next_
      }

      temp = this->head_;
      this->head_ = this->tail_;
      this->tail_ = temp;
    }
  }
  void unique() {
    if (head_) {
      NodeType *current = head_;

      while (current->next_) {
        if (current->value_ == current->next_->value_) {
          NodeType *to_delete = current->next_;
          current->next_ = to_delete->next_;

          if (to_delete->next_) {
            to_delete->next_->prev_ = current;
          } else {
            tail_ = current;
          }

          Deallocate(to_delete);
          --size_;
        } else {
          current = current->next_;
        }
      }
    }
  }
  NodeType *get_tail() const { return tail_; }

  void sort() {
    if (empty()) return;

    bool is_swap = true;
    NodeType *end = nullptr;

    while (is_swap) {
      is_swap = false;
      NodeType *current = head_;

      while (current->next_ != end) {
        if (current->value_ > current->next_->value_) {
          swap_pos(current, current->next_);
          is_swap = true;
        } else {
          current = current->next_;
        }
      }

      end = current;
    }
  }

  /* bonus part */
  template <typename... Args>
  iterator insert_many(iterator pos, Args &&...args) {
    iterator iter(pos.getNode());
    (..., (iter = insert(iter, std::forward<Args>(args)),
           ++iter));
    return --iter;
  }

  template <typename... Args>
  void insert_many_back(Args &&...args) {
    (push_back(std::forward<Args>(args)), ...);
  }

  template <typename... Args>
  void insert_many_front(Args &&...args) {
    (push_front(std::forward<Args>(args)), ...);
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

  void Deallocate(NodeType *node) {
    NodeAllocatorTraits::destroy(alloc_, node);
    NodeAllocatorTraits::deallocate(alloc_, node, 1);
  }

  void swap_pos(NodeType *node1, NodeType *node2) {
    if (node1 == node2) return;

    NodeType *prev1 = node1->prev_;
    NodeType *next2 = node2->next_;

    if (prev1) {
      prev1->next_ = node2;
    } else {
      head_ = node2;
    }
    if (next2) {
      next2->prev_ = node1;
    } else {
      tail_ = node1;
    }

    node2->prev_ = prev1;
    node2->next_ = node1;
    node1->prev_ = node2;
    node1->next_ = next2;
  }
};

template <typename T, bool is_const>
class ListIterator {
 public:
  friend struct Node<T>;
  friend class list<T>;

  using value_type = T;
  using pointer = typename std::conditional<is_const, const T *, T *>::type;
  using reference = typename std::conditional<is_const, const T &, T &>::type;

  using node_type = Node<T>;

  using conditional_node_ptr =
      typename std::conditional<is_const, const node_type *, node_type *>::type;
  using conditional_node_ref =
      typename std::conditional<is_const, const node_type &, node_type &>::type;

  ListIterator() : current_(nullptr) {}
  explicit ListIterator(conditional_node_ptr node,
                        const list<T> *list_ptr = nullptr)
      : current_(node), list_ptr_(list_ptr) {}

  reference operator*() { return current_->value_; }
  pointer operator->() { return &current_->value_; }

  ListIterator &operator++() {
    current_ = current_->next_;
    return *this;
  }

  ListIterator operator++(int) {
    ListIterator temp = *this;
    current_ = current_->next_;
    return temp;
  }

  ListIterator &operator--() {
    if (current_ == nullptr) {
      current_ = list_ptr_->get_tail();
    } else {
      current_ = current_->prev_;
    }
    return *this;
  }

  ListIterator operator--(int) {
    ListIterator temp = *this;
    if (current_ == nullptr) {
      current_ = list_ptr_->get_tail();
    } else {
      current_ = current_->prev_;
    }
    return temp;
  }

  bool operator==(const ListIterator &other) const {
    return current_ == other.current_;
  }

  bool operator!=(const ListIterator &other) const {
    return current_ != other.current_;
  }

  conditional_node_ptr getNode() const { return current_; }

 private:
  conditional_node_ptr current_;
  const list<T> *list_ptr_;
};

}  // namespace s21

#endif
#ifndef S21_CONTAINER_SRC_SET_RBTREE_H_
#define S21_CONTAINER_SRC_SET_RBTREE_H_

#include <initializer_list>
#include <iostream>
#include <iterator>
#include <memory>

enum color_t { RED_NODE, BLACK_NODE };

template <typename Key, typename T>
class RBNode {
  using value_type = std::pair<const Key, T>;

 public:
  value_type* value_;
  RBNode* parent_;
  RBNode* left_;
  RBNode* right_;
  color_t color_;

  RBNode(value_type* val, RBNode* p, RBNode* l, RBNode* r, color_t color)
      : value_(val), parent_(p), color_(color), left_(l), right_(r){};

  bool operator==(RBNode<Key, T>& other) const noexcept {
    return (value_ == other.value_);
  }

  bool operator!=(RBNode<Key, T>& other) const noexcept {
    return (value_ != other.value_);
  }
};

template <typename Key, typename T, typename Compare, bool is_const>
class RBIterator;

template <typename Key, typename T, typename Compare = std::less<Key>,
          typename Allocator = std::allocator<T>>
class RBTree {
  friend class RBNode<Key, T>;
  friend class RBIterator<Key, T, Compare, true>;
  friend class RBIterator<Key, T, Compare, false>;

 public:
  using value_type = std::pair<const Key, T>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using pointer = value_type*;
  using const_pointer = const value_type*;
  using iterator = RBIterator<Key, T, Compare, false>;
  using const_iterator = RBIterator<Key, T, Compare, true>;
  using size_type = size_t;
  using node_type = RBNode<Key, T>;
  using KeyCompare = std::less<Key>;

  using NodeAlloc = typename std::allocator_traits<
      Allocator>::template rebind_alloc<RBNode<Key, T>>;
  using ValAlloc = typename std::allocator_traits<
      Allocator>::template rebind_alloc<std::pair<const Key, T>>;
  using node_traits = std::allocator_traits<NodeAlloc>;
  using val_traits = std::allocator_traits<ValAlloc>;

 private:
  ValAlloc val_alloc_;
  NodeAlloc node_alloc_;
  Compare compare_;
  node_type* root_;
  size_type size_;

 public:
  RBTree()
      : val_alloc_(), node_alloc_(), compare_(), root_(nullptr), size_(0) {}

  RBTree(const RBTree<Key, T>& other) : root_(nullptr), size_(0) {
    auto it = other.cbegin();
    for (size_type i = 0; i < other.size_; ++i) {
      if (it == other.cend()) {
        break;
      }
      insert((*it).first, (*it).second);
      it++;
    }
  }

  ~RBTree() noexcept {
    if (!empty() && size_ != 0) {
      DeallocateDestroyTree(root_);
    }
    size_ = 0;
    root_ = nullptr;
  }

  std::pair<iterator, bool> insert(const Key& key, const T& value) {
    node_type* new_Node = nullptr;
    try {
      new_Node = allocate_node(key, value);
      size_++;
    } catch (...) {
      if (new_Node) {
        node_traits::deallocate(node_alloc_, new_Node, 1);
      }
      throw;
    }
    if (empty()) {
      new_Node->color_ = BLACK_NODE;
      root_ = new_Node;
      return std::make_pair<iterator, bool>(begin(), true);
    }
    node_type* parent = nullptr;
    node_type* current = root_;
    while (current != nullptr) {
      parent = current;
      if (compare_(key, current->value_->first)) {
        current = current->left_;
      } else if (compare_(current->value_->first, key)) {
        current = current->right_;
      } else {
        node_traits::destroy(node_alloc_, new_Node);
        node_traits::deallocate(node_alloc_, new_Node, 1);
        --size_;
        return {iterator(current, this), false};
      }
    }
    if (parent) {
      new_Node->parent_ = parent;
      if (compare_(key, parent->value_->first)) {
        parent->left_ = new_Node;
      } else {
        parent->right_ = new_Node;
      }

      if (new_Node->parent_->color_ == RED_NODE) {
        balanceAfterInsert(new_Node);
      }
    }
    return std::make_pair<iterator, bool>(iterator(new_Node, this), true);
  }

  // https://habr.com/ru/articles/573502/
  void erase(iterator pos) noexcept {
    if (pos == end()) {
      return;
    }

    node_type* del_node = find((*pos).first).itr_node_;
    color_t del_color = del_node->color_;
    if (del_node == root_ && size_ == 1) {
      dealloc(del_node);
      size_ = 0;
      return;
    }
    if (del_color == RED_NODE && del_node->left_ == nullptr &&
        del_node->right_ == nullptr) {
      (del_node->parent_->left_ == del_node)
          ? del_node->parent_->left_ = nullptr
          : del_node->parent_->right_ = nullptr;
      dealloc(del_node);
    } else if (del_color == BLACK_NODE && del_node->left_ == nullptr &&
               del_node->right_ == nullptr) {
      Rebalancing_tree(del_node, del_node->parent_);
      (del_node->parent_->left_ == del_node)
          ? del_node->parent_->left_ = nullptr
          : del_node->parent_->right_ = nullptr;
      dealloc(del_node);
    } else if (del_node->right_ != nullptr && del_node->left_ != nullptr) {
      node_type* min_node = min(del_node->right_);
      Replace(del_node, min_node);
      if (del_node->left_ == nullptr && del_node->right_ == nullptr) {
        if (del_node->color_ == RED_NODE) {
          (del_node->parent_->left_ == del_node)
              ? del_node->parent_->left_ = nullptr
              : del_node->parent_->right_ = nullptr;
          dealloc(del_node);
        } else {
          Rebalancing_tree(del_node, del_node->parent_);
          (del_node->parent_->left_ == del_node)
              ? del_node->parent_->left_ = nullptr
              : del_node->parent_->right_ = nullptr;
          dealloc(del_node);
        }
      } else {
        Replace(del_node, (del_node->left_ == nullptr) ? del_node->right_
                                                       : del_node->left_);
        if (del_node->color_ == BLACK_NODE) {
          Rebalancing_tree(del_node, del_node->parent_);
          (del_node->parent_->left_ == del_node)
              ? del_node->parent_->left_ = nullptr
              : del_node->parent_->right_ = nullptr;
          dealloc(del_node);
        } else {
          (del_node->parent_->left_ == del_node)
              ? del_node->parent_->left_ = nullptr
              : del_node->parent_->right_ = nullptr;
          dealloc(del_node);
        }
      }
    } else if (del_node->color_ == BLACK_NODE &&
               (del_node->left_ != nullptr || del_node->right_ != nullptr)) {
      Replace(del_node, (del_node->left_ == nullptr) ? del_node->right_
                                                     : del_node->left_);
      if (del_node->color_ == BLACK_NODE) {
        Rebalancing_tree(del_node, del_node->parent_);
        (del_node->parent_->left_ == del_node)
            ? del_node->parent_->left_ = nullptr
            : del_node->parent_->right_ = nullptr;
        dealloc(del_node);
      } else {
        (del_node->parent_->left_ == del_node)
            ? del_node->parent_->left_ = nullptr
            : del_node->parent_->right_ = nullptr;
        dealloc(del_node);
      }
    }
    --size_;
  }

  iterator find(const Key& key) noexcept {
    if (!empty()) {
      for (iterator itr = begin(); itr != end(); ++itr) {
        if ((*itr).first == key) {
          return itr;
        }
      }
    }
    return end();
  }

  bool contains(const Key& key) noexcept {
    if (!empty()) {
      for (const_iterator itr = cbegin(); itr != cend(); ++itr) {
        if ((*itr).first == key) {
          return true;
        }
      }
    }
    return false;
  }

  node_type* min() const noexcept {
    node_type* parent = root_;
    node_type* next = nullptr;
    while (parent->left_ != nullptr) {
      next = parent;
      parent = next->left_;
    }
    return parent;
  }

  node_type* max() const noexcept {
    node_type* parent = root_;
    node_type* next = nullptr;
    while (parent->right_ != nullptr) {
      next = parent;
      parent = next->right_;
    }
    return parent;
  }

  iterator begin() noexcept {
    node_type* begin_ = root_;
    while (begin_ != nullptr && begin_->left_ != nullptr) {
      begin_ = begin_->left_;
    }
    auto iter = iterator(
        static_cast<typename iterator::conditional_node_ptr>(begin_),
        reinterpret_cast<typename iterator::conditional_tree_ptr>(this));

    return iter;
  }

  const_iterator cbegin() const noexcept {
    node_type* begin = root_;
    while (begin != nullptr && begin->left_ != nullptr) {
      begin = begin->left_;
    }
    auto iter = const_iterator(begin, this);
    return iter;
  }

  iterator end() noexcept { return iterator(nullptr, this); };

  const_iterator cend() const noexcept { return const_iterator(nullptr, this); }

  size_type size() const noexcept { return size_; }

  bool empty() { return (root_ == nullptr) ? true : false; }

  void swap(RBTree<Key, T, Compare>& other) {
    std::swap(val_alloc_, other.val_alloc_);
    std::swap(node_alloc_, other.node_alloc_);
    std::swap(compare_, other.compare_);
    std::swap(root_, other.root_);
    std::swap(size_, other.size_);
  }

  void Move(RBTree<Key, T, Compare>&& other) noexcept {
    root_ = other.root_;
    size_ = other.size_;
    val_alloc_ = other.val_alloc_;
    node_alloc_ = other.node_alloc_;
    compare_ = other.compare_;
    other.root_ = nullptr;
    other.size_ = 0;
  };
  void clear() noexcept {
    if (!empty()) {
      DeallocateDestroyTree(root_);
    }
    size_ = 0;
    root_ = nullptr;
  }

 private:
  node_type* allocate_node(const Key& key, const T& value) {
    node_type* new_node = nullptr;
    new_node = node_traits::allocate(node_alloc_, 1);
    try {
      new_node->value_ = val_traits::allocate(val_alloc_, 1);
      val_traits::construct(val_alloc_, std::addressof(new_node->value_->first),
                            std::move_if_noexcept(key));
      val_traits::construct(val_alloc_,
                            std::addressof(new_node->value_->second),
                            std::move_if_noexcept(value));
      new_node->left_ = nullptr;
      new_node->right_ = nullptr;
      new_node->parent_ = nullptr;
      node_traits::construct(node_alloc_, std::addressof(new_node->color_),
                             RED_NODE);

    } catch (...) {
      node_traits::deallocate(node_alloc_, new_node, 1);
      throw;
    }
    return new_node;
  }

  void DeallocateDestroyTree(node_type* ptr) {
    if (ptr == nullptr) {
      return;
    }

    if (ptr->left_ != nullptr) {
      DeallocateDestroyTree(ptr->left_);
    }

    if (ptr->right_ != nullptr) {
      DeallocateDestroyTree(ptr->right_);
    }

    dealloc(ptr);
  }

  void dealloc(node_type* node) noexcept {
    node->right_ = nullptr;
    node->left_ = nullptr;
    node->parent_ = nullptr;
    val_traits::destroy(val_alloc_, std::addressof(node->value_->first));
    val_traits::destroy(val_alloc_, std::addressof(node->value_->second));
    val_traits::deallocate(val_alloc_, node->value_, 1);
    node_traits::destroy(node_alloc_, node);
    node_traits::deallocate(node_alloc_, node, 1);
    node = nullptr;
  }

  void balanceAfterInsert(node_type* new_Node) {
    while (new_Node != root_ && new_Node->parent_->color_ == RED_NODE) {
      node_type* parent = new_Node->parent_;
      node_type* grandparent = parent->parent_;
      if (grandparent == nullptr) {
        break;
      }
      node_type* uncle = (parent == grandparent->left_) ? grandparent->right_
                                                        : grandparent->left_;
      if (uncle != nullptr && uncle->color_ == RED_NODE) {
        parent->color_ = BLACK_NODE;
        uncle->color_ = BLACK_NODE;
        grandparent->color_ = RED_NODE;
        new_Node = grandparent;
      } else {
        if (new_Node == parent->right_ && parent == grandparent->left_) {
          leftRotate(parent);
          new_Node = parent;
          parent = new_Node->parent_;
        }
        if (new_Node == parent->left_ && parent == grandparent->left_) {
          rightRotate(grandparent);
          std::swap(parent->color_, grandparent->color_);
          new_Node = parent;
        } else if (new_Node == parent->left_ && parent == grandparent->right_) {
          rightRotate(parent);
          new_Node = parent;
        } else {
          leftRotate(grandparent);
          std::swap(parent->color_, grandparent->color_);
          new_Node = parent;
        }
      }
    }
    root_->color_ = BLACK_NODE;
  }
  void leftRotate(node_type* node) {
    node_type* temp = node->right_;

    node->right_ = temp->left_;
    if (temp->left_ != nullptr) {
      temp->left_->parent_ = node;
    }
    temp->parent_ = node->parent_;
    if (node->parent_ == nullptr) {
      root_ = temp;
    } else if (node == node->parent_->left_) {
      node->parent_->left_ = temp;
    } else {
      node->parent_->right_ = temp;
    }
    temp->left_ = node;
    node->parent_ = temp;
  }

  void rightRotate(node_type* node) {
    node_type* temp = node->left_;

    node->left_ = temp->right_;
    if (temp->right_ != nullptr) {
      temp->right_->parent_ = node;
    }
    temp->parent_ = node->parent_;
    if (node->parent_ == nullptr) {
      root_ = temp;
    } else if (node == node->parent_->right_) {
      node->parent_->right_ = temp;
    } else {
      node->parent_->left_ = temp;
    }
    temp->right_ = node;
    node->parent_ = temp;
  }
  void Rebalancing_tree(node_type* del_node, node_type* parent_node) noexcept {
    node_type* brother_node = nullptr;

    if (parent_node == root_ && size_ == 2) {
      if (parent_node->left_ == del_node) {
        if (parent_node->right_ != nullptr) {
          parent_node->right_->color_ = RED_NODE;
        }
      } else {
        if (parent_node->left_ != nullptr) {
          parent_node->left_->color_ = RED_NODE;
        }
      }
      return;
    }

    while (del_node != root_ &&
           (del_node == nullptr || del_node->color_ == BLACK_NODE)) {
      if (del_node == parent_node->left_) {
        brother_node = parent_node->right_;
        if (brother_node->color_ == RED_NODE) {
          parent_node->color_ = RED_NODE;
          brother_node->color_ = BLACK_NODE;
          leftRotate(parent_node);
          brother_node = parent_node->right_;
        }
        if ((brother_node->left_ == nullptr ||
             brother_node->left_->color_ == BLACK_NODE) &&
            (brother_node->right_ == nullptr ||
             brother_node->right_->color_ == BLACK_NODE)) {
          brother_node->color_ = RED_NODE;
          del_node = parent_node;
          parent_node = parent_node->parent_;
        } else {
          if (brother_node->right_ == nullptr ||
              brother_node->right_->color_ == BLACK_NODE) {
            if (brother_node->left_) brother_node->left_->color_ = BLACK_NODE;
            brother_node->color_ = RED_NODE;
            rightRotate(brother_node);
            brother_node = parent_node->right_;
          }
          brother_node->color_ = parent_node->color_;
          parent_node->color_ = BLACK_NODE;
          if (brother_node->right_) brother_node->right_->color_ = BLACK_NODE;
          leftRotate(parent_node);
          del_node = root_;
        }
      } else {
        brother_node = parent_node->left_;
        if (brother_node->color_ == RED_NODE) {
          parent_node->color_ = RED_NODE;
          brother_node->color_ = BLACK_NODE;
          rightRotate(parent_node);
          brother_node = parent_node->left_;
        }
        if ((brother_node->right_ == nullptr ||
             brother_node->right_->color_ == BLACK_NODE) &&
            (brother_node->left_ == nullptr ||
             brother_node->left_->color_ == BLACK_NODE)) {
          brother_node->color_ = RED_NODE;
          del_node = parent_node;
          parent_node = parent_node->parent_;
        } else {
          if (brother_node->left_ == nullptr ||
              brother_node->left_->color_ == BLACK_NODE) {
            if (brother_node->right_) brother_node->right_->color_ = BLACK_NODE;
            brother_node->color_ = RED_NODE;
            leftRotate(brother_node);
            brother_node = parent_node->left_;
          }
          brother_node->color_ = parent_node->color_;
          parent_node->color_ = BLACK_NODE;
          if (brother_node->left_) brother_node->left_->color_ = BLACK_NODE;
          rightRotate(parent_node);
          del_node = root_;
        }
      }
    }
    if (del_node) del_node->color_ = BLACK_NODE;
  }
  node_type* min(node_type* node) noexcept {
    node_type* current = node;
    while (current->left_ != nullptr) {
      current = current->left_;
    }
    return current;
  }
  void Replace(node_type* x_node, node_type* y_node) noexcept {
    node_type* x_parent = x_node->parent_;
    node_type* x_left = x_node->left_;
    node_type* x_right = x_node->right_;
    color_t x_color = x_node->color_;

    if (x_node->parent_ == nullptr) {
      root_ = y_node;
      root_->color_ = BLACK_NODE;
    } else if (x_node == x_node->parent_->left_) {
      x_node->parent_->left_ = y_node;
    } else {
      x_node->parent_->right_ = y_node;
    }

    if (y_node != nullptr) {
      x_node->color_ = y_node->color_;
      if (x_node == y_node->parent_) {
        x_node->parent_ = y_node;
      } else {
        x_node->parent_ = y_node->parent_;
      }
      x_node->left_ = y_node->left_;
      if (y_node->left_ != nullptr) {
        y_node->parent_->left_ = x_node;
      }
      x_node->right_ = y_node->right_;
      if (y_node->right_ != nullptr) {
        y_node->parent_->right_ = x_node;
      }
      y_node->parent_ = x_parent;
      y_node->color_ = x_color;

      if (x_left == y_node) {
        y_node->left_ = x_node;
      } else {
        y_node->left_ = x_left;
        if (x_left != nullptr) {
          x_left->parent_ = y_node;
        }
      }
      if (x_right == y_node) {
        y_node->right_ = x_node;
      } else {
        y_node->right_ = x_right;
        if (x_right != nullptr) {
          x_right->parent_ = y_node;
        }
      }
    }
  }
};

template <typename Key, typename T, typename Compare, bool is_const>
class RBIterator {
 public:
  friend class RBTree<Key, T, Compare>;
  friend class RBNode<Key, T>;
  using value_type = std::pair<const Key, T>;
  using node_type = RBNode<Key, T>;
  using tree_type = RBTree<Key, T, Compare>;

  using conditional_node_ptr =
      std::conditional_t<is_const, const node_type*, node_type*>;
  using conditional_node_ref =
      std::conditional_t<is_const, const node_type&, node_type&>;
  using conditional_tree_ptr =
      std::conditional_t<is_const, const tree_type*, tree_type*>;

  RBIterator() : itr_node_(nullptr), itr_tree_(nullptr) {}

  RBIterator(conditional_node_ptr node, conditional_tree_ptr tree)
      : itr_node_(node), itr_tree_(tree) {}

  RBIterator(const RBIterator<Key, T, Compare, is_const>& other)
      : itr_node_(other.itr_node_), itr_tree_(other.itr_tree_) {}

  RBIterator& operator=(const RBIterator&& other) noexcept {
    if (this != &other) {
      itr_node_ = std::move(other.itr_node_);
      itr_tree_ = std::move(other.itr_tree_);
    }
    return *this;
  }

  RBIterator& operator=(RBIterator& other) {
    if (this != &other) {
      itr_node_ = other.itr_node_;
      itr_tree_ = other.itr_tree_;
    }
    return *this;
  }

  bool operator==(const RBIterator& other) {
    return itr_node_ == other.itr_node_;
  }

  bool operator!=(const RBIterator& other) { return !(*this == other); }

  value_type& operator*() const { return *(itr_node_->value_); }
  value_type* operator->() const { return &(itr_node_->value_); }

  conditional_node_ptr node() { return itr_node_; }

  RBIterator& operator++() {
    if (itr_node_ == nullptr) {
      return *this;
    }
    if (itr_node_->right_ != nullptr) {
      itr_node_ = itr_node_->right_;
      while (itr_node_->left_ != nullptr) {
        itr_node_ = itr_node_->left_;
      }
    } else {
      node_type* parent = itr_node_->parent_;
      while (parent != nullptr && itr_node_ == parent->right_) {
        itr_node_ = parent;
        parent = parent->parent_;
      }
      itr_node_ = parent;
    }
    return *this;
  }

  RBIterator& operator++(int) {
    ++(*this);
    return *this;
  }

  RBIterator& operator--() {
    if (itr_node_ == nullptr && itr_node_ != itr_tree_->root_) {
      RBIterator temp(itr_tree_->max(), itr_tree_);
      this->itr_node_ = temp.itr_node_;
      this->itr_tree_ = temp.itr_tree_;
      return *this;
    }
    if (itr_node_->left_ != nullptr) {
      itr_node_ = itr_node_->left_;
      while (itr_node_->right_ != nullptr) {
        itr_node_ = itr_node_->right_;
      }
    } else {
      node_type* parent = itr_node_->parent_;
      while (parent != nullptr && itr_node_ == parent->left_) {
        itr_node_ = parent;
        parent = parent->parent_;
      }
      itr_node_ = parent;
    }

    return *this;
  }

  RBIterator& operator--(int) {
    RBIterator temp = *this;
    --(*this);
    return temp;
  }

 private:
  conditional_node_ptr itr_node_;
  conditional_tree_ptr itr_tree_;
};
#endif
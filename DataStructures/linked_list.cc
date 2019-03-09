#include "linked_list.h"
#include <stdexcept>

template <typename T>
LinkedList<T>::LinkedList() : Container<T>(), head_(), tail_() {}


template <typename T>
int LinkedList<T>::size() const {
    return this->size_;
}

template <typename T>
bool LinkedList<T>::empty() const {
    return this->size_ == 0;
}

template <typename T>
T LinkedList<T>::at(int index) const {
    if (index >= this->size_) {
        throw std::out_of_range("LinkedList<T>::at() : index out of range");
    }

    int i = 0;
    for (Node* ptr = head_; ptr; ptr = ptr->next, i++) {
        if (i == index) {
            return ptr->data;
        }
    }
}


template <typename T>
void LinkedList<T>::push_front(T value) {
    Node* new_node = new Node(value);

    if (!head_) {
        tail_ = new_node;
    } else {
        new_node->next = head_;
        head_->prev = new_node;
    }

    head_ = new_node;
    this->size_++;
}

template <typename T>
void LinkedList<T>::push_back(T value) {
    Node* new_node = new Node(value);

    if (!tail_) {
        head_ = new_node;
    } else {
        new_node->prev = tail_;
        tail_->next = new_node;
    }

    tail_ = new_node;
    this->size_++;
}

template <typename T>
T LinkedList<T>::pop_front() {
    if (!head_) {
        throw std::out_of_range("LinkedList<T>::pop_front() : index out of range");
    }

    Node* old_head = head_;
    T old_head_data = old_head->data;

    head_ = old_head->next;
    if (head_) {
        head_->prev = nullptr;
    } else {
        tail_ = nullptr;
    }
    delete old_head;
    this->size_--;
    return old_head_data;
}

template <typename T>
T LinkedList<T>::pop_back() {
    if (!tail_) {
        throw std::out_of_range("LinkedList<T>::pop_front() : index out of range");
    }

    Node* old_tail = tail_;
    T old_tail_data = old_tail->data;

    tail_ = old_tail->prev;
    if (tail_) {
        tail_->next = nullptr;
    } else {
        head_ = nullptr;
    }
    delete old_tail;
    this->size_--;
    return old_tail_data;
}

template <typename T>
void LinkedList<T>::insert(int index, T value) {
    int i = 0;
    for (Node* ptr = head_; ptr; ptr = ptr->next, i++) {
        if (i == index - 1) {
            Node* new_node = new Node(value);
            ptr->next->prev = new_node;
            new_node->next = ptr->next;
            ptr->next = new_node;
            new_node->prev = ptr;
            this->size_++;
        }
    }
}

template <typename T>
void LinkedList<T>::erase(int index) {
    int i = 0;
    for (Node* ptr = head_; ptr; ptr = ptr->next, i++) {
        if (i == index) {
            Node* target_node = ptr;
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            delete target_node;
            this->size_--;
            return;
        }
    }
}

template <typename T>
void LinkedList<T>::remove(T value) {
    for (Node* ptr = head_; ptr; ptr = ptr->next) {
        if (ptr->data == value) {
            Node* target_node = ptr;
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            delete target_node;
            this->size_--;
        }
    }
}

template <typename T>
int LinkedList<T>::find(T value) {
    int i = 0;
    for (Node* ptr = head_; ptr; ptr = ptr->next, i++) {
        if (ptr->data == value) {
            return i;
        }
    }
    return -1;
}


template <typename T>
T LinkedList<T>::front() const {
    return head_->data;
}

template <typename T>
T LinkedList<T>::back() const {
    return tail_->data;
}

template <typename T>
void LinkedList<T>::reverse() {
    // For each node, swap prev and next pointers.
    Node* ptr = head_;
    while (ptr) {
        Node* old_prev = ptr->prev;
        ptr->prev = ptr->next;
        ptr->next = old_prev;
        ptr = ptr->prev;
    }

    // Swap head and tail pointers.
    Node* old_head = head_;
    head_ = tail_;
    tail_ = old_head;
}

template <typename T>
std::string LinkedList<T>::ToString() const {
    std::string s;
    Node* ptr = head_;
    for (int i = 0; i < size(); i++) {
        s += std::to_string(ptr->data) + " ";
        ptr = ptr->next;
    }
    return s;
}

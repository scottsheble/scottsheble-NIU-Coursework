/**********************************************************************************************
 * NIU CSCI 340 Section YOUR_SECTION                                                          *
 * Assignment 2b                                                                               *
 * Scott Sheble - Z1963374 - scottsheble                                                      *
 *                                                                                            *
 *   I certify that everything I am submitting is either provided by the professor for use in *
 * the assignment, or work done by me personally. I understand that if I am caught submitting *
 * the work of others (including StackOverflow or ChatGPT) as my own is an act of Academic    *
 * Misconduct and will be punished as such.                                                   *
 *                                                                                            *
 **********************************************************************************************/
#ifndef NIUCSCI340_LIST_H
#define NIUCSCI340_LIST_H

#include "simple_linked_list.decl.h"
#include <iostream>

//#warning The provided version of simple_linked_list.h does not actually implement things. You will likely get compilation errors until you've at least partially implemented them. You can remove this warning once you've read it.

template <typename T>
template <typename ITERATOR>
simple_linked_list<T>::simple_linked_list(ITERATOR beg, ITERATOR end) {
    // Initialize the head pointer to nullptr
    head = nullptr;

    // Iterate through the range specified by beg and end
    for (ITERATOR it = beg; it != end; ++it) {
        // Create a new node with the current element
        linked_node<T> newNode = new linked_node<T>(*it);

        // If the list is empty, set the new node as the head
        if (!head) {
            head = newNode;
        } else {
            // Otherwise, find the last node and append the new node
            linked_node<T> current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}


template <typename T>
bool simple_linked_list<T>::empty() const {
    return head == nullptr;
}


template <typename T>
simple_linked_iterator<T> simple_linked_list<T>::begin() {
  // Create a new iterator pointing to the first element of the list
  return simple_linked_iterator<T>(head);
}


template <typename T>
simple_linked_iterator<T> simple_linked_list<T>::end() {
  // Return an iterator pointing to the end of the list (nullptr)
  return simple_linked_iterator<T>(nullptr);
}


template <typename T>
T& simple_linked_list<T>::front() {
  if (head == nullptr) {
    // Handle the case where the list is empty. You can throw an exception or
    // implement your error handling logic here.
    throw std::runtime_error("List is empty");
  }

  // Return a reference to the data in the first node
  return head->data;
}

    
template <typename T>
T& simple_linked_list<T>::back() {
  if (head == nullptr) {
    // Handle the case where the list is empty. You can throw an exception or
    // implement your error handling logic here.
    throw std::runtime_error("List is empty");
  }

  linked_node<T>* current = head;

  // Traverse the list until the last node is reached
  while (current->next != nullptr) {
    current = current->next;
  }

  // Return a reference to the data in the last node
  return current->data;
}


template <typename T>
void simple_linked_list<T>::pop_back() {
  if (head == nullptr) {
    // Handle the case where the list is empty. You can throw an exception or
    // implement your error handling logic here.
    throw std::runtime_error("List is empty");
  }

  if (head->next == nullptr) {
    // If there is only one element in the list, remove it.
    delete head;
    head = nullptr;
  } else {
    // Traverse the list to find the second-to-last node
    linked_node<T>* current = head;
    while (current->next->next != nullptr) {
      current = current->next;
    }

    // Delete the last node and set the next pointer of the second-to-last node to nullptr
    delete current->next;
    current->next = nullptr;
  }
}

template <typename T>
void simple_linked_list<T>::push_back(const T &x) {
    // Create a new node with the provided value
    linked_node<T> *newNode = new linked_node<T>(x);
    
    // If the list is empty, set the new node as the head
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        // Otherwise, add the new node to the end of the list
        tail->next = newNode;
        tail = newNode;
    }
    
    // Increment the size of the list
    n_elements++;
}


template <typename T>
simple_linked_list<T>::~simple_linked_list() {
    while (head != nullptr) {
        linked_node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    // After deleting all nodes, set the tail and size appropriately.
    tail = nullptr;
    simple_linked_list<T>size = 0;
}


template <typename T>
size_t simple_linked_list<T>::size() const {
    return size;
}


template <typename T>
void simple_linked_list<T>::clear() {
    while (head != nullptr) {
        linked_node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    simple_linked_list<T>size = 0;
}


// IMPLEMENTATIONS FOR ITERATOR

template <typename T>
bool simple_linked_iterator<T>::operator==(const simple_linked_iterator<T> &other) const {
    // Compare whether both iterators point to the same node in the same linked list
    return (*pos == other.list) && (*pos == other.current);
}


template <typename T>
simple_linked_iterator<T> &simple_linked_iterator<T>::operator++() {
    if (*pos) {
        *pos = *pos->next; // Move to the next node
    }
    return *this;
}

  
template <typename T>
simple_linked_iterator<T> simple_linked_iterator<T>::operator++(int) {
    simple_linked_iterator<T> temp = *this; // Create a copy of the current iterator
    if (*pos) {
        *pos = *pos->next; // Move to the next node
    }
    return temp; // Return the original iterator (before the increment)
}

    
template <typename T>
T &simple_linked_iterator<T>::operator*() {
    if (*pos) {
        return *pos->data; // Return a reference to the value in the current node
    } else {
        // Handle the case where the iterator is not pointing to a valid node.
        // You may throw an exception or return some default value based on your requirements.
        // Here, we'll throw an exception as an example.
        throw std::runtime_error("Dereferencing an invalid iterator");
    }
}


#endif


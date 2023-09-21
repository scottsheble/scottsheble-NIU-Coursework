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

#warning The provided version of simple_linked_list.h does not actually implement things. You will likely get compilation errors until you've at least partially implemented them. You can remove this warning once you've read it.

template <typename T>
template <typename ITERATOR> // constructor copying the contents of another container
simple_linked_list <T>::simple_linked_list(ITERATOR beg, ITERATOR end) {
  // XXX Not implemented. Write the code that goes here..
}

template <typename T>
bool simple_linked_list<T>::empty() const {
  // XXX Not implemented. Write the code that goes here..
}

template <typename T>
simple_linked_iterator <T> simple_linked_list<T>::begin() {
  // XXX Not implemented. Write the code that goes here..
}

template <typename T>
simple_linked_iterator <T> simple_linked_list<T>::end() {
  // XXX Not implemented. Write the code that goes here..
}

template <typename T>
T & simple_linked_list<T>::front() {
  // XXX Not implemented. Write the code that goes here..
}
    
template <typename T>
T & simple_linked_list<T>::back() {
  // XXX Not implemented. Write the code that goes here..
}

template <typename T>
void simple_linked_list<T>::pop_back() {
  // XXX Not implemented. Write the code that goes here..
}

template <typename T>
void simple_linked_list<T>::push_back(const T & x) {
  // XXX Not implemented. Write the code that goes here..
}

template <typename T>
simple_linked_list<T>::~simple_linked_list() {
  // XXX Not implemented. Write the code that goes here..
}

template <class T>
size_t simple_linked_list<T>::size() const {
  // XXX Not implemented. Write the code that goes here..
}

template <typename T>
void simple_linked_list<T>::clear() {
  // XXX Not implemented. Write the code that goes here..
}

// IMPLEMENTATIONS FOR ITERATOR

template <typename T>
bool simple_linked_iterator<T>::operator == (const simple_linked_iterator <T> & other) const {
  // XXX Not implemented. Write the code that goes here..
}

template <typename T>
simple_linked_iterator <T> & simple_linked_iterator <T>::operator ++ () { // preincrement
  // XXX Not implemented. Write the code that goes here..
}
  
template <typename T>
simple_linked_iterator <T> simple_linked_iterator<T>::operator ++ (int) { // postincrement
  // XXX Not implemented. Write the code that goes here..
}
    
template <typename T>
T & simple_linked_iterator<T>::operator * () { // dereference operator
  // XXX Not implemented. Write the code that goes here..
}

#endif


#include<iostream>
using namespace std;

template <typename T>

node<T>::node(T p_item)
{
    item= p_item;
    next=nullptr;
}  

template <typename T>
T node<T>::getItem() {
    return item;
}

template <typename T>
node<T>* node<T>::getNext() {
        if (next != nullptr) {
            return next;
        } else {
            return nullptr;
        }
    } 


template <typename T>
void node<T>::setItem(T p_item) {
    item = p_item;
}

template <typename T>
void node<T>::setNext(node<T>* p_next) {
    next = p_next;
}
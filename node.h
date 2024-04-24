#ifndef NODE_H   
#define NODE_H





template <typename T>
class node {
public:
    node(T p_item);
    T getItem();
    node<T>* getNext();
    void setItem(T  p_item);
    void setNext(node<T>* next);
private:
    T item;
    node* next;
};


#include"node.cpp"
#endif // NODE_H

#ifndef DEQ2_H   
#define DEQ2_H

#include"node.h"

template <typename T>
class DEQ2 {
public:
    DEQ2();
    void Add_Front(node<T>* p_itemNode);
    void Add_Rear(node<T>* p_itemNode);
    void Remove_Front();
    void Remove_Rear();
    T View_Front();
    T View_Rear();
    bool DEQisEmpty();
    void printList();
    int DEQ_Length();
    ~DEQ2();

private:
    node<T>* head;
    node<T>* tail;
    int counter;
};


#endif // DEQ2_H
#include"DEQ2.cpp"
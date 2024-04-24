#include<iostream>
using namespace std;


template <typename T>
DEQ2<T>::DEQ2() : head(nullptr), tail(nullptr), counter(0) {}

template <typename T>
void DEQ2<T>::Add_Front(node<T>* p_itemNode) {
    if (head == nullptr) {
        head = p_itemNode;
        tail = p_itemNode;
    } else {
        p_itemNode->setNext(head);
        head = p_itemNode;
    }
    counter++;
}


template <typename T>
void DEQ2<T>::Add_Rear(node<T>* p_itemNode) {
    if (head == nullptr) {
        head = p_itemNode;
        tail = p_itemNode;
    } else {
        tail->setNext(p_itemNode);
        tail=p_itemNode;
    }
    counter++;
}

template <typename T>
void DEQ2<T>::Remove_Front() {
    if (head != nullptr) {
        node<T>* temp = head;
        head = head->getNext();
        delete temp;
        counter--;
    }
}


template <typename T>
void DEQ2<T>::Remove_Rear() {
   if (head == nullptr) {
       
        return;
    }

    if (head->getNext() == nullptr) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        node<T>* current = head;
        while (current->getNext() != tail) {
            current = current->getNext();
        }

        delete tail;
        tail = current;
        tail->setNext(nullptr);
    }

    counter--;
}


template <typename T>
T DEQ2<T>::View_Front() 
{
    if (head != nullptr) {
        return head->getItem();
    } 
    return 0;
}

template <typename T>
T DEQ2<T>::View_Rear() {
    if (tail != nullptr) {
        return tail->getItem();
    }
    return 0; 
}

template <typename T>
bool DEQ2<T>::DEQisEmpty() {
    return head == nullptr;
}

template <typename T>
void DEQ2<T>::printList() {
    node<T>* current = head;
    while (current != nullptr) {
        cout << current->getItem() << " ";
        current = current->getNext();
    }
    cout << endl;
}

template <typename T>
int DEQ2<T>::DEQ_Length() {
    return counter;
}


template <typename T>
DEQ2<T>::~DEQ2() {
    while (head != nullptr) {
        node<T>* temp = head;
        head = head->getNext();
        delete temp;
    }
}
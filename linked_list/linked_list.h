#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

#include "node.h"

using namespace std;

template <class T>
class LinkedList {
private:
    Node<T> *head;
    int s;
public:
    LinkedList<T>();
    ~LinkedList<T>();
    void add(const T element);
    void add(int index, T element);
    void clear();
    int size() const;
    T get(const int index) const;
    bool remove(const T object);
    bool contains(const T object) const;
};

template <class T>
LinkedList<T>::LinkedList():s(0) {
    head = NULL;
}

template <class T>
void LinkedList<T>::add(const T element) {
    if(head == NULL) {
        head = new Node<T>(element, NULL);
    }
    else {
        Node<T> *node = new Node<T>(element,NULL);
        Node<T> *cur = head;
        while(cur != NULL) {
            if(cur->next == NULL) {
                s++;
                cur->next = node;
                return;
            }
            cur = cur->next;

        }
    }

    s++;
}

template <class T>
void LinkedList<T>::add(int index, T element) {
    if(index >= s) {
        return;
    }
    Node<T> * cur = head;
    if(index==0) {
        Node<T> * newnode = new Node<T>(element, head);
        head = newnode;
        s++;
        return;
    }

    for(int x=0; x<index-1; x++) {
        cur = cur->next;
    }
    Node<T> * newnode = new Node<T>(element, cur->next);
    cur->next = newnode;
    s++;
}

template <class T>
T LinkedList<T>::get(const int index) const {
    Node<T> *cur=head;
    int ctr = 0;
    while(cur != NULL) {
        if(ctr == index) {
            return cur->value;
        }
        cur = cur->next;
        ctr++;
    }
}

template <class T>
LinkedList<T>::~LinkedList() {
    Node<T> *cur = head;
    while(cur != NULL) {
        delete cur;
        cur = cur->next;
    }

}

template <class T>
void LinkedList<T>::clear() {
    delete this;
    s = 0;
    head = NULL;
}

template <class T>
int LinkedList<T>::size() const {
    return s;
}

template <class T>
bool LinkedList<T>::contains(const T object) const {
    Node<T> *cur = head;
    while(cur != NULL) {
        if(object == cur->value) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

template <class T>
bool LinkedList<T>::remove(const T object) {
    if(s==0) {
        return false;
    }
    Node<T> *cur = head;
    if(head->value == object) {
        Node<T>* temp = head->next;
        delete head;
        head = temp;
        s--;
        return true;
    }
    while(cur->next != NULL) {
        if(cur->next->value == object) {
            Node<T>* temp = cur->next->next;
            delete cur->next;
            cur->next = temp;
            s--;
            return true;
        }
        cur = cur->next;
    }
    return false;
}
#endif

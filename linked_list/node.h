#ifndef NODE_H
#define NODE_H


template <class T>
class Node {
public:
    T value;
    Node<T>* next;
    Node(T val,Node<T> *nxt);
};

template <class T>
Node<T>::Node(T val, Node<T> *nxt): value(val), next(nxt) {
}

#endif

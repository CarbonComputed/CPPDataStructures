#ifndef ArrayList_H_
#define ArrayList_H_

#include <iostream>
using namespace std;

template <class T>
class ArrayList {
    T* array;
    int len;
public:



    int size();
    void add(T);
    void add(T,int);
    ArrayList() {

        len=0;
        array=new T[0];
    }
    ~ArrayList();
    friend ostream& operator<<(ostream& output, ArrayList<T>& l);
    void remove(int);
    T get(int);
    void clear();
};
template<class T>
void ArrayList<T>::clear() {
    delete [] array;
    T* temp=new T[0];
    array=temp;
    len=0;
}

template <class T>
void ArrayList<T>::add(T value) {
    if(len==0) {
        array[0]=value;
        len++;
        return;
    }
    else {
        T* temp=new T[len+1];
        for(int x=0; x<len; x++) {
            temp[x]=array[x];
        }
        temp[len]=value;
        len++;
        delete [] array;
        array=temp;
    }
}

template <class T>
ArrayList<T>::~ArrayList() {
    delete [] array;
}

template <class T>
void ArrayList<T>::add(T value,int index) {
    if(len==0|| index < len) {
        array[0]=value;
        len++;
        return;
    }
    else {
        T* temp=new T[len+1];
        for(int x=0; x<len; x++) {
            if(x < index) {
                temp[x]=array[x];
            }

            else {
                temp[x+1]=array[x];
            }

        }
        temp[index]=value;
        len++;
        delete [] array;
        array=temp;
    }
}

template <class T>
int ArrayList<T>::size() {
    return len;
}

template <class T>
T ArrayList<T>::get(int index) {
    return array[index];
}

template <class T>
void ArrayList<T>::remove(int index) {
    if(len == 0) {
        return;
    }
    else {
        T* temp=new T[len-1];

        for(int x=0; x<len-1; x++) {
            if(x < index) {
                temp[x]=array[x];
            }
            else {
                temp[x]=array[x+1];
            }
        }
        len--;
        delete [] array;
        array=temp;
    }
}

template <class T>
ostream& operator<<(ostream& output, ArrayList<T>* l) {
    //output<<"TEST";

    //cout<<l.front->next->data;
    output<<'[';
    for(int x=0; x<l->size(); x++) {
        output<<l->get(x)<<",";
    }
    output<<"]";
    return output;

}

#endif

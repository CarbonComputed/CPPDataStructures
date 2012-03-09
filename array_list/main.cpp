/*
 * main.cpp
 *
 *  Created on: Jan 27, 2011
 *      Author: kevin
 */

#include <iostream>
#include "ArrayList.h"
using namespace std;

int main() {
    ArrayList<int>* list =new ArrayList<int>();
    list->add(5);
    list->add(6);

    cout<<list;
    list->add(7,2);
    cout<<list<<endl;
    cout<<list->size();
    delete list;
}

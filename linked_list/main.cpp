#include <iostream>

#include "linked_list.h"

using namespace std;

int main() {
    LinkedList<int> *l = new LinkedList<int>;
    for(int x = 1; x<=60; x++) {
        l->add(x);
    }
    l->add(59,99);
//cout<<l->get(0)<<endl;
// cout<<l->get(1)<<endl;
// cout<<l->get(45)<<endl;
// cout<<l->size()<<endl;
    l->remove(45);
// cout<<l->get(43)<<endl;
// cout<<l->size()<<endl;
// cout<<l->contains(60)<<endl;
// cout<<l->contains(45)<<endl;
    for(int x = 0; x< l->size(); x++) {
        cout<<l->get(x)<<endl;
    }
    delete l;
}

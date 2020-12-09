#include <stdio.h>
#include <iostream>

using namespace std;

template<class T>
struct elem{
    T data;
    elem *par;
    elem *left, *right;
    elem(T value) : par(NULL), left(NULL), right(NULL), data(value) {}
};

template<class T>
class binary_tree{
    elem<T> *top;
    
    static void show2(elem<T>* t);
public:
    
    void add(const T &data);
    bool find(const T &data);
    void show();
    
    binary_tree() : top(0) {}
};

template<class T>
void binary_tree<T>::add(const T &data){
    if(!top) {
        top = new elem<T>(data);
        return;
    }
    elem<T> *p = top;

    while(p)
        if(data < p->data){
            if(!(p->left)) {
                p->left = new elem<T>(data);
                p->left->par = p;
                return;
            }
            else p = p->left;
        }
        else if( data > p->data ){
            if(!(p->right)) {
                p->right = new elem<T>(data);
                p->right->par = p;
                return;
            }
            else p = p->right;
        }

        else if(p->data == data) return;
}

template<class T>
bool binary_tree<T>::find(const T &data){
    elem<T> *p = top;
        while(p)
            if(data < p->data)
                p = p -> left;
            else if(data > p->data)
                p = p->right;
            else if(p->data == data)
                return true;
    return false;
}

template<class T>
void binary_tree<T>::show2(elem<T>* t){
    if(!t) return;
    show2(t->left);
    std::cout << t->data << " ";
    show2(t->right);
}

template<class T>
void binary_tree<T>::show(){
    show2(top);
}
 

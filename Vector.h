//
// Created by burak on 13.03.2019.
//
#include <queue>
#ifndef EXP1_VECTOR_H
#define EXP1_VECTOR_H
using namespace std;

class Vector {
    int dimension;
    int *vals;
    int size;
public:
    //int *values=NULL;
    Vector();
    Vector(int);
    void setsize(int x){size=x;}
    void print();
    void createarr(int);
    void addvals(int,int);
    int tr;
    void operator+(Vector &v1);
    void operator*(int);
    void operator<<(int);
    void operator*(Vector &v1);
};
Vector::Vector() {}
Vector::Vector(int element) {

setsize(element);
createarr(element);

}

void Vector::createarr(int element) {
    this->size=element;
    this->vals = new int[element];
    for (int i = 0; i < element; i++)vals[i] = 0;
}

void Vector::operator*(Vector &v1) { //dot product

    if (size != v1.size)cout << "Error!Vector sizes must be same!";
    else {
        this->operator<<(0);cout<<" . ";v1<<0;cout<<" = ";
        int res = 0;
        for (int i = 0; i < size; i++) {
            res += this->vals[i] * v1.vals[i];

        }
        cout<<res<<endl;
    }
}
void Vector::operator+(Vector &v1){
    if(size != v1.size)cout<<"Error!Vector sizes must be same!";
    else{
        this->operator<<(0);cout<<" + ";v1<<0;cout<<" = ";
        Vector temp;
        temp.createarr(size);
        for(int q=0;q<size;q++){
            temp.vals[q]=this->vals[q]+v1.vals[q];
        }
        temp<<0;
    }
}

void Vector::operator*(int factor){
    Vector temp;
    temp.createarr(size);
    this->operator<<(0);cout<<" * "<<factor<<" = ";
    for(int i=0;i<size;i++){
        temp.vals[i]=factor*this->vals[i];
    }
    temp<<0;
};

void Vector::addvals(int num,int order) {

    vals[order]=num;
}
void Vector::operator<<(int x) {
    cout<< "(";
    for(int s=0;s<size;s++){
        if(s==size-1){cout<<vals[s];break;}
        cout<<vals[s]<<", ";
    }
    cout<<")";

}


#endif //EXP1_VECTOR_H

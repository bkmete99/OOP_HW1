//
// Created by burak on 13.03.2019.
//

#ifndef EXP1_POLYNOMIAL_H
#define EXP1_POLYNOMIAL_H
using namespace std;

class Polynomial {
    int * vals;
    int a;
    int size;
    int degree;
public:
    Polynomial(int);
    Polynomial();
    Polynomial(Polynomial &p1);
    void operator+(Polynomial &op1);
    void operator*(Polynomial &op1);
    void setsize(int x){size=x;}

    void createarr(int);
    int getsize(){return size;	}
    void setdegree(int x){degree=x;}
    int getdegree(){return degree;}
    void addvals(int,int);
   
    void operator<<(int);
    void printres();
};
Polynomial::Polynomial() {}
Polynomial::Polynomial(int inp) {

   size=inp;
    this->vals=new int[inp];
    for(int i=0;i<inp;i++)vals[i]=0;
}
Polynomial::Polynomial(Polynomial &p1){
	this->size=p1.size;
	this->vals=new int[size];
    for(int i=0;i<p1.size;i++)vals[i]=p1.vals[i];
}


void Polynomial::createarr(int element) {
    this->size=element;
    this->vals=new int[element];
    for(int i=0;i<element;i++)vals[i]=0;
}



void Polynomial::operator+(Polynomial &op1) {
    Polynomial temp;
	int tempsize;
    
    this->operator<<(0);cout<<" + ";op1<<0;cout<<" = ";
    if(op1.size>this->size){
        tempsize=op1.size;
        temp.createarr(tempsize);
        temp.size=tempsize;
        while(tempsize!=this->size-1) {
            temp.addvals(op1.vals[tempsize], tempsize);
            tempsize--;
        }
    }
    else if(this->size>op1.size){
        tempsize=this->size;
        temp.createarr(tempsize);
        temp.size=tempsize;
        tempsize--;
        while(tempsize!=op1.size-1) {
            temp.addvals(this->vals[tempsize], tempsize);
            tempsize--;
        }
    }
    else{tempsize=this->size;temp.size=tempsize;}
    while(tempsize!=-1){
        temp.vals[tempsize]=this->vals[tempsize]+op1.vals[tempsize];
        tempsize--;
    }
    temp<<0;
}

void Polynomial::operator*(Polynomial &op1) {
    Polynomial temp;
    this->operator<<(0);cout<<" * ";op1<<0;cout<<" = ";
    temp.createarr(op1.size+this->size);temp.size=op1.size+this->size-2;
    for(int j=this->size-1;j>=0;j--){
        for(int k=op1.size-1;k>=0;k--){
            temp.vals[k+j]+=this->vals[j]*op1.vals[k];
        }
    }
    temp<<-2;
}

void Polynomial::addvals(int num,int order) {
    vals[order]=num;
}

void Polynomial::operator<<(int order) {
    if(order==-1){return ;}
    if(order==-2){
        for(int a=this->size;a>-1;a--){
            if(vals[a]!=1 || a==0)cout << vals[a];
            if(a!=0 && a!=1)cout<<"x^"<<a<<" + ";
            else if(a==1)cout<<"x"<<" + ";
            degree++;
        }
    }
    else{
        if(order!=0)cout<<order<<". ";
    for(int a=this->size-1;a>-1;a--){
        if(vals[a]!=1 || a==0)cout << vals[a];
        if(a!=0 && a!=1)cout<<"x^"<<a<<" + ";
        else if(a==1)cout<<"x"<<" + ";
        degree++;
    }}
}



#endif //EXP1_POLYNOMİAL_H

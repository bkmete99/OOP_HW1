#include <iostream>
#include <fstream>
#include "Polynomial.h"
#include "Vector.h"
#include <string.h>
#include <cstring>
#include <sstream>
#include <queue>
using namespace std;

int main(int argc,char * argv[]) {

    //Vector part
    ifstream infile(argv[1]);int input,i2,i=0;
    if(!infile.is_open()){
        cout<<"file couldnt opened";
        return 0;
    }
    infile>>input;
    Vector *arr= new Vector[input];//array of vector objects cretaed

    string line;getline(infile,line);
    while(getline(infile,line)){
        int count=0;

        stringstream burak2(line);
		burak2>>i2;
		arr[i]=Vector(i2);
        //arr[i].setsize(i2);
       // arr[i].createarr(i2);
        while(burak2>>i2) {
            arr[i].addvals(i2,count);
            count++;}
            i++;
        }

string demand;
i=0;
    //taking polynomial
    ifstream infile2(argv[2]);int input2;
    if(!infile2.is_open()){
        cout<<"file couldnt opened";
    }
    infile2>>input2;

    Polynomial *arrp= new Polynomial[input2];//array of poly. object cretaed


    string line2;
    while(getline(infile2,line2)){//taking file line by line
        int count=1;
        stringstream burak2(line2);
        burak2>>i2;
        //arrp[i].setdegree(i2);
        int noofelements=i2+1;
        arrp[i]=Polynomial(noofelements);
        //arrp[i].createarr(noofelements);//taking place from memory for values of this obj
        //arrp[i].setsize(noofelements);
       // getchar();
       
        while(burak2>>i2) {
           arrp[i].addvals(i2,arrp[i].getsize()-count);//by one by adding them to my array
           count++;}

        i++;

    }
    int choose;
    cout<<"Polynomials and Vector List Program!"<<endl;
    cout<<"Possible actions:"<<endl;
    cout<<"1. Print Polynomial and Vector Lists"<<endl;
    cout<<"2. Do a polynomial operation"<<endl;
    cout<<"3. Do a vector operation"<<endl;
    cout<<"4. Help: Print possible actions "<<endl;
    cout<<"0. Exit the program"<<endl;

    while(1){
        cout<<endl<<"Enter an option: "<<endl;
        cin>>choose;
    if(choose==1){
cout<<"Vectors:"<<endl;
for(int i=0;i!=input;i++){
    cout<<i+1<<".";arr[i]<<i;
    cout<<endl;
}
cout<<endl<<"Polynomials:"<<endl;
for(int a=1;a!=input2+1;a++){
    arrp[a]<<a;
    cout<<endl;
}
    }
    else if(choose==2){

cout<<endl<<"Enter a polynomial operation:"<<endl;char sign;

int opr1,opr2;
cin>>opr1>>sign>>opr2;

if(sign=='+'){
    arrp[opr1]+arrp[opr2];
}
if(sign=='*'){
    arrp[opr1]*arrp[opr2];
}

    }
    else if(choose==3){
char sign;int opr1,opr2;//they must be 1 subtract
cout<<"Enter a vector operation:";
        cin>>opr1>>sign>>opr2;
        opr1--;opr2--;
        if(sign=='+'){
    arr[opr1]+arr[opr2];
}
        if(sign=='*'){
            arr[opr1]*(opr2+1);
        }
        if(sign=='.'){
            arr[opr1]*arr[opr2];
        }

    }
    
    else if(choose==4){
        cout<<"Polynomials and Vector List Program!"<<endl;
        cout<<"Possible actions:"<<endl;
        cout<<"1. Print Polynomial and Vector Lists"<<endl;
        cout<<"2. Do a polynomial operation"<<endl;
        cout<<"3. Do a vector operation"<<endl;
        cout<<"4. Help: Print possible actions "<<endl;
        cout<<"0. Exit the program"<<endl;
    }
    else if(choose==0){
break;
    }
    }

    return 0;
}

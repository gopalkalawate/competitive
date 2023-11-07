#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Employee{
    int id;
    string name;

    public :

        Employee();

        void getdata();

};

// ~Employee(class name) => Notation for destructor 

// :: => this is scope resolution operator
// c++ constructors dont have return type
// constructor is when the function name in the class have the same name as of the class
// as soon as the object is declared the constructor function gets called

// using friend and static we can put the constructor in static function

Employee :: Employee(){ // note that the name of the function is the 
    cin>>id;
    cin>>name;
}

void Employee::getdata() {
    cout<<id<<" "<<name;
}

int main(){
    Employee a;
    
    a.getdata();

}

// destructor is needed because memory allocated in heap doent  gets destroyed hence ...
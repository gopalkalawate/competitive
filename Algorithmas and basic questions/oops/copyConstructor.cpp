#include<bits/stdc++.h>
using namespace std;

class xyz{
    int data;
    public:



        xyz(){
            data = 10;
            cout<<"constructor called\n";
            
        }

        int get_i(){
            return data;
        }

        ~xyz(){
            cout<<"destructor called\n";
        }
};

xyz &fun(){
    xyz b;
    xyz &a = b;

    return a;
    // this.get_i();
    // return *this;
}

int main(){
    xyz a;
    a = fun();
    cout<<a.get_i();
}
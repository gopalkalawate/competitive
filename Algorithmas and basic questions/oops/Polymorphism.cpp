#include<iostream>
using namespace std;

class base{
    public:
        //virtual void  display()=0;
        int dm;
};

class derived : public base
{
    public:
        void display(){
            cout<<"virtual class hai bhai\n";
        }
        
};

class derived2 : public base
{
    public:
    int hj;
    void display(){

    }
};

class third : public derived2,public derived
{
    public:
    void display(){
        cout<<this->derived2::dm<<'\n';
    }
};

int main(){
    derived gk;
    //gk.display();

    //gk.base::display(); => base class function called

    base *kk;
    kk = &gk;
    //kk->display();

    //base dm;

    //derived2 mmm;

    third dm;
    dm.display();

    return 0;
}


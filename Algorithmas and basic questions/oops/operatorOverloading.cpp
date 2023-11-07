#include<iostream>
using namespace std;

class complex{
    
    public:
        int real,imag;
        complex(int r,int i){
            this->real = r;
            this->imag = i;
        }

        // complex operator+=(complex &b){
            
        //     this->real += b.real;
        //     this->imag += b.imag; 
        //     return *this;
        // }

        friend :: complex operator+(complex a,complex b);

        friend ostream& operator<<(ostream& out, const complex &a);

        
};

ostream& operator<<(ostream& out,const complex &a){
    out<<a.real<<" +i"<<a.imag;
    return out;
}

complex operator+(complex a,complex b){
    complex tmp(0,0);
            tmp.real = a.real + b.real;
            tmp.imag = a.imag + b.imag;

            return tmp;

}

class baseclass{
    public:
        
        void display(){
            cout<<"base hai bhai\n";
        }
};

class derived : public baseclass
{
    public:
        int manan;

        void display(){
            cout<<"derived hai bhai\n";
        }
};



int main(){
    complex a(1,2),b(2,4),c(0,0),d(1,1);

    c = a + b; // operator+(b)

    cout<<c.real <<" +i"<<c.imag<<'\n';

    cout<<"value of a"<<a.real<<" +i"<<a.imag<<'\n';

    cout<<c;

   

}
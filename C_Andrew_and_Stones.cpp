#include<iostream>
using namespace std;

class base{
    public:
        int m;
        void display(int n){
            cout<<"base\n";
        }
};

class derived : public base
{
    public:

        derived(int n=0,int m=9){
            cout<<"int wale\n";
            cout<<n<<'\n';
        }

        // derived(int m){
        //     cout<<"normal wale\n";
        // }

        void display(){
            cout<<"derived\n";
        }
        
};

int main(){
    derived ad(1,2);
    derived gk(1);

    ad.base::display(1);
}
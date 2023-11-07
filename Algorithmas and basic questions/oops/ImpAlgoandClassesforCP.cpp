#include<iostream>
using namespace std;

#define ll long long
#define M 998244353

class mint{
    
    public:
        ll a;
        mint(ll data){
            this->a = data;
        }

        mint operator+(mint &b){
            mint tmp(0);
            tmp.a = ((a%M) + b.a%M)%M;
            return tmp; 
        }

        mint operator-(mint &b){
            mint tmp(0);
            tmp.a = ((a%M) + b.a%M)%M;
            return tmp;
        }  

        mint operator*(mint &b){
            mint tmp(0);
            tmp.a = ((a%M) * b.a%M)%M;
            return tmp;
        }

        // operator int(){

        // }

        template <typename T>
        friend ::ostream operator<<(std :: ostream &out,mint a);
};

ostream& operator<<(ostream& out, const mint& a) {
    out << a.a;
    return out;
}


int main(){
    
    mint a(10),b(10),c(0);


    //c  = a+b;

    //int k = (int)a;

    cout<<a;
    

}
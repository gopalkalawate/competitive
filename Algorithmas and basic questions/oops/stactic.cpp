#include <iostream>
using namespace std;

class shared {
public:
    static int a;
    static int c;
    int b = 10;
    static int count;
    shared() { ++count; }
    ~shared() { --count; }
    static int increment() {
        int n = 0; // static me define ho jayega par vo object ke variable ko access nahi kar payega
        a++;
        c++;
        return c;
    }
};

int shared::a;
int shared::c;
int shared::count;

int main() {
    shared o1;
    shared o2;

    cout<<"the increment functions whic is static : "<<o1.increment()<<endl;
   
    
    // Print the address of the static function increment
    printf("Address of increment function: %p\n", &shared::increment);

    printf("o1 object increment function address %p \n",&o1.increment);
    printf("o2 object increment function address %p",&o2.increment);
    
    return 0;
}



// shared::a = 99;
    // shared x,y;
    // cout<<x.b<<endl;
   
    // cout<<"output for x "<<x.a;
    // x.a++; // only x change but due to static change will be everywhere
    // cout<<"\noutput for y\n "<<y.a;

    // cout<<&x.a<<"this is address for x\n";

    // cout<<&y.a<<"this is address for x\n";

    

    // cout<<"after increment for the static function "<<x.increment();
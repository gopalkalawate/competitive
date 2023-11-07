#include<iostream>
using namespace std;
int main() {
    long long a = 8261022826;
    long long b = ((a % 10) * 1e9) + a / 10;
    cout << (b ^ a) << '\n';
    return 0; // You should return 0 from main.
}

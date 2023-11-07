#include<bits/stdc++.h>
using namespace std;

int cyclicRightShift(int noo){ // function which will help us to calculate the number 
    std::string s = std::to_string(noo);

    char k = s.back();

    for (int i = s.size() - 1; i > 0; i--) {
        s[i] = s[i - 1];
    }
    s[0] = k;

    
    int result = std::stoi(s);
    
    return result;
}

int main(){
    int n=410097; // the encoded number
    for(int i=100000;i<=800000;i++){
        int x = cyclicRightShift(i);
        if((i^x)==n){
            cout<<i<<' ';
        }
    }
}
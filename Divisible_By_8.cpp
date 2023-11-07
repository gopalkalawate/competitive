#include <bits/stdc++.h>
using namespace std;

void soln() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    string k;

    if(n==1){
        s='8';
    }
    else if(n==2){
        k = s.substr(n-2,2);
    }
    else if(n>=3){
        k = s.substr(n-3,3);
    }

    if(stoi(k)%8==0){
        cout<<s<<'\n';
    }

    for(int i=0;i<=9;i++){
        k.back() = i + '0';
        if(stoi(k)%8==0){
            break;
        }
    }

    s.back() = k.back();

    cout<<s<<'\n';
   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) soln();
    return 0;
}

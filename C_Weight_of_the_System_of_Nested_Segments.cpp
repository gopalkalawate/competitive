#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct point{
    int weight,id,position;
};

void soln(){
    int n,k;cin>>n>>k;

    vector <point> a(k);

    for(int i=0;i<k;i++){
        cin>>a[i].position>>a[i].weight;
        a[i].id = i+1;
    }

    sort(a.begin(),a.end(),[](point a,point b){
        return a.weight < b.weight;
    });

    int sum = 0;
    for(int i=0;i<k;i++){
        if(i<2*n){
            sum += a[i].weight;
            
        }
        else{
            a.pop_back();
        }
    }

    cout<<sum<<'\n';

    sort(a.begin(),a.end(),[](point a,point b){
        return a.position < b.position;
    });

    for(int i=0;i<n;i++){
        cout<<a[i].id<<" "<<a[2*n-1-i].id<<'\n';
    }

    cout<<endl;

}

int main(){
    int t;cin>>t;
    while(t--) soln();
}
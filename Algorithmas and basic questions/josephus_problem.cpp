#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 998244353
#define pb push_back

int soln(int n) {
    if (n == 1)
        return 1;

    return (soln(n - 1) + 2) % n;
}

int main() {
    int n;
    cin >> n;
    printf("%d ", soln(n));
    printf("%d ",soln(n-1));
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 998244353
#define pb push_back
const int N = 1e5+10;
vector<vector<int>> g(N);
int visited[N] = {0};

void bfs(int vertex) {
    queue<int> q;
    visited[vertex] = 1;

    q.push(vertex);

    while (!q.empty()) {
        int current_v = q.front();
        q.pop(); // Corrected from q.pop()

        cout << current_v << " ";

        for (auto child : g[current_v]) { // Corrected from g[x]
            if (!visited[child]) {
                visited[child] = 1;
                q.push(child);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m; // n->vertices , m->edges

    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1); // considering undirected graph 
    }

    bfs(1);

    return 0;
}

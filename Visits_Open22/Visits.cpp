#include <bits/stdc++.h>
using namespace std;

vector<int> a, v;
vector<vector<int>> reversed_graph;
vector<bool> visited;

void mark(int y) {
    if (visited[y]) { 
        return; 
    }
    visited[y]=true;
    for (int c:reversed_graph[y]) { 
        mark(c); 
    }
}

int min_in_cycle(int curr) {
    // find minimum in the cycle
    int y=a[curr];
    int z=a[y];
    while (y!=z) {
        y=a[y];
        z=a[a[z]];
    }
    int min_v=v[y];
    y=a[y];
    while (y!=z) {
        min_v=min(min_v, v[y]);
        y=a[y];
    }
    mark(y);
    return min_v;
}

int main() {
    int n;
    cin >> n;
    v.resize(n);
    a.resize(n);
    visited.resize(n);
    reversed_graph.resize(n);
    long long ans=0;
    for (int i=0; i<n; i++) {
        cin >> a[i] >> v[i];
        a[i]--;
        reversed_graph[a[i]].push_back(i);
        ans+=v[i];
    }

    for (int i=0; i<n; i++) {
        if (!visited[i]) { 
            ans-=min_in_cycle(i); 
        }
    }
    cout << ans;
}
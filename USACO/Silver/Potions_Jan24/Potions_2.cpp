#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN=2e5+1;
vector<int> adj[MAXN];
int potions[MAXN],leaves[MAXN],ans=0,leaves_count=0;

void dfs(int v,int p) {
    if (v!=1 && adj[v].size()==1) {
        leaves[v]++;
    }
    for (int i:adj[v]) {
        if (i!=p) {
            dfs(i,v);
            leaves[v]+=leaves[i];
        }
    }
    int mn=min(potions[v],leaves[v]);
    ans+=mn;
    potions[v]-=mn;
    leaves[v]-=mn;
}

signed main() {
    int n; 
    cin >> n;
    vector<int> ord(n);
    for (int i=0; i<n; i++) {
        cin >> ord[i];
    }
    for (int i=0; i<n-1; i++) {
        int a,b; 
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1; i<n+1; i++) {
        if (i!=1 && adj[i].size()==1) {
            leaves_count++;
        }
    }
    for (int i=0; i<leaves_count; i++) {
        potions[ord[i]]++;
    }
    dfs(1,0);
    cout << ans;
}
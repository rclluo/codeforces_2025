#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    // ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<int> indegree(n);
    vector<int> connect(n);
    vector<int> moos(n);
    int a,b;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        a--;
        moos[i]=b;
        indegree[a]++;
        connect[i]=a;
    }
    vector<bool> visited(n,false);
    int curr=0;
    while (!visited[curr]) {
        visited[curr]=true;
        curr=connect[curr];
    }
    fill(visited.begin(),visited.end(),false);
    vector<bool> looped(n,false);
    while (!visited[curr]) {
        // cout << curr;
        visited[curr]=true;
        looped[curr]=true;
        curr=connect[curr];
    }
    // cout << '\n';
    int ans=0;
    for (int i=0; i<n; i++) {
        if (indegree[i]==0) {
            curr=i;
            while (!visited[curr]) {
                visited[curr]=true;
                ans+=moos[curr];
                curr=connect[curr];
            }
        }
    }
    // for (auto i:looped) {
    //     cout << i;
    // }
    // cout << '\n';
    int mn=LLONG_MAX;
    for (int i=0; i<n; i++) {
        if (looped[i]) {
            ans+=moos[i];
            mn=min(mn,moos[i]);
        }
    }
    cout << ans-mn;
}
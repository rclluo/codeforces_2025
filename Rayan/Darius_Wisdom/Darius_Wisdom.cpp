#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    set<int> s1,s2;
    for (int i=1; i<=n; i++) {
        if (a[i]==1) {
            s1.insert(i);
        }
        if (a[i]==2) {
            s2.insert(i);
        }
    }
    vector<pair<int,int>> ans;
    for (int i=n; i>=1; i--) {
        if (a[i]==2) {
            s2.erase(i);
            continue;
        }
        if (a[i]==1)  {
            if (s2.empty()) {
                s1.erase(i);
                continue;
            }
            int pos=*s2.begin();
            s2.erase(pos);
            swap(a[i],a[pos]);
            s1.erase(i);
            s1.insert(pos);
            ans.push_back({i,pos});
            continue;
        }
        if (s2.empty()) {
            if(s1.empty()) {
                break;
            }
            int pos=*s1.begin();
            s1.erase(pos);
            swap(a[i],a[pos]);
            ans.push_back({pos,i});
        } else {
            int pos1=*s1.begin();
            int pos2=*s2.begin();
            s2.erase(pos2);
            s1.erase(pos1);
            a[i]=2,a[pos1]=0,a[pos2]=1;
            s1.insert(pos2);
            ans.push_back({i,pos1});
            ans.push_back({i,pos2});
        }
    }

    cout << ans.size() << '\n';
    for(auto [x,y] : ans) {
        cout << x << ' ' << y << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
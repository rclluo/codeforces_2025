/*
n,k <= 1e5
-1e9 < x,l,r < 1e9
t <= n

greedy on number of trees able to cut down
sort trees and segments, if you can cut it down, cut it down
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n,k;
        cin >> n >> k;
        vector<int> trees(n);
        for (int i=0; i<n; i++) {
            cin >> trees[i];
        }
        sort(trees.begin(),trees.end());
        vector<tuple<int,int,int,int>> events;
        for (int i=0; i<n; i++) {
            events.push_back({trees[i],0,0,0});
        }
        for (int i=0; i<k; i++) {
            int l,r,t;
            cin >> l >> r >> t;
            int existing=upper_bound(trees.begin(),trees.end(),r)-lower_bound(trees.begin(),trees.end(),l);
            events.push_back({l,-1,r,existing-t});
        }
        sort(events.begin(),events.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int ans=0;
        for (const auto& event : events) {
            int l,type,r,t;
            tie(l,type,r,t)=event;
            if (type == -1) {
                pq.push({ans + t,r});
            } else {
                while (!pq.empty() && pq.top().second<l) {
                    pq.pop();
                }
                if (pq.empty() || pq.top().first != ans) {
                    ans += 1;
                }
            }
        }
        cout << ans << '\n';
    }
}


/*
Individual cow is too slow, must compress into pairs. 
Place heavier cows first, on the tower with heaviest on top.
The queue keeps track of the towers being built, with the tower with heaviest top first.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<pair<ll,ll>> cow_types(n);
    for (int i=0; i<n; i++) {
        ll w,a;
        cin >> w >> a;
        cow_types[i]={w,a};
    }
    sort(cow_types.begin(),cow_types.end(),greater<pair<ll,ll>>());
    queue<pair<ll,ll>> towers;
    towers.push({LLONG_MAX,m});
    ll ans=0;
    ll cows_left;
    for (const auto& [w,a]:cow_types) {
        cows_left=a;
        while (!towers.empty() && cows_left>0 && w+k<=towers.front().first) {
            if (towers.front().second>cows_left) {
                towers.front().second-=cows_left;
                cows_left=0;
            } else {
                cows_left-=towers.front().second;
                towers.pop();
            }
        }
        ll count=a-cows_left;
        if (count>0) {
            towers.push({w,count});
            ans+=count;
        }
    }
    cout << ans;
}
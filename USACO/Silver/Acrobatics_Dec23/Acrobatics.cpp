#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,m,k;
    cin >> n >> m >> k;
    vector<pair<long long,long long>> pairs(n);
    for (long long i=0; i<n; i++) {
        long long w, a;
        cin >> w >> a;
        pairs[i] = {w,a};
    }
    sort(pairs.rbegin(),pairs.rend());
    deque<pair<long long, long long>> towers;
    towers.push_back({LLONG_MAX,m});
    long long answer=0;
    for (const auto& [w,a]:pairs) {
        long long remaining=a;
        while (!towers.empty() && remaining > 0 && w+k<=towers.front().first) {
            if (towers.front().second>remaining) {
                towers.front().second-=remaining;
                remaining = 0;
            } else {
                remaining-=towers.front().second;
                towers.pop_front();
            }
        }
        long long cnt=a-remaining;
        if (cnt>0) {
            towers.push_back({w,cnt});
            answer+=cnt;
        }
    }

    cout << answer << endl;
}
#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
#define all(x) begin(x), end(x)

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ook order_of_key

const int big = 1e9;

void solve() {
    int N, K;
    cin >> N >> K;
    V<int> X(N);
    for (int &x : X) cin >> x;
    V<tuple<int, int, int>> ivals;
    for (int k = 0; k < K; ++k) {
        int l, r, t;
        cin >> l >> r >> t;
        ivals.push_back({r, l, t});
    }
    sort(all(X));
    sort(all(ivals));
    int iX = 0;
    vector<pair<int, int>> stk;
    Tree<pair<int, int>> t;
    for (auto [r, l, t_low] : ivals) {
        while (iX < X.size() && X.at(iX) <= r) {
            stk.push_back({X.at(iX), iX});
            ++iX;
        }
        int t_current = t.ook({r, big}) - t.ook({l, 0});
        while (t_current < t_low) {
            assert(!stk.empty());
            t.insert(stk.back());
            stk.pop_back();
            ++t_current;
        }
    }
    cout << N - size(t) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    while (TC--) solve();
}
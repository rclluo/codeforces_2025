#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool pair_comp_first(pair<ll,ll>& a,pair<ll,ll>& b) {
    return a.first<b.first;
}

bool pair_comp_second(pair<ll,ll>& a,pair<ll,ll>& b) {
    return a.second<b.second;
}

bool check(ll current_y,vector<pair<ll,ll>>& corners,vector<ll>& slopes) {
    vector<ll> max_slopes;
    for (auto& corner:corners) {
        max_slopes.push_back((corner.second-current_y)/corner.first);
    }
    sort(max_slopes.begin(),max_slopes.end());
    for (int i=0; i<slopes.size(); i++){
        if (slopes[i]>max_slopes[i])
            return false;
    }
    return true;
}

ll find_min_y(vector<pair<ll,ll>>& pos_corners,vector<ll>& pos_slopes) {
    sort(pos_slopes.begin(),pos_slopes.end());
    ll min_y=min_element(pos_corners.begin(),pos_corners.end(),pair_comp_second)->second;
    ll max_x=max_element(pos_corners.begin(),pos_corners.end(),pair_comp_first)->first;
    ll hi=min_y;
    ll lo=min_y-pos_slopes.back()*max_x;
    while (lo<hi) {
        ll mid=(lo+hi+1)/2;
        if (check(mid,pos_corners,pos_slopes)) {
            lo=mid;
        } else {
            hi=mid-1;
        }
    }
    return lo;
}

ll find_max_y(vector<pair<ll,ll>>& neg_corners,vector<ll>& neg_slopes) {
    vector<pair<ll,ll>> new_neg_corners;
    for (auto&target:neg_corners) {
        new_neg_corners.push_back({target.first,-target.second});
    }
    vector<ll> new_positiveSlopes;
    for (auto&s:neg_slopes) {
        new_positiveSlopes.push_back(-s);
    }
    return -find_min_y(new_neg_corners,new_positiveSlopes);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll x1;
        cin >> n >> x1;
        vector<ll> y_coordinates(2*n);
        vector<pair<ll,ll>> pos_corners,neg_corners;
        vector<ll> slopes(4*n);
        for (int i=0; i<n; ++i) {
            ll y1,y2,x2;
            cin >> y1 >> y2 >> x2;
            y_coordinates[2*i]=y1;
            y_coordinates[2*i+1]=y2;
            pos_corners.push_back({x2,y1});
            neg_corners.push_back({x2,y2});
        }
        for (int i=0; i<4*n; ++i) {
            cin >> slopes[i];
        }
        vector<ll> neg_slopes,pos_slopes;
        for (ll s:slopes) {
            if (s<0) {
                neg_slopes.push_back(s);
            } else {
                pos_slopes.push_back(s);
            }
        }
        if (neg_slopes.size()<n || pos_slopes.size()<n) {
            cout << -1 << '\n';
            continue;
        }
        sort(y_coordinates.begin(),y_coordinates.end());
        for (ll y:y_coordinates) {
            if (neg_corners.size()<neg_slopes.size()) {
                neg_corners.push_back({x1,y});
            } else {
                pos_corners.push_back({x1,y});
            }
        }
        if (neg_corners.size() != neg_slopes.size() || pos_corners.size() != pos_slopes.size() ) {
                cout << -1 << '\n';
                continue;
        }
        ll y_min=find_min_y(pos_corners,pos_slopes);
        ll y_max=find_max_y(neg_corners,neg_slopes);

        cout << y_max-y_min << '\n';
    }

    return 0;
}
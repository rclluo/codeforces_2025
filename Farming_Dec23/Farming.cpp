// you don't need to check every pair, only plants adjacent on the ranklist
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct plant {
    ll height;
    ll growth;
    int rank;
};

bool sort_by_rank(plant& a,plant& b ){
    return (a.rank<b.rank);
}

int divide(ll a,ll b) {
    return (a+b-1)/b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<plant> plants(n);
        for (int i=0; i<n; i++) {
            cin >> plants[i].height;
        }
        for (int i=0; i<n; i++) {
            cin >> plants[i].growth;
        }
        for (int i=0; i<n; i++) {
            cin >> plants[i].rank;
        }
        if (n==1) {
            if (plants[0].rank==0) {
                cout << 0 << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else if ( n==2) {
            sort(plants.begin(),plants.end(),sort_by_rank);
            if (plants[0].height>plants[1].height) {
                cout << 0 << '\n';
            } else {
                if (plants[0].growth<=plants[1].growth) {
                    cout << -1 << '\n';
                } else {
                    cout << divide((plants[1].height-plants[0].height+1),(plants[0].growth-plants[1].growth)) << '\n';
                }
            }
        } else {
            sort(plants.begin(),plants.end(),sort_by_rank);
            ll days=0,max_days=0;
            for (int i=0; i<n-1; i++){
                if (plants[i].height<=plants[i+1].height) {
                    if (plants[i].growth<=plants[i+1].growth) {
                        max_days=-1;
                        break;
                    } else {
                        days=divide((plants[i+1].height-plants[i].height+1),(plants[i].growth-plants[i+1].growth));
                        if (days>max_days) {
                            max_days=days;
                        }
                    }
                }
            }
            for (int i=0; i<n-1; i++){
                if ((plants[i].height+plants[i].growth*max_days)<=(plants[i+1].height+plants[i+1].growth*max_days)) {
                max_days=-1;
                break;
                }
            }      
            cout << max_days << '\n';
        }
    }
}
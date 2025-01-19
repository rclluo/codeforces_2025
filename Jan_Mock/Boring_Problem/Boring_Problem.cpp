// binary search

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    // ifstream cin("input.txt");
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> votes(n);
    vector<pair<ll,ll>> votes_copy(n);
    ll sum=0;
    for (int i=0; i<n; i++) {
        cin >> votes[i];
        votes_copy[i]={votes[i],i};
        sum+=votes[i];
    }
    sort(votes_copy.begin(),votes_copy.end(),greater<pair<ll,ll>>());
    ll votes_left=k-sum;
    for (int i=0; i<n; i++) {
        ll lower=0;
        ll upper=votes_left+1;
        while (lower<upper) {
            ll curr=(lower+upper)/2;
            ll num_votes=votes[i]+curr;
            ll remaining_votes=votes_left-curr;
            int j=lower_bound(votes_copy.begin(),votes_copy.end(),make_pair(num_votes,LLONG_MAX),greater<pair<ll,ll>>())-votes_copy.begin();
            int count=j;
            for (; j!=n; j++) {
                if (votes_copy[j].second!=i) {
                    if (remaining_votes>num_votes-votes_copy[j].first) {
                        remaining_votes-=num_votes-votes_copy[j].first+1;
                        count++;
                    } else {
                        break;
                    }
                }
            }
            if (count>=m) {
                lower=curr+1;
            } else {
                upper=curr;
            }
        }
        if (lower>votes_left) {
            cout << -1;
        } else {
            cout << lower;
        }
        if (i<n-1) {
            cout << ' ';
        }
    }
}
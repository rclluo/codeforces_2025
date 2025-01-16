#include <bits/stdc++.h>
using namespace std;
const int MAX_N=1e5;
pair<long long,long long> intervals[MAX_N];

int main() {
    ifstream cin("socdist.in");
    ofstream cout("socdist.out");
	int n,m;
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> intervals[i].first >> intervals[i].second;
	}
	sort(intervals,intervals+m);

	long long lower=0;
	long long upper=intervals[m-1].second-intervals[0].first+1;
	while (lower<upper) {
		long long mid=lower+(upper-lower+1)/2;
		int count=1;
		int interval_count=0;
		long long current=intervals[0].first;
		while (current+mid<=intervals[m-1].second) {
			while (current+mid > intervals[interval_count].second) {
				interval_count++;
			}
			current=max(intervals[interval_count].first,current+mid);
			count++;
			if (count==n) break;
		}

		if (count>=n) lower=mid;
		else upper=mid-1;
	}
	cout << lower << '\n';
}
#include <bits/stdc++.h>
using namespace std;

int n,m;

bool check(int w,vector<pair<int,int>>&intervals) {
	int curr_int=0;
	int curr_pos=intervals[0].first;
	int count=0;
	while (curr_int<m) {
		curr_pos=max(curr_pos,intervals[curr_int].first);
		while (curr_pos<=intervals[curr_int].second) {
			count++;
			curr_pos+=w;
		}
		curr_int++;
	}
	if (count>=n) {
		return true;
	} else {
		return false;
	}
}

int main() {
    ifstream cin("socdist.in");
    ofstream cout("socdist.out");
	cin >> n >> m;
	vector<pair<int,int>> intervals(m);
	for (int i=0; i<m; i++) {
		cin >> intervals[i].first >> intervals[i].second;
	}
	sort(intervals.begin(),intervals.end());
	long long lower=0;
	long long upper=intervals[m-1].second-intervals[0].first+1;
	while (lower<upper) {
		long long curr=lower+(upper-lower+1)/2;
		if (check(curr,intervals)) {
			lower=curr;
		} else {
			upper=curr-1;
		}
	}
	cout << lower;
}
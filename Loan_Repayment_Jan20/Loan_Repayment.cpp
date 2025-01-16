#include <bits/stdc++.h>
using namespace std;

long long n,k,m;

bool check(long long w,long long days) {
	long long g=0;
	while (days>0 && g<n) {
		long long y=(n-g)/w;
		if (y<m) {
			long long leftover=((n-g)+(m-1))/m;
			return leftover<=days;
		}
		long long repeat_days=n-(w*y);
		long long num_days=min((repeat_days-g)/y+1,days);
		g+=y*num_days;
		days-=num_days;
	}
	return g>=n;
}

int main() {
    ifstream cin("loan.in");
    ofstream cout("loan.out");
    cin >> n >> k >> m;
    long long lower=1,upper=LLONG_MAX/2;
    long long curr;
    while (upper>lower) {
        curr=(lower+upper+1)/2;
        if (check(curr,k)) {
            lower=curr;
        } else {
            upper=curr-1;
        }
    }
    cout << lower;
}
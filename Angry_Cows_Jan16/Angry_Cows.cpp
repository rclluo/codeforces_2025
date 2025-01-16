#include <bits/stdc++.h>
using namespace std;

const int MAX_POS=1e9;

int main() {
	ifstream cin("angry.in");
	ofstream cout("angry.out");
	int n;
	cin >> n;
	vector<int> bales(n);
	for (int i=0; i<n; i++) {
		cin >> bales[i];
		bales[i] *= 2;
	}
	sort(bales.begin(),bales.end());
	function<bool(int,int,int,bool)> push=[&](int pos,int idx,int r,bool dir){if(idx>=n-1&&dir==0){return(idx>=n||pos+r>=bales[idx]);}if(idx<=0&&dir==1){return(idx<0||pos-r<=bales[idx]);}if(dir==0){if(pos+r>=bales.back())return true;int new_idx=idx;while(new_idx<n&&pos+r>=bales[new_idx]){new_idx++;}if(new_idx==idx){return false;}return push(bales[new_idx-1],new_idx,r-2,dir);}else{if(pos-r<=bales[0]){return true;}int new_idx=idx;while(new_idx<n&&pos-r<=bales[new_idx]){new_idx--;}if(new_idx==idx){return false;}return push(bales[new_idx+1],new_idx,r-2,dir);}return false;};
	int lower=0;
	int upper=MAX_POS*2;
	while (lower<upper) {
		int power=lower+(upper-lower)/2;
		int pos_lo=0;
		int pos_hi=MAX_POS*2;

		while (pos_lo<pos_hi) {
			int pos=pos_lo+(pos_hi-pos_lo+1)/2;
			int close=lower_bound(bales.begin(),bales.end(),pos)-bales.begin();
			if (close<n&&push(pos,close,power,1)) {
				pos_lo=pos;
			} else {
				pos_hi=pos-1;
			}
		}

		int close=upper_bound(bales.begin(),bales.end(),pos_lo)-bales.begin();
		if (push(pos_lo,close,power,0)) {
			upper=power;
		} else {
			lower=power+1;
		}
	}
	cout << fixed << setprecision(1) << (double)lower/2 << endl;
}

*/

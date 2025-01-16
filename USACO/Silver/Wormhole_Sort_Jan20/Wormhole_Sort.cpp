#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream cin("wormsort.in");
	ofstream cout("wormsort.out");
	int n,m;
	cin >> n >> m;
	vector<int> cows(n);
	for (int &cow : cows) {
		cin >> cow;
		cow--;
	}

	int max_width=0;
	vector<vector<pair<int, int>>> neighbors(n);
	for (int w = 0; w < m; w++) {
		int c1,c2,width;
		cin >> c1 >> c2 >> width;
		c1--;
		c2--;
		neighbors[c1].push_back({c2,width});
		neighbors[c2].push_back({c1,width});
		max_width=max(max_width,width);
	}

	int lower=0;
	int upper=max_width+1;
	int valid=-1;
	while (lower<=upper) {
		int mid=(lower+upper)/2;
		vector<int> component(n,-1);
		int curr_comp=0;
		for (int cow=0; cow<n; cow++) {
			if (component[cow]!=-1) { 
                continue; 
            }
			vector<int> frontier{cow};
			while (!frontier.empty()) {
				int curr=frontier.back();
				frontier.pop_back();
				component[curr]=curr_comp;
				for (const auto &[n,w] : neighbors[curr]) {
					if (component[n]==-1 && w>=mid) {
						frontier.push_back(n);
					}
				}
			}
			curr_comp++;
		}

		bool sortable=true;
		for (int cow=0; cow<n; cow++) {
			if (component[cow]!=component[cows[cow]]) {
				sortable=false;
				break;
			}
		}
		if (sortable) {
			valid=mid;
			lower=mid+1;
		} 
        else {
			upper=mid-1;
		}
	}
	cout << (valid==max_width+1 ? -1:valid) << endl;
}
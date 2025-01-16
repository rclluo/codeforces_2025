#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
int n,m,k;
int lft[100],rht[100];
int p[MAXN],c[MAXN],pos[MAXN],ans[MAXN];
vector<int> a[MAXN+1];
 
int main() {
    ifstream cin("swap.in");
    ofstream cout("swap.out");
	cin >> n >> m >> k;
	for(int i=0;i<m;i++) {
		cin >> lft[i] >> rht[i];
		lft[i]--;
        rht[i]--;
	}
	for (int i=0; i<n; i++) {
		p[i]=i;
		for (int j=0; j<m; j++) {
			if (p[i]>=lft[j] && p[i]<=rht[j]) {
				p[i]=rht[j]+lft[j]-p[i];
            }
        }
	}
	int curr=1;
	for (int i=0; i<n; i++) {
        if (!c[i]) {
            c[i]=curr;
            a[curr].push_back(i);
            int j=p[i];
            if (j!=i) {
                pos[j]=1;
            }
            while (j!=i) {
                a[curr].push_back(j);
                c[j]=curr;
                if (p[j]!=i) {
                    pos[p[j]]=1+pos[j];
                }
                j=p[j];
            }
            curr++;
        }
	}
	for (int i=0; i<n; i++) {
		ans[a[c[i]][(pos[i]+k)%a[c[i]].size()]]=i;
    }
	for (int i=0; i<n; i++) {
		cout << ans[i]+1 << '\n';
	}
}
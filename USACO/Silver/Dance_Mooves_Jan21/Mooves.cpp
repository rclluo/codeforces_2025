
#include <bits/stdc++.h> 
using namespace std;

struct DSU {
	vector<int> e;
	void init(int n) { e=vector<int>(n,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x]=get(e[x]); }
	bool sameSet(int a,int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x,int y) { 
		x=get(x),y=get(y);
		if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y];
		e[y]=x;
		return 1;
	}
};

int n,k;
const int MX=1e5+1;
int P[MX];
unordered_set<int> trav[MX];
unordered_set<int> components[MX];

int main() {
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		P[i]=i;
		trav[i].insert(i);
	}
	for (int i=0; i<k; i++) {
		int a,b;
		cin >> a >> b;
		trav[P[a]].insert(b);
		trav[P[b]].insert(a);
		swap(P[a],P[b]);
	}
	DSU dsu;
	dsu.init(n+1);
	for (int i=1; i<=n; i++) {
        dsu.unite(i,P[i]);
    }
	for (int i=1; i<=n; i++) {
		for (int a : trav[i]) {
            components[dsu.get(i)].insert(a);
        }
    }
	for (int i=1; i<=n; i++) {
        cout << components[dsu.get(i)].size() << '\n';
    }
}
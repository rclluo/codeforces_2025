#include <bits/stdc++.h>
using namespace std;

class DSU {
  private:
	vector<int> parents;
	vector<int> sizes;

  public:
	DSU(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}

	int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}

	bool connected(int x, int y) { return find(x) == find(y); }
};

struct wormhole {
    int a,b;
    int width;
};

int main() {
    ifstream cin("wormsort.in");
    ofstream cout("wormsort.out");
    int n,m;
    cin >> n >> m;
    vector<int> cows(n+1);
    for (int i=1; i<=n; i++) {
        cin >> cows[i];
    }
    vector<wormhole> wormholes(m);
    for (int i=0; i<m; i++) {
        cin >> wormholes[i].a >> wormholes[i].b >> wormholes[i].width;
    }
    sort(wormholes.begin(), wormholes.end(), 
        [](const wormhole &a, const wormhole &b) { 
            return a.width > b.width; 
        }
    );
    DSU dsu(n);
    int curr=0;
    int min_width=INT_MAX;
    for (int i=1; i<=n; i++) {
        while (!dsu.connected(i,cows[i])) {
            dsu.unite(wormholes[curr].a,wormholes[curr].b);
            min_width=wormholes[curr].width;
            curr++;
        }
    }
    if (min_width==INT_MAX) {
        min_width=-1;
    }
    cout << min_width;
}
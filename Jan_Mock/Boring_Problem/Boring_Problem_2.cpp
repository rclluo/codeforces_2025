// use 2d prefixes to keep track of connections and blue square count
// diff in each rectangle to find ans
// Preprocessing: O(NM)
// Per query: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    string str;
    vector<vector<bool>> grid(n+1,vector<bool>(m+1,0));
    char a;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a;
            grid[i][j]=(a=='1');
        }
    }
    vector<vector<int>> blue_pref(n+1,vector<int>(m+1,0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            blue_pref[i][j]=grid[i][j]+blue_pref[i-1][j]+blue_pref[i][j-1]-blue_pref[i-1][j-1];
        }
    }
    vector<vector<int>> cons_pref(n+1,vector<int>(m+1,0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cons_pref[i][j]=(grid[i][j] && grid[i-1][j])+(grid[i][j] && grid[i][j-1])+cons_pref[i-1][j]+cons_pref[i][j-1]-cons_pref[i-1][j-1];
        }
    }
    vector<vector<int>> cons_pref_horizontal(n+1,vector<int>(m+1,0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cons_pref_horizontal[i][j]=cons_pref_horizontal[i][j-1]+(grid[i][j] && grid[i-1][j]);
        }
    }
    vector<vector<int>> cons_pref_vertical(m+1,vector<int>(n+1,0));
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cons_pref_vertical[i][j]=cons_pref_vertical[i][j-1]+(grid[j][i] && grid[j][i-1]);
        }
    }
    int x1,y1,x2,y2;
    int blue,cons;
    for (int i=0; i<q; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        blue=blue_pref[x2][y2]-blue_pref[x1-1][y2]-blue_pref[x2][y1-1]+blue_pref[x1-1][y1-1];
        cons=cons_pref[x2][y2]-cons_pref[x1-1][y2]-cons_pref[x2][y1-1]+cons_pref[x1-1][y1-1];
        cons-=cons_pref_horizontal[x1][y2]-cons_pref_horizontal[x1][y1-1];
        cons-=cons_pref_vertical[y1][x2]-cons_pref_vertical[y1][x1-1];
        cout << blue-cons << '\n';
    }
}
/*

0 0 0 0 0
0 0 1 1 1
0 0 2 3 3
0 0 4 5 5

0 0 0 0 0
0 1 1 0 1
0 0 1 1 0
0 1 1 0 1
*/

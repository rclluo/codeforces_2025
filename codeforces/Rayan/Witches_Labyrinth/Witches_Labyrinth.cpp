#include <bits/stdc++.h>
using namespace std;

vector<string> graph(1000);
vector<vector<bool>> visited(1000,vector<bool>(1000));

int n,m;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

void bfs(const int x,const int y) {
    visited[x][y]=true;
    queue<pair<int,int>> que;
    que.push(make_pair(x,y));
    while(!que.empty()) {
        const auto& p=que.front();
        que.pop();

        for (int i=0; i<4; i++) {
            int xx=p.first+dx[i],yy=p.second+dy[i];
            if (0<=xx && xx<n && 0<=yy && yy<m) {
                if (!((graph[xx][yy]=='U' && i==0) || (graph[xx][yy]=='D' && i==1) || (graph[xx][yy]=='L' && i==2) || (graph[xx][yy]=='R' && i==3))) {
                    continue;
                }
                if (graph[xx][yy] != '?' && !visited[xx][yy]) {
                    que.push(make_pair(xx,yy));
                    visited[xx][yy]=true;
                }
            }
        }
    }
}

void expend(const int n,const int m) {
    for (int j=0;j<m; j++) {
        if (graph[0][j]=='U' && !visited[0][j]) {
            bfs(0,j);
        }
    }
    for (int j=0; j<m; j++) {
        if (graph[n-1][j]=='D' && !visited[n-1][j]) {
            bfs(n-1,j);
        }
    }
    for (int i=0; i<n; i++) {
        if (graph[i][0]=='L' && !visited[i][0]) {
            bfs(i,0);
        }
    }
    for (int i=0; i<n; i++) {
        if (graph[i][m-1]=='R' && !visited[i][m-1]) {
            bfs(i,m-1);
        }
    }
}

void check() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (graph[i][j]=='?') {
                bool has_no_vis=false;
                for (int k=0; k<4; k++) {
                    int xx=i+dx[k],yy=j+dy[k];
                    if (0<=xx && xx<n && 0<=yy && yy<m) {
                        if (!visited[xx][yy]) {
                            has_no_vis=true;
                            break;
                        }
                    }
                }
                if(!has_no_vis) visited[i][j]=true;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        graph[i]=s;
        for (int j=0; j<m; j++) {
            visited[i][j]=0;
        }
    }

    expend(n,m);
    check();
    int ans=n*m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (visited[i][j]) {
                ans--;
            }
        }
    }
    cout << ans << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
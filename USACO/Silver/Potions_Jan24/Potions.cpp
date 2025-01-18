#include <bits/stdc++.h>
using namespace std;

int* numleaves;
int potions(int curr,int par,vector<vector<int>>& graph,int* modpots) {
    int sum=0;
    for (int a:graph[curr]) {
        if (a==par) {
            continue;
        }
        sum+=potions(a,curr,graph,modpots);
    }
    sum+=modpots[curr];
    return min(sum,numleaves[curr]);
}

int leaves_count(int curr, int par, vector<vector<int>>& graph) {
    if ((graph[curr].size()==1 && graph[curr][0]==par) || graph[curr].size()==0) {
        numleaves[curr]=1;
        return 1;
    }
    int sum=0;
    for (int a:graph[curr]) {
        if (a==par) {
            continue;
        }
        sum+=leaves_count(a,curr,graph);
    }
    numleaves[curr] = sum;
    return sum;
}

int main() {
    int n;
    cin >> n;
    int s = 0;
    int* pots = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> pots[i];
        pots[i]--;
    }
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    numleaves=new int[n];
    int leaves=leaves_count(s,-1,graph);
    int* modpots = new int[n]();
    for (int i = 0; i < leaves; i++) {
        modpots[pots[i]]++;
    }
    cout << potions(s, -1, graph, modpots) << '\n';
}
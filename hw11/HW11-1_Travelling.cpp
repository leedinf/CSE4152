#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<int> vs;
int N;
int mn;
void dfs(int t,const vector<vector<int>> &cost_graph, int cost, int cnt){

    for(int i=0;i<N;i++){
        if(cost+cost_graph[t][i] > mn) continue;
        if(vs[i]==0 && i!=t){
            vs[i]=1;
            dfs(i,cost_graph,cost+cost_graph[t][i],cnt+1);
            vs[i]=0;
        }
    }
    if(cnt==N-1){
        mn = min(mn,cost + cost_graph[t][0]);
        
        return;
    }

    return;
}
int travelling(int N, const vector<vector<int>> &cost_graph) {
    vs[0]=1;
    dfs(0,cost_graph,0,0);

    return mn;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    mn = INT_MAX;
    vs = vector<int>(N);
    vector<vector<int>> cost_graph(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost_graph[i][j];
        }
    }

    int ans = travelling(N, cost_graph);
    cout << ans << '\n';

    return 0;
}
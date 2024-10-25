#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
int n;
int maxind=0;
int maxA;
int maxB;
double Max=0;
double arr[3000000];
double brr[3000000];
int vs[3000000];
void init(){
    for(int i=0;i<=n+2;i++){
        vs[i]=0;
    }
}
void dfs(double dist,int t, vector<vector<pair<int, double>>> &adj){
    if(vs[t]==1) return;
    vs[t] =1;
    if(Max < dist){
        maxind = t;
        Max = dist;
    }
    for(auto k : adj[t]){
        dfs(k.second + dist,k.first, adj);
    }

}
void dfsA(double dist,int t, vector<vector<pair<int, double>>> &adj){
    if(vs[t]==1) return;
    vs[t] =1;
    if(adj[t].size()==1) arr[t] = dist;
    for(auto k : adj[t]){
        dfsA(k.second + dist,k.first, adj);
    }
}
void dfsB(double dist,int t, vector<vector<pair<int, double>>> &adj){
    if(vs[t]==1) return;
    vs[t] =1;
    if(adj[t].size()==1) brr[t] = dist;
    // cout<<"brr: "<< t<<' '<<brr[t]<<'\n';
    for(auto k : adj[t]){
        dfsB(k.second + dist,k.first, adj);
    }
}       
double findlong(int a,  vector<vector<pair<int, double>>> &adj){
    double b;
    Max = 0;
    maxind = 0;
    init();
    dfs(0,a, adj);
    maxA = maxind;
    // cout<<"!!!"<<Max<<' '<<maxind<<'\n';
    Max = 0;
    maxind = 0;
    init();
    dfs(0,maxA, adj);
    maxB = maxind;
    return Max;
}

double makelong(vector<vector<pair<int, double>>> &adj){
    for(int i=0;i<=n;i++){
        arr[i]=0;
        brr[i]=0;
    }
    // cout<<maxA<<' '<<maxB<<'\n';

    init();
    dfsA(0,maxA,adj);
    init();
    dfsB(0,maxB,adj);

    for(int i=1;i<=n;i++){
        if(i==maxA || i==maxB) continue;
        if(arr[i] > brr[i]) arr[i]=0;
        else brr[i] = 0;
    }
    double ma=0;
    double mb=0;
    for(int i=1;i<=n;i++){
        if(i==maxA || maxB==i) continue;
        ma=max(arr[i],ma);
    }
    // cout<<'\n';
    for(int i=1;i<=n;i++){
        if(i==maxA || maxB==i) continue;
        mb=max(brr[i],mb);
    }

    for(int i=1;i<=n;i++){
        // cout<<arr[i]<<' '<<brr[i]<<'\n';
    }
    return max(ma,mb) / 2;
}
int main() {
    // Do NOT delete these lines unless you know what you are doing:
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(12);

    int T;
    cin >> T;

    while (T--) {
        cin >> n;

        double max_dist = 0;

        vector<vector<pair<int, double>>> adj(n + 1);

        // input edge info
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            double w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        // TODO
        findlong(1,adj);
        double ekq = makelong(adj);
        // Print the minimum possible maximum distance
        cout << ekq<<'\n';
    }

    return 0;
}

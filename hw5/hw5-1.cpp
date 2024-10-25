#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int vs[300000];
int maxind;
double maxL;
void dfs_findlong(vector<vector<pair<int,double>>>& adj,int now,int n, double c, int m){
    
    if(vs[now] == m) return;
    vs[now]=m;
    for(auto k: adj[now]){
        if(vs[k.first]!=m){//ㄳasdasd
        int a;
            if(c+k.second>maxL){
                maxL = c+k.second;
                maxind = k.first;
            }
            dfs_findlong(adj,k.first,n,c+k.second,m);
        }
    }
}

double find_length(vector<vector<pair<int,double>>>& adj,int n){
    int long1,long2;

    maxind =0;
    maxL = 0;
    

    dfs_findlong(adj,1,n,0,1);
    long1 = maxind;
    
    maxind =0;
    maxL = 0;
    dfs_findlong(adj,long1,n,0,2);

    return maxL;
}
int main() {
    // Do NOT delete these lines unless you know what you are doing:
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(6);

    int T;
    cin >> T;
    
    while (T--) {

        maxL = 0;
        maxind = 0;
        int n;
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
        max_dist = find_length(adj,n)/2.0;
        // Print the minimum possible maximum distance
        cout << max_dist << "\n";
    }

    return 0;
}
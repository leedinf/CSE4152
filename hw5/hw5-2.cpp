#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int vs[300000];
int maxind;
double maxL;
double m2,m3;
int long1, long2;

void dfs_findlong(vector<double> &arr2,vector<double> &arr3,vector<vector<pair<int,double>>>& adj, int now, int n, double c, int m){

    
    if(vs[now] == m) return; 
    vs[now] = m; 

    for(auto k: adj[now]){
        if(vs[k.first]!=m){
            if(adj[k.first].size()==1){
                if(m==2){
                    arr2[k.first] = c+k.second;
                }
                if(m==3){
                    arr3[k.first] = c+k.second;
                }
            }
            if(c+k.second>maxL){
                    maxL = c+k.second;
                    maxind = k.first;
            }
            dfs_findlong(arr2,arr3,adj,k.first,n,c+k.second,m);
        }
    }
}


void find_length(vector<double>& arr2,vector<double>& arr3,vector<vector<pair<int,double>>>& adj, int n){
    
    int mark=1;
    m2=0; m3=0; 
    maxind = 0;
    maxL = 0;
    dfs_findlong(arr2,arr3,adj,1,n,0,mark++);//mark = 1
    long1 = maxind;

    maxind = 0;
    maxL = 0;
    dfs_findlong(arr2,arr3,adj,long1,n,0,mark++);//m2
    long2 = maxind;

    maxind = 0;
    maxL = 0;
    dfs_findlong(arr2,arr3,adj,long2,n,0,mark++);//m3
    for(int i=1;i<=n;i++){
        if(arr2[i]<arr3[i]) arr3[i]=0;
        else arr2[i]=0;
    }
    for(int i=1;i<=n;i++){
        if(m2<arr2[i] && i!=long2){
            m2 = arr2[i];
        }
        if(m3<arr3[i] && i!=long1){
            m3 = arr3[i];
        }   
    }
    
    cout<<((m2 > m3) ? m2 : m3)/2.0<<'\n';


    return;
}
int main() {
    // Do NOT delete these lines unless you know what you are doing:
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(12);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        for(int i=0;i<=n;i++){
            vs[i]=0;
        }

        vector<vector<pair<int, double>>> adj(n + 1);
        vector<double> arr2(n+1,0);
        vector<double> arr3(n+1,0);
        // input edge info
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            double w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        find_length(arr2,arr3,adj,n);

    }

    return 0;
}

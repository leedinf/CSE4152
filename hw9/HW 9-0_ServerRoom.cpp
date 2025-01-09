    #includeiostream
    #includealgorithm
    #includevector
    #includebitsstdc++.h
    using namespace std;
 
    vectorvectorint adj;
    int C, H, R, p1, p2;
    for(int i = N-1; i=0;i--){
        int t = lower_bound(s+i,s+N,arr[i].end) - s;
        dp[i] = max(dp[i+1],arr[i].value+dp[t]);
    }
    int cnt;
    int s[1000001];
    struct K{
        int start;
        int end;
        int value;
    };
    K arr[1000001];
    
    int dfs(int t, vectorint& dom, vectorint& vs){
        if(vs[t]==1) return 0;
        if(vs[t]==0 && adj[t].size()==0){
            cnt++;
            vs[t]=1;
            dom[t]=1;
            return 0;
        }섬처리
        vs[t]=1;
        int sig=0;

        for(auto k  adj[t]){
            if(vs[k]==0){
                sig+=dfs(k,dom,vs);
            }
        }
        if(sig0){
            dom[t]=1;
            cnt++;
            for(auto k adj[t]) dom[k]=1;
            return 0;
        }
        if(dom[t]==0) return 1;
        else return 0;
    }

    int solve(int r) {
        vectorint dom(r,0);
        vectorint vs(r,0);
        cnt=0;
        for(int i=0;ir;i++){
            if(vs[i]==0){
                if(dfs(i,dom,vs) == 1) cnt++;
            }
        }
        return cnt;
    }

    int main(void) {
        ios_basesync_with_stdio(false);
        cin.tie(nullptr);

        cin  C;     

        while (C--) {
            cin  R  H;
            adj = vectorvectorint(R);

            for (int i = 0; i  H; i++) {
                cin  p1  p2;

                adj[p1].push_back(p2);
                adj[p2].push_back(p1);
            }
            cout  solve(R)'n';
        }

        return 0;
    }

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<queue>

using namespace std;
queue<int> q;
int here=0;
vector<int> pebbles(int N, int K, string S) {
    vector<int> ans;
    int len=0;
    int mx=0;
    for(int i=0;i<N;i++){
        if(S[i]=='W'){
            if(q.size()<K){
                q.push(i);
                len++;
            }
            else{
                int z = q.front();
                q.pop();
                q.push(i);
                len = i - z;
            }
        }
        else{
            len++;
        }
        if(len>mx){
            mx=len;
            if(!q.empty())here=q.front();
        }
    }
    int cnt=0;
    for(int i=here;i<N;i++){
        if(S[i]=='W'){
            ans.push_back(i);
            cnt++;
        }
        if(cnt==K) break;
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main() {
    int N, K;
    string S;

    cin >> N >> K >> S;

    vector<int> ans = pebbles(N, K, S);

    cout << ans.size() << '\n';
    for (int x: ans) cout << x + 1 << ' ';
    cout << '\n';

    return 0;
}
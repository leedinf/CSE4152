#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;
void push_s(unordered_set<int> &vs, queue<pair<string,int>> &q, string &s, int n){
    for(auto k : s){
        if (k == '0') continue;
        int tmp = ((k-'0')%n);
        if(!vs.count(tmp)) q.emplace(string(1,k),tmp);
    }
}
string Gifts(const string& d, int n, int m) {
    unordered_set<int> vs;
    queue<pair<string,int>> q;
    string answer = "IMPOSSIBLE";

    string z = d;
    sort(z.begin(),z.end());
    
    int g = n + m;

    push_s(vs,q,z,n);
    while(!q.empty()){
        auto [tmp, mod] = q.front();//string, int
        q.pop();

        size_t g_size = to_string(g).size();
        if(mod == m){
            if(tmp.size()>g_size) return tmp;
            else if(tmp.size() == g_size && stoll(tmp)%n == m) return tmp; 
        }

        if(tmp.size() > g_size && vs.count(mod)==0) vs.insert(mod);

        for(auto k : z){
            int nxt = (mod*10 + (k-'0'))%n;
            if(vs.count(nxt) == 0) q.emplace(tmp+k,nxt);
        }

    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    int test_num;
    cin >> test_num;

    while (test_num--) {
        string d;
        int n, m;
        cin >> d >> n >> m;

        cout << Gifts(d, n, m) << "\n";
    }

    return 0;
}
ㅌ
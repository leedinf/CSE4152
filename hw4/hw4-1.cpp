#include <iostream>
#include <vector>
#include<stack>
using namespace std;

bool can_rearrange_trains(int N, vector<int> &trains) {
    // TODO:
    int t = 1;
    int ind = 0;
    stack<int> st;
    while(1){
        
        if(t>N) return true;
        if(ind==N && !st.empty() && st.top() != t) return false;
        if(ind < N && trains[ind]==t){
            t++;
            ind++;
        }
        else if(!st.empty() && st.top()==t){
            t++;
            st.pop();
        }
        else{
            st.push(trains[ind]);
            ind++;
        }
    }
}

int main() {
    // Do NOT delete these lines unless you know what you are doing:
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> trains(N);
        for (int i = 0; i < N; i++) {
            cin >> trains[i];
        }

        cout << can_rearrange_trains(N, trains) << '\n';
    }

    return 0;
}
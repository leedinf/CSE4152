#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool can_rearrange_trains(int N, vector<int> &trains) {
    // TODO:
    stack<int> st;
    st.push(0);
    int next = 1;
    int idx = 0;
    while(next<N){
        if(idx>N-1 && st.top() != next) return 0;
        if(trains[idx] == next){
            next++;
            idx++;
        }
        else if(st.top() == next){
            next ++;
            st.pop();
        }
        else{
            st.push(trains[idx]);
            idx++;
        }
    }
    return 1;
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
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
struct query {
    int R1, C1, R2, C2;
    double V;
};
vector<vector<double>> arr;
void matrix_addition(int N, vector<vector<double>>& A, int Q, vector<query>& queries) {
    //TODO:
    
    int i=0;
    while(i<Q){
        int r1,c1,r2,c2;
        double v;
        r1=queries[i].R1;
        c1=queries[i].C1;
        r2=queries[i].R2;
        c2=queries[i].C2;
        v = queries[i].V;
        r1--;
        c1--;
        r2--;
        c2--;
        arr[r1][c1] +=v;
        arr[r2+1][c2+1] +=v;
        arr[r2+1][c1] -=v;
        arr[r1][c2+1] -=v;
        i++;
    }
    for(int i=0;i<N;i++){
        for(int j=1;j<N;j++){
            arr[i][j] += arr[i][j-1];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=1;j<N;j++){
            arr[j][i] += arr[j-1][i];
        }
    }
    for(int j=0;j<N;j++){
        for(int k=0;k<N;k++){
            A[j][k] += arr[j][k];
        }
    }
    // for(int j=0;j<N;j++){
    //     for(int k=0;k<N;k++){
    //         cout<<arr[j][k]<<' ';
    //     }
    //     cout<<'\n';
    // }
}

int main() {
    // Do NOT delete these lines unless you know what you are doing:
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    arr.resize(N+1,vector<double>(N+1));
    vector<vector<double>> A(N, vector<double>(N));
    for (int i = 0; i < N+1; i++) {
        for (int j = 0; j < N+1; j++) {
            arr[i][j]=0;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    int Q;
    cin >> Q;

    vector<query> queries(Q);
    for (int i = 0; i < Q; i++) {
        cin >> queries[i].R1 >> queries[i].C1 >> queries[i].R2 >> queries[i].C2 >> queries[i].V;
    }

    matrix_addition(N, A, Q, queries);

    cout << fixed << setprecision(12);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int smallest=-10000000;


vector<int> findNLargestElements(vector<vector<int>>& matrix, int n) {
    vector<int> largestElements;
    vector<int> index(n);
    // TODO:
    for(int i=0;i<n;i++){//초기화 
        index[i] = 0;
        for(int j=1;j<n;j++){
            if(matrix[i][index[i]] < matrix[i][j]){
                index[i] = j;
            }
        }
    }
    for(int t=0;t<n;t++){
        int big_index;
        big_index=0;
        for(int i=1;i<n;i++){ // 큰거중 제일큰거찾기
            if(matrix[i][index[i]] > matrix[big_index][index[big_index]]){
                big_index=i;
            }
        }
        largestElements.push_back(matrix[big_index][index[big_index]]);
        matrix[big_index][index[big_index]] = -100000000;

        for(int i=0;i<n;i++){ // 큰거찾은라인 다시큰거찾기
            if(matrix[big_index][index[big_index]] < matrix[big_index][i]){
                index[big_index] = i;
            }
        }
    }
    
    return largestElements;
}

int main() {
    // Do NOT delete these lines unless you know what you are doing:
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> M(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> M[i][j];
            // if(i==0 && j ==0) smallest=M[i][j];
            // else {
                // smallest = min(smallest, M[i][j]);
            // }
        }
    }
    // smallest--;
    vector<int> largestElements = findNLargestElements(M, n);

    for (int element : largestElements) {
        cout << element << "\n";
    }

    return 0;
}

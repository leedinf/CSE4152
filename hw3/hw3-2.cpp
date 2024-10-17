#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define M_PI 3.14159265358979323846 
struct point {
    double x, y;

    point() : x(0), y(0) {}
    point(double x, double y) : x(x), y(y) {}
};

bool half_circle_property(int N, vector<point>& A) {
    //TODO:
    double pi = M_PI;
    vector<double> arr;
    for(int i=0;i<N;i++){
        arr.push_back(atan2(A[i].y,A[i].x));
    }
    sort(arr.begin(),arr.end());
    for(int i=1;i<N;i++){
        if(arr[i]-arr[i-1]>=M_PI - 0.000001) return true;
    }
    if(2*pi - arr[N-1] + arr[0] >= M_PI - 0.000001) return true;

    return false;
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

        vector<point> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i].x >> A[i].y;
        }

        bool answer = half_circle_property(N, A);

        cout << answer << '\n';
    }

    return 0;
}
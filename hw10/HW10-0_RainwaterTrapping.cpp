#include <iostream>
#include <vector>
using namespace std;

int maxWater(vector<int>& arr) {
    int res = 0;
    int l,r,lm,rm;
    l=0; r=arr.size()-1; lm=0; rm =0;

    while(l<=r){
        if(arr[l]<arr[r]){
            if(arr[l]<lm){
                res+=lm-arr[l];
            }
            else{
                lm = arr[l];
            }
            l++;
        }
        else{
            if(arr[r]<rm){
                res+=rm-arr[r];
            }
            else{
                rm = arr[r];
            }
            r--;
        }
    }

    return res;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test_num;
    cin >> test_num; 

    for (int t = 0; t < test_num; ++t) {
        int B;
        cin >> B; 

        vector<int> arr(B);
        for (int i = 0; i < B; ++i) {
            cin >> arr[i];
        }

        cout << maxWater(arr) << endl;
    }

    return 0;
}
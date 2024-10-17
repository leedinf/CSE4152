#include<iostream>
#include <vector>

using namespace std;

int findsum(int l, int r, vector<int> arr){
    if(l==r) return max(0,arr[l]);

    int mid = (l+r)/2;

    int leftsum = findsum(l,mid,arr);
    int rightsum = findsum(mid+1,r,arr);

    int maxleftsum = 0;
    int maxrightsum = 0;
    int midtoleft = 0;
    int midtoright = 0;

    for(int i = mid; i>=l; i--){
        midtoleft +=arr[i];
        maxleftsum = max(maxleftsum, midtoleft);
    }
    for(int i = mid+1; i<=r; i++){
        midtoright += arr[i];
        maxrightsum = max(maxrightsum, midtoright);
    }

    return max(leftsum, max(rightsum,maxleftsum+maxrightsum));
}
int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    int max_num=0;
    for(int i=0;i<n;i++) cin>>arr[i];
    int maxtail=0;

    for(int i=0;i<n;i++){
        maxtail= max(0,maxtail+arr[i]);
        max_num = max(max_num, maxtail);
    }
    cout<<max_num;
    // max_num=findsum(0,n-1,arr);

    // cout << max_num;


    return 0;
}
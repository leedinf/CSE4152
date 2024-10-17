#include<iostream>
#include<vector>
using namespace std;


vector<int> arr;
vector<int> brr;
int length=0;
void wornl(int a,int n, int len){
    if(a==n){
        if(brr.empty() || len < length){
            brr = arr;
            length = len;
        }
        return;
    }
    if(a>n) return;
    if(len>length && length != 0) return;
    int t;

    for(int i=len-1;i>=0;i--){
        if(len-1-i>3)continue;
        if(arr[i] <= n-a){
            t = a + arr[i];
            arr.push_back(t);
            wornl(t,n,len+1);
            arr.pop_back();
        }
    }
    
}
int main(){

    int n;
    cin >> n;

    
    arr.push_back(1);
    wornl(1,n,1);
    cout<< length-1 <<' ';
    for(int i=0;i<length;i++){
        cout<< brr[i] <<' ';
    }

    return 0;
}


/*
vector<int> min_multiplications(int n) {
    vector<int> powers;
    
    powers.push_back(n);
    while(n>1){
        if(n%2==0){
            if((n/2)%2 == 0){ // 둘로 나눈게 짝수면 ..
                n/=2;
                powers.push_back(n);
            }
            else {// 홀수면.. 다르게 나누는게 낫지 않을까..
                n-=2;
                if(n==0){
                    powers.push_back(1);
                    break;
                }
                else powers.push_back(n);
            }
        }
        else{
            n--;
        }
    }
    vector<int> tmp;
    for(int i=powers.size()-1;i>=0;i--){
        tmp.push_back(powers[i]);
    }
    return tmp;
}
*/
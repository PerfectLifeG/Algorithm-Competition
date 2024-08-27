#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000;
int n;
int C(int b,int a){
    int ans=1;
    for(int i=0;i<a;i++){
        if(1.0*ans*(b-i)/(a+i)>n||ans*(b-i)/(a+i)<=0){
            return n+1;
        }
        ans=ans*(b-i)/(i+1);
    }
    return ans;
}
// int C(int a, int b)//直接暴力求组合数 
// {
//     if(b > a-b) b = a-b;
//     int ans = 1;
//     for(int i = 1; i <= b; i++)  ans*a/1*(a-1)/2
//     {
//         ans = ans*(a-i+1)/i;
//         if(ans > n)//防止越界 
//             return n+1; 
//     }
//     return ans;
// } 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;int ans;
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=16;i>=1;i--){
        int l=2*i-1,r=1000000001;
        while(l+1!=r){
            int mid=l+r>>1;
            if(C(mid,i)>=n)r=mid;
            else l=mid;
        }
        if(C(r,i)==n){
            cout<<r*(1+r)/2+i+1;
            return 0;
        }
    }
    return 0;
}
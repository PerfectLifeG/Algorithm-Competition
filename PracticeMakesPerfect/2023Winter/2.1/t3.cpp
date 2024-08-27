#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    int cnt=0;
    if(n==1||n==2){cout<<0;return 0;}
    while(n!=2){
        n=n/(n/2+1);
        cnt++;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
int f[3]={1,1,2};
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cout<<f[i%3]<<' ';
    }
    return 0;
}
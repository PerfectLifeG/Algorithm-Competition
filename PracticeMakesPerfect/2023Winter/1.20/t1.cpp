#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    int s=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(a<0)s+=a;
        else if(a&1)s+=a;
        else if(a>0)s+=1;
    }
    cout<<s;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=10010;
#define int long long
signed main(){
    int n,k,a,b;
    cin>>n>>k>>a>>b;
    int lt=(n-1)*a;
    int dt=(k-1)*b+(n-1)*b;
    if(dt>lt)cout<<2;
    else if(dt<lt)cout<<1;
    else if(dt==lt)cout<<0;
    return 0;
}
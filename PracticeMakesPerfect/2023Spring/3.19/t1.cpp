#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10010;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        int a,b,c;cin>>a>>b>>c;
        if(a+b==c)cout<<'+'<<endl;
        else cout<<'-'<<endl;
    }
    return 0;
}
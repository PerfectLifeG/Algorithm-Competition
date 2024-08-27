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
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int p=c-a;
        int q=d-b;
        if(q<0)cout<<-1<<endl;
        else if(p<0)cout<<-p+2*q<<endl;
        else if(p>q)cout<<-1<<endl;
        else cout<<p+2*(q-p)<<endl;
    }
    return 0;
}
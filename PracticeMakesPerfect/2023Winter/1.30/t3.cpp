#include<bits/stdc++.h>
using namespace std;
const int N=10010;
#define int long long 
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        int a,b,c;cin>>a>>b>>c;
        int s=a+b+c;if(s-2*a<=0||s-2*b<=0||s-2*c<=0||(s-2*a)%2||(s-2*b)%2||(s-2*c)%2){cout<<"NO"<<endl;continue;}
        int la=(s-2*a)/2;int lb=(s-2*b)/2;int lc=(s-2*c)/2;
        if(la+lb<=lc||la+lc<=lb)cout<<"NO"<<endl;continue;
        cout<<"YES"<<endl;
        cout<<la<<' '<<lb<<' '<<lc<<endl;
    }
    return 0;
}
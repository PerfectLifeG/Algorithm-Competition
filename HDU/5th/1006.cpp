#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    string s;cin>>s;
    int n=s.size();
    s=' '+s;
    vector<int>f(n+1,0);
    int r=0,g=0,b=0;
    int idr=0,idg=0,idb=0;
    int mxr=0,mxg=0,mxb=0;
    for(int i=1;i<=n;i++){
        f[i]=f[i-1];
        if(s[i]=='R'){if(r==0)idr=i;r++;mxr=max(mxr,i);}
        if(s[i]=='B'){if(b==0)idb=i;b++;mxg=max(mxg,i);}
        if(s[i]=='G'){if(g==0)idg=i;g++;mxb=max(mxb,i);}
        if(r==3){
            f[i]=max(f[i],f[idr-1]+1);
            r=0;
        }
        else if(b==3){
            f[i]=max(f[i],f[idb-1]+1);
            b=0;
        }
        else if(g==3){
            f[i]=max(f[i],f[idg-1]+1);
            g=0;
        }
        if(mxr&&mxb&&mxg){
            if(i<n){
                f[i+1]=max(f[i+1],f[min({mxr,mxg,mxb})-1]+1);
            }
            mxr=mxb=mxg=0;
        }
    }
    cout<<f[n]<<endl;
    for(int i=1;i<=n;i++)
    cout<<i<<' '<<f[i]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
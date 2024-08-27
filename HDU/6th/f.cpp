#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=310;
const int mod=998244353;
const int INF=0x3f3f3f3f;
vector<int>mp;
inline int read()
{
  int x=0,f=1;
  char ch=getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-')
      f=-1;
    ch=getchar();
  }
  while(ch>='0' && ch<='9')
    x=x*10+ch-'0',ch=getchar();
  return x*f;
}
int v[N][N*N];
int v2[N][N*N];
int a[N],s[N];
void solve()
{
    int n;n=read();
    memset(v,0,sizeof v);
    memset(v2,0,sizeof v2);
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        for(int l=1;l<=n;l++){
            for(int r=l;r<=n;r++){
                if(l<=i&&r>=i)
                    v[i][s[r]-s[l-1]]++;
                else v2[i][s[r]-s[l-1]]++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=300;j++){
            int cnt=0;
            for(auto k:mp){
                if(k-j+a[i]>=0)cnt+=v[i][k-j+a[i]];
                cnt+=v2[i][k];
            }
            ans=max(ans,cnt);
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    _=read();
    for(int i=1;i<=300;i++){
        mp.push_back(i*i);
    }
    while(_--)solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'

char buf[1 << 21], *p1 = buf, *p2 = buf, obuf[1 << 21], *o = obuf, of[35];
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
 
inline int read()
{
  int s = 0, f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) s = s * 10 + c - '0';
  return s * f;
}


// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,q;
    n=read();q=read();
    vector<int>a(n+1);
    vector<int>b(n+1);
    // vector<int>c(n+1);
    // vector<int>s(n+1);
    vector<int>s2(n+1);
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){
        b[i]=read();
        // c[i]=b[i];
    }
    // for(int i=1;i<=n;i++)s[i]=c[i]+s[i-1];
    for(int i=1;i<=n;i++)s2[i]=a[i]+s2[i-1];
    while(q--){
        int x;x=read();
        priority_queue<int>q;
        int sum=0;
        for(int i=1;i<=x;i++){
            q.push(b[i]);
            sum+=b[i];
        }
        int ans=sum+s2[x];
        // int t=s2[x];
        for(int i=x+1;i<=n;i++){
            q.push(b[i]);
            sum+=b[i];
            sum-=q.top();
            q.pop();
            //cout<<i<<' '<<sum<<' '<<
            ans=min(sum+s2[i],ans);
        }
        // cout<<ans<<endl;
        printf("%lld\n",ans);
    }
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
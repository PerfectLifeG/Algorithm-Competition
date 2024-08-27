#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define int long long
int n;
int e[N*2],ne[N*2],h[N],idx=0;
int f[N][3];
int a[N];

void add(int a,int b){
  e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int pre){
  f[u][0]=a[u],f[u][1] = f[u][2] = 0;
  bool flag=true;
  int tmp=1e18;
  for(int i=h[u];~i;i=ne[i]){
    int j=e[i];
    if(j==pre) continue;
    dfs(j,u);
    f[u][2]+=min(f[j][1],f[j][0]);
    f[u][0]+=min(min(f[j][0],f[j][1]),f[j][2]);
    if(f[j][0]<=f[j][1]){
      flag=false;
      f[u][1]+=f[j][0];
    }
    else{
      f[u][1]+=f[j][1];
      tmp=min(tmp,f[j][0]-f[j][1]);
    }
  }
  if(flag) f[u][1]+=tmp;
}

signed main(){
  int T;
  cin>>T;
  int i;
  while(T--)
  {
    scanf("%lld",&n);
    idx=0;
    for(i=1;i<=n;i++)
    {
      scanf("%lld",&a[i]);
      h[i]=-1;
    }
    for(int i=1;i<n;i++){
      int x,y;
      scanf("%lld%lld",&x,&y);
      add(x,y),add(y,x);
    }
    dfs(1,-1);
    int ans=min(f[1][0],f[1][1]);
    printf("%lld\n",ans);
  }
  return 0;
}
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
 vector<int>v;
 int i;
 int j;
 int k;
 int u=1;
 int sum[N];
 bool check(int mid)
{
 int i;
 int u=0;
 int cnt=0;
 for(i=1;i<=n;i++)
 {
  int j=i;
  int now=0;
  while(j<=n)
  {
   int t=(a[i]+a[j])/2;
   int v=max(abs(a[j]-t),abs(a[i]-t));
   if(v<=mid)j++;
   else break;
  }
  cnt++;
  i=j-1;
 }
 return cnt<=3;
}
void solve(){
    int n;
    scanf("%lld",&n);
  for(i=1;i<=n;i++)
  {
   scanf("%lld",&a[i]);
   sum[i]=0;
  }
  sort(a+1,a+n+1);
  int ans=0;
  int l=-1;
  int r=1e9+10;
  while(l+1!=r)
  {
   int mid=l+r>>1;
   if(check(mid))r=mid;
   else l=mid;
  }
  printf("%lld\n",r);

}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
 cin>>T;
 for(i=0;i<32;i++)
 {
  v.push_back(u);
  u*=2;
 }
    while(T--){
        solve();
    }
    return 0;
}
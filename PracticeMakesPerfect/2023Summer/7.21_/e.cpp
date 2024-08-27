#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
#define yes puts("YES")
#define no puts("NO")
#define x first
#define y second
#define int long long
#define ti chrono::system_clock::now().time_since_epoch().count()
mt19937 rnd(ti + size_t(new char));
using namespace std;
const int N=1e5+10;
const int mod=1e9+7;
void solve()
{
    int i,j,k;
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        scanf("%lld%lld",&n,&m);
        int a[n];
        unordered_map<int,int>mp;
        int sum=0;
        int t=0;
        for(i=0;i<n;i++)scanf("%lld",&a[i]),sum+=a[i]*a[i],t+=a[i];
        m-=sum;
        m/=n;
        m+=t*t/n/n;
        m=sqrt(m);
        m-=t/n;
        m/=2;
        printf("%lld\n",m);
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}
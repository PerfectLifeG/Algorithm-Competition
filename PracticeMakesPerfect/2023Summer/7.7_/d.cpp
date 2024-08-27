#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
void solve()
{
    int n,d,h;
    cin>>n>>d>>h;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    double ans=1.0*n*d*h/2;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]+h){
            double t=1.0*(a[i-1]+h-a[i])/h;
            ans-=t*t*d*h/2;
        }
    }
    printf("%.8lf\n",ans);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
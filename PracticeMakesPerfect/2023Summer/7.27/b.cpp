#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int a;cin>>a;
    if(a==2){
        printf("%.9lf %.9lf\n",1.0,1.0);
        return;
    }
    double sum=1.0*((a-1)*(a-2)+a-1)/(1.0*(a-1)*(a-2)/2+(a-1));
    printf("%.9lf %.9lf\n",sum,2.0);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
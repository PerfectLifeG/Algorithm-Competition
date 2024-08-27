#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int a[N];
void solve()
{
    int i;
    int j;
    vector<int>v;
    for(i=1;i<=100000;i++)v.push_back(i*i);
    for(i=1;i<=1000;i++)
    {
        for(j=0;j<v.size()&&v[j]<i*i;j++)
        {
            int t=v[j]*v[j]-i*i;
            int now=sqrt(t);
            if(now*now==t)
            {
                a[i]++;
            }
        }
    }
    for(i=1;i<=1000;i++)cout<<a[i]<<"\n";

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}
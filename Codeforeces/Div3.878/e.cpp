#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    string s[3];cin>>s[1]>>s[2];
    int n=s[1].size();
    int cnt=0;
    for(int i=0;i<n;i++)if(s[1][i]!=s[2][i])cnt++;
    int t,q;cin>>t>>q;
    vector<PII>v;
    int idx=0;
    for(int i=0;i<q;i++){
        int op;cin>>op;
        for(;idx<v.size();idx++){
            int a=v[idx].y;
            // cout<<idx<<' '<<v[idx].x<<' '<<v[idx].y<<endl;
            if(v[idx].x+t>i)break;
            if(s[1][a]!=s[2][a])cnt++;
        }
        if(op==1){
            int a;cin>>a;a--;
            if(s[1][a]!=s[2][a])cnt--;
            v.push_back({i,a});
            // cout<<i<<' '<<a<<endl;
        }else if(op==2){
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            b--,d--;
            if(s[1][b]==s[2][b])cnt++;
            if(b!=d&&s[1][d]==s[2][d])cnt++;
            swap(s[a][b],s[c][d]);
            // cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
            if(s[1][b]==s[2][b])cnt--;
            if(b!=d&&s[1][d]==s[2][d])cnt--;
        }else{
            if(cnt==0)yes;
            else no;
        }
        // cout<<i<<' '<<cnt<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
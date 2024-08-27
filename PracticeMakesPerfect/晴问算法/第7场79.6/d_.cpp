#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=1e9+7;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    string s;
    cin>>s;
    int t=s.size();
    int sz=s.size();
    t=1<<t;
    set<string>q;
    for(int i=0;i<t-1;i++)
    {
        string tmp;
        for(int j=0;j<sz;j++)
        {
            if(i>>j&1)continue;
            else tmp+=s[j];
        }
        q.insert(tmp);
    }
    cout<<q.size()%mod<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
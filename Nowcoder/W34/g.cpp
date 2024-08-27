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
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    vector<int>book(n+1);
    string s;cin>>s;
    int nr=0,nw=0;
    int r=0,w=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!book[i]){
            int t=i;
            if(v[t]==t){
                if(s[t-1]=='R')nr++;
                if(s[t-1]=='W')nw++;
                book[t]=1;
            }else{
                int fr=0,fw=0;
                while(!book[t]){
                    book[t]=1;
                    if(s[t-1]=='R')fr=1,nr++;
                    if(s[t-1]=='W')fw=1,nw++;
                    t=v[t];
                }
                if(fr&&!fw)r++;
                else if(!fr&&fw)w++;
            }
            ans++;
        }
    }
    if(nr&&!nw||nw&&!nr){
        if(n-ans==0)cout<<0<<endl;
        else cout<<-1<<endl;
    }else{
        int mn=min(r,w);r-=mn,w-=mn;
        cout<<n-ans+2*(mn+r+w)<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
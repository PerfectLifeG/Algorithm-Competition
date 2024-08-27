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
const int INF=0x3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    int v[n][4];
    map<string,int>mp;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        mp[s]=i;
        int a,b,c;cin>>a>>b>>c;
        int d=round(1.0*(a+b+c)/3);
        v[i][0]=d,v[i][1]=a,v[i][2]=b,v[i][3]=c;
    }
    char c[4]={'A','C','M','E'};
    while(m--){
        string s;cin>>s;
        if(!mp.count(s)){
            cout<<"N/A"<<endl;
            continue;
        }
        int lst=1e9;int f;
        for(int i=0;i<4;i++){
            int res=v[mp[s]][i];
            int now=1;
            for(int j=0;j<n;j++){
                if(mp[s]==j)continue;
                int t=v[j][i];
                if(res<t){
                    now++;
                }
            }
            if(now<lst){
                lst=now;
                f=i;
            }
        }
        cout<<lst<<' '<<c[f]<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
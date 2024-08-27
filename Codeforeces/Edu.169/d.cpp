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
int book[7];
unordered_map<string,int>mp;
void solve(){
    int n,q;cin>>n>>q;
    vector<int>a(n+1);
    int pre[n+1][7]={};
    int suf[n+2][7]={};
    for(int i=0;i<7;i++)suf[n+1][i]=n+1;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        a[i]=mp[s];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(a[i]==j)pre[i][j]=i;
            else pre[i][j]=pre[i-1][j];
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=6;j++){
            if(a[i]==j)suf[i][j]=i;
            else suf[i][j]=suf[i+1][j];
        }
    }

    // for(int i=1;i<=2;i++){
    //     for(int j=1;j<=6;j++){
    //         cout<<i<<' '<<j<<' '<<pre[i][j]<<' '<<suf[i][j]<<endl;
    //     }
    // }

    while(q--){
        int x,y;cin>>x>>y;
        if(x>y)swap(x,y);
        if(book[a[x]]!=a[y]){
            cout<<y-x<<endl;
        }else{
            int l=0;
            for(int i=1;i<=6;i++){
                if(i!=a[x]&&i!=a[y]){
                    l=max(l,pre[y-1][i]);
                }
            }
            // cout<<l<<'?'<<endl;
            if(l!=0&&l>x){
                cout<<y-x<<endl;
                continue;
            }
            int r=n+1;
            for(int i=1;i<=6;i++){
                if(i!=a[x]&&i!=a[y]){
                    r=min(r,suf[y+1][i]);
                }
            }
            int ans=INF;
            if(r!=n+1)ans=min(ans,r-x+r-y);
            if(l!=0)ans=min(ans,x-l+y-l);
            // cout<<l<<' '<<r<<' '<<x<<' '<<y<<endl;
            if(ans==INF)cout<<-1<<endl;
            else cout<<ans<<endl;
        }
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;


    mp["BG"]=1;mp["BR"]=2;mp["BY"]=3;
    mp["GR"]=4;mp["GY"]=5;mp["RY"]=6;
    book[1]=6;book[2]=5;book[3]=4;
    book[4]=3;book[5]=2;book[6]=1;


    while(_--)solve();
    return 0;
}
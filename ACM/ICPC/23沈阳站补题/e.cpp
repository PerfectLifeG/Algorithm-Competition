#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,m,p,Q;
    cin>>n>>m>>p>>Q;

    queue<array<int,3>>q;
    int book[n+1][m+1][2]={};book[n][m][0]=1;
    q.push({n,m,0});
    int ans=-1;
    while(q.size()){
        auto [a,b,c]=q.front();
        q.pop();
        if(a==n&&c==1){ans=book[a][b][c]-1;break;}
        for(int i=0;i<=a;i++){
            for(int j=0;j<=b;j++){
                if(i+j>p)continue;
                if(a-i!=0&&a-i+Q<b-j)continue;
                if(book[n-a+i][m-b+j][!c])continue;
                book[n-a+i][m-b+j][!c]=book[a][b][c]+1;
                q.push({n-a+i,m-b+j,!c});
            }
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
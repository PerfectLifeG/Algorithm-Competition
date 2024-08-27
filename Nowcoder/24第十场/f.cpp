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
const int N=1100;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;

int book[N][N];
int n;
void check(int x1,int y1,int x2,int y2){

    int dx=x2-x1;
    int dy=y2-y1;

    int d=abs(__gcd(dx,dy));
    dx/=d;
    dy/=d;

    for(int i=x1,j=y1;i>=1&&j>=1&&i<=n&&j<=n;i+=dx,j+=dy){
        book[i][j]=1;
    }
    for(int i=x1,j=y1;i>=1&&j>=1&&i<=n&&j<=n;i-=dx,j-=dy){
        book[i][j]=1;
    }

}

void solve(){
    cin>>n;
    vector<PII>v;
    for(int i=0;i<n*n;i++){
        int x,y;cin>>x>>y;
        if(book[x][y]){
            cout<<0;
            continue;
        }
        cout<<1;
        book[x][y]=1;
        for(auto &[a,b]:v){
            check(x,y,a,b);
        }
        v.push_back({x,y});
    }


}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
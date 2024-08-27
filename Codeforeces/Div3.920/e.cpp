#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define A cout<<"Alice"<<endl
#define B cout<<"Bob"<<endl
#define P cout<<"Draw"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,m,xa,ya,xb,yb;
    cin>>n>>m>>xa>>ya>>xb>>yb;
    int t=abs(xa-xb);
    int t2=abs(ya-yb);
    if(xa>=xb){P;return;}
    if(ya==yb){
        if(t&1){
            A;
        }else B;
        return;
    }
    if(t&1){
        int p;
        if(ya<yb){
            p=min(t/2,m-yb);
        }else{
            p=min(t/2,yb-1);
        }
        t-=p*2;
        if(t/2+1>=t2){
            A;
        }else P;
    }else{
        int p;
        if(ya>yb){
            p=min(t/2,m-ya);
        }else{
            p=min(t/2,ya-1);
        }
        t-=p*2;
        if(t/2>=t2){
            B;
        }else P;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
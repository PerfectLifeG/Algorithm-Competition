#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
#define x first
#define y second
PII a[N];
int b[N];
void solve(){
    int n,q;cin>>n>>q;
    int t;cin>>t;
    b[1]=t;
    a[1].x=t;a[1].y=1;
    for(int i=2;i<=n;i++){
        cin>>t;b[i]=t;
        if(t>=b[i-1]){
            if(t!=b[i-1])a[i].x=a[i-1].x+1;
            else a[i].x=a[i-1].x;
            a[i].y=i;
        }else {
            a[i].y=a[i-1].y;
            
        }
        cout<<i<<' '<<a[i].x<<" "<<a[i].y<<endl;
    }
    while(q--){
        int l,r;cin>>l>>r;
        cout<<a[a[r].y].y-a[a[l].y].y+1<<endl;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;T=1;
    while(T--){
        solve();
    }
    return 0;
}
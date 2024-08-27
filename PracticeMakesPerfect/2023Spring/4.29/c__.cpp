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
int a[N];
int idx;
PII b[N];
void solve(){
    int n,q;cin>>n>>q;
    int l=1,r=1;
    cin>>a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i]<=a[i-1]){
            r++;
        }else{
            if(r-l+1>=3){
                b[idx].x=l;
                b[idx++].y=r;
            }
            l=r=i;
        }
    }
    // for(int i=0;i<idx;i++){
    //     cout<<b[i].x<<' '<<b[i].y<<endl;
    // }
    while(q--){
        int c,d;cin>>c>>d;
        // cout<<c<<' '<<d<<endl;
        l=-1;r=idx;
        while(l+1!=r){
            int mid=l+r>>1;
            if(b[mid].x>a[c])r=mid;
            else l=mid;
        }
        // cout<<l<<'.'<<endl;
        if(l!=-1)c=max(c,b[l].y);
        // cout<<c<<endl;
        r=idx;
        while(l+1!=r){
            int mid=l+r>>1;
            if(b[mid].x<a[c])l=mid;
            else r=mid;
        }
        if(r!=idx)d=min(d,b[r].x);
        cout<<d-c+1<<endl;
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
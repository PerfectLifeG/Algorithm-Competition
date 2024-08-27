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
int a[N],s[N];
void solve(){
    int n,q;cin>>n>>q;
    int l=1,r=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=3){
            if(a[i]<=a[i-1]&&a[i-1]<=a[i-2]){
                s[i]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        s[i]+=s[i-1];
        // cout<<s[i]<<' ';
    }
    // cout<<endl;
    while(q--){
        int c,d;cin>>c>>d;
        if(d-c+1==1){
            cout<<1<<endl;
            // return;
        }
        else if(d-c+1==2){
            cout<<2<<endl;
            // return;
        }
        else cout<<d-c+1-(s[d]-s[c-1])+s[c+1]-s[c-1]<<endl;
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
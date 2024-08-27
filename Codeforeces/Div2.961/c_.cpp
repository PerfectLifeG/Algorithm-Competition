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
const int N=1e6;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
bool check(int a1,int p,int a2,int q){
    double lglga1=log10(log10(1.0*a1)),lglga2=log10(log10(1.0*a2));
    double lg2=log10(2.0);
    return p*lg2+lglga1<=q*lg2+lglga2;
}
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    int f=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    vector<int>s(n+1);
    int ans=0;
    for(int i=2;i<=n;i++){
        if(a[i]==1&&a[i-1]>1){
            cout<<-1<<endl;
            return;
        }
        int l=-1,r=1e9;
        while(l+1!=r){
            int mid=l+r>>1;
            if(check(a[i-1],s[i-1],a[i],mid))r=mid;
            else l=mid;
        }
        s[i]=r;
        ans+=s[i];
    }

    for(int i=1;i<=n;i++)cout<<s[i]<<' ';cout<<endl;
    cout<<ans<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
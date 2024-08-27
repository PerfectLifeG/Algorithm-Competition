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
    int n,p;cin>>n>>p;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){cin>>a[i];a[i]=10-a[i];}
    if(a[p]!=1){
        cout<<"0 0"<<endl;
        return;
    }
    a[p]=1e9;
    int nowr=1;
    int nowl=1;
    int l=p-1,r=p+1;
    while((r<=n&&nowr||nowl&&l>=1)&&(l>=1||r<=n)){
        for(int i=r;i<=n;i++){
            if(nowr>=a[i]){
                nowl++;
                nowr=nowr-a[i]+1;
                r=i+1;
            }else{
                a[i]-=nowr;
                nowr=0;
                r=i;
                break;
            }
        }
        for(int i=l;i>=1;i--){
            if(nowl>=a[i]){
                nowl=nowl-a[i]+1;
                nowr++;
                l=i-1;
            }else{
                a[i]-=nowl;
                nowl=0;
                l=i;
                break;
            }
        }
    }
    cout<<nowl<<' '<<nowr<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
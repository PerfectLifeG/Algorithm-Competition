#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int t=0;
    int id=20;
    for(int i=1;i<=20;i++){
        double ans=0;
        for(int j=1;j<=20;j++){
            if(i>j){
                ans+=j+10-i;
            }else if(i<j){
                ans+=j-10-i;
            }
        }
        if(t<=ans){
            id=i;
            t=ans;
        }
    }
    cout<<t<<' '<<id<<endl;
    double ans=0;
    for(int i=1;i<=20;i++){
        if(i>id){
            ans+=i-10;
        }else if(i<id){
            ans+=i+10;
        }else ans+=i;
    }
    ans=ans*1.0/20;
    int n;cin>>n;
    printf("%.6lf",(n-1)*ans);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
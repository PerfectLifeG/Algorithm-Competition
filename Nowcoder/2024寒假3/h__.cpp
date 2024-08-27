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
const int INF=0x3f3f3f3f;
vector<PII>v1;
vector<PII>v2;
int check(vector<int> a){
    for(auto i:v1){
        if(a[i.x]>=a[i.y])return 0;
    }
    for(auto i:v2){
        if(a[i.x]<a[i.y])return 0;
    }
    return 1;
}
void solve(){
    v1.clear();
    v2.clear();
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x,y,z;cin>>x>>y>>z;
        if(z==0)v2.push_back({x,y});
        if(z==1)v1.push_back({x,y});
    }
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=3;k++){
                if(check({0,i,j,k})){
                    yes;
                    return;
                }
            }
        }
    }
    no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
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
    int n,m;cin>>n>>m;
    // vector<array<int,3>>v;
    vector<PII>v1;
    vector<PII>v2;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v1.push_back({a,b});
    }
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        v2.push_back({a,b});
    }
    sort(all(v1));
    sort(all(v2));
    int l=0,r=0;
    int j=0;
    for(int i=0;i<m;i++){
        while(v2[j].x<v1[i].y){
            if(v2[j].y<=v1[i].x){
                l=v2[j].y;
                r=max(r,v2[j].y+2*(v2[j].y-v2[j].x));
            }
            j++;
        }
        if(!(r>=v1[i].y&&v1[i].x>=l)){
            no;return;
        }
    }
    yes;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
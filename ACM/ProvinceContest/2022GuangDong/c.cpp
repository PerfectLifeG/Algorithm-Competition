#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<PII>v(n);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v[i]={a,b};
    }
    sort(v.begin(),v.end(),[&](PII a,PII b){
        if(a.x==b.x)return a.y>b.y;
        return a.x<b.x;
    });
    int j=n-1;
    int ans=0;
    for(int i=0;i<j;){
        if(v[i].x<v[j].x){
            if(v[i].y>v[j].y){
                ans+=v[j].y*(v[j].x-v[i].x);
                v[i].y-=v[j].y;
                j--;
            }else if(v[i].y<v[j].y){
                ans+=v[i].y*(v[j].x-v[i].x);
                v[j].y-=v[i].y;
                i++;
            }else{
                ans+=v[i].y*(v[j].x-v[i].x);
                i++;
                j--;
            }
        }else {j--;}
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
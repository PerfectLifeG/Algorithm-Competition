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
    vector<int>v1;
    vector<int>v2;
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    v1.push_back(a[0]);
    v2.push_back(1e9);
    for(int i=1;i<n;i++){
        if(v1.back()<=v2.back()){
            if(a[i]<=v1.back()){
                v1.push_back(a[i]);
            }else if(a[i]<=v2.back()){
                v2.push_back(a[i]);
            }else{
                v1.push_back(a[i]);
            }
        }else{
            if(a[i]<=v2.back()){
                v2.push_back(a[i]);
            }else if(a[i]<=v1.back()){
                v1.push_back(a[i]);
            }else{
                v2.push_back(a[i]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<v1.size();i++){
        if(v1[i]>v1[i-1])ans++;
    }
    for(int i=2;i<v2.size();i++){
        if(v2[i]>v2[i-1])ans++;
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
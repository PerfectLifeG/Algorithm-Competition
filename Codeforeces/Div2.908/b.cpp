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
    int n;cin>>n;
    vector<int>a(n);
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    int cnt=0;
    int f1=-1;int f2=-1;
    for(auto [i,j]:mp){
        if(j>=2){
            cnt++;
            if(cnt==2){
                f2=i;
            }
            else f1=i;
        }
    }
    vector<int>b(n,1);
    if(cnt>=2){
        for(int i=0;i<n;i++){
            if(f1!=-1&&a[i]==f1){
                b[i]=2;
                f1=-1;
            }
            if(f2!=-1&&a[i]==f2){
                b[i]=3;
                f2=-1;
            }
        }
        for(int i=0;i<n;i++){
            cout<<b[i]<<' ';
        }cout<<endl;
    }else cout<<-1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
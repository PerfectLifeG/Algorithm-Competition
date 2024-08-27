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
    int p[n][n];
    vector<int>v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>p[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(i%2==0)
            for(int j=0;j<n;j++){
                v.push_back(p[i][j]);
            }
        else 
            for(int j=n-1;j>=0;j--){
                v.push_back(p[i][j]);
            }
    }
    int t=0;
    for(int i=1;i<v.size();i++){
        if(v[i]>v[i-1]){
            t++;
        }
    }
    if(n*n-1-t>=t){
        cout<<v[0];
        for(int i=1;i<v.size();i++){
            cout<<' '<<v[i];
        }
    }else {
        cout<<v[v.size()-1];
        for(int i=v.size()-2;i>=0;i--){
            cout<<' '<<v[i];
        }
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
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
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    string s;
    string p;cin>>s>>p;
    string ssss=s.substr(2);
    int n=stoi(ssss);
    int a=0,b=0;
    for(int i=0;i<p.size();i++){
        if(p[i]=='R')a++;
        else b++;
        if(a==(n+1)/2){
            cout<<"kou!\n";
            cout<<i+1<<endl;
            return;
        }
        if(b==(n+1)/2){
            cout<<"yukari!\n";
            cout<<i+1<<endl;
            return;
        }
    }
    cout<<"to be continued."<<endl;
    cout<<p.size()<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
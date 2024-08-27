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
    int n;cin>>n;
    string s;
    getline(cin,s);
    for(int i=0;i<n;i++){
        getline(cin,s);
        // s+='/';
        // cout<<s<<endl;
        cout<<s.substr(0,s.find("://"))<<endl;
        s=s.substr(s.find("://")+3);
        // cout<<s<<endl;
        // return;
        cout<<s.substr(0,s.find("/"))<<endl;
        s=s.substr(s.find("/")+1);
        // cout<<s<<endl;
        // return;
        while(s.find("/")!=-1){
            if(s.find('=')<s.find("/")){
                cout<<s.substr(0,s.find("/"))<<endl;
            }
            s=s.substr(s.find("/")+1);
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
void solve(){
    int n,m;cin>>n>>m;
    vector<PII>v;
    for(int i=0;i<n;i++){
        int h1,m1,h2,m2;
        scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
        int t1=h1*60+m1,t2=h2*60+m2;
        v.push_back({t1,t2});
    }
    unordered_map<int,int>mp;
    map<string,int>mp2;
    for(int i=0;i<=1;i++){
        for(int j=0;j<=59;j++){
            int t=i*60+j;
            for(auto [a,b]:v){
                if(b<=a){
                    if(t<=b||t>=a){
                        mp[t]=1;
                    }
                }else{
                    if(a<=t&&t<=b){
                        mp[t]=1;
                    }
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        string s;cin>>s;
        mp2[s]=1;
    }
    int q;cin>>q;
    while(q--){
        int h1,m1,h2,m2;
        scanf("%d:%d",&h1,&m1);
        int t=h1*60+m1;
        scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
        int t1=h1*60+m1;int t2=h2*60+m2;
        string s;cin>>s;
        
        if(!mp.count(t)){
            cout<<"Loser xqq\n";
        }else if(t1>t2||!mp2.count(s)){
            cout<<"Joker xqq\n";
        }else cout<<"Winner xqq\n";
    }
}
signed main(){
    int _=1;
    while(_--)solve();
    return 0;
}
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
string st,ed;
string change(string s,int id){
    if(id==0){
        s[0]=(s[0]-'0')^1+'0';
        s[1]=(s[1]-'0')^1+'0';
        s[4]=(s[4]-'0')^1+'0';
        s[5]=(s[5]-'0')^1+'0';
    }
    if(id==1){
        s[0]=(s[0]-'0')^1+'0';
        s[1]=(s[1]-'0')^1+'0';
        s[2]=(s[2]-'0')^1+'0';
    }
    if(id==2){
        s[3]=(s[3]-'0')^1+'0';
        s[1]=(s[1]-'0')^1+'0';
        s[2]=(s[2]-'0')^1+'0';
        s[5]=(s[5]-'0')^1+'0';
    }
    if(id==4){
        s[3]=(s[3]-'0')^1+'0';
        s[0]=(s[0]-'0')^1+'0';
        s[4]=(s[4]-'0')^1+'0';
    }
    if(id==3){
        s[3]=(s[3]-'0')^1+'0';
        s[4]=(s[4]-'0')^1+'0';
        s[2]=(s[2]-'0')^1+'0';
        s[5]=(s[5]-'0')^1+'0';
    }
    if(id==5){
        s[3]=(s[3]-'0')^1+'0';
        s[0]=(s[0]-'0')^1+'0';
        s[2]=(s[2]-'0')^1+'0';
        s[5]=(s[5]-'0')^1+'0';
    }
    return s;
}
void bfs(){
    queue<string>q;
    q.push(st);
    unordered_map<string,int>mp;
    mp[st]=0;
    while(q.size()){
        auto t=q.front();
        if(t==ed){cout<<mp[ed]<<endl;return;}
        q.pop();
        for(int i=0;i<6;i++){
            string s=change(t,i);
            if(mp.count(s))continue;
            mp[s]=mp[t]+1;
            q.push(s);
        }
    }
    cout<<-1<<endl;
}
void solve(){
    cin>>st>>ed;
    bfs();
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
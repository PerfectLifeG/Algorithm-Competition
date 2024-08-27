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
unordered_map<string,int>mp;
void bfs(){
    queue<string>q;
    q.push("0000");
    mp["0000"]=0;
    while(q.size()){
        auto t=q.front();
        // cout<<t<<' '<<mp[t]<<endl;
        q.pop();
        for(int h=1;h<=9;h++){
            for(int k=0;k<4;k++){
                string p=t;
                for(int j=k;j>=0;j--){
                    p[j]=(t[j]-'0'+h+10)%10+'0';
                    if(!mp.count(p)){
                            mp[p]=mp[t]+h;
                            q.push(p);
                    }
                    else if(mp[p]>mp[t]+h){
                        mp[p]=mp[t]+h;
                        q.push(p);
                    }
                    for(int i=k+1;i<4;i++){
                        p[i]=(t[i]-'0'+h+10)%10+'0';
                        if(!mp.count(p)){
                            mp[p]=mp[t]+h;
                            q.push(p);
                        }
                        else if(mp[p]>mp[t]+h){
                            mp[p]=mp[t]+h;
                            q.push(p);
                        }
                    }
                }
                p=t;
                for(int j=k;j>=0;j--){
                    p[j]=(t[j]-'0'-h+10)%10+'0';
                    if(!mp.count(p)){
                            mp[p]=mp[t]+h;
                            q.push(p);
                    }
                    else if(mp[p]>mp[t]+h){
                        mp[p]=mp[t]+h;
                        q.push(p);
                    }
                    for(int i=k+1;i<4;i++){
                        p[j]=(t[j]-'0'-h+10)%10+'0';
                        if(!mp.count(p)){
                                mp[p]=mp[t]+h;
                                q.push(p);
                        }
                        else if(mp[p]>mp[t]+h){
                            mp[p]=mp[t]+h;
                            q.push(p);
                        }
                    }
                }
            }
        }
    }
}
void solve(){
    int a,b;cin>>a>>b;
    string s;
    for(int i=0;i<4;i++){
        s+='0'+(a%10-b%10+10)%10;
        a/=10;
        b/=10;
    }
    // for(auto [i,j]:mp)cout<<i<<' '<<j<<endl;
    // cout<<s<<endl;
    cout<<mp[s]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    bfs();
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
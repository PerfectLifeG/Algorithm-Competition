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
    unordered_map<string,vector<int>>mp;
    unordered_map<string,vector<int>>mp2;
    vector<string>v;
    for(int i=0;i<n;i++){
        int op;cin>>op;
        string s;
        getline(cin,s);
        v.push_back(s.substr(1));
        string t;
        for(int j=1;j<s.size();j++){
            if(s[j]!=' '&&s[j-1]==' '){
                t+=s[j];
            }
        }
        if(op){
            mp[t].push_back(i);
        }else{
            mp2[t].push_back(i);
        }
    }
    int m;cin>>m;
    string s1;
    getline(cin,s1);
    for(int i=0;i<m;i++){
        vector<int>st;
        int cnt=2;
        getline(cin,s1);
        string t1;t1+=s1[0];
        for(int j=1;j<s1.size();j++){
            if(s1[j]!=' '&&s1[j-1]==' '){
                t1+=s1[j];
            }
            if(s1[j]!=' ')cnt++;
        }
        string s2;
        getline(cin,s2);
        string t2;t2+=s2[0];
        for(int j=1;j<s2.size();j++){
            if(s2[j]!=' '&&s2[j-1]==' '){
                t2+=s2[j];
            }
            if(s2[j]!=' ')cnt++;
        }
        if(mp.count(t1+t2)){
            for(auto i:mp[t1+t2]){
                st.push_back(i);
            }
        }
        if(mp.count(t2+t1)){
            for(auto i:mp[t2+t1]){
                st.push_back(i);
            }
        }
        int cnt2=st.size();
        string ans2;
        if(mp2.count(t1+t2)){
            ans2=v[*mp2[t1+t2].begin()];
        }
        if(ans2==""&&mp2.count(t2+t1)){
            ans2=v[*mp2[t2+t1].begin()];
        }
        if(st.size()==1){
            cout<<v[st[0]]<<endl;
        }else if(st.size()){
            int x=cnt%cnt2;
            cout<<v[st[x]]<<endl;
        }else if(ans2!=""){
            cout<<ans2<<endl;
        }else cout<<"tian ji bu ke xie lu\n";
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
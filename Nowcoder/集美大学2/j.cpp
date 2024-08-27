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
vector<string>v;
int book[10];
string dfs(int id){
    if(!book[id])return v[id].substr(0,(int)v[id].size()-1ll);
    string ans;
    for(int i=0;i<v[id].size();i++){
        if(i>0&&v[id][i-1]=='*'){
            if(v[id][i]-'0'!=0&&v[id][i]-'0'-1<v[id].size()){
                string p=dfs(v[id][i]-'0'-1);
                if(p==".")return ".";
                ans+=p;
            }
        }else if(v[id][i]!='*'&&v[id][i]!='#')ans+=v[id][i];
        if(ans.size()>1000){
            return ".";
        }
    }
    if(ans.size()>1000){
        return ".";
    }
    return ans;
}
void solve(){
    int n;cin>>n;
    string s;
    getline(cin,s);
    for(int i=0;i<n;i++){
        string t;
        while(getline(cin,s)){
            t+=s;
            if(t.back()=='#')break;
        }
        v.push_back(t);
        if(t.find('*')!=-1)book[i]=1;
    }
    string p=dfs(0);
    if(p==".")cout<<"#";
    else cout<<p<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
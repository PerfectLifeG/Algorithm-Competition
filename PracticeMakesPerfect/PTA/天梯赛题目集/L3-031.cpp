#include<bits/stdc++.h>
using namespace std;
const int N=10010;
unordered_map<string,int>mp;int idx=1;
unordered_map<int,string>mp2;
vector<int>v[N];
int ru[N];
int main(){
    int n;cin>>n;
    int cnt=0;
    vector<int>pre;
    for(int k=0;k<n;k++){
        string s;cin>>s;
        string t;
        vector<int>p;
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                if(!mp.count(t)){mp[t]=idx;mp2[idx++]=t;}
                p.push_back(mp[t]);
                t="";
            }else{
                t+=s[i];
            }
        }
        if(!mp.count(t)){mp[t]=idx;mp2[idx++]=t;}
        p.push_back(mp[t]);
        if(k){
            if(pre.size()==p.size()){
                for(int i=0;i<pre.size();i++){
                    if(pre[i]!=p[i]){
                        v[pre[i]].push_back(p[i]);
                        ru[p[i]]++;
                        break;
                    }
                }
            }
        }
        pre=p;
        
    }
    
    priority_queue<string,vector<string>,greater<string>>q;
    for(auto [i,j]:mp){
        if(ru[mp[i]]==0)q.push(i);
    }

    vector<string>ans;
    while(q.size()){
        auto t=q.top();
        q.pop();
        ans.push_back(t);
        for(auto j:v[mp[t]]){
            if(--ru[j]==0){
                q.push(mp2[j]);
            }
        }
    }

    for(int i=0;i<ans.size();i++){
        if(i)cout<<'.';
        cout<<ans[i];
    }
    
}
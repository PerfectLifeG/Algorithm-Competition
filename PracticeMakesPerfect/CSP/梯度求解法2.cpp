#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=1e9+7;
const int INF=0x3f3f3f3f3f3f3f3f;
int ksm(int a,int n){
    int r=1ll;
    while(n){
        if(n&1)r=r*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return r;
}
void solve(){
    int n,m;cin>>n>>m;
    string line;
    string t;
    vector<string>s;
    getline(cin,line);getline(cin,line);
    stringstream ssin(line);
    while (ssin >> t){s.push_back(t);}

    function<map<int,int>(map<int,int>,map<int,int>)> merge=[&](map<int,int> mp1,map<int,int> mp2)->map<int,int>{
        map<int,int>mp;
        for(auto i:mp1){
            for(auto j:mp2){
                mp[i.x+j.x]+=i.y*j.y;
                mp[i.x+j.x]=(mp[i.x+j.x]%mod+mod)%mod;
            }
        }
        return mp;
    };
    function<map<int,int>(map<int,int>,map<int,int>)> add=[&](map<int,int> mp1,map<int,int> mp2)->map<int,int>{
        for(auto i:mp2){
            mp1[i.x]+=i.y;
            mp1[i.x]%=mod;
        }
        return mp1;
    };
    function<map<int,int>(map<int,int>,map<int,int>)> sub=[&](map<int,int> mp1,map<int,int> mp2)->map<int,int>{
        for(auto i:mp2){
            mp1[i.x]-=i.y;
            mp1[i.x]=(mp1[i.x]%mod+mod)%mod;
        }
        return mp1;
    };

    while(m--){
        int x;cin>>x;
        vector<int>val(n+1);
        for(int i=1;i<=n;i++){cin>>val[i];val[i]=(val[i]%mod+mod)%mod;}
        stack<map<int,int>>st;
        for(int i=0;i<s.size();i++){
            if(s[i].size()==1&&s[i][0]=='*'){
                auto mp1=st.top();st.pop();
                auto mp2=st.top();st.pop();
                st.push(merge(mp1,mp2));
            }else if(s[i].size()==1&&s[i][0]=='+'){
                auto mp1=st.top();st.pop();
                auto mp2=st.top();st.pop();
                st.push(add(mp1,mp2));
            }else if(s[i].size()==1&&s[i][0]=='-'){
                auto mp1=st.top();st.pop();
                auto mp2=st.top();st.pop();
                st.push(sub(mp2,mp1));
            }else if(s[i][0]=='x'){
                map<int,int>mp;
                int id=stoi(s[i].substr(1));
                if(id!=x)mp[0]=val[id];
                else mp[1]=1;
                st.push(mp);
            }else{
                map<int,int>mp;
                int id=stoi(s[i]);id=(id%mod+mod)%mod;
                mp[0]=id;
                st.push(mp);
            }
        }
        map<int,int>mp=st.top();
        int ans=0;
        for(auto i:mp){
            if(i.x==0)continue;
            ans+=i.x*i.y%mod*ksm(val[x],i.x-1)%mod;ans%=mod;
        }
        cout<<ans<<endl;
    }    
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
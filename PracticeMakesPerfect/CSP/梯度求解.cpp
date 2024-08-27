#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
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
    

    function<vector<map<int,int>>(vector<map<int,int>>,vector<map<int,int>>)> merge=[&](vector<map<int,int>> v1,vector<map<int,int>> v2)->vector<map<int,int>>{
        vector<map<int,int>>v;
        for(auto i:v1){
            for(auto j:v2){
                map<int,int>mp=i;
                for(auto k:j){
                    int a=k.x,b=k.y;
                    if(a==0)mp[a]=mp[a]*b;
                    else mp[a]=mp[a]+b;
                    mp[a]=mp[a]%mod;
                }
                v.push_back(mp);
            }
        }
        return v;
    };

    function<vector<map<int,int>>(vector<map<int,int>>,vector<map<int,int>>)> add=[&](vector<map<int,int>> v1,vector<map<int,int>> v2)->vector<map<int,int>>{
        vector<map<int,int>>v;
        for(auto i:v1)v.push_back(i);
        for(auto i:v2)v.push_back(i);
        return v;
    };

    function<vector<map<int,int>>(vector<map<int,int>>,vector<map<int,int>>)> sub=[&](vector<map<int,int>> v1,vector<map<int,int>> v2)->vector<map<int,int>>{
        vector<map<int,int>>v;
        for(auto i:v1)v.push_back(i);
        for(auto i:v2){
            i[0]=-i[0];
            i[0]=(i[0]+mod)%mod;
            v.push_back(i);
        }
        return v;
    };


    stack<vector<map<int,int>>>st;
    for(int i=0;i<s.size();i++){
        if(s[i].size()==1&&s[i][0]=='*'){
            vector<map<int,int>> v1=st.top();st.pop();
            vector<map<int,int>> v2=st.top();st.pop();
            st.push(merge(v1,v2));
        }else if(s[i].size()==1&&s[i][0]=='+'){
            vector<map<int,int>> v1=st.top();st.pop();
            vector<map<int,int>> v2=st.top();st.pop();
            st.push(add(v1,v2));
        }else if(s[i].size()==1&&s[i][0]=='-'){
            vector<map<int,int>> v1=st.top();st.pop();
            vector<map<int,int>> v2=st.top();st.pop();
            st.push(sub(v2,v1));
        }else if(s[i][0]=='x'){
            vector<map<int,int>>v;
            map<int,int>mp;
            int id=stoi(s[i].substr(1));
            mp[id]=1,mp[0]=1;
            v.push_back(mp);
            st.push(v);
        }else{
            vector<map<int,int>>v;
            map<int,int>mp;
            int id=stoi(s[i]);
            id=(id+mod)%mod;
            mp[0]=id;
            v.push_back(mp);
            st.push(v);
        }
    }
    
    auto v=st.top();
    while(m--){
        int x;cin>>x;
        vector<int>val(n+1);
        for(int i=1;i<=n;i++)cin>>val[i];
        int ans=0;
        for(auto mp:v){
            int sum=mp[0];sum%=mod;sum=(sum+mod)%mod;
            if(mp.count(x)){
                sum*=mp[x];sum%=mod;sum=(sum+mod)%mod;
                sum*=ksm(val[x],mp[x]-1);sum%=mod;sum=(sum+mod)%mod;
            }else {
                continue;
            }
            for(auto k:mp){
                int a=k.x,b=k.y;
                if(a==x||a==0)continue;
                sum*=ksm(val[a],b);sum%=mod;sum=(sum+mod)%mod;
            }
            ans+=sum;ans=(ans%mod+mod)%mod;
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
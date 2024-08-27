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
const int N=3000;
const int mod=998244353;
unordered_map<int,vector<PII>>mp;
set<int>s[N];
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int id;cin>>id;
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int a,b;cin>>a>>b;
            mp[a].push_back({b,id});
        }
    }

    int q;cin>>q;
    while(q--){
        string line;
        cin>>line;line+=")";
        stack<string>st;st.push("(");int idx=0;
        for(int i=0;i<line.size();i++){
            if(line[i]=='('||line[i]=='&'||line[i]=='|'){string tt="";tt+=line[i];st.push(tt);continue;}
            if(line[i]!=')'){
                s[idx].clear();
                int j=i;
                while(line[i]!=':'&&line[i]!='~')i++;
                int t1=stoi(line.substr(j,i-j));j=i+1;
                while(line[i]!=')')i++;
                int t2=stoi(line.substr(j,i-j));
                if(line[j-1]==':'){
                    for(auto k:mp[t1]){
                        if(k.x==t2)s[idx].insert(k.y);
                    }
                }else{
                    for(auto k:mp[t1]){
                        if(k.x!=t2)s[idx].insert(k.y);
                    }
                }
                st.push(to_string(idx));
                idx++;
            }
            if(line[i]==')'){
                int t1=-1,t2=-1;string c;
                while(st.top()!="("){
                    if(t1==-1)t1=stoi(st.top());
                    else if(t2==-1)t2=stoi(st.top());
                    else c=st.top();
                    st.pop();
                }
                st.pop();
                if(t2!=-1){
                    swap(t1,t2);
                    if(c=="&"){
                        set<int>tmp;
                        for(auto j:s[t1]){
                            if(s[t2].count(j))tmp.insert(j);
                        }
                        s[t1]=tmp;
                    }else{
                        for(auto j:s[t2]){
                            s[t1].insert(j);
                        }
                    }
                }
                st.push(to_string(t1));
                idx=t1+1;
            }
        }
        for(auto i:s[0])cout<<i<<' ';cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
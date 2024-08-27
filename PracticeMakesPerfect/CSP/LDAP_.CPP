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
const int INF=0x3f3f3f3f3f3f3f3f;
unordered_map<int,int>mp[N];
unordered_map<int,int>s[N];
int id[N];
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>id[i];
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int a,b;cin>>a>>b;
            mp[i][a]=b;
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
                    for(int k=0;k<n;k++){
                        if(mp[k].count(t1)&&mp[k][t1]==t2)s[idx][id[k]]=1;
                    }
                }else{
                    for(int k=0;k<n;k++){
                        if(mp[k].count(t1)&&mp[k][t1]!=t2)s[idx][id[k]]=1;
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
                        unordered_map<int,int>tmp;
                        for(auto j:s[t1]){
                            if(s[t2].count(j.x))tmp[j.x]=1;
                        }
                        s[t1]=tmp;
                    }else{
                        for(auto j:s[t2]){
                            s[t1][j.x]=1;
                        }
                    }
                }
                st.push(to_string(t1));
                idx=t1+1;
            }
        }
        set<int>ans;
        for(auto i:s[0])ans.insert(i.x);
        for(auto i:ans)cout<<i<<' ';cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
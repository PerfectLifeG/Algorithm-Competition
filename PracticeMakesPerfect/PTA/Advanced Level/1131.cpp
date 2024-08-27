#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=10010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
unordered_map<int,int>mp;
unordered_map<int,int>mp2;
int idx;
vector<PII>v[N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        int lst;cin>>lst;
        if(!mp.count(lst)){mp[lst]=idx;mp2[idx++]=lst;}
        lst=mp[lst];
        for(int j=1;j<k;j++){
            int a;cin>>a;
            if(!mp.count(a)){mp[a]=idx;mp2[idx++]=a;}
            v[lst].push_back({mp[a],i});
            v[mp[a]].push_back({lst,i});
            lst=mp[a];
        }
    }

    int st,ed;
    vector<int>ans;
    vector<int>line;
    vector<int>tmp1;
    vector<int>tmp2;
    int mx=INF;

    vector<int>book1(idx,INF);
    vector<int>book2(idx,INF);
    function<void(int,int)> dfs=[&](int t,int l){
        if(t==ed){
            tmp1.push_back(mp2[ed]);
            if(book1[ed]<mx){
                mx=book1[ed];
                ans=tmp1;
                line=tmp2;
            }else if(book1[ed]==mx&&tmp2.size()<line.size()){
                ans=tmp1;
                line=tmp2;
            }
            tmp1.pop_back();
            return;
        }
        for(auto [j,w]:v[t]){
            if(book1[j]<book1[t]+1)continue;
            if(t==st||w!=l){
                if(book1[j]==book1[t]+1&&tmp2.size()+1>book2[j])continue;
                book2[j]=tmp2.size()+1;
            }else {
                if(book1[j]==book1[t]+1&&tmp2.size()>book2[j])continue;
                book2[j]=tmp2.size();
            }
            book1[j]=book1[t]+1;
            if(t==st)tmp2.push_back(w);
            if(t!=st&&w!=l){
                tmp1.push_back(mp2[t]);
                tmp1.push_back(mp2[t]);
                tmp2.push_back(w);
                dfs(j,w);
                tmp2.pop_back();
                tmp1.pop_back();
                tmp1.pop_back();
            }else dfs(j,w);
            if(t==st)tmp2.pop_back();
        }
    };

    int q;cin>>q;
    while(q--){
        cin>>st>>ed;
        tmp1.push_back(st);
        st=mp[st],ed=mp[ed];
        book1[st]=1;book2[st]=1;mx=INF;
        dfs(st,-1);

        cout<<mx-1<<endl;
        for(int i=0;i<line.size();i++){
            printf("Take Line#%d from %04d to %04d.\n",line[i],ans[2*i],ans[2*i+1]);
        }
        ans.clear();line.clear();
        tmp1.clear();tmp2.clear();
        book1.assign(idx,INF);book2.assign(idx,INF);
    }

}
signed main(){
    int _=1;
    while(_--)solve();
    return 0;
}
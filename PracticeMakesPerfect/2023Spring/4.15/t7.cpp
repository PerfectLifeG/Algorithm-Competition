#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m;
int h[N],e[N],ne[N],idx2;
int fa[N];
int cnt[N];
void add(int a,int b){
    e[idx2]=b;
    ne[idx2]=h[a];
    h[a]=idx2++;
}
unordered_map<string,int>mp;
int dfs(int t){
    for(int i=h[t];~i;i=ne[i]){
        int j=e[i];
        cnt[t]+=dfs(j);
    }
    return cnt[t];
}
int main(){
    cin>>n>>m;
    int idx=1;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        string a,b;cin>>a>>b;
        if(!mp.count(a))mp[a]=idx++;
        if(!mp.count(b))mp[b]=idx++;
        if(a[0]>='0'&&a[0]<='9')cnt[mp[a]]=1;
        add(mp[b],mp[a]);
        fa[mp[a]]=mp[b];
    }
    int root;
    for(int i=1;i<idx;i++){
        if(!fa[i]){
            root=i;break;
        }
    }
    fa[root]=-1;
    dfs(root);
    char op[2];
    while(cin>>op){
     if(*op=='Q'){
         string a;cin>>a;
        if(!mp.count(a)){
            cout<<0<<endl;
            continue;
        }
         cout<<cnt[mp[a]]<<endl;
     }else if(*op=='T'){
         string a,b;cin>>a>>b;
         if(!mp.count(a)){
             mp[a]=idx++;
             // if(!mp.count(b)){
             //    mp[b]=idx++;
             //    cnt[mp[b]]++;
             //    fa[mp[b]]=-1;
             //    fa[mp[a]]=mp[b];
             //     continue;
             // }
             fa[mp[a]]=mp[b];
             int idb=mp[b];
             while(1){
                 cnt[idb]++;
                 if(fa[idb]==-1)break;
                 idb=fa[idb];
             }
             continue;
         }
         // if(!mp.count(b)){
         //    mp[b]=idx++;
         //    fa[mp[b]]=-1;
         //    cnt[mp[b]]++;
         //    fa[mp[a]]=mp[b];
         //    continue;
         // }
         int ida=fa[mp[a]],idb=mp[b];
         while(1){
            cnt[ida]--;
            if(fa[ida]==-1)break;
            ida=fa[ida];
         }
         while(1){
             cnt[idb]++;
             if(fa[idb]==-1)break;
             idb=fa[idb];
         }
         fa[mp[a]]=mp[b];
     }
     else break;
    }
    return 0;
}
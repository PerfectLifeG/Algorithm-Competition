#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=1000100;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int v1[N],v2[N];
int book[N];
unordered_map<int,int>mp1;
unordered_map<int,int>mp2;
int root[N];
int find(int a)
{
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b)
{
    int fa=find(a),fb=find(b);
    root[fa]=fb;
}
void solve()
{
    int n,k;cin>>n>>k;
    int flag=0;
    for(int i=1;i<=n;i++)root[i]=i;
    while(k--){
        int a,b;cin>>a>>b;
        if(find(a)!=find(b))merge(a,b);
        else flag=1;
        // if(mp1.count(b)&&mp2.count(a)){
        //     if(find(a)==find(b))
        //     {flag=1;continue;}
        // }
        if(mp2.count(a)&&mp2.count(b)){
            v2[a]=n+a;
            continue;
        }
        if(mp1.count(a)&&mp1.count(b)){
            v1[a]=n+a;
            continue;
        }
        if(!mp1.count(a)&&!mp2.count(a)){v1[a]=a;mp1[a]=1;}
        if(!mp2.count(b)&&!mp1.count(b)){v2[b]=b;mp2[b]=1;}
    }
    sort(v1+1,v1+1+n,greater<int>());
    sort(v2+1,v2+1+n,greater<int>());
    if(flag){
        cout<<2<<endl;
        vector<int>v;
        for(int i=1;i<=n;i++){
            if(v1[i]==0)break;
            if(v1[i]>n){cout<<v1[i]-n<<' ';v.push_back(v1[i]-n);book[v1[i]-n]=1;}
            else {cout<<v1[i]<<' ';v.push_back(v1[i]);book[v1[i]]=1;}
        }
        for(int i=1;i<=n;i++){
            if(v2[i]==0)break;
            if(v2[i]>n){cout<<v2[i]-n<<' ';v.push_back(v2[i]-n);book[v2[i]-n]=1;}
            else {cout<<v2[i]<<' ';v.push_back(v2[i]);book[v2[i]]=1;}
        }
        for(int i=1;i<=n;i++){
            if(!book[i]){cout<<i<<' ';v.push_back(i);}
        }
        cout<<endl; 
        for(int i=v.size()-1;i>=0;i--){
            cout<<v[i]<<' ';
        }
    }else{
        cout<<1<<endl;
        for(int i=1;i<=n;i++){
            if(v1[i]==0)break;
            if(v1[i]>n){cout<<v1[i]-n<<' ';book[v1[i]-n]=1;}
            else {cout<<v1[i]<<' ';book[v1[i]]=1;}
        }
        for(int i=1;i<=n;i++){
            if(v2[i]==0)break;
            if(v2[i]>n){cout<<v2[i]-n<<' ';book[v2[i]-n]=1;}
            else {cout<<v2[i]<<' ';book[v2[i]]=1;}
        }
        for(int i=1;i<=n;i++){
            if(!book[i])cout<<i<<' ';
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}
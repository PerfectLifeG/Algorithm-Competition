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
const int N=11000;
const int mod=998244353;
const int INF=0x3f3f3f3f;
unordered_map<string,int>mp;
unordered_map<int,string>mp2;
int idx;
int root[N];
int cnt[N];
int cnt2[N];
int find(int a){
    if(a==root[a])return root[a];
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    int ra=find(a),rb=find(b);
    if(ra<rb)swap(ra,rb);
    root[ra]=rb;
}
void solve(){
    int n,k;cin>>n>>k;
    for(int i=0;i<=2*n;i++)root[i]=i;
    for(int i=0;i<n;i++){
        string a,b;int c;
        cin>>a>>b>>c;
        int t1,t2;
        if(mp.count(a)){
            t1=mp[a];
        }else {mp2[idx]=a;mp[a]=idx;t1=idx++;}
        if(mp.count(b)){
            t2=mp[b];
        }else {mp2[idx]=b;mp[b]=idx;t2=idx++;}
        cnt[t1]+=c;
        cnt2[t1]+=c;
        cnt2[t2]+=c;
        merge(t1,t2);
    }
    vector<int>bang[2*n+1];
    for(int i=0;i<idx;i++){
        bang[root[find(i)]].push_back(i);
        // cout<<mp2[i]<<' '<<root[i]<<endl;
    }

    set<pair<string,int>>ans;
    for(int i=0;i<idx;i++){
        int sum=0,mx=i;
        for(auto j:bang[i]){
            sum+=cnt[j];
            if(cnt2[mx]<cnt2[j]){
                mx=j;
            }
        }
        if(sum>k&&bang[i].size()>2){
            ans.insert({mp2[mx],(int)bang[i].size()});
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i.x<<' '<<i.y<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
unordered_map<int,int>book;
vector<int>nums;
int hs(int i,int is_limit,int is_num,int cnt){
    return cnt*1000000+i*100+is_limit*10+is_num;
}
int dfs(int i,int is_limit,int is_num,int cnt){
    if(i==-1){
        return cnt%mod;
    }
    if(book.count(hs(i,is_limit,is_num,cnt)))return book[hs(i,is_limit,is_num,cnt)];
    int res=0;
    if(!is_num)res+=dfs(i-1,false,false,cnt);
    res%=mod;
    int up=1;//上界
    if(is_limit)up=nums[i];
    for(int j=1-is_num;j<=up;j++){
        res+=dfs(i-1,is_limit&&j==up,true,cnt+j);
        res%=mod;
    }
    book[hs(i,is_limit,is_num,cnt)]=res%mod;
    return res%mod;
}
void solve(){
    int l,r;cin>>l>>r;
    l--;
    nums.clear();book.clear();
    while(l)nums.push_back(l%2),l/=2;
    int a1=dfs(nums.size()-1,1,0,0);  
    nums.clear();book.clear();
    while(r)nums.push_back(r%2),r/=2;
    int a2=dfs(nums.size()-1,1,0,0);
    cout<<(a2-a1+mod)%mod<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
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
const int INF=0x3f3f3f3f;
int k,b;
unordered_map<int,int>book;
vector<int>nums;
int hs(int i,int is_limit,int is_num,int cnt){
    return i*1000+is_limit*100+is_num*10+cnt;
}
int dfs(int i,int is_limit,int is_num,int cnt){
    if(cnt>k)return 0;
    if(i==-1){
        if(cnt==k)return 1;
        else return 0;
    }
    if(book.count(hs(i,is_limit,is_num,cnt)))return book[hs(i,is_limit,is_num,cnt)];
    int res=0;
    if(!is_num)res+=dfs(i-1,false,false,cnt);
    int up=b-1;//上界
    if(is_limit)up=nums[i];
    for(int j=1-is_num;j<=up;j++){
        if(j==1) res+=dfs(i-1,is_limit&&j==up,true,cnt+1);
        else if(j==0)res+=dfs(i-1,is_limit&&j==up,true,cnt);
        else break;
    }
    book[hs(i,is_limit,is_num,cnt)]=res;
    return res;
}
void solve(){
    int l,r;cin>>l>>r;l--;
    cin>>k>>b;
    while(r)nums.push_back(r%b),r/=b;
    int t1=dfs(nums.size()-1,1,0,0);
    nums.clear();book.clear();
    while(l)nums.push_back(l%b),l/=b;
    int t2=dfs(nums.size()-1,1,0,0);
    cout<<t1-t2<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
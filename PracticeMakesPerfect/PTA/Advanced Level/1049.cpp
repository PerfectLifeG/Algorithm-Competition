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
vector<int>nums;
unordered_map<int,int>book;
int hs(int i,int is_limit,int is_num,int cnt){
    // cout<<i<<' '<<is_limit<<' '<<is_num<<' '<<cnt<<endl;
    return cnt*100000ll+i*100ll+is_limit*10ll+is_num;
}
int ans;
string s;
void dfs(int i,int is_limit,int is_num,int cnt,string p){
    if(i==-1){
        cout<<p<<' '<<cnt<<endl;
        ans+=cnt;
        return;
    }
    // cout<<p<<' '<<i<<' '<<is_limit<<' '<<is_num<<' '<<cnt<<' ';
    // cout<<hs(i,is_limit,is_num,cnt)<<endl;
    if(book.count(hs(i,is_limit,is_num,cnt)))return;
    // cout<<p<<' '<<i<<' '<<is_limit<<' '<<is_num<<' '<<cnt<<endl;
    if(!is_num)dfs(i-1,false,false,cnt,p);
    int up=9;//上界
    if(is_limit)up=nums[i];
    for(int j=1-is_num;j<=up;j++){
        if(j==1)dfs(i-1,is_limit&&j==up,true,cnt+1,p+char('0'+j));
        else dfs(i-1,is_limit&&j==up,true,cnt,p+char('0'+j));
    }
    // cout<<p<<':'<<i<<' '<<is_limit<<' '<<is_num<<' '<<cnt<<endl;
    book[hs(i,is_limit,is_num,cnt)]=1;
}
void solve(){
    int n;cin>>n;
    while(n)nums.push_back(n%10),n/=10;//把n的每一位扣出来
    dfs(nums.size()-1,1,0,0,"");
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
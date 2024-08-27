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
int hs(int i,int is_limit,int is_num,int cnt,int pre){
    return cnt*1000000+i*1000+is_limit*100+is_num*10+pre;
}
int dfs(int i,int is_limit,int is_num,int cnt,int pre,string p){
    // cout<<i<<' '<<is_limit<<' '<<p<<endl;
    if(i==-1){
        // cout<<p<<' '<<cnt<<endl;
        if(cnt>=2)return is_num;
        return 0;
    }
    if(book.count(hs(i,is_limit,is_num,cnt,pre)))return book[hs(i,is_limit,is_num,cnt,pre)];
    int res=0;
    if(!is_num)res+=dfs(i-1,false,false,cnt,pre,p);
    int up=9;
    if(is_limit)up=nums[i];
    if(is_num){
        int j=pre+2;
        // if(pre==9)cout<<j<<' '<<up<<endl;
        if(j<=up)res+=dfs(i-1,is_limit&&j==up,true,cnt+1,j,p+char('0'+j));
        j=pre-2;
        if(j>=0&&j<=up)res+=dfs(i-1,is_limit&&j==up,true,cnt+1,j,p+char('0'+j));
    }else{
        for(int j=1;j<=up;j++){
            res+=dfs(i-1,is_limit&&j==up,true,cnt+1,j,p+char('0'+j));
        }
    }
    book[hs(i,is_limit,is_num,cnt,pre)]=res;
    return res;
}
void solve(){
    int n;cin>>n;
    while(n)nums.push_back(n%10),n/=10;
    // for(auto i:nums)cout<<i<<' ';cout<<endl;
    cout<<dfs(nums.size()-1,1,0,0,0,"")<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
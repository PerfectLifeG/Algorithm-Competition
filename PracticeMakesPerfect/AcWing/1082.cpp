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
unordered_map<int,int>book;
vector<int>nums;

int hs(int i,int mask,int is_limit,int is_num){
    return i*1000000ll+mask*100ll+is_limit*10ll+is_num;
}
int dfs(int i,int mask,int is_limit,int is_num,int mx){
    if(i==-1)return is_num;
    if(book.count(hs(i,mask,is_limit,is_num)))return book[hs(i,mask,is_limit,is_num)];
    int res=0;
    if(!is_num)res+=dfs(i-1,mask,false,false,mx);
    int up=9;//上界
    if(is_limit)up=nums[i];
    for(int j=up;j>=1-is_num&&j>=mx;j--){
        if(((mask>>j)&1)==0)
            res+=dfs(i-1,mask|(1<<j),is_limit&&j==up,true,max(mx,j));
        else{
            res+=dfs(i-1,mask|(1<<j),is_limit&&j==up,true,max(mx,j));
            break;
        }
    }
    book[hs(i,mask,is_limit,is_num)]=res;
    return res;
}
void solve(){
    int l,r;
    while(cin>>l>>r){
        l--;
        nums.clear();book.clear();
        while(r)nums.push_back(r%10),r/=10;//把n的每一位扣出来
        int t1=dfs(nums.size()-1,0,1,0,0);
        nums.clear();book.clear();
        while(l)nums.push_back(l%10),l/=10;//把n的每一位扣出来
        int t2=dfs(nums.size()-1,0,1,0,0);
        cout<<t1-t2<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
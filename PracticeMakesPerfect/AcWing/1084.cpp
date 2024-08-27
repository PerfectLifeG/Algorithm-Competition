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
int m;
unordered_map<int,int>book;
vector<int>nums;
int hs(int i,int is_limit,int is_num,int sum){
    return i*1000+is_limit*100+is_num*10+sum;
}
int dfs(int i,int is_limit,int is_num,int sum){
    if(i==-1){
        if(sum%m==0)return is_num;
        else return 0;
    }
    if(book.count(hs(i,is_limit,is_num,sum)))return book[hs(i,is_limit,is_num,sum)];
    int res=0;
    if(!is_num)res+=dfs(i-1,false,false,sum);
    int up=9;//上界
    if(is_limit)up=nums[i];
    for(int j=1-is_num;j<=up;j++){
        res+=dfs(i-1,is_limit&&j==up,true,sum+j);
    }
    book[hs(i,is_limit,is_num,sum)]=res;
    return res;
}
void solve(){
    int l,r;
    while(cin>>l>>r>>m){
        int n=r;
        nums.clear();book.clear();
        while(n)nums.push_back(n%10),n/=10;//把n的每一位扣出来
        int t1=dfs(nums.size()-1,1,0,0);
        nums.clear();book.clear();
        n=l-1;
        while(n)nums.push_back(n%10),n/=10;//把n的每一位扣出来
        int t2=dfs(nums.size()-1,1,0,0);
        cout<<t1-t2<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
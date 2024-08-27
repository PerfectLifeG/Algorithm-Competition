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
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
unordered_map<int,array<int,3>>book;
vector<int>nums;
int hs(int i,int is_limit,int is_num,int sum,int t){
    return t*100000+i*1000+is_limit*100+is_num*10+sum;
}
int pw[20];
int m;
//18*2*2*7*7*9
array<int,3> dfs(int i,int is_limit,int is_num,int sum,int t){
    if(i==-1){
        if(t==0||sum==0){
            return {0,0,0};
        }
        return {0,0,1};
    }
    if(book.count(hs(i,is_limit,is_num,sum,t))){
        return book[hs(i,is_limit,is_num,sum,t)];
    }
    int res=0,add=0,cnt=0;
    if(!is_num){
        auto p=dfs(i-1,false,false,sum,t);
        res+=p[0];res%=mod;
        add+=p[1];add%=mod;
        cnt+=p[2];cnt%=mod;
    }
    int up=9;
    if(is_limit)up=nums[i];
    for(int j=1-is_num;j<=up;j++){
        if(j==7)continue;
        auto p=dfs(i-1,is_limit&&j==up,true,(sum+j)%7,(t*10+j)%7);
        int tt=j*pw[i]%mod;
        res+=(p[2]*tt%mod*tt%mod+2*tt*p[1]%mod+p[0])%mod;res%=mod;
        add+=(p[2]*tt%mod+p[1])%mod;add%=mod;
        cnt+=p[2]%mod;cnt%=mod;
    }
    book[hs(i,is_limit,is_num,sum,t)]={res,add,cnt};
    return {res,add,cnt};
}
void solve(){
    int l,r;cin>>l>>r;
    int n=r;
    nums.clear();book.clear();
    while(n)nums.push_back(n%10),n/=10;//把n的每一位扣出来
    auto t1=dfs(nums.size()-1,1,0,0,0);
    nums.clear();book.clear();
    n=l-1;
    while(n)nums.push_back(n%10),n/=10;//把n的每一位扣出来
    auto t2=dfs(nums.size()-1,1,0,0,0);
    cout<<(t1[0]-t2[0]+mod)%mod<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    int t=1;
    for(int i=0;i<=18;i++){
        pw[i]=t;
        t*=10;t%=mod;
    }
    while(_--)solve();
    return 0;
}
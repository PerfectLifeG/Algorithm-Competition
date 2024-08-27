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
int hs(int i,int is_limit,int is_num,int flag){
    return i*1000+is_limit*100+is_num*10+flag;
}
string s;
unordered_map<char,int>mp;
int dfs(int i,int is_limit,int is_num,int flag){
    if(i==-1){
        if(flag)return 0;
        return is_num;
    }
    if(book.count(hs(i,is_limit,is_num,flag)))return book[hs(i,is_limit,is_num,flag)];
    int res=0;
    // if(!is_num)res+=dfs(i-1,false,false,flag);
    int up=9;//上界
    if(is_limit)up=nums[i];
    if(s[i]=='_'){
        for(int j=1-is_num;j<=up;j++){
            res+=dfs(i-1,is_limit&&j==up,true,(flag*10+j)%8);
        }
    }else if(s[i]<='9'&&s[i]>='0'){
        if(s[i]-'0'>up)res=0;
        else if(!is_num&&s[i]=='0')res=0;
        else res+=dfs(i-1,true,true,(flag*10+s[i]-'0')%8);
    }else{
        if(!mp.count(s[i])){
            for(int j=1-is_num;j<=up;j++){
                mp[s[i]]=j;
                res+=dfs(i-1,is_limit&&j==up,true,(flag*10+j)%8);
            }
        }else
            res+=dfs(i-1,is_limit&&mp[s[i]]==up,true,(flag*10+mp[s[i]])%8);
    }
    book[hs(i,is_limit,is_num,flag)]=res;
    return res;
}
void solve(){
    int n;cin>>n;
    mp.clear();book.clear();nums.clear();
    cin>>s;
    reverse(s.begin(),s.end());
    int y;cin>>y;
    while(y)nums.push_back(y%10),y/=10;
    cout<<dfs(nums.size()-1,1,0,0)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
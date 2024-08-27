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
// unordered_map<int,int>book;
vector<int>nums;
string s;
unordered_map<char,int>mp;
char op[4]={'a','b','c','d'};
int dfs(int i,int is_limit,int is_num,int flag,string p){
    if(i==-1){
        // cout<<p<<' '<<flag<<endl;
        if(flag)return 0;
        return is_num;
    }
    int res=0;
    int up=9;//上界
    if(is_limit)up=nums[i];
    if(s[i]>='0'&&s[i]<='9'){
        if(s[i]-'0'>up)res=0;
        else if(!is_num&&s[i]=='0')res=0;
        else res+=dfs(i-1,is_limit&&s[i]-'0'==up,true,(flag*10+s[i]-'0')%8,p+s[i]);
    }else if(s[i]=='_'){
        int j;
        if(!is_num&&i==0)j=0;
        else j=1-is_num;
        for(;j<=up;j++){
            res+=dfs(i-1,is_limit&&j==up,true,(flag*10+j)%8,p+char('0'+j));
        }
    }else{
        if(mp.count(s[i])&&mp[s[i]]!=-1){
            res+=dfs(i-1,is_limit&&mp[s[i]]==up,true,(flag*10+mp[s[i]])%8,p+char('0'+mp[s[i]]));
        }else{
            for(int j=1-is_num;j<=up;j++){
                int pp=0;
                for(int k=0;k<4;k++){
                    if(s[i]==op[k])continue;
                    if(mp.count(op[k])&&mp[op[k]]==j){
                        pp=1;
                        break;
                    }
                }
                if(pp)continue;
                // cout<<flag<<"!"<<j<<endl;
                mp[s[i]]=j;
                res+=dfs(i-1,is_limit&&j==up,true,(flag*10+j)%8,p+char('0'+j));
            }
            mp[s[i]]=-1;
        }
    }
    return res;
}
void solve(){
    int n;cin>>n;
    mp.clear();nums.clear();
    cin>>s;
    reverse(s.begin(),s.end());
    int y;cin>>y;
    while(y)nums.push_back(y%10),y/=10;
    cout<<dfs(nums.size()-1,1,0,0,"")<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
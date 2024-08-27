#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
string s;
int n;
int flag;
void dfs(int l,int r,int now){
    // cout<<l<<' '<<r<<' '<<now<<endl;
    if(flag!=-2)return;
    if(l+1<r-1&&s[l]==s[r]&&now==s[l]&&(s[l+1]==now||s[r-1]==now)){
        flag=now;
        return;
    }
    if(l+1<=r-1&&s[l]==s[r]&&now==s[l]&&s[l+1]==(now^1)&&s[r-1]==(now^1)){
        while(r-3>=l+1&&s[r-2]==now&&s[r-3]==(now^1)){
            r-=2;
        }
        while(r-1>=l+3&&s[l+2]==now&&s[l+3]==(now^1)){
            l+=2;
        }
        if(l+3<r-1&s[l+2]==now&&s[l+3]==now||(r-3>l+1&&s[r-2]==now&&s[r-3]==now)){
           flag=now;
            return; 
        }
        r-=2;l+=2;
    }

    // 010010
    //01 0 10
    //01 0 10
    //01 00 10
    //01 1 10
    //01 10 10
    //01 10

    // 010010
    // if(l+1<=r-1&&s[l]==s[r]&&now==s[l]&&s[l+1]==(now^1)&&s[r-1]==(now^1)){
        
    // }

    if(l>r){flag=-1;return;}
    if(l==r&&s[l]==now){flag=-1;return;}
    if(l==r&&s[l]!=now){flag=now^1;return;}

    if(now==s[l])dfs(l+1,r,now^1);
    else if(now==s[r]) dfs(l,r-1,now^1);
    else {flag=now^1;return;}
}
void solve()
{
    cin>>n;
    cin>>s;
    // cout<<s<<endl;
    for(int i=0;i<s.size();i++)s[i]-='0';
    flag=-2;
    dfs(0,s.size()-1,0);
    cout<<flag<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    string s;cin>>s;
    int n=s.size();
    int now=-1;
    int flag=-1;
    int flag2=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='+'){
            now++;
        }
        else if(s[i]=='-'){
            now--;
            if(now<flag)flag=-1;
            if(flag==0)flag=-1;
            if(now<flag2)flag2=now;
        }
        else if(s[i]=='1'){
            if(flag!=-1){
                if(now>=flag){
                    no;return;
                }
            }
            if(now==-1){
                continue;
            }
            flag2=now;
        }else{
            if(now<=0){
                no;return;
            }
            if(flag2!=-1){
                if(now>=flag2){
                    no;return;
                }
            }
            if(flag==-1)flag=now;
            flag=min(flag,now);
        }
        if(flag==0)flag=-1;if(flag2==0)flag2=-1;
        // cout<<i<<' '<<now<<' '<<flag<<' '<<flag2<<endl;
    }
    yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
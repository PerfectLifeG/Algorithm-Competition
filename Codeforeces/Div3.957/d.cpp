#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,m,k;cin>>n>>m>>k;
    string s;cin>>s;s='L'+s+'L';
    int f=1;
    int at=0;
    while(at<=n){
        if(s[at]=='L'){
            int ff=0;
            for(int i=1;i+at<=n+1&&i<=m;i++){
                if(s[i+at]=='L'){
                    at=i+at;
                    ff=1;
                    break;
                }
            }
            if(!ff){
                at+=m;
                if(s[at]=='C'){f=0;break;}
            }
        }else{
            k--;
            if(k<0){f=0;break;}
            if(s[at]=='C'){f=0;break;}
            at++;
        }
    }
    if(f)yes;
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
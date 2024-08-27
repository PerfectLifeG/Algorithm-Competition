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
void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    int t=s.find('I');
    int l=t-1,r=t+1;
    int idx=0;
    while(k--){
        string op;cin>>op;
        if(op=="backspace"){
            if(l==-1)continue;
            if(r<n){
                if(s[l]=='('&&s[r]==')'){
                    r++;
                }
            }
            l--;
        }else if(op=="delete"){
            if(r==n)continue;
            r++;
        }else if(op=="<-"){
            if(l==-1)continue;
            s[r-1]=s[l];
            r--;
            l--;
        }else{
            if(r==n)continue;
            s[l+1]=s[r];
            r++;
            l++;
        }
    }
    cout<<s.substr(0,l+1)<<'I'<<s.substr(r)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
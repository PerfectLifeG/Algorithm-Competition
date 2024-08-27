#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<string,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int n;
PII check(string s){
    int cnt=s.size();
    if(s=="0")cnt=0;
    string t=s;
    if(s.find('.')!=-1){
        cnt=s.find('.');
        t=s.substr(0,s.find('.'))+s.substr(s.find('.')+1);
        if(t[0]=='0'){
            cnt=0;
            for(int i=1;i<t.size();i++){
                if(t[i]!='0'){
                    t=t.substr(i);
                    cnt=1-i;
                    break;
                }
            }
        }
    }
    if(t.size()<n){
        t+=string(n-t.size(),'0');
    }else{
        t=t.substr(0,n);
    }
    return {t,cnt};
}
void solve(){
    string a,b;cin>>n>>a>>b;
    int i=0;
    while(i+1<a.size()&&a[i]=='0'&&a[i+1]!='.')i++;a=a.substr(i);
    i=0;
    while(i+1<b.size()&&b[i]=='0'&&b[i+1]!='.')i++;b=b.substr(i);
    PII t1=check(a);
    PII t2=check(b);
    if(t1==t2){
        cout<<"YES 0."<<t1.x<<"*10^"<<t1.y<<endl;
    }else{
        cout<<"NO 0."<<t1.x<<"*10^"<<t1.y<<" 0."<<t2.x<<"*10^"<<t2.y<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
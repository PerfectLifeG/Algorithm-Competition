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
    int n;cin>>n;string t;cin>>t;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        // cout<<t<<' '<<s<<endl
        if(t=="Camel"){
            string ans="";
            if(s.find('_')!=-1){
                for(int i=1;i<s.size();i++){
                    if(s[i-1]=='_'){
                        s[i]=s[i]-'a'+'A';
                    }
                }
                for(auto i:s)if(i!='_')cout<<i;
                cout<<endl;
            }else if(s[0]>='A'&&s[0]<='Z'){
                s[0]=s[0]-'A'+'a';
                cout<<s<<endl;
            }else{
                cout<<s<<endl;
            }
        }
        if(t=="Snake"){
            string ans="";
            if(s.find('_')!=-1){
                cout<<s<<endl;
            }else if(s[0]>='A'&&s[0]<='Z'){
                ans+=(s[0]-'A'+'a');
                for(int i=1;i<s.size();i++){
                    if(s[i]>='A'&&s[i]<='Z'){
                        ans+='_';
                        ans+=(s[i]-'A'+'a');
                    }else ans+=s[i];
                }
                cout<<ans<<endl;
            }else{
                ans+=s[0];
                for(int i=1;i<s.size();i++){
                    if(s[i]>='A'&&s[i]<='Z'){
                        ans+='_';
                        ans+=(s[i]-'A'+'a');
                    }else ans+=s[i];
                }
                cout<<ans<<endl;
            }
        }
        if(t=="Pascal"){
            string ans="";
            if(s.find('_')!=-1){
                for(int i=1;i<s.size();i++){
                    if(s[i-1]=='_'){
                        s[i]=s[i]-'a'+'A';
                    }
                }
                s[0]=s[0]-'a'+'A';
                for(auto i:s)if(i!='_')cout<<i;
                cout<<endl;
            }else if(s[0]>='A'&&s[0]<='Z'){
                cout<<s<<endl;
            }else{
                s[0]=s[0]-'a'+'A';
                cout<<s<<endl;
            }
        }

    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
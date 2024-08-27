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
char check(char c){
    if(c>='0'&&c<='9')return c;
    if(c>='a'&&c<='z')return c;
    if(c>='A'&&c<='Z')return (c-'A'+'a');
    return '.';
}
map<string,int>mp;
void solve(){
    string s;
    getline(cin,s);
    s+='.';
    int n=s.size();
    int mx=0;
    for(int i=0;i<n;){
        if(check(s[i])=='.'){i++;continue;}
        int j=i+1;
        string tmp="";tmp+=check(s[i]);
        while(j<n&&check(s[j])!='.'){tmp+=check(s[j]);j++;}
        mp[tmp]++;mx=max(mx,mp[tmp]);
        i=j;
    }
    for(auto [i,j]:mp){
        if(j==mx){
            cout<<i<<' '<<j<<endl;
            return;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
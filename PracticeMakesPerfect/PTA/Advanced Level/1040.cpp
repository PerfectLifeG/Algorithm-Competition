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

int manercher(string t){
    string s="$#";
    for(int i=0;i<t.size();i++){
        s+=t[i];s+='#';
    }
    s+='^';
    vector<int>p(s.size());
    int mr=0,mid;
    for(int i=1;i<s.size();i++){
        if(i<mr)p[i]=min(p[mid*2-i],mr-i+1);
        else p[i]=1;
        while(s[i-p[i]]==s[i+p[i]])p[i]++;//最多执行n次
        if(i+p[i]>mr){
            mid=i;
            mr=i+p[i]-1;
        }
    }
    int ans=0;
    for(int i=0;i<p.size();i++){
        ans=max(p[i]-1,ans);
    }
    return ans;
}

void solve(){
    string s;getline(cin,s);
    cout<<manercher(s)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
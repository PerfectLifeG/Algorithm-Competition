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
int check(char a){
    if(a=='0'||a=='2'||a=='4'||a=='6'||a=='8')return 1;
    return 0;
}
int cmp(string a,string b){
    if(a.size()==b.size()){
        return a<b;
    }else{
        int ta=a.size();
        int tb=b.size();
        return ta<tb;
    }
}
void solve(){
    string s;cin>>s;
    vector<string>ans;
    for(int i=0;i<s.size();i++){
        if(!check(s[i])){continue;}
        int j=i-1;
        while(j>=0&&!check(s[j]))j--;
        ans.push_back(s.substr(j+1,i-j));
    }   
    sort(all(ans),cmp);
    for(auto i:ans)cout<<i<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
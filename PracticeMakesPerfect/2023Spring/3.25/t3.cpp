#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
void solve(){
    string s;cin>>s;
    int a=0,b=0;
    for(int i=0;i<s.size();i+=2){
        if(s[i]=='r'&&s[i+1]=='o'){
            if(s[i+1]=='s')a++;
            else if(s[i+1]=='r')a++,b++;
            else if(s[i+1]=='p')b++;
        }

        else if(s[i]=='s'){
            if(s[i+1]=='s')a++,b++;
            else if(s[i+1]=='r')b++;
            else if(s[i+1]=='p')a++;
        }
        else if(s[i]=='p'){
            if(s[i+1]=='s')b++;
            else if(s[i+1]=='r')a++;
            else if(s[i+1]=='p')a++,b++;
        }
    }
    if(a>b){
        cout<<"Win"<<endl;
    }else if(a==b){
        cout<<"Tie"<<endl;
    }else cout<<"Lose"<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
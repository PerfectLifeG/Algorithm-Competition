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
    string s;
    cin>>s;
    // s+='5';
    // for(int i=0;i<89;i++)s+='4';
    // s+='U';
    int n=s.size();
    int cnt=0;
    for(int i=0;i<n;){
        int j=i+1;
        if(s[i]!='3'){i++;continue;}
        while(j<n&&s[j]==s[i]){
            j++;
        }
        if(j-i>=10){
            cout<<"invalid\n";
            return;
        }
        i=j;
    }

    int lst=-1;
    s+='5';
    for(int i=0;i<n+1;i++){
        if(s[i]=='5'||s[i]=='U'){
            if(i-lst>90){
                cout<<"invalid\n";
                return;
            }
            lst=i;
        }
    }

    lst=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='5'||s[i]=='U'){
            if(lst==-1){
                lst=i;
                continue;
            }
            if(s[lst]=='5'&&s[i]=='5'){
                cout<<"invalid\n";
                return;
            }
            lst=i;
        }
    }
    cout<<"valid\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
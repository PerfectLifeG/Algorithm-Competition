#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
void solve()
{
    string s[3];
    for(int i=0;i<3;i++){
        cin>>s[i];
    }

    for(int i=0;i<3;i++){
        if(s[0][i]!='.'&&s[0][i]==s[1][i]&&s[1][i]==s[2][i]){
            cout<<s[0][i]<<endl;
            return;
        }
    }
    for(int i=0;i<3;i++){
        if(s[i][0]!='.'&&s[i][0]==s[i][1]&&s[i][1]==s[i][2]){
            cout<<s[i][0]<<endl;
            return;
        }
    }

//     if(s[0][0]!='.'&&s[0][0]==s[1][0]&&s[1][0]==s[2][0]){
//         cout<<s[0][0]<<endl;
//         return;
//     }
//     if(s[0][1]!='.'&&s[0][1]==s[1][1]&&s[1][1]==s[2][1]){
//         cout<<s[0][1]<<endl;
//         return;
//     }
//     if(s[0][2]!='.'&&s[0][2]==s[1][2]&&s[2][2]==s[2][2]){
// cout<<s[0][2]<<endl;
//         return;
//     }

//     if(s[2][0]!='.'&&s[2][0]==s[2][1]&&s[2][1]==s[2][2]){
//         cout<<s[2][0]<<endl;
//         return;
//     }
//     if(s[0][0]!='.'&&s[0][0]==s[0][1]&&s[0][1]==s[0][2]){
//         cout<<s[0][0]<<endl;
//         return;
//     }
//     if(s[1][0]!='.'&&s[1][0]==s[1][1]&&s[1][1]==s[1][2]){
// cout<<s[1][0]<<endl;
//         return;
//     }

    if(s[0][0]!='.'&&s[0][0]==s[1][1]&&s[1][1]==s[2][2]){
cout<<s[0][0]<<endl;
        return;
    }
    if(s[0][2]!='.'&&s[0][2]==s[1][1]&&s[1][1]==s[2][0]){
cout<<s[0][2]<<endl;
        return;
    }
    cout<<"DRAW"<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
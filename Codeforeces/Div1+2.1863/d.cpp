#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n,m;cin>>n>>m;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    vector<int>row(n),col(n);
    int t=0;
    int ans[n][m];
    int flag=0;
    for(int i=0;i<n;i++){
        if(flag)break;
        for(int j=0;j<m;j++){
            if(s[i][j]=='U'){
                ans[i][j]=t;t^=1;
                ans[i+1][j]=t;
                j++;
                while(j<m&&s[i][j]!='U'){
                    j++;
                }
                // cout<<i<<' '<<j<<endl;
                if(j==m||s[i][j]!='U'){
                    flag=1;break;
                }
                ans[i][j]=t;t^=1;
                ans[i+1][j]=t;
            }
        }
    }
    if(flag){cout<<-1<<endl;return;}
    for(int j=0;j<m;j++){
        if(flag)break;
        for(int i=0;i<n;i++){
            if(s[i][j]=='L'){
                ans[i][j]=t;t^=1;
                ans[i][j+1]=t;
                i++;
                while(i<n&&s[i][j]!='L'){
                    i++;
                }
                // cout<<i<<' '<<j<<endl;
                if(i==n||s[i][j]!='L'){
                    flag=1;break;
                }
                ans[i][j]=t;t^=1;
                ans[i][j+1]=t;
            }
        }
    }
    if(flag){cout<<-1<<endl;return;}
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='.')cout<<'.';
            else if(ans[i][j]==0)cout<<'W';
            else if(ans[i][j]==1)cout<<'B';
        }
        cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
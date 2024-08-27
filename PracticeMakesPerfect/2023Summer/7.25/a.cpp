#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n,z;
    cin>>n>>z;
    string s[n];
    int flag=1;
    for(int k=0;k<n;k++){
        cin>>s[k];
        if(!flag)continue;
        for(int i=0;i<n;){
            int j=i+1;
            while(j<n&&s[k][j]==s[k][i]){
                j++;
            }
            int cnt=j-i;
            if(cnt*z%100!=0){
                flag=0;
            }
            i=j;
        }   
    }
    if(!flag){
        cout<<"error"<<endl;
        return;
    }
    for(int k=0;k<n;k++){
        if(!flag)continue;
        for(int i=0;i<n;){
            int j=i+1;
            while(j<n&&s[j][k]==s[i][k]){
                j++;
            }
            int cnt=j-i;
            if(cnt*z%100!=0){
                flag=0;
            }
            i=j;
        }
    }
    if(!flag){
        cout<<"error"<<endl;
        return;
    }
    // aabb
    // aabb

    // aaaabbbb
    // aaaabbbb
    // aaaabbbb
    // aaaabbbb

    // aabb
    // aabb
    string ans[n];
    for(int k=0;k<n;k++){
        for(int i=0;i<n;){
            int j=i+1;
            while(j<n&&s[k][j]==s[k][i]){
                j++;
            }
            int cnt=(j-i);
            int t=cnt*z/100;
            while(t--){
                ans[k].push_back(s[k][i]);
            }
            i=j;
        }
    }
    // for(int k=0;k<n;k++)cout<<ans[k]<<endl;
    string ans2[2*n];
    for(int k=0;k<2*n;k++){
        for(int i=0;i<n;){
            int j=i+1;
            while(j<n&&ans[j][k]==ans[i][k]){
                j++;
            }
            int cnt=j-i;
            int t=cnt*z/100;
            while(t--){
                ans2[k].push_back(ans[i][k]);
            }
            i=j;
        }
    }
    // for(int k=0;k<2*n;k++)cout<<ans2[k]<<endl;
    for(int i=0;i<2*n;i++){
        for(int j=0;j<2*n;j++)
            cout<<ans2[j][i];
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
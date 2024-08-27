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
    int n;cin>>n;
    string s[2];cin>>s[0]>>s[1];
    s[0]='W'+s[0];
    s[1]='W'+s[1];n++;
    int ans=0;
    int sum=0;
    for(int i=0;i<n;i++){
        if(s[0][i]=='W'&&s[1][i]=='W'){
            int st,ed;
            while(i<n&&s[0][i]=='W'&&s[1][i]=='W')i++;
            if(i==n)break;
            sum=0;
            while(i<n){
                if(s[0][i]!=s[1][i]){
                    if(s[0][i]=='R')ed=0;
                    else ed=1;
                    if(st!=ed){
                        ans=max(ans,sum);
                        sum=1;
                        st=ed;
                    }
                }else if(s[0][i]==s[1][i]&&s[0][i]=='R'){
                    int j=i;
                    while(j<n&&(s[0][j]=='R'&&s[1][j]=='R')){
                        j++;
                    }
                    if(j==n||s[0][j]==s[1][j]&&s[0][j]=='W'){
                        sum+=(j-i)*2;
                        break;
                    }else{
                        if(s[0][j]=='R')ed=0;
                        else ed=1;
                        if(st==ed){
                            if((j-i)%2==0){
                                sum+=(j-i)*2;
                            }else sum+=(j-i)*2-1;
                        }else{
                            if((j-i)%2==0){
                                sum+=(j-i)*2-1;
                            }else sum+=(j-i)*2;
                        }
                        sum++;
                        st=ed;
                    }
                    i=j;
                }
                i++;
            }
            ans=max(ans,sum);
        }
    }
    ans=max(ans,sum);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
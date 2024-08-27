#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int ru[7];
int book[7][7]={INF};
void solve(){
    string s;
    cin>>s;if(s=="true")book[2][1]=1,ru[1]++;else book[1][2]=1,ru[2]++;
    cin>>s;if(s=="true")book[3][1]=1,ru[1]++;else book[1][3]=1,ru[3]++;
    cin>>s;if(s=="true")book[3][2]=1,ru[2]++;else book[2][3]=1,ru[3]++;
    cin>>s;if(s=="true")book[2][1]=1,ru[1]++;else book[1][2]=1,ru[2]++;
    cin>>s;if(s=="true")book[3][1]=1,ru[1]++;else book[1][3]=1,ru[3]++;
    cin>>s;if(s=="true")book[3][2]=1,ru[2]++;else book[2][3]=1,ru[3]++;
    int f=0;
    int flag=0;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(book[i][j]==1&&book[j][i]==1){goto l;}
            for(int k=1;k<=3;k++){
                if(book[i][k]==1&&book[k][i]==1||book[j][k]==1&&book[k][j]==1){goto l;}
                if(book[i][j]==1&&book[j][k]==1&&book[k][i]==1){
                    flag=1;
                }
            }
        }
    }
    if(flag){cout<<7<<endl;return;}
    l:
    for(int i=1;i<=3;i++){
        for(int j=i;j<=3;j++){
            if(book[i][j]==1&&book[j][i]==1){
                f++;
            }
        }
    }
    if(f==3){
        cout<<4<<endl;
    }else if(f==2){
        cout<<5<<endl;
    }else if(f==1){
        cout<<6<<endl;
    }else cout<<8<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
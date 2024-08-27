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
int n,m,hp,dmg;
void P(){
    cout<<'+';
    for(int i=0;i<m;i++){
        cout<<'-';
    }
    cout<<'+'<<endl;
}
void solve(){
    cin>>n>>m>>hp>>dmg;
    int k1=hp/m,k2=hp%m;
    int x=dmg/m,y=dmg%m;

    vector<int>v(m);
    for(int i=0;i<m;i++){
        v[i]=k1;
        if(k2>i)v[i]++;
        v[i]-=x;
    }

    string s;
    if(x!=0&&y==0&&k1!=0){
        for(int i=0;i<m;i++){
            s+='.';
        }
        P();
        for(int p=0;p<n;p++){
            cout<<'|';
            cout<<s;
            cout<<'|'<<endl;
        }
        P();
        return;
    }else{
        for(int i=0;i<m;i++){
            if(v[i])s+=('A'+(v[i]+4)%5);
            else {
                if(k1==0)s+=' ';
                else s+='.';
            }
        }
    }

    int flag=-1;
    for(int i=1;i<m;i++){
        if(s[i]!=s[i-1]){flag=i-1;break;}
    }
    for(int i=flag;i>=0;i--){
        if(y){s[i]='.';y--;}
    }
    for(int i=m-1;i>flag;i--){
        if(y){s[i]='.';y--;}
    }

    P();
    for(int p=0;p<n;p++){
        cout<<'|';
        cout<<s;
        cout<<'|'<<endl;
    }
    P();

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}
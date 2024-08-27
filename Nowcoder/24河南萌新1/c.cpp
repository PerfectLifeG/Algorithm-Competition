#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=510;
const int M=250010;
int n1,n2,m;
int book[N];
int match[N];
int e[M],h[N],ne[M],idx;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
bool find(int t){
    for(int i=h[t];i!=-1;i=ne[i]){
        int j=e[i];
        if(book[j]==0){
            book[j]=1;
            if(match[j]==0||find(match[j])){
               match[j]=t;
               return true;
            }
        }
    }
    return false;
}
signed main(){
    memset(h,-1,sizeof(h));
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int a;cin>>a;
            add(i,a);
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        memset(book,0,sizeof(book));
        if(find(i))cnt++;
    }
    if(cnt==n){
        yes;
    }else {
        no;
        cout<<n-cnt<<endl;
    }
    return 0;
}
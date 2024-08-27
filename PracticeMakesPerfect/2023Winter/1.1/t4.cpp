#include<bits/stdc++.h>
using namespace std;
const int N=10;
int book[N];
int book2[N];
int main(){
    int n,m;cin>>n>>m;
    int idx;
    memset(book2,1,sizeof book2);
    int num=n;
    for(int i=0;i<m;i++){
        int a,b;double c;
        cin>>a>>b>>c;
        if(num==1){printf("1\n%d",b);return 0;}
        if(c<37.5)book[b]++;
        if(c>=37.5){if(book2[b]==1){num--;book2[b]=0;}}
        idx=a;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(book[i]==idx)cnt++;
    }
    cout<<cnt<<endl;
    int flag=1;
    for(int i=1;i<=n;i++){
        if(book[i]==idx&&flag==0)cout<<" "<<i;
        if(book[i]==idx&&flag){cout<<i;flag=0;}
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int lowbit(int x){
    return x&-x;
}
int cnt1(int x){
    int cnt=0;
    while(x){
        x-=lowbit(x);
        cnt++;
    }
    return cnt;
}
int book[N];
int a[N];
int b[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++){cin>>a[i];b[a[i]]++;}
    sort(a,a+n);
    int cnt=1;
    for(int i=n-1;i>=0;i++){
        for(int j=0;j<b[a[i]];j++){
            book[cnt]=a[i-j];
            cnt++;
        }
    }
    for(int i=0;i<q;i++){
        int a;cin>>a;
        if(a>=idx)cout<<1<<endl;
        else cout<<book[a]<<endl;
    }
    return 0;
}
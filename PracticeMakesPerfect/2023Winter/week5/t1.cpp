#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int book[N];
int book1[N];
int book2[N];
unordered_map<int,int>mp;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    int idx;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(a==0)idx=i;
        book1[i]=a;
        book2[a]=i;
        if(i==a)book[a]=1;
    }
    int flag=0;if(book[0])flag=1;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(book[book1[i]])continue;
        int j=i;
        while(!book[book1[j]]){
            book[book1[j]]++;
            j=book1[j];
            cnt++;
        }
        cnt++;
    }
    if(flag)cout<<cnt;
    else cout<<cnt-2;
    return 0;
}
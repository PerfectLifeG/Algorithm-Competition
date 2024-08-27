#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int book[N];
int a[N];
int n;
vector<int>v1,v2;
int num(int j){
    int ret=1;
    while(j-1>0){
        if(v2[j]%n==v2[j-1]%n){ret++;j--;}
        else break;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    int flag=-1;int f2=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        book[a[i]]=i;
        if(a[i]<0)continue;
        if(a[i]%n==i){v1.push_back(a[i]);if(f2){flag=i;f2=0;}a[i]=-1;}
        else if(flag>=0&&i>a[i]%n){v2.push_back(a[i]);a[i]=-1;}
    }
    for(int i=0;i<n;i++)if(a[i]!=-1)v2.push_back(a[i]);
    sort(v1.begin(),v1.end());
    printf("%d",v1[0]);
    int idx=0;
    for(int i=1;i<v1.size();i++){
        for(int j=idx;j<v2.size();j++){
            if(v2[j]<v1[i]&&book[v2[j]]<book[v1[i]]&&v2[j]%n<v1[i]%n){
                printf(" %d",v2[j]);idx++;
            }
            else break;
        }
        printf(" %d",v1[i]);
    }
    for(int i=idx;i<v2.size();i++){
        printf(" %d",v2[i]);
    }
    return 0;
}
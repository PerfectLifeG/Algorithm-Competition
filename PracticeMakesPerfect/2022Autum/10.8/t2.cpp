#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int mx,flag;
int a[N];
int main(){
    int n;cin>>n;
    vector<int>v;
    for (int i = 1; i <= n; i++)
    {
        int b;cin>>b;
        v.push_back(b);
        a[i]=b;
        if(mx<b){
            mx=b;
            flag=i;
        }
    }
    sort(v.begin(),v.end());
    for(int h=1,r=1;h<=n;){
        while(r<n && a[r]!=*(v.end()-1))r++;
        v.erase(v.end()-1);
        int flag2=r;
        while(flag2>=h){
            printf("%d ",a[flag2]);
            flag2--;
        }
        h=r+1;
        r++;
    }
    return 0;
}
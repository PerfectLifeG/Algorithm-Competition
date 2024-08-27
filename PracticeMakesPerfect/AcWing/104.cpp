#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int a[N];
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int t=a[n/2];
    int s=0;
    for(int i=0;i<n;i++){
        s+=abs(t-a[i]);
    }
    cout<<s;
    return 0;
}
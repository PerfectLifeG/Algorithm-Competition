#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
multiset<int>s;
int a[N];
int book[N];
int book2[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];if(book[a[i]]==0){book[a[i]]=i;s.insert(i);book2[i]++;}
        else {s.insert(book[a[i]]);book2[book[a[i]]]++;}
        for(int j=1;j<=a[i]/j&&a[i]!=1;j++){
            if(a[i]%j==0){
                if(book[j]!=0){s.insert(book[j]);book2[book[j]]++;}
            }
        }
    }
    for(int i=0;i<q;i++){
        int op,x;
        cin>>op>>x;
        if(op==1){
            a[n]=x;if(book[x]==0){book[x]=n;s.insert(n);book2[n]++;}
            else {s.insert(book[x]);book2[book[x]]++;}
            for(int i=1;i<=x/i&&x!=1;i++){
                if(x%i==0){
                    if(book[i]!=0){s.insert(book[i]);book2[book[i]]++;}
                }
            }
            n++;
        }else{
            // auto it=s.upper_bound(x);
            cout<<book2[x]-1<<endl;
        }
    }
    return 0;
}
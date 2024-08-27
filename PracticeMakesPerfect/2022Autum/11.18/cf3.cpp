#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int l,r,x,a,b;
        scanf("%d%d%d%d%d",&l,&r,&x,&a,&b);
        if(a==b){cout<<0<<endl;continue;}
        else if(abs(b-a)>=x){cout<<1<<endl;continue;}
        else if(a<b){
            if(a-x>=l||b+x<=r)cout<<2<<endl;
            else if(b-x>=l&&a+x<=r){
            cout<<3<<endl;
            }else cout<<-1<<endl;
        }else{
            if(a+x<=r||b-x>=l)cout<<2<<endl;
            else if(b+x<=r&&a-x>=l){
            cout<<3<<endl;
            }else cout<<-1<<endl;
        }
    }
    return 0;
}
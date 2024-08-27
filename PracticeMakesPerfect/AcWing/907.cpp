#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int st,ed,n;
struct Range
{
    int l,r;
    bool operator<(const Range &a)const
    {
        return l<a.l;
    }
}range[N];

int main(){
    cin>>st>>ed;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>range[i].l>>range[i].r;
    }
    sort(range,range+n);
    int cnt=0;int i=0;
    while(st<=ed&&i<n){
        int t=st;
        while(range[i].l<=t&&i<n){
            if(range[i].r>st){
                st=range[i].r;
            }
            i++;
        }
        if(t==st)i++;
        cnt++;
    }
    if(st<ed)cout<<-1;
    else cout<<cnt;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct note
{
    string s;
    int n;
};
bool cmp(note n1,note n2){
    return n1.n>n2.n;
}
bool cmp2(note n1,note n2){
    return n1.s<n2.s;
}
int main()
{
    vector<note>v;
    string a;
    cin>>a;
    int len=a.size();
    int n;cin>>n;
    vector<note>vv;
    vector<note>vvv;
    for (int i = 0; i < n; i++)
    {
        string s;cin>>s;
        vvv.push_back({s,n});
        if(s.size()==len){
            int j=0;int l=len-1;
            while(l>=0){
                if(s[l]==a[l])j++;
                l--;
            }
            v.push_back({s,j});
        }
    }
    sort(v.begin(),v.end(),cmp);
    int flag=v[0].n;
    for(auto it:v){
        if(it.n!=flag)break;
        vv.push_back({it.s,it.n});
    }
    sort(vv.begin(),vv.end(),cmp2);
    if(vv.size()==0){
        sort(vvv.begin(),vvv.end(),cmp2);
        for(auto it:vvv){
        cout<<it.s<<endl;
        }
    }else
    for(auto it:vv){
        cout<<it.s<<endl;
    }
    return 0;
}
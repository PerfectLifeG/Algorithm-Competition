#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
    return b<a;// 相当于 a>b 降序
}
int main()
{
    int n;cin>>n;
    vector<int>v;
    for (int i = 0; i < n; i++)
    {
        int a;cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end(),cmp);
    int len=v.size();int s=0;
    for (int i = 0; i < (len+1)/2; i++)
    {
        s+=v[i];
    }
    cout<<"Outgoing #: "<<(len+1)/2<<endl;
    int ss=0;
    for (int i = (len+1)/2; i < len; i++)
    {
        ss+=v[i];
    }
    cout<<"Introverted #: "<<len-(len+1)/2<<endl;
    cout<<"Diff = "<<s-ss;
    return 0;
}
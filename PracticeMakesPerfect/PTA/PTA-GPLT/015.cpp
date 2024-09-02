#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
    return a>b;
}
int main()
{
    int n,m,k;
    cin>>n>>k>>m;
    vector<int>vv;
    for (int i = 0; i < n; i++)
    {
        vector<int>v;
        for (int i = 0; i < k; i++)
        {
            int a;cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        v.erase(v.begin());
        v.erase(v.end()-1);
        int cnt=0;
        for (int i = 0; i < k-2; i++)
        {
            cnt+=v[i];
        }
        vv.push_back(cnt);
    }
    sort(vv.begin(),vv.end(),cmp);
    printf("%.3f",vv[m-1]*1.0/(k-2));
    for (int i = m-2; i >= 0; i--)
    {
        printf(" %.3f",vv[i]*1.0/(k-2));
    }
    return 0;
}
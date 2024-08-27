#include<bits\stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n,k;
    vector<int>v0;
    for (int i = 0; i < n; i++)
    {
        int a;cin>>a;
        v0.push_back(a);
    }
    sort(v0.begin(),v0.end());
    for (int i = 0; i < k; i++)
    {
        int k;cin>>k;vector<int>v;
        for (int j = 0; j < k; j++)
        {
            int a;cin>>a;
            v.push_back(a*4);
        }
        sort(v.begin(),v.end());
        for (int j = 0; j < k; j++)
        {
            
        }
        
    }
    

    return 0;
}
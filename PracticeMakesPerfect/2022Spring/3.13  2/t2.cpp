#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int t;
    
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        vector<int>v;
        int n,s=0;
        cin>>n;
        for (int j = 0; j < n; j++)
        {
            int a;
            cin>>a;
            v.push_back(a);
        }

        
        vector<int>::iterator it1=v.begin();
        vector<int>::iterator it2=v.begin()+1;
        for (; it1!=v.end(); it1++)
        {
            it2=it1+1;
            for (; it2!=v.end(); it2++)
            {
                if(*it1%*it2==0){
                    s++;
                }
            }
        }
        cout<<s<<endl;
    }
    
    return 0;
}
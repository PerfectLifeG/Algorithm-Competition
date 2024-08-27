#include<bits\stdc++.h>
using namespace std;
int main()
{
    vector<int>v1(5);
    vector<int>v2(6);
    v2[6]=9;
    v1[0]=v2[6];
    vector<int>::iterator it=v1.begin();
    v1.insert(it,4);

    for ( it = v1.begin(); it != v1.end(); it++)
    {
        cout<< *it <<" ";
    }
    
    return 0;
}
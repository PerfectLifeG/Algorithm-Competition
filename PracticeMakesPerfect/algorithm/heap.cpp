#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v;
    int a[5];a[0]=46;a[1]=23;a[2]=26;a[3]=24;a[4]=10;
    v.push_back(46);
    v.push_back(24);
    v.push_back(23);
    v.push_back(26);
    v.push_back(10);
    make_heap(v.begin(),v.end(),less<int>());
    make_heap(a,a+5,less<int>());
    v.push_back(1);
    push_heap(v.begin(),v.end(),less<int>());
    pop_heap(v.begin(),v.end(),less<int>());
    v.erase(v.end()-1);
    if(is_heap(v.begin(),v.end(),less<int>())){
        cout<<6;
    }
    sort_heap(v.begin(),v.end(),less<int>());
    sort_heap(a,a+5,less<int>());
    return 0;
}
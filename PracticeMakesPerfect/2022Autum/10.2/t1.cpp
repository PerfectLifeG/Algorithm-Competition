#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        double M,m,v;
        cin>>M>>m>>v;
        double ret= m*v/(M-m);
        printf("%.2lf\n",ret);
    }
    return 0;
}
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
    char a[10000];int i=0;
    map<char,int> m;
    static int x,y,z,xx,yy,zz;
    while((a[i]=getchar())!='\n'){
        if(a[i]=='(') x++;
        if(a[i]=='[') y++;
        if(a[i]=='{') z++;
        if(a[i]==')') xx++;
        if(a[i]==']') yy++;
        if(a[i]=='}') zz++;
    }
    cout<<x+y+z<<" "<<xx+yy+zz<<endl;
    if(x==0&&y==0&&z==0&&xx==0&&yy==0&&zz==0)cout<<"NO";
    else if(x==xx&&y==yy&&z==zz)cout<<"YES";
    else cout<<"NO";
    return 0;
}
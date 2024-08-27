#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
    char c,cc;
    while((c=getchar())!='\n'){
        if(c=='1')a[1]++;
        else if(c=='2')a[2]++;
        else if(c=='3')a[3]++;
        else if(c=='4')a[4]++;
        else if(c=='5')a[5]++;
        else if(c=='6')a[6]++;
        else if(c=='7')a[7]++;
        else if(c=='8')a[8]++;
        else if(c=='9')a[9]++;
        else if(c=='0')a[0]++;
    }


    int b[10];
    while (1)
    {
        while((c=getchar())!='\n'){
                if(c=='1')b[1]++;
                else if(c=='2')b[2]++;
                else if(c=='3')b[3]++;
                else if(c=='4')b[4]++;
                else if(c=='5')b[5]++;
                else if(c=='6')b[6]++;
                else if(c=='7')b[7]++;
                else if(c=='8')b[8]++;
                else if(c=='9')b[9]++;
                else if(c=='0')b[0]++;
                cc=c;
            }
            for (int i = 0; i < 10; i++)
            {
                if(a[i]!=b[i])cout<<"NO"<<endl;
            }
            cout<<"YES"<<endl;
            if(c=='\n'&&cc=='0')break;
    }
    

    return 0;
}
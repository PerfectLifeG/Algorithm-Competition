#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    string a;
    while (cin>>a)
    {   int  mon=(a[10]-'0')*10+(a[11]-'0');int  day=(a[12]-'0')*10+(a[13]-'0');int  y=(a[6]-'0')*1000+(a[7]-'0')*100+(a[8]-'0')*10+(a[9]-'0');
        if((mon==1&&day>=1&&day<=31)||(mon==2&&day>=1&&day<=28)||(mon==3&&day>=1&&day<=31)||(mon==4&&day>=1&&day<=30)||(mon==5&&day>=1&&day<=31)||(mon==6&&day>=1&&day<=30)||(mon==7&&day>=1&&day<=31)||(mon==8&&day>=1&&day<=31)||(mon==9&&day>=1&&day<=30)||(mon==10&&day>=1&&day<=31)||(mon==11&&day>=1&&day<=30)||(mon==12&&day>=1&&day<=31))
        {int b=((a[0]-'0')*7+(a[1]-'0')*9+(a[2]-'0')*10+(a[3]-'0')*5+(a[4]-'0')*8+(a[5]-'0')*4+(a[5]-'0')*4+(a[5]-'0')*4+(a[5]-'0')+(a[5]-'0')+(a[6]-'0')*2+(a[7]-'0')*1+(a[8]-'0')*6+(a[9]-'0')*3+(a[10]-'0')*7+(a[11]-'0')*9+(a[12]-'0')*10+(a[13]-'0')*5+(a[14]-'0')*8+(a[15]-'0')*4+(a[16]-'0')*2)%11;
        switch (b)
        {
        case 0:if(a[16]=='1'){cout<<a<<":"<<" "<<a[6]<<a[7]<<a[8]<<a[9]<<"-"<<a[10]<<a[11]<<"-"<<a[12]<<a[13]<<" ";if((a[15]-'0')%2==0)cout<<"F"<<endl;else cout<<"M"<<endl;break;}
        case 1:if(a[16]=='0'){cout<<a<<":"<<" "<<a[6]<<a[7]<<a[8]<<a[9]<<"-"<<a[10]<<a[11]<<"-"<<a[12]<<a[13]<<" ";if((a[15]-'0')%2==0)cout<<"F"<<endl;else cout<<"M"<<endl;break;}
        case 2:if(a[16]=='x'){cout<<a<<":"<<" "<<a[6]<<a[7]<<a[8]<<a[9]<<"-"<<a[10]<<a[11]<<"-"<<a[12]<<a[13]<<" ";if((a[15]-'0')%2==0)cout<<"F"<<endl;else cout<<"M"<<endl;break;}
        case 3:if(a[16]=='9'){cout<<a<<":"<<" "<<a[6]<<a[7]<<a[8]<<a[9]<<"-"<<a[10]<<a[11]<<"-"<<a[12]<<a[13]<<" ";if((a[15]-'0')%2==0)cout<<"F"<<endl;else cout<<"M"<<endl;break;}
        case 4:if(a[16]=='8'){cout<<a<<":"<<" "<<a[6]<<a[7]<<a[8]<<a[9]<<"-"<<a[10]<<a[11]<<"-"<<a[12]<<a[13]<<" ";if((a[15]-'0')%2==0)cout<<"F"<<endl;else cout<<"M"<<endl;break;}
        case 5:if(a[16]=='7'){cout<<a<<":"<<" "<<a[6]<<a[7]<<a[8]<<a[9]<<"-"<<a[10]<<a[11]<<"-"<<a[12]<<a[13]<<" ";if((a[15]-'0')%2==0)cout<<"F"<<endl;else cout<<"M"<<endl;break;}
        case 6:if(a[16]=='6'){cout<<a<<":"<<" "<<a[6]<<a[7]<<a[8]<<a[9]<<"-"<<a[10]<<a[11]<<"-"<<a[12]<<a[13]<<" ";if((a[15]-'0')%2==0)cout<<"F"<<endl;else cout<<"M"<<endl;break;}
        case 7:if(a[16]=='5'){cout<<a<<":"<<" "<<a[6]<<a[7]<<a[8]<<a[9]<<"-"<<a[10]<<a[11]<<"-"<<a[12]<<a[13]<<" ";if((a[15]-'0')%2==0)cout<<"F"<<endl;else cout<<"M"<<endl;break;}
        case 8:if(a[16]=='4'){cout<<a<<":"<<" "<<a[6]<<a[7]<<a[8]<<a[9]<<"-"<<a[10]<<a[11]<<"-"<<a[12]<<a[13]<<" ";if((a[15]-'0')%2==0)cout<<"F"<<endl;else cout<<"M"<<endl;break;}
        case 9:if(a[16]=='3'){cout<<a<<":"<<" "<<a[6]<<a[7]<<a[8]<<a[9]<<"-"<<a[10]<<a[11]<<"-"<<a[12]<<a[13]<<" ";if((a[15]-'0')%2==0)cout<<"F"<<endl;else cout<<"M"<<endl;break;}
       case 10:if(a[16]=='2'){cout<<a<<":"<<" "<<a[6]<<a[7]<<a[8]<<a[9]<<"-"<<a[10]<<a[11]<<"-"<<a[12]<<a[13]<<" ";if((a[15]-'0')%2==0)cout<<"F"<<endl;else cout<<"M"<<endl;break;}
        default :cout<<a<<":"<<" "<<"invalid";
        }
     }
     else  cout<<a<<":"<<" "<<"invalid";
    }
    
    return 0;
}
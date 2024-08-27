#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int isp(int t);
int main()
{
    int l,k;
    char num[2000];
    scanf("%d %d",&l,&k);
    getchar();
    int i,j;
    char num1[k+1];
    gets(num);
	long long t;
	for(i=0;i+k-1<l;i++)
	{
		int t1=i,t2=0;
		j=i+k-1;
		for(t1;t1<=j;t1++)
		{
		num1[t2]=num[t1];
		t2++;	
		}
		num1[t2]='\0';
		t=atoi(num1);
		if(isp(t)==1)
		{
			printf("%s",num1);
			break;
		 } 
	}
	if(i+k-1==l) printf("404");
	return 0;
}
int isp(int t)
{
    int i;
    if(t==1) return 0;
	for(i=2;i<=sqrt(t);i++)
	{
		if(t%i==0) return 0;
		}	
		return 1;
}

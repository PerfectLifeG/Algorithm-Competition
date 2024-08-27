#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int parent[10000],n[10000],sq[10000],setn[10000],exist[10000];//
struct inf{
	int num;
	double pn;
	double ps;
};
bool cmp(struct inf a,struct inf b)
{
	if(a.ps!=b.ps)//如果人均房产数不相等，则大的排前面，否则按照代表元的字典序。
		return a.ps>b.ps;
	else
		return a.num<b.num;
}
int find(int x)
{
	int root=x;
	while(parent[root]!=root)
		root=parent[root];
	while(parent[x]!=root){
		int t=parent[x];
		parent[x]=root;
		x=t;
	}
	return root;
}
void unio(int a,int b)
{
	int ra=find(a);
	int rb=find(b);
	if(ra!=rb)
		if(ra<rb)//这里需要注意，序号小的作为代表元。我一开始好像在这边把序号大的信息累加到代表元上，后来才知道，有的元素可能会漏掉。毕竟有的人和代表元合并的时候可能还未输入他的房产信息。
			parent[rb]=ra;
		else
			parent[ra]=rb;
}
int main()
{
	//freopen("L2-007. 家庭房产.txt","r",stdin);
	int m,num=0,k=0;
	for(int i=0;i<10000;i++)
		parent[i]=i;
	cin>>m;
	for(int i=0;i<m;i++){
		int p,f,m,num,hn,s;
		cin>>p>>f>>m>>num;
		int cur[num];//先把孩子信息存下来，然后再合并，这样该人的房产信息才能放到代表元身上。
		for(int i=0;i<num;i++)
			cin>>cur[i];
		cin>>hn>>s;
		n[p]=hn;//房产数量
		sq[p]=s; //面积
		exist[p]=1;
		if(f!=-1){//不是-1才要合并
			unio(p,f);
			exist[f]=1;//标记该人存在	
		}
		if(m!=-1){
			unio(p,m);
			exist[m]=1;
		}
		for(int i=0;i<num;i++){
			unio(cur[i],p);
			exist[cur[i]]=1;
		}
	}
	for(int i=0;i<10000;i++)
		if(exist[i]){//对存在的人找他们的祖先，在对应序号的索引处值+1
			setn[find(i)]++;
			if(find(i)!=i){//对房产信息统计，除代表元以外的信息全部汇总
				n[find(i)]+=n[i];
				sq[find(i)]+=sq[i];		
			}
		}
	for(int i=0;i<10000;i++){
		if(setn[i])
			num++;//统计家庭数量
	}
	printf("%d\n",num);
	inf list[num];
	for(int i=0;i<10000;i++)
		if(setn[i])
			list[k++]={i,n[i]*1.0/setn[i],sq[i]*1.0/setn[i]};			
	sort(list,list+num,cmp);
	for(int i=0;i<num;i++)
		printf("%04d %d %.3lf %.3lf\n",list[i].num,setn[list[i].num],list[i].pn,list[i].ps);
	return 0;
}
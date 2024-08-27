#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define INF 999999999.9
#define PI acos(-1.0)
struct Point
{
	double x, y, dis;
}pt[1005], stack[1005], p0;
int top, tot;
//计算几何距离
double Dis(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
//极角比较， 返回-1: p0p1 在 p0p2 的右侧，返回 0:p0,p1,p2 共线
int Cmp_PolarAngel(struct Point p1, struct Point p2, struct Point pb)
{
	double delta=(p1.x-pb.x)*(p2.y-pb.y)-(p2.x-pb.x)*(p1.y-pb.y);
	if (delta<0.0) return 1;
	else if (delta==0.0) return 0;
	else return -1;
}
// 判断向量 p2p3 是否对 p1p2 构成左旋
bool Is_LeftTurn(struct Point p3, struct Point p2, struct Point p1)
{
	int type=Cmp_PolarAngel(p3, p1, p2);
	if (type<0) return true;
	return false;
}
//先按极角排，再按距离由小到大排
int Cmp(const void*p1, const void*p2)
{
	struct Point*a1=(struct Point*)p1;
	struct Point*a2=(struct Point*)p2;
	int type=Cmp_PolarAngel(*a1, *a2, p0);
	if (type<0) return -1;
	else if (type==0)
	{
		if (a1->dis<a2->dis) return -1;
		43
		else if (a1->dis==a2->dis) return 0;
		else return 1;
	}
	else return 1;
}
//求凸包
void Solve(int n)
{
	int i, k;
	p0.x=p0.y=INF;
	for (i=0;i<n;i++)
	{
		scanf("%lf %lf",&pt[i].x, &pt[i].y);
		if (pt[i].y < p0.y)
		{
			p0.y=pt[i].y;
			p0.x=pt[i].x;
			k=i;
		}
		else if (pt[i].y==p0.y)
		{
			if (pt[i].x<p0.x)
			{
				p0.x=pt[i].x;
				k=i;
			}
		}
	}
	pt[k]=pt[0];
	pt[0]=p0;
	for (i=1;i<n;i++)
		pt[i].dis=Dis(pt[i].x,pt[i].y, p0.x,p0.y);
	qsort(pt+1, n-1, sizeof(struct Point), Cmp);
//去掉极角相同的点
	tot=1;
	for (i=2;i<n;i++)
		if (Cmp_PolarAngel(pt[i], pt[i-1], p0))
			pt[tot++]=pt[i-1];
		pt[tot++]=pt[n-1];
//求凸包
		top=1;
		stack[0]=pt[0];
		stack[1]=pt[1];
		for (i=2;i<tot;i++)
			44
		{
			while (top>=1 && Is_LeftTurn(pt[i], stack[top], stack[top-1])==false)
				top--;
			stack[++top]=pt[i];
		}
	}
	int main (void)
	{
		int n;
		while (scanf("%d",&n)==2)
		{
			Solve(n);
		}
		return 0;
	}
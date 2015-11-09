#include <bits/stdc++.h>
using namespace std;
typedef long long num;
typedef int point;
const int MP = 2e5+7;
num x[MP], y[MP];
point lf, rt, p[MP];
int n, foi;

bool lexLess(int i, int j)
{ return (x[i] == x[j]) ? y[i] < y[j] : x[i] < x[j]; }
inline num cross(point i, point j,point k)
{ return (x[i]-x[j])*(y[k]-y[j]) - (y[i]-y[j])*(x[k]-x[j]); }

int main()
{
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
		scanf(" %lld%lld", x+i, y+i), p[i] = i;
	if(n==2)
	{
		printf("%d\n%d %d\n",1,1,2);
		return 0;
	}
	lf = *min_element(p,p+n,lexLess);
	rt = *max_element(p,p+n,lexLess);
	foi = 1;
	for(int i=0;i<n;i++)
		foi &= (cross(lf,rt,p[i]) == 0);
	if(foi)
		printf("%d\n%d %d\n",1,lf+1,rt+1);
	else
		printf("%d\n", 0);
}

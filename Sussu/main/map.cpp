#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;

int n, d, res[MAXN], indi[MAXN], indj[MAXN], degi, degj;

struct point{
	int i, j;
} p[MAXN];

bool cmp(point a,point b){
	if(a.j==b.j)
		return a.i<b.i;
	return a.j<b.j;
}

int main (){
	scanf("%d%d", &n, &d);
	for(int a=0;a<n;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		p[a].i=i;
		p[a].j=j;
	}
	sort(p,p+n,cmp);
	int men = 1000000010, mai = -1;
	int aa=0;
	for(int a=0;a<n;a++){
	    if(men<p[a].i && mai>p[a].i)
            res[a]++;
        if(a!=n-1 && p[a].j!=p[a+1].j){
            while(aa<=a){
                men=min(men,p[aa].i);
                mai=max(mai,p[aa].i);
                aa++;
            }
        }
	}
	men = 1000000010, mai = -1;
	aa=n-1;
	for(int a=n-1;a>=0;a--){
	    if(men<p[a].i && mai>p[a].i)
            res[a]++;
        if(a!=0 && p[a].j!=p[a-1].j){
            while(aa>=a){
                men=min(men,p[aa].i);
                mai=max(mai,p[aa].i);
                aa--;
            }
        }
	}
	int resul=0;
	for(int a=0;a<n;a++)
		if(res[a]==2)
			resul++;
	printf("%d\n", resul);
	return 0;
}

/*

6 5
0 0
1 4
2 2
3 2
4 4
5 1

6 1000000000
1 1
1 2
0 1
3 2
2 2
1 3

4 100000000
1 1
5 5
2 4
3 2

5 100000000
1 1
5 5
2 4
3 2
10 1

5 1000000000
0 0
1000000000 1000000000
1000000000 0
0 1000000000
1 1

*/

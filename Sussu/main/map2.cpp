#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;

int n, d, indi[MAXN], indj[MAXN], degi, degj;
long long ans;

struct resul{
    long long i, f, x;
} res[MAXN];

struct point{
	long long i, j;
} p[MAXN];

bool cmp(point a,point b){
	if(a.j==b.j)
		return a.i<b.i;
	return a.j<b.j;
}

int main (){
    ans=0;
	scanf("%d%d", &n, &d);
	for(int a=0;a<n;a++){
		long long int i, j;
		scanf("%lld%lld", &i, &j);
		p[a].i=i;
		p[a].j=j;
	}
	sort(p,p+n,cmp);
	long long men = 1000000010, mai = -1;
	int aa=0;
	for(int a=0;a<n;a++){
        res[a].x=p[a].j;
        res[a].i=men;
        res[a].f=mai;
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
        if(a!=0 && p[a].j!=p[a-1].j){
            printf("%d bota %d\n", p[a].j, max(0LL,mai-men));
            ans+=max(0LL,mai-men);
            while(aa>=a){
                men=min(men,p[aa].i);
                mai=max(mai,p[aa].i);
                aa--;
            }
        }
        printf("%lld %lld - %lld e %lld - %lld por %lld %lld SOMA %lld\n", p[a].j, res[a].i, res[a].f, men, mai, res[a].x, res[a-1].x, max(0LL,(min(res[a].f,mai)-max(res[a].i,men)-1)*(res[a].x-res[a-1].x-1)));
        if(men<mai && res[a].i<res[a].f)
            ans+=max(0LL,(min(res[a].f,mai)-max(res[a].i,men)-1)*(res[a].x-res[a-1].x-1));
	}
	int resul=0;
	printf("%lld\n", ans);
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

6 5
0 0
1 4
2 2
3 2
5 4
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

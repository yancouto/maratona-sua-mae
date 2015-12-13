#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 100010, MAXC = 100010, INF = 0x3f3f3f3f;


int n, m, degmax, degmin;

struct ares{
	int p, t, i;
} ar[MAXN], armin[MAXN], armax[MAXN];

struct result{
	int i, j;
} res[MAXN];


void botamax(int p, int t, int i){
	armax[degmax].p = p;
	armax[degmax].t = t;
	armax[degmax].i = i;
	degmax++;
}

void botamin(int p, int t, int i){
	armin[degmin].p = p;
	armin[degmin].t = t;
	armin[degmin].i = i;
	degmin++;
}


bool cmp(ares a, ares b){
	return a.p < b.p;
}

bool cmp2(ares a, ares b){
	return a.p > b.p;
}

inline int bb(int i,int j,int v,int vmax){
	while(i<j){
		int m = (i+j)/2;
		if(armin[m].p + v >= vmax)
			j = m;
		else
			i = m+1;
	}
	return i;
}

int main (){
	scanf("%d %d ", &n, &m);
	for(int a=0;a<m;a++){
		scanf("%d%d", &ar[a].p, &ar[a].t);
		if(ar[a].t == 0)
			botamax(ar[a].p, ar[a].t,a);
		else
			botamin(ar[a].p, ar[a].t, a);
	}
	sort(armin,armin+degmin,cmp);
	sort(armax,armax+degmax,cmp);

	for(int a=0;a<degmin;a++){
		res[armin[a].i].i = a+1;
		res[armin[a].i].j = n;
 	}
 	int imin = 0, jmin = 1;
	for(int a=0;a<degmax;a++){
		//int i = bb(pmin,degmin-1,armax[a].p, armin[pmin].p);
		while(imin < degmin-1 && (armax[a].p < armin[imin].p || armax[a].p < armin[jmin].p)){
			imin++;
			if(imin == jmin && jmin!=degmin-1){
				imin = 0;
				jmin++;
			}
		}
		if(imin >= degmin-1){
			puts("-1");
			return 0;
		}
		res[armax[a].i].i = imin +1;
		res[armax[a].i].j = jmin +1;
		imin++;
		if(imin == jmin && jmin!=degmin-1){
			imin = 0;
			jmin++;
		}
	}
	for(int a=0;a<m;a++){
		printf("%d %d\n", res[a].i, res[a].j);
	}
	return 0;
}	
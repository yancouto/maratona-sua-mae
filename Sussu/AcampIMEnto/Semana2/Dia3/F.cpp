
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

const int MAXN = 110;

int n, e, d;

struct cus {
	int i, v;
	cus(int ii, int vv){
		i = ii;
		v = vv;

	}
	cus(){}
}cd[MAXN], ce[MAXN];

bool cmp(cus a, cus b){
	return a.v < b.v;
}

int main (){
	scanf("%d%d%d", &n, &d, &e);
	for(int a=0;a<n;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		cd[a] = cus(a, i);
		ce[a] = cus(a, j);
	}
	sort(cd, cd+n, cmp);
	sort(ce, ce+n, cmp);
	double res;
	if(n == 1){
		res = max((double)d/cd[0].v, (double)e/ce[0].v);
	}
	else{
		if(cd[0].i == ce[0].i)
			res = max((double)d/cd[0].v + (double)e/ce[1].v, (double)d/cd[1].v + (double)e/ce[0].v);
		else{
			res = (double)d/cd[0].v + (double)e/ce[0].v;
		}
	}
	printf("%.2f\n", res);
}

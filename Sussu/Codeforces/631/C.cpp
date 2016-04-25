
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

const int MAXN = 212345;

int n, m, s[MAXN], res[MAXN], ord[MAXN];

struct man{
	int i, t, r;
} q[MAXN];

bool cmp(man a, man b){
	return (a.r > b.r || (a.r == b.r && a.i > b.i));
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
		ord[a] = s[a];
		res[a] = s[a];
	}
	for(int a=0;a<m;a++){
		scanf("%d%d", &q[a].t, &q[a].r);
		q[a].i = a;
	}
	sort(q, q+m, cmp);
	int ult = -1, ultr, ultt, degr;
	int ini=1, fim = n;
	for(int a=0;a<m;a++){
		if(ult >= q[a].i) continue;
		if(ult == -1){
			sort(ord+1, ord+q[a].r+1);
			fim = q[a].r;
			ult = q[a].i;
			ultr = q[a].r;
			ultt = q[a].t;
			degr = q[a].r;
			continue;
		}
		if(ultt == 2){
			for(int i=0;degr > q[a].r;i++){
				res[degr--] = ord[ini++];
			//	printf("res recebe %d do ini", ord[ini-1]);
			}
		}
		else{
			for(int i=0;degr > q[a].r;i++){
				res[degr--] = ord[fim--];
			//	printf("res recebe %d do fim", ord[fim+1]);
			}
		}
		ult = q[a].i;
		ultr = q[a].r;
		ultt = q[a].t;
	}
	if(ultt == 2){
		for(int i=0;degr > 0;i++){
			res[degr--] = ord[ini++];
			//printf("res recebe %d do ini", ord[ini-1]);
			
		}
	}
	else if(ultt == 1){
		for(int i=0;degr > 0;i++){
			res[degr--] = ord[fim--];
			//printf("res recebe %d do fim", ord[fim+1]);
		}
	}
	for(int a=1;a<=n;a++){
		printf("%d ", res[a]);
	}
}

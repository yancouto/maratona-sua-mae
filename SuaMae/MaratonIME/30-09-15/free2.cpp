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
const int oo = 100000000;

int n, N, need;
char s[10];
pii memo[1005][1005];
pii p[1003];

pii solve(int i, int qtd) {
	if(i >= N || qtd < 0) return (qtd)?pii(-oo, -oo):pii(0, 0);
	pii &m = memo[i][qtd];
	if(m.fst != -1) return m;
	int jan = need - qtd;
	int petra = i - jan;
	m = pii(-oo, -oo);
	int pet = (N - i - qtd) > 0;
	int bo;
	if(s[0] == 'P') bo = petra == (jan + 1);
	else bo = jan == petra;
	pii a(solve(i + 1 + bo, qtd-1));
	a.fst += p[i].snd;
	if(bo) a.snd += -p[i + 1].fst;
	m = max(m, a);
	if(pet) {
		a = solve(i + 1, qtd);
		a.snd += -p[i].fst;
		m = max(m, a);
	}
	return m;
}

int main() {
	for_tests(t, tt) {
		scanf("%d %s", &n, s);
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &p[i].fst, &p[i].snd);
			p[i].fst *= -1;
		}
		N = n;
		p[n] = pii(0, 0);
		sort(p, p + n);
		int ini = 0;
		int P = 0;
		if(!strcmp(s, "Petra")) { n--; P += -p[0].fst; ini++; }
		memset(memo, -1, sizeof memo);
		need = (n + 1) / 2;
		printf("%d %d\n", P + solve(ini, (n + 1) / 2).snd, solve(ini, (n+1)/2).fst);
	}
	return 0;
}

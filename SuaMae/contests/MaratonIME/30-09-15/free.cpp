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

pii p[1009];
int N;
pii memo[1003][1003];
pii solve(int i, int left) {
	if(i >= N) return left? pii(-100000000, -100000000) : pii(0, 0);
	pii &r = memo[i][left];
	if(r.fst != -1) return r;
	r = pii(-1000000000, -1000000000);
	int pet = N - i - left;
	if(pet < 0) return r;
	pet = pet > 0;
	if(left > 0) {
		pii a = solve(i + 1 + pet, left - 1);
		a.fst += p[i].snd;
		if(pet) a.snd += -p[i+1].fst;
		r = max(r, a);
	}
	if(pet) {
		pii a = solve(i + 1, left);
		a.snd += -p[i].fst;
		r = max(r, a);
	}
	return r;
}

int main() {
	int i, n;
	for_tests(tn, tt) {
		char c;
		scanf("%d %c%*s", &n, &c);
		for(i = 0; i < n; i++) {
			scanf("%d %d", &p[i].fst, &p[i].snd);
			p[i].fst = -p[i].fst;
		}
		p[n] = pii(0, 0);
		sort(p, p + n);
		int P = 0;
		i = 0;
		N = n;
		if(c == 'P') P += -p[i++].fst, n--;
		memset(memo, -1, sizeof memo);
		printf("%d %d\n", P + solve(i, ((n + 1) / 2)).snd, solve(i, ((n + 1) / 2)).fst);
	}
}

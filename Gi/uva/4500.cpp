#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
const int MAX = 5005;

char a[MAX], b[MAX];
int infa[26][2], infb[26][2];
int na, nb;

void prec(int inf[26][2], char s[MAX], int n) {
	for(int i = 1; i < n; i++) {
		if(inf[s[i] - 'A'][0] != n) continue;
		inf[s[i] - 'A'][0] = i;
	}
	for(int i = n - 1; i > 0; i--) {
		if(inf[s[i] - 'A'][1]) continue;
		inf[s[i] - 'A'][1] = i;
	}
}

int memo[MAX][MAX];
int solve(int ia, int ib) {
	if(ia == na && ib == nb) return 0;
	int &m = memo[ia][ib];
	if(m != -1) return m;
	int cora = (ia < na) ? (a[ia] - 'A') : 0;
	int corb = (ib < nb) ? (b[ib] - 'A') : 0;
	int suma = 0, sumb = 0;
	if(ia < na) {
		if(ia == infa[cora][0] && infb[cora][0] >= ib) suma -= (ia + ib - 1);
		if(ia == infa[cora][1] && infb[cora][1] < ib) suma += (ia + ib - 1);
	}
	if(ib < nb) {
		if(ib == infb[corb][0] && infa[corb][0] >= ia) sumb -= (ia - 1 + ib);
		if(ib == infb[corb][1] && infa[corb][1] < ia) sumb += (ia - 1 + ib);
	}
	m = 1000000000;
	if(ia < na) m = suma + solve(ia + 1, ib);
	if(ib < nb) m = min(m, sumb + solve(ia, ib + 1));
	return m;
}

int main() {
	int k; scanf("%d", &k);
	while(k--) {
		scanf("%s %s", a + 1, b + 1);
		na = strlen(a + 1); na++;
		nb = strlen(b + 1); nb++;
		for(int i = 0; i < 26; i++) {
			infa[i][0] = na;
			infb[i][0] = nb;
			infa[i][1] = 0;
			infb[i][1] = 0;
		}
		prec(infa, a, na);
		prec(infb, b, nb);
		for(int i = 1; i <= na; i++)
			for(int j = 1; j <= nb; j++)
				memo[i][j] = -1;
		printf("%d\n", solve(1, 1));
	}
	return 0;
}

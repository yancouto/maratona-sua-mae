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

char a[5005], b[5005];
int acca[26][5005], accb[26][5005];
int na, nb;

void prec(int acc[26][5005], int sz, char s[5005]) {
	for(int c = 'A'; c <= 'Z'; c++) 
		for(int i = 1; i < sz; i++) 
			acc[c - 'A'][i] = (s[i] == c) + acc[c - 'A'][i-1];
}

int memo[5005][5005];
int solve(int ia, int ib) {
	if(ia == na && ib == nb) return 0;
	int &mm = memo[ia][ib];
	if(mm != -1) return mm;
	int cora = (ia < na) ? (a[ia] - 'A') : 0;
	int corb = (ib < nb) ? (b[ib] - 'A') : 0;
	int suma = 0, sumb = 0;
	if(ia < na) {
		if(acca[cora][ia] == 1 && !acca[cora][ia - 1] && !accb[cora][ib - 1]) 
			{ suma -= (ia + ib - 1);}
		if(acca[cora][ia] == acca[cora][na - 1] && accb[cora][ib - 1] == accb[cora][nb - 1])
			{ suma += (ia + ib - 1);}
	}
	if(ib < nb) {
		if(accb[corb][ib] == 1 && !accb[corb][ib - 1] && !acca[corb][ia - 1])
			sumb -= (ia + ib - 1);
		if(accb[corb][ib] == accb[corb][nb - 1] && acca[corb][ia - 1] == acca[corb][na - 1])
			sumb += (ia + ib - 1);
	}
	mm = 1000000000;
	if(ia < na) mm = suma + solve(ia + 1, ib);
	if(ib < nb) mm = min(mm, sumb + solve(ia, ib + 1));
	return mm;
}

int main() {	
	int tt; scanf("%d", &tt);
	while(tt--) {
		scanf("%s %s", a + 1, b + 1);
		na = strlen(a + 1); nb = strlen(b + 1);
		na++; nb++;
		prec(acca, na, a);
		prec(accb, nb, b);
		for(int i = 1; i <= na; i++)
			for(int j = 1; j <= nb; j++)
				memo[i][j] = -1;
		printf("%d\n", solve(1, 1));
	}
	return 0;
}

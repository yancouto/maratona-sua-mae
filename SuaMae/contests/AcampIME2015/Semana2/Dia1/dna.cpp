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
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
int k;
char s1[1009], s2[1009];
int maxmatch[1003][1003];
inline int& mm(int i, int j) {
	return maxmatch[i][j];
}

int memo[1003][1003];
int lcs(int i, int j) {
	if(!s1[i] || !s2[j]) return 0;
	int &m = memo[i][j];
	if(m != -1)
		return m;
	m = max(lcs(i + 1, j), lcs(i, j + 1));
	for(int aux = k; aux <= mm(i, j); aux++)
		m = max(m, lcs(i + aux, j + aux) + aux);
	return m;
}


int main() {
	int i, j, l;
	while(true) {
		scanf("%d", &k);
		if(!k) return 0;
		scanf(" %s %s", s1, s2);
		for(i = 0; s1[i]; i++)
			for(j = 0; s2[j]; j++) {
				mm(i, j) = 0;
				memo[i][j] = -1;
			}
		for(i = 0; s1[i]; i++)
			for(j = 0; s2[j]; j++) {
				if(mm(i, j)) continue;
				for(l = 0; s1[i + l] && s2[j + l] && s1[i + l] == s2[j + l]; l++);
				for(int aux = 1; aux <= l; aux++) mm(i + l - aux, j + l - aux) = aux;
			}
		printf("%d\n", lcs(0, 0));
	}
}
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
const int MAX = 300009;
int n;
ull xo[MAX];
char str[MAX];
int val(char c) {
	if(c >= 'a' && c <= 'z') return c - 'a';
	else return c - 'A' + ('z' - 'a' + 1);
}

int main() {
	int i;
	scanf("%d %s", &n);
	for(i = 1; i <= n; i++)
		xo[i] = xo[i - 1] ^ (1ull << val(str[i - 1]));
	sort(xo + 1, xo + n + 1);
}
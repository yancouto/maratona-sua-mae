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
const int N = 1005;

int n, k, val;
char a[N], b[N];
ll A, B;
ll memog[100005], memob[100005];

ll solve_bad(int x);
ll solve_good(int x) {
	if(x == 0) return val;
	ll &m = memog[x];
	if(m != -1) return m;
	m = mod(mod(solve_good(x-1) * (A - 1)) + mod(solve_bad(x-1) * A));
	return m;
}

ll solve_bad(int x) {
	if(x == 0) return !val;
	ll &m = memob[x];
	if(m != -1) return m;
	m = mod(mod(solve_bad(x-1) * (B - 1)) + mod(solve_good(x-1) * B));
	return m;
}

int main() {
	int i, j;
	scanf("%s %s", a, b);
	n = strlen(a);
	scanf("%d", &k);
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) 
			if(a[(j+i+1)%n] != b[j]) { B++; break; }
		if(j == n) A++;
	}
	val = !strcmp(a, b);
	memset(memog, -1, sizeof memog);
	memset(memob, -1, sizeof memob);
	cout << solve_good(k) << '\n';
	return 0;
}

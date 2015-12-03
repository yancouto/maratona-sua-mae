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
const int N = 100005;

int n, m, k, a, b;
int l[N], r[N], d[N];
ll bitop[N], bitv[N];
ll v[N];

void update(ll bit[N], int p, int x) {
	for(int i = p; i < n; i += i&-i)
		bit[i] += x;
}

ll get(ll bit[N], int p) {
	ll ret = 0;
	for(int i = p; i > 0; i -= i&-i)
		ret += bit[i];
	return ret;
}

int main() {
	int i;
	scanf("%d %d %d", &n, &m, &k);
	for(i = 0; i < n; i++) scanf("%lld", &v[i]);
	for(i = 0; i < m; i++) scanf("%d %d %d", &l[i], &r[i], &d[i]);
	for(i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		printf("Inserindo %d e tira %d\n", a, b + 1);
		update(bitop, a, 1);
		printf("get %lld\n", get(bitop, 1));
		update(bitop, b + 1, -1);
	}
	for(i = 0; i < m; i++) {
		printf("operacao %d %d %d\n", l[i], r[i], d[i]);
		printf("get = %lld\n", get(bitop, i + 1));
		ll val = d[i] * get(bitop, i + 1);
		update(bitv, l[i], val);
		update(bitv, r[i] + 1, -val); 
	}
	for(int i = 0; i < n; i++) 
		printf("%lld ", v[i] + get(bitv, i + 1));
	putchar('\n');
	return 0;
}

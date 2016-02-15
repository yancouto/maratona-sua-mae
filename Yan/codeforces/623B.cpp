#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 1000002;
int n; ll A, B;
int a[N];

inline void get(int &x) {
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
}

ll memo[N][3][10];

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}

unordered_map<int, int> mp;
ll solve(int i, int skip, int cur) {
	if(cur == 1) return 100000000000000000ll;;
	if(i == n) return 0ll;
	assert(i < n);
	if(!mp.count(cur)) mp[cur] = mp.size() - 1;
	int v = mp[cur];
	ll &r = memo[i][skip][v];
	if(r) return r - 1;
	r = LLONG_MAX - 1ll;
	if(skip == 0) r = solve(i + 1, 1, cur) + A;
	if(skip == 1) r = min(solve(i, 2, cur), solve(i + 1, 1, cur) + A);
	else {
		r = min(r, solve(i + 1, skip, gcd(cur, a[i])));
		r = min(r, solve(i + 1, skip, gcd(cur, a[i] + 1)) + B);
		r = min(r, solve(i + 1, skip, gcd(cur, a[i] - 1)) + B);
	}
	return (++r) - 1ll;
}
unordered_set<int> el;
unordered_set<int> o;
ll s[N][3][100];
void all(int i, int skip, int cur) {
	if(cur == 1) return;
	if(i == n) { el.insert(cur); return; }
	if(o.count(cur)) {
		if(skip == 0) all(i + 1, 1, cur);
		if(skip == 1) all(i, 2, cur), all(i + 1, 1, cur);
		else {
			all(i + 1, skip, gcd(cur, a[i]));
			all(i + 1, skip, gcd(cur, a[i] + 1));
			all(i + 1, skip, gcd(cur, a[i] - 1));
		}
	} else {
		if(!mp.count(cur)) mp[cur] = mp.size() - 1;
		int v = mp[cur];
		if(s[i][skip][v >> 6] & (1 << (v & 63))) return;
		s[i][skip][v >> 6] |= (1 << (v & 63));
		if(skip == 0) all(i + 1, 1, cur);
		if(skip == 1) all(i, 2, cur), all(i + 1, 1, cur);
		else {
			all(i + 1, skip, gcd(cur, a[i]));
			all(i + 1, skip, gcd(cur, a[i] + 1));
			all(i + 1, skip, gcd(cur, a[i] - 1));
		}
	}
}


unordered_map<int, ll> mp[N];
int main() {
	int i;
	scanf("%d %lld %lld", &n, &A, &B);
	srand(time(NULL));
	//for(i = 0; i < n; i++) get(a[i]);
	for(i = 0; i < n; i++) a[i] = (rand() % 999999999) + 2;
	mp[0][a[0]] = 0;
	mp[0][a[0] + 1] = B;
	mp[0][a[0] - 1] = B;
	mp[0][0] = A;
	for(i = 1; i < n; i++) {
		unordered_map<int, ll> m;
		for(pii p : mp[i - 1])
			mp[i][p.fst] = m[p.fst] = p.snd + A;
		for(pii p : mp[i - 1]) {
			int g = gcd(p.fst, a[i]), gm = gcd(p.fst, a[i] - 1), gp = gcd(p.fst, a[i] + 1);
			if(!mp[i].count(gcd(p.fst, a[i]))) mp[i][gcd(p.fst, a[i])] = LLONG_MAX;
			if(!mp[i].count(gcd(p.fst, a[i] + 1))) mp[i][gcd(p.fst, a[i] + 1)] = LLONG_MAX;
			if(!mp[i].count(gcd(p.fst, a[i] - 1))) mp[i][gcd(p.fst, a[i] - 1)] = LLONG_MAX;
			mp[g] = min(mp[g], p.snd);
			mp[gm] = min(mp[gm], p.snd + B);
			mp[gp] = min(mp[gp], p.snd + B);
		}
	}
	reverse(a, a + n);
	mp2[0][a[0]] = 0;
	mp2[0][a[0] + 1] = B;
	mp2[0][a[0] - 1] = B;
	mp2[0][0] = A;
	ll mn = LLONG_MAX;
	for(i = 1; i < n; i++) {
		for(pii p : mp2[i - 1]) {
			int g = gcd(p.fst, a[i]), gm = gcd(p.fst, a[i] - 1), gp = gcd(p.fst, a[i] + 1);
			if(!mp2[i].count(gcd(p.fst, a[i]))) mp2[gcd(p.fst, a[i])] = LLONG_MAX;
			if(!mp2[i].count(gcd(p.fst, a[i] + 1))) mp2[gcd(p.fst, a[i] + 1)] = LLONG_MAX;
			if(!mp2[i].count(gcd(p.fst, a[i] - 1))) mp2[gcd(p.fst, a[i] - 1)] = LLONG_MAX;
			mp2[g] = min(mp[g], p.snd);
			mp2[gm] = min(mp[gm], p.snd + B);
			mp2[gp] = min(mp[gp], p.snd + B);
		}
		for(pii p : mp2
	}
}

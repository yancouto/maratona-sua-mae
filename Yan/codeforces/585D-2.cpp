// WA
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAX = 27;
int n;
int l[MAX], m[MAX], w[MAX];
map<pii, ll> mp;
map<pii, string> path;
char st[200];
void gen(int i, ll lx, ll mx, ll wx) {
	if(i == n / 2) {
		st[2*i] = 0;
		pii k(lx - mx, lx - wx);
		if(!mp.count(k) || lx > mp[k]) {
			mp[k] = lx;
			path[k] = st;
		}
		return;
	}
	st[2*i] = 'M'; st[2*i + 1] = 'W';
	gen(i + 1, lx, mx + m[i], wx + w[i]);
	st[2*i] = 'L';
	gen(i + 1, lx + l[i], mx, wx + w[i]);
	st[2*i + 1] = 'M';
	gen(i + 1, lx + l[i], mx + m[i], wx);
}

ll best;
char bst[200];

void gen2(int i, ll lx, ll mx, ll wx) {
	if(i == n) {
		pii k(mx - lx, wx - lx);
		if(mp.count(k) && mp[k] > best) {
			best = mp[k];
			string &s = path[k];
			for(int j = 0; j < n/2; j++)
				bst[2*j] = s[2*j], bst[2*j+1] = s[2*j+1];
			for(int j = n/2; j < n; j++)
				bst[2*j] = st[2*j], bst[2*j+1] = st[2*j+1];
		}
		return;
	}
	st[2*i] = 'M'; st[2*i + 1] = 'W';
	gen2(i + 1, lx, mx + m[i], wx + w[i]);
	st[2*i] = 'L';
	gen2(i + 1, lx + l[i], mx, wx + w[i]);
	st[2*i + 1] = 'M';
	gen2(i + 1, lx + l[i], mx + m[i], wx);
}

int main() {
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d %d %d", &l[i], &m[i], &w[i]);
	mp[pii(0, 0)] = 0;
	gen(0, 0, 0, 0);
	best = LLONG_MIN;
	gen2(n/2, 0, 0, 0);
	if(best == LLONG_MIN) puts("Impossible");
	else for(i = 0; i < n; i++) printf("%c%c\n", bst[2*i], bst[2*i+1]);
}

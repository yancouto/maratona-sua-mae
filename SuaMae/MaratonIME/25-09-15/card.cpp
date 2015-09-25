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
int f[256];
struct card {
	char c, s;
	int v;
	void read() {
		scanf(" %c %c", &c, &s);
		v = f[c];
	}
	void prn(char *cs) {
		printf("%c%c%s", c, s, cs);
	}
	bool operator < (card o) const { return v < o.v; }
	bool operator == (card o) const{ return v == o.v; }
} cs[13];

map<int, int> mp;
int a[13], pot[13];
int nu() {
	int x = 0;
	for(int i = 0; i < 13; i++)
		x += pot[i] * a[i];
	return x;
}
int solve() {
	int x = nu();
	if(x == 0) return 0;
	if(mp.count(x)) return mp[x];
	int i, j;
	for(i = 0; a[i] == 0; i++);
	int &r = mp[x];
	r = 1000;
	for(j = 1; j <= a[i] && j <= 4; j++) {
		a[i] -= j;
		r = min(r, 1 + solve());
		a[i] += j;
	}
	for(j = i; j < 13 && a[j]; j++) {
		a[j]--;
		if(j - i + 1 >= 5) r = min(r, 1 + solve());
	}
	for(j--; j >= i; j--)
		a[j]++;
	for(j = i + 1; j < 13; j++) {
		if(a[j] >= 3 && a[i] >= 2) {
			a[j] -= 3; a[i] -= 2;
			r = min(r, 1 + solve());
			a[j] += 3; a[i] += 2;
		}
		if(a[j] >= 2 && a[i] >= 3) {
			a[j] -= 2; a[i] -= 3;
			r = min(r, 1 + solve());
			a[j] += 2; a[i] += 3;
		}
	}
	return r;
}
int b[13], c[13][5];
void prn(int v, char *st) {
	cs[c[v][--b[v]]].prn(st);
}

void build() {
	int x = nu();
	if(x == 0) return;
	int i, j;
	for(i = 0; a[i] == 0; i++);
	int r = mp[x];
	for(j = 1; j <= a[i] && j <= 4; j++) {
		a[i] -= j;
		if(r == 1 + solve()) {
			while(j-- > 1) prn(i, " ");
			prn(i, "\n");
			build();
			return;
		}
		a[i] += j;
	}
	for(j = i; j < 13 && a[j]; j++) {
		a[j]--;
		if(j - i + 1 >= 5 && r == 1 + solve()) {
			while(j > i) prn(j--, " ");
			prn(i, "\n");
			build();
			return;
		}
	}
	for(j--; j >= i; j--)
		a[j]++;
	for(j = i + 1; j < 13; j++) {
		if(a[j] >= 3 && a[i] >= 2) {
			a[j] -= 3; a[i] -= 2;
			if(r == 1 + solve()) {
				prn(j, " "); prn(j, " "); prn(j, " ");
				prn(i, " "); prn(i, "\n");
				build();
				return;
			}
			a[j] += 3; a[i] += 2;
		}
		if(a[j] >= 2 && a[i] >= 3) {
			a[j] -= 2; a[i] -= 3;
			if(r == 1 + solve()) {
				prn(j, " "); prn(j, " ");
				prn(i, " "); prn(i, " "); prn(i, "\n");
				build();
				return;
			}
			a[j] += 2; a[i] += 3;
		}
	}
	assert(false);
}

int main() {
	int i = 0;
	for(char c : "23456789TJQKA")
		f[c] = i++;
	pot[0] = 1;
	for(i = 1; i < 13; i++)
		pot[i] = 5 * pot[i-1];
	for_tests(t, tt) {
		for(i = 0; i < 13; i++)
			cs[i].read();
		memset(a, 0, sizeof a);
		for(i = 0; i < 13; i++) {
			a[cs[i].v]++;
			b[cs[i].v]++;
			c[cs[i].v][a[cs[i].v] - 1] = i;
		}
		mp.clear();
		printf("%d\n", solve());
		build();
	}
}

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

int n, s;
map<int, int> sell, buy;

void add_sell(int p, int q) {
	if(sell.count(p)) sell[p] += q;
	else sell[p] = q;
}

void add_buy(int p, int q) {
	if(buy.count(p)) buy[p] += q;
	else buy[p] = q;
}

int main() {
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; i++) {
		char c; int p, q;
		scanf(" %c %d %d", &c, &p, &q);
		if(c == 'B') add_buy(p, q);
		else add_sell(p, q);
	}
	map<int, int> :: iterator it;
	vector<pii> sl, by;
	int count = 0;
	for(it = sell.begin(), count = 0; it != sell.end() && count < s; ++count, ++it)
		sl.pb(make_pair(it->fst, it->snd));
	for(it = buy.end(), count = 0; it != buy.begin() && count < s; ++count, --it) {
		if(it == buy.end()) continue;
		by.pb(make_pair(it->fst, it->snd));
	}
	if(!buy.empty() && count <= s) by.pb(make_pair(it->fst, it->snd));
	for(int i = sl.size() - 1; i >= 0; i--) printf("S %d %d\n", sl[i].fst, sl[i].snd);
	for(int i = 0; i < by.size(); i++) printf("B %d %d\n", by[i].fst, by[i].snd);

	return 0;
}

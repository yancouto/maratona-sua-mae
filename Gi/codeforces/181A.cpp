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

vector<pii> lin[2], cc[2];

int main() {
	int n, m, i, j;
	char c;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			scanf(" %c", &c);
			if(c == '*') {
				if(lin[0].empty() || lin[0][0].fst == i+1) lin[0].pb(pii(i+1, j+1));
				else lin[1].pb(pii(i+1, j+1));
				if(cc[0].empty() || cc[0][0].snd == j+1) cc[0].pb(pii(i+1, j+1));
				else cc[1].pb(pii(i+1, j+1));
			}
		}
	int l1, c1;
	if(lin[0].size() < 2) l1 = lin[0][0].fst;
	else l1 = lin[1][0].fst;
	if(cc[0].size() < 2) c1 = cc[0][0].snd;
	else c1 = cc[1][0].snd;
	printf("%d %d\n", l1, c1);
	return 0;
}

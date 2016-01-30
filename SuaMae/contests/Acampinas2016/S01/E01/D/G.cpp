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
double sq2 = sqrt(2.);


int best[8];
int x[200009], y[200009];

double val(int bm, int i) {
	double l = 1, r = sq2 - 1.;
	if(bm & 1) swap(l, r);
	if(bm & 2) l = -l;
	if(bm & 4) r = -r;
	return x[i] * l + y[i] * r;
}

double dist(int i, int j) {
	int dx = abs(x[i] - x[j]), dy = abs(y[i] - y[j]);
	return min(dx, dy) * (sq2 - 1) + max(dx, dy);
}

int main() {
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		for(j = 0; j < 8; j++)
			if(val(j, i) > val(j, best[j]))
				best[j] = i;
	}
	double mx = -1/0.; pii ans;
	for(i = 0; i < n; i++)
		for(j = 0; j < 8; j++)
			if(dist(i, best[j]) > mx)
				mx = dist(i, best[j]),
				ans = pii(i, best[j]);
	printf("%d %d\n", ans.fst + 1, ans.snd + 1);
}

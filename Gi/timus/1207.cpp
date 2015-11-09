#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 10005;

int n, x, y, ip;
pii p[N];
int f[N];

bool dir(int i, int j, int k) {
	return p[i].x * p[j].y + p[i].y * p[k].y + p[j].x * p[k].y - (p[k].x * p[j].y + p[k].y * p[i].x + p[j].x * p[i].y) > 0;
}

bool comp(int a, int b) {
	return x * p[a].y + y * p[b].y + p[a].x * p[b].y - (p[b].x * p[a].y + p[b].y * x + p[a].x * y) > 0;
}

int main() {
	int i, ii = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%lld %lld", &p[i].x, &p[i].y);
		f[i] = i;
	}
	for(i = 1; i < n; i++)
		if(p[i].y < p[ii].y) ii = i;
		else if(p[i].y == p[ii].y && p[i].x < p[ii].x) ii = i;	
	x = p[ii].x; y = p[ii].y;
	printf("Base %d %d\n", x, y);
	sort(f, f + n, comp); 
	for(i = 0; i < n; i++)
		printf("%d %d\n", p[f[i]].x, p[f[i]].y);
	printf("%d %d\n", f[0] + 1, f[n/2]);
	return 0;
}

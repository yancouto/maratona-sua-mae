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

int n;
pii p[N];
ll x, y;
int f[N];

bool comp(int a, int b) {
	return (x * p[a].y + y * p[b].x + p[a].x * p[b].y - (p[b].x * p[a].y + p[b].y * x + p[a].x * y)) > 0;
}

int main() {
	int i, ii = 0, j;
	scanf("%d", &n);
	if(n == 2) { puts("1 2"); return 0; }
	for(i = 0; i < n; i++) 
		scanf("%lld %lld", &p[i].x, &p[i].y), f[i] = i;
	for(i = 1; i < n; i++)
		if(p[i].y < p[ii].y) ii = i;
		else if(p[i].y == p[ii].y && p[i].x < p[ii].x) ii = i;	
	x = p[ii].x; y = p[ii].y;
	for(i = ii + 1; i < n; i++) 
		swap(f[i], f[i-1]); 
	sort(f, f + n - 1, comp); 
	printf("%d %d\n", f[n-1] + 1, f[n/2 - 1] + 1);
	return 0;
}

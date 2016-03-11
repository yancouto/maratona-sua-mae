#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 100005;

int n;
pii p[N];
int ct[N*10], acc[N*10];
int memo[N];

int solve(int i) {
	if(i <= 0) return 0;
	int &me = memo[i];
	if(me != -1) return me;
	me = acc[p[i].f] - 1;
	if(p[i].f - p[i].s - 1 >= 0)
		me -= acc[p[i].f-p[i].s-1];
	me += solve(i - me - 1);
	return me;
}
bool cmp (pii a, pii b) { return a.f < b.f; }
int main() {
	int i;
	memset(memo, -1, sizeof memo);
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &p[i].f, &p[i].s);
		ct[p[i].f] = 1; 
	}
	sort(p, p + n, cmp);
	acc[0] = ct[0];
	for(i = 1; i <= 1000000; i++)
		acc[i] = acc[i-1] + ct[i];
	int ans = INT_MAX;
	for(i = n - 1; i >= 0; i--) 
		ans = min(ans, n - i - 1 + solve(i));
	printf("%d\n", ans);
	return 0;
}

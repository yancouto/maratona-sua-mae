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

struct fri{
	int m, f;
};

fri v[100005];
bool cmp(fri a, fri b) {
	return a.m < b.m;
}
int main() {
	int n, d; 
	scanf("%d %d", &n, &d);
	for(int i = 0; i < n; i++)
		scanf("%d %d", &v[i].m, &v[i].f);
	v[n].m = INT_MAX;
	v[n].f = 0;
	sort(v, v + n, cmp);
	ll acc[100005];
	for(int i = 0; i < n; i++) {
		acc[i] = ((i)?acc[i-1]:0) + v[i].f;
	}
	int lst = 1;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = lst; j <= n; j++) {
			if(v[j].m < v[i].m + d) continue;
			lst = j;
			ans = max(ans, acc[j-1] - ((i)?acc[i-1]:0));
			break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

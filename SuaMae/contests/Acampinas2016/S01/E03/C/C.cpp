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

vector<int> v;
int a[100];
void solve(int i, int val) {
	if(i < 0) { v.pb(val); return; }
	if(val < 0) return;
	solve(i - 1, a[i] + val);
	if(val) solve(i - 1, a[i] - val);
}

int main() {
	int i, k, j;
	scanf("%d", &k);
	for(i = 0; i < k; i++)
		scanf("%d", &a[i]);
	solve(k - 2, a[k - 1]);
	solve(k - 2, a[k - 1] + 1);
	solve(k - 2, a[k - 1] - 1);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	vector<pii> ans;
	for(i = 0; i < v.size(); ) {
		for(j = i + 1; j < v.size() && v[j] == v[j - 1] + 1;) j++;
		ans.pb(pii(v[i], v[j - 1]));
		i = j;
	}
	printf("%d\n", (int) ans.size());
	for(pii p : ans)
		printf("%d %d\n", p.fst, p.snd);
}

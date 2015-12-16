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

int n;
ll sum, a, x;
deque<int> dq;
ll add[200010];

int main() {
	int i, j, op;
	scanf("%d", &n);
	dq.pb(0);
	for(i = 0; i < n; i++) {
		scanf("%d", &op);
		if(op == 1) {
			cin >> a >> x;
			sum += x * a;
			add[a] += x;
		} else if(op == 2) {
			cin >> x;
			sum += x; dq.pb(x);
		}
		else {
			sum -= (dq.back() + add[dq.size()]);
			add[dq.size() - 1] += add[dq.size()];
			add[dq.size()] = 0;
			dq.pop_back();
		}
		printf("%.8f\n", (double) sum / (double) dq.size());
	}
	return 0;
}

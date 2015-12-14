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
const int MAX = 100009;
int memo[MAX][102][2];
int a[MAX], b[MAX];
vector<int> num[MAX];
int seen[MAX][102][2], tempo;
int N;

inline int solve(int i, int k, bool have) {
	return memo[i][k][have];
	//if(i == N || k == 0) return 0;
	//int &r = memo[i][k][have];
	//if(seen[i][k][have] == tempo) return r;
	//seen[i][k][have] = tempo;
	//int p = upper_bound(num[a[i]].begin(), num[a[i]].end(), i) - num[a[i]].begin();	
	//r = solve(i + 1, k - 1, false) + 1;
	//if(!have) r = max(r, solve(i + 1, k, false));
	//if(p < num[a[i]].size()) r = max(r, solve(num[a[i]][p], k, true) + 1);
	//return r;
}

deque<int> beg;
void build(int i, int k, bool have) {
	if(i == N || k == 0) return;
	int ans = solve(i, k, have);
	if(ans == solve(i + 1, k - 1, false) + 1) {
		beg.pb(i);
		build(i + 1, k - 1, false);
		return;
	}
	if(!have && ans == solve(i + 1, k, false)) {
		build(i + 1, k, false);
		return;
	}
	int p = upper_bound(num[a[i]].begin(), num[a[i]].end(), i) - num[a[i]].begin();
	assert(p < num[a[i]].size());
	build(num[a[i]][p], k, true);
}

int main() {
	freopen("funny.in", "r", stdin);
	freopen("funny.out", "w", stdout);
	int i, K, k, have;
	while(true) {
		scanf("%d %d", &N, &K);
		if(!N) return 0;
		tempo++;
		for(i = 0; i < N; i++) {
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b, b + N);
		int bs = unique(b, b + N) - b;
		for(i = 0; i < N; i++)
			a[i] = lower_bound(b, b + bs, a[i]) - b;
		for(i = 0; i < N; i++)
			num[a[i]].pb(i);
		for(k = 1; k <= K; k++)
			memo[N][k][0] = memo[N][k][1] = 0;
		for(i = N - 1; i >= 0; i--)
			for(k = 1; k <= K; k++)
				for(have = 0; have <= 1; have++) {
					int &r = memo[i][k][have];
					int p = upper_bound(num[a[i]].begin(), num[a[i]].end(), i) - num[a[i]].begin();	
					r = solve(i + 1, k - 1, false) + 1;
					if(!have) r = max(r, solve(i + 1, k, false));
					if(p < num[a[i]].size()) r = max(r, solve(num[a[i]][p], k, true) + 1);
				}
		int ans = solve(0, K, false);
		printf("%d\n", ans);
		beg.clear();
		build(0, K, false);
		beg.pop_back();
		deque<int>::iterator it = beg.end();
		for(i = 0; i < N - 1; i++)
			if(beg.size() < K - 1 && !binary_search(beg.begin(), it, i))
				beg.pb(i);
		assert(beg.size() == K - 1);
		sort(beg.begin(), beg.end());
		for(i = 0; i < beg.size(); i++)
			printf("%d ", beg[i] + 1);
		putchar('\n');

		for(i = 0; i < bs; i++)
			num[i].clear();
	}
}

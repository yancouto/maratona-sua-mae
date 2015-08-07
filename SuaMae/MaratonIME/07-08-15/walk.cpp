#include <cstdio>
#include <vector>
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
int fact[20];
int seen[1 << 16], tempo;
vector<int> v;
int tto = 0;
void dfs(int left, int ind) {
	if(left == 0) {
		if(seen[ind] == tempo) return;
		seen[ind] = tempo;
		int oc[3] = {0, 0, 0};
		for(int i = 0; i < v.size(); i++)
			oc[v[i]]++;
		int a = fact[v.size()];		
		for(int i = 0; i < 3; i++)
			a /= fact[oc[i]];
		tto += a;
		return;
	}
	for(int i = 0; i < 3; i++) {
		v.pb(i);
		dfs(left - 1, ind + (1 << (left*2)) * i);
		v.pop_back();
	}
}

int s(int n) {
	tempo++;
	if(n % 2) return 0;
	v.clear();
	dfs(n / 2, 0);
	return tto;
}

int main() {
	int i, n;
	fact[0] = 1;
	for(i = 1; i < 20; i++)
		fact[i] = i * fact[i - 1];
	for_tests(t, tt) {
		scanf("%d", &n);
		int tot = 0;
		for(i = 0; i <= n; i += 3)
			tot += 6 * s(n - i);
		printf("%d\n", tot);
	}
}

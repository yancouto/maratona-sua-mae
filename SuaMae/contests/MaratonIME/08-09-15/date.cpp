#include <bits/stdc++.h>
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

int f[256];
void pre() {
	int i;
	for(i = '2'; i <= '9'; i++)
		f[i] = i - '2';
	i = 8;
	for(char c : "TJQKA")
		f[c] = i++;
	i = 0;
	for(char c : "DCHS")
		f[c] = i++;
}

int v[26];
int main() {
	pre();
	int i; char c, n;
	for_tests(t, tt) {
		set<int> s;
		for(i = 0; i < 52; i++)
			s.insert(i);
		for(i = 0; i < 26; i++) {
			scanf(" %c%c", &c, &n);
			int cn = f[c] * 4 + f[n];
			s.erase(cn);
			v[i] = cn;
		}
		sort(v, v + 26, greater<int>());
		int pt = 0;
		for(i = 0; i < 26; i++) {
			auto it = s.lower_bound(v[i]);
			if(it == s.begin()) continue;
			pt++;
			s.erase(--it);
		}
		printf("%d\n", pt);
	}
}

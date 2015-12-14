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
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
char str[30];
int seen[30], tempo;
vector<int> v;

int main() {
	int i;
	for_tests(t, tt) {
		v.clear();
		scanf(" %s", str);
		tempo++;
		for(i = 0; i < 26; i++) {
			if(seen[i] == tempo) continue;
			seen[i] = tempo;
			int cyc = 1;
			int j = str[i] - 'A';
			while(j != i) {
				seen[j] = tempo;
				cyc++;
				j = str[j] - 'A';
			}
			if((cyc & 1) == 0) v.pb(cyc);
		}
		sort(v.begin(), v.end());
		bool ok = true;
		while(ok && !v.empty()) {
			if(v.size() == 1 || v[v.size()-2] != v[v.size()-1]) ok = false;
			else { v.pop_back(); v.pop_back(); }
		}
		if(ok) puts("Yes");
		else puts("No");		
	}
	return 0;
}

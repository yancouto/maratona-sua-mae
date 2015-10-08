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

set<string> st;

int main() {
	char f[25], s[25];
	scanf("%s", f);
	st.insert(string(f));
	while(42) {
		scanf("%s", s);	
		if(s[0] == '#') break;
		int n = strlen(s), i = 0;
		for(i = 0; i < n; i++) 
			if(s[i] == '-') { s[i] = '\0'; break; }
		st.insert(string(s));
		st.insert(string(s+i+1));
	}
	printf("%d\n", st.size() - 1);
	return 0;
}


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

int mask[1000];
int main() {
	int n; scanf("%d", &n);
	char s[105]; scanf("%s", s);
	char c = 'z';
	char d = 'Z';
	int nn = strlen(s);
	for(int i = 0; i < nn; i++) { 
		if(s[i] >= 'a') mask[s[i] - 'a'] = 1;
		else mask[s[i] - 'A'] = 1;
	}
	for(int i = 0; i < 26; i++)
		if(!mask[i]) { puts("NO"); return 0; }
	puts("YES");

}

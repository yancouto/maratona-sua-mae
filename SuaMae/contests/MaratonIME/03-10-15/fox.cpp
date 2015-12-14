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

char s[105];
int mark[26];

int main() {
	int n; 
	fgets(s, 100, stdin);
	sscanf(s, "%d", &n);
	while(n--) {
		memset(mark, 0, sizeof mark);
		fgets(s, 105, stdin);
		int nn = strlen(s);
		for(int i = 0; i < nn; i++) {
			if(s[i] >= 'A' && s[i] <= 'Z') mark[s[i]-'A'] = 1;
			if(s[i] >= 'a' && s[i] <= 'z') mark[s[i]-'a'] = 1;
		}
		bool mis = true;
		for(int i = 0; i < 26; i++) {
			if(!mark[i] && mis) printf("missing "), mis = false;
			if(!mark[i]) printf("%c", i+'a');
		}
		if(mis) printf("pangram");
		putchar('\n');
	}
	return 0;
}

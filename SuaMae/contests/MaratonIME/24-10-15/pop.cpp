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

char s[30], cmp[30];
bool mark[30];
int n, ic, i, k, ip;
int p[30];

void func() {
	ip = 0;
	for(i = 0; i < ic; i++) {
		if(ip) {
		//	printf("COmpara %c %c\n", cmp[p[ip-1]], cmp[i]);
			if(cmp[p[ip-1]] == cmp[i]) { ip--; mark[p[ip]] = 0; }
			else if(mark[i]) p[ip++] = i;
		}
		else if(mark[i]) p[ip++] = i;
		//printf("Pilha %c\n", cmp[p[ip-1]]);
	}
}

int main() {
	for_tests(t, tt) {
		scanf("%s", s);
		memset(mark, 0, sizeof mark);
		n = strlen(s); ic = i = 0;
		while(i < n) {
			cmp[ic] = s[i];
			if(i == 0 && s[i] != s[i+1]) mark[i] = 1;
			else if(i == n-1 && s[i] != s[i-1]) mark[i] = 1;
			else if(i > 0 && i < n-1 && s[i] != s[i-1] && s[i] != s[i+1])
				mark[ic] = 1;
			k = i;
			while(k < n && s[k] == s[i]) k++;
			i = k;
			ic++;
		}
//		for(i = 0; i < ic; i++)
//			printf(" %c %d", cmp[i], mark[i]);
//		putchar('\n');
		func();
		reverse(cmp, cmp + ic);
		reverse(mark, mark + ic);
		func();
		for(i = 0; i < ic; i++)
			if(mark[i]) break;
		if(i < ic) puts("0");
		else puts("1");
	}
	return 0;
}

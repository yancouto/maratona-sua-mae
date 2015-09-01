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

char s[4005];
ll pot[4005], hd[4005], ha[4005];
int n;

void ppot() {
	pot[0] = 1;
	for(int i = 1; i < 4005 ; i++)
		pot[i] = mod(pot[i-1] * 257);
}

void phash() {
	hd[0] = s[0];
	for(int i = 1; i < n; i++) 
		hd[i] = mod(hd[i-1] + mod(s[i] * pot[i]));
	ha[n-1] = s[n-1];
	for(int i = n-2; i >= 0; i--)
		ha[i] = mod(ha[i+1] + mod(s[i] * pot[n-i-1]));
}	

bool match(int l, int r, int a, int b) {
	ll x = mod(hd[r] - ((l) ? hd[l-1] : 0) + modn);
	ll y = mod(ha[a] - ((b==n-1) ? 0 : ha[b+1]) + modn);
	int p = n - b - 1;
	if(l > p) { swap(l, p); swap(x, y); }
	x = mod(x * pot[p-l]);
	return x == y;		
}
int memo[4005];
int solve(int i) {
	if(i == n) return 0;
	int &m = memo[i];
	if(m != -1) return m;
	int ans = 1 + solve(i + 1); 
	for(int j = i + 1; j < n; j++) {
		int l, r, a, b, nn = j - i + 1;
		l = i; r = i + nn/2 - 1;
		a = r + 1; b = j;
		if(nn % 2) a++;
		if(match(l, r, a, b)) ans = min(ans, 1 + solve(j + 1));
	}
	return m = ans;
}

void build(int i) {
	if(i == n) return ;
	int ans = solve(i);
	if(ans == 1 + solve(i + 1)) {
		printf("%c", s[i]); 
		if(i < n - 1) putchar(' '); 
		build(i + 1); 
	}  
	else {
		for(int j = i + 1; j < n; j++) {
			int l, r, a, b, nn = j - i + 1;
			l = i; r = i + nn/2 - 1;
			a = r + 1; b = j;
			if(nn % 2) a++;
			if(!match(l, r, a, b)) continue;
			if(ans == 1 + solve(j + 1)) {
				for(int k = i; k <= j; k++) printf("%c", s[k]);
				if(j < n - 1) putchar(' ');
				build(j + 1);
				break;
			}
		}
	}
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	ppot(); phash();
	memset(memo, -1, sizeof memo);
	printf("%d\n", solve(0));
	build(0);
	putchar('\n');
	return 0;
}

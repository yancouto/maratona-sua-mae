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

bool seen[60];
int v[200], iv, x[200], n, mx;
char s[200];

void show() {
	for(int i = 0; i < iv; i++)
		printf("%d ", v[i]);
	putchar('\n');
}

bool brute(int i) {
	if(i == n) { show(); return true; }
	if(!seen[x[i]]) {
		v[iv++] = x[i]; seen[x[i]] = 1;
		if(brute(i+1)) return true;
		iv--; seen[x[i]] = 0;
	}
	if(i == n - 1) return false;
	int num = x[i] * 10 + x[i+1];
	if(num <= mx && !seen[num]) {
		v[iv++] = num; seen[num] = 1;
		if(brute(i+2)) return true;
		iv--; seen[num] = 0;
	}
	return false;
}

int main() {
	freopen("joke.in", "r", stdin);
	freopen("joke.out", "w", stdout);
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; i++) x[i] = s[i]-'0';
	mx = n;
	if(n > 9) mx = (n-9)/2 + 9;
	brute(0);
	return 0;
}

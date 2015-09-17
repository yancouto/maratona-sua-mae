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
#define MAX 5005

char str[MAX];
int n;
int z[MAX], zf[MAX], freq[30];
void zfunction(int st) {
	st--;
	int l = 0, r = 0;
	for(int i = st + 1; i < n; i++) {
		if(i > r) {
			l = r = i;
			while(r < n && str[r] == str[r - l + st]) r++;
			z[i]= r - l; r--;
			continue;
		}
		int k = i - l + st;
		if(z[k] < r - i + 1) { z[i] = z[k]; continue; }
		l = i;
		while(r < n && str[r] == str[r - l + st]) r++;
		z[i] = r - l; r--;
	}
}

void updatez() {
	for(int i = 0; i < n; i++)
		zf[i] = max(zf[i], z[i]);
}

int main() {
	scanf("%s", str); 
	n = strlen(str);
	ll ans = n;
	for(int i = 1; i < n; i++) {
		memset(z, 0, sizeof z);
		zfunction(i);
		updatez();
		ans += n - i - zf[i];
	}
	printf("%lld\n", ans);
	return 0;
}

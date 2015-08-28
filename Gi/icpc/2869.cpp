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


int num[1000];
int aux[1000];

ll toNum(int l, int r, int n[1000]) {
	ll pot = 1;
	ll ret = 0;
	for(int i = r; i >= l; i--) {
		ret += n[i] * pot;
		pot *= 10;
	}
	return ret;
}

int main() {
	char str[1000];
	while(42) {
		scanf("%s", str);
		int n = strlen(str);
		for(int i = 0; i < n; i++) num[i] = str[i] - '0';
		if(n == 1 && num[0] == 0) break;
		if(n == 1) { puts("0"); continue; }
		ll nn = toNum(0, n-1, num);
		int mid = n / 2;
		if(n % 2 == 0) mid--;
		ll ans = 0;
		for(int i = n / 2 - 1, j = 0; i >= 0; i--, j++)
			aux[j] = num[i];
		ll a = toNum(0, n / 2 - 1, aux);
		ll b = toNum(mid + 1, n - 1, num);
		if(a >= b) {
			for(int i = 0; i <= mid; i++) aux[i] = num[i];
			for(int i = 0, j = n-1; i < n / 2; i++, j--) 
				aux[j] = num[i];
			ans = toNum(0, n-1, aux) - nn;
			printf("%lld\n", ans);
			continue;
		}
		ll org = toNum(0, mid, num) + 1;
		int i = mid; 
		memset(aux, 0, sizeof aux);
		while(org != 0) { aux[i--] = org % 10; org /= 10; }
		for(int i = 0, j = n-1; i < n / 2; i++, j--) 
			aux[j] = aux[i];
		ans = toNum(0, n-1, aux) - nn;
		printf("%lld\n", ans);
	}
	return 0;
}

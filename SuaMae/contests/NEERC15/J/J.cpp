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

int num[1009], n, resp[1009], num2[1009];
void gen_random() {
	for(int i = 0; i < n; i++)
		num[i] = ((rand()) & 1);
}

int query() {
	for(int i = 0; i < n; i++)
		putchar('0' + num[i]);
	putchar('\n');
	fflush(stdout);
	int v;
	scanf("%d", &v);
	if(v == n) exit(0);
	return (v == (n / 2));
}

int main() {
	int i;
	srand(time(NULL));
	scanf("%d", &n);
	while(true) {
		gen_random();
		int v = query();
		if(v) break;
	}
	num[0] = !num[0];
	int tot = 0;
	for(i = 1; i < n; i++) {
		num[i] = !num[i];
		resp[i] = query();
		tot += resp[i];
		num[i] = !num[i];
	}
	num[0] = !num[0];
	for(i = 0; i < n; i++)
		num2[i] = num[i];
	num[0] = num2[0];
	for(i = 1; i < n; i++)
		num[i] = resp[i] ^ num2[i];
	query();
	num[0] = !num2[0];
	for(i = 1; i < n; i++)
		num[i] = (num2[i] ^ (!resp[i]));
	query();
}

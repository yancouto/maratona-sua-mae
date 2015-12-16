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

int a[50];
int main() {
	int i;
	for(i = 0; i < 50; i++)
		a[i] = i + 1;
	random_shuffle(a, a + 50);
	for(i = 0; i < 50; i++)
		printf("%d", a[i]);
	putchar('\n');
}

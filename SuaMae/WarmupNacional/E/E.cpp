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

int a[3];
char op[2];

int apply(char op, int a, int b) {
	if(op == '+') return a + b;
	if(op == '-') return a - b;
	return a * b;
}

int eval() {
	if(op[0] == '*') return apply(op[1], a[0] * a[1], a[2]);
	if(op[1] == '*') return apply(op[0], a[0], a[1] * a[2]);
	return apply(op[1], apply(op[0], a[0], a[1]), a[2]);
}
int mn;
void test(int i) {
	if(i == 2) {
		mn = min(mn, eval());
		return;
	}
	op[i] = '+';
	test(i + 1);
	op[i] = '-';
	test(i + 1);
	op[i] = '*';
	test(i + 1);
}

int main() {
	for(int i = 0; i < 3; i++)
		scanf("%d", &a[i]);
	sort(a, a + 3);
	mn = INT_MAX;
	do {
		test(0);
	} while(next_permutation(a, a + 3));
	printf("%d\n", mn);
}

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

bool dif(int a, int b, int c) { return a != b && a != c && b != c; }
bool isSet(int a, int b, int c) { return a == b && a == c && b == c; }

int hand[5];

int main() {
	int a, b, c;
	while(42) {
		scanf("%d %d %d", &a, &b, &c);
		if(a+b+c == 0) return 0;
		if(dif(a, b, c)) puts("1 1 2");
		else if(!isSet(a, b, c)) {
			if(a == c) swap(b, c);
			else if(b == c) swap(a, c);
			if(c == 13) printf("1 %d %d\n", a+1, b+1);
			else if(c+1 == a && c + 1 == 13) puts("1 1 1");
			else if(c+1 == a) printf("%d %d %d\n", a, b, a+1);
			else if(c+1 > a) printf("%d %d %d\n", a, b, c+1);
			else printf("%d %d %d\n", c+1, a, b);
		}
		else if(a == 13) printf("*\n");
		else printf("%d %d %d\n", a+1, b+1, c+1);
	}
	return 0;
}

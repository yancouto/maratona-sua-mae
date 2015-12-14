#include <cstdio>
#include <deque>
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

int main() {
	int n, i, j;
	for_tests(t, tt) {
		scanf("%d", &n);
		deque<int> d;
		for(i = n; i >= 1; i--) {
			d.push_front(i);
			for(j = 0; j < i; j++) {
				int a = d.back(); d.pop_back();
				d.push_front(a);
			}
		}
		for(i = 0; i < n; i++)
			printf("%d ", d[i]);
		printf("\n");
	}
	return 0;
}

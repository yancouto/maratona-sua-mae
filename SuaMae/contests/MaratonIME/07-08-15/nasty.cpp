#include <cstdio>
#include <algorithm>
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
	int r, e, c;
	 for_tests(t, tt) {
		  scanf("%d %d %d", &r, &e, &c);
		  if(r > e - c) puts("do not advertise");
		  else if(r < e - c) puts("advertise");
		  else puts("does not matter");
	 }
	 return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int n, x, y, lst;
map<int, int> sell, buy;

char op[10];
int main() {
	for_tests(t, tt) {
		lst = 0;
		sell.clear(); buy.clear();
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%s %d shares at %d\n", op, &y, &x);
			if(!strcmp(op, "sell")) sell[x] += y;
			else buy[x] += y;
			map<int, int>::iterator it, it2;
			bool out = true;
			while(out) {
				out = false;
				if(!buy.empty()) it = buy.end(), --it;
				if(!sell.empty()) it2 = sell.begin();
				if(!sell.empty() && !buy.empty()) {
					if((it->x) >= (it2->x)) {
						pii a(it->x, max((it->y) - (it2->y), 0));
						pii b(it2->x, max((it2->y) - (it->y), 0));
						out = true; lst = b.x;
						buy.erase(it); sell.erase(it2);
						if(a.y) buy.insert(a);
						if(b.y) sell.insert(b);
					}
				}
			}

			if(sell.empty()) printf("- ");
			else printf("%d ", it2->x);
			if(buy.empty()) printf("- ");
			else printf("%d ", it->x);
			if(!lst) printf("-\n");
			else printf("%d\n", lst);
		}
	}
	return 0;
}

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

int n;
char s[10];
map<int, int> sell, buy;

int main() {
	for_tests(t, tt) {
		sell.clear(); buy.clear();
		scanf("%d", &n);
		int x, y;
		int ask = 0, bid = 0, lst = 0;
		for(int i = 0; i < n; i++) {
			scanf("%s %d shares at %d", s, &y, &x);
			map<int, int>::iterator it, it2;
			if(!strcmp(s, "sell")) sell[x] += y;
			else buy[x] += y;
			bool out = true;
			while(out) {
				out = false;
				if(!buy.empty()) { it = buy.end(); --it; }
				if(!sell.empty()) it2 = sell.begin();
				if(!buy.empty() && !sell.empty()) {
					if(it->x >= it2->x) {				
						out = true;
						pii a = pii(it->x, max(it->y - it2->y, 0));
						pii b = pii(it2->x, max(it2->y - it->y, 0));
						lst = it2->x;
						buy.erase(it); sell.erase(it2);
						if(a.y) buy.insert(a); 
						if(b.y) sell.insert(b);
					}
				}
			}
			if(!buy.empty()) { it = buy.end(); --it; }
			if(!sell.empty()) it2 = sell.begin();
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

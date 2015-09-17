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

int p, q, l, r;
int aloha;
vector<pii> x, z;
int main(){
	scanf("%d %d %d %d", &p, &q, &l, &r);
	int i;
	for(i = 0; i < p; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		z.pb(make_pair(a, b));
	}
	for(i = 0; i < q; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		x.pb(make_pair(a, b));
	}
	int resp = 0;
	set<int> ans;
	for(i = 0; i < p; i++){
		int a = z[i].fst;
		int b = z[i].snd;
		for(int j = 0; j < q; j++){
			int c, d;
			c = x[j].fst;
			d = x[j].snd;
			for(int k = l; k <= r; k++)
				if((c+k <= b && d+k >= a) || (c+k <= a && d+k >= a) || (c+k >= a && d+k <= b) || (c+k <= a && d+k >= b)) {
					if(ans.find(k) == ans.end()){
						resp++;
						ans.insert(k);
					}
				}
		}
	}
	printf("%d\n", resp);
	return 0;
}

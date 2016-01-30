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

struct Ponto {
	int x, y, z;
	Ponto () {}
	Ponto (int x, int y, int z) : x(x), y(y), z(z) {}
	bool operator <(const Ponto &o)const{
		if(x == o.x) {
			if (y == o.y) return o.z < z;
			return  o.y < y;
		}
		return o.x < x;
	}
};

set<Ponto> st;
ll A, B, C, n;
int dx[6] = {1, -1, 0, 0 , 0, 0 }; 
int dy[6] = {0, 0 , 1, -1, 0, 0 };
int dz[6] = {0, 0 , 0, 0 , 1, -1};


int main() {
	int i, j;
	ll x, y, z;
	set<Ponto>::iterator it;
	scanf("%lld %lld %lld %lld", &A, &B, &C, &n);
	ll ans = 2 * A * B + 2 * A * C + 2 * B * C;
	for(i = 0; i < n; i++) {
		scanf("%lld %lld %lld", &x, &y, &z);
		st.insert(Ponto(x, y, z));
		for(j = 0; j < 6; j++) {
			if((x + dx[j] < 0 || x + dx[j] >= A) || (y + dy[j] < 0 || y + dy[j] >= B) || (z + dz[j] < 0 || z + dz[j] >= C)) ans--;
			else if(!st.count(Ponto(x + dx[j], y + dy[j], z + dz[j]))) ans++;
			else ans--;
		}

	}
	printf("%lld\n", ans);
	return 0;
}

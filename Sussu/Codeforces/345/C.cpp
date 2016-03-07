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

const int MAXN = 200010;

int n;

pii s[MAXN];

map<int,int> l, c;

map<pii, int> coin;

ll res;

int main(){
	scanf("%d", &n);
	res = 0;
	for(int a=0;a<n;a++){
		scanf("%d%d", &s[a].fst, &s[a].snd);
		if(coin.find(s[a]) != coin.end())
			res -= coin[s[a]];

		coin[s[a]]++;

		if(l.find(s[a].fst) != l.end())
			res += l[s[a].fst]; 

		l[s[a].fst]++;

		if(c.find(s[a].snd) != c.end())
			res += c[s[a].snd];

		c[s[a].snd]++;
	}
	cout << res;
}
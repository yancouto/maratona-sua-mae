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

const int MAXN = 200010, INF = 0x3f3f3f3f;

ll n, s[MAXN];

struct menor{
	ll i, v;
} esq[MAXN], dir[MAXN];

int main()
{
	cin >> n;
	esq[0].v = INF;
	for(int a=1;a<=n;a++){
		cin >> s[a];
		if(s[a] < esq[a-1].v){
			esq[a].v = s[a];
			esq[a].i = a;
		}
		else
			esq[a] = esq[a-1];

	}
	dir[n+1].v = INF;
	for(int a=n;a>=1;a--){
		if(s[a] <= dir[a+1].v){
			dir[a].v = s[a];
			dir[a].i = a;
		}
		else
			dir[a] = dir[a+1];
	}

	ll res = 0;

	for(int a=1;a<=n;a++){
		ll men, ind;
		if(esq[a-1].v <= dir[a].v-1){
			men = esq[a-1].v;
			ind = esq[a-1].i;
		}
		else{
			men = dir[a].v;
			ind = dir[a].i;
		}

		if(men == 0){
			if(ind < a)
				res = max(res,n-a+ind);
			else
				res = max(res,ind-a);
		}
		else{
			if(ind < a){
				res = max(res,n-a+1 + ind-1 + n*men);
			}
			else{
				res = max(res, ind-1-a+1 + n*men);
			}
		}
	}
	cout << res;
	return 0;
}
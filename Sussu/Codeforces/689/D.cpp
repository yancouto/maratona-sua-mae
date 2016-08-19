#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

ll sa[MAXN], sb[MAXN];
ll n;

set <pii> ma, mb;

int main (){
	cin >> n;
	for(int a=0;a<n;a++){
		cin >> sa[a];
	}
	for(int a=0;a<n;a++){
		cin >> sb[a];
	}
	ll i = 0, j = 0;
	ll ans = 0;
	while(j < n){
		ma.insert(pii(-sa[j], -j));
		mb.insert(pii(sb[j], -j));

		while(i <= j && -ma.begin()->fst > mb.begin()->fst){
			ma.erase(pii(-sa[i], -i));
			mb.erase(pii(sb[i], -i));
			i++;
		}
		if(!ma.empty()){
			pii ta = *ma.begin();
			pii tb = *mb.begin();

			if(ta.fst == -tb.fst){
			//	printf("== somo %lld - %lld +1\n", min(-ta.snd, -tb.snd), i);

				ans += min(-ta.snd, -tb.snd) - i + 1ll;
			}
		}
		j++;
	}
	cout << ans << endl;
}

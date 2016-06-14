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

const int MAXN = 112345;

int n, k, bon[1123456];

struct opo{
	int k, g, p;
	opo(){}
	opo(int kk, int gg, int pp){
		k = kk; g =gg; p = pp;
	}
};

vector<opo> gan;
opo s[MAXN];

bool cmp(opo a, opo b){
	return a.k < b.k;
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		int kk, g, p;
		scanf("%d%d%d", &kk, &g, &p);
		gan.pb(opo(kk, g, p));
		s[a] = opo(kk, g, p);
	}
	sort(s, s+n, cmp);
	int i = 0;
	for(int a=0;a<1000001;a++){
		if(a > i)
	}
	ll bon = 0;
	ll res = 0;
	for(int i = 0;i < n;i++){
		opo en = gan[i];
		res++;
		if(k > en.k){
			k += en.g;
			bon += en.g;
		}
		else{
			if(bon-en.p <= 0){
				puts("-1");
				return 0;
			}
			else{
				ll cnt = (en.k - k + 1)/(bon-en.p) + 1*((en.k - k + 1)%(bon-en.p) != 0);
				res += (i+1)*cnt;
				k += ((bon-en.p)*cnt);
			}
			bon += en.g;
		}
	}
	printf("%lld\n", res);
}

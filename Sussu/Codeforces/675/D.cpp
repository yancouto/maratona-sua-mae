
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

int n, s[MAXN];

set <int> v;

map <int, int> ind;

int main (){
	scanf("%d", &n);
	v.insert(-1);
	v.insert(1000000001);
	ind[-1] = -1;
	ind[1000000001] = -1;
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		ind[s[a]] = a;
		if(a==0){
			v.insert(s[a]);
			continue;
		}
		if(ind[*(--v.lower_bound(s[a]))] > ind[*v.lower_bound(s[a])])
			printf("%d ", *(--v.lower_bound(s[a])));
		else
			printf("%d ", *v.lower_bound(s[a]));
		v.insert(s[a]);
	}

}

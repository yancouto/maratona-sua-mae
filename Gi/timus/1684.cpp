//WA
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

ll pot[75005], inv[75005];
int n1, n2;

ll prec_inv(int i, ll j) {
	if(2 * j > modn - 2) return j;
	inv[i] = mod(inv[i] * inv[i]);
	ll aux = inv[i];
	ll w = prec_inv(i, 2 * j);
	if(2 * j + w > modn - 2) return w;
	inv[i] = mod(inv[i] * aux); 
	return 2 * j + w;
}

void prec_pot() {
	pot[0] = 1;
	int n = max(n1, n2);
	for(int i = 1; i < n; i++)
		pot[i] = mod(pot[i-1] * 31);
	inv[0] = 1;
	for(int i = 1; i < n; i++) {
		inv[i] = pot[i];
		ll j = prec_inv(i, 1);
		for(j = j + 1; j <= modn - 2; j++) 
			inv[i] = mod(inv[i] * pot[i]);
	}
	//for(int i = 0; i < n; i++)
	//	printf("(%d) %lld\n", i, inv[i]);
}


void make_hash(ll h[75005], char s[75005], int n) {
	h[0] = s[0];
	for(int i = 1; i < n; i++) 
		h[i] = mod(h[i-1] + mod(s[i] * pot[i]));
}

ll get_hash(int l, int r, ll h[75005], int n) {
	if(r > n - 1) return -1;
	ll a, b;
	a = 0; if(l > 0) a = h[l-1];
	b = h[r];
	return mod(mod(b - a + modn) * inv[l]);
}

void show_hash(ll h[75005], int n) {
	for(int i = 0; i < n; i++)
		printf("%lld ", h[i]);
	putchar('\n');
}

ll h1[75005], h2[75005];
set<pii> ans;
int main() {
	char s1[75005], s2[75005];
	scanf(" %s %s", s1, s2);
	n1 = strlen(s1);
	n2 = strlen(s2);
	prec_pot();
	make_hash(h1, s1, n1);
	make_hash(h2, s2, n2);
	//show_hash(h1, n1);
	//show_hash(h2, n2);
	for(int i = 0; i < n2; i++) {
		int imax = -1;
	//	printf("-------------------------------------------------\n\n");
		for(int j = 0; j < n1; j++) {
			ll a = get_hash(0, j, h1, n1);
			ll b = get_hash(i, i+j, h2, n2);
	//		printf("Comparando [%d, %d] com [%d, %d] %lld = %lld\n", 0, j, i, i + j, a, b);
			if(a == b) imax = i + j;  
			else break;
		}
	//	printf("Bateu %d %d\n", i, imax);
		if(imax == -1) continue;
		ans.insert(pii(i, imax));		
	}
	int lst = -1;
	bool yes = true;
	vector<int> vec;
	for(auto it = ans.begin(); it != ans.end(); ++it) {
		if(it->fst > lst + 1) { yes = false; break; } 
		if(lst < it->snd) vec.pb(it->fst);
		lst = max(lst, it->snd);
	}
	if(lst < n2-1) yes = false;
	if(!yes) puts("YES");
	else {
		puts("NO");
		lst = 0;
		for(int i = 1; i < vec.size(); i++) {
			for(int j = lst; j < vec[i]; j++) 
				printf("%c", s2[j]);
			putchar(' ');
			lst = vec[i]; 	
		}
		for(int j = lst; j < n2; j++) 
			printf("%c", s2[j]);
		printf(" \n");
	}
	return 0;
}

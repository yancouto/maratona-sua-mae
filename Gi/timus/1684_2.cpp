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

ll pot[75005];
int n1, n2;

void prec_pot() {
	pot[0] = 1;
	int n = max(n1, n2);
	for(int i = 1; i < n; i++)
		pot[i] = mod(pot[i-1] * 31);
}

void make_hash(ll h[75005], char s[75005], int n) {
	h[0] = s[0];
	for(int i = 1; i < n; i++) 
		h[i] = mod(h[i-1] + mod(s[i] * pot[i]));
}

ll h1[75005], h2[75005];

bool get_hash(int l, int r, int b, int e) {
	if(r > n1 - 1 || e > n2 - 1) return false;
	ll d1 = mod(h1[r] - ((l) ? h1[l-1] : 0) + modn);
	ll d2 = mod(h2[e] - ((b) ? h2[b-1] : 0) + modn);
	if(l > b) return d1 == mod(d2 * pot[l-b]);
	return d2 == mod(d1 * pot[b-l]);
}

void show_hash(ll h[75005], int n) {
	for(int i = 0; i < n; i++)
		printf("%lld ", h[i]);
	putchar('\n');
}

set<pii> ans;

int main() {
	char s1[75005], s2[75005];
	scanf(" %s %s", s1, s2);
	n1 = strlen(s1);
	n2 = strlen(s2);
	prec_pot();
	make_hash(h1, s1, n1);
	make_hash(h2, s2, n2);
	for(int i = 0; i < n2; i++) {
		int imax = -1;
		for(int j = 0; j < n1; j++) {
			if(get_hash(0, j, i, i + j)) imax = i + j;  
			else break;
		}
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
		printf("\n");
	}
	return 0;
}

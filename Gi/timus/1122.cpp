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

int tab[4], mv[3];


bool check(int mask) {
	int t[4] = {tab[0], tab[1], tab[2], tab[3]}
	for(int i = 0; i < 4; i++) {
		for(int j = 0
	}

}


int main() {
	for(int i = 0; i < 4; i++) {
		tab[i] = 0;
		for(int j = 0; j < 4; j++) {
			char c; scanf(" %c", &c);
			if(c == 'B') 
				tab[i] = (tab[i] | (1 << j));
		}
	}
	
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			char c; scanf(" %d", &c);
			if(c == 1)
				mv[i] = (mv[i] | (1 << j));
		}
	}

	for(int t = 0; t < (1 << 16); t++) {
		
	}

	return 0;
}

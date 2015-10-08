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

int l[3][2], c[3][2], d1[2], d2[2];
char tab[3][3];

bool checklin(int cc, char let) {
	for(int i = 0; i < 3; i++)
		if(l[i][cc] == 2 && !l[i][!cc]) { 
			int j; for(j = 0; j < 3 && tab[i][j] != '#');
			tab[i][j] = let;
			return true;
		}
	return false;
}

bool checkcol(int cc, char let) {
	for(int i = 0; i < 3; i++)
		if(c[i][cc] == 2 && !c[i][!cc]) { 
			int j; for(j = 0; j < 3 && tab[j][i] != '#');
			tab[j][i] = let;
			return true;
		}
	return false;
}

bool checkd1(int cc, char let) {
	if(d1[cc] == 2 && !d1[!cc]) {
		if(tab[0][0] == '#') tab[0][0] = let;
		else if(tab[1][1] == '#') tab[1][1] = let;
		else if(tab[2][2] == '#') tab[2][2] = let;
		return true;
	}
	return false;
}

bool checkd2(int cc, char let) {
	if(d2[cc] == 2 && !d2[!cc]) {
		if(tab[0][2] == '#') tab[0][2] = let;
		else if(tab[1][1] == '#') tab[1][1] = let;
		else if(tab[2][0] == '#') tab[2][0] = let;
		return true;
	}
	return false;
}

int main() {
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++) {
			scanf(" %c", &tab[i][j]);
			l[i][tab[i][j] == 'X']++;		
			c[j][tab[i][j] == 'X']++;		
			if(i == j) d1[tab[i][j] == 'X']++;
			if(i+j == 2) d2[tab[i][j] == 'O']++; 
		}
	if(checklin(1, 'X')) { puts("Crosses win"); return 0; }
	if(checkcol(1, 'X')) { puts("Crosses win"); return 0; }
	if(checkd1(1, 'X')) { puts("Crosses win"); return 0; }
	if(checkd2(1, 'X')) { puts("Crosses win"); return 0; }
	if(!checklin(0, 'X') && !checkcol(0, 'X') && !checkd1(0, 'X') && !checkd2(0, 'X')) {
		puts("Draw"); return 0;
	}

	return 0;
}

		
	
		
	
	return 0;	
}

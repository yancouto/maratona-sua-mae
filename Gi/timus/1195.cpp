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

char tab[3][3];

bool check(int p) {
	int cr, ot;
	int d1r, d1o, d2r, d2o;
	d1r = d1o = d2r = d2o = 0;
	for(int i = 0; i < 3; i++) {
		cr = ot = 0;
		for(int j = 0; j < 3; j++) {
			cr += tab[i][j] == 'X';
			ot += tab[i][j] == 'O';
			if(i == j) { d1r += (tab[i][j] == 'X'); d1o += (tab[i][j] == 'O'); }
			if(i+j == 2) { d2r += (tab[i][j] == 'X'); d2o += (tab[i][j] == 'O'); }
		}
		if(p && cr == 3) return true;
		if(!p && ot == 3) return true;	
	}
	if(p && (d1r == 3 || d2r == 3)) return true;
	if(!p && (d1o == 3 || d2o == 3)) return true;
	for(int j = 0; j < 3; j++) {
		cr = ot = 0;
		for(int i = 0; i < 3; i++) {
			cr += tab[i][j] == 'X';
			ot += tab[i][j] == 'O';
		}
		if(p && cr == 3) return true;
		if(!p && ot == 3) return true;	
	}
	return false;
}

int seen[3];
vector<pii> pos;
int beg;

int play(int n, int j) {
	if(n == 0) return 2;
	char c = (j) ? 'X' : 'O';
	int w, d, dr;
	w = d = dr = 0;
	for(int i = 0; i < 3; i++) {
		int a = pos[i].fst, b = pos[i].snd;
		if(seen[i]) continue;
		seen[i] = 1; tab[a][b] = c;
		if(check(j)) w++; 
		else {
			int ans = play(n-1, !j);
			if(ans == 2) dr++;
			else if(ans == j) w++;
			else d++;
		}
		seen[i] = 0; tab[a][b] = '#';
	}
	if(w) return j;
	if(dr) return 2;
	return !j;
}

int main() {
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++) {
			scanf(" %c", &tab[i][j]);
			if(tab[i][j] == '#') pos.pb(pii(i, j));
		}
	int ans = play(3, 1);
	if(ans == 1) puts("Crosses win");
	else if(ans == 0) puts("Ouths win");
	else puts("Draw");
	return 0;	
}

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

char g[10][11234];
int n;
int pos(int i, int of) {
	return 6 * i + of;
}

string mat[10][7] = {
{ "xxxxx",
  "x...x",
  "x...x",
  "x...x",
  "x...x",
  "x...x",
  "xxxxx"
},
{ "....x",
  "....x",
  "....x",
  "....x",
  "....x",
  "....x",
  "....x"
},
{ "xxxxx",
  "....x",
  "....x",
  "xxxxx",
  "x....",
  "x....",
  "xxxxx"
},
{ "xxxxx",
  "....x",
  "....x",
  "xxxxx",
  "....x",
  "....x",
  "xxxxx"
},
{ "x...x",
  "x...x",
  "x...x",
  "xxxxx",
  "....x",
  "....x",
  "....x"
},
{ "xxxxx",
  "x....",
  "x....",
  "xxxxx",
  "....x",
  "....x",
  "xxxxx"
},
{ "xxxxx",
  "x....",
  "x....",
  "xxxxx",
  "x...x",
  "x...x",
  "xxxxx"
},
{ "xxxxx",
  "....x",
  "....x",
  "....x",
  "....x",
  "....x",
  "....x"
},
{ "xxxxx",
  "x...x",
  "x...x",
  "xxxxx",
  "x...x",
  "x...x",
  "xxxxx"
},
{ "xxxxx",
  "x...x",
  "x...x",
  "xxxxx",
  "....x",
  "....x",
  "xxxxx"
},
};
//....x.xxxxx.xxxxx.x...x.xxxxx.xxxxx.xxxxx.......xxxxx.xxxxx.xxxxx
//....x.....x.....x.x...x.x.....x.........x...x...x...x.x...x.x...x
//....x.....x.....x.x...x.x.....x.........x...x...x...x.x...x.x...x
//....x.xxxxx.xxxxx.xxxxx.xxxxx.xxxxx.....x.xxxxx.xxxxx.xxxxx.x...x
//....x.x.........x.....x.....x.x...x.....x...x...x...x.....x.x...x
//....x.x.........x.....x.....x.x...x.....x...x...x...x.....x.x...x
//....x.xxxxx.xxxxx.....x.xxxxx.xxxxx.....x.......xxxxx.xxxxx.xxxxx

int get(int &x, int &ind) {
	int i, j;
	for(; ind < n && g[2][pos(ind, 2)] != 'x'; ind++) {
		int num;
		for(num = 0; ; num++) {
			bool ok = true;
			for(i = 0; i < 7; i++)
				for(j = 0; j < 5; j++)
					ok &= mat[num][i][j] == g[i][pos(ind, j)];
			if(ok) break;
		}
		x = 10 * x + num;
	}
}

void print(ll a) {
	int i, j;
	for(i = 0; i < 7; i++)
		for(j = 0; j < 10000; j++)
			g[i][j] = '.';
	ll sz = 0, b = 0, ind = 0;
	for(; a; a /= 10) b = 10 * b + (a % 10), sz++;
	int tot = 6 * sz - 1;
	for(; sz--; ind++, b /= 10)
		for(i = 0; i < 7; i++)
			for(j = 0; j < 5; j++)
				g[i][pos(ind, j)] = mat[b % 10][i][j]; 
	for(i = 0; i < 7; i++) {
		for(j = 0; j < tot; j++)
			putchar(g[i][j]);
		putchar('\n');
	}
}

int main() {
	int i;
	for(i = 0; i < 7; i++)
		scanf("%s", g[i]);
	n = strlen(g[0]);
	assert(((n + 1) % 6) == 0);
	n = (n + 1) / 6;
	int a = 0, b = 0; i = 0;
	get(a, i); i++; get(b, i);
	a += b;
	print(a);
}

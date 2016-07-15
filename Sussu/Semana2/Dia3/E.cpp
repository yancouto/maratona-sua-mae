#include <bits/stdc++.h>
#define mp make_pair
#define debug(args...) //fprintf(stderr, args)
#define pb push_back
#define ff first
#define ss second
using namespace std;

const int MAXN = 1123, INF = 0x3f3f3f3f;

int n;

int dp(int sd, int st) {
	if(sd < 0) return INF;
	if(sd == 0 && st == 0) return "";
	if(!ok[sd][st][fl]) {
		debug("calculando %d %d %d\n", sd, st, fl);
		ok[sd][st][fl] = 1;
		memo[sd][st][fl] = "$";
		int ini = fl ? 0 : 1;
		for(int i = ini; i <= 9; i++) {
			string aux = f(sd - i, (st * 10 + i) % n, fl || (i != 0));
			debug("testando %d em f(%d,%d, %d)\n", i, sd, st, fl);
			if(aux != "$") {
				debug("DEU BOM POR %d", i);
				return memo[sd][st][fl] = to_char(i) + aux;
			}
		}
	}
	return memo[sd][st][fl];
}

int main() {
	scanf("%d", &n);
	cout << f(n, 0, 0);
	return 0;
}

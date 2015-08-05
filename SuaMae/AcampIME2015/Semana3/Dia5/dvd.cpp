#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
int n;
vector<int> who[150][6];
char name[2005][110];

int memo[200][6][6][40];
int solve(int y, int r, int c, int bm) {
	if(y + 1870 > 2006) return 0;
	int &ret = memo[y][r][c][bm];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = 1; i <= 5; i++) {
		int k = 1 << (i - 1);
		if(bm & k) continue;
		if((c - (i != r)) < 0) continue;
		ret = max(ret, int(who[y][i].size()) + solve(y, i, c - (i!=r), bm | k));
	}
	ret = max(ret, solve(y+1, r, c, 0));
	return ret;
}

void build(int y, int r, int c, int bm) {
	if(y + 1870 > 2006) return;
	int ans = solve(y, r, c, bm);
	if(ans == solve(y+1, r, c, 0)) {
		build(y+1, r, c, 0);
		return;
	}
	for(int i = 1; i <= 5; i++) {
		int k = 1 << (i-1);
		if(bm & k) continue;
		if((c - (i != r)) < 0) continue;
		if(ans == (int(who[y][i].size()) + solve(y, i, c - (i!=r), bm | k))) {
			 for(int ii = 0; ii < who[y][i].size(); ii++)
				 printf("\"%s\n", name[who[y][i][ii]]);
			build(y, i, c - (i!=r), bm | k);
			return;
		}
	}
}

int main(){
	for_tests(t, tt) {
		memset(memo, -1, sizeof memo);
		for(int i = 0; i <150; i++)
			for(int j = 0; j < 6; j++)
				who[i][j].clear();
		scanf("%d", &n);
		char c;
		for(int i = 0; i < n; i++){
			scanf(" %c", &c);
			int count = 0;
			do{
				scanf("%c", &c);
				name[i][count++] = c;
			} while(c != '\"');
			name[i][count++] = '\0';
			int b, c;
			scanf(" %d %d", &b, &c);
			b -= 1870;
			who[b][c].pb(i);
		}
		if(tt > 1) putchar('\n');
		printf("%d\n", solve(0, 0, 6, 0));
		build(0, 0, 6, 0);
	}
	return 0;
}


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


int n, endy;
int memo[150][35][7][7];
vector<int> who[150][6];
int qtd[150][6];
char name[2005][110];

int solve(int y, int mask, int c, int r){
	if(y == endy+1) return 0;
	int &m = memo[y][mask][c][r];
	if(m != -1) return m;
	int ans = 0;
	for(int i = 1; i <= 5; i++){
		int k = 1<<(i-1);
		if(mask&k) continue;
		if(!qtd[y][i]) continue;
		if(c + (i!=r) > 5) continue;
		ans = max(ans, qtd[y][i] + solve(y, mask|k, c + (i != r), i));
	}
	ans = max(ans, solve(y+1, 0, c, r));
	return m = ans;
}

void build(int y, int mask, int c, int r) {
	if(y == n) return;
	int ans = solve(y, mask, c, r);
	if(ans == solve(y + 1, 0, c, r))
		build(y + 1, 0, c, r);
	else {
		 for(int i = 1; i <= 5; i++) {
			  int k = (1 << (i-1));
			  if(mask & k) continue;
			  if(!qtd[y][i]) continue;
			  if(ans == qtd[y][i] + solve(y, mask | k, c + ((i==r)?0:1), i)) {
				   for(int j = 0; j < who[y][i].size(); j++)
					   printf("%s\n", name[who[y][i][j]]);
					build(y, mask | k, c + ((i==r)?0:1), i);
					break;
			  }
		 }
	}


}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
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
	}
	return 0;
}

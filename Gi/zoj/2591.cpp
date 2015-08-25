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

int n, gYear;
vector<int> info[150][6];
int memo[150][35][7][7];
char names[2005][110];

ll max(ll a, ll b) { if(a > b) return a; return b; }

int solve(int y, int mask, int lst, int qtd){
	if(y > gYear) return 0; 
	int &m = memo[y][mask][lst][qtd];
	if(m != -1) return m;
	int ans = 0;
	for(int i = 0; i < 5; i++){
		int k = 1 << i;
		if(mask & k) continue;
		if(info[y][i+1].empty()) continue;
		if(qtd + (lst != i + 1) <= 6)
			ans = max(ans, info[y][i+1].size() + solve(y, mask | k, i + 1, qtd + (lst != i + 1)));		
	}
	ans = max(ans, solve(y + 1, 0, lst, qtd));
	return m = ans;
}

void build(int y, int mask, int lst, int qtd){
	if(y > gYear) return;
	bool found = false;
	int ans = solve(y, mask, lst, qtd);
	for(int i = 0; i < 5; i++){
		int k = 1 << i;
		if(mask & k) continue;
		if(info[y][i+1].empty()) continue;
		if(qtd + (lst != i + 1) <= 6)
			if(ans == info[y][i+1].size() + solve(y, mask | k, i + 1, qtd + (lst != i + 1))) {
				for(int j = 0; j < info[y][i+1].size(); j++)
					printf("%s\n", names[info[y][i+1][j]]);
				build(y, mask | k, i + 1, qtd + (lst != i + 1));
				found = true;
				break;
			}
	}
	if(!found && ans == solve(y + 1, 0, lst, qtd)) build(y + 1, 0, lst, qtd);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		memset(memo, -1, sizeof memo);
		for(int i = 0; i < 150; i++) for(int j = 0; j < 6; j++) info[i][j].clear();
		gYear = 0;
		scanf("%d", &n);
		getchar();
		for(int i = 0; i < n; i++){
			int c = 0;
			scanf(" %c", &names[i][c++]);
			while(42){
				scanf("%c", &names[i][c++]);
				if(names[i][c-1] == '\"') break;
			}
			names[i][c] = '\0';
			int year, reg;
			scanf("%d %d", &year, &reg);
			year -= 1870;
			gYear = max(gYear, year);
			info[year][reg].pb(i);
		}
		printf("%d\n", solve(0, 0, 0, 0));
		build(0, 0, 0, 0);
		if(t > 0) putchar('\n');
	}
	return 0;
}

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
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif

int conf[15], fix[15];
char star[7][10];

bool check() {
	int ver[6][4];
	ver[0][0]=1; ver[0][1]=2; ver[0][2]=3; ver[0][3]=4;
	ver[1][0]=0; ver[1][1]=2; ver[1][2]=5; ver[1][3]=7;
	ver[2][0]=0; ver[2][1]=3; ver[2][2]=6; ver[2][3]=10;
	ver[3][0]=7; ver[3][1]=8; ver[3][2]=9; ver[3][3]=10;
	ver[4][0]=1; ver[4][1]=5; ver[4][2]=8; ver[4][3]=11;
	ver[5][0]=4; ver[5][1]=6; ver[5][2]=9; ver[5][3]=11;

	for(int i=0; i<6; i++) {
		int sum=0;
		for(int j=0; j<4; j++)
			sum+=conf[ver[i][j]];
		if(sum!=26) {
			//printf("False\n");
			return false;
		}
	}
		
	return true;
}

int memo[15][5000];
bool a=false;
int resp[15];
bool solve(int i, int mask) {
	if(i==12) {
		if(check()) {
			if(!a && conf[0] && conf[1]) {
				for(int i=0; i<12; i++) {
					resp[i]=conf[i];
					//printf("[%d] = %d\n", i, conf[i]);
				}
				return a = true;
			}
			return false;
		}
		return false;
	}
	int m = 0;
	//int &m=memo[i][mask];
	//if(m!=-1) return m;
	if(fix[i]) return m=solve(i+1, mask);
	else {
		for(int k=11; k>=0; k--) {
			int g=1<<k;
			if(mask&g) continue;
			conf[i]=12-k;
			if(solve(i+1, mask|g))
				return m=true;
		}
	}
	return m=false;
}


int main() {
	while (true) {
		a=false;
		memset(fix, 0, sizeof fix);
		memset(memo, -1, sizeof memo);
		int count=0, inimask=0;
		for(int i=0; i<5; i++) {
			for(int j=0; j<9; j++) {
				if (scanf(" %c", &star[i][j])==EOF) return 0;
				char c=star[i][j];
				if(c=='.') continue;
				if(c>='A' && c<='Z') {
					fix[count]=1;
					inimask=inimask|(1<<(12-(c-'A'+1)));
					//printf("c=%c-inimask=%d\n", c, 1<<(12-(c-'A'+1)));
					conf[count]=c-'A'+1;
				}
				count++;
			}
		}
		//conf[0]=6;
		//printf("Solve=%d\n", solve(1, inimask|(1<<6)));
		bool ans =solve(0, inimask);
		//bool ans=solve(0, inimask);
		count=0;
		for(int i=0; i<5; i++) {
			for(int j=0; j<9; j++) {
				if(star[i][j]=='.')
					printf(".");
				else {
					printf("%c", resp[count]+'A'-1);
					count++;
				} 	
			}
			printf("\n");
		}
	}
	return 0;
}

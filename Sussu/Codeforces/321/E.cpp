
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

const int MAXN = 4123, INF = 0x3f3f3f3f;

int n, k;

int m[MAXN][MAXN], dp[MAXN][MAXN], sum[MAXN][MAXN];

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

int gond(int i, int j){
	return sum[j][j] + sum[i-1][i-1] - sum[i-1][j] - sum[j][i-1];
}

void go(int i, int j, int opti, int optj, int g){
	if(i > j) return;
	int opt = opti;
	int m = (i+j)/2;
	for(int a=opti;a<=min(m, optj);a++){
		if(dp[m][g] >= dp[a-1][g-1] + gond(a, m)){
			opt = a;
			dp[m][g] = dp[a-1][g-1] + gond(a, m);
		}
	}
	go(i, m-1, opti, opt, g);
	go(m+1, j, opt, optj, g);
}

int main (){
	scanf("%d%d", &n, &k);
	memset(dp, INF, sizeof(dp));
	int tot = 0;
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
			m[a][b] = readInt();
			sum[a][b] = sum[a-1][b] + sum[a][b-1] - sum[a-1][b-1] + m[a][b];
			tot += m[a][b];
		}
	}
	for(int a=1;a<=n;a++){
		dp[a][1] = sum[a][a];
	}
	for(int g = 2;g <= k;g++){
		go(1, n, 1, n, g);
	}
	printf("%d\n", dp[n][k]/2);
}

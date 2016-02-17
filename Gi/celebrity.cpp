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
const int MAX = 26;

int N, np;
int v[MAX], prec[2000][MAX];

void brute(int i, int j) {
	if(i == N/2) {
		for(int k = 0; k < i; k++)
			prec[np++][k] = p[k];  
		return;
	}
	if(j == N) return;
	p[i] = v[j];
	brute(i+1, j+1);
	brute(i, j+1);
}

int main() {
	int i, j;
	while(42) {
		scanf("%d", &N);
		if(!N) break;
		for(i = 0; i < n; i++)
			scanf("%d", &v[i]);
		brute(0, 0);
		for(i = 0; i < np; i++) {
			for(j = 0; j < N/2; j++)
				printf("%d ", prec[i][j]);
			putchar('\n');
		}
	}
	return 0;
}

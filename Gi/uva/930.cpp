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

int n, N;
int tab[10][10];

bool isCorner(int pos) {
	int i = pos / N; i++;
	int j = pos % N; j++;
	return !(i % n) && !(j % n);
}

int mark[10];
bool brute(int pos) {
	int i = pos / N;
	int j = pos % N;
	if(i && !j) {
	//	puts("Checando linha");
		memset(mark, 0, sizeof mark);
		for(int k = 0; k < N; k++)
			mark[tab[i-1][k]] = 1;
		for(int k = 1; k <= N; k++)
			if(!mark[k]) return false;
	}
	if(i == N - 1 && j) {
	//	puts("Checando coluna");
		memset(mark, 0, sizeof mark);
		for(int k = 0; k < N; k++)
			mark[tab[k][j-1]] = 1;
		for(int k = 1; k <= N; k++)
			if(!mark[k]) return false;
	}
	if(pos && isCorner(pos-1)) {
	//	puts("Checando bordas");
		memset(mark, 0, sizeof mark);
		int ii = (pos - 1) / N;
		int jj = (pos - 1) % N;
		for(int k = ii - n + 1; k <= ii; k++)
			for(int l = jj - n + 1; l <= jj; l++)
				mark[tab[k][l]] = 1;
		for(int k = 1; k <= N; k++)
			if(!mark[k]) return false;
				
	}
	if(pos == N * N) {
//		puts("Terminei o tabuleiro");
		for(int k = 0; k < N; k++) {
			for(int l = 0; l < N; l++) {
				printf("%d", tab[k][l]);
				if(l != N - 1) putchar(' ');
			}
			putchar('\n');
		}
		return true;
	}
	if(tab[i][j])
		return brute(pos + 1);
	for(int dig = 1; dig <= 9; dig++) {
		tab[i][j] = dig;
		if(brute(pos+1)) return true;
	}
	tab[i][j] = 0;
	return false;
}

int main() {
	while(scanf("%d", &n) != EOF) {
		N = n*n;
		for(int i = 0; i < N; i++) 
			for(int j = 0; j < N; j++) 
				scanf("%d", &tab[i][j]);
		puts("Lido");
		if(!brute(0)) puts("NO SOLUTION");
	}
	return 0;
}

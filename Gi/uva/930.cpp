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
	if(pos == N * N) {
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
		return brute(pos+1);
	
	int mm[10];
	memset(mm, 0, sizeof mm);
	for(int k = 0; k < N; k++)
		mm[tab[k][j]] = 1;
	for(int k = 0; k < N; k++)
		mm[tab[i][k]] = 1;
	int x = i - (i%n);
	int y = j - (j%n);
	for(int k = x; k < x + n; k++)
		for(int l = y; l < y + n; l++)
			mm[tab[k][l]] = 1;
	for(int dig = 1; dig <= N; dig++) {
		if(mm[dig]) continue;
		tab[i][j] = dig;
		if(brute(pos+1)) return true;
	}
	tab[i][j] = 0;
	return false;
}

int main() {
	int um = 0;
	while(scanf("%d", &n) != EOF) {
		if(um) putchar('\n');
		N = n*n;
		for(int i = 0; i < N; i++) 
			for(int j = 0; j < N; j++) 
				scanf("%d", &tab[i][j]);
		int mm[10]; 
		memset(mm, 0, sizeof mm);
		bool stop = false;
		for(int i = 0; i < N; i++) 
			for(int j = 0; j < N; j++)
				mm[tab[j][i]] = 1;
		for(int i = 1; i <= N && !stop; i++)
			if(mm[i] > 1) {  puts("NO SOLUTION"); stop = true; }
		if(stop) continue;

		memset(mm, 0, sizeof mm);
		for(int i = 0; i < N; i++) 
			for(int j = 0; j < N; j++)
				mm[tab[j][i]] = 1;
		for(int i = 1; i <= N && !stop; i++)
			if(mm[i] > 1) {  puts("NO SOLUTION"); stop = true; }
		if(stop) continue;

		if(!brute(0)) puts("NO SOLUTION");
		um++;
	}
	return 0;
}

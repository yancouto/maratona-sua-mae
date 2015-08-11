//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
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

int main(){
	int t, s, q;
	scanf("%d %d %d", &t, &s, &q);
	int tme = 0;
	int carga = 0;
	int resp = 0;
	while(tme < t){
		tme++;
		carga++;
		if(carga > 1) s++;
		if(carga == q) carga = 0;
		if(tme > s){ resp++; tme = 1; } 
	}
	printf("%d\n", resp + 1);
	return 0;
}

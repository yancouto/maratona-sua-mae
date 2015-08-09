
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
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

int n;
int reg[105], sreg[105], acc[105];
int seen[1000005];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int a; char c;
		scanf(" %c %d", &c, &reg[i]);
		if(c == '+') {
			sreg[i] = 1;
			seen[reg[i]] = 1;
		}
		else sreg[i] = 0;
	}
	for(int i = n-1; i >= 0; i--){
		acc[i] = acc[i+1];
		if(!sreg[i]){
			bool found = false;
			for(int j = 0; j < i && !found; j++)
				if(reg[i] == reg[j] && sreg[j])
					found = true;
			if(!found)
				acc[i]++;
		}	
	}
	int cur = acc[0];
	//printf("curr=%d\n", cur);
	int cap = cur;
	for(int i = 0; i < n; i++){
		if(sreg[i]) {
			cur++;
			cap = max(cap, cur);
		} else cur--; 
	}
	printf("%d\n", cap);
	
	return 0;
}

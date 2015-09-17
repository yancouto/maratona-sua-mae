//#include <bits/stdc++.h>

#include <cstdio>
#include <algorithm>
#include <cstring>
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
int aloha;
int n;

int main(){
	scanf("%d", &n);
	if(n < 4) puts("NO");
	else{
		puts("YES");
		if(n == 5){
			puts("1 + 2 = 3");
			puts("5 - 3 = 2");
			puts("3 * 4 = 12");
			puts("12 * 2 = 24");
		}else{
			puts("3 * 4 = 12");
			if(n > 4){
				puts("1 + 5 = 6");
				puts("6 - 6 = 0");
				for(int i = 7; i <= n; i++)
					printf("%d * 0 = 0\n", i);
				puts("0 + 2 = 2");
			}
			else
				puts("2 * 1 = 2");
			puts("2 * 12 = 24");
			
		}
	}
	return 0;
}

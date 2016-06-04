
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
int main() {
	ll i, j, n;
	cin >>n>> i>> j;
	if (i < n && j < 0){
		i = n + n-i;
		j *= -1;
	}
	else if(i < n && j >= 0) {
		puts("NO");
		return 0;
	}
	else if(i > n && j <=0){
		puts("NO");
		return 0;
	}
	if(j == 0){
		if(n == i)
			puts("YES");
		else
			puts("NO");
		return 0;
	}
	if((i-n)%j == 0)
		puts("YES");
	else
		puts("NO");
}

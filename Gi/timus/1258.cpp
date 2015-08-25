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

int main(){
	int w, d, x0, y0, x1, y1;
	char col[1005];
	scanf("%d %d %d %d %d %d\n", &w, &d, &x0, &y0, &x1, &y1);
	scanf("%s", col);
	
	int v = 0, h = 0;
	int lfb = 0, llr = 0;
	for(int i = 0; col[i] != '\0'; i++){
		bool fb = false, lf = false;
		if(col[i] == 'F' || col[i] == 'B') fb = true;
		if(col[i] == 'L' || col[i] == 'R') lf = true;
		if(fb) v++; else h++;
		if(!lfb && fb) lfb = (col[i] == 'F')?-1:1;
		if(!llr && lf) llr = (col[i] == 'L')?-1:1;
	}
	if(h % 2) x1 = w - x1;
	if(v % 2) y1 = d - y1;
	x1 += llr * h * w;
	y1 += lfb * v * d;
	printf("%.4f\n", sqrt((ll)(x1 - x0) * (ll)(x1 - x0) + (ll)(y1 - y0) * (ll)(y1 - y0)));
	return 0;
}

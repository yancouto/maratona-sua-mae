//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
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
#define eps 10e-6
int a[200010];

double min(double a, double b){
	if(a < b) return a;
	return b;
}

int main(){
	int n;
	double w;
	scanf("%d %lf", &n, &w);
	for(int i = 0; i < 2*n; i++)
		scanf("%d", &a[i]);
	sort(a, a+2*n);
	double dose = w/(ld)(3*n);
	dose = min(dose, a[0]);
	dose = min(dose, a[n]/2.0);
	printf("%.10f\n", dose*3.0*n);
	return 0;
}

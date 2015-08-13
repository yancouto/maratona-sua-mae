//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
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

int seen[100005];
int seenc[100005];
struct Item{
	int ind, v;
};

bool myfunction(Item a, Item b){
	if(a.v == b.v) return a.ind < b.ind;
	return a.v < b.v;
}
bool myfunction2(Item a, Item b){
	return a.ind < b.ind;
}
int main(){
	int n;
	Item a[100005];
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i].v);
		a[i].ind = i;
		seen[a[i].v]++;
	}
	sort(a, a+n, myfunction);
	vector<int> vec;
	for(int i = 1; i <= n; i++)
		if(!seen[i]) vec.pb(i);
	int v = 0;
	for(int i = n-2; i >= 0 && v < vec.size(); i--)
		if(a[i].v == a[i+1].v) a[i].v = vec[v++];
	if(v != vec.size())
		for(int i = n-1; i >= 0 && v < vec.size(); i--){
			if(a[i].v > n || seenc[a[i].v]) a[i].v = vec[v++];
			seenc[a[i].v] = 1;
		}
	sort(a, a+n, myfunction2);
	for(int i = 0; i < n; i++)
		printf("%d ", a[i].v);
	printf("\n");
	return 0;
}

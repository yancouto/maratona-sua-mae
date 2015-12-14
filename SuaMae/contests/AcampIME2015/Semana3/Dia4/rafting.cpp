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

int ni, no;
vector< pair<int, int> > inr, out;

double min(double a, double b) {
	 if(a < b) return a;
	 return b;
}

double calc() {
	double ret = 1000000000;
	for(int i = 0; i < inr.size(); i++) {	
		for(int j = 0; j < out.size(); j++) {
			double d = (inr[i].fst - out[j].fst)*(inr[i].fst - out[j].fst) + (inr[i].snd - out[j].snd)*(inr[i].snd - out[j].snd);
			ret = min(ret, d);
		}
	}
	for(int i = 0; i < inr.size(); i++) {
		for(int j = 0; j < out.size(); j++) {
			double cl, ca;
			double cap, clp;
			double x, y;
			bool here = false;

			int j1 = (j+1) % out.size();
			if(out[j].fst == out[j1].fst) {
				 ca = 1.0;
				 cl = out[j].fst;
				 cap = 0.0;
				 clp = inr[i].snd;
				 x = out[j].fst;
				 y = inr[i].snd;
				 here = true;
			}
			else {
				ca = (out[j].snd - out[j1].snd)/(out[j].fst - out[j1].fst);
				cl = (out[j].snd - ca*(out[j].fst)); 
			}
			if(!ca) {
				cap = 1.0;
				clp = inr[i].fst;
				x = inr[i].fst;
				y = out[j].snd;
			}
			else if(!here){
				cap = -1.0/ca;
				clp = (inr[i].snd - cap*(inr[i].fst));
				x = (clp-cl)/(ca-cap);
				y = ca*x + cl;
			}
			if((x >= out[j].fst && x <= out[j1].fst && y >= out[j].snd && y <= out[j1].snd) || (x >= out[j1].fst && x <= out[j].fst && y >= out[j1].snd && y <= out[j].snd)) {
				 double d = (x-inr[i].fst)*(x-inr[i].fst) + (y-inr[i].snd)*(y-inr[i].snd);
				 ret = min(ret, d);
			}
		}
	}

	for(int i = 0; i < out.size(); i++) {
		for(int j = 0; j < inr.size(); j++) {
			double cl, ca;
			double clp, cap;
			double x, y;
			bool here = false;
			int j1 = (j+1) % inr.size();
			if(inr[j].fst == inr[j1].fst) {
				 ca = 1.0;
				 cl = inr[j].fst;
				 cap = 0.0;
				 clp = out[i].snd;
				 x = inr[j].fst;
				 y = out[i].snd;
				 here = true;
			}
			else {
				ca = (inr[j].snd - inr[j1].snd)/(inr[j].fst - inr[j1].fst);
				cl = (inr[j].snd - ca*(inr[j].fst)); 
			}
			if(!ca) {
				cap = 1.0;
				clp = out[i].fst;
				x = out[i].fst;
				y = inr[j].snd;
			}
			else if(!here){
				cap = -1.0/ca;
				clp = (out[i].snd - cap*(out[i].fst));
				x = (clp-cl)/(ca-cap);
				y = ca*x + cl;
			}
			if((x >= inr[j].fst && x <= inr[j1].fst && y >= inr[j].snd && y <= inr[j1].snd) || (x >= inr[j1].fst && x <= inr[j].fst && y >= inr[j1].snd && y <= inr[j].snd)) {
				 double d = (x-out[i].fst)*(x-out[i].fst) + (y-out[i].snd)*(y-out[i].snd);
				 ret = min(ret, d);
			}
		}
	}
	return ret;
}

int main() {
	 int t;
	 scanf("%d", &t);
	 while(t--) {
		inr.clear(); out.clear();
		scanf("%d", &ni);
		for(int i = 0; i < ni; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			inr.pb(make_pair(a, b));
		}
		scanf("%d", &no);
		for(int i = 0; i < no; i++) {
			 int a, b;
			 scanf("%d %d", &a, &b);
			 out.pb(make_pair(a, b));
		}
		printf("%.7f\n", sqrt(calc())/2.0);
	 }
	 return 0;
}

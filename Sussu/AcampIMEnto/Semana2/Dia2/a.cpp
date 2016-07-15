#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;
const int MAX = 512;

int n;
double x[MAX], y[MAX];

inline int cmp(const double &x, const double &y, const double tol = 1e-7){
	return (x <= y+tol) ? (x + tol < y) ? -1 : 0 : 1;
}

double atw(double y, double x){
	double ang = atan2(y, x);
	if(cmp(ang, 0.0) == -1) return 2.0*M_PI+ang;
	else return ang;
}

int main(){
	while(scanf(" %d", &n) == 1 && n > 0){
		double tang = 0.0;
		for(int i=0;i<n;i++){
			scanf(" %lf %lf", &x[i], &y[i]);
			
			if(i > 0){
				tang += atw(y[i]-y[i-1], x[i]-x[i-1]);
			}
		}
		while(cmp(tang, 2.0*M_PI) == 1) tang -= 2.0*M_PI;
		
		if(n == 1){
			printf("%lf\n%lf\n%lf %lf\n", 0.0, 0.0, x[0], y[0]);
			continue;
		}
		
		double giro = -tang/(double)(n-1), giro2 = (2*M_PI-tang)/(double)(n-1);		
		if(cmp(giro, 0.0) == -1) giro= 2.0*M_PI + giro;
		if(cmp(giro2, giro) == -1) giro = giro2;
		
		printf("%lf\n%lf\n", 0.0, giro);
		for(int i=0;i<n;i++){
			double r = sqrt(x[i]*x[i] + y[i]*y[i]);
			double nang = atw(y[i], x[i])+giro;
			printf("%lf %lf\n", r*cos(nang), r*sin(nang));
		}
		printf("\n");
	}
	return 0;
}

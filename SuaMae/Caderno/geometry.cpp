#include <cmath>
template<typename num> struct point {
	num x, y;
	point() {}
	point(num a, num b) : x(a), y(b) {}
	point operator + (point o) const { return point(x + o.x, y + o.y); }
	point operator - (point o) const { return point(x - o.x, y - o.y); }
	num operator * (point o) const { return x * o.x + y * o.y; }
	num operator ^ (point o) const { return x * o.y - y * o.x; }
	point operator * (num i) const { return point(x * i, y * i); }
	point operator / (num i) const { return point(x / i, y / i); }
	point<double> rotate(double deg) {
		double cs = cos(deg), sn = sin(deg);
		return point<double>(x*cs - y*sn, x*sn + y*cs);
	}
	num distSqr(point o) const { return (*this - o) * (*this - o); }
	bool operator < (point o) const { return x < o.x || (x == o.x && y < o.y); }
};
template<typename num> double distSegSqr(point<num> a, point<num> b, point<num> c) {
	if((b - a) * (c - b) > 0) return b.distSqr(c);
	if((a - b) * (c - a) > 0) return a.distSqr(c);
	double d = (b - a) ^ (c - a);
	return d * d / ((b - a) * (b - a));
}

template <typename num> struct line {
	num a, b, c;
	line() {}
	line(num aa, num bb, num cc) : a(aa), b(bb), c(cc) {}
	line(point<num> s, point<num> e) : a(e.y - s.y), b(e.x - s.x), c(a*s.x + b*s.y) {}
	line pass(point<num> p) { return line(a, b, a*p.x + b*p.y); }
	point<double> inter(line o) {
		double d = a * o.b - o.a * b;
		if(d == 0) return point<double>(0, 0); //fudeu
		return point<double>((o.b * c - b * o.c)/d, (a * o.c - o.a * c)/d);
	}
};
typedef point<int> pointi;
typedef point<double> pointd;
typedef line<int> linei;
typedef line<double> lined;

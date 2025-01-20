/**
 * Author: Takanori MAEHARA, chilli
 * Date: 2019-11-03
 * License: CC0
 * Source: https://github.com/spaghetti-source/algorithm/blob/master/geometry/_geom.cc#L729
 * Description: Calculates the area of the intersection of 2 circles
 * Status:
 */

//const double PI = acos(-1);
template<class P>
double circleCircleArea(P c, double cr, P d, double dr) {
	if (cr < dr) swap(c, d), swap(cr, dr);
	auto A = [&](double r, double h) {
		// h = min(h, r); // just in case
		return r*r*acos(h/r)-h*sqrt(r*r-h*h);
	};
	auto l = (c - d).dist(), a = (l*l + cr*cr - dr*dr)/(2*l);
	if (l - cr - dr >= 0) return 0; // far away
	if (l - cr + dr <= 0) return PI*dr*dr;
	if (l - cr >= 0) return A(cr, a) + A(dr, l-a);
	else return A(cr, a) + PI*dr*dr - A(dr, a-l);
}


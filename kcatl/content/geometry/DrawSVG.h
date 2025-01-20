/**
 * Author: ITMO
 * Date: 2023-11-20
 * License: CC0
 * Source: ITMO notebook
 * Description: Draws geometrical objects (line, circles, text) on an SVG image.
 * Change the colors and parameters at will. Open the output image file in a browser.
 * Usage: svg.open(); svg.circle(point(0, 0), 0.3); svg.close();
 * Status: tested
 */
#pragma once

#include "Point.h"

typedef Point<double> point;
struct SVG { // other colors: green, purple, yellow, ...
	FILE *out;
	double sc = 50; // scaling factor
	void open() {
		out = fopen("image.svg", "w");
		fprintf(out, "<svg xmlns='http://www.w3.org/2000/svg' viewBox='-1000 -1000 2000 2000'>\n");
	}
	void line(point a, point b) {
		a = a * sc, b = b * sc;
		fprintf(out, "<line x1='%f' y1='%f' x2='%f' y2='%f' stroke='blue'/>\n", a.x, -a.y, b.x, -b.y);
	}
	void circle(point a, double r) {
		a = a * sc; r *= sc;
		fprintf(out, "<circle cx='%f' cy='%f' r='%f' stroke='black' fill='red'/>\n", a.x, -a.y, r);
	}
	void text(point a, string s) {
		a = a * sc;
		fprintf(out, "<text x='%f' y='%f' font-size='50px'>%s</text>\n", a.x, -a.y, s.c_str());
	}
	void close() {
		fprintf(out, "</svg>\n");
		fclose(out);
		out = 0;
	}
	~SVG() {if (out) close();}
} svg;

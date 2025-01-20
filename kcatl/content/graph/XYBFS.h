/**
 * Author: Tomatoes
 * Date: 2015-02-23
 * License: CC0
 * Source: Tomatoes
 * Description: Use queue to find shortest path from single source when all edges have weight $W = X$ or $W = Y$ $(X, Y \geq 0)$
 * Time: O(N + M)
 * Status: idk
 */
#pragma once

queue QX , QY
push source S to QX
	while one of the two queues is not empty:
	u = pop minimal distant node among the two queue heads
		for all edges e of form (u, v):
			if dist(v) > dist(u) + cost(e):
			dist(v) = dist(u) + cost(e);
			if cost(e) == X:
				QX.push(dist(v), v);
			else:
				QY.push(dist(v), v);

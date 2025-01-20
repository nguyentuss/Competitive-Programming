#include <vector>
#include <iostream>
#include <queue>


void dijkstra(){
	priority_queue<ii , vector <ii> , greater <ii>>;
	for (....)
		d[i] = oo;
	d[1] = 0;
	q.push(ii(0,1))

	while (!.empty())
	{
		u = ...top().second;
		du = ...top().first;
		if (du != d[u]) continue; 
		for (...size())
		{
			v = graph[u][i].second;
			uv = graph[u][i].first;
			if (d[v] > uv + du)
				dv = uv + du;
				q.push(ii(d[v],v))
		}
	}
}
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int is_visited[1002];
vector<int> g[1002];

void dfs(int start)
{
	if (is_visited[start])
		return ;

	
	is_visited[start] = 1;
	cout<<start<<" ";

	for(int i=0; i<g[start].size(); i++)
	{
		dfs(g[start][i]);
	}
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	is_visited[start] = 1;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		cout<<v<<" ";
		for(int i=0; i< g[v].size(); i++)
		{
			int tmp = g[v][i];
			if (!is_visited[tmp]) 
			{
				q.push(tmp);
				is_visited[tmp] = 1;
			}
		}
	}
}

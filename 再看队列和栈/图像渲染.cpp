#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

//广度优先搜索
class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		vector<vector<int>>visited(image.size(),vector<int>(image[0].size(),0));
		visited[sr][sc] = 1;

		int row = image.size();
		int column = image[0].size();

		queue<int>queue;
		queue.push(sr*column+sc);

		while (!queue.empty())
		{
			int size = queue.size();
			for (int i = 0; i < size; i++)
			{
				int top = queue.front();
				queue.pop();

				int x = top%column;
				int y = (top-x)/column;
				//点的上方
				if (y-1 >= 0 && image[y-1][x] == image[sr][sc] && !visited[y-1][x])
				{
					image[y-1][x] = newColor;
					queue.push(x+(y-1)*column);
					visited[y - 1][x] = 1;
				}
				//点的下方
				if (y+1 <= row-1 && image[y+1][x] == image[sr][sc] && !visited[y+1][x])
				{
					image[y+1][x] = newColor;
					queue.push(x + (y+1)*column);
					visited[y + 1][x];
				}
				//点的左方
				if (x-1 >= 0 && image[y][x-1] == image[sr][sc] && !visited[y][x-1])
				{
					image[y][x-1] = newColor;
					queue.push(x-1 + y*column);
					visited[y][x - 1];
				}
				//点的右方
				if (x+1 <= column-1 && image[y][x+1] == image[sr][sc] && !visited[y][x+1])
				{
					image[y][x+1] = newColor;
					queue.push(x+1 + y*column);
					visited[y][x + 1];
				}
			}
		}
		image[sr][sc] = newColor;
		return image;
	}
};

int main()
{
	vector<int>vec1 = { 0,0,1 };
	vector<int>vec2 = { 1,0,0 };
	vector<vector<int>>test(2,vector<int>(3,0));
	test[0] = vec1;
	test[1] = vec2;
	Solution*s = new Solution;
	s->floodFill(test, 1, 0, 2);
	return 0;
}

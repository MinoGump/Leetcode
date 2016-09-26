#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		int m = matrix.size(), n;
		if (m != 0)n = matrix[0].size();
		int cycle = m > n ? (n + 1) / 2 : (m + 1) / 2;//环的数目
		vector<int>res;

		int a = n, b = m;//a,b分别为当前环的宽度、高度
		for (int i = 0; i < cycle; i++, a -= 2, b -= 2)
		{
			//每个环的左上角起点是matrix[i][i],下面顺时针依次打印环的四条边
			for (int column = i; column < i + a; column++)
				res.push_back(matrix[i][column]);
			for (int row = i + 1; row < i + b; row++)
				res.push_back(matrix[row][i + a - 1]);
			if (a == 1 || b == 1)break; //最后一个环只有一行或者一列
			for (int column = i + a - 2; column >= i; column--)
				res.push_back(matrix[i + b - 1][column]);
			for (int row = i + b - 2; row > i; row--)
				res.push_back(matrix[row][i]);
		}
		return res;
	}
};

int main() {
	Solution s;
	int num[3][3] = { { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } };
	vector<vector<int> > matrix;
	matrix.push_back(vector<int>(num[0], num[0] + 3));
	matrix.push_back(vector<int>(num[1], num[1] + 3));
	matrix.push_back(vector<int>(num[2], num[2] + 3));
	vector<int> result = s.spiralOrder(matrix);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}

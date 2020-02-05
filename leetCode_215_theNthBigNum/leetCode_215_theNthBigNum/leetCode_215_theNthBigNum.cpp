// leetCode_215_theNthBigNum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		//创建最小堆
		priority_queue<int, vector<int>, greater<int> > smallQ;

		for (int i = 0; i < nums.size(); i++)
		{
			//如果最小堆中的元素的个数少于K个，那么可以直接将元素入堆
			if (smallQ.size() < k)
			{
				smallQ.push(nums[i]);
			}
			else
			{
				//当堆中元素多余K个时
				//如果堆顶的元素大于新的元素，则将堆顶元素弹出，将新元素放入堆中
				if (smallQ.top() < nums[i])
				{
					smallQ.pop();
					smallQ.push(nums[i]);
				}
				//如果堆顶元素小于新的元素，则不做操作
				//最后保证最小堆中的K个元素就是数组中最大的K个元素
				//堆顶的就是数组中第K大的元素
			}
		}
		return smallQ.top();
	}
};

int main()
{
	vector<int> nums = { 3, 2, 1, 5, 6, 4 };
	int k = 2;
	Solution solution;
	int result = solution.findKthLargest(nums, k);
	cout << result;
	system("pause");
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

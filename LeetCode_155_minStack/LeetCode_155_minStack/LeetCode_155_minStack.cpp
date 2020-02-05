// LeetCode_155_minStack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stack>

using namespace std;




class MinStack
{
	public:
		MinStack();
		~MinStack();

		void push(int x) 
		{
			origin_Stack.push(x);
			if (min_Stack.empty())
			{
				min_Stack.push(x);
			}
			else
			{
				if (x>min_Stack.top())
				{
					x = min_Stack.top();
					
				}
				//这个放到外面  放里面的时候  x比min_Stack栈顶小的话就不执行了
				min_Stack.push(x);
			}
		}

		void pop()
		{
			origin_Stack.pop();
			min_Stack.pop();

		}

		int top()
		{
			return origin_Stack.top();
		}

		int getMin()
		{
			return min_Stack.top();
		}


	private:
		//为了保证取最小值的方法的时间复杂度为常数，增加min_Stack，用来记录栈中的最小值，栈顶始终为当前栈中元素的最小值
		//只有当新进的元素小于min_Stack的栈顶元素时，才将新进元素放入min_Stack，否则min_Stack始终放入原来的栈顶元素
		//当出栈时，origin_Stack和min_Stack同时出栈，能够保证当前min_Stack栈顶的元素任然是栈中剩余元素的最小值
		stack<int> origin_Stack, min_Stack;	
		

};

MinStack::MinStack()
{
}

MinStack::~MinStack()
{
}





int main()
{
	MinStack minStack;
	minStack.push(3);
	cout << minStack.getMin() << endl;
	minStack.push(1);
	cout << minStack.getMin() << endl;
	minStack.push(4);
	cout << minStack.getMin() << endl;
	minStack.push(4);
	cout << minStack.getMin() << endl;
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

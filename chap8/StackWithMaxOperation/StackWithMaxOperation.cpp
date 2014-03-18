// 8.1 Stack with max operation

#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

// TODO
class MaxStack
{
	public:
		MaxStack(int c) : top(-1), size(0), capacity(c), data(vector<int>(c)) {}

	pivate:
		int top;
		int size;
		int capacity;
		vector<int> data;
};

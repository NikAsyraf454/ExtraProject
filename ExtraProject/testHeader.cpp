#include"GameLibHeader.h"

const int max_size = 10;

int main()
{
	int count = 0;							//used to track the number of data in the list
	//intialize
	Stack stack(max_size);					//to set the maximum size of the list

	cout << "Testing Stack" << endl;

	stack.Show(count);

	for (int i = 0; count < stack.max_size; i++)
	{
		stack.Add(i);
		count++;
	}

	stack.Show(count);

	cout << stack.Extract(5, count) << endl;
	count--;
	stack.Show(count);
	cout << stack.Extract(2, count) << endl;
	count--;
	cout << stack.Extract(7, count) << endl;
	count--;
	cout << stack.Extract(1, count) << endl;
	count--;
	stack.Show(count);
	return 0;
}
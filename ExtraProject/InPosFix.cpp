#include<iostream>
#include<stack>
using namespace std;

void ShowStack(stack<char> test)
{
	while (!test.empty())
	{
		cout << test.top();
		test.pop();
	}
}

stack<char> Reverse(stack<char> test3)
{
	stack<char> test;
	while (!test3.empty())
	{
		test.push(test3.top());
		test3.pop();
	}
	return test;
}

int Decide(char x)
{
	if (isalpha(x) || isdigit(x))
		return 1;
	else if (x == '(')
		return 2;
	else if (x == ')')
		return 3;
	else if (x == '^')
		return 4;
	else if (x == '*' || x == '/')
		return 5;
	else if (x == '+' || x == '-')
		return 6;
}

int main()
{
	stack<char> test, test2, test3;
	int n, a = 0, b = 0, z = 0, bodmas = 6;
	cout << "Enter number of char/digit: ";
	cin >> n;
	cout << "Enter " << n << " char/digit: ";
	for (int i = 0; i < n; i++)
	{
		char x;
		cin >> x;
		test3.push(x);
	}

	test3 = Reverse(test3);

	cout << "\nreversed test3: ";
	ShowStack(test3);
	cout << endl;
	//bodmas = Decide(test3.top());
	
	while (!test3.empty())			//condition of ')' is found
	{
		cout << "a :" << a << " b :" << b << endl;
		cout << "test: ";
		ShowStack(test);
		cout << endl;
		cout << "test2 :";
		ShowStack(test2);
		cout << endl;
		z = Decide(test3.top());

		if (bodmas < z && z > 3)
		{
			cout << "in" << endl;
			//while(test)					//while test is not empty, but if inside (), how to do it
			test2.push(test.top());
			test.pop();
			
			if (a == 0 && b == 0 && test3.empty())
			{
				cout << "in 1" << endl;
				while (!test.empty())
				{
					test2.push(test.top());
					test.pop();
				}
			}
		}
		else
		{
			cout << "in 2" << endl;
			switch (z)
			{
			case 1:
				test2.push(test3.top());
				break;
			case 2:
				test.push(test3.top());
				a++;
				bodmas = 6;					//to reset bodmas value after ()
				break;
			case 3:
				test.push(test3.top());
				b++;
				break;
			case 4: case 5: case 6:
				test.push(test3.top());
				break;
			}
			test3.pop();
		}

		if (a > 0 && b > 0)					//if '(' exist and to match up with ')'
		{
			cout << "in 3" << endl;
			test.pop();					//to delete ')'
			b--;
			while (z != 2)					//push to Answer Stack(test1)
			{
				test2.push(test.top());
				test.pop();
				z = Decide(test.top());
			}
			test.pop();					//to delete '('
			a--;
			bodmas = 6;
		}

		if (z > 3)
		{
			bodmas = z;
			cout << "bodmas: " << bodmas << endl;
		}
	} 

	while (!test.empty())
	{
		test2.push(test.top());
		test.pop();
	}
	
	cout << "\ntest2 :";
	test2 = Reverse(test2);
	ShowStack(test2);

	return 0;
}


//a+b-c*d/e^
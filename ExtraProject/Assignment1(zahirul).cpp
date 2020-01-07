#include<iostream>
#include<stack>

using namespace std;
struct penting
{
	stack<int>id;
	stack<int>price;
	stack<int>quantity;
};

struct penting2
{
	int id2;
	int price2;
	int quantity2;
};

int main() {
	int choice, count =0, pilihan,NewID, SearchID, i=0, delID, flag=0,j;
	char check;
	struct penting2 CD[10];
	stack<int> stack1;
	stack<int> stack2;

	do
	{
		flag = 0;
		cout << endl;
		cout << "0 - Exit." << endl;
		cout << "1 - Add New Item." << endl;
		cout << "2 - Delete Item." << endl;
		cout << "3 - Display Items." << endl;
		cout << "4 - Update Items." << endl;
		cout << "5 - Search Items." << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 0:
			break;

		case 1:
			if (count >= 10)
				cout << "Error memory is FULL." << endl;
			else
			{
				cout << "Enter ID 	: ";
				cin >> CD[i].id2;
				//id.push(p);
				cout << "Enter Price	:";
				cin >> CD[i].price2;
				//price.push(p);
				cout << "Enter Quantity	:";
				cin >> CD[i].quantity2;
				//quantity.push(q);
				cout << "CD " << count+1 << " inserted." << endl;
				stack1.push(i);
				count++;
			}
			cout << "Enter Y to continue	:";
			if (cin >> check && (check == 'Y' || check == 'y'))
				break;
			else
			{
				choice = 0;
				break;
			}

		case 2:
			cout << "Enter Id to be deleted: ";
			cin >> delID;
			while (!stack1.empty())
			{
				if (delID == CD[stack1.top()].id2)
				{
					stack1.pop();
					flag = 1;
				}
				else
				{
				stack2.push(stack1.top());
				stack1.pop();
				}	
			}
			while (!stack2.empty())
			{
				stack1.push(stack2.top());
				stack2.pop();
			}
			if (flag == 0)
			{
				cout << "not found";
			}
			else
			{
				cout << "CD " << delID << " has been deleted";
				count--;
			}
				

			break;

		case 3:
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				cout << "\nID " << CD[stack1.top()].id2;
				cout << "\nprice " << CD[stack1.top()].price2;
				cout << "\nquantity " << CD[stack1.top()].quantity2;
				stack1.pop();
			}
			while (!stack2.empty())
			{
				stack1.push(stack2.top());
				stack2.pop();
			}
			break;

		case 4:
			cout << "RESULT" << endl;
			cout << "Book ID: ";
			cin >> NewID;
			while (!stack1.empty())
			{
				if (NewID == CD[stack1.top()].id2)
				{
					flag = 1;
					cout << "\n1.new price";
					cout << "\n2.new quantity";
					cin >> pilihan;
					if (pilihan == 1)
					{
						cout << "Enter new value of price: ";
						cin >> CD[stack1.top()].price2;
					}
					else if (pilihan == 2)
					{
						cout << "Enter new value of quantity: ";
						cin >> CD[stack1.top()].quantity2;
					}
					else
						cout << "Invalid choice.";
				}

				stack2.push(stack1.top());
				stack1.pop();
			}
			while (!stack2.empty())
			{
				stack1.push(stack2.top());
				stack2.pop();
			}
			if (flag == 0)
			{
				cout << "not found";
			}

			break;

		case 5:
			cout << "Which element? ";
			cin >> SearchID;
			while (!stack1.empty())
			{
				if (SearchID == CD[stack1.top()].id2)
				{
					cout << "\nID " << CD[stack1.top()].id2;
					cout << "\nprice " << CD[stack1.top()].price2;
					cout << "\nquantity " << CD[stack1.top()].quantity2;
					flag = 1;
				}
				stack2.push(stack1.top());
				stack1.pop();
			}
			while (!stack2.empty())
			{
				stack1.push(stack2.top());
				stack2.pop();
			}
			if (flag == 0)
			{
				cout << "not found";
			}
			break;
		default:
			cout << "\nAn Invalid choice." << endl;
		}
		i++;
	} while (choice != 0);
	cout << "Thank you";
	return 0;

}
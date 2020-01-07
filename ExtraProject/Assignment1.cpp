#include <iostream>
#include <string>
#include <vector>
using namespace std;


class game {
	public:
		
			int ID;
			char name[50];
			float price;
			char genre[50];
			char developer[50];	
	
	

		void display() 
		{
			cout << "ID is : " << ID << endl;
			cout << "Name is : " << name << endl;
			cout << "Price is : " << price << endl;
			cout << "Genre is : " << genre << endl;
			cout << "Developed by : " << developer << endl;
		}
		
		void displayUpdate()
		{
			cout << "ID is : " << ID << endl;
			cout << "1. Name is : " << name << endl;
			cout << "2. Price is : " << price << endl;
			cout << "3. Genre is : " << genre << endl;
			cout << "4. Developed by : " << developer << endl;
		}



}; 
	
void displaymenu(void)
{
	cout << "--------------------" << endl;
	cout << " :: MENU ::" << endl << endl;
	cout << "1. Add New Record " << endl;
	cout << "2. Search Record " << endl;
	cout << "3. Display Record " << endl;
	cout << "4. Update Record " << endl;
	cout << "5. Delete Record " << endl;
	cout << "--------------------" << endl;

}
int main()
{

	int select = 1, i = 0, found = 0, DisplayID, update = 0;
	char temp[50];
	vector<int> vec;


	for (int i = 0; select != 0; i++)
	{
		displaymenu();
		game obj[100];
		cin >> select;
		if (select == 1) 
		{
			if (vec.size() != 10)
			{
				string a;
				cout << "Enter Game ID : ";
				cin >> obj[i].ID;
				cout << "Enter Game Name : ";
				cin.ignore(256, '\n');
				cin.getline(obj[i].name, 50);
				cout << "Enter Game Price : ";
				cin >> obj[i].price;
				cout << "Enter Game Genre : ";
				cin.ignore(256, '\n');
				cin.getline(obj[i].genre, 50);
				//cin.ignore(256, '\n');
				cout << "Enter Game Developer : ";

				cin.getline(obj[i].developer, 50);
				vec.push_back(i);
			}
			else 
			{
				cout << "Your memory is full! Please delete some objects";
			}
		}
		else if (select == 2) 
		{
			int search;
			cout << "Enter Game ID to search : ";
			cin >> search;
			vector<int>::iterator itr = vec.begin();
			for (itr = vec.begin(); itr != vec.end(); itr++)
			{
				i = *itr;

				if (search == obj[i].ID)
				{
					obj[i].display();
					cout << endl;
					break;
				}//tambah flag
				else
					cout << "Game ID " << search << " not found! " << endl;
			}

		}
		else if (select == 3)
		{
			vector<int>::iterator itr = vec.begin();

			cout << " ========= RECORD =========" << endl;
			for (itr = vec.begin(); itr != vec.end(); itr++)
			{
				cout << "Game " << *itr + 1 << " : " << endl;
				i = *itr;
				obj[i].display();
				cout << endl;
				cout << " ========= ****** =========" << endl;
			}
		}
		else if (select == 4)
		{
			cout << " ========= RECORD UPDATE =========\n";
			cout << "Enter ID : ";
			cin >> update;
			vector<int>::iterator itr = vec.begin();
			for (itr = vec.begin(); itr != vec.end(); itr++)
			{
				i = *itr;
				cout << "\n::Results::" << endl;
				if (update == obj[i].ID)
				{
					cout << "Current record" << endl;
					obj[i].displayUpdate();
					cout << endl;
					cout << "Enter choice to update: ";
					cin >> update;
					if (update == 1)
					{
						cout << "Enter New Game Name : ";
						cin >> obj[i].name;
					}
					else if (update == 2)
					{
						cout << "Enter New Game Price : ";
						cin >> obj[i].price;
					}
					else if (update == 3)
					{
						cout << "Enter New Game Genre : ";
						cin >> obj[i].genre;
					}
					else if (update == 4)
					{
						cout << "Enter New Game Developer : ";
						cin >> obj[i].developer;
					}
					cout << "Status: Completed";
					break;
				}//tambah flag
				else
				{
					cout << "Game ID " << update << " not found! \n";
					break;
				}
			}
			//cout << "--------------------------------"
		}
		else if (select == 5)
		{
			int del;
			char ConfirmDel;
			cout << " ========= RECORD DELETION =========\n";
			cout << "Enter ID to be deleted : ";
			cin >> del;
			vector<int>::iterator itr = vec.begin();
			for (itr = vec.begin(); itr != vec.end(); itr++)
			{
				i = *itr;
				if (del == obj[i].ID)
				{
					obj[i].display();
					cout << endl;
					cout << "Do you want to delete " << del << " ? [Y/N]";
					cin >> ConfirmDel;
					if (ConfirmDel == 'Y' || ConfirmDel == 'y')
					{
						vec.erase(itr);
					}
					break;
				}
				else
					cout << "Game ID " << del << " not found! \n";
			}
		}

	}
	return 0;
}



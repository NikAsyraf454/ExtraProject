#include <iostream>
#include <string>
#include <vector>
using namespace std;


class game {
	public:
		
			char ID[50];
			char name[50];
			float price;
			char genre[50];
			char developer[50];	
	
		void display() 
		{
			cout << "Game ID : " << ID << endl;
			cout << "Game Name : " << name << endl;
			cout << "Game Price : " << price << endl;
			cout << "Game Genre : " << genre << endl;
			cout << "Game Developed by : " << developer << endl;
		}
		
		void displayUpdate()
		{
			cout << "Game ID : " << ID << endl;
			cout << "1. Game Name  : " << name << endl;
			cout << "2. Game Price  : " << price << endl;
			cout << "3. Game Genre  : " << genre << endl;
			cout << "4. Game Developed by : " << developer << endl;
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

	int select = 1, i = 0, found = 0, DisplayID, update = 0, comp,temp;
	char cont,search[50];
	vector<int> vec;
	

	for (int i = 0; select != 0; i++)
	{

		int flag = 0;
		displaymenu();
		game obj[100];
		cin >> select;
		cin.ignore(256, '\n');
		if (select == 1) 
		{
			if (vec.size() != 3)
			{
				string a;
				cout << "Enter Game ID : ";
				//cin.ignore(256, '\n');
				cin.getline(obj[i].ID, 50);

				//**
				temp = i;
				vector<int>::iterator itr = vec.begin();
				for (itr = vec.begin(); itr != vec.end(); itr++)
				{
					i = *itr;
					if (strcmp(obj[temp].ID, obj[i].ID) == 0)
					{
						cout << "The Game ID is already exist! \n";
						flag = 1;
						break;
					}
					
				}
				if (flag == 1)
					continue;
				i = temp;
				//**

				cout << "Enter Game Name : ";
				//cin.ignore(256, '\n');
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
			
			
			cout << "Enter Game ID to search : ";
			cin.getline(search, 50);
			vector<int>::iterator itr = vec.begin();
			for (itr = vec.begin(); itr != vec.end(); itr++)
			{
				i = *itr;
				if(strcmp(search, obj[i].ID) == 0)
				{
					obj[i].display();
					cout << endl;
					flag = 1;
					break;
				}
				
					
			}
			if (flag != 1)
				cout << "Game ID " << search << " not found! " << endl;

		}
		else if (select == 3)
		{
			vector<int>::iterator itr = vec.begin();
			if (vec.size() > 0)
			{
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
			else
			{
				cout << "Record Empty";
			}
		}
		else if (select == 4)
		{
			cout << " ========= RECORD UPDATE =========\n";
			cout << "Enter ID : ";
			cin.getline(search, 50);
			vector<int>::iterator itr = vec.begin();
			for (itr = vec.begin(); itr != vec.end(); itr++)
			{
				i = *itr;
				
				if (strcmp(search, obj[i].ID) == 0)
				{
					cout << "\n::Results::" << endl;
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
					cout << "Status: Completed\n";
					flag = 1;
					
				}
				
			}
			if (flag == 0)
			{
				cout << "Game ID " << search << " not found! \n";
				
			}
			//cout << "--------------------------------"
		}
		else if (select == 5)
		{
			char ConfirmDel;
			cout << " ========= RECORD DELETION =========\n";
			cout << "Enter ID to be deleted : ";
			cin >> search;
			vector<int>::iterator itr = vec.begin();
			for (itr = vec.begin(); itr != vec.end(); itr++)
			{
				i = *itr;
				if (strcmp(search, obj[i].ID) == 0)
				{
					obj[i].display();
					cout << endl;
					cout << "Do you want to delete : " << search << " ? [Y/N]";
					cin >> ConfirmDel;
					if (ConfirmDel == 'Y' || ConfirmDel == 'y')
					{
						vec.erase(itr);
					}
					flag = 1;
					break;
				}
				
			}
			if(flag == 0)
				cout << "Game ID " << search << " not found! \n";
		
		}
		cout << "\nEnter any key to continue : ";
		cin >> cont;
		system("CLS");

	}
	return 0;
}



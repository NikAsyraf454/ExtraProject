#include<iostream>
using namespace std;

const int max_size = 10;

class Stack {

public:

	Stack(int max_size);

	int max_size;

	void Add(int data);
	int Extract(int data,int count);

	void Show(int count);

private:

	struct node {
		int data;
		node* next;
	};

	node* head;
	node* tail;

	void push(node*& head, node*& tail, int data) {
		if (head == NULL)							//if there is no data
		{
			node* n = new node;
			n->data = data;
			n->next = NULL;
			head = n;
			tail = n;
		}
		else if (head != NULL) 
		{
			node* n = new node;
			n->data = data;
			n->next = head;
			head = n;
			tail->next = head;
		}
		
	}

	void showdata(node*& head, node*& tail, int count) {	//display all data available in list
		node* temp = new node;							
		temp = head;
		if (temp == NULL) {									//if there is no data
			cout << "Empty" << endl;
		}
		else {
			cout << "element: " << endl; 
			for(int i = 0; i < count ;i++)
			{	
				cout << temp->data << endl;
				temp = temp->next;
			}
		}
		
	}

	void pop(node*& head, node*& tail,int count) 
	{
		if (head == NULL) 
		{
			cout << "Empty" << endl;
		}
		else if (head == tail) 
		{
			cout << "value: " << head->data << " was popped" << endl;
			delete head;
			head = NULL;
			tail = NULL;
		}
		else 
		{
			//cout != NULL
			node* delptr = new node;
			node* skip = new node;											//to set the number before the point to next number of the deleted number
			delptr = head;
			skip = head;
			head = head->next;
			cout << "value: " << delptr->data << " was popped" << endl;
			for(int i = 0; i < count-1; i++)								//to circulate the list
			{
				skip=skip->next;											//to find the number before the deleted number
			}
			skip->next = head;												//point the number before the deleted number to the number after deleted number
			delete delptr;													//deletes the data
		}
	}
};

Stack::Stack(int _max_size)					
{
	max_size = _max_size;		
	head = NULL;							//is set to NULL as the start of the program
	tail = NULL;
}

void Stack::Add(int data)					//call function in class(private)
{
	push(head, tail, data);
}

int Stack::Extract(int data,int count)
{
	node* temp = new node;
	temp = head;
	int a = temp->data;
	while (a != data)						//search for the exact data
	{
		temp = temp->next;
		a = temp->data;
	}
	int poppedvalue = temp->data;
	//head = temp;
	pop(temp, tail,count);					//delete the data
	
	return poppedvalue;						//can be use to delete or pop data to somewhere else
}

void Stack::Show(int count)					//call function in class(private)
{
	showdata(head,tail,count);
}



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

	cout << stack.Extract(5,count) << endl;
	count--;
	stack.Show(count);
	cout << stack.Extract(2,count) << endl;
	count--;
	stack.Show(count);
	cout << stack.Extract(7, count) << endl;
	count--;
	stack.Show(count);
	cout << stack.Extract(0, count) << endl;
	count--;
	stack.Show(count);
	return 0;
}
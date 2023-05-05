#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int value;
int pasirinkimas;
int pasirinkimas2;

struct node
{
	int data;
	node* next;
	node* prev;
};

class LinkedList
{
private:
	node* tail;
public:
	LinkedList()
	{
		tail = NULL;
	}

	void AddNodeFront(LinkedList& list)
	{
		cout << "iveskite reiksme" << endl;
		cin >> value;
		node* temp = new node;
		temp->data = value;
		if (tail == NULL)
		{
			tail = temp;
			tail->next = tail;
			tail->prev = tail;
		}
		else
		{
			temp->next = tail->next;
			temp->prev = tail;
			tail->next->prev = temp;
			tail->next = temp;
		}
		cout << "elementas pridetas!" << endl;
		system("pause");
		list.Menu(list);
	}
	void AddNodeEnd(LinkedList& list)
	{
		cout << "iveskite reiksme" << endl;
		cin >> value;
		node* temp = new node;
		temp->data = value;
		if (tail == NULL)
		{
			tail = temp;
			tail->next = tail;
			tail->prev = tail;
		}
		else
		{
			temp->next = tail->next;
			temp->prev = tail;
			tail->next->prev = temp;
			tail->next = temp;
			tail = temp;
		}
		cout << "elementas pridetas!" << endl;
		system("pause");
		list.Menu(list);
	}
	void AddNodeInsert(LinkedList& list)
	{
		int norima_pos;
		cout << "ivskite reiksme" << endl;
		cin >> value;
		cout << "ivskite pozicija" << endl;
		cin >> norima_pos;
		node* temp = new node;
		temp->data = value;
		if (tail == NULL)
		{
			cout << "Dar nera elementu, del to skaicius bus idetas i pirma pozicija" << endl;
			tail = temp;
			tail->next = tail;
			tail->prev = tail;
		}
		else
		{
			node* cur = tail->next;
			node* pre = tail;
			for (int i = 1; i < norima_pos; i++)
			{
				pre = cur;
				cur = cur->next;
			}
			if (cur == tail->next && norima_pos != 1)
			{
				temp->next = tail->next;
				tail->next = temp;
				temp->prev = tail;
				temp->next->prev = temp;
				tail = temp;
			}
			else
			{
				pre->next = temp;
				temp->next = cur;
				temp->prev = pre;
				cur->prev = temp;
			}
		}
		cout << "elementas pridetas!" << endl;
		system("pause");
		list.Menu(list);
	}

	void  DeleteNodeFront(LinkedList& list)
	{
		if (tail == NULL)
		{
			cout << "negalime istrinti!" << endl;
		}
		else
		{
			node* temp = new node;
			temp = tail->next;
			temp->next->prev = tail;
			tail->next = temp->next;
			if (temp == tail)
			{
				tail = NULL;
			}
			delete temp;
			cout << "elementas istrintas!" << endl;
		}
		system("pause");
		list.Menu(list);
	}
	void DeleteNodeEnd(LinkedList& list)
	{
		if (tail == NULL)
		{
			cout << "negalime istrinti!" << endl;
		}
		else
		{
			node* temp = tail;
			tail = tail->prev;
			if (temp == tail)
			{
				delete temp;
				tail = NULL;
			}
			else
			{
				tail->next = temp->next;
				temp->next->prev = tail;
				delete temp;
			}
			cout << "elementas istrintas!" << endl;
		}
		system("pause");
		list.Menu(list);
	}
	void DeleteNodeInsert(LinkedList& list)
	{
		int norima_pos;
		if (tail == NULL)
		{
			cout << "negalime istrinti!" << endl;
		}
		else
		{
			node* pre = tail;
			node* cur = tail->next;
			cout << "iveskite norima pozicija" << endl;
			cin >> norima_pos;
			for (int i = 1; i < norima_pos; i++)
			{
				pre = cur;
				cur = cur->next;
			}
			if (tail->next == tail)
			{
				tail = NULL;
			}
			else
			{
				if (cur == tail)
				{
					tail = pre;
					tail->next = cur->next;
					cur->next->prev = tail;
				}
				else if (norima_pos == 1 && cur != tail)
				{
					tail->next = cur->next;
					cur->next->prev = tail;
				}
				else if (tail->prev == cur)
				{
					tail->prev = cur->prev;
					cur->prev->next = tail;
				}
				else
				{
					pre->next = cur->next;
					cur->next->prev = pre;
				}
			}
			delete cur;
			cout << "elementas istrintas!" << endl;
		}
		system("pause");
		list.Menu(list);
	}

	void Search(LinkedList& list)
	{
		int pozicija = 1;
		int rado = 0;
		if (tail == NULL)
		{
			cout << "norimo skaiciaus nerasime, nes sarasas tuscias?!" << endl;
		}
		else
		{
			cout << "koki skaiciu norite surasti?" << endl;
			cin >> value;
			node* temp = new node;
			temp = tail->next;
			while (temp != tail)
			{
				if (temp->data == value)
				{
					cout << "skaicius yra " << pozicija << " pozicijoje" << endl;
					temp = temp->next;
					pozicija++;
					rado = 1;
				}
				else
				{
					temp = temp->next;
					pozicija++;
				}
			}
			if (value == temp->data)
			{
				cout << "skaicius yra " << pozicija << " pozicijoje" << endl;
			}
			else if (rado == 0)
			{
				cout << "skaicius nerastas :/" << endl;
			}
		}
		system("pause");
		list.Menu(list);
	}

	void IsEmpty(LinkedList& list)
	{
		if (tail == NULL)
		{
			cout << "tuscias" << endl;
		}
		else
		{
			cout << "pustustis" << endl;
		}
		system("pause");
		list.Menu(list);
	}

	void Display(LinkedList& list)
	{
		if (tail == NULL)
		{
			cout << "sarasas tuscias!" << endl;
		}
		else
		{
			node* temp = tail->next;
			while (temp != tail)
			{
				cout << temp->data << "\t";
				temp = temp->next;
			}
			cout << temp->data << "\t";
		}
		system("pause");
		list.Menu(list);
	}

void Reverse(LinkedList& list)
	{
		if (tail == NULL)
		{
			cout << "sarasas tuscias!" << endl;
		}
		else
		{
			node* pre = tail;
			node* nxt = tail;
			tail = tail->next;
			while (pre != tail)
			{
				pre = nxt->prev;
				nxt->prev = nxt->next;
				nxt->next = pre;
				nxt = pre;
			}
			pre = nxt->prev;
			nxt->prev = nxt->next;
			nxt->next = pre;
			cout << "sarasas apsuktas! :)" << endl;
		}
		system("pause");
		list.Menu(list);
	}

	int Menu(LinkedList& list)
	{
		system("CLS");
		cout << "1 = prideti nauja elementa saraso" << endl;
		cout << "2 = pasalinti elementa is saraso" << endl;
		cout << "3 = surasti elementa sarase" << endl;
		cout << "4 = patikrinti ar sarasas yra tuscias" << endl;
		cout << "5 = atspausdinti sarasa" << endl;
		cout << "6 = apsukti sarasa" << endl << endl;
		cout << "0 = isjungti" << endl;
		cin >> pasirinkimas;
		system("CLS");
		if (pasirinkimas == 1)
		{
			cout << "1 = pradzioje" << endl;
			cout << "2 = pabaigoje" << endl;
			cout << "3 = pasirinkti pozicija" << endl;
			cin >> pasirinkimas2;
			if (pasirinkimas2 == 1)
				list.AddNodeFront(list);
			else if (pasirinkimas2 == 2)
				list.AddNodeEnd(list);
			else if (pasirinkimas2 == 3)
				list.AddNodeInsert(list);
			else
				list.Menu(list);
		}
		else if (pasirinkimas == 2)
		{
			cout << "1 = pradzioje" << endl;
			cout << "2 = pabaigoje" << endl;
			cout << "3 = pasirinkti pozicija" << endl;
			cin >> pasirinkimas2;
			if (pasirinkimas2 == 1)
				list.DeleteNodeFront(list);
			else if (pasirinkimas2 == 2)
				list.DeleteNodeEnd(list);
			else if (pasirinkimas2 == 3)
				list.DeleteNodeInsert(list);
			else
				list.Menu(list);
		}
		else if (pasirinkimas == 3)
		{
			list.Search(list);
		}
		else if (pasirinkimas == 4)
		{
			list.IsEmpty(list);
		}
		else if (pasirinkimas == 5)
		{
			list.Display(list);
		}
		else if (pasirinkimas == 6)
		{
			list.Reverse(list);
		}
		else if (pasirinkimas == 0)
		{
			return 0;
		}
		else
		{
			list.Menu(list);
		}
	}
};

int main()
{
	LinkedList list;
	list.Menu(list);
	return 0;
}
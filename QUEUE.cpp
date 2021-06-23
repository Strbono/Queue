#include <iostream>
#include <cstdlib>
#include <queue>
#include <algorithm>
#define MAX 5

using namespace std;

struct queue {
	int data[MAX];
	int first, last;
}antrian;

void init() {
	antrian.first = -1;
	antrian.last = -1;
}

bool full() {
	if (antrian.last == MAX - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool empty() {
	if (antrian.last == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void showdata() {
	int i;
	if (!empty())
	{
		for (i = antrian.first; i < antrian.last; i++)
		{
			cout << antrian.data[i] << " | ";

		}
		cout << "\n";
	}
}

void inQueue() {
	showdata();
	int element;

	if (!full())
	{
		cout << "Input Data: ";
		cin >> element;
		cout << "Data succes to add\n";
		antrian.data[antrian.last] = element;
		antrian.last++;
	}
	else
	{
		cout << "Queue is full\n";
	}
	
}

void deQueue() {
	int i;
	showdata();

	if (!empty()) 
	{
		cout << "\n Pickup an data \" "<<antrian.data[antrian.first]<<" \..." << endl;
		for (i = antrian.first; i < antrian.last; i++)
		{
			antrian.data[i] = antrian.data[i + 1];
		}
		antrian.last--;
	}
	else
	{
		cout << "Queue Empty";
	}
	
}

void clear() {
	antrian.first = -1;
	antrian.last = -1;
}

int main() {
	int choice, element;
	init();
	cout << "Demo Queue with Linear Array" << endl;
	do
	{
		showdata();
		cout << "\n Main Menu\n";
		cout << "============\n";
		cout << "[1] Init \n[2] InQueue \n[3] DeQueue \n[4] Clear \n[0] EXIT \n";
		cout << "============\n";
		cout << "\n Input Choice: "; cin >> choice;
		cout << "============\n";
		switch (choice)
		{
		case 1: init();
			break;
		case 2: inQueue();
			break;
		case 3: deQueue();
			break;
		case 4: clear();
			break;
		}
	} while (choice!=0);

	return 0;

}
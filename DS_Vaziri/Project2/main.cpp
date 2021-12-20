#include <iostream>
#include <unistd.h>
#include "Node.hpp"
using namespace std;
int menu(){
	int M_number = 0;
	system("clear");
	cout << "Here is a list of what you are able to do:\n";
	cout << "Enter a number: (1-9)\n";
	cout <<" \033[1;31m 1) Length of the linked list \033[0m\n";
	cout <<" \033[1;32m 2) Search for an element \033[0m\n";
	cout <<" \033[1;33m 3) Delete an element \033[0m\n";
	cout <<" \033[1;34m 4) Add new element \033[0m\n";
	cout <<" \033[1;35m 5) UPPERCASE the letters \033[0m\n";
	cout <<" \033[1;36m 6) lowercase the letters \033[0m\n";
	cout <<" \033[1;37m 7) Print \033[0m\n";
	cout <<" \033[1;91m 8) Print in reverse order \033[0m\n";
	cout <<" \033[1;92m 9) EXIT \033[0m\n";
	cin >> M_number;
	system("clear");
	return M_number;
}
int main() {
	cout << "Enter the elements of linked list and then press ENTER:\n";
	string element;
	getline(cin, element);
	Node *start, *end, *temp;
	Node Linkedlist(element[0]);
	start = &Linkedlist;
	end = start;
	int i = 1;
	while (i < element.size()) {
		temp = new (Node);
		temp -> fill_next(nullptr);
		temp -> fill_let(element[i]);
		end -> fill_next(temp);
		end = temp;
		++i;
	}
	while (true) {
		switch (menu()) {
			case 1: {
				cout << "\033[1;31m*** Length of the linked list ***\033[0m\n";
				int length = Linkedlist.Length(start);
				cout << "Your list's length is: " << length << endl;
				cout << "\033[7;31mREDIRECTING TO MENU\033[0m\n";
				sleep(2);
				system("clear");
				break;
			}
			case 2: {
				cout << "\033[1;32m*** Search for an element ***\033[0m\n";
				cout << "Enter the letter you want to find in the list: \n";
				char let;
				cin >> let;
				int f = Linkedlist.Search(let, start);
				if(f!=-1) {
					cout << let << " was first appeared in " ;
					if(f==1)	cout << f << "st place";
					else if(f==2)	cout << f << "nd place";
					else if(f==3)	cout << f << "rd place";
					else	cout << f << "th place";
				}
				else	cout << "NOT FOUND!";
				cout << endl;
				cout << "\033[7;32mREDIRECTING TO MENU\033[0m\n";
				sleep(2);
				system("clear");
				break;
			}
			case 3: {
				cout << "\033[1;33m*** Delete an element ***\033[0m\n";
				cout << "Enter the letter you want to be deleted from the list: \n";
				char let;
				cin >> let;
				int index = Linkedlist.Search(let,start);
				if(index!=-1) {
					Linkedlist.Delete(index-1, start);
					Linkedlist.Print(start);
				}
				else	cout << let << " is not in the list!\n";
				cout << endl;
				cout << "\033[7;33mREDIRECTING TO MENU\033[0m\n";
				sleep(2);
				system("clear");
				break;
			}
			case 4: {
				int L=Linkedlist.Length(start)+1;
				cout << "\033[1;34m*** Add new element ***\033[0m\n";
				cout << "Enter the letter you want to be added to the list: \n";
				char let;
				cin >> let;
				cout << "Enter new element's place as a number: (1-" << L << ")\n";
				int position;
				cin >> position;
				Node *new_element;
				new_element = new (Node);
				new_element -> fill_let(let);
				if(position>L || position<1)	cout << "Out of range!";
				else	Linkedlist.Add(position, start,new_element);
				Linkedlist.Print(start);
				cout << endl;
				cout << "\033[7;34mREDIRECTING TO MENU\033[0m\n";
				sleep(2);
				system("clear");
				break;
			}
			case 5: {
				cout << "\033[1;35m*** UPPERCASE the letters ***\033[0m\n";
				Linkedlist.UPPERCASE(start);
				Linkedlist.Print(start);
				cout << endl;
				cout << "\033[7;35mREDIRECTING TO MENU\033[0m\n";
				sleep(2);
				system("clear");
				break;
			}
			case 6: {
				cout << "\033[1;36m*** lowercase the letters ***\033[0m\n";
				Linkedlist.lowercase(start);
				Linkedlist.Print(start);
				cout << endl;
				cout << "\033[7;36mREDIRECTING TO MENU\033[0m\n";
				sleep(2);
				system("clear");
				break;
			}
			case 7: {
				cout << "\033[1;37m*** Print ***\033[0m\n";
				Linkedlist.Print(start);
				cout << endl;
				cout << "\033[7;37mREDIRECTING TO MENU\033[0m\n";
				sleep(2);
				system("clear");
				break;
			}
			case 8: {
				cout << "\033[1;91m***Print in reverse order ***\033[0m\n";
				Linkedlist.reversedPrint(start);
				cout << endl;
				cout << "\033[7;91mREDIRECTING TO MENU\033[0m\n";
				sleep(2);
				system("clear");
				break;
			}
			case 9: {
				cout << "\033[1;36m Goodbye! \033[0m \n";
				sleep(1);
				system("clear");
				return 0;
			}
			default:
				menu();
				break;
		}
	}
	return 0;
}

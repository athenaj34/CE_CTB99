#include <iostream>
#include <vector>
using namespace std;
class integer{

	int number;

public:
	//methods
	void get_num();
	void set_num(int num);
	//accessors
	int return_num() {	return number; }

};
//methods defenitions
void integer::get_num(){
	cin >> number;
}

void integer::set_num(int num){
	number=num;
}

integer* bubble_sort(integer arr[]){
	int temp=0,max=arr[0].return_num();
	for (int j = 0; j < 10; j++)
        for (int i = 0; i < 10 -j -1; i++)
            if (arr[i].return_num() > arr[i +1].return_num()){
                temp = arr[i].return_num();
                arr[i].set_num(arr[i + 1].return_num());
                arr[i + 1].set_num(temp);
      }
      return arr;
  }

int main(){
  
	integer numbers[10];
	for(int i=0;i<10;++i){
		cout << i+1 <<  ") Enter a number: \n";
		numbers[i].get_num();
	}
	integer* dup_numbers=bubble_sort(numbers);
  
	cout << "*******************\n";
	
	for(int i=0;i<10;++i)
		cout << dup_numbers[i].return_num() << endl;
	
}

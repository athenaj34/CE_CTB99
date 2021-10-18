#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>
#include "gnuplot.h"
using namespace std;
clock_t t;

//template <class type>

//hanoi
vector <int> a;
vector <int> b;
vector <int> c;
void menu();
void move(vector<int>&from,vector<int>&to){
	to.push_back(from.back());
	from.pop_back();
}

void hanoi(vector<int>&from,vector<int>&to,vector<int>&_using,int num){
	if(num==1)
		move(from,to);
	else{
		hanoi(from, _using, to,num-1);
		move(from,to);
		hanoi(_using, to, from, num-1);
	}
}

void hanoi_exe(){
	cout <<" \033[1;35m**** HANOI TOWER **** \033[0m\n";
	int disk_num = rand()%30+1;
	cout <<  "Executing Hanoi Tower for " << disk_num << " disks.\n";
	t = clock();
	for(int i=disk_num;i>=1;--i)
		a.push_back(i);
	
	hanoi(a,b,c,disk_num);

	t = clock() - t;
	cout << double(t)*1000/CLOCKS_PER_SEC <<" ms" << endl;
	menu();
}
int bsearch(vector<int> list, int from, int to, int key)
{
    	if (list.size() == 0)
        	return -1;
    	if (from > to)
        	return -1;

    	int mid = (from + to) / 2;
    	if (list[mid] == key)
        	return mid;
    	else if (list[mid] < key)
        	return bsearch(list, mid + 1, to, key);
    	else
        	return bsearch(list, from, mid - 1, key);
}

int binary_search(vector<int> v, int key) {
    	return bsearch(v, 0, v.size() - 1, key);
}
void bSearch_exe(){
	cout <<" \033[1;37m**** BINARY SEARCH **** \033[0m\n";
    	int size;
    	cout << "How many numbers do you have?:\n";
    	cin >> size;
    	int key = rand()%(200);
    	cout <<"I will look for " << key << " in the list!\n";
    	vector<int> list;
    	int x;
    	for(int i=0;i<size;++i){
		x = rand()%(size-169);
    		list.push_back(x);
    	}
    	sort(&list[0],&list[size-1]);
    	t = clock();
    	int idx = binary_search(list, key);
    	t = clock() - t ;
    	if (idx == -1)
        	cout << "key not found" << endl ;
    	else
        	cout << "key is found at index " << idx << endl ;
    	cout << double(t)*1000/CLOCKS_PER_SEC << " ms" << endl ;
	menu();
}
void swap(int & i, int& j){
        int temp = i;
        i = j;
        j = temp;
}

void bubble_sort(vector<int>& numbers, int size){
        if(size==1)
                return;
        else
                for(int i=0;i<size-1;i++)
                        if(numbers[i]>numbers[i+1]){
                                swap(numbers[i],numbers[i+1]);
                                bubble_sort(numbers,size-1);
                        }
}
void bubble_exe(){
	cout <<" \033[1;36m**** BUBBLE SORT **** \033[0m\n";
        vector <int>numbers;
        int size;
	cout << "How many numbers do you have?: \n";
	cin >> size;
	int x;
        for(int i=0;i<size;++i){
		x = rand();
                numbers.push_back(x);
	}
	t = clock();
        bubble_sort(numbers,size);
	t = clock() - t;
	cout << double(t)*1000/CLOCKS_PER_SEC << " ms" << endl;
	menu();
}
int min_index(vector <int>& numbers, int startIndex){
        int min = numbers[startIndex];
        for(int i=startIndex+1; i<numbers.size(); ++i)
                if(min > numbers[i])
                        min = numbers[i];
        for(int i=startIndex+1; i<numbers.size();++i)
                if(min == numbers[i])
                        return i;
        return startIndex;
}

void selection_sort(vector<int>& numbers, int start=0){
        if(start==numbers.size()-1)
                return;
        else{
                int minIndex = min_index(numbers,start);
                swap(numbers[start],numbers[minIndex]);
                selection_sort(numbers,start+1);
        }
}

void selection_exe(){
	cout <<" \033[1;33m**** SELECTION SORT **** \033[0m\n";
        vector <int>numbers;
        int size;
	cout << "How many numbers do you have?: \n" ;
	cin >> size;
	int x;
        for(int i=0;i<size;++i){
		x = rand();
 		numbers.push_back(x);
	}
	t = clock();
        selection_sort(numbers);
        t = clock() - t;
	cout << double(t)*1000/CLOCKS_PER_SEC << " ms" << endl;
	menu();
}

int linearSearch(vector <int> numbers,int size, int key){
	if(size>0){
        	if(numbers[size-1]==key)
                	return size-1;
        	else
                	return linearSearch(numbers,size-1,key);
	}
	else
		return -1;
}
void linear_exe(){
	cout <<" \033[1;32m**** LINEAR SEARCH **** \033[0m\n";
	vector <int>list;
	int size;
	cout << "How many numbers do you have?: \n";
	cin >> size;
	int key = rand()%200;
	cout << "I will be searching for " << key << " in the list!\n";
	int x;
	for(int i=0;i<size;++i){
		x = rand()%2000;
		list.push_back(x);		
	}
	t = clock();
	int idx = linearSearch(list,size,key);
	t = clock() -t ;
	if(idx==-1)
		cout << "key not found\n";
	else
		cout << "key found at index " << idx << endl;
	cout << double(t)*1000/CLOCKS_PER_SEC << " ms\n"; 
	menu();
}

int partition (vector<int>arr, int first, int last)
{
        int pivot = arr[last];
        int i = (first - 1);

        for (int j = first; j <= last- 1; j++)
                if (arr[j] <= pivot)
                {
                        i++;
                        swap(arr[i], arr[j]);
                }
        swap(arr[i + 1], arr[last]);
        return (i + 1);
}

void quickSort(vector<int> arr, int start, int end)
{
        if (start < end){
                int pi = partition(arr, start,end);
                quickSort(arr, start, pi - 1);
                quickSort(arr, pi + 1, end);
        }
}
void quick_exe()
{
        vector<int> numbers;
        int size;
        cout << "How many numbers do you have?: \n";
        cin >> size;
        int x;
        for(int i=0;i<size;++i){
                x = rand()%2000;
                numbers.push_back(x);
        }
        t = clock();
        quickSort(numbers, 0, size-1);
        t = clock() -t ;
        cout << double(t)*1000/CLOCKS_PER_SEC << " ms\n";
	menu();
}

void menu(){
	srand(time(NULL));
	cout << "\033[1;31m ****Time Complexity****\033[0m\nChoose a program from below to be executed: (1-7)\n";
	cout << "1) Hanoi Tower\n2) Binary Search\n3) Bubble Sort\n4) Linear Search\n5) Quick Sort\n6) Selection Sort\n7) EXIT\n";	
	int program_num;
	cin >> program_num;
	system("clear");
	if(program_num==1)
		hanoi_exe();
	else if(program_num==2)
		bSearch_exe();
	else if(program_num==3)
		bubble_exe();
	else if(program_num==4)
		linear_exe();
	else if(program_num==5)
		quick_exe();
	else if(program_num==6)
		selection_exe();
	else if(program_num==7)
		return;

}

/*void graph(vector <int>n_vec,vector<double>time_vec){
 	Gnuplot plot;
	string x_str,y_str;
	for(int i=0;i<n_vec.size();++i){
		x_str+=to_string(n_vec[i]);
		y_str+=to_string(time_vec[i]);
	}
 	plot("set multiplot") ;
 	plot("plot ") ;
 	cin.get();

}
*/
int main(){
	system("clear");	
	menu();
	return 0;
}

#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include "gnuplot.h"
using namespace std;
clock_t t;
ofstream hanoiFile("hanoi.txt");
ofstream binFile("bSearch.txt");
ofstream bubFile("bubble.txt");
ofstream linearFile("linear.txt");
ofstream quickFile("quick.txt");
ofstream shellFile("shell.txt");
int counter=0;
int Search = 0;
vector <int> a;
vector <int> b;
vector <int> c;
void Allgraph();
void menu();
void hanoigraph();
void bSearchgraph();
void bubblegraph();
void lineargraph();
void quickgraph();
void shellgraph();
void move(vector<int>&from,vector<int>&to){
	to.push_back(from.back());
	from.pop_back();
}
//hanoi
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
	int disk_num = counter;
	hanoiFile << disk_num << " ";
	t = clock();
	for(int i=disk_num;i>=1;--i)
		a.push_back(i);
	
	hanoi(a,b,c,disk_num);
	t = clock() - t;
	hanoiFile << double(t)*1000/CLOCKS_PER_SEC << endl;
}

//binary search
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
		int size = Search;
		binFile << size << " ";
		int key = rand()%(200)+1;
		vector<int> list;
		int x;
		for(int i=0;i<size;++i){
		x = rand()%(size)+1;
			list.push_back(x);
		}
		sort(&list[0],&list[size-1]);
		t = clock();
		int idx = binary_search(list, key);
		t = clock() - t ;
		binFile << double(t)*1000/CLOCKS_PER_SEC << endl ;
}
void swap(int & i, int& j){
		int temp = i;
		i = j;
		j = temp;
}

//bubble sort
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
		vector <int>numbers;
		int size = Search;
		bubFile << size << " ";
		int x;
		for(int i=0;i<size;++i){
			x = rand();
			numbers.push_back(x);
		}
		t = clock();
		bubble_sort(numbers,size);
		t = clock() - t;
		bubFile << double(t)*1000/CLOCKS_PER_SEC << endl;
}

//shell sort
void shell_sort(vector<int>& numbers, int n){
    for (int i = n/2; i > 0; i /= 2)
    {
        for (int j = i; j < n; j += 1)
        {
            int temp = numbers[i];
            int q;           
            for (q = j; q >= i && numbers[q - i] > temp; q -= i)
                numbers[q] = numbers[q - i];
            numbers[q] = temp;
        }
    }
}
void shell_exe(){
		vector <int>numbers;
		int size = Search;
		shellFile << size << " ";
		int x;
		for(int i=0;i<size;++i){
		x = rand()%size;
 		numbers.push_back(x);
		}
		t = clock();
		shell_sort(numbers,size);
		t = clock() - t;
		shellFile << double(t)*1000/CLOCKS_PER_SEC <<  endl;
}

//linear search
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
	vector <int>list;
	int size = Search;
	linearFile << size << " ";
	int key = rand()%200;
	int x;
	for(int i=0;i<size;++i){
		x = rand()%2000;
		list.push_back(x);
	}
	t = clock();
	int idx = linearSearch(list,size,key);
	t = clock() -t ;
	linearFile << double(t)*1000/CLOCKS_PER_SEC << endl; 
}

int partition (vector<int>numbers, int first, int last)
{
		int pivot = numbers[last];
		int i = (first - 1);

		for (int j = first; j <= last- 1; j++)
				if (numbers[j] <= pivot)
				{
						i++;
						swap(numbers[i], numbers[j]);
				}
		swap(numbers[i + 1], numbers[last]);
		return (i + 1);
}
//quick sort
void quickSort(vector<int> numbers, int start, int end)
{
		if (start < end){
				int pi = partition(numbers, start,end);
				quickSort(numbers, start, pi - 1);
				quickSort(numbers, pi + 1, end);
		}
}
void quick_exe()
{
		vector<int> numbers;
		int size = Search;
		quickFile << size << " ";
		int x;
		for(int i=0;i<size;++i){
			x = rand()%2000;
			numbers.push_back(x);
		}
		t = clock();
		quickSort(numbers, 0, size-1);
		t = clock() -t ;
		quickFile << double(t)*1000/CLOCKS_PER_SEC << endl;
}

void menu(){
	srand(time(NULL));
	cout << "\033[1;31m ****Time Complexity****\033[0m\nChoose a program from below to be executed: (1-8)\n";
	cout << "1) Hanoi Tower\n2) Binary Search\n3) Bubble Sort\n4) Linear Search\n5) Quick Sort\n6) Shell Sort\n7) Graphs\n8) EXIT\n";	
	int program_num;
	cin >> program_num;
	system("clear");
	if(program_num==1){
		cout <<" \033[1;35m**** HANOI TOWER **** \033[0m\n";
		for(int i=0;i<29;++i){
			cout << "Processing Please wait...\b\b\b...\r";
			counter++;
			hanoi_exe();
		}
		counter=0;
		hanoiFile.close();
		hanoigraph();
	}
	else if(program_num==2){
		cout <<" \033[1;37m**** BINARY SEARCH **** \033[0m\n";
		for(int i=0;i<80;i+=2){
			cout << "Processing Please wait...\b\b\b...\r";
			if(i<20)
				Search++;
			else if(i<30)
					Search+=10000;
			else
				Search+=100000;
			
			bSearch_exe();
		}
		Search=0;
		binFile.close();
		bSearchgraph();
	}
	else if(program_num==3){
		cout <<" \033[1;36m**** BUBBLE SORT **** \033[0m\n";
		for(int i=0;i<80;i+=2){
			cout << "Processing Please wait...\b\b\b...\r";
			if(i<20)
				Search++;
			else if(i<30)
				Search+=10;
			else
				Search+=50;
			bubble_exe();
		}
		Search=0;
		bubFile.close();
		bubblegraph();
	}
	else if(program_num==4){
		cout <<" \033[1;32m**** LINEAR SEARCH **** \033[0m\n";
		for(int i=0;i<1300;i+=40){
			cout << "Processing Please wait...\b\b\b...\r";
			if(i<20)
				Search++;
			else if(i<180)
				Search+=50;
			else
				Search+=5000;
			
			linear_exe();
		}
		Search=0;
		linearFile.close();
		lineargraph();
	}
	else if(program_num==5){
		cout <<" \033[1;34m**** QUICK SORT **** \033[0m\n";
		for(int i=0;i<30000;i+=1500){
			cout << "Processing Please wait...\b\b\b...\r";
			if(i<=4500)
				Search++;
			else if(i<=15000)
				Search+=50;
			else if(i<=20000)
				Search+=1000;
			else
				Search+=15000;
			
			quick_exe();
		}
		Search=0;
		quickFile.close();
		quickgraph();
	}
	else if(program_num==6){
		cout <<" \033[1;33m**** SHELL SORT **** \033[0m\n";
		for(int i=0;i<300;i+=3){
			cout << "Processing Please wait...\b\b\b...\r";
			if(i<15)
				Search++;
			else if(i<30)
				Search+=50;
			else if(i<100)
				Search+=100;
			else if(i<200)
				Search+=10000;
			else
				Search+=50000;
			
			shell_exe();
		}
		Search=0;
		shellFile.close();
		shellgraph();
	}

	else if(program_num==7)
		Allgraph();
	else if(program_num==8){
		cout << "\033[1;31m ****Good Bye!****\033[0m\n";
		sleep(1);
		system("clear");
		return;
	}


}
//graph
void hanoigraph(){
 	Gnuplot plot;
	plot("set term qt 0 size 1100,900");
	plot("set title \"***Hanoi Tower***\\n\\nO(2^n)\" font \",15\"");
	plot("set xlabel \"Number of disks\" font \",15\"");
	plot("set ylabel \"Execution time (ms)\" font \",15\"");
	plot("set xzeroaxis");
	plot("set yzeroaxis");
	plot("set ticscale 1");
	plot("set grid");
	plot("set style line 1 ");
	plot("set xtics 0,1,40");
	plot("set ytics 0,1000");
	plot("plot 'hanoi.txt' smooth unique w linespoints pt 7 lc rgb '#0060ad' lw 3") ;
	plot("set term gif size 1200,1000 ");
	plot("set output 'hanoi.gif'");
	plot("replot");
	plot("set term pop");
	usleep(5);
	cout << "Press any key to continue\n";
	cin.get();
	cin.get();
	menu();
}
void bSearchgraph(){
	Gnuplot plot;
	plot("set term qt 0 size 1100,900");
	plot("set title \"***Binary Search***\\n\\nΩ(1) | O(log n)\" font \",15\"");
	plot("set xlabel \"Sequence Size\" font \",15\"");
	plot("set ylabel \"Execution time (ms)\" font \",15\"");
	plot("set xzeroaxis");
	plot("set yzeroaxis");
	plot("set ticscale 1");
	plot("set grid");
	plot("set logscale x");
	plot("set logscale y");
	plot("plot 'bSearch.txt' smooth unique w linespoints pt 7 lc rgb '#0060ad' lw 3") ;
	plot("set term gif size 1200,1000 ");
	plot("set output 'bSearch.gif'");
	plot("replot");
	plot("set term pop");
	usleep(5);
	cout << "Press any key to continue\n";
	cin.get();
	cin.get();
	menu();
}
void bubblegraph(){
	Gnuplot plot;
	plot("set term qt 0 size 1100,900");
	plot("set xzeroaxis");
	plot("set yzeroaxis");
	plot("set ticscale 1");
	plot("set grid");
	plot("set title \"***Bubble Sort***\\n\\nΩ(n) | Θ(n^2) | O(n^2)\" font \",15\"");
	plot("set xlabel \"Sequence Size\" font \",15\"");
	plot("set ylabel \"Execution time (ms)\" font \",15\"");
	plot("set xtics 0,200");
	plot("set ytics 0,50");
	plot("plot 'bubble.txt' smooth unique w linespoints pt 7 lc rgb '#0060ad' lw 3") ;
	plot("set term gif size 1200,1000 ");
	plot("set output 'bubble.gif'");
	plot("replot");
	plot("set term pop");
	usleep(5);
	cout << "Press any key to continue\n";
	cin.get();
	cin.get();
	menu();
}
void lineargraph(){
	Gnuplot plot;
	plot("set term qt 0 size 1100,900");
	plot("set xzeroaxis");
	plot("set yzeroaxis");
	plot("set ticscale 1");
	plot("set title \"***Linear Search***\\n\\nΩ(1) | Θ(n) | O(n)\" font \",15\"");
	plot("set xlabel \"Sequence Size\" font \",15\"");
	plot("set ylabel \"Execution time (ms)\" font \",15\"");
	plot("set grid");
	plot("set xtics 0,10000");
	plot("set logscale y");
	plot("plot 'linear.txt' smooth unique w linespoints pt 7 lc rgb '#0060ad' lw 3") ;
	plot("set term gif size 1200,1000 ");
	plot("set output 'linearSearch.gif'");
	plot("replot");
	plot("set term pop");
	usleep(5);
	cout << "Press any key to continue\n";
	cin.get();
	cin.get();
	menu();
}
void quickgraph(){
	Gnuplot plot;
	plot("set term qt 0 size 1100,900");
	plot("set xzeroaxis");
	plot("set yzeroaxis");
	plot("set ticscale 1");
	plot("set grid");
	plot("set title \"***Quick Sort***\\n\\nΩ(nlog n) | Θ(n log n) | O(n^2)\" font \",15\"");
	plot("set xlabel \"Sequence Size\" font \",15\"");
	plot("set ylabel \"Execution time (ms)\" font \",15\"");
	plot("set logscale x");
	plot("set logscale y");
	plot("plot 'quick.txt' smooth unique w linespoints pt 7 lc rgb '#0060ad' lw 3") ;
	plot("set term gif size 1200,1000 ");
	plot("set output 'quickSort.gif'");
	plot("replot");
	plot("set term pop");
	usleep(5);
	cout << "Press any key to continue\n";
	cin.get();
	cin.get();
	menu();
}
void shellgraph(){
	Gnuplot plot;
	plot("set term qt 0 size 1100,900");
	plot("set xzeroaxis");
	plot("set yzeroaxis");
	plot("set ticscale 1");
	plot("set grid");
	plot("set title \"***Shell Sort***\\n\\nΩ(n) | Θ((nlog n)^2) | O(nlog n)\" font \",15\"");
	plot("set xlabel \"Sequence Size\" font \",15\"");
	plot("set ylabel \"Execution time (ms)\" font \",15\"");
	plot("set logscale y");
	plot("plot 'shell.txt' smooth unique w linespoints pt 7 lc rgb '#0060ad' lw 3") ;
	plot("set term gif size 1200,1000 ");
	plot("set output 'shellSort.gif'");
	plot("replot");
	plot("set term pop");
	usleep(5);
	cout << "Press any key to continue\n";
	cin.get();
	cin.get();
	menu();
}
void Allgraph(){
	Gnuplot plot;
	plot("set term qt 0 size 1100,900");
	plot("set xzeroaxis");
	plot("set yzeroaxis");
	plot("set ticscale 1");
	plot("set grid");
	plot("set title \"***Time Complexity Graphs***\" font \",15\"");
	plot("set xlabel \"n\" font \",15\"");
	plot("set ylabel \"Execution time (ms)\" font \",15\"");
	plot("set key outside bottom right ");
	plot("set logscale y");
	plot("set logscale x");
	plot("plot 'hanoi.txt' t 'Hanoi Tower O(2^n)' smooth unique w linespoints pt 7 lw 3,'bSearch.txt' t 'Binary Search O(log n)' smooth unique w linespoints pt 7 lw 3,'bubble.txt' t 'Bubble Sort O(n^2)' smooth unique w linespoints pt 7 lw 3,'linear.txt' t 'Linear Search O(n)' smooth unique w linespoints pt 7 lw 3,'quick.txt' t 'Quick Sort O(n^2)' smooth unique w linespoints pt 7 lw 3,'shell.txt' t 'Shell Sort O(nlog n)' smooth unique w linespoints pt 7 lw 3") ;
	plot("set term gif size 1200,1000 ");
	plot("set output 'Graphs.gif'");
	plot("replot");
	plot("set term pop");
	usleep(5);
	cout << "Press any key to continue\n";
	cin.get();
	cin.get();
	menu();
}
int main(){
	system("clear");	
	menu();
	return 0;
}

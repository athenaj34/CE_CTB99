#include <iostream>
#include "gnuplot.h"
using namespace std;
int main(){
 Gnuplot plot;
 plot("set multiplot") ;
 plot("plot cos(x),sin(x)") ;
 cin.get();
 return 0;
}

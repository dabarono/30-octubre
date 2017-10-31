#include <cmath>
#include <iostream>
#include "omp.h"

double f(double x){
  double g=4.0/(1.0+x*x);
  return g;
}


int main(void){
  double n=1000;
  double dx=1/n;
  double sum=0;
  double x;
#pragma omp parallel for private(x)reduction(+:sum)
  for(int j=0;j<=n;j=j+1){
    x=dx*j;
    sum=sum+f(x);
  }
  double pi=dx*sum;
  std::cout<<pi<<std::endl;
}

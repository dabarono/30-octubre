#include <iostream>
//#include <omp.h>
#include <cmath>

double f(double x){
  double g=4.0/(1+pow(x,2));
  return g;
}

int main(void){
  double x=0;
  double sum=0;
  double n=100000;
  double dx=1/100;
  for (int i=0;i<=n;i=i+1){
    sum=sum+f(x);
    x=(0.5+i)*dx;
    std::cout<<sum<<std::endl; 
  }
  double pi=dx*sum;
  std::cout<<pi<<std::endl;
}

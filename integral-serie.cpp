#include <cmath>
#include <iostream>

double f(double x){
  double g=4.0/(1.0+x*x);
  return g;
}


int main(void){
  double n=1000;
  double dx=1/n;
  double sum=0;
  for(int j=0;j<=n;j=j+1){
    sum=sum+f(dx*j);
  }
  double pi=dx*sum;
  std::cout<<pi<<std::endl;
}

#include <cmath>
#include <iostream>
#include <vector>
#include "omp.h"

int main(void){
  double N=100;
  double sum=0;
  double sum2=0;
  std::vector<double>A(N);
  for(int k=0;k<N;++k)
    A[k]=k+1;
  for(int l=0;l<N;++l)//SUMA EN SERIE
    sum2=sum2+A[l];
  //omp_set_num_threads(7);
#pragma omp parallel for reduction(+:sum)//SUMA EN PARALELO
  for(int j=0;j<N;++j){
      sum=sum+A[j];
    }
  double promedio=sum/N;//PROMEDIO EN SERIE
  double promedio2=sum2/N;//PROMEDIO EN PARALELO
  std::cout<<sum2<<std::endl;
  std::cout<<promedio2<<std::endl;
  std::cout<<sum<<std::endl;
  std::cout<<promedio<<std::endl;
}

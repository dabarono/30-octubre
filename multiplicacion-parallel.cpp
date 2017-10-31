#include <cmath>
#include <iostream>
#include <vector>
#include "omp.h"

int main(void){
  int N=10;
  std::vector<double>A(N*N), B(N*N), C(N*N);
  for(int j=0; j<=N;j=j+1)//llenado de A
    for(int k=0;k<=N;k=k+1)
      A[j*N+k]=j+k;
  for(int j=0; j<=N;j=j+1)//llenado de B
    for(int k=0;k<=N;k=k+1)
      B[j*N+k]=j-k;
#pragama omp parallel for private(k,l)
  for(int j=0; j<=N;j=j+1)//multiplicacion
    for(int k=0;k<=N;k=k+1)
      for(int l=0;l<=N;l=l+1)
	C[j*N+k]=A[j*N+l]*B[l*N+k];
}

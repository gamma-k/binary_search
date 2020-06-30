#include <stdio.h>

int n;
int k;
int A[100000];
int Amax;//max{A[0],...,A[n-1]}

int p(int x){
  int i,num,workload;
  num = 0;
  i = 0;
  while(i<n){
    workload = A[i];
    while(workload <= x){
      i++;
      if(i >= n) break;
      workload += A[i];
    }
    num++;
  }
  return num <= k;
}

int main(){
  int i, lb, ub, Asum;
  Amax = 0;
  Asum = 0;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    if(A[i] > Amax) Amax = A[i];
    Asum += A[i];
  }
  lb = Amax - 1;
  ub = Asum;
  while(ub - lb > 1){
    int mid = (ub + lb) / 2;
    if(p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }
  printf("%d\n",ub);
  return 0;
}

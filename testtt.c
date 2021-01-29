#include <stdio.h> 

#define MAX 10


void fun(int arr[], size_t arr_size)   
{ 
  int i;    
  for (i = 0; i < arr_size; i++)  
  {   
    arr[i] = i;   
  } 
  printf("%d\n", i);
} 
  
int main() 
{ 
  int i;   
  int arr[MAX] = {0, 0 ,0, 0}; 
  fun(arr, MAX); 
    
  for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) 
    printf(" %d ", arr[i]); 
  
  getchar();   
  return 0; 
} 

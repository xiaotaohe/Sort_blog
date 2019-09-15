/*************************************************************************
    > File Name: heap_sort_nr.cpp
    > Author: 陶超
    > Mail: taochao1997@qq.com 
    > Created Time: Tue 10 Sep 2019 10:55:38 PM PDT
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/fcntl.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stack>
using namespace std;


/*
 *非递归的归并排序
 */


void merger(int* arr,int* tmp,int left,int mid,int right)
{
  int b1 = left,e1 = mid;
  int b2 = mid+1,e2 = right;
  int index = 0;
  while(b1<=e1 && b2<=e2)
  {
    if(arr[b1]<=arr[b2])
      tmp[index++] = arr[b1++];
    else
      tmp[index++] = arr[b2++];
  }
  while(b1<=e1)
    tmp[index++] = arr[b1++];
  while(b2<=e2)
    tmp[index++] = arr[b2++];
  index = 0;
  for(int i = left;i<=right;i++)
    arr[i] = tmp[index++];
}
void heap_sort(int* arr,int* tmp,int right)
{
  int size = 1;
  while(size<=right)
  {
    int low = 0;
    while(low+size<=right)
    {
      int mid = low+size-1;
      int hight = mid+size;
      if(hight>right)
        hight = right;
      merger(arr,tmp,low,mid,hight);
      low = hight+1;
    }
    size *= 2;
  }
}
int main()
{

  int arr[10] = {1,3,2,10,9,5,4,6,8,7};
  int* tmp = new int[10];
  heap_sort(arr,tmp,9);
  delete[] tmp;
  for(auto e : arr)
    cout<<e<<" ";
  cout<<endl;
	return 0;
}

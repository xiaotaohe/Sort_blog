/*************************************************************************
    > File Name: quick_sort_nr.cpp
    > Author: 陶超
    > Mail: taochao1997@qq.com 
    > Created Time: Tue 10 Sep 2019 10:36:00 PM PDT
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
 *非递归实现快排
 */

int partion(int* arr,int left,int right)
{
  int begin = left,end = right;
  while(begin<end)
  {
    while(begin<end && arr[begin]<=arr[right])
      begin++;
    while(begin<end && arr[end]>=arr[right])
      end--;
    swap(arr[begin],arr[end]);
  }
  swap(arr[right],arr[end]);
  return begin;
}

void quick_sort(int* arr,int left,int right)
{
  int mid = partion(arr,left,right);
  stack<int> s;
  if(mid>left+1)
  {
    //先压有边界
    s.push(mid-1);
    s.push(left);
  }
  if(mid<right-1)
  {
    s.push(right);
    s.push(mid+1);
  }
  while(!s.empty())
  {
    //取出左右边界
    int i = s.top();
    s.pop();
    int j = s.top();
    s.pop();
    mid = partion(arr,i,j);
    //先压右边界
    if(mid>i+1)
    {
      s.push(mid-1);
      s.push(i);
    }
    if(mid<j-1)
    {
      s.push(j);
      s.push(mid+1);
    }
  }
}

int main()
{
  int arr[10] = {10,9,2,3,4,5,8,7,6,1};
  quick_sort(arr,0,9);
  for(auto& e:arr)
    cout<<e<<" ";
  cout<<endl;
	return 0;
}

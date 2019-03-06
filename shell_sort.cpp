#include<iostream>
using namespace std;

//希尔插排
void insert(int* a,int size,int gap)
{
  for(int i = gap;i<size;i+=gap)
  {
    int cur = a[i];
    int j = i;
    for(j = i;j>0;j-=gap)
    {
      if(a[j-gap]>cur)
        a[j] = a[j-gap];
      else 
        break;
    }
    swap(a[j],cur);
  }
}
//希尔排序
void shell_sort(int* a,int size)
{
  int gap = size;
  while(gap)
  {
    gap = gap/3+1;
    insert(a,size,gap);
    if(gap == 1)
      break;
  }
}
int main()
{
  int a[10] = {10,9,8,7,6,5,4,3,2,1};
  shell_sort(a,10);
  for(auto p : a)
    cout<<p<<" ";
  cout<<endl;
  return 0;
}

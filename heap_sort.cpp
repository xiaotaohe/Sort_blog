/*
 * 这段代码实现堆排序
 */
#include<iostream>
#include<vector>
using namespace std;

void AdjustDown(vector<int>& v,int parent,int size)
{
    int child = parent*2+1;
    while(child<size)
    {
      if(child+1<size && v[child+1]>v[child])
        child++;
      if(v[child]>v[parent])
      {
        swap(v[child],v[parent]);
        parent = child;
        child = parent*2+1;
      }
      else 
        break;
    }
}

void heap_sort(vector<int>& v)
{
  //建堆，向下调整
  for(int i = (v.size()-2)/2;i>=0;i--)
  {
    //向下调整
    AdjustDown(v,i,v.size());
  }
  //排序，交换堆顶和队尾，缩短队尾，然后重新向下调整
  for(int i = 1;i<=v.size();i++)
  {
    swap(v[0],v[v.size()-i]);
    AdjustDown(v,0,v.size()-i);
  }
}
int main()
{
  vector<int> v{1,2,10,9,8,5,4,6,7,3};
  heap_sort(v);
  for(auto& e : v)
    cout<<e<<" ";
  cout<<endl;
  return 0;
}


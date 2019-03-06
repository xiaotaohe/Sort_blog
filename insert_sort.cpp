#include<iostream>
using namespace std;

//插入排序
//记录当前节点值，有前面节点逐个比较，如果比它大就用前面覆盖后面
void Insert(int* a,int size)
{
  for(int i = 1;i<size;i++)
  {
    int cur = a[i];//当前位置
    int j = i;
    //当j-1不大于cur时，找到要插入的位置为j;
    for(j = i;j>0;j--)
    {
      if(a[j-1]>cur)
        a[j] = a[j-1];
      else 
        break;
    }
    swap(a[j],cur);
  }
}

void test_Insert()
{
  int a[10] = {10,9,2,3,5,6,7,8,1,4};
  Insert(a,sizeof(a)/sizeof(a[0]));
  for(auto p:a)
    cout<<p<<" ";
  cout<<endl;
}
int main()
{
  test_Insert();
  return 0;
}

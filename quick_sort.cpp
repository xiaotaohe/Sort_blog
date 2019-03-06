#include<iostream>
using namespace std;
//找中间值作为左右分界点
int partion(int* a,int left,int right)
{
  //以最右侧为基准值
  //从左开始找比基准大的值
  //从右侧找比基准值小的值
  //找到之后交换
  //当左右指针相遇的时候，交换相遇点，与左右侧
  int dev = right;//基准
  while(left<right)
  {
    while(left<right && a[left] <= a[dev])
      left++;
    while(left<right && a[right] >= a[dev])
      right--;
    swap(a[left],a[right]);
  }
  swap(a[dev],a[right]);
  return left;
}
//将数组一直分为左侧、中间（1个值）、右侧;直到全部分为一个的时候有序
void quick_sort(int* a, int left, int right)
{
  if(left>=right)
    return;
  //dev保存中间值
  int dev = partion(a,left,right);
  quick_sort(a,left,dev-1);
  quick_sort(a,dev+1,right);

}
void test_quick()
{
  int a[10] = {10,9,8,7,6,5,4,3,2,1};
  quick_sort(a,0,9);
  for(int i = 0;i<10;i++)
    std::cout<<a[i]<<" ";
  std::cout<<endl;
}

int main()
{
  test_quick();
  return 0;
}

#include<iostream>
#include<vector>
using namespace std;

//这段代码目的是实现泛型的归并函数
template<class T>
void meger(vector<T>& v,vector<T>& ret,int left,int index,int right)
{
  //标志两个序列的开头和结尾下标
  int b1 = left,b2 = index+1;
  int e1 = index,e2 = right;
  //合并的部分
  int k = 0;
  while(b1<=e1 && b2<=e2)
  {
    if(v[b1]<v[b2])
      ret[k++] = v[b1++];
    else  
      ret[k++] = v[b2++];
  }
  while(b1<=e1)
    ret[k++] = v[b1++];
  while(b2<=e2)
    ret[k++] = v[b2++];
  //将这段数据放回原数组
  k = 0;
  for(int i = left;i<=right;i++)
    v[i] = ret[k++];
}

template<class T>
void meger_sort(vector<T>& v,vector<T>& ret,int left,int right)
{
  if(left<right)
  {
    int index = (left+right)>>1;
    meger_sort(v,ret,left,index);
    meger_sort(v,ret,index+1,right);
    meger(v,ret,left,index,right);
  }
}

int main()
{
  vector<int> v{10,9,5,6,7,4,3,2,1};
  //归并是以空间换取时间
  vector<int> ret = v;
  meger_sort<int>(v,ret,0,v.size()-1);
  for(auto& e : v)
    cout<<e<<" ";
  cout<<endl;
  return 0;
}

#include <iostream>
#include <cstdlib>
struct MyArray 
{
  double* a = nullptr;
  size_t n = 0;
  size_t realN = 0;
  MyArray():n(0), realN(0){ a = new double[0];}
  MyArray(const size_t& n):n(n), realN(n)
  {
    a = new double [n];
    for(int i = 0; i < n; i++)
      a[i] = 0;

  }

  void print() const
  {
      for (int i=0;i < n; i++)
        std::cout << a[i] << ' ';
      std::cout << std::endl;
  }
  void resize(const size_t& k)
  {
    double* b = new double [k];
    for (int i=0; i < std::min(k, n); i++)
      b[i] = a[i];
    delete[] a;
    a = b;
  }
  void add(const double& el)
  {
   n+=1;
   if(n > realN) {
     realN = (realN==0 ? 10: realN * 2);
     resize(realN);
   }
    a[n-1] = el;
  }
  void remove(const size_t& i)
  {
    if(i >=n) return;
    for(size_t j=i; j<n-1; j++)
           a[j] = a[j+1];
    n--;
    if (2 * n < realN)
    {
      size_t newSize = realN;
      while (n * 2 < newSize) newSize/=2;
      resize(newSize);
      realN = newSize;
    }
  }
double& operator[] (size_t ind)
{
  if (ind >=n) return a[0];
  return a[ind];
}
  ~MyArray()
  {
          delete[] a;
  }

};

int main() 
{
  MyArray a;
  for (int i=0; i<11; i++)
    a.add(i);
  a.remove(4);
  a[4]=-1.7657;
  a.print();
          
}

#include <iostream>
#include "Quaternion.h"
using namespace std;
void QuaternionConstr() {
  Quaternion a; 
  a.print();
  Quaternion a1(1,1,1,1);
  a1.print();
  Quaternion b = a;
  b.print();
}
void QuaternionOper()
{
  cout<<"Operations:\n";
  Quaternion a1(1,2,1,-1);
  Quaternion a2(5,-2,0,4);
  (a1 + a2).print();
  (a1 - a2).print();
  (a1 * a2).print();
  (a1 / a2).print();
  a1.conjugated().print();
  cout << a1.mod() << endl;
  a1.inverse().print();
  (a1 * a1.inverse()).print();
  cout << (a1==a1) << endl;
  cout << (a1==a2) << endl;
}
int main()
{
  QuaternionConstr();
  QuaternionOper();
	return 0;
}

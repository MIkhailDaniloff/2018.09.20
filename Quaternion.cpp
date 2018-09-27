#include "Quaternion.h"

  void Quaternion::print() const
  {
          cout << "a : " << a << ", i : " << i 
               << ", j : " << j << ", k " << k << endl;
  }
double Quaternion::mod () const
  {
          return sqrt(a*a + i*i + j*j + k*k);
  }
Quaternion Quaternion::conjugated () const
  {
          return Quaternion(a, -i, -j, -k);
  }
Quaternion Quaternion::inverse() const
  {
          return conjugated() / (mod() * mod());
  }


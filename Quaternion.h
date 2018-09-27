#ifndef QUATERNION_H
#define QUATERNION_H
#include <iostream>
#include <cmath>
using namespace std;

struct Quaternion
{
  double a;
  double i, j, k;

  Quaternion(double a, double i, double j, double k): a(a), i(i), j(j), k(k){}
  Quaternion(): a(0), i(0), j(0), k(0){}
  Quaternion(const Quaternion& q): a(q.a), i(q.i), j(q.j), k(q.k){}

  friend const Quaternion operator+(const Quaternion& q1, const Quaternion& q2)
  {
      Quaternion res(q1.a + q2.a, q1.i + q2.i,
                     q1.j + q2.j, q1.k + q2.k);
      return res;
  }
  friend const Quaternion operator*(const Quaternion& q1, const double& x)
  {
      Quaternion res(q1.a * x, q1.i * x, q1.j * x, q1.k * x);
      return res;
  }
  friend const Quaternion operator*(const double& x, const Quaternion& q1)
  {
      Quaternion res(q1.a * x, q1.i * x, q1.j * x, q1.k * x);
      return res;
  }
  friend const Quaternion operator-(const Quaternion& q1, const Quaternion& q2)
  {
      Quaternion res = q1 + (q2 * -1);
      return res;
  }
  friend const Quaternion operator*(const Quaternion& q1, const Quaternion& q2)
  {
      Quaternion res(q1.a * q2.a - q1.i * q2.i - q1.j * q2.j - 
                     q1.k * q2.k, q1.a * q2.i + q2.a * q1.i -
                     q1.j * q2.k + q2.j * q1.k, q1.a * q2.j +
                     q2.a * q1.j + q1.i * q2.k - q2.i * q1.k,
                     q1.a * q2.k + q2.a * q1.k - q1.i * q2.j +
                     q2.i * q1.j);
      return res;
  }
  friend const Quaternion operator/(const Quaternion& q, const double& x)
  {
          double t = 1 / x;
          return q * t;
  }
  friend const Quaternion operator/(const double& x, const Quaternion& q)
  {
          return x * q.inverse();
  }
  friend const Quaternion operator/(const Quaternion& q1, const Quaternion& q2)
  {
          return q1 * q2.inverse();
  }
  friend const bool operator==(const Quaternion& q1, const Quaternion& q2)
  {
    return (q1-q2).mod() == 0;
  }

  void print() const;
  Quaternion conjugated () const;
  double mod () const;
  Quaternion inverse() const;

};




#endif

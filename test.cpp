#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

class A
{
private:
  int a;
  std::string s;

public:
  A(int a, std::string s) : a(a), s(s) {}
  void print() { std::cout << a << " " << s << std::endl; }
  bool operator<(const A &other) const
  {
    if (s == other.s)
      return a < other.a;
    return s < other.s;
  }
  bool operator>(const A &other) const
  {
    if (s == other.s)
      return a > other.a;
    return s > other.s;
  }
};

inline bool functionOfComparison(const A &a, const A &b)
{
  if (a > b)
    return true;
  return false;
}

int main()
{
  // std::vector<A> v;
  // v.push_back(A(1, "a"));
  // v.push_back(A(1, "b"));
  // v.push_back(A(3, "b"));
  // v.push_back(A(2, "a"));
  // v.push_back(A(2, "b"));
  // v.push_back(A(3, "a"));
  // v.push_back(A(3, "b"));

  // std::sort(v.begin(), v.end(), functionOfComparison);

  // for (auto &i : v)
  //   i.print();

  double number;
  std::string s = "bruno";
  // std::istringstream iss(s);
  // while (std::getline(iss, s, ','))
  // {
  //   number = std::stod(s); 
  //   std::cout << number << std::endl;
  // }
  try
  {
    number = std::stod(s);
    std::cout << number;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  // while (iss >> number)
  //   std::cout << number << std::endl;
  return 0;
}

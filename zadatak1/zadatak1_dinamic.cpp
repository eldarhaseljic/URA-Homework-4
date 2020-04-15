#include <iostream>
#include <stdexcept>
#include <vector>

int function(int n)
{
  if(n<0) return 0;
  std::vector<int> vector(n+1);
  vector[0] = 1;
  vector[1] = 1;
  vector[2] = 1;
  vector[3] = 2;
  for(int i = 4; i<n+1; ++i)
  {
     vector.at(i) = vector.at(i-1) + vector.at(i-3) + vector.at(i-4);
  }
  return vector.at(n);
}

int main(int argc, char *argv[])
{
  int num;
  std::cout << "Unesite neki broj " << std::endl;
  std::cout << "Vas broj: ";
  while(!(std::cin>>num))
  {
    std::cin.clear();
    std::cin.ignore();
  }
  int result = function(num);
  std::cout << "Ukupan broj kombinacja rezultata brojevectora 1 , 3 , 4 broja "<< num;
  std::cout << " je " << result << std::endl;
  return 0;
}
 

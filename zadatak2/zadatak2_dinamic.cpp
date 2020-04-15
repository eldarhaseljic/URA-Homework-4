#include <iostream>
#include <stdexcept>
#include <vector>

int function( int n )
{ 
  if(n<0) return 0;
  std::vector<int> vector(n+1);
  vector[0] = 2;
  vector[1] = 4;
  vector[2] = 12;
  for(int i = 3; i<n+1; ++i)
    vector.at(i) = vector.at(i-3) + 2*vector.at(i-2) + 3*vector.at(i-3);
 return vector.at(n);

}

int main(int  argc, char *argv[])
{
  int num;
  std::cout << "Unesite neki broj " << std::endl;
  std::cout << "Vas broj: ";
  while(!(std::cin>>num))
  {
    std::cin.ignore();
    std::cin.clear();
  }
  int result = function(num);
  std::cout << "Rezultat funkcije za broj "<< num <<" je " << result << std::endl;
  return 0;
}

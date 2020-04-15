#include <iostream>
#include <stdexcept>
#include <vector>

std::vector<long> globl {2 , 4 , 12};

long function( long n )
{
  if(n<0) throw std::out_of_range("Broj mora biti veci ili jednak 0!!!!");
  if(n<3) return globl.at(n);
  if(globl.at(n)==0)
  {
  globl.at(n) = 3*function(n-3) + 2*function(n-2) + function(n-3);    
  }
  return globl.at(n);
}

int main(int  argc, char *argv[])
{
  long num;
  std::cout << "Unesite neki broj " << std::endl;
  std::cout << "Vas broj: ";
  while(!(std::cin>>num))
  {
    std::cin.clear();
    std::cin.ignore();
  }
  if(num>=globl.size()) globl.resize(num+1);
  long result = function(num);
  std::cout << "Rezultat funkcije za broj "<< num <<" je " << result << std::endl;
  for(auto i=0; i<globl.size();++i)
    std::cout << globl.at(i) << std::endl;
  return 0;
}

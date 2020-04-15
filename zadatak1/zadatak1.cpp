#include <iostream>
#include <stdexcept>

int function(int n)
{
  if(n<0) return 0;
  if(n>=0 && n<3) return 1;
  if(n==3) return 2;
  return  function(n-4) + function(n-3) + function(n-1);
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
  std::cout << "Ukupan broj kombinacja rezultata brojeva 1 , 3 , 4 broja "<< num;
  std::cout << " je " << result << std::endl;
  
  return 0;
}
 

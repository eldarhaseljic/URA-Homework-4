#include <iostream>

int function( int n )
{
  if(n == 0) return 2;
  if(n == 1) return 4;
  if(n == 2) return 12;
  return 3*function(n-3) + 2*function(n-2) + function(n-3); 
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
  std::cout << "Rezultat funkcije za broj "<< num <<" je " << result << std::endl;
  return 0;
}

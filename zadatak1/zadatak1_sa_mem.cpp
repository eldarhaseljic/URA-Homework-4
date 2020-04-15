#include <iostream>
#include <stdexcept>
#include <vector>

std::vector<long> vector {1,1,1,2};

long function(long n)
{
  if(n<0) throw std::out_of_range("Nalazite se van granica");
  if(n>=0 && n<3) return vector.at(n);
  if(n==3) return vector.at(n);
  if(vector.at(n)==0) vector.at(n) = function(n-4) + function(n-3) + function(n-1);
  return vector.at(n);
}

int main(int argc, char *argv[])
{
  long num;
  std::cout << "Unesite neki broj " << std::endl;
  std::cout << "Vas broj: ";
  while(!(std::cin>>num))
  {
    std::cin.clear();
    std::cin.ignore();
  }
  if(num>=vector.size()) vector.resize(num+1);
  long result = function(num);
  std::cout << "Ukupan broj kombinacja rezultata brojevectora 1 , 3 , 4 broja "<< num;
  std::cout << " je " << result << std::endl;
  for(auto i = 0;i<vector.size();++i) std::cout << vector.at(i) << std::endl;  
  return 0;
}
 

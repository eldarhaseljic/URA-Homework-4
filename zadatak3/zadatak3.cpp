#include <iostream>
#include <algorithm>

int recursion(int *niz1, int* niz2 , int n1, int n2)
{
  if(n1==0 || n2 == 0)
    return 0;
  if(niz1[n1-1] == niz2[n2-1])
    return 1 + recursion(niz1, niz2, n1-1,n2-1);
  else
    return std::max(recursion(niz1,niz2,n1,n2-1),recursion(niz1,niz2,n1-1,n2));
}

int NIZ[10];
int memory(int *niz1, int * niz2, int n1, int n2)
{
  if(n1==0 || n2==0) return 0;
  if(niz1[n1-1] == niz2[n2-1])
  {
    NIZ[n1-1] = 1 + memory(niz1,niz2,n1-1,n2-1);
  }
  else
  {
    NIZ[n1-1] = std::max(memory(niz1,niz2,n1-1,n2),memory(niz1,niz2,n1,n2-1));
  }
  return NIZ[n1-1];
}

int dinamic(int *niz1 , int *niz2 , int n1 , int n2)
{
  int tmp[n1+1][n2+1];
  for(int i = 0; i<=n1;++i)
    tmp[i][0]=0;
  for(int i = 0; i<=n2;++i)
    tmp[0][i]=0;
  for(int i =1;i<=n1;++i){
    for(int j=1; j<=n2;++j)
    {
      if(niz1[i-1]==niz2[j-1])
      {
        tmp[i][j]=tmp[i-1][j-1]+1;
      }
      else
        tmp[i][j]=std::max(tmp[i-1][j],tmp[i][j-1]);
    }
  }
  std::cout  << std::endl;
  std::cout << "LOOKUP TABELA " << std::endl;
  for(int i=0;i<=n1;++i)
  {
    for(int j=0;j<=n2;++j)
    {
      std::cout << tmp[i][j] << " | ";
    }
    std::cout << std::endl;
  }
  return tmp[n1][n2];
}
void sekvenca(int*niz, int n)
{
  int nizsek[n];
  for(auto i=0;i<n;++i)
    nizsek[i]=0;
  int br = 0;
  nizsek[br++]=niz[0];
  for(auto i=0;i<=n;++i)
  {
    if(NIZ[i]!=NIZ[i+1])
      nizsek[br++]=niz[i+1];
  }
  std::cout << "SEKVENCA : ";
  for(auto i=0;i<br-1;++i)
  {
    std::cout <<  nizsek[i]  << "\t";
  }
  std::cout << std::endl;
}
int main(int argc, char *argv[])
  {
  int niz [] = {9,21,8,32,20,40,59};
  int n = sizeof(niz)/sizeof(niz[0]);
  int niz1 [n];
  std::copy(niz,niz+n,niz1);
  std::sort(niz1, niz1+n-1);
  int n1 = sizeof(niz1)/sizeof(niz1[0]);
  std::cout << "Elementi niza su : " << std::endl;
  for(auto i = 0; i < n ; ++i) 
  {
   std::cout << niz[i] << "\t";
  }
  std::cout << std::endl << std::endl;
  std::cout << "Duzina najduze podsekvence odredjena rekurzijom bez memorizacije je: ";
  std::cout << recursion(niz,niz1,n,n1) << std::endl << std::endl;  
  std::cout << "Elementi niza koristenog u memorizaciji prije memorizacije su : "; 
  std::cout << std::endl;
  for(auto i = 0; i < n ; ++i) 
  {
   std::cout << NIZ[i] << "\t";
  }
  std::cout << std::endl << std::endl; 
  std::cout << "Duzina najduze podsekvence odredjena rekurzijom sa memorizacijom je: ";
  std::cout << memory(niz,niz1,n,n1) << std::endl;
  std::cout << "Elementi niza koristenog u memorizaciji poslje memorizacije su : "; 
  std::cout << std::endl ;
  for(auto i = 0; i < n ; ++i) 
  {
   std::cout << NIZ[i] << "\t";
  }
  std::cout  << std::endl << std::endl;
  int a=dinamic(niz,niz1,n,n1);
  std::cout << "Duzina najduze podsekvence odredjena dinamickim programiranjem je: ";
  std::cout << a << std::endl;
  sekvenca(niz , n);
  
  return 0;
  }
  
  


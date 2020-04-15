#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct ride
{
  string name;
  int price;
  int durat;
  ride()=default;
  ride(string s,int p, int d):name{s},price{p},durat{d}{}
  void print()
  {
    cout<<"Name: "<<name<<endl;
    cout<<"Price: "<<price<<endl;
    cout<<"Duration: "<<durat<<endl;
  }
};

int problem5(ride *rides,int size_,int max_price)
{
  if(size_==0 || max_price==0)
    return 0;

  if(rides[size_-1].price>max_price)
    return(problem5(rides,size_-1,max_price));
  else
    return max(problem5(rides,size_-1,max_price),rides[size_-1].durat+problem5(rides,size_-1,max_price-rides[size_-1].price));
}

void problem5dp(ride *rides,int size_,int max_price)
{
  int n=max_price+1;
  int m=size_;
  int T[m][n];
  for(int i=0;i<n;++i)
    T[0][i]=0;
  for(int i=0;i<m;++i)
    T[i][0]=0;

  for(int i=1;i<size_;++i)
  {
    for(int j=1;j<=max_price;++j)
    {
      if(rides[i].price>j)
        T[i][j]=T[i-1][j];
      else
        T[i][j]=max(T[i-1][j],rides[i].durat+T[i-1][j-rides[i].price]);
    }
  }
  cout<<"Najduze vrijeme koje se moze provesti na voznjama: "<<T[m-1][n-1]<<endl;
  cout<<"Voznje koje treba odabrati:\n\n";
  for(int i=m-1,j=n-1;i && j; )
  {
    if(T[i][j]==T[i-1][j])
      --i;
    else
    {
      rides[i].print();
      cout<<endl;
      j=j-rides[i].price;
      --i;
    }
  }
}

int main(int argc,char ** argv)
{
  ride voznje[7];
  voznje[1]=ride("Voznja 6",1,10);
  voznje[2]=ride("Voznja 4",2,2);
  voznje[3]=ride("Voznja 5",3,4);
  voznje[4]=ride("Voznja 3",4,35);
  voznje[5]=ride("Voznja 2",5,18);
  voznje[6]=ride("Voznja 1",10,40);
  problem5dp(voznje,7,10);
  cout<<problem5(voznje,7,10)<<endl;
  return 0;
}

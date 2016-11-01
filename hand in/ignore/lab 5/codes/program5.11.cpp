#include <iostream>
using namespace std;

class Cone
{
	private:
   	double radius;
   public:
   	Cone(double);
      Cone();
   	double getRadius();
      void longestRadius(Cone[]);
};
Cone:: Cone(double a)
{
	radius=a;
}
Cone:: Cone()
{
	radius=3.5;
}
double Cone::getRadius()
{	return radius;}

void Cone::longestRadius(Cone c[])
{
	double longest;
  for(int i=0; i<3;i++)
  {
  	  if(c[i].getRadius()<c[i+1].getRadius())
        longest=c[i+1].getRadius();
      else
        longest=c[i].getRadius();
  }
      cout<<longest;
}

int main()
{
   Cone c1[3]={4.5, Cone(5.5), Cone(7.5)};
   Cone c2;
   for(int i=0;i<3;i++)
	   c1[i].getRadius();
   c2.longestRadius(c1);

   return 0;
}

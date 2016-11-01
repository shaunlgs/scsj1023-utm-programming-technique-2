#include <iostream>
using namespace std;

class BMI{
  private:
    double weight;
    double height;
    void initialize(double w, double h);
  public:
    BMI (double w, double h);
    BMI (double b);
    BMI ();
    ~BMI ();
    double getBMI() const;
    void print() const;
};

void BMI::initialize(double w, double h)
{  weight = w;
   height = h;
   cout << "The object has just been created" << endl;
   print();
}

BMI::BMI (double w, double h)
{  initialize(w,h); }

BMI::BMI (double b)
{  initialize(b,b); }

BMI::BMI ()
{  initialize(0,0); }

double BMI::getBMI () const
{
	return (weight / (height * height));
}

void BMI::print() const
{
	cout <<"Weight: " << weight << endl
	     <<"Height: " << height << endl << endl;
}

BMI::~BMI (){
    cout << "The object is being destroyed" << endl;
    print();
}

int main()
{
   BMI b[3] = { BMI(180.2,132),
                      BMI(155.4,69.6),
                      BMI(139,100)};

   cout<<"The area of b1 is "<<b[0].getBMI()<<endl;
   cout<<"The area of b2 is "<<b[1].getBMI()<<endl;
   cout<<"The area of b3 is "<<b[2].getBMI()<<endl;
   return 0;
}


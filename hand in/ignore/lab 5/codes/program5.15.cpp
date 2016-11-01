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
    BMI b1(150,120);
    BMI *b2;
    BMI *b3 = new BMI(175,74);
    b2 = new BMI;

    cout<<"The area of b1 is "<<b1.getBMI()<<endl;
    cout<<"The area of b2 is "<<b2->getBMI()<<endl;
    cout<<"The area of b3 is "<<b3->getBMI()<<endl;
    delete b3;

    return 0;
}

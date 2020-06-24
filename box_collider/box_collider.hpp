#include <iostream>

using namespace std;

class box_collider{

public:
  box_collider(long double mi1,long double mi2);

  void isDebug(bool is) {debug=is;}
    
  bool hit();

private:
  long double econ() {return 0.5*m1*v1*v1+0.5*m2*v2*v2;}
  long double pcon() {return m1*v1+m2*v2;}

  long double m1,m2;
  long double v1,v2;

  bool debug;

};

box_collider::box_collider(long double mi1, long double mi2):
  m1(mi1),m2(mi2),v1(0.0),v2(-1.0),debug(false)
{}

bool box_collider::hit(){

  if (v1<0) {
    v1=-v1;
    return true;
  }
  else if (v1>=0 && v2>=0 && v1<=v2){
    if (debug){
      cout << " Final E,p : " << econ() << ", " << pcon()
	   << " Final V1,V2 : " << v1 << ", " << v2 << endl;
    }
    return false;
  }

  long double ei = econ();
  long double pi = pcon();
  long double v1i = v1;
  long double v2i = v2;

  v1 = ((m1-m2)/(m1+m2))*v1i+(2.0*m2/(m1+m2))*v2i;
  v2 = (2.0*m1/(m1+m2))*v1i+((m2-m1)/(m1+m2))*v2i;

  if (debug){
    cout << " Initial E,p : " << ei << ", " << pi
	 << " Initial V1,V2 : " << v1i << ", " << v2i
	 << " Final E,p : " << econ() << ", " << pcon()
	 << " Final V1,V2 : " << v1 << ", " << v2 << endl;
  }
  
  if (v1>=0 && v2>=0 && v1<=v2)
    return false;
  else
    return true;
  
}

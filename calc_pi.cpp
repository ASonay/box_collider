#include <iostream>
#include <stdlib.h>

#include "box_collider/box_collider.hpp"

using namespace std;

void argParser(long double &m1,long double &m2,string &verb,int argc, char** argv);
int main(int argc, char** argv)
{
  long double m1=1;
  long double m2=100;
  string verb="NONE";

  argParser(m1,m2,verb,argc,argv);
  
  box_collider box(m1,m2);

  if (verb=="DEBUG" || verb=="debug" || verb=="Debug")
    box.isDebug(true);

  unsigned long long count=0;

  while (box.hit())
    count++;

  cout << "TOTAL COUNT : " << count << endl;
  
}

void argParser(long double &m1,long double &m2,string &verb,int argc, char** argv)
{
  if (argc>1)
    m1=atof(argv[1]);
  else
    cout << "Default M1 and M2 will be used.." << endl;
  
  if (argc>2)
    m2=atof(argv[2]);
  
  if (argc>3)
    verb=argv[3];

  if (m1<0 || m2<0)
    cout << "Negative mass will not be accepted." << endl;

  m1=abs(m1);
  m2=abs(m2);

  if (m1==0){
    m1=1;
    cout << "Zero mass will not be accepted." << endl;
  }

  if (m2==0){
    m2=100;
    cout << "Zero mass will not be accepted." << endl;
  }
 
  cout << "M1=" << m1 << endl;
  cout << "M2=" << m2 << endl;
}

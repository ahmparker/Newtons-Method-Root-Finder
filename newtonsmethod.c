#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

complex f (complex x){
  return ((3 * x * x * x) - (19 * x * x) + (81 * x) - 25); //this is our f(x)!
}
complex g (complex x){  //this is our method that finds f'(x).
  double h = 0.000001;
  complex z = f(x + h);
  complex y = f(x);
  return ((z-y) / h) ;
}
complex inc(){ //this method takes the user's inputted guess and returns it
  double a,b;
  scanf("%lf %lf",&a, &b) ;
  return a + b*I;
}
int deg(){
  int a;
  scanf("%d", &a);
  return a;
}

complex shrink(complex a){ //this is newton's method
  complex x1 = a;
  complex x2;

  x2 = x1 - (f(a) / g(a));
  x1 = x2;
  return x2;
}
void outc(complex x) //this outputs our "shrunken" guess
{
  printf("%14.10lf + %14.10lf i\n", creal(x), cimag(x)) ;
}

int main(){ //main method
  complex r;
  int d,i;
  printf("enter coefficients  : ") ;
  d = deg();
  printf("enter your root guess : ") ;
  r = inc(); 
  for (i = 1; i < 40; i++){
    r = shrink(r);
    printf("%d : ",i );
    outc(r);
  }
}

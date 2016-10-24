#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){

      if(argc!=5){
       cout << "Error. Inserte los dos pares ordenados de coordenadas [ <x0> <y0> <x1> <y1> ]." << endl;
      }

      ofstream coord, tiempo;
      tiempo.open("tiempo.csv", std::ofstream::out | std::ofstream::app);
      coord.open ("linea.csv");
      tiempo << "\n"; 
	int dx, dy, x1, x0, y1, y0, x, y, deltap1, deltap2, xend, p, n;
	x0 = atoi(argv[1]);
	y0 = atoi(argv[2]);
	x1 = atoi(argv[3]);
	y1 = atoi(argv[4]);
       
        clock_t t;
        /*AQUI EMPIEZA EL ALGORITMO*/
        t = clock();
	dx = abs(x1-x0);
	dy = abs(y1-y0);
	p  = 2*dy-dx;
        deltap1 = 2*dy;
        deltap2 = 2*dy-2*dx;        
  
	if(x0>x1)
	{
	  x = x1;
	  y = y1;
	  xend = x0; 	
	}else{
	  x = x0;
	  y = y0;
	  xend = x1;
	} 

	//cout << "Las coordenadas de los pixeles son: " << endl;
	while(x<=xend)
	{
          // coord << x;
	  // coord << ",";
	  // coord << y;
	  // coord << "\n";
	//   cout << "( " << x << ", " << y << " )" << endl;
	   x=x+1;
	   if(p<0)
	    p=p+deltap1;
	   else
	   {
	    y=y+1;
	    p=p+deltap2;
	   }    
	}
        /*AQUI TERMINA EL ALGORITMO*/
        tiempo << (float)(clock() - t)/CLOCKS_PER_SEC;

     //   cout << "Tiempo de ejecucion: " << (float)(clock() - t)/CLOCKS_PER_SEC << " segundos." << endl;

        tiempo << ",";
        n = dx + 1;
        tiempo << n;
        
        coord.close();
        tiempo.close();

	return 0;
}

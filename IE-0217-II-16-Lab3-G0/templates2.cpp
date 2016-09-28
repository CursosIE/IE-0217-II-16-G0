/**
 * @file
 * @author  	Felipe Moya Coto <moyafelipe94@gmail.com> - Emanuel Hernández <emanuel.hernandezcastillo@gmail.com>
 * @version 1.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * https://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 *
 * Programa que implementa una distintas clases utilizando templates
 * se sobrecargan operadores para realizar operaciones sobre los elementos de las distintas clases
 */

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>       /* time */


using namespace std;

#define FILAS 4 /* Filas de la Matriz  */
#define COLUMNAS 5 /* Columnas de la Matriz  */

//! Clase calculadora para realizar operaciones sobre objetos dados.
	 /*!
   \param d1 Puntero al primer objeto sobre el cual se va realizar la operacion.
   \param d2 Puntero al segundo objeto sobre el cual se va realizar la operacion.
   */
template <typename data>
class Calculadora{
   public:
   Calculadora(){} //Constructor
   ~Calculadora(){} //Destructor
   data add(const data &d1, const data &d2);
   data sub(const data &d1, const data &d2);
   data mul(const data &d1, const data &d2);
   data div(const data &d1, const data &d2);
   data print(const data &d1);
};

template <typename data>
data Calculadora<data>::add(const data &d1, const data &d2){
   data resultado;
   resultado = d1 + d2;
   return resultado;
}

template <typename data>
data Calculadora<data>::sub(const data &d1, const data &d2){
   data resultado;
   resultado = d1 - d2;
   return resultado;
}

template <typename data>
data Calculadora<data>::mul(const data &d1, const data &d2){
   data resultado;
   resultado = d1 * d2;
   return resultado;
}

template <typename data>
data Calculadora<data>::div(const data &d1, const data &d2){
   data resultado;
   resultado = d1 / d2;
   return resultado;
}

template <typename data>
data Calculadora<data>::print(const data &d1){
   cout << "El resultado es : " << d1 << endl;
   return d1;
}

//! Clase   Polinomio, sobrecarga de operadores para realizar operaciones sobre polinomios.
	 /*!
   \param ordenMax define el orden maximo del polinomio sobre el cual se esta operando.
   */

template <typename data>
class Polinomio{
    public:
     Polinomio(){}
    ~Polinomio(){}
     int ordenMax;
     //data *coeffs;
     //coeffs = new data [ordenMax+1];
     data coeffs[100];
     Polinomio<data> operator+(const Polinomio &p2);
     Polinomio<data> operator-(const Polinomio &p2);
     Polinomio<data> operator*(const Polinomio &p2);
     Polinomio<data> operator/(const Polinomio &p2);
     Polinomio<data> operator~();
};

//! sobrecarga del operador + para realizar suma sobre objetos de la clase Polinomio.
template <typename data>
Polinomio<data> Polinomio<data>::operator+ (const Polinomio &p2) {
    Polinomio<data> resultado;
    resultado.ordenMax = max(ordenMax, p2.ordenMax);
    for (int i = 0; i <= ordenMax; i++)
    {
          resultado.coeffs[i] = coeffs[i] + p2.coeffs[i];
    }
    return resultado;
}

//! sobrecarga del operador - para realizar resta sobre objetos de la clase Polinomio.
template <typename data>
Polinomio<data> Polinomio<data>::operator- (const Polinomio &p2) {
    Polinomio<data> resultado;
    resultado.ordenMax = max(ordenMax, p2.ordenMax);
    for (int i = 0; i <= ordenMax; i++)
    {
          resultado.coeffs[i] = coeffs[i] - p2.coeffs[i];
    }
    return resultado;
}
//! sobrecarga del operador * para realizar multiplicacion sobre objetos de la clase Polinomio.
template <typename data>
Polinomio<data> Polinomio<data>::operator* (const Polinomio &p2) {
    Polinomio<data> resultado;
    resultado.ordenMax = ordenMax + p2.ordenMax;
      for(int i = ordenMax; i >= 0; i--)
      {
        for(int j = p2.ordenMax; j >= 0; j--){
          resultado.coeffs[i+j] += coeffs[i] * p2.coeffs[j];
        }
      }
    return resultado;
}
//! sobrecarga del operador / para realizar division sobre objetos de la clase Polinomio.
template <typename data>
Polinomio<data> Polinomio<data>::operator/ (const Polinomio &p2) {

    Polinomio<data> resultado;
    resultado.ordenMax = ordenMax - p2.ordenMax;
    data temp;
    if(ordenMax < p2.ordenMax){
      cout << "Orden de denominador es mayor que el del numerador... Cerrando." << endl;
      exit(0);
    }
    else{
    bool salir = false;
      for(int i = ordenMax; i >= 0; i--)
      {
        if(salir)
        {
         break;
        }
        for(int j = p2.ordenMax; j >= 0; j--){
          if(i<j){
            salir = true;
	    break;
          }
          if(j==p2.ordenMax){
            resultado.coeffs[i-j] = coeffs[i] / p2.coeffs[p2.ordenMax];
            temp = resultado.coeffs[i-j];
          }
          coeffs[i-p2.ordenMax+j] = coeffs[i-p2.ordenMax+j] - temp * p2.coeffs[j];
    //      cout << "temp = " <<temp << endl;
    //      cout << "coeffs[" << i-p2.ordenMax+j << "] = " << coeffs[i-p2.ordenMax+j] << endl;
        }
      }
    }
    return resultado;
}
//! sobrecarga del operador ~ para realizar impresion sobre objetos de la clase Polinomio.
template <typename data>
Polinomio<data> Polinomio<data>::operator~(){
   cout << "Polinomio resultante:\nP(x) = ";
   for(int j = ordenMax; j > 0 ; j--) {
    if (j == 1)
       cout  << coeffs[j] << "x" << " + ";
    else
       cout << coeffs[j] << "x^" << j << " + ";
    }
    cout << coeffs[0] << endl;
}


//! Clase Fraccion, sobrecarga de operadores para realizar operaciones sobre fracciones.
	 /*!
   \param num numerador de la funcion a operar.
   \param den denominador de la funcion a operar.
   */
template <typename data>
class Fraccion{
    public:
     Fraccion(){}
    ~Fraccion(){}
     double num;
     double den;
     Fraccion<data> operator+(const Fraccion &f2);
     Fraccion<data> operator-(const Fraccion &f2);
     Fraccion<data> operator*(const Fraccion &f2);
     Fraccion<data> operator/(const Fraccion &f2);
     Fraccion<data> operator~();
};
//! sobrecarga del operador + para realizar suma sobre objetos de la clase Fraccion.
template <typename data>
Fraccion<data> Fraccion<data>::operator+ (const Fraccion &f2) {
    Fraccion<data> resultado;
    resultado.num = (num*f2.den+den*f2.num);
    resultado.den= (den*f2.den);
    return resultado;
}
//! sobrecarga del operador - para realizar resta sobre objetos de la clase Fraccion.
template <typename data>
Fraccion<data> Fraccion<data>::operator- (const Fraccion &f2) {
    Fraccion<data> resultado;
    resultado.num = (num*f2.den-den*f2.num);
    resultado.den= (den*f2.den);
    return resultado;
}
//! sobrecarga del operador * para realizar multiplicacion sobre objetos de la clase Fraccion.
template <typename data>
Fraccion<data> Fraccion<data>::operator* (const Fraccion &f2) {
    Fraccion<data> resultado;
    resultado.num = (num*f2.num);
    resultado.den= (den*f2.den);
    return resultado;
}
//! sobrecarga del operador / para realizar division sobre objetos de la clase Fraccion.
template <typename data>
Fraccion<data> Fraccion<data>::operator/ (const Fraccion &f2) {
    Fraccion<data> resultado;
    resultado.num = (num*f2.den);
    resultado.den= (den*f2.num);
    return resultado;
}
//! sobrecarga del operador ~ para realizar impresion sobre objetos de la clase Fraccion.
template <typename data>
Fraccion<data> Fraccion<data>::operator~(){
   cout << "Fraccion resultante:\n  A/B = ";
  cout << num <<"/"<<den << endl;
}


//! Clase Matriz, sobrecarga de operadores para realizar operaciones sobre matrices.
	 /*!
   \param filas cantidad de filas de la matriz a operar.
   \param columnas cantidad de columnas de la matriz a operar.
   \param valid se utiliza como bandera para determinar si la operacion es valida segun los tamanos de las matrices a operar.
   */
template <typename data>
class Matriz{
    public:
     Matriz(){}
    ~Matriz(){}
    double  arreglo[100][100];
    int filas;
    int columnas;
    int valid;

     Matriz<data> operator+(const Matriz &m2);
     Matriz<data> operator-(const Matriz &m2);
     Matriz<data> operator*(const Matriz &m2);
     Matriz<data> operator/(const Matriz &m2);
     Matriz<data> operator~();
};
//! sobrecarga del operador + para realizar suma sobre objetos de la clase Matriz.
template <typename data>
Matriz<data> Matriz<data>::operator+ (const Matriz &m2) {
    Matriz<data> resultado;
    if (filas==m2.filas && columnas==m2.columnas){
      for(int i = 0; i<filas; i++)     {
          for(int j = 0; j<columnas; j++)     {
           resultado.arreglo[i][j]=arreglo[i][j]+m2.arreglo[i][j];
             if(j==COLUMNAS-1){
         }
       }
     }
     resultado.valid=1;
  }else{
  resultado.valid=0;
  }
    resultado.filas=filas;
    resultado.columnas=columnas;
    return resultado;
}
//! sobrecarga del operador - para realizar resta sobre objetos de la clase Matriz.
template <typename data>
Matriz<data> Matriz<data>::operator- (const Matriz &m2) {
    Matriz<data> resultado;
    if (filas==m2.filas && columnas==m2.columnas){
      for(int i = 0; i<filas; i++)     {
          for(int j = 0; j<columnas; j++)     {
           resultado.arreglo[i][j]=arreglo[i][j]-m2.arreglo[i][j];
             if(j==COLUMNAS-1){
         }
       }
     }
     resultado.valid=1;
  }else{
  resultado.valid=0;
  }
    resultado.filas=filas;
    resultado.columnas=columnas;
    return resultado;
}
//! sobrecarga del operador * para realizar multiplicacion sobre objetos de la clase Matriz.
template <typename data>
Matriz<data> Matriz<data>::operator* (const Matriz &m2) {
    Matriz<data> resultado;
    if (columnas==m2.filas){
      resultado.filas=filas;
      resultado.columnas=m2.columnas;
      for(int i=0; i<filas; ++i){
           for(int j=0; j<m2.columnas; ++j){
               for(int z=0; z<columnas; ++z){
                   resultado.arreglo[i][j] += arreglo[i][z] * m2.arreglo[z][j];
                    //cout << "m1["<<i<<"]["<<z<<"]="<<arreglo[i][z] << endl;
                    //cout << "m2["<<z<<"]["<<j<<"]="<<m2.arreglo[z][j] << endl;
                    //cout << "resultado["<<i<<"]["<<j<<"]="<<resultado.arreglo[i][j] << endl;
                 }
              //   cout << "-------------------------------------------" << endl;
               }
               //cout << "a" << endl;

            }
            cout << "Resultado" << endl;
     resultado.valid=1;
  }else{
  resultado.valid=0;
  }
    return resultado;
}
//! sobrecarga del operador / para realizar division sobre objetos de la clase Matriz.
template <typename data>
Matriz<data> Matriz<data>::operator/ (const Matriz &m2) {
    Matriz<data> resultado;
    if (filas==m2.filas && columnas==m2.columnas){
      for(int i = 0; i<filas; i++)     {
          for(int j = 0; j<columnas; j++)     {
           resultado.arreglo[i][j]=arreglo[i][j]/m2.arreglo[i][j];
             if(j==COLUMNAS-1){
         }
       }
     }
     resultado.valid=1;
  }else{
  resultado.valid=0;
  }
    resultado.filas=filas;
    resultado.columnas=columnas;
    return resultado;
}
//! sobrecarga del operador ~ para realizar impresion sobre objetos de la clase Matriz.
template <typename data>
Matriz<data> Matriz<data>::operator~(){
  if (valid==1){
    for(int i = 0; i<filas; i++)     {
      for(int j = 0; j<columnas; j++)     {
          cout << arreglo[i][j];
          cout << " " ;
          if(j==columnas-1){
            cout << "" << endl;
       }
     }
   }
}else{
cout << "IMPOSIBLE REALIZAR SUMA TAMAÑOS NO COINCIDEN" << endl;;
}
}


//! Funcion  principal se instancias las clases y se llaman a los operadores sobre cargados de estas.
	 /*!
   \
   */
int main(){
   srand (time(NULL));

  Calculadora <int> calcu;
  int x = 6;
  int y = 2;
  int z;
  cout << "Calculadora: \n" << "x = " << x << ", y = " << y << endl;
  cout << "Suma: " << endl;
  z = calcu.add(x,y);
  calcu.print(z);
  cout << "Resta: " << endl;
  z = calcu.sub(x,y);
  calcu.print(z);
  cout << "Mult: " << endl;
  z = calcu.mul(x,y);
  calcu.print(z);
  cout << "Div: " << endl;
  z = calcu.div(x,y);
  calcu.print(z);
  cout <<"__________________________" << endl;
  cout << "POLINOMIOS" << endl;
  Polinomio <float> p1;
  Polinomio <float> p2;
  Polinomio <float> p3;
  p1.ordenMax = 3;
  p2.ordenMax = 1;
  p1.coeffs[0] = -1; p1.coeffs[1] = 2; p1.coeffs[2] = -5; p1.coeffs[3] = 3;

  cout << "Polinomio 1:\nP1(x) = ";
   for(int j = p1.ordenMax; j > 0 ; j--) {
    if (j == 1)
       cout  << p1.coeffs[j] << "x" << " + ";
    else
       cout << p1.coeffs[j] << "x^" << j << " + ";
    }
    cout << p1.coeffs[0] << endl;


//p1.coeffs[4] = 4;
  p2.coeffs[0] = 1; p2.coeffs[1] = 2;// p2.coeffs[2] = 1;
  cout << "Polinomio 2:\nP2(x) = ";
   for(int j = p2.ordenMax; j > 0 ; j--) {
    if (j == 1)
       cout  << p2.coeffs[j] << "x" << " + ";
    else
       cout << p2.coeffs[j] << "x^" << j << " + ";
    }
    cout << p2.coeffs[0] << endl;


  p3 = p1 / p2;

  ~p3;
//----------------------------
//----------------------------
  Fraccion <float> f1;
  Fraccion <float> f2;
  Fraccion <float> f3;
  f1.num=7;
  f1.den=3;
  f2.num=5;
  f2.den=7;
  cout <<"__________________________"<< endl;
  cout << "FRACCION" << endl;
  cout <<"__________________________"<< endl;
  cout << "Fraccion 1: "<<f1.num<<"/"<<f1.den << endl;
  cout << "Fraccion 2: "<<f2.num<<"/"<<f2.den << endl;
cout << "----------------------" << endl;
cout << "Suma" << endl;
cout << "----------------------" << endl;
  f3=f1 +f2;
  ~f3;
cout << "----------------------" << endl;
cout << "Resta" << endl;
cout << "----------------------" << endl;
  f3=f1 -f2;
  ~f3;
cout << "----------------------" << endl;
cout << "Multiplicacion" << endl;
cout << "----------------------" << endl;
  f3=f1 *f2;
  ~f3;
cout << "----------------------" << endl;
cout << "Division" << endl;
cout << "----------------------" << endl;
  f3=f1 /f2;
  ~f3;
cout << "_________________________" << endl;
cout << "Matriz" << endl;
cout << "_________________________" << endl;
  Matriz <float> m1;
  Matriz <float> m2;
  Matriz <float> m3;
  Matriz <float> m4;
  m1.filas=FILAS;
  m1.columnas=COLUMNAS;
  cout <<"----------------------"<< endl;
  cout << "MATRIZ A" << endl;
  cout << "Filas = " <<m1.filas<< endl;
  cout << "Columnas = " <<m1.columnas<< endl;
  cout << "----------------------"<< endl;
   for(int m = 0; m<m1.filas; m++)     {
       for(int n = 0; n<m1.columnas; n++)     {
        m1.arreglo[m][n]=rand()%10+1;
        cout << m1.arreglo[m][n];
        cout << " " ;
          if(n==m1.columnas-1){
        cout << "" << endl;
      }
    }
  }
   m2.filas=FILAS;
   m2.columnas=COLUMNAS;

  cout << "__________________________" << endl;
  cout << "MATRIZ B" << endl;
  cout << "Filas = " <<m2.filas<< endl;
  cout << "Columnas = " <<m2.columnas<< endl;
  cout << "__________________________"<< endl;
  for(int m = 0; m<m2.filas; m++)     {
    //cout << "m="<<m << endl;
      for(int n = 0; n<m2.columnas; n++)     {
        m2.arreglo[m][n]=rand()%10+1;
        cout << m2.arreglo[m][n];
        cout << " " ;
      // cout << "n=" <<n<< endl;
         if(n==m2.columnas-1){
        cout << "" << endl;
      }
    }
  }
  m4.filas=5;
  m4.columnas=4;
  cout << "__________________________" << endl;
  cout << "MATRIZ C" << endl;
  cout << "Filas = " <<m4.filas<< endl;
  cout << "Columnas = " <<m4.columnas<< endl;
  cout << "__________________________"<< endl;
  for(int m = 0; m<m4.filas; m++)     {
    //cout << "m="<<m << endl;
      for(int n = 0; n<m4.columnas; n++)     {
        m4.arreglo[m][n]=rand()%10+1;
        cout << m4.arreglo[m][n];
        cout << " " ;
      // cout << "n=" <<n<< endl;
         if(n==m4.columnas-1){
        cout << "" << endl;
      }
    }
  }


//----------------------------
//Suma
//----------------------------
cout << "----------------------" << endl;
cout << "Suma MATRIZ A + MATRIZ B " << endl;
cout << "----------------------" << endl;
   m3=m1 +m2;
   ~m3;
cout << "----------------------" << endl;
cout << "Resta MATRIZ A - MATRIZ B " << endl;
cout << "----------------------" << endl;
   m3=m1 -m2;
   ~m3;

cout << "----------------------" << endl;
cout << "Multiplicacion MATRIZ A * MATRIZ C" << endl;
cout << "----------------------" << endl;
  m3=m1 *m4;
  ~m3;
  cout << "----------------------" << endl;
  cout << "Division MATRIZ A / MATRIZ B" << endl;
  cout << "----------------------" << endl;
    m3=m1 /m2;
    ~m3;




return 0;



}

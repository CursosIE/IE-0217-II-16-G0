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
 * Programa que implementa pilas y colas para simular al ingreso a un casino
 */
#include <cstdlib>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <time.h>       /* time */
#include <string>

//#include <string.h>

using namespace std;
//! Class node
	 /*!
   \param data Almacena la informacion.
   \param priority Define la prioridad de elementos.
   \param next puntero al siguiente nodo.
	 */

template <typename type>
class node{
     public:
     type data;
     float priority;
     node<type> *next;

     node<type> *createNode(type info, float priority);
};

template <typename type>
node<type> *node<type>::createNode(type info, float priority)
{
	node<type> *newNode = new node<type>;
        newNode->data = info;
        newNode->priority = priority;
        return newNode;
}
//! Class queu
	 /*!
   \param head Puntero al primer elemento de la cola.
   \param tail Puntero al ultimo elemento de la cola.
	 */
template <typename type>
class queu{
      public:
      node<type> *head;
      node<type> *tail;
      void push(queu<type> &q, type j, float priority);
      void pop(queu<type> &q);
      void deleteQueu(queu<type> &q);
      void printQueu(queu<type> &q);
      void prioritize(queu<type> &q);

};

template <typename type>
void queu<type>::push(queu<type> &q , type j, float priority) //q para queu, j para job
{
      node<type> *temp = new node<type>;  //nodo temporal para empujar los nodos nuevos
      temp = temp->createNode(j , priority);
      temp->next = NULL;
      //cout << "DEBUG" << endl;
      if(q.head == NULL)
      {
        q.head = temp;
      }else  //Si head es nulo, significa que la cola esta vacia
      {
        (q.tail)->next = temp;
      }

      //delete(temp);
      q.tail = temp;
}

template <typename type>
void queu<type>::pop(queu<type> &q) //q para queu, j para job
{
      node<type> *temp = new node<type>;  //nodo temporal, como es puntero, al borrarlo, se borra el elemento de la cola

      temp   = q.head;           //se guarda la direccion del head del queu
      q.head = (q.head)->next;   //se shiftea el siguiente elemento del queu
      delete(temp);              //se borra el primer elemento del queu
}

template <typename type>
void queu<type>::deleteQueu(queu<type> &q)
{
     node<type> *temp;
     while( q.head != NULL)
     {
            temp = q.head;
            q.head = temp->next;
            delete(temp);
     }
     q.head = NULL;
     q.tail = NULL;

}

template <typename type>
void queu<type>::printQueu(queu<type> &q)
{
     node<type> *temp;
     temp = q.head;
     //cout << "EL TIPO ES: " << typeid(type).name() << endl;

     /*
       while( temp != NULL)
       {
         cout << " " << temp->data;
         temp = temp->next;
       }
      */
       while( temp != NULL)
       {
         cout << " " << temp->data;
         temp = temp->next;
       }

      cout << "\n";
}

template <typename type>
void queu<type>::prioritize(queu<type> &q)
{
     node<type> *temp1, *temp2;  //dos temporales, una para moverse en la cola, y la otra cola es para realizar el intercambio
     temp1  = q.head;
     int prior_temp;
     type data_temp;

     while(temp1->next != NULL)
     {
           temp2 = temp1->next;
           while(temp2 != NULL){
	     if(temp1->priority < temp2->priority)
             {
               prior_temp = temp1->priority;
               data_temp  = temp1->data;
               temp1->priority = temp2->priority;
               temp1->data     = temp2->data;
               temp2->priority = prior_temp;
               temp2->data     = data_temp;
             }
            temp2 = temp2->next;
           }
           temp1 = temp1->next;
     }
}

//! Class Carta
	 /*!
   \param Valor Representa el valor de la carta.
   \param tipo  Representa los distintos palos de las cartas.
	 */

class Carta{
public:
  Carta(){};
  vector<string> valor={"A ","2 ","3 ","4 ","5 ","6 ","7 ","8 ","9 ","10 ","J ","Q ","K "};
  vector<string> tipo={"Corazones ","Bastos ","Trebol ","Diamantes "};
  string* getValor(){
    string *p1;
    p1= &valor[0];
    return p1;
  }
  string* getTipo(){
    string *p2;
    p2= &tipo[0];
    return p2;
  }

};
//! Class Maso
	 /*!
   \param pila_maso Pila con todas las cartas en orden.
   \param pila_maso_barajado Pila con todas las cartas barajadas.
	 */

class Maso{
public:
  Maso(){};
     stack <string>  pila_maso;
     stack <string>  pila_maso_barajado;
     string cartas[52];
     int c1=0;
     string temp2;
     string* crearMaso(string *p1, string *p2){
       string *p2b;
       p2b=p2;
       for(int i=0;i<13;i++){
         for (int j=0;j<4;j++){
          //  std::cout << "*p1:" <<*p1<< std::endl;
          //  std::cout << "*p2:" <<*p2b<< std::endl;
           pila_maso.push(*p1 + *p2b );

          // std::cout << "pila_maso.top()" <<pila_maso.top()<< std::endl;
           cartas[c1]=pila_maso.top();
           //std::cerr << "cartas:" <<cartas[c1]<< std::endl;
           p2b++;
           c1++;
         }
         p2b=p2;
         p1++;

       }
     }
     string* barajar(){
       int random1, random2;
       string tmp;
       for(int c2=0; c2<=50;c2++){
         random1= rand()%52;
         random2= rand()%52;
         tmp=cartas[random1];
         cartas[random1]=cartas[random2];
         cartas[random2]=tmp;
       }
       for(int c3=0;c3<52;c3++){
         pila_maso_barajado.push(cartas[c3]);
        // std::cout << "CARTA #:" <<c3<< std::endl;
          //std::cout << "pila_maso:barajado.top()" <<pila_maso_barajado.top()<< std::endl;
        //  std::cout << pila_maso_barajado.top() << std::endl;
       }
     }
    string getCarta(){
      temp2=pila_maso_barajado.top();
      pila_maso_barajado.pop();
    //  std::cout << "temp2=" <<temp2<< std::endl;
      return temp2;
    }
};
//! Class Mesa
	 /*!
   \param jugador1 jugador 1 de la mesa.
   \param jugador2 jugador 2 de la mesa.
   \param jugador3 jugador 3 de la mesa
	 */

class Mesa{
public:
  char jugador1='-';
  char jugador2='-';
  char jugador3='-';
  int campos_libres=3;
  void setCampos_libres(int n){
    campos_libres=n;
  }
  int getCampos_libres(){
    return campos_libres;
  }
  Mesa(){};
  void setJugador1(char nombre){
    jugador1=nombre;
  }
  void setJugador2(char  nombre){
    jugador2=nombre;
  }
  void setJugador3(char  nombre){
    jugador3=nombre;
  }
  char getJugador1(){
    return jugador1;
  }
  char getJugador2(){
    return jugador2;
  }
  char getJugador3(){
    return jugador3;
  }
  int getPuntos(string carta){
  char valor = carta.at(0);
  //std::cout << "valor: " <<valor<< std::endl;
  switch (valor) {
    case 'A':
      return 11;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
    case '8':
      return 8;
    case '9':
      return 9;
    case '1':
      return 10;
    case 'J':
      return 10;
    case 'Q':
      return 10;
    case 'K':
      return 10;
    }
  }


};
//! Class Jugador
	 /*!
   \param nombre Nombre del jugador .
   \param total total de puntos en el blackjack.
	 */

class Jugador{
public:
  char nombre;
  int total;
  void setNombre(char n){
    nombre= n;
  }
  char getNombre (){
    return nombre;
  }
  int accion(int puntos){
  if (puntos<19){
    return 1;
  }
    else{
    return 0;
    }

}
};
int main(int argc, char *argv[])
{
 if(argc!=2){
   cout << "Argumentos invalidos (argc!=2 o typeid(type)!=char)." << endl;
   exit(0);
  }
  srand (time(NULL));
  queu<char> my_q;
  queu<char> cola;
  cola.head = NULL;                 //se declara la cola vacia en un inicio
  cola.tail = NULL;
  my_q.head = NULL;                 //se declara la cola vacia en un inicio
  my_q.tail = NULL;
  char e = 'E';
  char d = 'D';
  char t = 'T';
  string cadena = argv[1];

  // for(int i = 0; i < cadena.length(); i++) //-----------> ESTO ES EL PSEUDOCODIGO DE LO QUE QUERIA HACER
  // {
  //
  //    if(cadena.at(i) == 'E')
  //     my_q.push(my_q, cadena.at(i), 2);
  //    if(cadena.at(i) == 'T')
  //     my_q.push(my_q, cadena.at(i), 1);
  //    if(cadena.at(i) == 'D')
  //     my_q.push(my_q, cadena.at(i), 0.5);
  // }
  //
  //
  // cout << "La cola es: " << endl;
  // my_q.printQueu(my_q);
  //
  // my_q.prioritize(my_q);
  // cout << "La cola con prioridad es: "  << endl;  /* 4,7,5,8---> 8,7,5,4 */
  // my_q.printQueu(my_q);
  // my_q.deleteQueu(my_q);
  //

  Carta cartita;
  Maso masito;
  Maso maso1;
  Maso maso2;
  Maso maso3;
  Mesa mesita;
  Mesa mesa1;
  Mesa mesa2;
  Mesa mesa3;
  Jugador jugador1;
  Jugador jugador2;
  Jugador jugador3;
  string *puntero1, *puntero2, *puntero3,*puntero4,*puntero5,*puntero6;
  string carta;
  int puntos;
  puntero1= cartita.getValor();
  puntero2= cartita.getTipo();
  puntero3= cartita.getValor();
  puntero4= cartita.getTipo();
   puntero5= cartita.getValor();
   puntero6= cartita.getTipo();
  // std::cout << "puntero 1:" <<puntero1<< std::endl;
  // std::cout << "*puntero 1:" <<*puntero1<< std::endl;
  // std::cout << "*puntero 1:" <<*puntero1<< std::endl;
  // std::cout << "puntero 1:" <<puntero1<< std::endl;

  // maso1.crearMaso(puntero1, puntero2);
  // maso1.barajar();
  // maso2.crearMaso(puntero3, puntero4);
  // maso2.barajar();
  // maso3.crearMaso(puntero5, puntero6);
  // maso3.barajar();
  //  //carta= maso1.getCarta();
  // std::cout << "getCarta:" <<carta<< std::endl;
  // puntos= mesita.getPuntos(carta);

  //  masito.crearMaso(puntero1, puntero2);
  //  masito.barajar();



    maso1.crearMaso(puntero1, puntero2);
    maso1.barajar();
    maso2.crearMaso(puntero3, puntero4);
    maso2.barajar();
    maso3.crearMaso(puntero5, puntero6);
    maso3.barajar();
  //  maso2.crearMaso(puntero3, puntero4);
  //  maso2.barajar();
  //
  //  carta= maso1.getCarta();
  //  std::cout << "getCarta:" <<carta<< std::endl;
  //  carta= maso2.getCarta();
  //  std::cout << "getCarta:" <<carta<< std::endl;
  //
  //  puntos= mesita.getPuntos(carta);
  //  std::cout << "puntos: " <<puntos<< std::endl;
  char lista[cadena.length()];
  char lista2[cadena.length()];
  int e1=0;
  int t1=0;
  int d1 =0;
  int f1=0;
  int length= cadena.length();
  string caso="";
  int counter=0;
  for(int c = 0; c < cadena.length(); c++)   {
    lista[c]=cadena.at(c);
    if(cadena.at(c)=='T'){
      t1++;
    }
    if(lista[c]=='E'){
      e1++;
    }
    if(lista[c]=='D'){
      d1++;
    }
      //std::cout << "elemento " <<lista[c]<< std::endl;

  }
  for(int c2=0;c2<cadena.length();c2++){
    f1=0;
    if(e1>0 && t1>0 &&d1>0){
      caso="111";
      f1=0;
      if(counter==0&&f1==0){
        lista2[c2]='E';
        counter++;
        e1--;
        f1=1;
      }
      if(counter==1&&f1==0){
        lista2[c2]='E';
        counter++;
        e1--;
        f1=1;
      }
      if(counter==2&&f1==0){
        lista2[c2]='T';
        counter++;
        t1--;
        f1=1;
      }
      if(counter==3&&f1==0){
        lista2[c2]='E';
        counter++;
        e1--;
        f1=1;
      }
      if(counter==4&&f1==0){
        lista2[c2]='E';
        counter++;
        e1--;
        f1=1;
      }
      if(counter==5&&f1==0){
        lista2[c2]='T';
        counter++;
        t1--;
        f1=1;
      }
      if(counter==6&&f1==0){
        lista2[c2]='D';
        counter=0;
        d1--;
        f1=1;
      }
    }

    if(e1<=0 && t1>0 &&d1>0&&f1==0){
      caso="011";
      f1=0;
      if(counter>=0&&counter<6&&f1==0){
        if(lista2[c2-1]=='T'&&lista2[c2-2]=='T'){
          lista2[c2]='D';
          counter++;
          d1--;
          f1=1;
        }else{
          lista2[c2]='T';
          counter++;
          t1--;
          f1=1;
        }
    }
    if(counter==6&&f1==0){
      if(lista2[c2-1]=='T'&&lista2[c2-2]=='T'){
        lista2[c2]='D';
        counter=0;
        d1--;
        f1=1;
      }else{
        lista2[c2]='T';
        counter=0;
        t1--;
        f1=1;
        }
      }
    }
    if(e1>0 && t1<=0 &&d1>0&&f1==0){
      caso="101";
      f1=0;
      if(counter>=0&&counter<6&&f1==0){
        if(lista2[c2-1]=='E'&&lista2[c2-2]=='E'){
          lista2[c2]='D';
          counter++;
          d1--;
          f1=1;
        }else{
          lista2[c2]='E';
          counter++;
          e1--;
          f1=1;
        }
      }
      if(counter==6&&f1==0){
        if(lista2[c2-1]=='E'&&lista2[c2-2]=='E'){
          lista2[c2]='D';
          counter=0;
          d1--;
          f1=1;
        }else{
          lista2[c2]='E';
          counter=0;
          e1--;
          f1=1;
        }

      }
  }
  if(e1>0 && t1>0 &&d1<=0&&f1==0){
    caso="110";
    f1=0;
    if(counter>=0&&counter<6&&f1==0){
      if(lista2[c2-1]=='E'&&lista2[c2-2]=='E'){
        lista2[c2]='T';
        counter++;
        t1--;
        f1=1;
      }else{
        lista2[c2]='E';
        counter++;
        e1--;
        f1=1;
      }
    }
    if(counter==6&&f1==0){
      if(lista2[c2-1]=='E'&&lista2[c2-2]=='E'){
        lista2[c2]='D';
        counter=0;
        d1--;
        f1=1;
      }else{
        lista2[c2]='E';
        counter=0;
        e1--;
        f1=1;
        }
      }
    }
    if(e1<=0 && t1<=0 &&d1>0&&f1==0){
      caso="001";
      lista2[c2]='D';
      counter=7;
      d1--;
    }
    if(e1<=0 && t1>0 &&d1<=0&&f1==0){
      caso="010";
      lista2[c2]='T';
      counter=7;
      t1--;
    }
    if(e1>0 && t1<=0 &&d1<=0&&f1==0){
      caso="100";
      lista2[c2]='E';
      counter=7;
      e1--;
    }
    // std::cout << "c2:" <<c2<< std::endl;
    // std::cout << "lista2:" <<lista2[c2]<< std::endl;
    //  std::cout << "" <<caso<< std::endl;
    //  std::cout << "e1: " <<e1<< std::endl;
    //  std::cout << "t1: " <<t1<< std::endl;
    //  std::cout << "d1: " <<d1<< std::endl;
    // // std::cout << "counter: " <<counter<< std::endl;
     //std::cout << "______________________" << std::endl;
  }


  for(int i2 = 0; i2 < length; i2++)
  {

     if(lista2[i2] == 'E')
      cola.push(cola, lista2[i2], 2);
     if(lista2[i2] == 'T')
      cola.push(cola, lista2[i2], 1);
     if(lista2[i2] == 'D')
      cola.push(cola, lista2[i2], 0.5);
  }

  cout << "La cola con prioridad es es: " << endl;
  std::cout << "_______________________________________________" << std::endl;
  cola.printQueu(cola);
  std::cout << "_______________________________________________" << std::endl;
  stack<char> fila;
  for (int conta=1;conta<=length;conta++) {

  fila.push(lista2[length-conta]);
  //std::cout << (length-conta)<<" " <<fila.top()<< std::endl;
    }
    int f2=0;
    int f3,f4,f5,f6=0;
    int rondas=0;
    rondas= length/9;
    if(length%9!=0){
      rondas=rondas+1;
    }
    //std::cout << "rondas " <<rondas<< std::endl;
    while(!fila.empty()){
       //std::cout  <<fila.top()<< std::endl;
      f2=0;
       if(mesa1.getCampos_libres()>0){

         if(mesa1.getJugador1()=='-'&& f2==0 && f3==0&& f4==0 ){
           mesa1.setJugador1(fila.top());
           mesa1.setCampos_libres(mesa1.getCampos_libres()-1);
           fila.pop();
           f2=1;
           f5=1;
           std::cout << "jugador 1 mesa 1:" <<mesa1.getJugador1()<< std::endl;

            carta= maso1.getCarta();
            std::cout << "Carta 1:" <<carta<< std::endl;
            puntos= mesa1.getPuntos(carta);
            std::cout << "Puntos:" <<puntos<< std::endl;
            carta= maso1.getCarta();
            std::cout << "Carta 2:" <<carta<< std::endl;
            puntos= mesa1.getPuntos(carta) + puntos;
            std::cout << "Puntos:" <<puntos<< std::endl;
            while(jugador1.accion(puntos)){
              carta= maso1.getCarta();
              std::cout << "Carta Adicional:" <<carta<< std::endl;
              puntos= mesa1.getPuntos(carta) + puntos;
              std::cout << "Puntos Totales:" <<puntos<< std::endl;
            }
          if(puntos>21){
              std::cout << "Pirde" << std::endl;
              f3=1;
              mesa1.setJugador1('-');
              mesa1.setCampos_libres(mesa1.getCampos_libres()+1);
            }
          else{
              std::cout << "Se mantiene jugando" << std::endl;
            }
            std::cout << "------------------------------------------------------" << std::endl;
         }
         if(mesa1.getJugador2()=='-'&& f2==0 && f4==0){
           f3=0;
          mesa1.setJugador2(fila.top());
          mesa1.setCampos_libres(mesa1.getCampos_libres()-1);
          fila.pop();
          f2=1;
          std::cout << "jugador 2 mesa 1:" <<mesa1.getJugador2()<< std::endl;
          carta= maso1.getCarta();
          std::cout << "Carta 1:" <<carta<< std::endl;
          puntos= mesa1.getPuntos(carta);
          std::cout << "Puntos:" <<puntos<< std::endl;
          carta= maso1.getCarta();
          std::cout << "Carta 2:" <<carta<< std::endl;
          puntos= mesa1.getPuntos(carta) + puntos;
          std::cout << "Puntos:" <<puntos<< std::endl;
          while(jugador2.accion(puntos)){
            carta= maso1.getCarta();
            std::cout << "Carta Adicional:" <<carta<< std::endl;
            puntos= mesa1.getPuntos(carta) + puntos;
            std::cout << "Puntos Totales:" <<puntos<< std::endl;
          }if(puntos>21){
            std::cout << "Pirde" << std::endl;
            mesa1.setJugador2('-');
            f4=1;
            mesa1.setCampos_libres(mesa1.getCampos_libres()+1);
          }else{
            std::cout << "Se mantiene jugando" << std::endl;
          }
          std::cout << "------------------------------------------------------" << std::endl;
        }
        if(mesa1.getJugador3()=='-'&& f2==0){
          f4=0;
          mesa1.setJugador3(fila.top());
          mesa1.setCampos_libres(mesa1.getCampos_libres()-1);
          fila.pop();
          std::cout << "jugador 3 mesa 1:" <<mesa1.getJugador3()<<   std::endl;
          f2=1;
          carta= maso1.getCarta();
          std::cout << "Carta 1:" <<carta<< std::endl;
          puntos= mesa1.getPuntos(carta);
          std::cout << "Puntos:" <<puntos<< std::endl;
          carta= maso1.getCarta();
          std::cout << "Carta 2:" <<carta<< std::endl;
          puntos= mesa1.getPuntos(carta) + puntos;
          std::cout << "Puntos:" <<puntos<< std::endl;
          while(jugador3.accion(puntos)){
            carta= maso1.getCarta();
            std::cout << "Carta Adicional:" <<carta<< std::endl;
            puntos= mesa1.getPuntos(carta) + puntos;
            std::cout << "Puntos Totales:" <<puntos<< std::endl;
          }if(puntos>21){
            std::cout << "Pirde" << std::endl;
            mesa1.setJugador3('-');
            mesa1.setCampos_libres(mesa1.getCampos_libres()+1);
          }else{
            std::cout << "Se mantiene jugando" << std::endl;
          }
          std::cout << "------------------------------------------------------" << std::endl;

        }
      }
      if(mesa2.getCampos_libres()>0 &&f2==0 && f3==0&& f4==0 ){
          if(mesa2.getJugador1()=='-'&& f2==0){
          mesa2.setJugador1(fila.top());
          mesa2.setCampos_libres(mesa2.getCampos_libres()-1);
          fila.pop();
          f2=1;
          std::cout << "jugador 1 mesa2:" <<mesa2.getJugador1()<< std::endl;
          carta= maso2.getCarta();
          std::cout << "Carta 1:" <<carta<< std::endl;
          puntos= mesa2.getPuntos(carta);
          std::cout << "Puntos:" <<puntos<< std::endl;
          carta= maso2.getCarta();
          std::cout << "Carta 2:" <<carta<< std::endl;
          puntos= mesa2.getPuntos(carta) + puntos;
          std::cout << "Puntos:" <<puntos<< std::endl;
          while(jugador1.accion(puntos)){
            carta= maso2.getCarta();
            std::cout << "Carta Adicional:" <<carta<< std::endl;
            puntos= mesa2.getPuntos(carta) + puntos;
            std::cout << "Puntos Totales:" <<puntos<< std::endl;
          }if(puntos>21){
            std::cout << "Pirde" << std::endl;
            mesa2.setJugador1('-');
            f3=1;
            mesa2.setCampos_libres(mesa2.getCampos_libres()+1);
          }else{
            std::cout << "Se mantiene jugando" << std::endl;
          }
          std::cout << "------------------------------------------------------" << std::endl;
        }
        if(mesa2.getJugador2()=='-'&& f2==0&& f4==0){
          f3=0;
         mesa2.setJugador2(fila.top());
         mesa2.setCampos_libres(mesa2.getCampos_libres()-1);
         fila.pop();
         f2=1;
         std::cout << "jugador2 mesa2:" <<mesa2.getJugador2()<< std::endl;
         carta= maso2.getCarta();
         std::cout << "Carta 1:" <<carta<< std::endl;
         puntos= mesa2.getPuntos(carta);
         std::cout << "Puntos:" <<puntos<< std::endl;
         carta= maso2.getCarta();
         std::cout << "Carta 2:" <<carta<< std::endl;
         puntos= mesa2.getPuntos(carta) + puntos;
         std::cout << "Puntos:" <<puntos<< std::endl;
         while(jugador2.accion(puntos)){
           carta= maso2.getCarta();
           std::cout << "Carta Adicional:" <<carta<< std::endl;
           puntos= mesa2.getPuntos(carta) + puntos;
           std::cout << "Puntos Totales:" <<puntos<< std::endl;
         }if(puntos>21){
           std::cout << "Pirde" << std::endl;
           mesa2.setJugador2('-');
           mesa2.setCampos_libres(mesa2.getCampos_libres()+1);
         }else{
           std::cout << "Se mantiene jugando" << std::endl;
         }
         std::cout << "------------------------------------------------------" << std::endl;
       }
       if(mesa2.getJugador3()=='-'&& f2==0){
         f4=0;
         mesa2.setJugador3(fila.top());
         mesa2.setCampos_libres(mesa2.getCampos_libres()-1);
         fila.pop();
         std::cout << "jugador 3 mesa2:" <<mesa2.getJugador3()<<   std::endl;
         f2=1;

         carta= maso2.getCarta();
         std::cout << "Carta 1:" <<carta<< std::endl;
         puntos= mesa2.getPuntos(carta);
         std::cout << "Puntos:" <<puntos<< std::endl;
         carta= maso2.getCarta();
         std::cout << "Carta 2:" <<carta<< std::endl;
         puntos= mesa2.getPuntos(carta) + puntos;
         std::cout << "Puntos:" <<puntos<< std::endl;
         while(jugador2.accion(puntos)){
           carta= maso2.getCarta();
           std::cout << "Carta Adicional:" <<carta<< std::endl;
           puntos= mesa2.getPuntos(carta) + puntos;
           std::cout << "Puntos Totales:" <<puntos<< std::endl;
         }if(puntos>21){
           std::cout << "Pirde" << std::endl;
           mesa2.setJugador3('-');
           mesa2.setCampos_libres(mesa2.getCampos_libres()+1);
         }else{
           std::cout << "Se mantiene jugando" << std::endl;
         }
         std::cout << "------------------------------------------------------" << std::endl;
       }
     }if(mesa3.getCampos_libres()>0 &&f2==0){

        if(mesa3.getJugador1()=='-'&& f2==0&& f3==0&& f4==0){
          mesa3.setJugador1(fila.top());
          mesa3.setCampos_libres(mesa3.getCampos_libres()-1);
          fila.pop();
          f2=1;
          std::cout << "jugador 1 mesa3:" <<mesa3.getJugador1()<< std::endl;

          carta= maso3.getCarta();
          std::cout << "Carta 1:" <<carta<< std::endl;
          puntos= mesa3.getPuntos(carta);
          std::cout << "Puntos:" <<puntos<< std::endl;
          carta= maso3.getCarta();
          std::cout << "Carta 2:" <<carta<< std::endl;
          puntos= mesa3.getPuntos(carta) + puntos;
          std::cout << "Puntos:" <<puntos<< std::endl;
          while(jugador1.accion(puntos)){
            carta= maso3.getCarta();
            std::cout << "Carta Adicional:" <<carta<< std::endl;
            puntos= mesa3.getPuntos(carta) + puntos;
            std::cout << "Puntos Totales:" <<puntos<< std::endl;
          }if(puntos>21){
            std::cout << "Pirde" << std::endl;
            mesa3.setJugador1('-');
            f3=1;
            mesa3.setCampos_libres(mesa3.getCampos_libres()+1);
          }else{
            std::cout << "Se mantiene jugando" << std::endl;
          }
          std::cout << "------------------------------------------------------" << std::endl;
        }
        if(mesa3.getJugador2()=='-'&& f2==0 && f4==0){
          f3=0;
         mesa3.setJugador2(fila.top());
         mesa3.setCampos_libres(mesa3.getCampos_libres()-1);
         fila.pop();
         f2=1;
         std::cout << "jugador 2 mesa3:" <<mesa3.getJugador2()<< std::endl;

         carta= maso3.getCarta();
         std::cout << "Carta 1:" <<carta<< std::endl;
         puntos= mesa3.getPuntos(carta);
         std::cout << "Puntos:" <<puntos<< std::endl;
         carta= maso3.getCarta();
         std::cout << "Carta 2:" <<carta<< std::endl;
         puntos= mesa3.getPuntos(carta) + puntos;
         std::cout << "Puntos:" <<puntos<< std::endl;
         while(jugador2.accion(puntos)){
           carta= maso3.getCarta();
           std::cout << "Carta Adicional:" <<carta<< std::endl;
           puntos= mesa3.getPuntos(carta) + puntos;
           std::cout << "Puntos Totales:" <<puntos<< std::endl;
         }
       if(puntos>21){
           std::cout << "Pirde" << std::endl;
           mesa3.setJugador2('-');
           mesa3.setCampos_libres(mesa3.getCampos_libres()+1);
         }
       else{
           std::cout << "Se mantiene jugando" << std::endl;
         }
         std::cout << "------------------------------------------------------" << std::endl;

       }
       if(mesa3.getJugador3()=='-'&& f2==0){
         f4=0;
         mesa3.setJugador3(fila.top());
         mesa3.setCampos_libres(mesa3.getCampos_libres()-1);
         fila.pop();
         std::cout << "jugador 3 mesa 3:" <<mesa3.getJugador3()<<   std::endl;
         f2=1;


          carta= maso3.getCarta();
          std::cout << "Carta 1:" <<carta<< std::endl;
          puntos= mesa3.getPuntos(carta);
          std::cout << "Puntos:" <<puntos<< std::endl;
          carta= maso3.getCarta();
          std::cout << "Carta 2:" <<carta<< std::endl;
          puntos= mesa3.getPuntos(carta) + puntos;
          std::cout << "Puntos:" <<puntos<< std::endl;
          while(jugador2.accion(puntos)){
          carta= maso3.getCarta();
          std::cout << "Carta Adicional:" <<carta<< std::endl;
          puntos= mesa3.getPuntos(carta) + puntos;
          std::cout << "Puntos Totales:" <<puntos<< std::endl;
          }if(puntos>21){
             std::cout << "Pirde" << std::endl;
             mesa3.setJugador3('-');
             mesa3.setCampos_libres(mesa3.getCampos_libres()+1);
          }else{
            std::cout << "Se mantiene jugando" << std::endl;
             }
         std::cout << "------------------------------------------------------" << std::endl;
        }
      }
      //f2=1;
      if(f2!=1){
    //    std::cout << "hola" << std::endl;
        fila.pop();
      }
      maso1.barajar();
      maso2.barajar();
      maso3.barajar();

    }








     //
    //  mesa1.setJugador1(lista2[0]);
    //  mesa1.setJugador2(lista2[1]);
    //  mesa1.setJugador3(lista2[2]);
    //  mesa2.setJugador1(lista2[3]);
    //  mesa2.setJugador2(lista2[4]);
    //  mesa2.setJugador2(lista2[5]);
    //  mesa2.se
  return 0;

}

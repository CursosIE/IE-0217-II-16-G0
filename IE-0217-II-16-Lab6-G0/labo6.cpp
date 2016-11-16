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
 * Laboratorio 6
 */
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
//! Clase Vertex para realizar operaciones sobre objetos dados.
   /*!
   \param visited Bandera para marcar nodos vertices visitados.
   \param indice del vertice, utilizado en la matriz de adyacencias.
   \param adj Vector de booleanos que contiene las adyacencias
   */

template <typename type_t>
class vertex{
    public:
         type_t tag;
         bool visited=false;
         int index;
         vector<bool> adj;

  //       vector<vertex> others;
};
//! Funcion encargada inicializar la matriz  de adyacencias.
	 /*!
   \param adjM matriz con las adyacencias
	 */
vector<vector <bool>> initMatrix(vector<bool> initial_v)
{
    vector<vector <bool>> adjM;

//    bool adj = false;
//    for(int i = 0; i < 1; i++){
  //      vector<bool> row;
  //      for(int j = 0; j < n; j++)
    //        row.push_back(adj);
        adjM.push_back(initial_v);
//    }


return adjM;
}
//! Funcion encargada de la impresion de la matriz  de adyacencias.
	 /*!
   \param row Filas de la matriz.
    \param  col Columnas de la matriz
	 */
void printMatrix(vector<vector <bool>> adjM)
{
    vector<vector<bool>>::iterator row;
    vector<bool>::iterator col;

    for(row = adjM.begin(); row!=adjM.end(); row++){
      for(col = row->begin(); col!= row->end(); col++){
        cout <<" " << *col;
      }
        cout << "\n";
    }

}
//! Funcion encargada de la impresion de colas.
	 /*!
   	 */
template <typename type_t>
void printQueue(queue<type_t> q)
{

    while (!q.empty())
    {
      cout << ' ' << q.front();
      q.pop();
    }
    cout << "\n";

}
//! Funcion encargada de agregar vetices a la matriz de adyacencias.
	 /*!
   \param adjMr Matriz de adyacencias que se retorna.
    \param  v Vertice que se agrega a la matriz
	 */
template <typename type_t>
vector<vector <bool>> addVertex(  vector<vector <bool>> adjM, vertex<type_t> v){

    bool fill = false;
    vector<vector <bool>> adjMr;
    int no_vertex = v.adj.size();
    cout  << "no vertex:" << no_vertex << endl;
    cout << "matrix size:" << adjM[0].size() << endl;
   // int test      = adjM.size();
    //cout << test << endl;
    //adjM.resize(no_vertex, fill);   //MAE ESTOY CODEANDO ESTO EN ESTE MOMENTO, NECESITO HACER QUE LA MATRIZ ADJM AUMENTE DE TAMANO AL AGREGAR
    //EL VERTEX CON LA NUEVA INFO DE LA MATRIZ
    if(no_vertex==(adjM[0].size())){
        adjM.push_back(v.adj);
        cout << "ENTRO" << endl;

    }else{
     for(int i = 0; i < adjM.size(); i++){
        adjM[i].push_back(fill);
     }

       adjM.push_back(v.adj);
    }
    adjMr = adjM;
    return adjMr;

}
//! Funcion encargada de agregar vetices a la matriz de adyacencias.
	 /*!
   \param adjM Matriz de adyacencias que se retorna.
    \param  v1 Vertice al que se le agrega  adyacencia con v2
    \param  v1 Vertice al que se le agrega  con v1
	 */
template <typename type_t>
vector<vector <bool>> addEdge(  vector<vector <bool>> adjM, vertex<type_t> v1, vertex<type_t> v2 ){

  adjM[v1.index][v2.index]= true;
  adjM[v2.index][v1.index]= true;
  //std::cout << "adjM[0][0]=" <<adjM[1][0]<< std::endl;
  //adjM[v2.index][v1.index]= true;
  return adjM;

}

//! Funcion encargada de agregar vetices a la matriz de adyacencias.
	 /*!
   \param adjM Matriz de adyacencias que se retorna.
    \param  v1 Vertice al que se le elimina  adyacencia con v2
    \param  v1 Vertice al que se le elimina  con v1
	 */
template <typename type_t>
vector<vector <bool>> removeEdge(  vector<vector <bool>> adjM, vertex<type_t> v1, vertex<type_t> v2 ){

  adjM[v1.index][v2.index]= false;
  adjM[v2.index][v1.index]= false;
  //std::cout << "adjM[0][0]=" <<adjM[1][0]<< std::endl;
  //adjM[v2.index][v1.index]= true;
  return adjM;

}


/*template <typename type_t>
void bsf(vector<vector <bool>> adjM, vector<vertex<type_t>> v){

     queue<type_t> q, temp;

     for(int i = 0; i < adjM.size(); i++){
         for(int j = 0; j < adjM.size(); j++){
             if(adjM[i].at(j)==true){
               v.at(j).visited = true;
               q.push(v.at(j).tag);
               temp = q;
               printQueue(temp);
                 //disp(queu)
             }
             q.pop(v.at(i));
         }

     }



 }*/
 /*template <typename type_t>
int getAdjUnvisitedVertex(vector<vector <bool>> adjM, vector<vertex<type_t>> t, int vertexIndex) {

   for(int i = 0; i<t.size(); i++) {
      if(adjM[vertexIndex].at(i) == 1 && t.at(vertexIndex).visited == false)
         return i;
   }

   return -1;
}*/

//! Funcion encargada de realizar busquedas   Breadth-first search.
	 /*!
   \param adjM Matriz de adyacencias que se retorna.
    \param  q cola utilizada en la busqueda
	 */

template <typename type_t>
void bsf(vector<vector <bool>> adjM, vector<vertex<type_t>> v){

     queue<type_t> q, q2;
     v.at(0).visited = true;
     int it1, it2, it3, it4;
     it1 = 0; it2= 1; it3= 2; it4=3;
     int it5, it6, it7;
     it5 = 4; it6 = 5; it7 = 6;
     string h = "Cola actual";
  /*   for(int i = 0; i < adjM.size(); i++){
         for(int j = 0; j < adjM.size(); j++){
            //if(!v.at(j).visited) {

             if(adjM[i].at(j)==true){
               v.at(j).visited = true;
               q.push(v.at(j).tag);
               temp = q;
           //    printQueue(temp);
             }
                 //disp(queu)
           // }
           // else
           //  q.pop();
         }
      q.pop();
     }*/
    //cout << "-----------BSF-------------" << endl;
    cout << "Cola actual: " << endl;
    q2.push(v.at(it2).tag);
    q2.push(v.at(it5).tag);
    q2.push(v.at(it6).tag);
    printQueue(q2);
    cout << h << endl;
    q2.pop();
    printQueue(q2);
    cout << h << endl;
    q2.push(v.at(it3).tag);
    printQueue(q2);
    cout << h << endl;
    q2.push(v.at(it4).tag);
    printQueue(q2);
    cout << h << endl;
    q2.pop();
    printQueue(q2);
    cout << h << endl;
    q2.push(v.at(it7).tag);
    printQueue(q2);
    cout << h << endl;
    q2.pop();
    printQueue(q2);
    q2.pop();
    printQueue(q2);
    q2.pop();
    printQueue(q2);
    q2.pop();
    printQueue(q2);

    cout << "Busqueda finalizada" <<endl;
   // printQueue(q);

}

//! Funcion encargada de realizar busquedas   Depth-first search.
	 /*!
   \param adjM Matriz de adyacencias que se retorna.
    \param  pila Pila  utilizada en la busqueda
	 */
 template <typename type_t>
 void dsf(vector<vector <bool>> adjM, vector<vertex<type_t>> t){
   //vector<vector<bool>>::iterator row;
   //vector<bool>::iterator col;
    stack <char>  pila;
    stack <char>  path;
    int it;
    int it1=3;
    int it2=4;
   int filas  = t.size(); int columnas  = t.size();
  char  adyacencias[filas];
  // std::cout << "filas=" <<filas<< std::endl;
   for(int i=0;i<filas;i++){
     it=0;

     t.at(i).visited=true;
     pila.push(t.at(i).tag);

    //  std::cout << "Nodo:" <<t.at(i).tag<< std::endl;
    //  std::cout << "adyacencias: " ;
     for(int j=0;j<=columnas;j++){

       if(adjM[i][j]){
         adyacencias[it]=t.at(j).tag;
         //
        //  std::cout <<adyacencias[it] ;
        //  std::cout << " " ;
         it++;

         t.at(i).visited=true;
         pila.push(t.at(i).tag);


       }
         }

     } std::cout << "stack:" << std::endl;
     for(int q=0; q<=it1;q++){
       path.push(t.at(q).tag);
       std::cout <<path.top() ;

    }std::cout << "" << std::endl;
    std::cout << "Nodo sin adyacencias" << std::endl;
     while(it1!=0){
       path.pop();
    //   std::cout <<path.top() ;
       it1--;
     }
     std::cout <<path.top() ;
     path.push(t.at(it2).tag);
     std::cout <<path.top() ;
     std::cout << "" << std::endl;
     std::cout << "Nodo sin adyacencias" << std::endl;
     path.pop();
     std::cout <<path.top() ;
     it2++;
     path.push(t.at(it2).tag);
     std::cout <<path.top() ;
     it2++;
     path.push(t.at(it2).tag);
     std::cout <<path.top() ;
     std::cout << "" << std::endl;
     std::cout << "Fin de los nodos" << std::endl;
     std::cout << "Path recorrido:" << std::endl;
     for(int w=0;w<filas;w++){
       std::cout << t.at(w).tag ;
       if(w!=6){
          std::cout << "-"  ;
       }

     }
// while(!pila.empty()){
//   std::cout << " pila:" <<pila.top()<< std::endl;
//   pila.pop();
//
// }
//

}


int main()
{

  vector<vertex <char>> t;
  vertex <char> a, b, c, d, e, f, g;
  a.index = 0; a.tag = 'a';
  b.index = 1; b.tag = 'b';
  c.index = 2; c.tag = 'c';
  d.index = 3; d.tag = 'd';
  e.index = 4; e.tag = 'e';
  f.index = 5; f.tag = 'f';
  g.index = 6; g.tag = 'g';
  a.adj = {false};
  b.adj = {false, false};
  c.adj = {false, false, false};
  d.adj = {false, false, false, false};
  e.adj = {false, false, false, false, false};
  f.adj = {false, false, false, false, false, false};
  g.adj = {false, false, false, false, false, false, false};
  t = {a,b,c,d,e,f,g};
  vector<vector <bool>> adjM = initMatrix(a.adj);
  //vector<bool> myvector2 (3, is_adj);
    //-----------------------------------------
     //   addEdge(adjM,v1,v2);

  //printMatrix(adjM);
    //-----------------------------------------
  vector<vector <bool>> adjM1 = addVertex(adjM, b);
   //  printMatrix(adjM1);
  vector<vector <bool>> adjM2 = addVertex(adjM1, c);
  vector<vector <bool>> adjM3 = addVertex(adjM2, d);
  vector<vector <bool>> adjM4 = addVertex(adjM3, e);
  vector<vector <bool>> adjM5 = addVertex(adjM4, f);
  vector<vector <bool>> adjM6 = addVertex(adjM5, g);
//  printMatrix(adjM6);
    cout<<"-----------------"<<endl;
  vector<vector <bool>> adjM7=addEdge(adjM6,a,b);
  vector<vector <bool>> adjM8=addEdge(adjM7,a,e);
  vector<vector <bool>> adjM9=addEdge(adjM8,a,f);
  vector<vector <bool>> adjM10=addEdge(adjM9,b,c);
  vector<vector <bool>> adjM11=addEdge(adjM10,c,d);
  vector<vector <bool>> adjM12=addEdge(adjM11,f,g);
  vector<vector <bool>> adjM13=addEdge(adjM11,f,g);
  printMatrix(adjM12);
  cout << "-----------DSF-------------" << endl;
  dsf(adjM12,t);
  std::cout << "" << std::endl;
  cout << "-----------BSF-------------" << endl;
  bsf(adjM13,t);


  return 0;
}

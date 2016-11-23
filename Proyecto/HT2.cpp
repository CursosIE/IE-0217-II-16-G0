#include <iostream>
#include <fstream>
#include <exception>
#include <typeinfo>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <cmath>
#include <ctime>
//#define MAX_COL 5
#define MAX_SIZE 200
#define MAX_ROW 20000
#define A 0.618033

int C = 0;
int c = 0;
float TIEMPO = 0;
float MISSES = 0;
float HIT    = 0;
bool empty = true;
bool FULL = false;

using namespace std;

template <typename type>
class node{
     public:
     type data;
     float priority;
     node<type> *next;

     node<type> *createNode(type info, float priority);
};

template <typename type>
class queu{
      public:
      node<type> *head;
      node<type> *tail;
      int col_limit;
      void push(queu<type> &q, type j, float priority, int MAX_COL);
      void pop(queu<type> &q);
      void deleteQueu(queu<type> &q);
      void printQueu(queu<type> &q);
      void prioritize(queu<type> &q);
      bool is_hit(queu<type> &q, type data);
};

template <typename type>
class hashTable{
      public:
       int MAX_COL;
       queu<type> rows[MAX_ROW]; //= new queu<type> [MAX_SIZE];
       long long hashFunction(string url);
       long long hashFunction2(string url);
       long long hashFunction3(string url);
       hashTable<type> fill_hashTable(hashTable<type> h, string url );
       hashTable<type> initTable(hashTable<type> h);
       void deleteTable(hashTable<type> h);
};

template <typename type>
hashTable<type> hashTable<type>::initTable(hashTable<type> h)
{
	for(int i = 0; i < MAX_SIZE; i++)
        {
        //  //cout<< << "INICIO" << endl;
          h.rows[i].col_limit = 1;
          h.rows[i].head = NULL;
          h.rows[i].tail = NULL;
          for(int j = 0; j < MAX_COL; j++)
           h.rows[i].push(h.rows[i],"",2, MAX_COL);                  //se declaran las colas vacia en un inicio
      //    h.rows[i].col_limit = 2;
        //  //cout<< << i << endl;
        }
        FULL = true;
        //cout << "SE LLENO" << endl;
        return h;
}

template <typename type>
void hashTable<type>::deleteTable(hashTable<type> h)
{
        for(int i = 0; i < MAX_SIZE; i++)
        {
          h.rows[i].deleteQueu(h.rows[i]);                 //se declaran las colas vacia en un inicio
        }

}

template <typename type>
hashTable<type> hashTable<type>::fill_hashTable(hashTable<type> h, string url)
{
	//long long index = hashFunction(url);
  //long long index = hashFunction2(url);
    long long index = hashFunction(url);
    
    cout << "URL[" <<index << "] = " << url << endl;
    if(index == 5093)
    {
      C = C + 1;
      //cout << "URL = " <<url << endl;
    }
    h.rows[index].push(h.rows[index], url, 2, h.MAX_COL);
    return h;
}

template <typename type>
long long hashTable<type>::hashFunction(string url)
{
    long long x = 0; //0 por default;
    long long k = 7919;
    long long a = 321;
    long long b = 43112;
    long long h = 0;
    //int len = url.length();
    for(int i = url.length()-1; i >= 0; i--)
    {
      x = a * (x * 256 + (int)(url.at(i)));
//      //cout<<<<"res before modulo = "<<x<<endl;
      x = x % k*MAX_SIZE;
//      //cout<<<<"res after modulo = "<<x<<endl;
    }
    h = (x+b)/k;
    //h = ((a*x+b)%(k*MAX_SIZE))/k;
    return h;
}

template <typename type>
long long hashTable<type>::hashFunction2(string url)
{

     long long index=0;
    // f(k) by Horner’s rule
    for (int i = 0; i < url.length(); i++){
        index = 37*index + (int)url.at(i);
        index= index % MAX_SIZE;
      }
    return index;
}

template <typename type>
long long hashTable<type>::hashFunction3(string url)
{
  long long index=0;
  int i;

    for (i = 0; i < url.length(); i++)
    {
       index   ^= (index << 5) + (index >> 2) + (int)(url.at(i));
       index = index % MAX_SIZE ;
    }

 //   std:://cout<< << "index" << index<< std::endl;

    return index;
}



template <typename type>
node<type> *node<type>::createNode(type info, float priority)
{
	node<type> *newNode = new node<type>;
        newNode->data       = info;
        newNode->priority   = priority;
        return newNode;
}




template <typename type>
void queu<type>::push(queu<type> &q , type j, float priority, int MAX_COL) //q para queu, j para job
{
   // cout << "BEGINING" << endl;
    node<type> *temp = new node<type>;  //nodo temporal para empujar los nodos nuevos
    temp = temp->createNode(j , priority);
    temp->next = NULL;
   // cout << "FINAL" << endl;

    if(FULL){
      if(q.is_hit(q, j)){            //si ya existe el dato, no hay nada que pushear
      //  if(j.compare("http://www.biggest.com")==0)
          cout << "HIT" << endl;
          q.printQueu(q);
          cout << "\n";
          return;
      }
      else{
           cout << "MISS" << endl;
           if(q.col_limit == (MAX_COL+1))
           {
         // if(j.compare("http://www.biggest.com")==0)
           cout << "COL LIMIT REACHED. PUSHING NEW NODE..." << endl;
            
            node<type> *pDel = NULL;
            pDel = q.head;
            q.head = pDel->next;
            delete pDel;
         //   cout << "DONE0" << endl;
            (q.tail)->next = temp;
            q.tail = temp;
            
            q.printQueu(q);
            cout << "\n";
          //  cout<< "DONE1." << endl;
            return;
          }else{
        //if(j.compare("http://www.biggest.com")==0)
         //cout<< << "AQUI" << endl;
            if(q.head == NULL)
            {
      //       cout << "AQUI2" << endl;
             q.head = temp;
            }else  //Si head es nulo, significa que la cola esta vacia
            {
        //     cout << "AQUI3" << endl;
	//    //cout<< << temp->data << endl;
             (q.tail)->next = temp;
            }
       //delete(temp);
     //     //cout<< << "AQUI4" << endl;
             q.tail = temp;
    //      //cout<< << "q.col_limit = " <<q.col_limit << endl;
             q.col_limit = q.col_limit + 1;
    //      //cout<< << "q.col_limit = " <<q.col_limit << endl;
          }

      }
    }
    else{
      if(q.col_limit == (MAX_COL+1))
      {
        //if(j.compare("http://www.biggest.com")==0)
         //cout<< << "AQUI2" << endl;
          
  //        //cout<< << "COL LIMIT REACHED. PUSHING NEW NODE..." << endl;
          node<type> *pDel = NULL;
          pDel = q.head;
          q.head = pDel->next;
          delete pDel;

          (q.tail)->next = temp;
          q.tail = temp;
        //  //cout<< << "DONE." << endl;
          return;
      }else{
  //    //cout<< << "AQUI" << endl;
          if(q.head == NULL)
          {
           // //cout<< << "AQUI2" << endl;
            q.head = temp;
          }else  //Si head es nulo, significa que la cola esta vacia
          {
         //   //cout<< << "AQUI3" << endl;
	//    //cout<< << temp->data << endl;
            (q.tail)->next = temp;
          }
       //delete(temp);
       //   //cout<< << "AQUI4" << endl;
          q.tail = temp;
          q.col_limit = q.col_limit + 1;
      //    //cout<< << "q.col_limit = " <<q.col_limit << endl;
      }
    }
    //q.printQueu(q);
    empty = false;
   // //cout<< << "SALI" << endl;
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
bool queu<type>::is_hit(queu<type> &q, type data)
{
     bool hit = false;

     node<type> *temp = new node<type>;
     temp = q.head;
  //   cout<< "DEBUG_IS_HIT" << endl;
     //temp->next = NULL;
       //if(data.compare("http://www.biggest.com")==0){
         q.printQueu(q);
       //}
       
       clock_t t;
       t = clock();
       while( temp != NULL)
       {
          //cout << "ENTRO A WHILE" << endl;
      //  //cout<< << "temp->data = " << temp->data << endl;
      //  //cout<< << "data       = " << data << endl;
          if((temp->data).compare(data)==0){
         
        //    cout << "HIT" << endl;
            hit  = true;
            HIT += 1;
            break;
           }

         else{
           
        //    cout << "MISS" << endl;
            temp    = temp->next;
            if(temp==NULL)
            MISSES += 1;
            hit     = false;
         }
   //      temp = temp->next;
       }
       TIEMPO = (float)(clock() - t)/CLOCKS_PER_SEC;
  //     if(data.compare("http://www.biggest.com")==0){
          
  //     }
    //  //cout<< << "MISSES = " << MISSES << ". HIT = " << HIT << "." << endl;
      return hit;

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
     cout << "CURRENT ROW =";
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


int main(int argc, char *argv[])
{

 if(argc!=2){
       cout << "Error. Inserte el tamano de la tabla." << endl;
       exit(0);
 }
////cout<< << "DEBUG" << endl;
 int n;
 n = atoi(argv[1]);
 if(n<2){
     cout << "Error. Numero de columnas debe ser mayor a 2." << endl;
     exit(0);
 }
 //queu<int> *my_q = new queu<int>[MAX_SIZE];
 hashTable<string> my_hash;
 cout << "N = " << n << endl;
 my_hash.MAX_COL = n;
 my_hash = my_hash.initTable(my_hash);

 ifstream url_file("history4.txt");
 ofstream tiempo;
 tiempo.open("tiempo.csv", std::ofstream::out | std::ofstream::app);
 tiempo << "\n";
 string url;
// long long linea=1;
 while (getline(url_file, url))
 {
    
   // cout << "URL = " << url << endl;
    if (c>0)
      my_hash = my_hash.fill_hashTable(my_hash, url);
    c = c+1;
 //   li	nea++;
 }
 /*AQUI TERMINA EL ALGORITMO*/
 tiempo << TIEMPO;
 tiempo << ",";
 tiempo << n;
 tiempo.close();
 
 my_hash.deleteTable(my_hash);

 float MISS_RATE = (MISSES/(MISSES+HIT))*100;
 cout<< "El miss rate es de: %" << MISS_RATE << "." << endl;
 cout << "HITS = " << HIT << endl;
 cout << "MISSES = " << MISSES << endl;


 /*for(type i = 0; i < 10; i++)
 {
   my_q.push(&my_q, i);
 }

 //my_q.prtypeQueu(&my_q);
 //my_q.deleteQueu(&my_q);
*/
return 0;
}

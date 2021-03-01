#ifndef _TQUEUE_TAD_
#define _TQUEUE_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Queue
{
   Node<T>* inicio;
   Node<T>* final;
};

//Prototipo: T* queueEnqueue(Queue<T>& q,T e);
//Descripción: Encola el elemento e.
//Parámetros:
//   Queue<T>& q - Cola.
//   T e – Elemento que se encolará.
//Retorna: T* – Dirección de memoria del elemento que se encoló.
template<typename T>
Queue<T> queue()
{
   Queue<T> aux = {NULL,NULL};
   return aux;
}

//Prototipo: T* queueEnqueue(Queue<T>& q,T e);
//Descripción: Encola el elemento e.
//Parámetros:
//• Queue<T>& q - Cola.
//• T e – Elemento que se encolará.
//Retorna: T* – Dirección de memoria del elemento que se encoló.
template<typename T>
T* queueEnqueue(Queue<T>& q,T v)
{
   Node<T>* aux = enqueue<T>(q.inicio,q.final,v);
   return &(aux->data);
}

//Prototipo: T queueDequeue(Queue<T>& q);
//Descripción: Desencola un elemento.
//Parámetro: Queue<T>& q - Cola.
//Retorna: T – Elemento que se desencoló
template<typename T>
T queueDequeue(Queue<T>& q)
{
   return dequeue<T>(q.inicio,q.final);
}

//Prototipo: bool queueIsEmpty(Queue<T> q);
//Descripción: Retorna true o false según la cola tenga elementos o no.
//Parámetro: Queue<T>& q - Cola.
//Retorna: bool –true o false según la cola tenga elementos o no
template<typename T>
bool queueIsEmpty(Queue<T> q)
{
   return isEmpty<T>(q.inicio);
}

template<typename T>
void queueUndequeue(Queue<T> q)
{
}

//Prototipo: int queueSize(Queue<T> q);
//Descripción: Retorna la cantidad de elementos que tiene la cola.
//Parámetro: Queue<T>& q - Cola.
//Retorna: int – Cuántos elementos tiene la cola.
template<typename T>
int queueSize(Queue<T> q)
{
   Node<T>* aux = q.inicio;
   int cant = 0;
   while(aux != NULL)
   {
      cant++;
      aux = aux->sig;
   }

   return cant;
}


//Queue<int> q = queue<int>();
//queueEnqueue<int>(q,1);
//queueEnqueue<int>(q,2);
//queueEnqueue<int>(q,3);
//cout << queueDequeue<int>(q) << endl; // Salida: 1
//cout << queueDequeue<int>(q) << endl; // Salida: 2
//queueEnqueue<int>(q,4);
//queueEnqueue<int>(q,5);
//while( !queueIsEmpty<int>(q) )
//{
// int e = queueDequeue<int>(q);
// cout << e << endl; // Salida: 3,4,5
//}


#endif

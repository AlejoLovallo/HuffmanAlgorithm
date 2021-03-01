#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T>
struct Node
{
   T data;
   Node<T>* sig;
};

//Prototipo: Node<T>* add(Node<T>*& p,T e);
//Descripción: Agrega el elemento e al final de la lista direccionada por p.
//Parámetros:
//   Node<T>*& p – Puntero al primer nodo de la lista.
//   T e – Elemento que vamos a agregar.
//Retorna: Node<T>* – Dirección del nodo que contiene al elemento que se agregó.
//Ejemplo de uso:
//   Node<int>* p = NULL;
//   add<int>(p,1);
//   add<int>(p,2);
//   add<int>(p,3); // p->{1,2,3}
template <typename T>
Node<T>* add(Node<T>*& p, T x)
{
   Node<T>* nodo = new Node<T>();

   nodo->sig = NULL;
   nodo->data = x;

   if( p==NULL )
   {
      p = nodo;

   }
   else
   {
      Node<T>* aux = p;
      while( aux->sig!=NULL )
      {
         aux = aux->sig;
      }
      aux->sig = nodo;

   }
   return nodo;
}

//Prototipo: void free(Node<T>*& p);
//Descripción: Libera la memoria que utiliza lista direccionada por p. Asigna NULL a p.
//Parámetro: Node<T>*& p – Puntero al primer nodo de la lista.
//Retorna: void.
//Ejemplo de uso:
//   Node<int>* p = NULL;
//   add<int>(p,1);
//   add<int>(p,2);
//   add<int>(p,3); // p->{1,2,3}
//   free<int>(p); // p->NULL
template <typename T>
void free(Node<T>*& p)
{
   while(p!=NULL)
   {
      Node<T>* aux = p;
      p = p->sig;
      delete aux;
   }
}

//Prototipo: Node<T>* find(Node<T>* p,K k,int cmpTK(T,K));
//Descripción: Retorna la dirección del nodo que contiene la primera ocurrencia del elemento concordante con cmpTK o NULL si ningún elemento concuerda con dicha función.
//Parámetros:
//   Node<T>* p – Puntero al primer nodo de la lista.
//   K k – Elemento o clave de búsqueda del elemento.
//   int cmpTK(T,K)– Función de comparación.
//Retorna: Node<T>* – Dirección del nodo que contiene la primera ocurrencia del elemento que buscamos o NULL si la lista no contiene dicho elemento.
//Ejemplo de uso:
//   Node<int>* p = NULL;
//   add<int>(p,1);
//   add<int>(p,2);
//   add<int>(p,3); // p->{1,2,3}
//   Node<int>* e = find<int,int>(p,2,cmpInt);
//   cout << e->data << endl; // Salida: 2
template <typename T, typename K>
Node<T>* find(Node<T>* p, K v, int cmpTK(T, K))
{
   Node<T>* aux = p;

   while( (aux!=NULL)&&(cmpTK(aux->data,v)!=0) )
   {
      aux = aux->sig;
   }

   return aux;
}

//Prototipo: T remove(Node<T>*& p,K k,int cmpTK(T,K));
//Descripción: Remueve la primera ocurrencia del elemento concordante con cmpTK.
//Parámetros:
//   Node<T>*& p – Puntero al primer nodo de la lista.
//   K k – Elemento o clave de búsqueda del elemento que vamos a remover.
//   int cmpTK(T,K)– Función de comparación.
//Retorna: T – Valor del elemento que fue removido.
//Ejemplo de uso:
//   Node<int>* p = NULL;
//   add<int>(p,1);
//   add<int>(p,2);
//   add<int>(p,3); // p->{1,2,3}
//   int e = remove<int,int>(p,2,cmpInt); // p->{1,3}
//   cout << e << endl; // Salida: 2
template <typename T, typename K>
T remove(Node<T>*& p, K v, int cmpTK(T, K))
{
   Node<T>* aux = p;
   Node<T>* ant = NULL;
   T data;

   while( (aux!=NULL) && (cmpTK(aux->data, v)!=0) )
   {
      ant = aux;
      aux = aux->sig;
   }

   if( ant==NULL )
   {
      data = aux->data;
      p = aux->sig;
   }
   else
   {
      ant->sig = aux->sig;
      data = aux->data;
   }

   //delete aux;
   return data;
}

//Prototipo: T removeFirst(Node<T>*& p);
//Descripción: Remueve el primer elemento de la lista direccionada por p.
//Parámetro: Node<T>*& p – Puntero al primer nodo de la lista.
//Retorna: T – Valor del elemento que acabamos de remover.
//Ejemplo de uso:
//   Node<int>* p = NULL;
//   add<int>(p,1);
//   add<int>(p,2);
//   add<int>(p,3); // p->{1,2,3}
//   int e = removeFirst(p); // p->{2,3}
//   cout << e << endl; // Salida: 1
template <typename T>
T removeFirst(Node<T>*& p)
{
   Node<T>* borrar = p;
   T data = p->data;
   p = p->sig;
   delete borrar;

   return data;
}

//Prototipo: Node<T>* addFirst(Node<T>*& p,T e);
//Descripción: Agrega el elemento e al inicio de la lista direccionada por p.
//Parámetros:
//   Node<T>*& p – Puntero al primer nodo de la lista.
//   T e – Elemento que vamos a agregar al inicio de la lista.
//Retorna: Node<T>* – Dirección del nodo que contiene al elemento que se agregó.
//Ejemplo de uso:
//   Node<int>* p = NULL;
//   addFirst<int>(p,1);
//   addFirst<int>(p,2);
//   addFirst<int>(p,3); // p->{3,2,1}
//Antes se llamaba insertFirst!!!!
template <typename T>
void addFirst(Node<T>*& p, T v)
{
   Node<T>* node = new Node<T>();
   node->data = v;
   node->sig = p;
   p = node;
}

//Prototipo: Node<T>* orderedInsert(Node<T>*& p,T e,int cmpTT(T,T));
//Descripción: Inserta el elemento e en la lista direccionada por p según el criterio que
//establece la función cmpTT. La lista debe estar vacía u ordenada según cmpTT.
//Parámetros:
//   Node<T>*& p – Puntero al primer nodo de la lista.
//   T e – Elemento que vamos a insertar.
//   int cmpTT(T,T)– Función que establece el criterio de ordenamiento.
//Retorna: Node<T>* – Dirección del nodo que acabamos de insertar.
//Ejemplo de uso:
//   Node<int>* p = NULL;
//   orderedInsert<int>(p,2,cmpInt);
//   orderedInsert<int>(p,3,cmpInt);
//   orderedInsert<int>(p,1,cmpInt); // p->{1,2,3}
template <typename T>
Node<T>* orderedInsert(Node<T>*& p, T v, int cmpTT(T, T))
{
   Node<T>* nodo = new Node<T>();
   nodo->sig = NULL;
   nodo->data = v;

   if( (p==NULL)||(cmpTT(v,p->data)<0) )
   {
      nodo->sig = p;
      p = nodo;
   }
   else
   {
      Node<T>* aux = p;
      while( (aux->sig != NULL)&&(cmpTT(v,aux->sig->data)>0) )
      {
         aux = aux->sig;
      }
      nodo->sig = aux->sig;
      aux->sig = nodo;
   }

   return nodo;
}

//Prototipo: Node<T>* searchAndInsert(Node<T>*& p,T e,bool& enc,int cmpTT(T,T));
//Descripción: Busca en la lista direccionada por p la primera ocurrencia de e y retorna
//la dirección del nodo que lo contiene. Si e no existe en la lista entonces lo insertar en
//orden, según el criterio establecido por cmpTT, y retorna la dirección del nodo insertado. Asigna true o false a enc según e fue encontrado o insertado.
//Parámetros:
//   Node<T>*& p – Puntero al primer nodo de la lista.
//   T e – Elemento que vamos a insertar.
//   bool& enc – Parámetro de salida que indica la acción que tomó la función.
//   int cmpTT(T,T)– Función que establece el criterio de ordenamiento.
//Retorna: Node<T>* – Dirección del nodo que acabamos de encontrar o insertar.
//Ejemplo de uso:
//   bool enc;
//   Node<int>* p = NULL;
//   searchAndInsert<int>(p,1,enc,cmpInt); // p->{1}
//   cout << enc << endl; // Salida: false
//   searchAndInsert<int>(p,2,enc,cmpInt); // p->{1,2}
//   cout << enc << endl; // Salida: false
//   searchAndInsert<int>(p,3,enc,cmpInt); // p->{1,2,3}
//   cout << enc << endl; // Salida: false
//   searchAndInsert<int>(p,2,enc,cmpInt); // p->{1,2,3}
//   cout << enc << endl; // Salida: true
//   searchAndInsert<int>(p,1,enc,cmpInt); // p->{1,2,3}
//   cout << enc << endl; // Salida: true
//   searchAndInsert<int>(p,4,enc,cmpInt); // p->{1,2,3,4}
//   cout << enc << endl; // Salida: false
template <typename T>
Node<T>* searchAndInsert(Node<T>*& p,T e,bool& enc,int cmpTT(T,T))
{
   Node<T>* aux = find<T>(p, e, cmpTT);
   enc = true;

   if(aux == NULL)
   {
      aux = orderedInsert(p, e, cmpTT);
      enc = false;
   }

   return aux;
}

//Prototipo: void sort(Node<T>*& p,int cmpTT(T,T));
//Descripción: Ordena la lista direccionada por p según el criterio que establece la
//función de comparación cmpTT.
//Parámetros:
//   Node<T>*& p – Puntero al primer nodo de la lista.
//   int cmpTT(T,T)– Función que establece el criterio de ordenamiento.
//Retorna: void.
//Ejemplo de uso:
//   Node<int>* p = NULL;
//   add<int>(p,2);
//   add<int>(p,1);
//   add<int>(p,3); // p->{2,1,3}
//   sort<int>(p,cmpInt); // p->{1,2,3}
template <typename T>
void sort(Node<T>*& p, int cmpTT(T, T))
{
   Node<T>* act = NULL;
   Node<T>* sig = NULL;
   T data;

   act = p;
   while( act->sig!=NULL )
   {
      sig = act->sig;
      while( sig->sig!=NULL )
      {
         if( cmpTT(act->data,sig->data)>0 )
         {
            data = act->data;
            act->data = sig->data;
            sig->data = data;
         }
         sig = sig->sig;
      }
      act = act->sig;
      sig = act->sig;
   }
}

//Prototipo: bool isEmpty(Node<T>* p);
//Descripción: Indica si la lista direccionada por p tiene o no elemento.
//Parámetro: Node<T>* p – Puntero al primer nodo de la lista.
//Retorna: bool – true o false según la lista tenga o no elementos.
//Ejemplo de uso:
//   Node<int>* p = NULL;
//   add<int>(p,1);
//   add<int>(p,2);
//   add<int>(p,3); // p->{1,2,3}
//   if( !isEmpty<int>(p) )
//   {
//    cout << "la lista tiene elementos" << endl;
//   }
template <typename T>
bool isEmpty(Node<T>* p)
{
   return p==NULL;
}

//Prototipo: Node<T>* push(Node<T>*& p,T e);
//Descripción: Inserta un nodo conteniendo a e al inicio de la lista direccionada por p.
//Parámetros:
//   Node<T>*& p – Puntero al primer nodo de la lista.
//   T e – Elemento que vamos a agregar al inicio de la lista (apilar).
//Retorna: Node<T>* – Dirección del nodo que contiene al elemento que se agregó.
//Ejemplo de uso:
//   Node<int>* p = NULL;
//   push<int>(p,1); // p->{1}
//   push<int>(p,2); // p->{2,1}
//   push<int>(p,3); // p->{3,2,1}
template <typename T>
void push(Node<T>*& p, T v)
{
   addFirst<T>(p, v);
}

//Prototipo: T pop(Node<T>*& p);
//Descripción: Remueve el primer nodo de la lista direccionada por p.
//Parámetro: Node<T>*& p – Puntero al primer nodo de la lista.
//Retorna: T – Elemento que contenía el nodo que fue removido.
//Ejemplo de uso:
//   Node<int>* p = NULL;
//   push<int>(p,1); // p->{1}
//   push<int>(p,2); // p->{2,1}
//   push<int>(p,3); // p->{3,2,1}
//   int e = pop<int>(p); // p->{2,1}
//   cout << e << endl; // Salida: 3
template <typename T>
T pop(Node<T>*& p)
{
   return removeFirst<T>(p);
}

//Prototipo: Node<T>* enqueue(Node<T>*& p,Node<T>*& q,T e);
//Descripción: Agrega el elemento e al final la lista direccionada por q.
//Parámetros:
//   Node<T>*& p – Puntero al primer nodo de la lista.
//   Node<T>*& q – Puntero al último nodo de la lista.
//   T e – Elemento que vamos a agregar al final de la lista (q).
//Retorna: Node<T>* – Dirección del nodo que contiene al elemento que se agregó.
//Ejemplo de uso:
//   Node<int>* p = NULL;
//   Node<int>* q = NULL;
//   enqueue<int>(p,q,1); // p->{1}<-q
//   enqueue<int>(p,q,2); // p->{1,2}<-q
//   enqueue<int>(p,q,3); // p->{1,2,3}<-q
template <typename T>
Node<T>* enqueue(Node<T>*& p, Node<T>*& q, T v)
{
   Node<T>* aux = new Node<T>();
   aux->sig=NULL;
   aux->data=v;

   if(p == NULL){
      p = aux;
   }
   else{
      q->sig = aux;
   }
   q = aux;

   return aux;
}

//Prototipo: Node<T>* enqueue(Node<T>*& q,T e);
//Descripción: Agrega el elemento e al final la lista circular direccionada por q.
//Parámetros:
//   Node<T>*& q – Puntero al último nodo de la lista circular.
//   T e – Elemento que vamos a agregar al final de la lista (q).
//Retorna: Node<T>* – Dirección del nodo que contiene al elemento que se agregó.
//Ejemplo de uso:
//   Node<int>* q = NULL;
//   enqueue<int>(q,1); // {1}<-q
//   enqueue<int>(q,2); // {1,2}<-q
//   enqueue<int>(q,3); // {1,2,3}<-q
template <typename T>
Node<T>* enqueue(Node<T>*& q, T e)
{
   Node<T>* aux = new Node<T>();
   aux->sig = NULL;
   aux->data = e;

   if( q == NULL)
   {
      aux->sig = aux;
   }
   else
   {
      aux->sig = q->sig;
      q->sig = aux;
   }
   q = aux;

   return aux;
}

//Prototipo: T dequeue(Node<T>*& p,Node<T>*& q);
//Descripción: Remueve el primer nodo de la lista direccionada por p.
//Parámetros:
//   Node<T>*& p – Puntero al primer nodo de la lista.
//   Node<T>*& q – Puntero al último nodo de la lista.
//Retorna: T – Elemento que contenía el nodo que fue removido.
//Ejemplo de uso:
//   Node<int>* p = NULL;
//   Node<int>* q = NULL;
//   enqueue<int>(p,q,1); // p->{1}<-q
//   enqueue<int>(p,q,2); // p->{1,2}<-q
//   enqueue<int>(p,q,3); // p->{1,2,3}<-q
//   int e = dequeue<int>(p,q); // p->{2,3}<-q
//   cout << e << endl; // Salida: 1
template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   Node<T>* aux = p;
   p = p->sig;
   T t = aux->data;
   delete aux;

   if( p==NULL )
   {
      q=NULL;
   }

   return t;
}

//Prototipo: T dequeue(Node<T>*& q);
//Descripción: Remueve el primer nodo de la lista circular direccionada por q.
//Parámetro: Node<T>*& q – Puntero al último nodo de la lista circular.
//Retorna: T – Elemento que contenía el nodo que fue removido.
//Ejemplo de uso:
//   Node<int>* q = NULL;
//   enqueue<int>(q,1); // {1}<-q
//   enqueue<int>(q,2); // {1,2}<-q
//   enqueue<int>(q,3); // {1,2,3}<-q
//   int e = dequeue<int>(q); // {2,3}<-q
//   cout << e << endl; // Salida: 1
template <typename T>
T dequeue(Node<T>*& q)
{
   Node<T>* aux = q->sig;
   q->sig = aux->sig;
   T t = aux->data;

   if(q == aux){
      q = NULL;
   }

   delete aux;
   return t;
}



//!!!!!!
template <typename T>
T* removeFirst2(Node<T>*&p){
    Node<T> *aux = p;

    //Muevo a p para que vaya al otro nodo
    p = p->sig;

    return &(aux->data);
}


#endif

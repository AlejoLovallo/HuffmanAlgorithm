#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct List
{
   Node<T>* inicio;
   Node<T>* indice;
};

//Prototipo: List<T> list();
//Descripción: Función de inicialización.
//Retorna: List<T> – La lista.
template<typename T>
List<T> list()
{
   List<T> lista = {NULL,NULL};

   return lista;
}

//Prototipo: T* listAdd(List<T>& lst,T e);
//Descripción: Agrega un elemento al final de la lista.
//Parámetros:
//   List<T>& lst - Lista.
//   T e – Elemento que se agregará al final de la lista.
//Retorna: T* – Dirección de memoria del elemento que se agregó.
template<typename T>
T* listAdd(List<T>& lst,T v)
{
   Node<T>* aux = add<T>(lst.inicio,v);

   if(lst.inicio->sig ==NULL)
      lst.indice = aux;

   return &(aux->data);
}

//Prototipo: T listRemove(List<T>& lst,K k,int cmpTK(T,K));
//Descripción: Remueve el elemento que concuerde con k según la función cmpTK.
//Parámetros:
//   List<T>& lst - Lista.
//   K k – Elemento que será removido de la lista.
//Retorna: T – Elemento que fue removido.
template<typename T,typename K>
void listRemove(List<T>& lst,K k, int cmpTK(T,K))
{
   remove<T,K>(lst.inicio, k, cmpTK);
}

//Prototipo: T* listFind(List<T>& lst,K k,int cmpTK(T,K));
//Descripción: Retorna la dirección del primer elemento concordante con k según cmpTK.
//Parámetros:
//   List<T>& lst - Lista.
//   K k – Clave o elemento a buscar.
//   int cmpTK(T,K) – Función de comparación.
//Retorna: T* – Dirección del elemento encontrado o NULL si hubo concordancia
template<typename T,typename K>
T* listFind(List<T> lst,K k, int cmpTK(T,K))
{
   Node<T>* aux = find<T,K>(lst.inicio, k, cmpTK);
   return &(aux->data);
}

//Prototipo: T* listOrderedInsert(List<T>& lst ,T t,int cmpTK(T,T));
//Descripción: Inserta un elemento según el orden que establece cmpTT. La lista debe
//estar ordenada (según cmpTT) o vacía.
//Parámetros:
//   List<T>& lst - Lista.
//   T t – Elemento a insertar.
//   int cmpTT(T,T) – Función de comparación.
//Retorna: T* – Dirección del elemento insertado.
template<typename T>
T* listOrderedInsert(List<T>& lst,T t,int cmpTT(T,T))
{
   Node<T>* aux = orderedInsert<T>(lst.inicio,t,cmpTT);

   if(lst.inicio->sig ==NULL)
         lst.indice = aux;

   return &(aux->data);
}

//Prototipo: void listSort(List<T> &lst,int cmpTT(T,T));
//Descripción: Ordena la lista según el criterio que establece cmpTT.
//Parámetros:
//   List<T>& lst – Lista.
//   int cmpTT(T,T) – Función de comparación.
//Retorna: void
template<typename T>
void listSort(List<T>& lst,int cmpTT(T,T))
{
   sort<T>(lst.inicio,cmpTT);
}

//Prototipo: bool listIsEmpty(List<T> lst);
//Descripción: Indica si la lista está vacía o tiene elementos.
//Parámetro: List<T>& lst – Lista.
//Retorna: bool – true si la lista está vacía, false si tiene elementos.
template<typename T>
bool listIsEmpty(List<T> lst)
{
   return !isEmpty(lst.inicio);
}

//Prototipo: bool listHasNext(List<T> lst);
//Descripción: Indica si quedan más elementos para seguir iterando la lista.
//Parámetro: List<T>& lst – Lista.
//Retorna: bool – true si es posible seguir iterando la lista.
template<typename T>
bool listHasNext(List<T>& lst)
{
   return !isEmpty(lst.indice);
}

//Prototipo: int listSize(List<T> lst);
//Descripción: Indica cuántos elementos tiene la lista.
//Parámetro: List<T>& lst – Lista.
//Retorna: int – Cantidad de elementos que tiene la lista.
template<typename T>
int listSize(List<T> lst)
{
   Node<T>* aux = lst.inicio;
   int cant = 0;
   while(aux != NULL)
   {
      cant++;
      aux = aux->sig;
   }

   return cant;
}

//Prototipo: T* listNext(List<T> lst);
//Descripción: Retorna la dirección del siguiente elemento de la lista en la iteración.
//Parámetro: List<T>& lst – Lista.
//Retorna: T* – Dirección del siguiente elemento en la iteración.
template<typename T>
T* listNext(List<T>& lst)
{
   T* aux = &(lst.indice->data);
   lst.indice = lst.indice->sig;
   return aux;
}

//Prototipo: void listReset(List<T>& lst);
//Descripción: Prepara la lista para iterarla.
//Parámetro: List<T>& lst – Lista.
//Retorna: void.
template<typename T>
void listReset(List<T>& lst)
{
   lst.indice = lst.inicio;
}

//Prototipo: void listFree(List<T>& lst);
//Descripción: Libera la memoria que ocupa la lista.
//Parámetro: List<T>& lst – Lista.
//Retorna: void
template<typename T>
void listFree(List<T>& lst)
{
   free<T>(lst.inicio);
}



//!!!!!!!!!!!!!!!

template <typename T>
T* listRemoveFirst(List<T>& lst){
    return removeFirst2<T>(lst.inicio);
}



//EJEMPLO BASE
//List<int> lst = listCreate<int>();
//listAdd<int>(lst,1);
//listAdd<int>(lst,2);
//listAdd<int>(lst,3);
//while( listHasNext<int>(lst) )
//{
// int* e = listNext<int>(lst);
// cout << e << endl;
//}
//listFree<int>(lst);

#endif

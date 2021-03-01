#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template<typename T>
struct Arr
{
   T* p;
   int cap;
   int length;
};

//Prototipo: Arr<T> arr(int cap);
//Descripci�n: Inicializa un array con capacidad cap y longitud inicial vac�a.
//Par�metro: int cap � Capacidad inicial del array.
//Retorna: Arr<T> � El array
//Ejemplo de uso:
//    // array y longitud
//    Arr<int> a = arr<int>(10);
template<typename T>
Arr<T> arr(int size)
{
   Arr<T> ar = {new T[size], size, 0};
   return ar;
}

//Prototipo: Arr<T> arr();
//Descripci�n: Inicializa un array cuya capacidad inicial se establece por defecto.
//Retorna: Arr<T> � El array.
//Ejemplo de uso:
//   // array y longitud
//   Arr<int> a = arr<int>();
template<typename T>
Arr<T> arr()
{
   return arr<T>(10);
}

//Prototipo: int arrAdd(Arr<T>& arr,T t);
//Descripci�n: Agrega t al final de arr incrementando, de ser necesario, su capacidad. Retorna la posici�n del arr donde qued� ubicado el elemento t.
//Par�metros:
//   Arr<T>& arr � El array.
//   T t � Elemento que se agregar�.
//Retorna: int � Posici�n de arr donde se agreg� el elemento t.
//Ejemplo de uso:
//   // array y longitud
//   Arr<int> a = arr<int>();
//   int pos = arrAdd<int>(a,10); // pos = 0
template<typename T>
int arrAdd(Arr<T>& a,T v)
{
   int pos = 0;

   if(a.cap == a.length)
      redimensionar<T>(a.p, a.cap, 2*a.cap);
   pos = add<T>(a.p, a.length, v);

   return pos;
}

//Prototipo: T* arrGet(Arr<T> arr,int p);
//Descripci�n: Retorna la direcci�n del elemento de arr ubicado en la posici�n p.
//Par�metros:
//   Arr<T> arr � El array.
//   int p � Posici�n del elemento de arr al cual queremos acceder.
//Retorna: T* � Direcci�n del elemento ubicado en la posici�n p del array arr.
//Ejemplo de uso:
//   Arr<int> a = arr<int>();
//   arrAdd<int>(a,10);
//   arrAdd<int>(a,20);
//   arrAdd<int>(a,30);
//   int* p = arrGet<int>(a,1);
//   *p = 22; // cambia 20 por 22
template<typename T>
T* arrGet(Arr<T> a,int p)
{
   return a.p + p;
}

//Prototipo: void arrSet(Arr<T>& a,int p,T t);
//Descripci�n: Asigna el elemento t en la posici�n p del array a.
//Par�metros:
//   Arr<T>& a � El array.
//   int p � Posici�n del elemento de a al cual queremos acceder.
//   T t � Elemento que vamos a asignar en la posici�n p de a.
//Retorna: void.
//Ejemplo de uso:
//   Arr<int> a = arr<int>();
//   arrAdd<int>(a,10);
//   arrAdd<int>(a,20);
//   arrAdd<int>(a,30);
//   arrSet<int>(a,1,99); // reemplaza 20 x 99
template<typename T>
void arrSet(Arr<T>& a,int p,T t)
{
   insert<T>(a.p, a.len, t, p);
}

//Prototipo: void arrInsert(Arr<T>& arr,T t,int p);
//Descripci�n: Inserta t en la posici�n p del array arr.
//Par�metros:
//   Arr<T>& arr � El array.
//   T t � Elemento a insertar.
//   int p � Posici�n donde quedar� insertado t.
//Retorna: void.
//Ejemplo de uso:
//   Arr<int> a = arr<int>();
//   arrInsert<int>(a,10,0);
//   arrInsert<int>(a,20,0);
//   arrInsert<int>(a,30,0);
//   int* p = arrGet<int>(a,0);
//   cout << *p << endl; // SALIDA: 30
template<typename T>
void arrInsert(Arr<T>& a,T v,int p)
{
   if(a.cap == a.length)
      redimensionar<T>(a.p, a.cap, 2*a.cap);
   insert<T>(a.p, a.length, v, p);
}

//Prototipo: int arrSize(Arr<T> arr);
//Descripci�n: Retorna la longitud actual del array arr.
//Par�metro: Arr<T> arr � El array.
//Retorna: int � Longitud del array arr.
//Ejemplo de uso:
//   Arr<int> a = arr<int>();
//   arrAdd<int>(a,10);
//   arrAdd<int>(a,20);
//   arrAdd<int>(a,30);
//   for(int i=0;i<arrSize<int>(a);i++)
//   {
//    int* e = arrGet<int>(a,i)
//    cout << *e << endl; // SALIDA: 10,20,30
//   }
template<typename T>
int arrSize(Arr<T> a)
{
   return a.length;
}

//Prototipo: T arrRemove(Arr<T>& arr,int p);
//Descripci�n: Remove el elemento de arr ubicado en la posici�n p.
//Par�metros:
//   Arr<T>& arr � El array.
//   int p � Posici�n a remover.
//Retorna: T � Elemento que ocupaba la posici�n p dentro de arr.
//Ejemplo de uso:
//   Arr<int> a = arr<int>();
//   arrAdd<int>(a,10);
//   arrAdd<int>(a,20);
//   arrAdd<int>(a,30);
//   int e = arrRemove<int>(a,0);
//   cout << e << endl; // SALIDA: 10
template<typename T>
T arrRemove(Arr<T>& a,int p)
{
   return remove<T>(a.p, a.length, p);
}

//Prototipo: void arrRemoveAll(Arr<T>& arr);
//Descripci�n: Remueve todos los elemento de arr dej�ndolo vaci�.
//Par�metro: Arr<T>& arr � El array.
//Retorna: void.
//Ejemplo de uso:
//   Arr<int> a = arr<int>();
//   arrAdd<int>(a,10);
//   arrAdd<int>(a,20);
//   arrAdd<int>(a,30);
//   // elimino todos los elementos
//   arrRemoveAll<int>(a);
//   cout << arrSize<int>(a) << endl; // SALIDA: 0
template<typename T>
void arrRemoveAll(Arr<T>& a)
{
   a.length = 0;
}

//Prototipo: int arrFind(Arr<T> arr,K k,int cmpTK(T,K));
//Descripci�n: Retorna la posici�n que k ocupa dentro de arr, seg�n la funci�n de
//             comparaci�n cmpTK, o un valor negativo si arr no contiene a k.
//Par�metros:
//   Arr<T>& arr � El array.
//   int k � Elemento a buscar.
//   int cmpTK(T,K) � Funci�n de comparaci�n.
//Retorna: int � Posici�n de la primera ocurrencia de k dentro de arr o un valor
//         negativo si arr no contiene a k.
//Ejemplo de uso:
//   Arr<int> a = arr<int>();
//   arrAdd<int>(a,10);
//   arrAdd<int>(a,20);
//   arrAdd<int>(a,30);
//   int pos = arrFind<int,int>(a,30,cmpInt);
//   cout << pos << endl; // SALIDA: 2
template<typename T,typename K>
int arrFind(Arr<T>& a,K k, int cmpTK(T,K))
{
   return find<T,K>(a.p, a.length, k, cmpTK);
}

//Prototipo: int arrOrderedInsert(Arr<T>& arr,T t,int cmpTT(T,T));
//Descripci�n: Inserta t en arr seg�n el criterio de precedencia que establece cmpTT.
//Par�metros:
//   Arr<T>& arr � El array.
//   T t � Elemento a insertara.
//   int cmpTT(T,T) � Funci�n de comparaci�n.
//Retorna: int � Posici�n donde qued� insertado t dentro de arr.
//Ejemplo de uso:
//   Arr<int> a = arr<int>();
//   arrOrderedInsert<int>(a,2,cmpInt);
//   arrOrderedInsert<int>(a,1,cmpInt);
//   arrOrderedInsert<int>(a,3,cmpInt);
//   for(int i=0;i<arrSize<int>(a);i++)
//   {
//    int* p = arrGet<int>(a,i);
//    cout << *p << endl; // SALIDA 1,2,3
//   }
template<typename T>
int arrOrderedInsert(Arr<T>& a,T t,int cmpTT(T,T))
{
   if(a.cap == a.length)
      redimensionar<T>(a.p, a.cap, 2*a.cap);
   return orderedInsert<T>(a.p, a.length, t, cmpTT);
}

//Prototipo: void arrSort(Arr<T>& arr,int cmpTT(T,T));
//Descripci�n: Ordena el array arr seg�n establece cmpTT.
//Par�metros:
//   Arr<T>& arr � El array.
//   int cmpTT(T,T) � Funci�n de comparaci�n.
//Retorna: void.
//Ejemplo de uso:
//   Arr<int> a = arr<int>();
//   arrAdd<int>(a,2);
//   arrAdd<int>(a,1);
//   arrAdd<int>(a,3);
//   // ordeno
//   arrSort<int>(a,cmpInt);
//   for(int i=0;i<arrSize<int>(a);i++)
//   {
//    int* p = arrGet<int>(a,i);
//    cout << *p << endl; // SALIDA 1,2,3
//   }
template<typename T>
void arrSort(Arr<T>& a,int cmpTT(T,T))
{
   sort<T>(a.p, a.length, cmpTT);
}

#endif

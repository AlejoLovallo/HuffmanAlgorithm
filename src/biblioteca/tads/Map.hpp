
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Arr.hpp"

using namespace std;

template<typename K,typename T>
struct Map
{
   Arr<K> keys;
   Arr<T> values;
   int pos;
};

//Prototipo: Map<K,V> map();
//Descripci�n: Inicializa un map.
//Retorna: Map<K,V> � El map.
//Ejemplo de uso:
//    Map<string,int> m = map<string,int>();
template<typename K,typename T>
Map<K,T> map()
{
   Map<K,T> map = {arr<K>(), arr<T>(), 0};
   return map;
}

//Prototipo: V* mapGet(Map<K,V> map,K k);
//Descripci�n: Retorna la direcci�n de memoria del valor asociado a la clave k o NULL si map no contiene ning�n valor asociado a dicha clave.
//Par�metros:
//   Map<K,V> map � El map.
//   K k � Clave con la cual, dentro del map, quedar� asociado el elemento v.
//Retorna: V* - Direcci�n de memoria del elemento vinculado con la clave k o NULL si map no contiene ning�n valor asociado a k.
//Ejemplo de uso:
//   int* v = mapGet<string,int>(m,v);
//   cout << k << ", " << v << endl;
template<typename K,typename T>
T* mapGet(Map<K,T>& m,K k)
{
   int i=0, tam=arrSize<K>(m.keys);
   K* p = arrGet<K>(m.keys,i);

   while(i<tam &&  *p!=k){
      i++;
      p = arrGet<K>(m.keys, i);
   }

   return (i!=tam)? arrGet<T>(m.values, i) : NULL;
}

//Prototipo: V* mapPut(Map<K,V>& map,K k,V v);
//Descripci�n: Agrega al map map el elemento v asociado a la clave k. Si exist�a una entrada vinculada a k se debe reemplazar el valor anterior por v.
//Par�metros:
//   Map<K,V>& map � El map.
//   K k � Clave con la cual, dentro del map, quedar� asociado el elemento v.
//   V v � Valor o elemento a agregar.
//Retorna: V* - Direcci�n de memoria del elemento vinculado con la clave k.
//Ejemplo de uso:
// creo un map y le agrego valores
//   Map<string,int> m = map<string,int>();
//   mapPut<string,int>(m,"uno",1);
//   mapPut<string,int>(m,"dos",2);
//   mapPut<string,int>(m,"tres",3);
template<typename K,typename T>
T* mapPut(Map<K,T>& m,K k,T v)
{
   T* p = mapGet<K>(m, k);

   if(p == NULL){
      int pos = arrAdd<K>(m.keys, k);
      arrAdd<T>(m.values, v);
      p = arrGet<T>(m.values, pos);
   }
   else{
      *p = v;
   }

   return p;
}

//Prototipo: bool mapContains(Map<K,V> map,K k);
//Descripci�n: Verifica si map contiene a k.
//Par�metros:
//   Map<K,V> map � El map.
//   K k �Clave.
//Retorna: bool - true o false seg�n map contenga, o no, una entrada vinculada a k.
//Ejemplo de uso:
//   //verifico si existe y muestro su valor asociado
//   if( mapContains<string,int>(m,k) )
//   {
//    int* v = mapGet<string,int>(m,k);
//    cout <<"El valor asociado a "<< k <<" es "<< v << endl;
//   }
template<typename K,typename T>
bool mapContains(Map<K,T>& m,K k)
{
   T* v = mapGet<K>(m,k);
   return (v == NULL)? false : true;
}

//Prototipo: V mapRemove(Map<K,V>& map,K k);
//Descripci�n: Elimina de map la entrada identificada con la clave k.
//Par�metros:
//   Map<K,V>& map � El map.
//   K k �Clave que identifica la entrada a remover.
//Retorna: V � Valor que conten�a la entrada asociada a la clave k.
template<typename K,typename T>
T mapRemove(Map<K,T>& m,K k)
{
   int pos=0, tam=arrSize<K>(m.keys);
   K* p = arrGet<K>(m.keys,pos);

   while(pos<tam &&  *p!=k){
      p = arrGet<K>(m.keys, pos);
      pos++;
   }

   T value = arrRemove<T>(m.values,pos);
   arrRemove<K>(m.keys,pos);
   return value;
}

//Prototipo: void mapRemoveAll(Map<K,V>& map);
//Descripci�n: Elimina todas las entradas del map map.
//Par�metros: Map<K,V>& map � El map.
//Retorna: void.
template<typename K,typename T>
void mapRemoveAll(Map<K,T>& m)
{
   arrRemoveAll<K>(m.keys);
   arrRemoveAll<T>(m.values);
   m.pos=0;
}

//Prototipo: int mapSize(Map<K,V> map);
//Descripci�n: Retorna la cantidad actual de entradas que tiene map.
//Par�metros: Map<K,V>& map � El map.
//Retorna: int � Cantidad de entradas que tiene map
template<typename K,typename T>
int mapSize(Map<K,T> m)
{
   return arrSize(m.keys);
}

//Prototipo: bool mapHasNext(Map<K,V> map);
//Descripci�n: Indica si quedan m�s elementos para continuar iterando el map.
//Par�metros: Map<K,V> map � El map.
//Retorna: bool � true o false seg�n queden elementos para continuar iterando.
template<typename K,typename T>
bool mapHasNext(Map<K,T>& m)
{
   return m.pos<arrSize(m.keys);
}

//Prototipo: K mapNextKey(Map<K,V>& map);
//Descripci�n: Permite iterar sobre las claves del map. Esta funci�n es mutuamente
//             excluyente respecto de mapNextValue.
//Par�metros: Map<K,V>& map � El map.
//Retorna: K � La siguiente clave dentro de una iteraci�n.
template<typename K,typename T>
K mapNextKey(Map<K,T>& m)
{
   K* key = arrGet<K>(m.keys,m.pos);
   m.pos++;
   return *key;
}

//Prototipo: V* mapNextValue(Map<K,V>& map);
//Descripci�n: Permite iterar sobre los valores que contiene el map. Esta funci�n es mutuamente excluyente despecto de mapNextKey.
//Par�metros: Map<K,V>& map � El map.
//Retorna: V* � Direcci�n de memoria del siguiente valor dentro de una iteraci�n.
template<typename K,typename T>
T* mapNextValue(Map<K,T>& m)
{
   T* v = arrGet<T>(m.values, m.pos);
   m.pos++;
   return v;
}

//Prototipo: void mapReset(Map<K,V>& map);
//Descripci�n: Prepara el map para comenzar una nueva iteraci�n.
//Par�metros: Map<K,V>& map � El map.
//Retorna: void
template<typename K,typename T>
void mapReset(Map<K,T>& m)
{
   m.pos = 0;
}

//Prototipo: void mapSortByKeys(Map<K,V>& map,int cmpKK(K,K);
//Descripci�n: Ordena el map aplicando sobre sus claves el criterio que establece cmpKK.
//Par�metros:
//   Map<K,V> map � El map.
//   int cmpKK(K,K) - Funci�n de comparaci�n.
//Retorna: void.
template<typename K,typename T>
void mapSortByKeys(Map<K,T>& m,int cmpKK(K,K))
{
   arrSort<K>(m.keys,cmpKK);
}

//Prototipo: void mapSortByValues(Map<K,V>& map,int cmpVV(V,V);
//Descripci�n: Ordena el map aplicando sobre sus values el criterio que establece cmpVV.
//Par�metros:
//   Map<K,V> map � El map.
//   int cmpVV(V,V) � Funci�n de comparaci�n.
//Retorna: void.
template<typename K,typename T>
void mapSortByValues(Map<K,T>& m,int cmpTT(T,T))
{
   arrSort<T>(m.values,cmpTT);
}

//Ejemplo de uso
/*
// creo un map y le agrego valores
   Map<string,int> m = map<string,int>();
   mapPut<string,int>(m,"uno",1);
   mapPut<string,int>(m,"dos",2);
   mapPut<string,int>(m,"tres",3);

   // el usuario ingresa una clave
   string k;
   cin >> k;

   // verifico si existe y muestro su valor asociado
   if( mapContains<string,int>(m,k) )
   {
       int* v = mapGet<string,int>(m,k);
       cout <<"El valor asociado a "<< k <<" es "<< *v << endl;
       // el usuario ingresa un valor para modificar el anterior
       int nuevoVal;
       cin >> nuevoVal;
       // modificamos el valor asociado a k
       *v = nuevoVal;
      }

   // itero el map mostrando sus valores
   mapReset<string,int>(m);
   while( mapHasNext<string,int>(m))
   {
       string k = mapNextKey<string,int>(m);
       int* v = mapGet<string,int>(m,k);
       cout << k << ", " << *v << endl;
   }
*/

#endif

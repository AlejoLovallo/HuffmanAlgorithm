#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

//Prototipo: int add(T arr[],int& len,T e);
//Descripci�n: Agrega el elemento e al final de arr incrementando su longitud len.
//Par�metros:
//    T arr[] � Array donde agregaremos un elemento.
//    int& len � Longitud actual del array.
//    T e � Elemento que vamos a agregar.
//Retorna: int � Posici�n del array donde qued� ubicado el elemento que agregamos.
//Ejemplo de uso:
// // array y longitud
// string a[10];
// int len = 0;
// // agrego elementos
// add<string>(a,len,"John");
// add<string>(a,len,"Paul");
// add<string>(a,len,"George");
// add<string>(a,len,"Ringo");
// // recorro y muestro
// for(int i=0;i<len;i++){
//    cout << a[i] << endl;
// }
template <typename T> int add(T arr[], int& len, T v)
{
   arr[len] = v;
   len++;
   return (len-1);
}

//Prototipo: void insert(T arr[],int& len,T e,int p);
//Descripci�n: Inserta el elemento e en la posici�n p del array arr. Desplaza los
//             elementos ubicados a partir de p+1 e incrementa la longitud len.
//Par�metros:
//    T arr[] � Array donde agregaremos un elemento.
//    int& len � Longitud actual del array.
//    T e � Elemento que vamos a agregar.
//    int p � Posici�n donde se insertar� el nuevo elemento.
//Retorna: void.
//Ejemplo de uso:
//    // array y longitud
//    string a[10];
//    int len = 0;
//    // agrego elementos
//    insert<string>(a,len,"John",0);
//    insert<string>(a,len,"Paul",0);
//    insert<string>(a,len,"George",0);
//    insert<string>(a,len,"Ringo",0);
//    // recorro y muestro
//    for(int i=0;i<len;i++)
//    {
//       cout << a[i] << endl; // SALIDA: Ringo,George,Paul,John
//    }
template <typename T>
void insert(T arr[], int& len, T v, int pos)
{
   for(int i=len ; i>pos ; i--){
      arr[i] = arr[i-1];
   }
   arr[pos] = v;

   len++;
}

//Prototipo: T remove(T arr[],int& len, int p);
//Descripci�n: Remueve el elemento ubicado en la posici�n p del array arr. Desplaza
//             ubicados a partir de p y decrementa la longitud len.
//Par�metros:
//    T arr[] � Array donde agregaremos un elemento.
//    int& len � Longitud actual del array.
//    int p � Posici�n cuyo elementoo ser� removido.
//Retorna: T � Elemento que fue removido del array.
//Ejemplo de uso:
//   // array y longitud
//   string a[10];
//   int len = 0;
//   // agrego elementos
//   add<string>(a,len,"John");
//   add<string>(a,len,"Paul");
//   add<string>(a,len,"George");
//   add<string>(a,len,"Ringo");
//   while( len>0 )
//   {
//    cout << remove<string>(a,len,0) << endl;
//   }
template <typename T>
T remove(T arr[], int& len, int pos)
{
   T aux = arr[pos];

   len--;
   for(int i=pos ; i<len ; i++){
      arr[i] = arr[i+1];
   }

   return aux;
}

//Prototipo: int find(T arr[],int len,K k, int cmpTK(T,K));
//Descripci�n: Retorna la posici�n de la primera ocurrencia de k dentro de arr o un
//             valor negativo si arr no contiene a k.
//Par�metros:
//    T arr[] � Array donde agregaremos un elemento.
//    int len � Longitud actual del array.
//    K k � Valor a buscar dentro de arr.
//    int cmpTK(T,K) � Funci�n de comparaci�n.
//Retorna: int � Posici�n de la primera ocurrencia de k dentro de arr o un valor
//          negativo si arr no contiene a k.
//Ejemplo de uso:
//   struct Persona
//   {
//    int dni;
//    string nom;
//   };
//   Persona persona(int d,string n)
//   {
//    return {d,n};
//   }
//   int cmpPersonaDNI(Persona p,int d)
//   {
//    return p.dni-d;
//   }
//   // array de personas
//   int len=3;
//   Persona arr[] = {persona(10,"Pablo")
//    ,persona(20,"Pedro")
//    ,persona(30,"Juan")
//   };
//   // busco por DNI
//   int pos = find<Persona,int>(arr,len,20,cmpPersonaDNI);
//   cout << pos << endl; // SALIDA: 1
//   }
template <typename T, typename K>
int find(T arr[], int len, K v, int cmpTK(T,K))
{
   int i= 0;

   while((i<len) && (cmpTK(arr[i],v)!=0)){
      i++;
   }

   return (i<len)? i : -1;
}

//Prototipo: int orderedInsert(T arr[],int len,T e,int cmpTT(T,T));
//Descripci�n: Inserta  dentro de arr seg�n el criterio de precedencia que establece
//             cmpTT, y retorna la posici�n donde dicho elemento qued� insertado.
//             El array arr debe estar ordenado o vac�o.
//Par�metros:
//   T arr[] � Array donde agregaremos un elemento.
//   int len � Longitud actual del array.
//   T e � Valor a insetar dentro de arr.
//   int cmpTT(T,T) � Funci�n de comparaci�n.
//Retorna: int � retorna la posici�n donde dicho elemento qued� insertado
//Ejemplo de uso:
//   // funcion de comparacion
//   int cmpInt(int a,int b){return a-b;}
//   // array y longitud
//   int arr[] = {1,2,3,5,6,7,8};
//   int len = 7;
//   int pos = orderedInsert<int>(arr,len,4,cmpInt);
//   cout << pos << endl;
template <typename T>
int orderedInsert(T arr[], int& len, T v, int cmpTT(T,T))
{
   int pos = 0;
   while((pos<len) && (cmpTT(v,arr[pos])>0)){
      pos++;
   }
   insert<T>(arr, len, v, pos);
   return pos;
}

//Prototipo: void sort(T arr[],int len,int cmpTT(T,T));
//Descripci�n: Ordena arr seg�n el criterio de precedencia que establece cmpTT.
//Par�metros:
//   T arr[] � Array donde agregaremos un elemento.
//   int len � Longitud actual del array.
//   int cmpTT(T,T) � Funci�n de comparaci�n.
//Retorna: void.
//Ejemplo de uso:
//   // funcion de comparacion
//   int cmpInt(int a,int b){return a-b;}
//   // array y longitud
//   int arr[] = {5,4,3,2,1};
//   int len = 5;
//   // ordeno y muestro
//   sort<int>(arr,len,cmpInt);
//   for(int i=0;i<len;i++)
//   {
//    cout << arr[i] << endl;
//   }
template <typename T>
void sort(T arr[], int len, int cmpTT(T,T))
{
   for(int i=0 ; i<len ; i++){
      for(int j=0 ; j<(len-1) ; j++){
         if(cmpTT(arr[j],arr[j+1])>0){
            T aux = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = aux;
         }
      }
   }
}

template <typename T>
void redimensionar(T* a,int cap,int nuevaCap)
{
   // creo un array con la nueva capacidad
   T* b = new T[nuevaCap];
   // copio los datos del array a al array b
   for(int i=0; i<cap; i++)
   {
      b[i]=a[i];
   }
   // libero el array a
   delete[] a;
   a = b;
}

#endif

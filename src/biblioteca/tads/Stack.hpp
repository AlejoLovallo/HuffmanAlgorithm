#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Stack
{
   Node<T>* inicio;
};

template<typename T>
Stack<T> stack()
{
   Stack<T> pila = {NULL};
   return pila;
}

//Prototipo: T* stackPush(Stack<T>& st,T e);
//Descripci�n: Apila el elemento e.
//Par�metros:
//   Stack<T>& st - Pila.
//   T e � Elemento que se apilar�.
//Retorna: T* � Direcci�n de memoria del elemento que se apil�.
template<typename T>
void stackPush(Stack<T>& st,T v)
{
   push<T>(st.inicio,v);
}

//Prototipo: T stackPop(Stack<T>& st);
//Descripci�n: Desapila un elemento.
//Par�metro: Stack<T>& st - Pila.
//Retorna: T � Elemento que se desapil�.
template<typename T>
T stackPop(Stack<T>& st)
{
   return pop<T>(st.inicio);
}

//Prototipo: bool stackIsEmpty(Stack<T> st);
//Descripci�n: Retorna true o false seg�n la pila tenga elementos o no.
//Par�metro: Stack<T>& st - Pila.
//Retorna: bool �true o false seg�n la pila tenga elementos o no.
template<typename T>
bool stackIsEmpty(Stack<T> st)
{
   return isEmpty<T>(st.inicio);
}

//Prototipo: int stackSize(Stack<T> st);
//Descripci�n: Retorna la cantidad de elementos que tiene la pila.
//Par�metro: Stack<T>& st - Pila.
//Retorna: int � Cu�ntos elementos tiene la pila.
template<typename T>
int stackSize(Stack<T> st)
{
   Node<T>* aux = st.inicio;
   int cant = 0;
   while(aux != NULL)
   {
      cant++;
      aux = aux->sig;
   }

   return cant;
}


//Stack<int> st = stack<int>();
//stackPush<int>(st,1);
//stackPush<int>(st,2);
//stackPush<int>(st,3);
//while( !stackIsEmpty<int>(st) )
//{
// int e = stackPop<int>(st);
// cout << e << endl; // Salida: 3,2,1
//}

#endif

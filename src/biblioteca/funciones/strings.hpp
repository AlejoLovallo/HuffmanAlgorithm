#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

// --[ Funciones Basicas ]--

// --[ Funciones Basicas ]--

//Prototipo: int length(string s);
//Descripci�n: Cuenta la cantidad de caracteres que componen la cadena s.
//Par�metro:
//    string s � Cadena cuya longitud debemos averiguar.
//Retorna: int � Cu�ntos caracteres contiene la cadena s.
//Ejemplo de uso:
//    string s = "Hola";
//    int n = length(s);
//    cout << n << endl; // muestra: 4 s = "";
//    n = length(s);
//    cout << n << endl; // muestra: 0
int length(string s)    //OK
{
   int cont = 0;

   while(s[cont] != '\0'){
      cont++;
   }

   return cont;
}


//Prototipo: int charCount(string s,char c);
//Descripci�n: Cuenta la cantidad de veces que aparece el car�cter c dentro de s.
//Par�metros:
//   string s � Cadena que contiene al car�cter c.
//   char c � Car�cter cuya cantidad de ocurrencias queremos averiguar.
//Retorna: int � Cu�ntas veces aparece c dentro de la cadena s.
//Ejemplo de uso:
//    string s = "Esto es una prueba";
//    int n = charCount(s,'e');
//    cout << n << endl; // muestra: 2
//    n = charCount(s,' ');
//    cout << n << endl; // muestra: 3
int charCount(string s,char c)   //OK
{
   int cont=0;

   for(int i=0 ; s[i]!='\0' ; i++){
      if(s[i] == c)
         cont++;
   }

   return cont;
}


//Prototipo: string substring(string s,int d,int h);
//Descripci�n: Retorna la subcadena de s comprendida entre las posiciones d (inclu-sive) y h (no inclusive).
//Par�metros:
//    string s � Cadena que contiene la subcadena que queremos obtener.
//    int d � Posici�n (inclusive) que indica d�nde comienza la subcadena.
//    int h � Posici�n (no inclusive) que indica d�nde finaliza la subcadena.
//Retorna: string � La subcadena de s comprendida comprendida entre las posi-ciones d (inclusive) y h (no inclusive).
//Ejemplo de uso:
//    string s = "Esto es una prueba";
//    string x = substring(s,2,10);
//    cout << x << endl; // muestra: to es un
//    x = substring(s,2,length(s));
//    cout << x << endl; // muestra: to es una prueba
string substring(string s,int d,int h)    //OK
{
   string subCadena = "";

   for(int i=0 ; s[i]!='\0' ; i++){
      if(i>=d && i<h)
         subCadena += s[i];
   }

   return subCadena;
}


//Prototipo: string substring(string s,int d);
//Descripci�n: Retorna la subcadena de s comprendida entre la posici�n d y el final de la cadena.
//Par�metros:
//    string s � Cadena que contiene la subcadena que queremos obtener.
//    int d � Posici�n (inclusive) que indica d�nde comienza la subcadena.
//Retorna: string � La subcadena de s comprendida comprendida entre la posici�n d (inclusive) y el final de la cadena.
//Ejemplo de uso:
//    string s = "Esto es una prueba";
//    string x = substring(s,2);
//    cout << x << endl; // muestra: to es una prueba
string substring(string s,int d)    //OK
{
   string subCadena="";

   for(int i=0 ; s[i]!='\0' ; i++){
      if(i>=d)
         subCadena += s[i];
   }

   return subCadena;
}


//Prototipo: int indexOf(string s,char c);
//Descripci�n: Retorna la posici�n que ocupa la primera ocurrencia del car�cter c dentro de la cadena s, o -1 si s no contiene a c.
//Par�metros:
//    string s - Cadena que contiene al car�cter c.
//    char c - Car�cter cuya posici�n, dentro de s, queremos averiguar.
//Retorna: string � La posici�n que ocupa, dentro de s, la primera ocurrencia del car�cter c, o un valor negativo si s no contiene a c.
//Ejemplo de uso:
//    string s = "Esto es una prueba";
//    int p = indexOf(s,'e');
//    cout << p << endl; // muestra: 5
//    p = indexOf(s,'X');
//    cout << p << endl; // muestra: -1
int indexOf(string s,char c)     //OK
{
   int pos = -1;

   for(int i=0 ; s[i]!='\0' ; i++){
      if((pos == -1) && (s[i] == c)){
         pos = i;
      }
   }

   return pos;
}


//Prototipo: int indexOf(string s,char c,int offset);
//Descripci�n: Retorna la posici�n que ocupa la primera ocurrencia de un car�cter c dentro de la cadena s, descartando los primeros offeset caracteres (desplaza-miento inicial).
//Par�metros:
//    string s - Cadena que contiene al car�cter c.
//    char c - Car�cter cuya posici�n, dentro de s, queremos averiguar.
//    int offset - Posici�n de desplazamiento desde donde debemos buscar.
//Retorna: string � La posici�n que ocupa, dentro de s, la primera ocurrencia del car�cter c, considerando desde offset.
//Ejemplo de uso:
//    string s = "Esto es una prueba";
//    int p = indexOf(s,'e',0);
//    cout << p << endl; // muestra: 5
//    p = indexOf(s,'e',12);
//    cout << p << endl; // muestra: 15
//    p = indexOf(s,'E',1);
//    cout << p << endl; // muestra: -1
int indexOf(string s,char c,int offSet)   //--->
{
   s = substring(s, offSet);
   int pos = indexOf(s, c);

   return (pos != -1? pos+offSet: -1);
}

//Prototipo: int lastIndexOf(string s,char c);
//Descripci�n: Retorna la posici�n de la �ltima ocurrencia del car�cter c dentro de s.
//Par�metros:
//    string s - Cadena que contiene al car�cter c.
//    char c - Car�cter cuya �ltima posici�n, dentro de s, queremos averiguar.
//Retorna: string � La posici�n que ocupa, dentro de s, la �ltima ocurrencia del car�cter c, o un valor negativo si s no contiene a c.
//Ejempl0:
//       string s = "Esto es una prueba";
//       int p = lastIndexOf(s,'u');
//       cout << p << endl; // muestra: 14
//       p = lastIndexOf(s,'e');
//       cout << p << endl; // muestra: 15
//       p = lastIndexOf(s,'E');
//       cout << p << endl; // muestra: 0
int lastIndexOf(string s,char c)    //OK
{
//   int pos = -1, aux = -1;
//   string cadenaCortada;
//
//   for(int i=0 ; s[i]!='\0' ; i++){
//      cadenaCortada = substring(s, i);
//      aux = indexOf(cadenaCortada, c);
//
//      if(aux != -1){
//         pos = i+aux;
//         i += pos;
//      }
//   }

   int pos=0;

   for(int i=0 ; s[i]!='\0' ; i++){
      if(s[i] == c)
         pos = i;
   }

   return pos;
}


//Prototipo: int indexOfN(string s,char c,int n);
//Descripci�n: Retorna la posici�n de la n-�sima ocurrencia de c dentro de s.
//Par�metros:
//    string s - Cadena que contiene al car�cter c.
//    char c - Car�cter cuya posici�n se debe determinar. Se asume que s contiene a c, al menos, n veces.
//    int n - N�mero de ocurrencia de c, contando desde 1.
//Retorna: int - La posici�n de la n-�sima ocurrencia de c dentro de s.
//Ejemplo de uso:
//    string s = "John|Paul|George|Ringo";
//    int p = indexOfN(s,'|',1);
//    cout << p << endl; // muestra: 4
//    p = indexOfN(s,'|',2);
//    cout << p << endl; // muestra: 9
//    p = indexOfN(s,'|',3);
//    cout << p << endl; // muestra: 16
int indexOfN(string s,char c,int n)    //--->
{
   int pos = -1;

   pos = indexOf(s, c);
   for(int i=1 ; i!=n ; i++){
       pos = indexOf(s,c,pos+1);
   }

   return pos;
}
//int indexOfN(string s,char c,int n)
//{
//   int aux=0, pos=-1, cont=0;
//   string cadenaCortada;
//
//   for(int i=0 ; s[i]!='\0' ; i++){
//      cadenaCortada = substring(s, i);
//      pos = indexOf(cadenaCortada, c);
//
//      if(pos!=-1 && cont<n){
//         aux = i+ pos;
//         i += pos;
//         cont++;
//      }
//   }
//
//   return cont==n?aux:-1;
//}

//Prototipo: int charToInt(char c);
//Descripci�n: Retorna el valor num�rico del car�cter c (que debe ser num�rico).
//Par�metros: char c - Car�cter cuyo valor ser�: '0', '1', � o '9'.
//Retorna: int - El valor num�rico del car�cter c.
//Ejemplo de uso:
//    char c = '2';
//    int n = charToInt(c);
//    cout << n << endl; // muestra: 2
int charToInt(char ch)     //OK
{
   return (int)(ch - '0');
}


//Prototipo: char intToChar(int i);
//Descripci�n: Retorna el car�cter que representa al valor de i, que debe estar com-prendido entre 0 y 9. Es la funci�n inversa de charToInt.
//Par�metro: int i - Valor num�rico entero comprendido entre 0 y 9.
//Retorna: char - El car�cter que representa al valor de i.
//Ejemplo de uso:
//    int i = 2;
//    char c = intToChar(i);
//    cout << c << endl; // muestra: 2
char intToChar(int i)      //OK
{
   return (char)i + '0';
}


//Prototipo: int getDigit(int n,int i);
//Descripci�n: Retorna el i-�simo d�gito del valor de n.
//Par�metros:
//    int n � N�mero entero de 1 o m�s d�gitos desde donde que se quiere obtener el d�gito que se ubica en la i-�sima posici�n.
//    int i - Posici�n, contando desde 0 (cero) y de derecha a izquierda, del d�-gito de n que queremos obtener.
//Retorna: int - El d�gito que se ubica en la i-�sima posici�n de n.
//Ejemplo de uso:
//    int n = 12345;
//    int i = 0;
//    int r = getDigit(n,i);
//    cout << r << endl; // muestra: 5
//    i = 1;
//    r = getDigit(n,i);
//    cout << r << endl; // muestra: 4
int getDigit(int n,int i)     //OK
{
   int cont = 0;

   while(cont != i){
      cont++;
      n /= 10;
   }

   return (n%10);
}


//Prototipo: int digitCount(int n);
//Descripci�n: Retorna la cantidad de d�gitos que contiene el valor de n.
//Par�metro:
//    int n - Valor num�rico cuya cantidad de d�gitos queremos averiguar.
//Retorna: int - La cantidad de d�gitos que tiene el valor de n.
//Ejemplo de uso:
//    int n = 12345;
//    int i = digitCount(n);
//    cout << i << endl; // muestra: 5
int digitCount(int i)      //OK
{
   int digitos = 1;

   while(i/10 != 0){
      digitos++;
      i=i/10;
   }

   return digitos;
}


//Prototipo: string intToString(int i);
//Descripci�n: Retorna una cadena de caracteres representando el valor i.
//Par�metro: int i - Valor num�rico entero que se va a representar como string.
//Retorna: string - Cadena de caracteres que representando el valor de i.
//Ejemplo de uso:
//    int i = 12345;
//    string s = intToString(i);
//    cout << s << endl; // muestra: 12345
string intToString(int num)         //OK
{
   int posDigitos = digitCount(num)-1;
   int aux=0;
   string cadena="";

   for(int i=posDigitos ; i>=0 ; i--){
      aux = getDigit(num, i);
      cadena += intToChar(aux);
   }

   return cadena;
}

//Prototipo: int stringToInt(string s);
//Descripci�n: Retorna el valor num�rico de la cadena s, que debe contener s�lo d�gitos num�ricos. Esta funci�n es la funci�n inversa de intToString.
//Par�metro: string s - Cadena de caracteres que s�lo contiene d�gitos num�ricos.
//Retorna: int - El valor num�rico que est� representado en la cadena s.
//Ejemplo de uso:
//    string s = "12345";
//    int i = stringToInt(s);
//    cout << i << endl; // muestra: 12345
int stringToInt(string s)          //OK
{
   int num=0;
   int digits = length(s)-1, digito;

   for(int i=0 ; s[i]!='\0' ; i++){
      digito = charToInt((char)s[i]);
      num += (digito* pow(10,digits));
      digits--;
   }

   return num;
}

//Prototipo: int stringToInt(string s,int b); // SOBRECARGA
//Descripci�n: Retorna el valoro num�rico representado en la cadena s, considerando que dicho valor est� expresado en la base num�rica b.
//Par�metros:
//    string s - Cadena que representa un valor num�rico entero en base b.
//    int b - Base num�rica del valor que representado en la cadena s.
//Retorna: int - El n�mero num�rico representado en la cadena s.
//Ejemplo de uso:
//    string s = "10";
//    int i = stringToInt(s,10);
//    cout << i << endl; // muestra: 10
//    i = stringToInt(s,2);
//    cout << i << endl; // muestra: 2
//    i = stringToInt(s,16);
//    cout << i << endl; // muestra: 16
int stringToInt(string s,int b)        //OK
{
   int num=0, digito;
   int digits = length(s)-1;

    for(int i=0 ; s[i]!='\0' ; i++){
       digito = charToInt((char)s[i]);

       if(s[i]>='A' && s[i]<='Z')
          digito-=7;

       num += (digito* pow(b,digits));
       digits--;
    }

   return num;
}

//Prototipo: string charToString(char c);
//Descripci�n: Retorna una cadena cuyo �nico car�cter es c.
//Par�metro:
//       char c � Car�cter que ser� el contenido de la cadena.
//Retorna: string - Una cadena de longitud 1 cuyo �nico car�cter ser� c.
//Ejemplo de uso:
//       char c = 'A';
//       string s = charToString(c);
//       cout << s << endl; // muestra: A
//       cout << length(s) << endl; // muestra: 1
//       c = ' ';
//       string s = charToString(c);
//       cout << s << endl; // muestra: [VACIO]
//       cout << length(s) << endl; // muestra: 1
string charToString(char c)         //OK
{
   string cadena="";
   cadena += c;
   return cadena;
}

//Prototipo: char stringToChar(string s);
//Descripci�n: Retorna el �nico car�cter que contiene la cadena s. Esta es la funci�n inversa de charToString.
//Par�metro:
//       string s - Cadena de caracteres de longitud 1.
//Retorna: char - El �nico car�cter que contiene la cadena s.
//Ejemplo de uso:
//       string s = "A";
//       char c = stringToChar(s);
//       cout << c << endl; // muestra: A
//       cout << (int)c << endl; // muestra: 65
//       s = " ";
//       c = stringToChar(s);
//       cout << c << endl; // muestra: [VACIO]
//       cout << (int)c << endl; // muestra: 32, ASCII de ' '
char stringToChar(string s)         //OK
{
   return s[0];
}

//Prototipo: string stringToString(string s);
//Descripci�n: Retorna la misma cadena que recibe. Se trata de una funci�n trivial que usaremos m�s adelante, dentro de este mismo cap�tulo.
//Par�metro:
//       string s - Cadena de caracteres.
//Retorna: string � La misma cadena que recibe como par�metro.
//Ejemplo de uso:
//       string s = stringToString("Hola");
//       cout << s << endl; // muestra: Hola
string stringToString(string s)        //OK
{
   return s;
}

//Prototipo: string doubleToString(double d);
//Descripci�n: Retorna una cadena representando el valor contenido en d.
//Par�metro: double d - Valor que se representar� como cadena.
//Retorna: string - Cadena de caracteres representando el valor de d.
//Ejemplo de uso:
//       double d = 123.4;
//       string s = doubleToString(d);
//       cout << s << endl; // muestra: 123.4
string doubleToString(double d)        //--->
{
   int parteEntera = (int)d;
   int parteDecimal = (d-parteEntera)*1000000;
   string numero = intToString(parteEntera);

   numero += ',';
   numero += intToString(parteDecimal);

   return numero;
}

//Prototipo: double stringToDouble(string s);
//Descripci�n: Retorna el valor num�rico representado en la cadena s.
//Par�metro:
//       string s - Cadena que contiene un valor compatible con double.
//Retorna: double � El valor que est� representado en la cadena s.
//Ejemplo de uso:
//       string s = "123,4";
//       double d = stringToDouble(s);
//       cout << d << endl; // muestra: 123.4
double stringToDouble(string s)
{
   double num=0, peso=0;
   int posComa = indexOf(s , ',');
   int exponente=0, digito=0;

   exponente = posComa-1;

   for(int i=0 ; s[i]!='\0' ; i++){
      if(s[i]!=','){
         digito = charToInt((char)s[i]);
         peso = pow(10, exponente);
         num += ((double)digito * peso);
         exponente--;
      }
   }

   return num;
}

//Prototipo: bool isEmpty(string s);
//Descripci�n: Retorna true o false seg�n s sea o no la cadena vac�a.
//Par�metro:
//    string s - Una cadena de caracteres.
//Retorna: bool � Retorna true si s es la cadena vac�a o false si no lo es.
//Ejemplo de uso:
//    string s = "";
//    if( isEmpty(s) ) { cout << "Cadena vacia" << endl; }
//    s = "Hola";
//    if( !isEmpty(s) ) { cout << "No es la cadena vacia" << endl; }
bool isEmpty(string s)        //OK
{
   return length(s)!=0?false:true;
}

//Prototipo: bool contains(string s,char c);
//Descripci�n: Determinar si la cadena s contiene al car�cter c.
//Par�metros:
//    string s - Cadena que podr�a contener al car�cter c.
//    char c - Car�cter cuyo valor podr�a estar contenido en s.
//Retorna: bool - true si s contiene a c; false si no lo contiene.
//Ejemplo de uso:
//    string s = "abcd";
//    char c = 'b';
//    if( contains(s,c) ) {
//       cout << s << " contiene a: " << c << endl;
//    }
//    c = 'X';
//    if( !contains(s,c) ) {
//       cout << s << " NO contiene a: " << c << endl;
//    }
bool contains(string s, char c)        //OK
{
   return indexOf(s,c)!=-1?true:false;
}

//Prototipo: string replace(string s,char oldChar,char newChar);
//Descripci�n: Reemplaza en s todas las ocurrencias de oldChar por newChar.
//Par�metros:
//    string s - Cadena sobre la cual se reemplazar�n los caracteres.
//    char oldChar - Car�cter que va a ser reemplazado por newChar.
//    char newChar - Valor que reemplazar� todas las ocurrencias de oldChar.
//Retorna: string - La cadena s con caracteres oldChar donde antes ten�a oldChar.
//Ejemplo de uso:
//    string s = "Esto es una prueba";
//    string r = replace(s,'e','X');
//    cout << r << endl; // SALIDA: Esto Xs una pruXba
string replace(string s, char oldChar, char newChar)        //--->
{
   int pos = indexOf(s, oldChar);

   while(pos != -1){
      s[pos] = newChar;
      pos = indexOf(s, oldChar);
   }

   return s;
}

//Prototipo: string insertAt(string s,int pos,char c);
//Descripci�n: Insertar el car�cter c en la posici�n pos de la cadena s.
//Par�metros:
//    string s - Cadena de caracteres donde se insertar� un car�cter.
//    int pos - Posici�n de s se va a insertar al car�cter c.
//    char c - Car�cter que se insertar� en s, en la posici�n pos.
//Retorna: string - Una cadena cuya longitud ser� length(s)+1, id�ntica a s pero con el valor de c insertado en la posici�n pos.
//Ejemplo de uso:
//    string s = "Esto es una prueba";
//    int pos = 6;
//    char c = 'X';
//    string r = insertAt(s,pos,c);
//    cout << r << endl; // SALIDA: Esto eXs una prueba
string insertAt(string s,int pos,char c)        //OK
{
   string primeraParte = substring(s,0,pos);
   string segundaParte = substring(s,pos);
   string cadenaCompleta;

   primeraParte += c;
   cadenaCompleta = primeraParte + segundaParte;

   return cadenaCompleta;
}

//Proototipo: string removeAt(string s,int pos);
//Descripci�n: Remover de s el car�cter ubicado en la posici�n pos.
//Par�metros:
//    string s - Cadena de caracteres sobre la cual se remover� un car�cter.
//    int pos - Posici�n del car�cter que se remover�.
//Retorna: string - Una cadena igual a s pero sin s[pos].
//Ejemplo de uso:
//    string s = "Esto es una prueba";
//    int pos = 7;
//    string r = removeAt(s,pos);
//    cout << r << endl; // SALIDA: Esto esuna prueba
string removeAt(string s,int pos)         //OK
{
   string primeraParte = substring(s,0,pos);
   string segundaParte = substring(s,pos+1);
   string cadenaCompleta;

   cadenaCompleta = primeraParte + segundaParte;

   return cadenaCompleta;
}

//Funci�n ltrim
//Prototipo: string ltrim(string s);
//Descripci�n: Recorta los espacios en blanco que se encuentren a la izquierda de s.
//Par�metro:
//    string s - Cadena que podr�a tener espacios a la izquierda.
//Retorna: string - Una cadena id�ntica a s pero sin espacios a la izquierda.
//Ejemplo de uso:
//    string s = " Esto es una prueba";
//    string r = ltrim(s); // muestra: [Esto es una prueba]
//    cout << "[" << r << "]" << endl;
//    s = "Esto es una prueba";
//    r = ltrim(s); // muestra: [Esto es una prueba]
//    cout << "[" << r << "]" << endl;
//    s = " Esto es una prueba ";
//    r = ltrim(s); // muestra: [Esto es una prueba ]
//    cout << "[" << r << "]" << endl;
string ltrim(string s)        //OK
{
   while(s[0] == ' '){
      s = removeAt(s, 0);
   }

   return s;
}

//Prototipo: string rtrim(string s);
//Descripci�n: Recortar los espacios en blanco a la derecha de s.
//Par�metro:
//    string s - Cadena que podr�a tener espacios a la derecha.
//Retorna: string - Una cadena id�ntica a s sin espacios en blanco a la derecha.
//Ejemplo de uso:
//    string s = "Esto es una prueba ";
//    string r = rtrim(s);
//    muestra: [Esto es una prueba]
//    cout << "[" << r << "]" << endl;
//    s = "Esto es una prueba";
//    r = rtrim(s);
//    muestra: [Esto es una prueba]
//    cout << "[" << r << "]" << endl;
//    s = " Esto es una prueba  ";
//    r = rtrim(s);
//    muestra: [ Esto es una prueba]
//    cout << "[" << r << "]" << endl;
//    s = " Esto es una prueba ";
//    r = rtrim(ltrim(s));
//    muestra: [Esto es una prueba]
//    cout << "[" << r << "]" << endl;
string rtrim(string s)        //OK
{
   int tam = length(s);

   while(s[tam-1] == ' '){
      s = removeAt(s, tam-1);
      tam--;//importante porque al sacar un elemto la poscion del ultimo elemto cambia
   }

   return s;

}

//Prototipo: string trim(string s);
//Descripci�n: Recortar los espacios en blanco ubicados a izquierda y derecha de s.
//Par�metro:
//    string s - Cadena que podr�a contener espacios en los extremos.
//Retorna: string - Una cadena id�ntica a s sin espacios en los extremos.
//Ejemplo de uso:
//    string s = " Esto es una prueba ";
//    string r = trim(s);
//    muestra: [Esto es una prueba]
//    cout << "[" << r << "]" << endl;
//    s = "Esto es una prueba";
//    r = rtrim(s);
//    muestra: [Esto es una prueba]
//    cout << "[" << r << "]" << endl;
string trim(string s)      //OK
{
   s = ltrim(s);
   s = rtrim(s);

   return s;
}

//Prototipo: string replicate(char c,int n);
//Descripci�n: Generar una cadena de caracteres compuesta por n caracteres c.
//Par�metros:
//    int n - Cantidad de caracteres que tendr� la cadena generada.
//    char c - Car�cter que se replicar� n veces para generar la cadena.
//Retorna: string - Una cadena compuesta por n caracteres c.
//Ejemplo de uso:
//    int n = 5;
//    char c = 'X';
//    string r = replicate(c,n);
//    cout << "[" << r << "]" << endl;  // muestra: [XXXXX]
//    c = ' ';
//    r = replicate(c,n);
//    cout << "[" << r << "]" << endl; // muestra: [ ]
string replicate(char c,int n)         //OK
{
   string cadena="";

   for(int i=0 ; i<n ; i++){
      cadena += c;
   }

   return cadena;
}

//Prototipo: string spaces(int n);
//Descripci�n: Genera una cadena de caracteres compuesta por n caracteres ' '.
//Par�metro:
//    int n � Longitud de la cadena que se generar�.
//Retorna: string - Una cadena compuesta por n caracteres ' '.
//Ejemplo de uso:
//    int n = 5;
//    string r = spaces(n);
//    muestra: [ ] (cinco espacios)
//    cout << "[" << r << "]" << endl;
string spaces(int n)       //OK
{
   return replicate(' ',n);
}

//Prototipo: string lpad(string s,int n,char c);
//Descripci�n: Retorna una cadena id�ntica a s, con longitud n completando, si fuese necesario, con caracteres c a la izquierda hasta llegar a la longitud requerida.
//Par�metros:
//    int n - Longitud final que tendr� la cadena.
//    char c - Car�cter con que se completar� a s si fuera necesario.
//Retorna: string - Una cadena de longitud n compuesta por n-length(s) carac-teres c seguidos de la cadena s.
//Ejemplo de uso:
//    string s = "Hola";
//    int n = 10;
//    char c = 'X';
//    string r = lpad(s,n,c);
//    cout << "[" << r << "]" << endl; // muestra: [XXXXXXHola]
string lpad(string s,int n,char c)        //--->
{
   string cadena="";
   int agregar = n-length(s);

   cadena = replicate(c, agregar);
   cadena += s;

   return cadena;
}

//Prototipo: string rpad(string s,int n,char c);
//Descripci�n: Idem lpad pero, de ser necesario, agrega caracteres c a la derecha.
//Par�metros:
//    int n - Longitud final que tendr� la cadena retornada.
//    char c - Car�cter con que se debe completar� la cadena.
//Retorna: string - Una cadena de longitud n compuesta por el contenido de s se-guida de n-length(s) caracteres c.
//Ejemplo de uso:
//    string s = "Hola";
//    int n = 10;
//    char c = 'X';
//    string r = rpad(s,n,c);
//    cout << "[" << r << "]" << endl; // muestra: [HolaXXXXXX]
string rpad(string s,int n,char c)        //OK
{
   string cadena=s;
   int agregar = n-length(s);

   cadena += replicate(c, agregar);

   return cadena;
}

//Prototipo: string cpad(string s,int n,char c);
//Descripci�n: Idem rpad pero distribuye los caracteres c a izquierda y derecha.
//Par�metros:
//    int n - Longitud final que tendr� la cadena.
//    char c - Car�cter con que se completar� si fuerea necesario.
//Retorna: string - Una cadena de longitud n compuesta por s y caracteres c distribuidos a la izquierda y a la derecha de modo tal que su longitud final sea n.
//Ejemplo de uso:
//    string s = "Hola";
//    int n = 10;
//    char c = 'X';
//    string r = cpad(s,n,c);
//    cout << "[" << r << "]" << endl; // muestra: [XXXHolaXXX]
string cpad(string s,int n,char c)        //--->
{
   int cantAgregar = n - length(s);
   int tamMitades = cantAgregar/2;

   s = lpad(s, tamMitades+length(s), c);
   s = rpad(s, n, c);

   return s;
}

//Prototipo: bool isDigit(char c);
//Descripci�n: Determinar si el valor de c corresponde o no a un d�gito num�rico.
//Par�metro: char c - Car�cter a determinar si representa a un d�gito num�rico.
//Retorna: bool - true si c es '0', '1', '2', ..., '9', false en cualquier otro caso.
//Ejemplo de uso:
//    char c = '9';
//    if( isDigit(c) ) {
//       cout << c << " es digito" << endl; // SALIDA
//    }
//    c = 'A';
//    if( !isDigit(c) ) {
//       cout << c << " NO es digito" << endl; // SALIDA
//    }
bool isDigit(char c)       //OK
{
   bool bandera = (c>='0'&& c<='9')?true:false;

   return bandera;
}

//Prototipo: bool isLetter(char c);
//Descripci�n: Determina si el valor de c corresponde o no a una letra.
//Par�metro: char c - Car�cter a determinar si representa a una letra.
//Retorna: bool - true si c es 'A', 'B', 'C', ..., 'Z' o 'a', 'b', 'c', ..., 'z'. Si no retorna false.
//Ejemplo de uso:
//    char c = 'X';
//    if( isLetter(c) ) {
//       cout << c << " es letra" << endl; // SALIDA
//    }
//    c = '9';
//    if( !isLetter(c) ) {
//       cout << c << " NO es letra" << endl; // SALIDA
//    }
bool isLetter(char c)         //OK
{
   return ((c>='A'&& c<='Z')||(c>='a'&& c<='z'))?true:false;
}

//Prototipo: bool isUpperCase(char c);
//Descripci�n: Determinar si el valor de c corresponde a una letra may�scula.
//Par�metro: char c - Car�cter para determinar si es una letra may�scula.
//Retorna: bool - true si c es 'A', 'B', 'C', ..., 'Z', false en cualquier otro caso.
//Ejemplo de uso:
//    char c = 'X';
//    if( isUpperCase(c) ) {
//       cout << c << " es letra mayuscula" << endl; // SALIDA
//    }
//    c = 'x';
//    if( !isUpperCase(c) ) {
//       cout << c << " NO es mayuscula" << endl; // SALIDA
//    }
bool isUpperCase(char c)         //OK
{
   return (c>='A'&& c<='Z')?true:false;
}

//Prototipo: bool isLowerCase(char c);
//Descripci�n: Determina si el valor de c corresponde a una letra min�scula.
//Par�metro: char c - Car�cter a debe determinar si contiene una letra min�scula.
//Retorna: bool - true si c es 'a', 'b', 'c', ..., 'z', false en cualquier otro caso.
//Ejemplo de uso:
//    char c = 'a';
//    if( isLowerCase(c) ) {
//       cout << c << " es letra minuscula" << endl; // SALIDA
//    }
//    c = 'A';
//    if( !isLowerCase(c) ) {
//       cout << c << " NO es minuscula" << endl; // SALIDA
//    }
bool isLowerCase(char c)         //OK
{
   return (c>='a'&& c<='z')?true:false;
}

//Prototipo: char toUpperCase(char c);
//Descripci�n: Convertir el valor de c a may�scula.
//Par�metro:
//    char c - El car�cter cuyo valor se debe convertir a may�scula.
//Retorna: char � Si c es una letra min�scula retorna su may�scula, en cualquier otro caso retorna el mismo valor de c.
//Ejemplo de uso:
//    char c = 'a';
//    char r = toUpperCase(c);
//    cout << r << endl; // Salida: A (convierte a mayuscula)
//    c = 'B';
//    r = toUpperCase(c);
//    cout << r << endl; // Salida: B (ya era mayuscula)
//    c = '9'; r = toUpperCase(c);
//    cout << r << endl; // Salida: 9 (no es una letra)
char toUpperCase(char c)         //OK
{
   if(isLowerCase(c))
      c = c-('a'-'A');

   return c;
}

//Prototipo: char toLowerCase(char c);
//Descripci�n: Convierte el valor de c a may�scula.
//Par�metro:
//    char c - El car�cter cuyo valor se debe convertir a min�scula.
//Retorna: char � Si c es un una letra may�scula retorna su min�scula, en cualquier otro caso retorna el mismo car�cter c.
//Ejemplo de uso:
//    char c = 'A';
//    char r = toLowerCase(c);
//    cout << r << endl; // Salida: a (convierte a minuscula)
//    c = 'b'; r = toLowerCase(c);
//    cout << r << endl; // Salida: b (ya era minuscula)
//    c = '9';
//    r = toLowerCase(c);
//    cout << r << endl; // Salida: 9 (no es una letra)
char toLowerCase(char c)         //OK
{
   if(isUpperCase(c))
      c = c+('a'-'A');

   return c;

}

bool endsWith(string name, string terminacion)
{
   string aux = substring(name, length(name)-length(terminacion));
   return (aux == terminacion);
}

#endif

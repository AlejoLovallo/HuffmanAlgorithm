#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

// --[ Funciones Basicas ]--

// --[ Funciones Basicas ]--

//Prototipo: int length(string s);
//Descripción: Cuenta la cantidad de caracteres que componen la cadena s.
//Parámetro:
//    string s – Cadena cuya longitud debemos averiguar.
//Retorna: int – Cuántos caracteres contiene la cadena s.
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
//Descripción: Cuenta la cantidad de veces que aparece el carácter c dentro de s.
//Parámetros:
//   string s – Cadena que contiene al carácter c.
//   char c – Carácter cuya cantidad de ocurrencias queremos averiguar.
//Retorna: int – Cuántas veces aparece c dentro de la cadena s.
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
//Descripción: Retorna la subcadena de s comprendida entre las posiciones d (inclu-sive) y h (no inclusive).
//Parámetros:
//    string s – Cadena que contiene la subcadena que queremos obtener.
//    int d – Posición (inclusive) que indica dónde comienza la subcadena.
//    int h – Posición (no inclusive) que indica dónde finaliza la subcadena.
//Retorna: string – La subcadena de s comprendida comprendida entre las posi-ciones d (inclusive) y h (no inclusive).
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
//Descripción: Retorna la subcadena de s comprendida entre la posición d y el final de la cadena.
//Parámetros:
//    string s – Cadena que contiene la subcadena que queremos obtener.
//    int d – Posición (inclusive) que indica dónde comienza la subcadena.
//Retorna: string – La subcadena de s comprendida comprendida entre la posición d (inclusive) y el final de la cadena.
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
//Descripción: Retorna la posición que ocupa la primera ocurrencia del carácter c dentro de la cadena s, o -1 si s no contiene a c.
//Parámetros:
//    string s - Cadena que contiene al carácter c.
//    char c - Carácter cuya posición, dentro de s, queremos averiguar.
//Retorna: string – La posición que ocupa, dentro de s, la primera ocurrencia del carácter c, o un valor negativo si s no contiene a c.
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
//Descripción: Retorna la posición que ocupa la primera ocurrencia de un carácter c dentro de la cadena s, descartando los primeros offeset caracteres (desplaza-miento inicial).
//Parámetros:
//    string s - Cadena que contiene al carácter c.
//    char c - Carácter cuya posición, dentro de s, queremos averiguar.
//    int offset - Posición de desplazamiento desde donde debemos buscar.
//Retorna: string – La posición que ocupa, dentro de s, la primera ocurrencia del carácter c, considerando desde offset.
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
//Descripción: Retorna la posición de la última ocurrencia del carácter c dentro de s.
//Parámetros:
//    string s - Cadena que contiene al carácter c.
//    char c - Carácter cuya última posición, dentro de s, queremos averiguar.
//Retorna: string – La posición que ocupa, dentro de s, la última ocurrencia del carácter c, o un valor negativo si s no contiene a c.
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
//Descripción: Retorna la posición de la n-ésima ocurrencia de c dentro de s.
//Parámetros:
//    string s - Cadena que contiene al carácter c.
//    char c - Carácter cuya posición se debe determinar. Se asume que s contiene a c, al menos, n veces.
//    int n - Número de ocurrencia de c, contando desde 1.
//Retorna: int - La posición de la n-ésima ocurrencia de c dentro de s.
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
//Descripción: Retorna el valor numérico del carácter c (que debe ser numérico).
//Parámetros: char c - Carácter cuyo valor será: '0', '1', … o '9'.
//Retorna: int - El valor numérico del carácter c.
//Ejemplo de uso:
//    char c = '2';
//    int n = charToInt(c);
//    cout << n << endl; // muestra: 2
int charToInt(char ch)     //OK
{
   return (int)(ch - '0');
}


//Prototipo: char intToChar(int i);
//Descripción: Retorna el carácter que representa al valor de i, que debe estar com-prendido entre 0 y 9. Es la función inversa de charToInt.
//Parámetro: int i - Valor numérico entero comprendido entre 0 y 9.
//Retorna: char - El carácter que representa al valor de i.
//Ejemplo de uso:
//    int i = 2;
//    char c = intToChar(i);
//    cout << c << endl; // muestra: 2
char intToChar(int i)      //OK
{
   return (char)i + '0';
}


//Prototipo: int getDigit(int n,int i);
//Descripción: Retorna el i-ésimo dígito del valor de n.
//Parámetros:
//    int n – Número entero de 1 o más dígitos desde donde que se quiere obtener el dígito que se ubica en la i-ésima posición.
//    int i - Posición, contando desde 0 (cero) y de derecha a izquierda, del dí-gito de n que queremos obtener.
//Retorna: int - El dígito que se ubica en la i-ésima posición de n.
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
//Descripción: Retorna la cantidad de dígitos que contiene el valor de n.
//Parámetro:
//    int n - Valor numérico cuya cantidad de dígitos queremos averiguar.
//Retorna: int - La cantidad de dígitos que tiene el valor de n.
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
//Descripción: Retorna una cadena de caracteres representando el valor i.
//Parámetro: int i - Valor numérico entero que se va a representar como string.
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
//Descripción: Retorna el valor numérico de la cadena s, que debe contener sólo dígitos numéricos. Esta función es la función inversa de intToString.
//Parámetro: string s - Cadena de caracteres que sólo contiene dígitos numéricos.
//Retorna: int - El valor numérico que está representado en la cadena s.
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
//Descripción: Retorna el valoro numérico representado en la cadena s, considerando que dicho valor está expresado en la base numérica b.
//Parámetros:
//    string s - Cadena que representa un valor numérico entero en base b.
//    int b - Base numérica del valor que representado en la cadena s.
//Retorna: int - El número numérico representado en la cadena s.
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
//Descripción: Retorna una cadena cuyo único carácter es c.
//Parámetro:
//       char c – Carácter que será el contenido de la cadena.
//Retorna: string - Una cadena de longitud 1 cuyo único carácter será c.
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
//Descripción: Retorna el único carácter que contiene la cadena s. Esta es la función inversa de charToString.
//Parámetro:
//       string s - Cadena de caracteres de longitud 1.
//Retorna: char - El único carácter que contiene la cadena s.
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
//Descripción: Retorna la misma cadena que recibe. Se trata de una función trivial que usaremos más adelante, dentro de este mismo capítulo.
//Parámetro:
//       string s - Cadena de caracteres.
//Retorna: string – La misma cadena que recibe como parámetro.
//Ejemplo de uso:
//       string s = stringToString("Hola");
//       cout << s << endl; // muestra: Hola
string stringToString(string s)        //OK
{
   return s;
}

//Prototipo: string doubleToString(double d);
//Descripción: Retorna una cadena representando el valor contenido en d.
//Parámetro: double d - Valor que se representará como cadena.
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
//Descripción: Retorna el valor numérico representado en la cadena s.
//Parámetro:
//       string s - Cadena que contiene un valor compatible con double.
//Retorna: double – El valor que está representado en la cadena s.
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
//Descripción: Retorna true o false según s sea o no la cadena vacía.
//Parámetro:
//    string s - Una cadena de caracteres.
//Retorna: bool – Retorna true si s es la cadena vacía o false si no lo es.
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
//Descripción: Determinar si la cadena s contiene al carácter c.
//Parámetros:
//    string s - Cadena que podría contener al carácter c.
//    char c - Carácter cuyo valor podría estar contenido en s.
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
//Descripción: Reemplaza en s todas las ocurrencias de oldChar por newChar.
//Parámetros:
//    string s - Cadena sobre la cual se reemplazarán los caracteres.
//    char oldChar - Carácter que va a ser reemplazado por newChar.
//    char newChar - Valor que reemplazará todas las ocurrencias de oldChar.
//Retorna: string - La cadena s con caracteres oldChar donde antes tenía oldChar.
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
//Descripción: Insertar el carácter c en la posición pos de la cadena s.
//Parámetros:
//    string s - Cadena de caracteres donde se insertará un carácter.
//    int pos - Posición de s se va a insertar al carácter c.
//    char c - Carácter que se insertará en s, en la posición pos.
//Retorna: string - Una cadena cuya longitud será length(s)+1, idéntica a s pero con el valor de c insertado en la posición pos.
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
//Descripción: Remover de s el carácter ubicado en la posición pos.
//Parámetros:
//    string s - Cadena de caracteres sobre la cual se removerá un carácter.
//    int pos - Posición del carácter que se removerá.
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

//Función ltrim
//Prototipo: string ltrim(string s);
//Descripción: Recorta los espacios en blanco que se encuentren a la izquierda de s.
//Parámetro:
//    string s - Cadena que podría tener espacios a la izquierda.
//Retorna: string - Una cadena idéntica a s pero sin espacios a la izquierda.
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
//Descripción: Recortar los espacios en blanco a la derecha de s.
//Parámetro:
//    string s - Cadena que podría tener espacios a la derecha.
//Retorna: string - Una cadena idéntica a s sin espacios en blanco a la derecha.
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
//Descripción: Recortar los espacios en blanco ubicados a izquierda y derecha de s.
//Parámetro:
//    string s - Cadena que podría contener espacios en los extremos.
//Retorna: string - Una cadena idéntica a s sin espacios en los extremos.
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
//Descripción: Generar una cadena de caracteres compuesta por n caracteres c.
//Parámetros:
//    int n - Cantidad de caracteres que tendrá la cadena generada.
//    char c - Carácter que se replicará n veces para generar la cadena.
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
//Descripción: Genera una cadena de caracteres compuesta por n caracteres ' '.
//Parámetro:
//    int n – Longitud de la cadena que se generará.
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
//Descripción: Retorna una cadena idéntica a s, con longitud n completando, si fuese necesario, con caracteres c a la izquierda hasta llegar a la longitud requerida.
//Parámetros:
//    int n - Longitud final que tendrá la cadena.
//    char c - Carácter con que se completará a s si fuera necesario.
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
//Descripción: Idem lpad pero, de ser necesario, agrega caracteres c a la derecha.
//Parámetros:
//    int n - Longitud final que tendrá la cadena retornada.
//    char c - Carácter con que se debe completará la cadena.
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
//Descripción: Idem rpad pero distribuye los caracteres c a izquierda y derecha.
//Parámetros:
//    int n - Longitud final que tendrá la cadena.
//    char c - Carácter con que se completará si fuerea necesario.
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
//Descripción: Determinar si el valor de c corresponde o no a un dígito numérico.
//Parámetro: char c - Carácter a determinar si representa a un dígito numérico.
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
//Descripción: Determina si el valor de c corresponde o no a una letra.
//Parámetro: char c - Carácter a determinar si representa a una letra.
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
//Descripción: Determinar si el valor de c corresponde a una letra mayúscula.
//Parámetro: char c - Carácter para determinar si es una letra mayúscula.
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
//Descripción: Determina si el valor de c corresponde a una letra minúscula.
//Parámetro: char c - Carácter a debe determinar si contiene una letra minúscula.
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
//Descripción: Convertir el valor de c a mayúscula.
//Parámetro:
//    char c - El carácter cuyo valor se debe convertir a mayúscula.
//Retorna: char – Si c es una letra minúscula retorna su mayúscula, en cualquier otro caso retorna el mismo valor de c.
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
//Descripción: Convierte el valor de c a mayúscula.
//Parámetro:
//    char c - El carácter cuyo valor se debe convertir a minúscula.
//Retorna: char – Si c es un una letra mayúscula retorna su minúscula, en cualquier otro caso retorna el mismo carácter c.
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

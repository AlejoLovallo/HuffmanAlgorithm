//============================================================================
// Name        : Compresi�n de archivos mediante el algoritmo de Huffman
// Author      : Juan Guerre�o
// Version     : 2.8
// Copyright   : Your copyright notice
// Description : Comprimir y Descomprimir
//============================================================================

#ifndef _MAIN
#define _MAIN

#include <iostream>
#include "biblioteca/tads/Arr.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/BitWriter.hpp"
#include "biblioteca/tads/BitReader.hpp"
#include "biblioteca/tads/HuffmanTree.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"

using namespace std;


void eliminarTerminacionHuff(string& fName)
{
   fName = substring(fName, 0, length(fName)-4);
}

void inicializarTabla(HuffmaneTable tabla[])
{
   for( int i = 0; i<256; i++ )
   {
      tabla[i].cod = "";
      tabla[i].n = 0;
   }
}

void contarOcurrencias(string fName, HuffmaneTable tabla[])
{
   //Abro el archivo
   FILE* archivo = fopen(fName.c_str(),"r+b");

   //Inicializo la tabla
   inicializarTabla(tabla);

   //Recorro el archivo
   unsigned char c = read<unsigned char>(archivo);
   while( !feof(archivo) )
   {
      tabla[(int)c].n++;
      c = read<unsigned char>(archivo);
   }

   //Cierro el archivo
   fclose(archivo);
}

int cmpChar(HuffmanTreeInfo x, HuffmanTreeInfo y)
{
   return x.c-y.c;
}

int cmpHuffmanTreeInfo(HuffmanTreeInfo x, HuffmanTreeInfo y)
{
   unsigned int val = x.n>y.n? 1 : -1;

   if( x.n==y.n )
   {
      val = cmpChar(x,y);
   }

   return val;
}

void completarListaEnlazada(List<HuffmanTreeInfo>& lista, HuffmaneTable tabla[])
{
   for( unsigned int i = 0; i<256; i++ )
   {
      HuffmaneTable valores = tabla[i];
      //Pregunto si hay por lo menos una ocurrecia
      if( valores.n>0 )
      {
         HuffmanTreeInfo x = {i, valores.n, NULL, NULL};
         listOrderedInsert<HuffmanTreeInfo>(lista,x,cmpHuffmanTreeInfo);
      }
   }
}

HuffmanTreeInfo* convertirListaEnArbol(List<HuffmanTreeInfo>& lista)
{
   int i = 1;

   HuffmanTreeInfo* e1 = listRemoveFirst<HuffmanTreeInfo>(lista);
   while( listSize<HuffmanTreeInfo>(lista)>0 )
   {
      HuffmanTreeInfo* e2 = listRemoveFirst<HuffmanTreeInfo>(lista);

      HuffmanTreeInfo* padre = new HuffmanTreeInfo();

      // hijos
      padre->left = e2;
      padre->right = e1;

      // cant de ocurrencias
      padre->n = e1->n+e2->n;

      // caracter ficticio
      padre->c = 255+i;
      i++;

      //Insercion ordenada
      listOrderedInsert<HuffmanTreeInfo>(lista,*padre,cmpHuffmanTreeInfo);

      e1 = listRemoveFirst<HuffmanTreeInfo>(lista);
   }

   return e1;
}

void completarCodigosEnTabla(HuffmanTreeInfo* raiz, HuffmaneTable tabla[])
{
   //Genero el arbol y lo recorro
   HuffmanTree ht = huffmanTree(raiz);

   string s="";
   HuffmanTreeInfo* aux = huffmanTreeNext(ht,s);
   while(aux != NULL)
   {
      tabla[aux->c].cod = s;
      aux = huffmanTreeNext(ht,s);
   }
}

unsigned char obtenerCantHojas(HuffmaneTable tabla[])
{
   unsigned char cantHojas = 0;

   for( int i = 0; i<256; i++ )
   {
      if( tabla[i].n>0 )
      {
         cantHojas++;
      }
   }

   return cantHojas;
}

unsigned int cantCaracteresModificados(HuffmaneTable tabla[])
{
   unsigned char cantCaracteres = 0;

   for( int i = 0; i<256; i++ )
   {
      cantCaracteres += tabla[i].n;
   }

   return cantCaracteres;
}

void generarArchivoComprimido(string fName, HuffmaneTable tabla[])
{
   //Abro el archivo
   FILE* archivo = fopen(fName.c_str(),"r+b");
   //Agrego la terminacion al nombre
   fName += ".huf";

   //Creo el Archivo comprimido
   FILE* comprimido = fopen(fName.c_str(),"w+b");
   BitWriter x = bitWriterCreate(comprimido);

   //Cuantas hojas hay
   unsigned char cantHojas = obtenerCantHojas(tabla);
   write<unsigned char>(comprimido,cantHojas);

   //Imprimo registros de la tabla
   for( int i = 0; i<256; i++ )
   {
      if( tabla[i].n>0 )
      {
         write<unsigned char>(comprimido,(unsigned char)i);

         //Grabo Cant de digitos del codigo
         unsigned int tam = length(tabla[i].cod);
         write<unsigned char>(comprimido,intToChar(tam));

         //Imprimo codigo
         for( unsigned int j = 0; j<tam; j++ )
            write<char>(comprimido,(char)tabla[i].cod[j]);
      }
   }

   //Obtengo tamanio del fichero
   unsigned int tamFichero = (unsigned int)fileSize<unsigned char>(archivo);
   write<unsigned int>(comprimido,tamFichero);

   //Recorro fName
   unsigned char c = read<unsigned char>(archivo);
   while( !feof(archivo) )
   {
      HuffmaneTable valores = tabla[(unsigned int)c];
      string codigo = valores.cod;

      for( int i = 0; codigo[i]!='\0'; i++ )
      {
         bitWriterWrite(x, charToInt((char)codigo[i]));
      }
      c = read<unsigned char>(archivo);
   }

   bitWriterFlush(x);

   //Cierro el archivo
   fclose(archivo);
   fclose(comprimido);
}

void comprimir(string fName)
{
   // paso 1
   HuffmaneTable tabla[256];
   cout<<"Contando Ocurencias..." <<endl;
   contarOcurrencias(fName,tabla);
   cout<<"Ya se han contado las Ocurencias" <<endl<<endl;

   // paso 2
   cout<<"Creando lista enlazada..." <<endl;
   List<HuffmanTreeInfo> lista = list<HuffmanTreeInfo>();
   completarListaEnlazada(lista,tabla);
   cout<<"Ya se ha creado la lista" <<endl<<endl;

   // paso 3
   cout<<"Convirtiendo Lista en Arbol..." <<endl;
   HuffmanTreeInfo* raiz = convertirListaEnArbol(lista);
   cout<<"Ya se ha convertido la lista en Arbol" <<endl<<endl;


   // Recorro el arbol para obtener los codigos y los cargo
   // en el array de contadores, en el campo code
   cout<<"Agregando codigos en la tabla..." <<endl;
   completarCodigosEnTabla(raiz,tabla);
   cout<<"Ya se ha completado la tabla con los codigos" <<endl<<endl;

   // Grabo el archivo comprimido
   cout<<"Comprimiendo..." <<endl;
   generarArchivoComprimido(fName,tabla);
   cout<<"Proceso Terminado" <<endl<<endl;
}

HuffmanTreeInfo* crearRama(string code, HuffmanTreeInfo* raiz, unsigned char car)
{
   if( raiz==NULL )
   {
      raiz = new HuffmanTreeInfo();
      raiz->left = NULL;
      raiz->right = NULL;
      raiz->c = 256;
   }
   HuffmanTreeInfo *aux = raiz;
   for( int i = 0; i<length(code); i++ )
   {
      if( code[i]=='1' )
      {
         if( aux->right==NULL )
         {
            aux->right = new HuffmanTreeInfo();
            aux->right->left = NULL;
            aux->right->right = NULL;
            aux->right->c = 256;
         }
         aux = aux->right;
      }
      else
      {
         if( aux->left==NULL )
         {
            aux->left = new HuffmanTreeInfo();
            aux->left->left = NULL;
            aux->left->right = NULL;
            aux->left->c = 256;
         }
         aux = aux->left;
      }
   }
   aux->c = car;
   return raiz;
}

void descomprimir(string fName)
{
   //inicio un timer
   unsigned int tick1 = clock();

   cout <<"Descomprimiendo encabezado..."<<endl;

   //Archivo comprimido
   FILE* f = fopen(fName.c_str(),"r+b");
   eliminarTerminacionHuff(fName);
   FILE* fnew = fopen(fName.c_str(),"w+b");

   unsigned int cant_hojas = read<unsigned int>(f);
   string aux = "";

   HuffmanTreeInfo* raiz = NULL;

   for( unsigned int i = 0; i<cant_hojas; i++ )
   {

      //Leo la letra o el espacio
      unsigned char letra = read<unsigned char>(f);

      //Leo la cantidad de digitos correspondientes a la letra
      unsigned char tam = read<unsigned char>(f);

      //Leo el codigo
      aux = "";
      for( int j = 0; j<charToInt(tam); j++ )
      {
         aux += read<unsigned char>(f);
      }

      raiz = crearRama(aux,raiz,letra);
   }

   //unsigned int tamArchiv = fileSize<unsigned char>(f);

   unsigned int tamFichero = read<unsigned int>(f);
   cout <<"Descomprecion del encabezado terminada..."<<endl;

   cout <<"Descomprimiendo archivo..."<<endl;
   BitReader br = bitReaderCreate(f);
   HuffmanTreeInfo* x = raiz;
   bool interruptor = false;

   //cout<<"\t" <<"Se han procesado " <<(unsigned int)fileSize<unsigned char>(fnew);
   //      cout <<"bytes" <<endl;

   unsigned int bit = bitReaderRead(br);
   while( !feof(f) && !interruptor )
   {
      if( bit==0 )
         x = x->left;

      if( bit==1 )
         x = x->right;


      if( (x->c) != 256 )
      {
         unsigned char y = x->c;
         write<unsigned char>(fnew,y);
         x = raiz;

         cout<<"\t"<<"Se ha procesado el "<<((100*(unsigned int)fileSize<unsigned char>(fnew))/tamFichero);
         cout<<"%"<<endl;

//        cout<<"\t" <<"Se han procesado " <<(unsigned int)fileSize<unsigned char>(fnew);
//                  cout <<"bytes" <<endl;
      }

      if( (unsigned int)fileSize<unsigned char>(fnew) == tamFichero )
      {
         cout << "En algun momento llego aca ?? " << endl;
         interruptor = true;
      }
      else
      {
         bit = bitReaderRead(br);
      }

   }
   cout <<"Descomprecion terminada"<<endl;

   //obtengo tiempo final
   unsigned int tick2 = clock();
   unsigned int elapsed = tick2 - tick1;

   double elapsed_time = (double)elapsed/CLOCKS_PER_SEC;

   cout<<"La Descomprecion tardo: "<<elapsed_time<<" segundos"<<endl;

   fclose(f);
   
}

// PROGRAMA PRINCIPAL
int main(int argc, char** argv)
{
   // argumento recibido en linea de comando
   string fName = argv[1];

   cout<<"Procesando..." <<endl<<endl;
   if( !endsWith(fName,".huf") )
   {
      comprimir(fName);
   }
   else
   {
      descomprimir(fName);
   }

   return 0;
}

#endif

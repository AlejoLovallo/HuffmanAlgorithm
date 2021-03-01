#ifndef _TBITWRITER_T_
#define _TBITWRITER_T_

#include <iostream>
#include "../funciones/files.hpp"

using namespace std;

struct BitWriter
{
   FILE* f;
   unsigned char b;
   int cant;
};

//Prototipo: BitWriter bitWriterCreate(FILE* f);
//Descripción: Crea e inicializa una variable tipo BitWriter.
//Parámetros: FILE* f – Archivo donde se grabarán los bit.
//Retorna: BitWriter.
//Ejemplo de uso:
//    FILE* f = fopen("arch.bin","w+b");
//    BitWriter bw = bitWriterCreate(f);
BitWriter bitWriterCreate(FILE* f){
   BitWriter bits;

   bits.f = f;
   bits.b = 0;
   bits.cant = 0;

   return bits;
}

//Prototipo: void bitWriterWrite(BitWriter bw,int bit);
//Descripción: Graba un bit en el archivo.
//Parámetros:
//    BitWriter br – Variable del TAD.
//    int bit – 1 o 0 que se grabará en el archivo.
//Retorna: void.
//Ejemplo de uso:
//      FILE* f = fopen("arch.bin","w+b");
//      BitWriter bw = bitWriterCreate(f);
//      bitWriterWrite(bw,0);
//      bitWriterWrite(bw,1);
//      bitWriterWrite(bw,0);
//      bitWriterWrite(bw,0);
//      bitWriterWrite(bw,0);
//      bitWriterWrite(bw,0);
//      bitWriterWrite(bw,0);
//      bitWriterWrite(bw,1);
//      fclose(f);
void bitWriterWrite(BitWriter& bw, int bit)
{
   bw.b = (bw.b<<1) | (unsigned char)bit;
   bw.cant = bw.cant + 1;

   if( bw.cant==8 )
   {
      write<char>(bw.f,bw.b);
      bw.cant = 0;
   }
}

//Prototipo: void bitWriterFlush(BitWriter bw);
//Descripción: Indica que ya no se grabarán más bit. En caso de que la cantidad de bit
//que grabamos no llegue a ser múltiplo de 8, completa con ceros a la derecha y graba.
//Parámetros: BitWriter br – Variable del TAD.
//Retorna: void.
//Ejemplo de uso:
//    FILE* f = fopen("arch.bin","w+b");
//    BitWriter bw = bitWriterCreate(f);
//    bitWriterWrite(bw,0);
//    bitWriterWrite(bw,1);
//    bitWriterFlush(bw);
//    fclose(f);
void bitWriterFlush(BitWriter bw)
{
   while( bw.cant != 0 )
   {
      bitWriterWrite(bw,0);
   }
}

#endif

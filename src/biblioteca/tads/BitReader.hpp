#ifndef _TBITREADER_T_
#define _TBITREADER_T_

#include <iostream>
#include "../funciones/files.hpp"

using namespace std;

struct BitReader
{
   FILE* f;
   unsigned char b;
   int pos;
};

//Prototipo: BitReader bitReaderCreate(FILE* f);
//Descripci�n: Crea e inicializa una variable tipo BitReader.
//Par�metro: FILE* f � Archivo desde el cual se leer�n los bit.
//Retorna: BitReader.
//Ejemplo de uso:
//    FILE* f = fopen("arch.bin","r+b");
//    BitReader br = bitReaderCreate(f);
BitReader bitReaderCreate(FILE* f)
{
   BitReader bits = { f, 0, 0 };
   return bits;
}

//Prototipo: int bitReaderRead(BitReader br);
//Descripci�n: Lee un bit desde el archivo.
//Par�metro: BitReader bw � Variable del TAD.
//Retorna: int � Bit (1 o 0) que le�do desde el archivo.
//Ejemplo de uso:
//    FILE* f = fopen("arch.bin","r+b");
//    BitReader br = bitReaderCreate(f);
//    int bit = bitReaderRead(br);
//    while( !feof(f) )
//    {
//       cout << bit << endl;
//       bit = bitReaderRead(br);
//    }
//    fclose(f);
int bitReaderRead(BitReader& br)
{
   if(br.pos == 0)
   {
      br.b = read<char>(br.f);
      br.pos = 8;
   }

   br.pos--;

   return (br.b>>br.pos)&1;
}


#endif

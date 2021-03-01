#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template<typename T> T read(FILE* f)
{
   T buff;
   fread(&buff, sizeof(T), 1, f);
   return buff;
}

template<typename T> void write(FILE* f, T v)
{
   fwrite(&v, sizeof(T), 1, f);
}

template<typename T> void seek(FILE* f, int n)
{
   fseek(f,n*sizeof(T),SEEK_SET); 
}

template<typename T>
long fileSize(FILE* f)
{
   // tomo la posicion actual
   long curr=ftell(f);
   // muevo el puntero al final del archivo
   
	fseek(f,0,SEEK_END);  // SEEK_END hace referencia al final del archivo
   
	// tomo la posicion actual (ubicado al final)
   long ultimo=ftell(f);
   
   // vuelvo a donde estaba al principio
 	fseek(f,curr,SEEK_SET);

   return ultimo/sizeof(T);
}

template<typename T> long filePos(FILE* f)
{
   return ftell(f)/sizeof(T);
}

#endif

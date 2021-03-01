#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

// --[Funciones Token]--

int tokenCount(string s,char sep) // ok
{
   if(length(s)==0)
   {
      return 0;
   }
   else
   {
      return charCount(s,sep)+1;
   }
}

// pablo|juan|pedro|carlos
string getTokenAt(string s,char sep, int p)  // ok
{
   int d=(p==0)?0:indexOfN(s,sep,p)+1;
   int h=(p==tokenCount(s,sep)-1)?length(s):indexOfN(s,sep,p+1);
   return substring(s,d,h);
}

void addToken(string& s,char sep,string t) // ok
{
   if(tokenCount(s,sep)==0)
   {
      s=t;
   }
   else
   {
      s+=sep+t;
   }
}

string removeTokenAt(string& s,char sep, int p) //  ok
{
   string ret="";
   string ns="";
   int n=tokenCount(s,sep);
   for(int i=0; i<n; i++)
   {
      string tk = getTokenAt(s,sep,i);

      if( i!=p )
      {
         addToken(ns,sep,tk);
      }
      else
      {
         ret=tk;
      }
   }

   s=ns;
   return ret;
}

void setTokenAt(string& s,char sep, string t,int p) // ok
{
   string ret="";
   string ns="";
   int n=tokenCount(s,sep);
   for(int i=0; i<n; i++)
   {

      if( i!=p )
      {
         string tk = getTokenAt(s,sep,i);
         addToken(ns,sep,tk);
      }
      else
      {
         addToken(ns,sep,t);
      }
   }

   s=ns;

}

int findToken(string s,char sep, string t)
{
   int n=tokenCount(s,sep);
   for(int i=0;i<n;i++)
   {
      if( t==getTokenAt(s,sep,i) )
      {
         return i;
      }
   }

   return -1;
}

// --[/Funciones Token]--


#endif

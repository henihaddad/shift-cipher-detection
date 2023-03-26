#include<iostream>
#include<cctype>
#include<string>
using namespace std;
int scoreParDecalage[26];


bool test2(string ch)
{
   bool a=false;
   int n=14;
   string motFrequenteA2Lettre[n]={"le","la","il","me","te","se","ma","si","je","on","de","un","du","ce"};
   for (int i=0;i<n;i++)
   {
      if (ch==motFrequenteA2Lettre[i]) a=true;
   }
   return a;
}
bool test4(string ch)
{
   bool a=false;
   int n=6;
   string motFrequenteA4Lettre[n]={"elle","celle","ceux","plus","onze","quel"};
   for (int i=0;i<n;i++)
   {
      if (ch==motFrequenteA4Lettre[i]) a=true;
   }
   return a;
}
bool test3(string ch)
{
   bool a=false;
   int n=5;
   string motFrequenteA3Lettre[n]={"pas","son","mon","nos","une",};
   for (int i=0;i<n;i++)
   {
      if (ch==motFrequenteA3Lettre[i]) a=true;
   }
   return a;
}
bool testTout(string mot)
{
   int l=mot.length();
   if (l==2) return test2(mot);
   else if (l==1) return (mot=="a");
   else if (l==3) return test3(mot);
   else if (l==4) return test4(mot);
   else return false;
}



string decodageParDecalageMot(string mot, int dec)
{
   for (int i=0;i<mot.length();i++)
   {
      mot[i]=tolower(mot[i]);
      mot[i]=(((mot[i]+dec-'a')%26)+26)%26+'a';
   }
   return mot;
}
string decodageParDecalageTout(string texte, int dec)
{
   for (int i=0;i<texte.length();i++)
   {
      char c=texte[i];
      if (isalpha(c))
      {
         bool isMaj=isupper(c);
         c=tolower(c);
         c=(((c+dec-'a')%26)+26)%26+'a';
         if (isMaj) c=toupper(c);
      }
      texte[i]=c;
   }
   return texte;
}
int meilleurDecalage()
{
   int max=-1,k=-1;
   for (int i=0;i<26;i++)
   {
      if (scoreParDecalage[i]>max)
      {
         max=scoreParDecalage[i];
         k=i;
      }
   }
   return k;
}
int main()
{
   for (int i=0;i<26;i++)
   scoreParDecalage[i]=0;
   string texte;
   getline(cin,texte);
   texte+=" ";
   string mot="";
   for (int i=0;i<texte.length();i++)
   {
      
      if (isalpha(texte[i]))
      {
         mot+=texte[i];
         
      }
      else 
      {
         
         for (int dec=0;dec<26;dec++)
         {
            string aTester=decodageParDecalageMot(mot,dec);
            if (testTout(aTester)) 
            {
               scoreParDecalage[dec]++;
               
            }
            
         }
         
         mot="";
      }
   }
   int meilleurDec=meilleurDecalage();
   string theBest=decodageParDecalageTout(texte, meilleurDec);
   
   
   
   cout<<theBest;
}
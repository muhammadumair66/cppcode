#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

//Function to get file names
void getFileName(ifstream &inpFile,ofstream &outpFile)
{
    string inp;
    //Input file
    cout<<endl<<"Enter the file name to read data : ";
    cin>>inp;
    inpFile.open(inp.c_str());
    if(!inpFile)
    {
        cout<<endl<<"UNABLE TO OPEN THE FILE.";
        exit(0);
   }
    //Output file
   outpFile.open("lastnameProj3Results.txt",ios::app);
   if(!outpFile)
    {
        cout<<endl<<"UNABLE TO OPEN THE FILE.";
        exit(0);
   }
}

//Function to count words in input file and write to output file
void countWords(ifstream &inpFile,ofstream &outpFile)
{
    int tot=0;
    string words;
    //Read words in file till end
    while(!inpFile.eof())
    {
       inpFile>>words;
       tot++;
       }
       outpFile<<endl<<tot<<" Number of words are in the file.";
}

//Function to count characters in file
void countChars(ifstream &inpFile,ofstream &outpFile,int array[4],string &letters,string &digit,string &punc,string &symb)
{
   int numbLetters=0,numbdigits=0,numbpunc=0,numbSymb=0;
   int i;
   string words;
    //Check all characters and count them
   inpFile.seekg(0, ios::beg);
    while(!inpFile.eof())
    {
       inpFile>>words;
       for(i=0;words[i]!='\0';i++)
       {
      
           if((words[i]>='a' && words[i]<='z') ||(words[i]>='A' && words[i]<='Z'))
           {
               letters=letters+words[i];
                   numbLetters++;
                   }
          
           if(words[i]>='0' && words[i]<='9')
           {
              digit = digit+words[i];
              numbdigits++;
               }
          
           if(words[i]=='!' || words[i]=='\?' || words[i]=='.' || words[i]=='\,' || words[i]==':'|| words[i]==';'|| words[i]==' \' '|| words[i]==' \" ')
           {
               punc=punc+words[i];
               numbpunc++;
           }
      
    if(words[i]=='@' || words[i]=='#' || words[i]=='$' || words[i]=='%' || words[i]=='&'|| words[i]=='%'|| words[i]=='&' || words[i]=='*'|| words[i]=='('|| words[i]==')'|| words[i]=='+'|| words[i]=='=' || words[i]=='/'|| words[i]=='-'|| words[i]=='<'|| words[i]=='>')
       {
           symb=symb+words[i];
           numbSymb++;
       }
              
           }
       }
    
    //Store characters in array
   array[0]=numbLetters;
   array[1]=numbdigits;
   array[2]=numbpunc;
   array[3]=numbSymb;
  
  

   }
  
//Function to print number of characters to output file
   void printCount(string letters,string digit,string punc,string symb,int array[],ofstream &outpFile)
   {
      int i,sum=0;
      for(i=0;i<4;i++)
      sum = sum + array[i];
      outpFile<<endl<<"Letters : "<<letters;
      outpFile<<endl<<"Digits : "<<digit;
      outpFile<<endl<<"Punctuation : "<<punc;
      outpFile<<endl<<"Symbols : "<<symb;
      outpFile<<endl<<"Number of Letters : "<<array[0];
      outpFile<<endl<<"Number of Digits : "<<array[1];
      outpFile<<endl<<"Number of Punctuations : "<<array[2];
      outpFile<<endl<<"Number of Symbols : "<<array[3];
      outpFile<<endl<<"% of Letters : "<<(float)(array[0]*100)/sum;
      outpFile<<endl<<"Digits : "<<(float)(array[1]*100)/sum;
      outpFile<<endl<<"Punctuation : "<<(float)(array[2]*100)/sum;
      outpFile<<endl<<"Symbols : "<<(float)(array[3]*100)/sum;
          
     
   }

int main()
{
    //Declare array to store characters
    static int array[4];
    //Declare file names
    ifstream inpFile;
    ofstream outpFile;
    string letters,digit,punc,symb;
    //Functions to call
    getFileName(inpFile,outpFile);
    countWords(inpFile,outpFile);
    countChars(inpFile,outpFile,array,letters,digit,punc,symb);
    printCount(letters,digit,punc,symb,array,outpFile);
   
    return 0;
}


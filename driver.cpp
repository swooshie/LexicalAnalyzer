/*
Group No: 55
Jhaveri Aditya Alok: 2018A7PS0209H
Rushabh Parikh: 2018A7PS1217H
Dhruv Maheshwari: 2018A7PS0170H
Lokesh Mehra: 2018A7PS0268H
*/

// We made a compiler in C++ for our small language names as Tommy024

#include <bits/stdc++.h>
#include "lexer.h"
using namespace std;
int head,tail,ln;
int ctoken;
int main(int argc, char *argv[])
{
        string lin;
        fstream inputFile,outputFile;
        outputFile.open(argv[2],ios::out);
        inputFile.open(argv[1],ios::in);
        if (inputFile.is_open()){
                while(getline(inputFile, lin)){
                        head=0,tail=0;
                        ln++;
                        do
                        {
                                letop* lexToken=getNextToken(lin);
                                if(lexToken==NULL)
                                {
                                        break;
                                }
                                else
                                {
                                        if(lexToken->token=="ERROR")
                                        {
                                                outputFile<<"Lexical Error found at "<<"line #"<<ln<<"; Lexeme: "<<lexToken->lexeme<<"\n";
                                        }
                                        else
                                        {
                                                outputFile<<"Lexeme: "<<lexToken->lexeme<<" , Token : "<<lexToken->token<<" found at line #"<<ln<<"\n";
                                        }
                                }
                        }while(head<lin.length());
                }
        }
        inputFile.close();
        outputFile.close();
        return 0;
}

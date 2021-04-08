/*
Group No: 55
Jhaveri Aditya Alok: 2018A7PS0209H
Rushabh Parikh: 2018A7PS1217H
Dhruv Maheshwari: 2018A7PS0170H
Lokesh Mehra: 2018A7PS0268H
*/

// We made a compiler in C++ for our small language names as Tommy024

#include<bits/stdc++.h>
using namespace std;

typedef struct LexerTokenPair
{
	string lexeme="";
	string token="";
	int lineno;
	int tokenno;
	
}letop;

extern int head,tail,ln;
extern int ctoken;
letop* getNextToken(string s);





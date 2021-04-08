/*
Group No: 55
Jhaveri Aditya Alok: 2018A7PS0209H
Rushabh Parikh: 2018A7PS1217H
Dhruv Maheshwari: 2018A7PS0170H
Lokesh Mehra: 2018A7PS0268H
*/

// We made a compiler in C++ for our small language names as Tommy024

#include<bits/stdc++.h>
#include "lexer.h"

vector<string> keywords={"int","float","boolean","string","method","return","while","if","else","break","continue","&&","true","false","input","output", "||"};
vector<string> tokens={"INT","FLOAT","BOOLEAN","STRING","METHOD","RETURN","WHILE","IF","ELSE","BREAK","CONTINUE","&&","TRUE","FALSE","INPUT","OUTPUT", "||"};

using namespace std;
int str_flag, comment_flag, period_flag=0, error=0;
letop* createTokenPair(char c){         
    letop* myletop = new letop();
    myletop->lexeme = "";
    myletop->lexeme.push_back(c);
    return myletop;
}

letop* createTokenPair_ID(string s){         
    letop* myletop = new letop();
    myletop->lexeme = "";
    int i=head;
    for(i=head;i<tail;i++)
    {
        myletop->lexeme.push_back(s[i]);
    }
    return myletop;
}

letop* getNextToken(string s)
{
        int state=0;
        while(tail<s.length())
        {
                if(tail>=s.length())
                {
                        break;
                }
                char c=s[tail];
                switch(state)
                {
                        case 0:
                                if(c==';')
                                {
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->token = "SEMICOLON";
                                        ltpair->lineno = ln;
                                        ctoken++;
                                        state=0;
                                        tail++;
                                        head=tail;
                                        return ltpair;
                                        break;
                                }
                                else if(c==' '|| c=='\t'){
                                        state = 0;
                                        c = s[++tail];
                                        head = tail;
                                        
                                }   
                                else if(c=='+')
                                {
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->token = "ADDITION_OP";
                                        ltpair->lineno = ln;
                                        state=0;
                                        tail++;
                                        head=tail;
                                        return ltpair;
                                        break;
                                } 
                                else if(c=='%')
                                {
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->token = "MODULO_OP";
                                        ltpair->lineno = ln;
                                        state=0;
                                        tail++;
                                        head=tail;
                                        return ltpair;
                                        break;
                                }  
                                else if(c=='/')
                                {
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->token = "DIVISION_OP";
                                        ltpair->lineno = ln;
                                        state=0;
                                        tail++;
                                        head=tail;
                                        return ltpair;
                                        break;
                                }  
                                else if(c=='(')
                                {
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->token = "OPEN_PARENTHESIS";
                                        ltpair->lineno = ln;
                                        ctoken++;
                                        state=0;
                                        tail++;
                                        head=tail;
                                        return ltpair;
                                        break;
                                }
                                else if(c==')')
                                {
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->token = "CLOSED_PARANTHESIS";
                                        ltpair->lineno = ln;
                                        ctoken++;
                                        state=0;
                                        tail++;
                                        head=tail;
                                        return ltpair;
                                        break;
                                }
                                else if(c=='-')
                                {
                                        state = 0;
                                        c = s[++tail];
                                }
                                else if(c=='@')
                                {
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->token = "START_SYM";
                                        ltpair->lineno = ln;
                                        ctoken++;
                                        state=0;
                                        tail++;
                                        head=tail;
                                        return ltpair;
                                        break;
                                }
                                else if(c=='$')
                                {
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->token = "END_SYM";
                                        ltpair->lineno = ln;
                                        ctoken++;
                                        state=0;
                                        tail++;
                                        head=tail;
                                        return ltpair;
                                        break;
                                }
                                else if(c=='[')
                                {
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->token = "OPEN_SQUARE";
                                        ltpair->lineno = ln;
                                        ctoken++;
                                        state=0;
                                        tail++;
                                        head=tail;
                                        return ltpair;
                                        break;
                                }
                                else if(c==']')
                                {
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->token = "CLOSE_SQUARE";
                                        ltpair->lineno = ln;
                                        ctoken++;
                                        state=0;
                                        tail++;
                                        head=tail;
                                        return ltpair;
                                        break;
                                }
                                else if(c==',')
                                {
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->token = "COMMA";
                                        ltpair->lineno = ln;
                                        ctoken++;
                                        state=0;
                                        tail++;
                                        head=tail;
                                        return ltpair;
                                        break;
                                }
                                
                                else if(c=='\"') 
                                {
                                        str_flag=1;
                                        state=8;
                                        c = s[++tail];
                                } 
                                
                                else if(c=='*')
                                {
                                        state=7;
                                        c=s[++tail];
                                }
                                else if(c=='<'){
                                        c = s[++tail];
                                        state = 5;
                                }
                                else if(c=='>'){
                                        c = s[++tail];
                                        state = 4;
                                }
                                else if(c=='=')
                                {
                                        state=3;
                                        c = s[++tail];
                                }
                                else if(isalpha(c)){
                                        c=s[++tail];
                                        state=2;
                                }
                                else if(c=='!')
                                {
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->token = "NOT";
                                        ltpair->lexeme = "!";
                                        ltpair->lineno = ln;
                                        ctoken++;
                                        state=0;
                                        tail++;
                                        head=tail;
                                        return ltpair;
                                        break;
                                }
                                else if(c=='0')
                                {
                                        if(tail==s.length()-1)
                                        {
                                                letop* ltpair=createTokenPair(c);

                                                ltpair->token = "INTEGER_LIT";
                                                ltpair->lineno = ln;
                                                ctoken++;
                                                state=0;
                                                tail++;
                                                head=tail;
                                                return ltpair;
                                                break;

                                        }
                                        c=s[++tail];
                                        state=9;
                                }
                                else if(c>='1' && c<='9')
                                {
                                        if(tail==s.length()-1)
                                        {
                                                letop* ltpair=createTokenPair(s[head]);
                                                for(int i =head+1;i<=tail;i++)
                                                {
                                                        ltpair->lexeme.push_back(s[i]);
                                                }
                                                ltpair->token = "INTEGER_LIT";
                                                ltpair->lineno = ln;
                                                ctoken++;
                                                state=0;
                                                tail++;
                                                head=tail;
                                                return ltpair;
                                                break;

                                        }
                                        c=s[++tail];
                                        state=10;
                                }
                                else if(c=='\n')
                                {
                                        return NULL;
                                        break;
                                }
                                break;
                        case 2:
                                
                                if(c=='_'){
                                        state=1;
                                        c=s[++tail];
                                }
                                else {   if(isalpha(c)){
                                        state=2;
                                        c=s[++tail];

                                }
                                else{
                                        letop* ltpair=createTokenPair_ID(s);
                                        auto it = find(keywords.begin(), keywords.end(), ltpair->lexeme);
                                        if(it!=keywords.end())
                                        {
                                                ltpair->token = tokens[it-keywords.begin()];
                                                ltpair->lineno = ln;
                                                state=0;
                                                
                                                head=tail;
                                                ctoken++;
                                                return ltpair; 
                                                break;
                                        }
                                        else{
                                                ltpair->token = "IDENTIFIER";
                                                ltpair->lineno = ln;
                                                state=0;
                                                
                                                head=tail;
                                                ctoken++;
                                                return ltpair;
                                                break;
                                        }
                                }
                                } break;
                        case 3:
                                if(c == '=')
                                {
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->lexeme = "==";
                                        ltpair->token = "EQ";
                                        ltpair->lineno = ln;
                                        state=0;
                                        tail++;
                                        head=tail;
                                        return ltpair;
                                        break;
                                }
                                else
                                {
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->token = "ASSIGN_OP";
                                        ltpair->lexeme = "=";
                                        ltpair->lineno = ln;
                                        state=0;
                                        
                                        head=tail;
                                        return ltpair;
                                        break;
                                } break;
                        case 4:
                                if(c=='=')
                                {
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->lexeme = ">=";
                                        ltpair->token = "GE";
                                        ltpair->lineno = ln;
                                        state=0;
                                        tail++;
                                        head=tail;
                                        return ltpair;
                                        break;
                                }
                                else
                                {
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->lexeme = ">";
                                        ltpair->token = "GT";
                                        ltpair->lineno = ln;
                                        state=0;
                                        
                                        head=tail;
                                        return ltpair;
                                        break;
                                } break;
                        case 5:
                                if(c=='=')
                                {
                                        letop* ltpair=createTokenPair(c);

                                        ltpair->lexeme = "<=";
                                        ltpair->token = "LE";
                                        ltpair->lineno = ln;
                                        state=0;
                                        tail++;
                                        head=tail;
                                        return ltpair;
                                        break;
                                }
                                else if (c=='>')
                                {
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->lexeme = "<>";
                                        ltpair->token = "NE";
                                        ltpair->lineno = ln;
                                        state=0;
                                        tail++;
                                        head=tail;
                                        return ltpair;
                                        break;
                                } else{
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->lexeme = "<";
                                        ltpair->token = "LT";
                                        ltpair->lineno = ln;
                                        state=0;
                                        
                                        head=tail;
                                        return ltpair;
                                        break;
                                } break;
                        case 7:
                                if(c=='/')
                                {
                                        tail++;
                                        while(tail<s.length()-1 && !(s[tail]=='*' && s[tail+1]=='/'))
                                        {
                                                tail++;
                                        }
                                        if(s[tail]=='*' && s[tail+1]=='/')
                                        {
                                                tail+=2;
                                                head = tail;
                                                state = 0;
                                                break;
                                        }
                                        else{
                                                cout<<"The comments section wasn't closed properly\n";
                                        }
                                }
                                else
                                {
                                        letop* ltpair=createTokenPair(c);
                                        ltpair->lexeme="*";
                                        ltpair->token = "MULTIPLICATION_OP";
                                        ltpair->lineno = ln;
                                        state=0;
                                        
                                        head=tail;
                                        return ltpair;
                                        break;
                                } break;
                               
                        case 8:
                                for(int i = tail;i<s.length();i++)
                                {
                                        if(s[i]=='\"')
                                        {
                                                letop* ltpair=createTokenPair(s[head]);
                                                for(int j=head+1;j<=i;j++){
                                                        ltpair->lexeme.push_back(s[j]);
                                                }
                                                ltpair->token = "STR_LIT";
                                                ltpair->lineno = ln;
                                                ctoken++;
                                                head = tail=i+1;
                                                
                                                state = 0;
                                                return ltpair;
                                                break;
                                        }
                                }
                                
                                if(true)
                                {
                                letop* ltpair=createTokenPair(s[head]);
                                for(int j=head+1;j<s.length();j++){
                                        ltpair->lexeme.push_back(s[j]);
                                }
                                ltpair->token = "ERROR";
                                ltpair->lineno = ln;
                                ctoken++;
                               
                                state = 0;
                                head=tail=s.length();
                                return ltpair;
                                break;
                                }
                                break;
                                
                        case 9:
                                
                                if(c>='0' && c<='9')
                                {
                                        
                                        letop* ltpair=createTokenPair(s[head]);
                                        for(int j=head+1;j<s.length();j++){
                                                if((s[j]>='0' && s[j]<='9') || s[j]== '.' )
                                                {
                                                        ltpair->lexeme.push_back(s[j]);
                                                        if(j==s.length()-1)
                                                        {
                                                                if(j==s.length()-1)
                                                                {
                                                                        ltpair->token = "ERROR";
                                                                        ltpair->lineno = ln;
                                                                        ctoken++;
                                                                        head = tail = ++j;
                                                                        state = 0;
                                                                        return ltpair;
                                                                        break;
                                                                }
                                                        }
                                                }
                                                else
                                                {
                                                        ltpair->token = "ERROR";
                                                        ltpair->lineno = ln;
                                                        ctoken++;
                                                        head = tail = j;
                                                        
                                                        state = 0;
                                                        return ltpair;
                                                        break;

                                                }
                                        }
                                        break;

                                }
                                else if(c=='.')
                                {
                                        
                                        state = 10;
                                        break;

                                }
                                else
                                {
                                        
                                        
                                        letop* ltpair = createTokenPair(c);
                                        ltpair->lexeme = "0";
                                        ltpair->token = "INTEGER_LIT";
                                        ltpair->lineno = ln;
                                        ctoken++;
                                        
                                        head = tail;
                                        state = 0;
                                        return ltpair;
                                        break;
                                        


                                }
                                break;
                        case 10:
                                if(c>='0' && c<='9' && tail!=s.length()-1)
                                {
                                        c=s[++tail];
                                        state=10;
                                }
                                else if(c=='.')
                                {
                                        
                                        letop* ltpair=createTokenPair(s[head]);
                                        for(int j=head+1;j<s.length();j++){
                                                if((s[j]>='0' && s[j]<='9') || s[j]== '.')
                                                {
                                                        if(s[j]=='.')
                                                        {
                                                                period_flag++;
                                                        }
                                                        ltpair->lexeme.push_back(s[j]);
                                                        if(j==s.length()-1)
                                                        {
                                                                ltpair->token = "FLOAT_LIT";
                                                                ltpair->lineno = ln;
                                                                ctoken++;
                                                                head = tail = ++j;
                                                                

                                                        }
                                                }
                                                else
                                                {
                                                        ltpair->token = "FLOAT_LIT";
                                                        ltpair->lineno = ln;
                                                        ctoken++;
                                                        head = tail = j;
                                                        break;
                                                        

                                                }
                                        }
                                        if(period_flag>1 || s[tail-1]=='.'||s[tail-1]== '0')
                                        {
                                                ltpair->token= "ERROR";
                                        }
                                        state = 0;
                                        period_flag=0;
                                        return ltpair;
                                        break;
                                }
                                else
                                {
                                        if(tail==s.length()-1 && s[tail] >='0' && s[tail]<='9')
                                        {
                                                tail++;
                                        }
                                        letop* ltpair=createTokenPair(s[head]);
                                        for(int j=head+1;j<tail;j++){
                                                ltpair->lexeme.push_back(s[j]);
                                        }
                                        ltpair->token = "INTEGER_LIT";
                                        ltpair->lineno = ln;
                                        ctoken++;
                                        head = tail;
                                        //tail++;
                                        state = 0;
                                        return ltpair;
                                        break;
                                }
                                break;

                }
        }
    
}

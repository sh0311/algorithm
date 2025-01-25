/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
using namespace std;



int main()
{
    list<char> li;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        li.push_back(s[i]);
    }
    
    int n;
    cin>>n;
    int size=li.size();
    auto it=li.end();
    
    for(int i=0;i<n;i++){
        char op,ch;
        cin>>op;
        if(op=='P'){
            cin>>ch;
            li.insert(it,ch);
            
        }else{
            switch(op){
                case 'L':
                    if(it!=li.begin()){
                        it--;
                    }
                    break;
                case 'D':
                    if(it!=li.end()){
                        it++;
                    }
                    break;
                case 'B':
                    if(it!=li.begin()){
                        it=li.erase(--it);
                    }
                    break;
                default:
                    break;
            }
        }
    }
    for(auto i:li){
        cout<<i;
    }
    return 0;
}
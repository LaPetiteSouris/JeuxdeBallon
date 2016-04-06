#ifndef _BUT_H_
#define _BUT_H_
#include <iostream>
#include <vector>
#include "ballon.h"

using namespace std;

class Ballon;

class But{
public:
    int age;
    string nom;
    static vector<But*> * instances; 
    Ballon * monBallon;

    But(string , int );
    ~But();
    
    static void lireNom (string &);
    static void lireAge (int &);
    void imprimer();
    static But* creer_une_instance(); 
    static void imprimer_instances(); 
    static But* getInstance(string);
    void toString(string &); 
    void toIdent(string &);     
    static bool detruire_une_instance(); 
    static void associer_ballon_instance(); 
    void associer_ballon(Ballon *); 

};

#endif 
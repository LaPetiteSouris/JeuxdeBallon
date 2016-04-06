#ifndef _JOUEUR_H_
#define _JOUEUR_H_
#include <iostream>
#include <vector>
#include "ballon.h"

using namespace std;

class Ballon;

class Joueur{
        public:
       
              int age;
              string nom;
              static vector<Joueur*> * instances; 
              Ballon * monBallon;

             Joueur(string , int );
             ~Joueur();
    
    static void lireNom (string &);
    static void lireAge (int &);
    void imprimer();
    static Joueur * creer_une_instance(); 
    static void imprimer_instances(); 
    static Joueur* getInstance(string); 
    void toString(string &); 
    void toIdent(string &);     
    static bool detruire_une_instance(); 
    static void associer_ballon_instance(); 
    void associer_ballon(Ballon *); 
    static void dissocier_ballon_instance(); 
    void dissocier_ballon(Ballon *); 

};

#endif 

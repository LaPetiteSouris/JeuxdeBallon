#ifndef _BALLON_H_
#define _BALLON_H_
#include <iostream>
#include <string.h>
#include <vector>
#include "but.h"
#include "joueur.h"


using namespace std;

   class But;
   class Joueur;

class Ballon {
    public :
    string identificateur; 
    int taille; 
    static vector<Ballon*> * instances;
    But* monBut;
    vector<Joueur*>* mesJoueurs;
    
    Ballon(string, int); 
    ~Ballon();
    
    static void lireIdentificateur(string &); 
    static void lireTaille(int &); 
    void imprimer(); 
    static Ballon * creer_une_instance(); 
    static void imprimer_instances(); 
    static Ballon *getInstance(string); 
    void toString(string &);
    void toIdent(string &); 
    static bool detruire_une_instance(); 
    static void associer_but_instance(); 
    void associer_but(But *); 
    static void associer_joueur_instance(); 
    void associer_joueur(Joueur *); 
    static void dissocier_joueur_instance(); 
    void dissocier_joueur(Joueur *); 
    
};

#endif 

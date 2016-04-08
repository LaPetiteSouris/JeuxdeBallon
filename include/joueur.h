
#ifndef _JOUEUR_H_
#define _JOUEUR_H_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "../include/ballon.h"


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
    static Joueur * creer_instance();
    static void imprimer_instances();
    static Joueur* getInstance(string);
    void toIdent(string &);
    static bool detruire_une_instance();
    static void associer_ballon_Joueur();
    void associer_ballon(Ballon *);
    static void dissocier_ballon_Joueur();
    void dissocier_ballon(Ballon *);

};

#endif

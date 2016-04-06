#include <iostream>
#include <string.h>
#include "../include/ballon.h"
#include "../include/but.h"
#include "../include/joueur.h"


using namespace std;

vector<Ballon*> * Ballon::instances;

Ballon::Ballon(string s,int a){
    identificateur=s;
    taille=a;
    monBut=NULL;
    mesJoueurs=new vector<Joueur*>();
}

Ballon::~Ballon(){
 for (vector<Ballon*>::iterator b=instances->begin(); b!=instances->end(); b++){
            if (this==*b){
                instances->erase(b);
                break;
 }
 }
}

void Ballon::lireIdentificateur(string &s){
    cout<<"Entrer l'indentidicateur du ballon : "<<endl;
    cin>>s;
}

void Ballon::lireTaille(int &a){
    cout<<"Entrer la taille du ballon : "<<endl;
    cin>>a;
}

void Ballon::imprimer(){
    string s;
    this->toString(s);
    cout << s <<endl;
}

Ballon* Ballon::creer_une_instance(){
    string s;
    int a;
    Ballon::lireIdentificateur(s);
    Ballon::lireTaille(a);
    Ballon* b=new Ballon(s,a);
    if(b==NULL){
        cerr<<"Echec de creeation!!!"<<endl;
        return NULL;
    }
    b->imprimer();
    return b;
}

void Ballon::imprimer_instances(){
    for(vector<Ballon*>::iterator i=instances->begin();i!=instances->end(); i++){
        (*i)->imprimer();
    }
}

Ballon* Ballon::getInstance(string s){
    for (vector<Ballon*>::iterator b=instances->begin(); b!=instances->end(); b++){
        if ((*b)->identificateur==s){
            return *b;
        }
    }
    return NULL;
}


void Ballon::toString(string &s){
    char ss[16];
    sprintf (ss, "%d", taille);
    s = "Identificateur " + identificateur + "\n Taille " + ss + "\n But ";
    if (monBut) 
        s = s + monBut->nom;
    else 
       s = s + "null ";
    s = s + "\nJoueurs : ";
    string sss = "";
    for (vector<Joueur*>::iterator j = mesJoueurs->begin(); j!= mesJoueurs->end();j++) {
        (*j)->toIdent(sss) ; 
    }
    s = s + sss + "\n";
}

void Ballon::toIdent(string & s) {
    s =s + identificateur + " ";
}

bool Ballon::detruire_une_instance(){
    string s;
    Ballon::lireIdentificateur(s);
    Ballon* n=Ballon::getInstance(s);
    if(n!=NULL){
        delete n;
        cout<<"Destruction du ballon reussi"<<endl;        
        return true;
    }
    cout<<"Erreur le ballon n'existe pas"<<endl;    
    return false;
}

void Ballon::associer_but_instance(){
    string s1;    
    But::lireNom(s1);
    But* b=But::getInstance(s1);
    string s2;
    Ballon::lireIdentificateur(s2);
    Ballon* n=Ballon::getInstance(s2);

    if(b==NULL){
        cerr<<"Erreur le But n'existe pas"<<endl;
        return;
    }
    if(n==NULL){
        cerr<<"Erreur le ballon n'existe pas"<<endl;
        return;
    }
    n->associer_but(b);
    b->associer_ballon(n);    
    cout<<"Ballon & But associe"<<endl;
    
}

void Ballon::associer_but(But * b){
    monBut=b;
}

void Ballon::associer_joueur_instance(){
    string s1;    
    Joueur::lireNom(s1);
    Joueur* b=Joueur::getInstance(s1);
    string s2;
    Ballon::lireIdentificateur(s2);
    Ballon* n=Ballon::getInstance(s2);

    if(b==NULL){
        cerr<<"Erreur le Joueur n'existe pas"<<endl;
        return;
    }
    if(n==NULL){
        cerr<<"Erreur le Ballon n'existe pas"<<endl;
        return;
    }
    n->associer_joueur(b);
    b->associer_ballon(n);
    cout<<"Ballon et Joueur associe"<<endl;

}

void Ballon::associer_joueur(Joueur *j){
    mesJoueurs->insert(mesJoueurs->begin(), j);
}

void Ballon::dissocier_joueur_instance(){
    string s1;    
    Joueur::lireNom(s1);
    Joueur* b=Joueur::getInstance(s1);
    string s2;
    Ballon::lireIdentificateur(s2);
    Ballon* n=Ballon::getInstance(s2);

    if(b==NULL){
        cerr<<"Erreur le Joueur n'existe pas"<<endl;
        return;
    }
    if(n==NULL){
        cerr<<"Erreur le Ballon n'existe pas"<<endl;
        return;
    }
    n->dissocier_joueur(b);
    b->dissocier_ballon(n);
    cout<<"Ballon et Joueur dissocie"<<endl;
}

void Ballon::dissocier_joueur(Joueur *j){
    for (vector<Joueur*>::iterator b=mesJoueurs->begin(); b!=mesJoueurs->end(); b++){
            if (*b==j){
                mesJoueurs->erase(b);
                break;
            }
    }
    cerr<<"Erreur Ballon & Joueur non associe"<<endl;


}


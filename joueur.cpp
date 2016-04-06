
#include <iostream>
#include <string>
#include <vector>
#include "ballon.h"
#include "joueur.h"


using namespace std;

vector<Joueur*> * Joueur::instances;

Joueur::Joueur (string s, int a){
    nom=s;
    age=a;
    monBallon=NULL;
}

Joueur::~Joueur(){
    for (vector<Joueur*>::iterator j=instances->begin(); j!=instances->end(); j++){
        if(this==*j){
            instances->erase(j);
            break;
    }
 }
}

void Joueur::lireNom (string& s){
    cout<<"Entrer un nom de joueur: "<<endl;
    cin>>s;
}
void Joueur::lireAge (int& a){
    cout<<"Entrer l age du joueur: "<<endl;
    cin>>a;
}

void Joueur::imprimer(){
    string s;
    this->toString(s);
    cout << s <<endl;
}

Joueur* Joueur::creer_une_instance(){
    string s;
    int a;
    Joueur::lireNom(s);
    Joueur::lireAge(a);
    Joueur* j=new Joueur(s,a);
    if(j==NULL){
        cerr<<"Erreur de creation!!!"<<endl;
        return NULL;
    }
    cout<<"Joueur cree";
    j->imprimer();
    return j;
}

void Joueur::imprimer_instances(){
    for(vector<Joueur*>::iterator j=instances->begin();j!=instances->end(); j++){
        (*j)->imprimer();
    }
}

Joueur* Joueur::getInstance(string s){
    for (vector<Joueur*>::iterator j=instances->begin(); j!=instances->end(); j++){
        if ((*j)->nom==s){
            return *j;
        }
    }
    return NULL;
}

void Joueur::toString(string &s){
    char ss[16];
    sprintf (ss, "%d", age);
    s = "Nom " + nom + "\n Age " + ss + "\n But ";
    if (monBallon) 
        s = s + monBallon->identificateur;
    else 
        s = s + "null ";
}

void Joueur::toIdent(string & s) {
    s = s + nom + " ";
}

bool Joueur::detruire_une_instance(){
    string s;
    Joueur::lireNom(s);
    Joueur* n=Joueur::getInstance(s);
    if(n!=NULL){
        delete n;
        cout<<"Destruction de ballon reussi"<<endl;        
        return true;
    }
    cout<<"Erreur le Ballon n existe pas"<<endl;    
    return false;
}

void Joueur::associer_ballon_instance(){
    string s1;    
    Joueur::lireNom(s1);
    Joueur* b=Joueur::getInstance(s1);
    string s2;
    Ballon::lireIdentificateur(s2);
    Ballon* n=Ballon::getInstance(s2);

    if(b==NULL){
        cerr<<"Erreur le Joueur n existe pas "<<endl;
        return;
    }
    if(n==NULL){
        cerr<<"Erreur le Ballon n existe pas"<<endl;
        return;
    }
    b->associer_ballon(n);
    n->associer_joueur(b);    
    cout<<"Joueur & Ballon asscie"<<endl;
    

}

void Joueur::associer_ballon(Ballon *b){
    monBallon=b;
}

void Joueur::dissocier_ballon_instance(){
    string s1;    
    Joueur::lireNom(s1);
    Joueur* j=Joueur::getInstance(s1);
    string s2;
    Ballon::lireIdentificateur(s2);
    Ballon* n=Ballon::getInstance(s2);

    if(j==NULL){
        cerr<<"Erreur le Joueur n existe pas"<<endl;
        return;
    }
    if(n==NULL){
        cerr<<"Erreur le Ballon n existe pas"<<endl;
        return;
    }

    j->monBallon=NULL;
    n->dissocier_joueur(j);

    cout<<"Joueur & Ballon dissocie"<<endl;    
}

void Joueur::dissocier_ballon(Ballon *b){
    monBallon=NULL;
}

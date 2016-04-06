
#include <iostream>
#include <string>
#include <vector>
#include "but.h"
#include "ballon.h"

using namespace std;

vector<But*> * But::instances;

But::But (string s, int a){
    nom=s;
    age=a;
    monBallon=NULL;
}

But::~But(){
    for (vector<But*>::iterator j=instances->begin(); j!=instances->end(); j++){
        if(this==*j){
            instances->erase(j);
            break;
        }
    }
}

void But::lireNom (string& s){
    cout<<"Entrer un nom de joueur: "<<endl;
    cin>>s;
}

void But::lireAge (int& a){
    cout<<"Entrer l age du joueur: "<<endl;
    cin>>a;
}

void But::imprimer(){
    string s;
    this->toString(s);
    cout << s <<endl;
}

But* But::creer_une_instance(){
    string s;
    int a;
    But::lireNom(s);
    But::lireAge(a);
    But* j=new But(s,a);
    if(j==NULL){
        cerr<<"Erreur de creation"<<endl;
        return NULL;
    }
    cout<<"Joueur cree ";
    j->imprimer();
    return j;
}

void But::imprimer_instances(){
    for(vector<But*>::iterator j=instances->begin();j!=instances->end(); j++){
        (*j)->imprimer();
    }
}

But* But::getInstance(string s){
    for (vector<But*>::iterator j=instances->begin(); j!=instances->end(); j++){
        if ((*j)->nom==s){
            return *j;
        }
    }
    return NULL;
}

void But::toString(string &s){
    char ss[16];
    sprintf (ss, "%d", age);
    s = "Nom " + nom + "\n Age " + ss + "\n But ";
    if (monBallon) 
        s = s + monBallon->identificateur;
    else 
        s = s + "null ";
}

void But::toIdent(string & s) {
    s = s + nom + " ";
}

bool But::detruire_une_instance(){
    string s;
    But::lireNom(s);
    But* n=But::getInstance(s);
    if(n!=NULL){
        delete n;
        cout<<"Destruction de ballon reussi"<<endl;        
        return true;
    }
    cout<<"Erreur le Ballon n existe pas"<<endl;    
    return false;
}

void But::associer_ballon_instance(){
    string s1;    
    But::lireNom(s1);
    But* b=But::getInstance(s1);
    string s2;
    Ballon::lireIdentificateur(s2);
    Ballon* n=Ballon::getInstance(s2);

    if(b==NULL){
        cerr<<"Erreur le But n existe pas"<<endl;
        return;
    }
    if(n==NULL){
        cerr<<"Erreur le Ballon n'existe pas"<<endl;
        return;
    }
    b->associer_ballon(n);
    n->associer_but(b);    
    cout<<"But & Ballon associe"<<endl;
    
}

void But::associer_ballon(Ballon *b){
    monBallon=b;
}

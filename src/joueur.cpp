
//MUSTAFA
#include "../include/joueur.h"

using namespace std;

vector<Joueur*> * Joueur::instances;

Joueur::Joueur (string nom, int age){
    this->nom=nom;
    this->age=age;
    monBallon=NULL;
}

Joueur::~Joueur(){
    for (vector<Joueur*>::iterator i=instances->begin(); i!=instances->end(); i++){
        if(this==*i){
            instances->erase(i);
            break;
    }
 }
}

void Joueur::lireNom (string& _nom){
    cout<<"saisie le nom"<<endl;
    cin>>_nom;
}
void Joueur::lireAge (int& _age){
    cout<<"saisie l'age"<<endl;
    cin>>_age;
}

void Joueur::imprimer(){

string Result;//la chaine de caracteres qui va contenir le result
stringstream convert;
convert << age;
Result = convert.str();
    Result = "Nom : " + nom + "\n But : ";
    if (monBallon)
        Result = Result + monBallon->identificateur;
    cout<<Result<<endl;
}

Joueur* Joueur::creer_instance(){
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
    cout<<"Les joueurs : \n"<<endl;
    for(vector<Joueur*>::iterator i=instances->begin();i!=instances->end(); i++){
        (*i)->imprimer();
    }
}

Joueur* Joueur::getInstance(string _nom){
    for (vector<Joueur*>::iterator j=instances->begin(); j!=instances->end(); j++){
        if ((*j)->nom==_nom){
            return *j;
        }
    }
    return NULL;
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
    cout<<"Erreur le Ballon n'existe pas"<<endl;
    return false;
}

void Joueur::associer_ballon_Joueur(){
    string _nom;
    string id;
    Joueur::lireNom(_nom);
    Joueur* j=Joueur::getInstance(_nom);
    Ballon::lireIdentificateur(id);
    Ballon* n=Ballon::getInstance(id);

    if(j==NULL){
        cerr<<"Erreur le Joueur : "<<_nom<<"n'existe pas "<<endl;
        return;
    }
    if(n==NULL){
        cerr<<"Erreur le Ballon : "<<id<<" n'existe pas"<<endl;
        return;
    }
    //associer le ballon au joueur
    j->associer_ballon(n);
    //associer le joueur au ballon
    n->associer_joueur(j);
    cout<<"Le Joueur : "<<_nom<<" et le Ballon : "<<id<<" sont asscie"<<endl;


}

void Joueur::associer_ballon(Ballon *b){
    monBallon=b;
}

void Joueur::dissocier_ballon_Joueur(){
    string _nom;
    string id;
    Joueur::lireNom(_nom);
    Joueur* j=Joueur::getInstance(_nom);
    Ballon::lireIdentificateur(id);
    Ballon* n=Ballon::getInstance(id);
    if(j==NULL){
        cerr<<"Erreur le Joueur : "<<_nom<<" n'existe pas"<<endl;
        return;
    }
    if(n==NULL){
        cerr<<"Erreur le Ballon : "<<id<<"n'existe pas"<<endl;
        return;
    }
    j->monBallon=NULL;
    n->dissocier_joueur(j);

    cout<<"Le joueur "<<_nom<<" et le Ballon "<<id<<" vient d'etre dissocie"<<endl;
}

void Joueur::dissocier_ballon(Ballon *b){
    monBallon=NULL;
}

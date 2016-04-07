// TUNG

#include "../include/but.h"


using namespace std;

vector<But *> *But::instances;

But::But(string nom_, int age_) {
    nom = nom_;
    age = age_;
    monBallon = NULL;
}

But::~But() {
    instances->erase(std::remove(instances->begin(), instances->end(), this), instances->end());
}

void But::lireNom(string &str) {
    cout << "Entrer nom de joueur: " << endl;
    cin >> str;
}

void But::lireAge(int &age) {
    cout << "Entrer age de joueur: " << endl;
    cin >> age;
}

void But::imprimer() {
    string str;
    this->toString(str);
    cout << str << endl;
}

But *But::creer_une_instance() {
    string str;
    int age_;
    lireNom(str);
    lireAge(age_);
    But *but = new But(str, age_);
    but->imprimer();
    return but;
}

void But::imprimer_instances() {
    for (vector<But *>::iterator i = instances->begin(); i < instances->end(); ++i) {
        (*i)->imprimer();
    }
}

But *But::getInstance(string s) {
    for (vector<But *>::iterator i = instances->begin(); i != instances->end(); i++) {
        if ((*i)->nom == s) {
            return *i;
        }
    }
    return NULL;
}


bool But::detruire_une_instance() {
    string str;
    But::lireNom(str);
    But *but = But::getInstance(str);
    // There is no harm of deleting something that does not exist
    delete(but);
    return true;

}

void But::associer_ballon_instance() {
    string s1;
    But::lireNom(s1);
    But *b = But::getInstance(s1);
    string s2;
    Ballon::lireIdentificateur(s2);
    Ballon *n = Ballon::getInstance(s2);

    if (b == NULL) {
        cerr << "Erreur le But n existe pas" << endl;
        return;
    }
    if (n == NULL) {
        cerr << "Erreur le Ballon n'existe pas" << endl;
        return;
    }
    b->associer_ballon(n);
    n->associer_but(b);
    cout << "But & Ballon associe" << endl;

}

void But::associer_ballon(Ballon *b) {
    monBallon = b;
}


void But::toString(string &s) {
    char ss[16];
    sprintf(ss, "%d", age);
    s = "Nom " + nom + "\n Age " + ss + "\n But ";
    if (monBallon)
        s = s + monBallon->identificateur;
    else
        s = s + "null ";
}

void But::toIdent(string &s) {
    s = s + nom + " ";
}
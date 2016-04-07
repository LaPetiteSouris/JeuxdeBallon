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
    toString(str);
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

But *But::getInstance(string str) {
    for (vector<But *>::iterator i = instances->begin(); i != instances->end(); i++) {
        if ((*i)->nom == str) {
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
    delete (but);
    return true;

}

void But::associer_ballon_instance() {
    string nom_;
    But::lireNom(nom_);
    But *pBut = But::getInstance(nom_);
    string id;
    Ballon::lireIdentificateur(id);
    Ballon *pBallon = Ballon::getInstance(id);
    if (!pBut && !pBallon) {

        pBut->associer_ballon(pBallon);
        pBallon->associer_but(pBut);
        cout << "but et ballon associe avec reussis" << endl;
    } else {
        cout << cout << "ballon ou but n'est pas trouve. Veuillez verifier l'entree svp!" << endl;
    }
}


void But::associer_ballon(Ballon *ballon) {
    monBallon = ballon;
}


void But::toString(string &str) {
    char ss[16];
    sprintf(ss, "%d", age);
    str = "Nom " + nom + "\n Age " + ss + "\n ballon(id) ";
    if (monBallon)
        monBallon->toIdent(str);
    else
        str = str + "null ";
}

void But::toNom(string &str) {
    str = str + nom + " ";
}
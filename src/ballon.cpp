// TUNG
#include "../include/ballon.h"


Ballon::Ballon(string str, int taille_) {
    identificateur = str;
    taille = taille_;
    monBut = NULL;
    //Todo: check this sh#t, not a good idea to call new here
    mesJoueurs = new vector<Joueur *>();
}

Ballon::~Ballon() {
    instances->erase(std::remove(instances->begin(), instances->end(), this), instances->end());
}

void Ballon::lireIdentificateur(string &in) {
    cout << "Entrer l'indentidicateur du ballon : " << endl;
    cin >> in;
}

void Ballon::lireTaille(int &taille) {
    cout << "Taille du ballon : " << endl;
    cin >> taille;
}

void Ballon::imprimer() {
    string str;
    toString(str);
    cout << str << endl;
}

Ballon *Ballon::creer_une_instance() {
    string str;
    int taille_;
    lireIdentificateur(str);
    lireTaille(taille_);
    Ballon *ballon = new Ballon(str, taille_);
    ballon->imprimer();
    instances->insert(instances->begin(), ballon);
    return ballon;
}

void Ballon::imprimer_instances() {
    for (vector<Ballon *>::iterator i = instances->begin(); i < instances->end(); ++i) {
        (*i)->imprimer();
    }
}

Ballon *Ballon::getInstance(string str) {
    for (vector<Ballon *>::iterator i = instances->begin(); i != instances->end(); i++) {
        if ((*i)->identificateur == str) {
            return *i;
        }
    }
    return NULL;
}


bool Ballon::detruire_une_instance() {
    string str;
    Ballon::lireIdentificateur(str);
    Ballon *bal_ptr = Ballon::getInstance(str);
    delete bal_ptr;
    // There is no harm of deleting something that does not exist
    return true;
}

void Ballon::associer_but_instance() {
    string nom_;
    But::lireNom(nom_);
    But *but_ptr = But::getInstance(nom_);
    string id;
    Ballon::lireIdentificateur(id);
    Ballon *ballon_ptr = Ballon::getInstance(id);
    if (!but_ptr && ballon_ptr) {

        but_ptr->associer_ballon(ballon_ptr);
        ballon_ptr->associer_but(but_ptr);
        cout << "Ballon et But associe" << endl;

    } else {
        cout << "ballon ou but n'est pas trouve. Veuillez verifier l'entree svp!" << endl;

    }
}

void Ballon::associer_but(But *but) {
    monBut = but;
}

void Ballon::associer_joueur_instance() {
    string nome_;
    Joueur::lireNom(nome_);
    Joueur *joueur_ptr = Joueur::getInstance(nome_);
    string id;
    Ballon::lireIdentificateur(id);
    Ballon *ballon_ptr = Ballon::getInstance(id);

    if (!joueur_ptr && !ballon_ptr) {

        ballon_ptr->associer_joueur(joueur_ptr);
        joueur_ptr->associer_ballon(ballon_ptr);
        cout << "Ballon et Joueur associe" << endl;


    } else {
        cout << "ballon_ptr ou joueur n'est pas trouve. Veuillez verifier l'entree svp!" << endl;

    }
}

void Ballon::associer_joueur(Joueur *joueur) {
    mesJoueurs->insert(mesJoueurs->begin(), joueur);
}

void Ballon::dissocier_joueur_instance() {
    string nom_;
    Joueur::lireNom(nom_);
    Joueur *joueur_ptr = Joueur::getInstance(nom_);
    string id;
    Ballon::lireIdentificateur(id);
    Ballon *ballon_ptr = Ballon::getInstance(id);
    if (!joueur_ptr && !ballon_ptr) {

        ballon_ptr->dissocier_joueur(joueur_ptr);
        joueur_ptr->dissocier_ballon(ballon_ptr);
        cout << "Ballon et Joueur dissocie avec reuissis" << endl;

    }
    else {
        cout << "ballon_ptr ou joueur n'est pas trouve. Veuillez verifier l'entree svp!" << endl;
    }
}

void Ballon::dissocier_joueur(Joueur *jouer) {
    mesJoueurs->erase(std::remove(mesJoueurs->begin(), mesJoueurs->end(), jouer), mesJoueurs->end());

}


void Ballon::toString(string &str) {
    char ss[16];
    sprintf(ss, "%d", taille);
    str = "Identificateur " + identificateur + "\n Taille " + ss + "\n But ";
    if (monBut)
        str = str + monBut->nom;
    else
        str = str + "null ";
    str = str + "\nJoueurs : ";
    string sss = "";
    for (vector<Joueur *>::iterator j = mesJoueurs->begin(); j != mesJoueurs->end(); j++) {
        (*j)->toIdent(sss);
    }
    str = str + sss + "\n";
}

void Ballon::toIdent(string &s) {
    s = s + identificateur + " ";
}

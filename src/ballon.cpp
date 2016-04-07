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

Ballon *Ballon::getInstance(string s) {
    for (vector<Ballon *>::iterator b = instances->begin(); b != instances->end(); b++) {
        if ((*b)->identificateur == s) {
            return *b;
        }
    }
    return NULL;
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

bool Ballon::detruire_une_instance() {
    string s;
    Ballon::lireIdentificateur(s);
    Ballon *n = Ballon::getInstance(s);
    if (n != NULL) {
        delete n;
        cout << "Destruction du ballon reussi" << endl;
        return true;
    }
    cout << "Erreur le ballon n'existe pas" << endl;
    return false;
}

void Ballon::associer_but_instance() {
    string s1;
    But::lireNom(s1);
    But *b = But::getInstance(s1);
    string s2;
    Ballon::lireIdentificateur(s2);
    Ballon *n = Ballon::getInstance(s2);

    if (b == NULL) {
        cerr << "Erreur le But n'existe pas" << endl;
        return;
    }
    if (n == NULL) {
        cerr << "Erreur le ballon n'existe pas" << endl;
        return;
    }
    n->associer_but(b);
    b->associer_ballon(n);
    cout << "Ballon & But associe" << endl;

}

void Ballon::associer_but(But *b) {
    monBut = b;
}

void Ballon::associer_joueur_instance() {
    string s1;
    Joueur::lireNom(s1);
    Joueur *b = Joueur::getInstance(s1);
    string s2;
    Ballon::lireIdentificateur(s2);
    Ballon *n = Ballon::getInstance(s2);

    if (b == NULL) {
        cerr << "Erreur le Joueur n'existe pas" << endl;
        return;
    }
    if (n == NULL) {
        cerr << "Erreur le Ballon n'existe pas" << endl;
        return;
    }
    n->associer_joueur(b);
    b->associer_ballon(n);
    cout << "Ballon et Joueur associe" << endl;

}

void Ballon::associer_joueur(Joueur *j) {
    mesJoueurs->insert(mesJoueurs->begin(), j);
}

void Ballon::dissocier_joueur_instance() {
    string s1;
    Joueur::lireNom(s1);
    Joueur *b = Joueur::getInstance(s1);
    string s2;
    Ballon::lireIdentificateur(s2);
    Ballon *n = Ballon::getInstance(s2);

    if (b == NULL) {
        cerr << "Erreur le Joueur n'existe pas" << endl;
        return;
    }
    if (n == NULL) {
        cerr << "Erreur le Ballon n'existe pas" << endl;
        return;
    }
    n->dissocier_joueur(b);
    b->dissocier_ballon(n);
    cout << "Ballon et Joueur dissocie" << endl;
}

void Ballon::dissocier_joueur(Joueur *j) {
    for (vector<Joueur *>::iterator b = mesJoueurs->begin(); b != mesJoueurs->end(); b++) {
        if (*b == j) {
            mesJoueurs->erase(b);
            break;
        }
    }
    cerr << "Erreur Ballon & Joueur non associe" << endl;


}


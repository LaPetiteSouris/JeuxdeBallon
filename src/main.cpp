//MUSTAFA

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "../include/joueur.h"
#include "../include/ballon.h"
#include "../include/but.h"

using namespace std;
//Les prototypes des fonctions

  void Menu_principale();
  void Menu_ballon();
  void Menu_Joueur();
  void Menu_but();

  void traitement_ballon(int &i);
  void traitement_joueur(int &i);
  void traitement_but(int &i);
  void traitement_menu(int &i);
//le programme principal
int main (int argc, char *argv[]){

    Ballon::instances = new vector<Ballon*>();
    Joueur::instances = new vector<Joueur*>();
    But::instances = new vector<But*>();
    cout <<"********TP6 : Tung son HOANG & Mustafa DRISSI ***********"<<endl;
    Menu_principale();
    return 0;
}

// Les fonctions

void Menu_principale(){
system("clear");
    cout << "\n Menu general, veuillez saisir votre choix : " << endl;
    cout << "  1.Joueur" << endl;
    cout << "  2.Ballon" << endl;
    cout << "  3.But" << endl;
    cout << "  0.Quitter"<< endl;
    int i;
    cout<<"saisir votre choix : "<<endl;
    cin>>i;
    traitement_menu(i);
}
void traitement_menu(int &i){

    while(i!=0){
        switch(i){
            case 1 : {
                Menu_Joueur();
                break;}
            case 2:{
                Menu_ballon();
                break;}
            case 3:{
                Menu_but();
                break;}

        }
    }
    exit(0);
}
void Menu_ballon(){
    system("clear");
     cout << "\n Menu Ballon, veuillez saisir votre choix : " <<  endl;
     cout << "  1.creer un ballon." <<  endl;
     cout << "  2.detruire un ballon" <<  endl;
     cout << "  3.afficher la liste des ballons" <<  endl;
     cout << "  4.associer un ballon a un but" <<  endl;
     cout << "  5.associer un ballon a des joueurs" <<  endl;
     cout << "  6.dissocier un ballon d un joueur"<< endl;
     cout << "  0.retour." <<  endl;
        int i;
        cout<<"saisir votre choix : "<<endl;
        cin>>i;
        traitement_ballon(i);
}

void Menu_Joueur(){
    system("clear");
     cout << "\n Menu Joueur, veuillez saisir votre choix : " <<  endl;
     cout << "  1.creer un joueur" <<  endl;
     cout << "  2.detruire un joueur" <<  endl;
     cout << "  3.afficher la liste des joueurs" <<  endl;
     cout << "  4.associer un joueur a un ballon" <<  endl;
     cout << "  5.dissocier un joueur d une ballon" <<  endl;
     cout << "  0.retour" <<  endl;
        int i;
        cout<<"saisir votre choix : "<<endl;
        cin>>i;
        traitement_joueur(i);

}

void Menu_but(){
    system("clear");
     cout << "\n Menu But, veuillez saisir votre choix : " <<  endl;
     cout << "  1.creer un but" <<  endl;
     cout << "  2.detruire un but" <<  endl;
     cout << "  3.afficher la liste des buts" <<  endl;
     cout << "  4.associer un ballon a un but" <<  endl;
     cout << "  0.retour" <<  endl;
        int i;
        cout<<"saisir votre choix : "<<endl;
        cin>>i;
        traitement_but(i);
}


void traitement_ballon(int &i){

    while(i!=0){
        switch(i){
            case 1:{
                Ballon* b=Ballon::creer_une_instance();
                Ballon::instances->insert(Ballon::instances->begin(), b);
                break;}
            case 2 :{
                Ballon::detruire_une_instance();
                break ;}
            case 3:{
                Ballon::imprimer_instances();
                break;}
            case 4 :{
                Ballon::associer_but_instance();
                break;}
            case 5 :{
                Ballon::associer_joueur_instance();
                break;}
            case 6 :{
                Ballon::dissocier_joueur_instance();
                break;}

            }
         cout << "Saisir de nouveau votre choix : " <<  endl;
         cin >>i;
    }
    if(i==0)
        Menu_principale();
}

void traitement_joueur(int &i){

    while(i!=0){
        switch(i){
            case 1:   {Joueur* j=Joueur::creer_instance();
                 Joueur::instances->insert(Joueur::instances->begin(), j);
                 break;}
            case 2:{
                Joueur::detruire_une_instance();
                break;}
            case 3:{
                Joueur::imprimer_instances();
                break;}
            case 4:{
                Joueur::associer_ballon_Joueur();
                break;}
            case 5:{
                Joueur::dissocier_ballon_Joueur();
                break;}
            }
         cout << "Saisir de nouveau votre choix : " <<  endl;
         cin >>i;
    }
    if(i==0)
        Menu_principale();
}

void traitement_but(int &i){

    while(i!=0){
        switch(i){
            case 1 :{
                But* b=But::creer_une_instance();
                But::instances->insert(But::instances->begin(), b);
                break;}
            case 2 :{
                But::detruire_une_instance();
                break;}
            case 3 : {
                But::imprimer_instances();
                break;}
            case 4 :{
                But::associer_ballon_instance();
                break;}
    }
cout << "Saisir � nouveau votre choix : " <<  endl;
         cin >>i;
}
    if(i==0)
        Menu_principale();
}





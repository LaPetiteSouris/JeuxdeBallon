
#include <iostream>
#include <string>
#include "../include/joueur.h"
#include "../include/ballon.h"
#include "../include/but.h"

  void affiche_menu();
  void affiche_ballon();
  void affiche_joueur();
  void affiche_but();
  void traite_ballon(int &i);
  void traite_joueur(int &i);
  void traite_but(int &i);


int main (int argc, char *argv[]){
    Ballon::instances = new vector<Ballon*>();
    Joueur::instances = new vector<Joueur*>();
    But::instances = new vector<But*>();
    
    std::cout << "***********************************************************" << std::endl;
    std::cout << "******************************TP6**************************" << std::endl;
    std::cout << "***********************************************************" << std::endl;
       
    int i=1,j=1;
    affiche_menu();
    std::cout << "==>";    
    std::cin >>i;

    while(i!=0){
                
            if(i==1){    
            affiche_joueur();
            traite_joueur(j);            
        }
            else if (i==2){
            affiche_ballon();
            traite_ballon(j);
        }
            else if (i==3){
            affiche_but();
            traite_but(j);     
        }
            else{
            std::cout << "Erreur!" << std::endl;    
        }
        affiche_menu();
        std::cout << "==>";    
        std::cin >>i;

    }
}

void affiche_menu(){
    std::cout << "                                    " << std::endl;    
    std::cout << "Entrer votre choix" << std::endl;
    std::cout << "  1.Joueur" << std::endl;
    std::cout << "  2.Ballon" << std::endl;
    std::cout << "  3.But" << std::endl;
    std::cout << "  0.Quitter"<<std::endl;
}

void affiche_ballon(){  
    std::cout << "Saisir votre choix" << std::endl;
    std::cout << "  1.creer un ballon." << std::endl;
    std::cout << "  2.detruire un ballon" << std::endl;
    std::cout << "  3.afficher la liste des ballons" << std::endl;
    std::cout << "  4.associer un ballon a un but" << std::endl;
    std::cout << "  5.associer un ballon a des joueurs" << std::endl; 
    std::cout << "  6.dissocier un ballon d un joueur"<<std::endl; 
    std::cout << "  0.retour." << std::endl;
}

void affiche_joueur(){      
    std::cout << "Saisir votre choix" << std::endl;
    std::cout << "  1.creer un joueur" << std::endl;
    std::cout << "  2.detruire un joueur" << std::endl;
    std::cout << "  3.afficher la liste des joueurs" << std::endl;
    std::cout << "  4.associer un joueur a un ballon" << std::endl; 
    std::cout << "  5.dissocier un joueur d une ballon" << std::endl; 
    std::cout << "  0.retour" << std::endl;
 
}

void affiche_but(){      
    std::cout << "Saisir votre choix" << std::endl;
    std::cout << "  1.creer un but" << std::endl;
    std::cout << "  2.detruire un but" << std::endl;
    std::cout << "  3.afficher la liste des buts" << std::endl;
    std::cout << "  4.associer un ballon a un but" << std::endl;
    std::cout << "  0.retour" << std::endl;
}


void traite_ballon(int &i){
    std::cout << "==>";    
    std::cin >>i;
    while(i!=0){
        if(i==1){
            Ballon* b=Ballon::creer_une_instance();
            Ballon::instances->insert(Ballon::instances->begin(), b);
        }else if (i==2){
            Ballon::detruire_une_instance();
        }else if (i==3){
            Ballon::imprimer_instances();
        }else if (i==4){
            Ballon::associer_but_instance();
        }else if (i==5){
            Ballon::associer_joueur_instance();        
        }else if (i==6){
            Ballon::dissocier_joueur_instance();                
        }else{
            std::cout << "Erreur" << std::endl;
        }
        std::cout << "Saisir de nouveau votre choix" << std::endl;
        std::cout << "==>";
        std::cin >>i;
    }
}

void traite_joueur(int &i){
    std::cout << "==>";    
    std::cin >>i;
    while(i!=0){
        if(i==1){
            Joueur* j=Joueur::creer_une_instance();
            Joueur::instances->insert(Joueur::instances->begin(), j);
        }else if (i==2){
            Joueur::detruire_une_instance();        
        }else if (i==3){
            Joueur::imprimer_instances();        
        }else if (i==4){
            Joueur::associer_ballon_instance();
        }else if (i==5){
            Joueur::dissocier_ballon_instance();        
        }else{
            std::cout << "Erreur!" << std::endl;
        }
        std::cout << "Saisir de nouveau votre choix" << std::endl;
        std::cout << "==>";
        std::cin >>i;
    }
}

void traite_but(int &i){
    std::cout << "==>";    
    std::cin >>i;
    while(i!=0){
        if(i==1){
            But* b=But::creer_une_instance();
            But::instances->insert(But::instances->begin(), b);
        }else if (i==2){
            But::detruire_une_instance();                
        }else if (i==3){
            But::imprimer_instances();        
        }else if (i==4){
            But::associer_ballon_instance();
        }else{
            std::cout << "Erreur" << std::endl;
        }
        std::cout << "Saisir de nouveau votre choix " << std::endl;
        std::cout << "==>";
        std::cin >>i;
    }

}





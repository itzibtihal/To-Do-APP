// bibliothèque pour effectuer des opérations d'entrée/sortie 
#include <stdio.h>

// bibliothèque standard pour la gestion de la mémoire
#include <stdlib.h>

// bibliothèque liéer à la gestion du temps
#include <time.h>

//bibliothèque de manipulation de chaînes de caractères 
#include <string.h>

//bibliothèque permet d'utiliser le type de données booléen 
#include <stdbool.h>

#include <ctype.h>

// importe la déclaration des fonctions
#include "proototype/prototype.h"
// importe des entités (structures)
#include "entities/toDo.h"
// importe des fonctions de vue
#include "service/vueFunctions.h"
// importe des fonctions de service
#include "service/serviceFunctions.h"

  // variable

   int id = 0;
   int i = 0 ;

int main (){
   

  

         Sas();
         interface();
         todo();

          //Menu de l'applicationvoid

    int input;
	while(1){
		again :
		printTab();printf("==========================================              ===========================================\n");
        printTab();printf("==========================================   M E N U    ===========================================\n");
        printTab();printf("==========================================              ===========================================\n \n \n");
		do {
			printTab();printf("1  Ajouter une nouvelle tâche\n\n");
			printTab();printf("2  Ajouter plusieurs nouvelles tâches\n\n");
			printTab();printf("3  Afficher la liste de toutes les tâches \n\n\n");
			printTab();printf("4  Modifier une tâche\n\n");
			printTab();printf("5  Supprimer les tâches par\n\n");
            printTab();printf("6  Rechercher les tâches\n\n");
			printTab();printf("7  Statistique des tâches\n\n\n");
			
			printTab();printf("0  Quiter\n\n");
			input=getInt();

            switch (input)
            {
            case 0 :
                  exit(0);;
            break;
            case 1 :
                      // fonction d'ajout d 'une taches
                       AjouterTache();
            break;
            case 2 :
                      // fonction d' ajout de plusieurs taches
                      AjouterDesTaches()
            break;
            case 3 :
               /* Trier les tâches par ordre alphabétique.

                Trier les tâches par deadline.

                Afficher les tâches dont le deadline est dans 3 jours ou moins.*/
               while (1)
               {
                 int choix ;
                 do
                 {
                  printTab();printf("\t=======   Lister toutes les taches ======= \n\n\n");
                  printTab();printf("1  lister toutes les tâches par ordre alphabétique \n\n");
                  printTab();printf("2  lister toutes les tâches  par deadline \n\n");
                  printTab();printf("3  lister toutes les tâches  dont le deadline est dans 3 jours ou moins \n\n");
                  printTab();printf("0  Menu \n\n");
                  choix = getInt();
                 } while (choix > 3 || choix < 0);
                 
                      switch (choix)
                      {
                      case 1:
                        // fonction  lister toutes les tâches par ordre alphabétique
                        break;
                      case 2 :
                         // fonction  lister toutes les tâches  par deadline
                         break;
                       case 3 :
                         // fonction  lister toutes les tâches  dont le deadline est dans 3 jours ou moins 
                         break;
                        case 0 : break;
                      
                        if(!choix) break;
                      }
                    break;
               }

            case 4 :
                /*
                   Modifier la description d'une tâche.

                   Modifier le statut d’une tâche.

                   Modifier le deadline d’une tâche
                */
               
            break;   
            
            default:
                break;
            }
			
		}while(input > 7 || input < 0);
	}	
         



}
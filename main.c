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
   // nombre des taches
   int n = 0;

int main (){
   

  

         Sas();
         interface();
         todo();

          //Menu de l'applicationvoid

    int input;
	while(1){
		again :
		printf("\n\n\n\n");
		printf("\t\t==========================================                    ===========================================\n");
        printf("\t\t==========================================      M E N U       ===========================================\n");
        printf("\t\t==========================================                    ===========================================\n \n \n");
		do {
			printTab();printf("1  Ajouter une nouvelle tache\n\n");
			printTab();printf("2  Ajouter plusieurs nouvelles taches\n\n");
			printTab();printf("3  Afficher la liste de toutes les taches \n\n\n");
			printTab();printf("4  Modifier une tache\n\n");
			printTab();printf("5  Supprimer les taches par ID \n\n");
            printTab();printf("6  Rechercher les taches\n\n");
			printTab();printf("7  Statistique des taches\n\n\n");
			
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
                      AjouterDesTaches();
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
                          ListByCloseDeadline();
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
                   while (1)
               {
                 int choix ;
                 do
                 {
                  printTab();printf("\t=======   Modifier  les taches ======= \n\n\n");
                  printTab();printf("1  Modifier la description d'une tache \n\n");
                  printTab();printf("2  Modifier le statut d’une tache\n\n");
                  printTab();printf("3  Modifier le deadline d’une tache \n\n");
                  printTab();printf("0  Menu \n\n");
                  choix = getInt();
                 } while (choix > 3 || choix < 0);
                 
                      switch (choix)
                      {
                      case 1:
                        // fonction  pour Modifier la description d'une tache
                             updateDescription();

                        break;
                      case 2 :
                         // fonction pour Modifier le statut d’une tache
                             updateStatus();
                         break;
                       case 3 :
                         // fonction pour Modifier le deadline d’une tache
                          updateDeadline();
                         break;
                        case 0 : break;
                      
                        if(!choix) break;
                      }
                    break;
               } 
            break;   

            case 5:
                 // fonction de suppression par id
                  void deleteById();
            break;

            case 6:
                   while (1)
               {
                 int choix ;
                 do
                 {
                  printTab();printf("\t=======   Rechercher  les taches ======= \n\n\n");
                  printTab();printf("1  Rechercher une tache par son Identifiant.\n\n");
                  printTab();printf("2  Rechercher une tache par son Titre\n\n");
                  printTab();printf("0  Menu \n\n");
                  choix = getInt();
                 } while (choix > 2 || choix < 0);
                 switch (choix)
                 {
                 case 1:
                    // FONCTION DE recherche by id
                    getById();
                    break;

                case 2:
                    // fonction de recherche par titre
                     rechercherTacheParTitre();
                    break;
                    
                 default:
                    break;
                 }
                 
                 
                 }
            break;

            case 7 :
               while (1)
               {
                int choix ;
                   do
                 {
                  printTab();printf("\t=======   Statistique des taches ======= \n\n\n");
                  printTab();printf("1  Afficher le nombre total des taches.\n\n");
                  printTab();printf("2  Afficher le nombre de taches complètes et incompletes.\n\n");
                  printTab();printf("3  Afficher le nombre de jours restants jusqu'au délai de chaque tâche.\n\n");
                  printTab();printf("0  Menu \n\n");
                  choix = getInt();
                 } while (choix > 2 || choix < 0);
                 switch (choix)
                 {
                 case 1:
                    getNtache();
                    break;
                 case 2:
                    getCompletedandIncompletedTasks();
                    break;
                 case 3:
                    
                    break;       
                 
                 default:
                    break;
                 }
               }
               
            break;
            
            default:
                break;
            }
			
		}while(input > 7 || input < 0);
	}	
         



}
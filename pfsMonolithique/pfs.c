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

// ================================================================================= structure ==============================================================================

// date structure 
typedef struct date{
 	int jour;
 	int mois;
 	int annee;
}date;



// les valeurs possible de status 

/*
enum Statuts {
    Arealiser = 1 ,
    EncoursDeRealisation = 2 , 
    Finalisee = 3
};*/




// to  do structure 
typedef struct toDo
{
    int id ;
    char titre [50];
    char description[400];
    struct date deadline ;
    // enum Status status;
    int  Status;
}toDo; 
toDo Task[300];

// ============================================================================= fonction de vue ========================================================================

 // fontion qui affiche "projet fin sas"
void Sas(){
    
    printf("\n\n\n");
		printf("\t\t			.---.               _        .-.   .---.  _          .--.  .--.  .--. \n");
		printf("\t\t			: .; :             :_;      .' `.  : .--':_;        : .--': .; :: .--'\n");
		printf("\t\t			:  _.'.--.  .--.   .-. .--. `. .'  : `;  .-.,-.,-.  `. `. :    :`. `. \n");
		printf("\t\t			: :   : ..'' .; :  : :' '_.' : :   : :   : :: ,. :   _`, :: :: : _`, :\n");
		printf("\t\t			:_;   :_;  `.__.'  : :`.__.' :_;   :_;   :_;:_;:_;  `.__.':_;:_;`.__.'\n");
		printf("\t\t			                 .-. :                                                     \n");                                                              
		printf("\t\t			                 `._.'                                                          \n");                                                         
		printf("\n\n\n");
		}



// fonction qui affiche le message de bonjour à l'application
/*
void interface()
{
    
    printf("\n\n\n");
    printf("\t \t ~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");
    printf("\t \t ~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n\n");
    printf("\t \t } : } : } : } : } : } "
           ": } : } : } :   "
           "WELCOME TO the TODO APP "
           "     : { : { : { : { : { "
           ": { : { : { : {\n\n");
    printf("\t \t ~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");
    printf("\t \t ~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");
    
   
} */

// affichage de msg to do 

void todo(){
     printf("\n\n\n\n");
    printf("\t \t ~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");

    printf("\t \t ~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n\n");
    printf("\t \t \t \t \t   TTTTTT    OOO        DDDD        OOO \n");
    printf("\t \t \t \t \t     T     O     O      D    D    O     O\n");
    printf("\t \t \t \t \t     T     O     O      D    D    O     O\n");
    printf("\t \t \t \t \t     T       OOO        DDDD        OOO\n");
    printf("\t \t ~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");
    printf("\t \t ~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");


}


// fonction qui affiche error 404

void error404(){    
    printf("==================================================================================\n");
    printf("\n");
  	printf("  ______                                  _  _      ___    _  _   \n");
	printf(" |  ____|                                | || |    / _ \\  | || |  \n");
	printf(" | |__     _ __   _ __    ___    _ __    | || |_  | | | | | || |_ \n");
	printf(" |  __|   | '__| | '__|  / _ \\  | '__|   |__   _| | | | | |__   _|\n");
	printf(" | |____  | |    | |    | (_) | | |         | |   | |_| |    | |  \n");
	printf(" |______| |_|    |_|     \\___/  |_|         |_|    \\___/     |_|  \n");
    printf("\n");
    printf("==================================================================================\n");    
}

void printTab(){
	printf("\t\t\t\t\t");
}


int getInt(){
	int n;
	printf("\t\t\t:");
	scanf("%d", &n);
return n;
}
//=================================================================================== fonction de  service =============================================================

      // ++++++++++++++++++++++ ajouter une tache ++++++++++++++++

void AjouterTache(int *i, int *id, int *n) {
    Task[*i].id = (*id)++;
    printTab();
    printf("Entrer le titre de votre tache :\n\n ");
    printTab();
    printTab();scanf(" %[^\n]", Task[*i].titre);
    printTab();
    printf("Entrer une Description :\n\n ");
    printTab();
    printTab();scanf(" %[^\n]", Task[*i].description);
    printTab();
    printf("Entrez un Deadline (jour / mois / annee) :\n\n");
    printTab();
    printTab();scanf("%d / %d / %d", &Task[*i].deadline.jour, &Task[*i].deadline.mois, &Task[*i].deadline.annee);

    printTab();
    printf("Status :\n");
    do {
        printTab();
        printf("1  a realiser\n");
        printTab();
        printf("2  en cours de realisation\n");
        printTab();
        printf("3  finalisee\n");
        printTab();
        printf("Merci de modifier votre status : \n\n");
        printTab();
        scanf("%d", &Task[*i].Status);
    } while (Task[*i].Status < 1 || Task[*i].Status > 3);
    (*i)++;
    (*n)++;
}


    //  +++++++++++++++++++++++++++++++++++++++++++   ajouter des taches ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  void AjouterDesTaches(int *i, int *id, int *n) {
    int nombreDeTaches;
    printTab();printf("Combien de taches souhaitez-vous ajouter ? : ");
    printTab();scanf("%d", &nombreDeTaches);

    for (int j = 0; j < nombreDeTaches; j++) {
        printTab();printf("Tache # %d\n", j + 1);
        //ajouter une tâche individuelle
        AjouterTache(i, id, n);

        printTab();printf("Tache #%d ajoutee avec succes!\n", j + 1);
        
    }
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++ afficher les taches ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



void ListAll(int *i){
    if (*i == 0) {
        printf("Aucune tache enregistree pour le moment.\n");
        return;
    }

    printf("Liste de toutes les taches enregistrees :\n");
    for (int j = 0; j < *i; j++) {
        printf("ID : %d\n", Task[j].id);
        printf("Titre : %s\n", Task[j].titre);
        printf("Description : %s\n", Task[j].description);
        printf("Deadline : %d-%d-%d\n", Task[j].deadline.jour, Task[j].deadline.mois, Task[j].deadline.annee);
        printf("Statut : ");
        switch (Task[j].Status) {
            case 1:
                printf("A realiser\n");
                break;
            case 2:
                printf("En cours de realisation\n");
                break;
            case 3:
                printf("Finalisee\n");
                break;
            default:
                printf("Statut inconnu\n");
        }
        printf("\n");
    }
}
 

// ==================  list close ones ======================

 void ListByCloseDeadline(int *i){
      // importer la date actuelle 
        int  dayNow, moisNow, anNow;
        time_t now;
    
        // Renvoie l'heure actuelle
        time(&now); 
       // Convertir au format  locale
        struct tm *local = localtime(&now);
        dayNow = local->tm_mday;          
        moisNow = local->tm_mon + 1;     
        anNow = local->tm_year + 1900;  

        // comparer la date acctuelle avec la date saisi par lutilisateur 
    
    for (int j = 0; j < *i; j++) {
        int joursRestants = (Task[j].deadline.annee - anNow) * 365 +
                            (Task[j].deadline.mois - moisNow) * 30 +
                            (Task[j].deadline.jour - dayNow);
        if (joursRestants < 4)
        {
            // affichage des jours < = 3
            printTab();printf("Taches dont le delai est de 3 jours ou moins :\n \n");
            printTab();printf("Titre : %s \n: " , Task[j].titre);
            printTab(); printf("Description : %s\n", Task[j].description);
            printTab();printf("Deadline : %d / %d / %d \n", Task[j].deadline.jour, Task[j].deadline.mois, Task[j].deadline.annee);
            printTab(); printf("Statut : ");
        switch (Task[j].Status) {
            case 1:
                printf("A realiser\n");
                break;
            case 2:
                printf("En cours de realisation\n");
                break;
            case 3:
                printf("Finalisee\n");
                break;
            default:
                printf("Statut inconnu\n");
        }
            printf("\n");
        }      
   }
} 

// fontction qui examine si l'ID exist ou pas
bool idExiste(int id, int *i) {
    for (int j = 0; j < *i; j++) {
        if (Task[j].id == id) {
            return true; // L'ID existe
        }
    }
    return false; // L'ID n'existe pas
}



// =========================FONCTION MODIFIER LA DESCRIPTION ===============
void updateDescription(int *i) {
    // Afficher les tâches
    ListAll(i);

    // Entrer l'ID de la tâche
    int identi;
    bool result;

    do {
        printTab();
        printf("Entrer l'identifiant de la tache que vous voulez modifier :\n");
        printTab();
        scanf("%d", &identi);
        result = idExiste(identi, i);
        if (!result) {
            printTab();
            printf("L'identifiant %d n'existe pas dans le tableau. Veuillez réessayer.\n", identi);
        }
    } while (!result);

    // Modifier la description
    printTab();printf("Merci de modifier la description : \n\n");
    
    printTab();scanf(" %[^\n]", Task[identi].description);
    
}


 //============================    modifier le status   ==================

void updateStatus(int *i) {
    // Afficher les tâches
    ListAll(i);

    // Entrer l'ID de la tâche
    int identi;
    bool result;

    do {
        printTab();
        printf("Entrer l'identifiant de la tache que vous voulez modifier :\n");
        printTab();
        scanf("%d", &identi);
        result = idExiste(identi, i);
        if (!result) {
            printTab();
            printf("L'identifiant %d n'existe pas dans le tableau. Veuillez reessayer!\n", identi);
        }
    } while (!result);

    // Modifier le statut
    printTab();
    printf("Rappelons que les choix de statut sont :\n");
    do {
        printTab();
        printf("1  A realiser\n");
        printTab();
        printf("2  En cours de realisation\n");
        printTab();
        printf("3  Finalisee\n");
        printTab();
        printf("Merci de modifier votre statut : \n\n");
        printTab();
        scanf("%d", &Task[identi].Status);
    } while (Task[identi].Status < 1 || Task[identi].Status > 3);
}

// ====================== modifier le deadline ====================
void updateDeadline(int *i) {
    // Afficher les tâches
    ListAll(i);

    // Entrer l'ID de la tâche
    int identi;
    bool result;

    do {
        printTab();
        printf("Entrer l'identifiant de la tache que vous voulez modifier :\n");
        printTab();
        scanf("%d", &identi);
        result = idExiste(identi, i);
        if (!result) {
            printTab();
            printf("L'identifiant %d n'existe pas dans le tableau ! Veuillez reessayer.\n", identi);
        }
    } while (!result);

    // Modifier deadline
    printTab();
    printf("Merci d'entrer la nouvelle date :\n");
    printTab();
    printf("Sous la forme DD / MM / YYYY: \n");
    scanf("%d / %d / %d", &Task[identi].deadline.jour, &Task[identi].deadline.mois, &Task[identi].deadline.annee);
}

 // ================= ================= ==========  delete ========== ============= ================ ============  


   // delete by id 


   void deleteById(int *i, int *n) {
    // Afficher les tâches
    ListAll(i);

    // Entrer l'ID de la tâche à supprimer
    int identi;
    bool result;

    do {
        printTab();
        printf("Entrer l'identifiant de la tache que vous voulez supprimer :\n");
        printTab();
        scanf("%d", &identi);
        result = idExiste(identi, i);
        if (!result) {
            printTab();
            printf("L'identifiant %d n'existe pas dans le tableau. Veuillez reessayer.\n", identi);
        }
    } while (!result);

    // Supprimer la tache ==> l'ID 
    for (int j = 0; j < *n; j++) {
        if (Task[j].id == identi) {
            for (int k = j; k < *n - 1; k++) {
                Task[k] = Task[k + 1];
            }
            (*n)--;
            (*i)--;
            break; // Sortir  apres la suppression
        }
    }
}




     //============================== ==================   rechercher   ================= ====================== ================= 


// ++++++++++++++++++++++++++ +++++++++++++++++++++++ get by id  +++++++++++ +++++++++++++++

void getById(int *i){

         int identi;
         bool result;

    do {
           printTab();printf("Entrer l'identifiant de la tache que vous voulez Afficher :\n");
           printTab();scanf("%d", &identi);
           result = idExiste(identi, i);
           if (!result) {
              printTab();printf("L'identifiant %d n'existe pas dans le tableau. Veuillez reessayer.\n", identi);
           }
       } while (!result);

         printTab();printf("ID : %d\n", Task[identi].id);
         printTab();printf("Titre : %s\n", Task[identi].titre);
         printTab();printf("Description : %s\n", Task[identi].description);
         printTab();printf("Deadline : %d-%d-%d\n", Task[identi].deadline.jour, Task[identi].deadline.mois, Task[identi].deadline.annee);
         printTab();printf("Statut : ");
        switch (Task[identi].Status) {
            case 1:
                printf("A realiser\n");
                break;
            case 2:
                printf("En cours de realisation\n");
                break;
            case 3:
                printf("Finalisee\n");
                break;
            default:
                printf("Statut inconnu\n");
        }
        printf("\n");

}


// +++++++++++++ +++++++++++++++++++ ++++++++++++++++++ get by titre +++++++++++ +++++++++++++++++++ ++++++++++++++++

void rechercherTacheParTitre(int *i) {

    char titreRecherche[50]; 
    printf("Entrez le titre de la tache que vous recherchez : ");
    scanf(" %[^\n]", titreRecherche);

    bool trouve = false;

    for (int j = 0; j < *i; j++) {
        if (strcmp(Task[j].titre, titreRecherche) == 0) {
            // Titre trouve ==> affichage des détails de la tâche
            printTab();printf("Tache trouvee :\n");
            printTab();printf("ID : %d\n", Task[j].id);
            printTab();printf("Titre : %s\n", Task[j].titre);
            printTab();printf("Description : %s\n", Task[j].description);
            printTab();printf("Deadline : %d / %d / %d\n", Task[j].deadline.jour, Task[j].deadline.mois, Task[j].deadline.annee);
            printTab();printf("Statut : ");

            switch (Task[j].Status) {
                case 1:
                    printTab();printf("A realiser\n");
                    break;
                case 2:
                    printTab();printf("En cours de realisation\n");
                    break;
                case 3:
                    printTab();printf("Finalisee\n");
                    break;
                default:
                    printTab();printf("Statut inconnu\n");
            }
            printf("\n");

            trouve = true;
        }
    }

    if (!trouve) {
        printTab();printf("Aucune tache trouvee avec le titre \"%s\".\n", titreRecherche);
    }
}


// +++++++++++++++++++ ++++++++++++++++++++++  STATISTIQUES +++++++++++++ ++++++++++++++++ ++++++++++++++++

// ========================  afficher nombre des tache  ===================

void getNtache(int *i) {
    int cmpt = 0;

    for (int j = 0; j < *i; j++) {
        if (Task[j].Status == 1 || Task[j].Status == 2 || Task[j].Status == 3) {
            cmpt++;
        }
    }
    printTab();printf("Le nombre total de taches est : %d\n", cmpt);
}

// ==========================  list completed nd incompleted tasks =============
  
  void getCompletedandIncompletedTasks(int *i) {
    int count1 = 0;
    int count2 = 0;

    for (int j = 0; j < *i; j++) {
        if (Task[j].Status == 1 || Task[j].Status == 2) {
            count1++;
        }
        if (Task[j].Status == 3) {
            count2++;
        }
    }

    printTab();
    printf("Le nombre de taches completees : %d\n", count2);
    printTab();
    printf("Le nombre de taches incompletes : %d\n", count1);
}

// ========================== afficher Jours Restants  =============

void afficherJoursRestants(int *i) {
    time_t now;
    struct tm *local;
    int joursRestants;

    time(&now);
    local = localtime(&now);

    printTab();printf("Jours restants jusqu'au delai pour chaque tache :\n");
    

    for (int j = 0; j < *i; j++) {
        joursRestants = 0;

        // Calculer les jours restants en comparant la date limite avec la date actuelle
        joursRestants += (Task[j].deadline.annee - (local->tm_year + 1900)) * 365;
        joursRestants += (Task[j].deadline.mois - (local->tm_mon + 1)) * 30;
        joursRestants += (Task[j].deadline.jour - local->tm_mday);

        printTab();
        printf("Tâche n° : %d - %s : %d jours\n", Task[j].id, Task[j].titre, joursRestants);
    }
}
// ====================================== declarer les variable global =========

int id = 0;
   int i = 0 ;
   // nombre des taches
   int n = 0;







//================== main =========================================
int main() {
    Sas();
    todo();

    int input;

    while (1) {
        do {
            printf("\n\n\n\n");
		printf("\t\t==========================================                    ===========================================\n");
        printf("\t\t==========================================      M E N U       ===========================================\n");
        printf("\t\t==========================================                    ===========================================\n \n \n");
			printTab();printf("1  Ajouter une nouvelle tache\n\n");
			printTab();printf("2  Ajouter plusieurs nouvelles taches\n\n");
			printTab();printf("3  Afficher la liste de toutes les taches \n\n");
			printTab();printf("4  Modifier une tache\n\n");
			printTab();printf("5  Supprimer les taches par ID \n\n");
            printTab();printf("6  Rechercher les taches\n\n");
			printTab();printf("7  Statistique des taches\n\n\n");
			
			printTab();printf("0  Quiter\n\n");
            input = getInt();
        } while (input > 7 || input < 0);
        switch (input) {


            case 0:
                exit(0);
            break;




            case 1:
                AjouterTache(&i, &id, &n); // Pass i, id, and n by reference
            break;






            case 2 :
                AjouterDesTaches(&i, &id, &n);    
            break;  



            case 3:
               /* Trier les tâches par ordre alphabétique.
                Trier les tâches par deadline.
                Afficher les tâches dont le deadline est dans 3 jours ou moins.*/
               while (1)
               {
                 int choix ;
                 do
                 {
                  printTab();printf("\t=======   Lister toutes les taches ======= \n\n\n");
                  printTab();printf("1  lister toutes les taches par ordre alphabetique \n\n");
                  printTab();printf("2  lister toutes les taches  par deadline \n\n");
                  printTab();printf("3  lister toutes les taches  dont le deadline est dans 3 jours ou moins \n\n");
                  printTab();printf("0  Menu \n\n");
                  choix = getInt();
                 } while (choix > 3 || choix < 0);
                 
                      switch (choix)
                      {
                      case 1:break;
                       
                         // fonction  lister toutes les tâches  par deadline
                      case 2 :break;
                        
                          // fonction  lister toutes les tâches  dont le deadline est dans 3 jours ou moins 
                       case 3 : ListByCloseDeadline(&i); break;
                    
                        case 0 : break;
                     } 
                        if(!choix) break;
               } 
            break;  

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
                        // fonction  pour Modifier la description d'une tache
                      case 1: updateDescription(&i);
                      ;break;
                         // fonction pour Modifier le statut d’une tache
                      case 2 : updateStatus(&i) ; 
                      break;    
                          // fonction pour Modifier le deadline d’une tache
                      case 3 : updateDeadline(&i); break;
                      case 0 : break;
                       }
                        if(!choix) break;
               } 
            break;
                
            case 5: deleteById( &i, &n);break;
            case 6 :  
            
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
                 {// FONCTION DE recherche by id
                 case 1: getById(&i); break;
                   // fonction de recherche par titre
                case 2:rechercherTacheParTitre(&i);break;
                case 0: break;
                 }if(!choix) break;
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
                  printTab();printf("3  Afficher le nombre de jours restants jusqu'au delai de chaque tache.\n\n");
                  printTab();printf("0  Menu \n\n");
                  choix = getInt();
                 } while (choix > 2 || choix < 0);
                 switch (choix)
                 {
                 case 1:getNtache(&i); break;
                 case 2: getCompletedandIncompletedTasks(&i);break; 
                 case 3: afficherJoursRestants(&i);  break; 
                 case 0:break;
                 
                 }if(!choix) break;
               } break;
              


            default: error404();
                break;
        }
    }

    return 0;
}
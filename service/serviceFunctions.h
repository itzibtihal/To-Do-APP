// ajouter une tache

void AjouterTache(int *i, int *id, int *n) {
    Task[*i].id = (*id)++;
    printTab();
    printf("Entrer le titre de votre tache :\n\n ");
    printTab();
    scanf(" %[^\n]", Task[*i].titre);
    printTab();
    printf("Entrer une Description :\n\n ");
    printTab();
    scanf(" %[^\n]", Task[*i].description);
    printTab();
    printf("Entrez un Deadline (jour / mois / annee) :\n\n");
    printTab();
    scanf("%d / %d / %d", &Task[*i].deadline.jour, &Task[*i].deadline.mois, &Task[*i].deadline.annee);

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


// ajouter des taches
  void AjouterDesTaches(int *i, int *id, int *n) {
    int nombreDeTaches;
    printTab();printf("Combien de taches souhaitez-vous ajouter ? : ");
    printTab();scanf("%d", &nombreDeTaches);

    for (int j = 0; j < nombreDeTaches; j++) {
        printTab();printf("Tache # %d\n", j + 1);
        //ajouter une tâche individuelle
        AjouterTache(i, id, n);

        printTab();printf("Tâche #%d ajoutee avec succes!\n", j + 1);
        
    }
}





// afficher les taches 



void ListAll(){
     printf("Liste de toutes les taches enregistrees :\n");
    for (int j = 0; j < i; j++) {
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
 

/*  // lister par ordre alphabétique

void ListByLetters(){
       
        int result;
        toDo   c;
             

    printTab();printf("la liste des taches par ordre alphabetique : \n\n\n");

    //fonction pour mettre tout les lettres en minuscule
    for(int i = 0; Task[i].titre; i++){
     Task[i].titre = tolower(Task[i].titre);
     // comparer
       for(int j=i+1;j<n;j++){

          result = strcmp(Task[i].titre, Task[j].titre);

           if( result >0){
             c=Task[i];
             Task[i]=Task[j];
              Task[j]=c;
            }
        }
           
            // fonction pour afficher le nouveau tableau trier 
              
              
            printTab();printf("Titre : %s \n": , Task[j].titre);
            printTab(); printf("Description : %s\n", Task[j].description);
            printTab();printf("Deadline : %d-%d-%d\n", Task[j].deadline.jour, Task[j].deadline.mois, Task[j].deadline.annee);
            printTab();printf("Status : %d\n", Task[j].Status);
            printf("\n");

    }
   
  
}
*/

/*

   // lister par deadline 

 void ListByDeadline(){
       
       


 }
*/
     // lister les taches dont le deadline est dans 3jrs ou -

 void ListByCloseDeadline(){
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
    
    for (int j = 0; j < i; j++) {
        int joursRestants = (Task[j].deadline.annee - anNow) * 365 +
                            (Task[j].deadline.mois - moisNow) * 30 +
                            (Task[j].deadline.jour - dayNow);
        if (joursRestants < 4)
        {
            // affichage des jours < = 3
            printTab();printf("Tâches dont le délai est de 3 jours ou moins :\n \n");
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
        } else {
            printTab();printf(" aucune date est interieur a 3 jour !");
        }
           
   }
} 






     // modifier une tache

       // fontction qui examine si l'ID exist ou pas 

           bool idExiste(int id) {
              for (int j = 0; j < i; j++) {
                    if (Task[j].id == id) {
                      return true; // L'ID existe 
                   }
               } 
            }



     // modifier la description 
      void updateDescription(){
        // afficher les taches 
           ListAll();
         
        // entrer l' id de la tache
          int identi;
         bool result;

        do {
           printTab();printf("Entrer l'identifiant de la tache que vous voulez modifier :\n");
           printTab();scanf("%d", &identi);
           result = idExiste(identi);
           if (!result) {
              printTab();printf("L'identifiant %d n'existe pas dans le tableau. Veuillez reessayer.\n", identi);
           }
       } while (!result);

       // modifier description 
           printTab();printf("Merci de modifier votre description : \n\n");    
           printTab();scanf(" %[^\n]",Task[identi].description);
      }


 // modifier le status 

       void updateStatus(){
               // afficher les taches 
           ListAll();
         
               // entrer l' id de la tache
          int identi;
         bool result;

        do {
           printTab();printf("Entrer l'identifiant de la tache que vous voulez modifier :\n");
           printTab();scanf("%d", &identi);
           result = idExiste(identi);
           if (!result) {
              printTab();printf("L'identifiant %d n'existe pas dans le tableau. Veuillez réessayer! \n", identi);
           }
       } while (!result);

              // modifier de status 
                
             printTab();
             printf(" rappelons que les choix de status sont  :\n");
        do {
            printTab();printf("1  A realiser\n");
            printTab();printf("2  en cours de realisation\n");
            printTab();printf("3  finalisee\n");
            printTab();printf("Merci de modifier votre status : \n\n"); 
            printTab();
            scanf("%d",Task[identi].Status);
       } while (Task[identi].Status < 1 || Task[identi].Status > 3); 
      }




    // modifier le deadline 
      
        void updateDeadline(){
               // afficher les taches 
           ListAll();
         
               // entrer l' id de la tache
          int identi;
         bool result;

        do {
           printTab();printf("Entrer l'identifiant de la tache que vous voulez modifier :\n");
           printTab();scanf("%d", &identi);
           result = idExiste(identi);
           if (!result) {
              printTab();printf("L'identifiant %d n'existe pas dans le tableau. Veuillez reessayer.\n", identi);
           }
       } while (!result);

              // modifier de status 
                
             printTab();printf(" Merci d'entrer la nouvelle date :\n");
             printTab();printf("sous la forme DD / MM / YYYY: \n");
             printTab();scanf(" %d / %d / %d",Task[identi].deadline.jour,Task[identi].deadline.mois,Task[identi].deadline.annee);
      }


       

     // Suprimer 
   // delete by id 

   void deleteById(){
         // afficher les taches 
           ListAll();
         
               // entrer l' id de la tache
          int identi;
         bool result;

        do {
           printTab();printf("Entrer l'identifiant de la tache que vous voulez suprimer :\n");
           printTab();scanf("%d", &identi);
           result = idExiste(identi);
           if (!result) {
              printTab();printf("L'identifiant %d n'existe pas dans le tableau. Veuillez reessayer.\n", identi);
           }
       } while (!result);

       
       // delete 

       for(i=0;i<n;i++){
             if(Task[i].id == identi){
                 for(int j=i;j<n-1;j++){
                     Task[j]=Task[j+1];
                      n--;
                      i--;
                  }
            }
        }
   }



     // rechercher
// get by id 

void getById(){

         int identi;
         bool result;

    do {
           printTab();printf("Entrer l'identifiant de la tache que vous voulez modifier :\n");
           printTab();scanf("%d", &identi);
           result = idExiste(identi);
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






// get by titre 

void rechercherTacheParTitre() {

    char titreRecherche[50]; 
    printf("Entrez le titre de la tache que vous recherchez : ");
    scanf(" %[^\n]", titreRecherche);

    bool trouve = false;

    for (int j = 0; j < i; j++) {
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







      // statistique
// afficher nombre des tache
void getNtache(){
    int cmpt = 0 ;
    printTab();printf("le nombre totale des taches est : \n");
    if (Task[i].status==1 || Task[i].status==2 || Task[i].status==3)
    {
        cmpt++ ;
    }
    printTab();printf("%d",cmpt);
}


// afficher les taches completes et incomplete 
void getCompletedandIncompletedTasks(){
    int count1=0;
    int count2=0;
    for(i=0;i<n;i++){
        if(Task[i].status==1 || Task[i].status==2) count1++;
        if(Task[i].status==3) count2++;
    }
    printTab();printf("le nombre des taches    completes : %d \n ", count2);
    printTab();printf(" incompletes : %d \n", count1);

}
// afficher le nombre de jour restant jusqu'au délai






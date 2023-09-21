// ajouter une tache


void AjouterTache() {
    Task[i].id = id++;
    printTab();
    printf("Entrer le titre de votre tache :\n\n ");
    printTab();
    scanf(" %[^\n]", Task[i].titre);
    printTab();
    printf("Entrer une Description :\n\n ");
    printTab();
    scanf(" %[^\n]", Task[i].description);
    printTab();
    printf("Entrez un Deadline (jour / mois / annee) :\n\n");
    printTab();
    scanf("%d / %d / %d", &Task[i].deadline.jour, &Task[i].deadline.mois, &Task[i].deadline.annee);

    printTab();
    printf("Status :\n");
    int stat;
    do {
        printTab();
        printf("1  à réaliser\n");
        printTab();
        printf("2  en cours de réalisation\n");
        printTab();
        printf("3  finalisee\n");
        printTab();
        scanf("%d",&stat);
    } while (stat < 1 || stat > 3);


     if ( stat == 1)
     {
        strcpy(Task[i].Status ,"a realiser");
     }else if (stat == 2)
     {
        strcpy(Task[i].Status ,"en cours de realisation");
     }else if ( stat == 3)
     {
        strcpy(Task[i].Status,"finalisee"); 
     }
   
    i++;
}

/*

// ajouter des taches

void AjouterDesTaches() {
    int nombreDeTaches;
    printf("Combien de tâches souhaitez-vous ajouter ? ");
    scanf("%d", &nombreDeTaches);

    for (int j = 0; j < nombreDeTaches; j++) {
        AjouterTache();
    }
}


// afficher les taches 
 
  // lister par ordre alphabétique

void ListByLetters(){
       
        int result;
        toDo   c;
             

    printTab();printf("la liste des taches par ordre alphabetique : \n");

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
    }
   
   // fonction pour afficher le nouveau tableau trier 
}

   // lister par deadline 

 void ListByDeadline(){
       
       


 }

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
    printTab();printf("Tâches dont le délai est de 3 jours ou moins :\n");
    for (int j = 0; j < i; j++) {
        int joursRestants = (Task[j].deadline.annee - anNow) * 365 +
                            (Task[j].deadline.mois - moisNow) * 30 +
                            (Task[j].deadline.jour - dayNow);
        if (joursRestants < = 3)
        {
            // affichage des jours < = 3
            printTab();printf("Titre : %s \n": , Task[j].titre)
            printTab(); printf("Description : %s\n", Task[j].description);
            printTab();printf("Deadline : %d-%d-%d\n", Task[j].deadline.jour, Task[j].deadline.mois, Task[j].deadline.annee);
            printTab();printf("Status : %d\n", Task[j].Status);
            printf("\n");
        }
           
   }
} 







     // modifier une tache
 
 // modifier la description 
      void updateDescription(){
        // afficher les taches 

        // entrer l' id de la tache
        int identi ;
        do
        {
           printTab();printf("entrer l'identifiant de tache que vous voullez modifier : \n");
           printTab();scanf("%d",identi)
        } while (Task);
        

      }
 // modifier le status 
 // modifier le deadline 


     // Suprimer 
// delete by id 





     // rechercher
// get by id 
// get by titre 






      // statistique
// afficher nombre des tache
// afficher les taches completes et incomplete 
// afficher le nombre de jour restant jusqu'au délai



*/


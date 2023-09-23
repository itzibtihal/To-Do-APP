//=================================================================================== fonction de  service =============================================================

      // ++++++++++++++++++++++ ajouter une tache ++++++++++++++++
void AjouterTache(int *i, int *id, int *n) {
    Task[*i].id = (*id)++;
    printTab();printf("Entrer le titre de votre tache :\n\n ");
    printTab();scanf(" %[^\n]", Task[*i].titre);
    printTab();printf("Entrer une Description :\n\n ");
    printTab();scanf(" %[^\n]", Task[*i].description);
    printTab();printf("Entrez un Deadline (jour / mois / annee) :\n\n");
    printTab();scanf("%d / %d / %d", &Task[*i].deadline.jour, &Task[*i].deadline.mois, &Task[*i].deadline.annee);
    printTab();printf("Status :\n");
    do {
        printTab();printf("1  a realiser\n");
        printTab();printf("2  en cours de realisation\n");
        printTab();printf("3  finalisee\n");
        printTab();printf("Merci de choisir votre status : \n\n");
        printTab();scanf("%d", &Task[*i].Status);
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
        printTab();printf("Tache n  %d\n", j + 1);
        //ajouter une tache individuelle
        AjouterTache(i, id, n);

        printTab();printf("Tache n  %d ajoutee avec succes!\n", j + 1);

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
        printf("Deadline : %d /%d /%d\n", Task[j].deadline.jour, Task[j].deadline.mois, Task[j].deadline.annee);
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

//=========================== list par ordre alpha =============

void triOrdreAlpha(int *i, int *n) {
   printTab();printf("La liste des taches par ordre alphabetique :\n");
    toDo c;
    
    for (*i = 0; *i < *n - 1; (*i)++) {
        for (int j = *i + 1; j < *n; j++) {
            int result = strcmp(Task[*i].titre, Task[j].titre);
            if (result > 0) {
                c = Task[*i];
                Task[*i] = Task[j];
                Task[j] = c;
            }
        }
    }
    
    ListAll(n);
}

//========================== list by deadline =================


void ListByDeadline(int *i, int *n) {
    printTab();printf("La liste des taches par deadline : \n\n");
    toDo T;

    for (*i = 0; *i < (*n) - 1; (*i)++) {
        int result1 = (Task[*i].deadline.annee * 365) + (Task[*i].deadline.mois * 30) + (Task[*i].deadline.jour);
        for (int j = *i + 1; j < *n; j++) {
            int result2 = (Task[j].deadline.annee * 365) + (Task[j].deadline.mois * 30) + (Task[j].deadline.jour);

            if (result1 > result2) {
                T = Task[*i];
                Task[*i] = Task[j];
                Task[j] = T;
                result1 = result2; 
            }
        }
    }
    ListAll(n);
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
        int joursRestants = (Task[j].deadline.annee - anNow) * 365 +(Task[j].deadline.mois - moisNow) * 30 +(Task[j].deadline.jour - dayNow);
        if (joursRestants < 4 && joursRestants >=  0)
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
        printTab();printf("Entrer l'identifiant de la tache que vous voulez modifier :\n");
        printTab();scanf("%d", &identi);
        result = idExiste(identi, i);
        if (!result) {
            printTab();printf("L'identifiant %d n'existe pas dans le tableau. Veuillez réessayer.\n", identi);
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
        printTab();printf("Entrer l'identifiant de la tache que vous voulez modifier :\n");
        printTab();scanf("%d", &identi);
        result = idExiste(identi, i);
        if (!result) {
            printTab();printf("L'identifiant %d n'existe pas dans le tableau. Veuillez reessayer!\n", identi);
        }
    } while (!result);

    // Modifier le statut
    printTab();printf("Rappelons que les choix de statut sont :\n");
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
    // Afficher les taches
    ListAll(i);

    // Entrer l'ID de la tache à supprimer
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
    // ou bien utiliser n et afficher directement n (nombre des taches)
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
        printf("Tache n : %d - %s : %d jours\n", Task[j].id, Task[j].titre, joursRestants);
    }
}
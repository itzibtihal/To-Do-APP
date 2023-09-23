// fonction d'affichage
void Sas();
void interface();
void error404();
void todo();
void printTab();
int getInt();

// fonction de service
       // fonctions d'ajout 
void AjouterTache(int *i, int *id, int *n);
void AjouterDesTaches(int *i, int *id, int *n);
       //fonctions pour lister
void ListAll(int *i);
void triOrdreAlpha(int *i, int *n);
void ListByDeadline(int *i, int *n);
void ListByCloseDeadline(int *i);
       // fonction return si l ' id existe ou pas
bool idExiste(int id, int *i);
       //fonctions de modification
void updateDescription(int *i);
void updateStatus(int *i);
void updateDeadline(int *i);
       // fonction de suppression par id
void deleteById(int *i, int *n);
       //  fonctions de recherche
void getById(int *i);
void rechercherTacheParTitre(int *i);
       // fonctions de statistique 
void getNtache(int *i);
void getCompletedandIncompletedTasks(int *i);
void afficherJoursRestants(int *i); 

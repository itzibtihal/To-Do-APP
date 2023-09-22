// fonction d'affichage
void Sas();
void interface();
void error404();
void todo();
void printTab();
int getInt();

// fonction de service
       // fonctions d'ajout 
void AjouterTache();
void AjouterDesTaches();
       //fonctions pour lister
void ListAll();
void ListByCloseDeadline();
       // fonction return si l ' id existe ou pas
bool idExiste(int id);
       //fonctions de modification
void updateDescription();
void updateStatus();
void updateDeadline();
       // fonction de suppression par id
void deleteById();
       //  fonctions de recherche
void getById();
void rechercherTacheParTitre();
       // fonctions de statistique 
void getNtache();
void getCompletedandIncompletedTasks();
void getDaysToDeadline(); 

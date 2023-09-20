// date structure 
typedef struct date{
 	int jour;
 	int mois;
 	int annee;
}date;



// les valeurs possible de status 
typedef enum Status Status;
enum Statuts {
    Aréaliser = 1 ,EncoursDeRéalisation = 2 , Finalisée = 3;
};



// to  do structure 
typedef struct toDo
{
    int id ;
    char titre [50];
    char description[]={};
    struct date deadline ;
    enum Status Status;
}toDo;
 
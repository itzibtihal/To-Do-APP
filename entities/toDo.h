
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


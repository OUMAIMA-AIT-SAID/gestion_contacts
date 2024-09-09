#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX 50
#define MAX_NUM  15

//structure Contact 
typedef struct {
    char name[MAX];
    char phone[MAX_NUM];
    char email[MAX];
} Contact;

Contact contacts[MAX_CONTACTS];
int count = 0;
//fonction d'ajouter

void ajouter_contact(int a) {
    char nom[MAX];
    char phone[MAX_NUM];
    char email[MAX];

    if (count + a > MAX_CONTACTS) {
        printf("Le carnet de contacts est plein.\n");
        return;
    }

    for (int j = 0; j < a; j++) {
        int exists = 0;

        printf("Entrez le nom du contact: ");
        scanf("%s", nom);
        printf("Entrez le numéro de téléphone: ");
        scanf("%s", phone);
        printf("Entrez l'email: ");
        scanf("%s", email);

        // si le contact déjà
        for (int i = 0; i < count; i++) {
            if (strcmp(contacts[i].name, nom) == 0) {
                printf("Le contact %s existe déjà.\n", nom);
                exists = 1;
                break;
            }
        }

        if (!exists) {
            Contact nouv_contact;
            strcpy(nouv_contact.name, nom);
            strcpy(nouv_contact.phone, phone);
            strcpy(nouv_contact.email, email);
            contacts[count] = nouv_contact;
            count++;
            printf("Contact ajouté.\n");
        }
    }
}
    
    
   
 
    

//modifier_contact
//----------------------------------------------------------------------
 
void modifier_contact() {
    char name[MAX];
    int i;

    printf("Entrez le nom du contact pour modifier: ");
    scanf(" %s", name);

    for (i = 0; i <count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Entrez le nouveau num de tele: ");
            scanf(" %s", contacts[i].phone);

            printf("Entre la nouvelle  email: ");
            scanf(" %s", contacts[i].email);
            



            printf("Contact modifier avec succès.\n");
            return;
        }
    }
    printf("Contact non trouve.\n");
}

//supprimer_contact
void supprimer_contact( int supp) {
    char name[MAX];
    int i,existe=-1;

    
   if (supp ==1)
   {
    printf("Entrez le nom du contact pour supprimer: ");
    scanf(" %s", name);
    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            
            for (int j=i; j < count - 1; j++) {
            contacts[j] = contacts[j + 1];
            
        }
        count--;
        printf("Contact supprimer \n");
        return;
        }
        printf("pas de Contact \n"); 
    }       
   }  
   else if (supp  == 0)
   {
    printf("non efectuer"); 
   }
   
   
}

//rechercher_contact
//------------------------------------------------------------------------------------------------
void rechercher_contact() {
    char name[MAX];
    int i;

    printf("Entrez le nom du contact pour rechercher: ");
    scanf(" %s", name);

    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("nom: %s\n", contacts[i].name);
            printf("Tele: %s\n", contacts[i].phone);
            printf("email: %s\n", contacts[i].email);
            return;
        }
    }
    printf("Contact non trouvé.\n");
}

    
   //afficher_contacts
   //_______________________________________________________________________________________________
void afficher_contact(int tri) {
    if (count == 0) {
        printf("Aucun contact à afficher.\n");
        return;
    }

    // Tri des contacts 

    // Tri croissant par nom
    if (tri == 1) { 
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (strcmp(contacts[i].name, contacts[j].name) > 0) {
                    Contact temp = contacts[i];
                    contacts[i] = contacts[j];
                    contacts[j] = temp;
                }
            }
        }
    } 
    // Tri décroissant par nom
    else if (tri == 3) { 
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (strcmp(contacts[i].name, contacts[j].name) < 0) {
                    Contact temp = contacts[i];
                    contacts[i] = contacts[j];
                    contacts[j] = temp;
                }
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("Nom: %s\n", contacts[i].name);
        printf("Téléphone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
        printf("----------------------\n");
    }
}
//foonction  main
//____________________-----------------------------------------------------------------------

int main() {
    int choix;
    int supp_choix;
    int tri_choix;

    do {
        printf("1. Ajouter un contact\n");
        printf("2. Modifier un contact\n");
        printf("3. Supprimer un contact\n");
        printf("4. Rechercher un contact\n");
        printf("5. Afficher tous les contacts\n");
        printf("6. Quitter\n");
        printf("ChoisisseR une option: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:{
            int number;
            printf("combien de contact vous avez ajouter?");
            scanf("%d",&number);
            ajouter_contact(number);
                break;
            }
            case 2:
                modifier_contact();
                break;
            case 3:
               printf("SI vous voullez vraiment supprimer ce contact tapper 1 ?");
               scanf("%d",&supp_choix);
                 supprimer_contact(supp_choix);
                break;
            case 4:
                rechercher_contact();
                break;
            case 5:
                

                printf("1. Afficher tri croissant\n");
                printf("2. Afficher sans tri\n");
                printf("3. Afficher tri décroissant\n");
                printf("Choisissez un type de tri: ");
                scanf("%d",&tri_choix);
                afficher_contact(tri_choix);
                break;
            
                
            case 6:
                printf("mrc\n");
                break;
            default:
                printf("Option invalide. .\n");
        }

    } while (choix != 6);

    return 0;
}
#include "toFile.h"
#include "fromFile.h"


void freeMemory(tGarage*, short unsigned int*, tMechanic*, unsigned int*);
void freeMechanicMemory(tMechanic*, unsigned int*);
void freeMaterialMemory(tMaterial*, unsigned int*);
void SecondaryMenu();

int main(void) {
    tGarage* garage = NULL;
    short unsigned int currentNumGarages = 0;
    tMechanic* mechanic = NULL;
    unsigned int currentNumOfMechanics = 0, i = 0;
    int searchResult = 0;
    char choice;
    bool z;
    choice = ' ';
    garage = fromFile_importTGarage(garage, &currentNumGarages);
    garage = fromFile_importTMaterial(garage, currentNumGarages);
    mechanic = fromFile_importTMechanic(mechanic, &currentNumOfMechanics);
    
    do {
        
        printf("\n\n(I)nserir elementos");
        printf("\n(P)esquisar elementos");
        printf("\n(L)istar elementos");
        printf("\n(E)liminar elementos");
        printf("\n(A)lterar elementos");
        printf("\n(D)esativar/Ativar oficina");
        printf("\n(S)air");
        printf("\nSelecione opcao: ");
        

        scanf("%c", &choice);
        ClearBuffer();
        choice = tolower(choice);
         
        switch (choice) {

            case 'i':
                system(CLEAR_CMD);
                SecondaryMenu();
                scanf("%c", &choice);
                ClearBuffer();

                switch (choice) {
                    case '1':
                        garage = InsertGarage(garage, &currentNumGarages);
                       
                        break;
                    case '2':

                        mechanic = InsertMechanic(mechanic, &currentNumOfMechanics, garage, currentNumGarages);
                        break;
                    case '3':
                        printf("\nSelecione a oficina do material que quer adicionar");
                        searchResult = ChooseGarage(garage, currentNumGarages);
                        if (searchResult != -1) {

                            garage[searchResult].material = material_add(garage[searchResult].material,
                                    &(garage[searchResult].numMaterial), material_fillMaterial(), true);

                        } else {
                            printf("\nOficina nao encontrada");
                        }
                        break;
                    default:
                        printf("Opção '%c' inválida", choice);
                        break;
                }
                break;

            case 'p':SecondaryMenu();
                system(CLEAR_CMD);
                SecondaryMenu();
                scanf("%c", &choice);
                ClearBuffer();
                switch (choice) {
                    case '1':
                        searchResult = ChooseGarage(garage, currentNumGarages);
                        ShowGarage(garage, searchResult);
                        break;
                    case '2':

                        searchResult = SearchMechanic(mechanic, currentNumOfMechanics, NULL);
                        break;
                    case '3':
                        printf("\nSelecione a oficina do material que quer pesquisar");
                        searchResult = ChooseGarage(garage, currentNumGarages);
                        if (searchResult > -1) {

                            searchResult = material_searchMaterial(garage[searchResult].material, garage[searchResult].numMaterial, NULL);


                        } else {
                            printf("\nOficina nao encontrada");
                        }
                        break;
                    default:
                        printf("Opção '%c' inválida", choice);
                        break;
                }
                break;

            case 'l':SecondaryMenu();
           
                system(CLEAR_CMD);
                SecondaryMenu();

                scanf("%c", &choice);
                ClearBuffer();
                switch (choice) {
                    case '1':
                       
                        ListGarage(garage, currentNumGarages);
                        break;
                    case '2':

                        ShowAllMechanic(mechanic, currentNumOfMechanics);
                        break;
                    case '3':
                        printf("\nSelecione a oficina dos materiais que quer listar");
                        searchResult = ChooseGarage(garage, currentNumGarages);
                        if (searchResult > -1) {

                            material_listAll(garage[searchResult].material, garage[searchResult].numMaterial);

                        } else {
                            printf("\nOficina nao encontrada");
                        }
                        break;
                    default:
                        printf("Opção '%c' inválida", choice);
                        break;
                }


                break;

            case 'e':SecondaryMenu();
                system(CLEAR_CMD);
                SecondaryMenu();
                scanf("%c", &choice);
                ClearBuffer();

                switch (choice) {
                    case '1':
                        garage = DeleteGarage(garage, &currentNumGarages);
                        break;
                    case '2':
                        mechanic = RemoveMechanic(mechanic, &currentNumOfMechanics);
                        break;
                    case '3':
                        printf("\nSelecione a oficina do material que quer eliminar");
                        searchResult = ChooseGarage(garage, currentNumGarages);
                        if (searchResult != -1) {

                            garage[searchResult].material = material_remove(garage[searchResult].material,
                                    &(garage[searchResult].numMaterial));

                        } else {
                            printf("\nOficina nao encontrada");
                        }
                        break;
                    default:
                        printf("Opção '%c' inválida", choice);
                        break;
                }

                break;

            case 'a':SecondaryMenu();
            system(CLEAR_CMD);
                SecondaryMenu();
                scanf("%c", &choice);
                ClearBuffer();

                switch (choice) {
                    case '1':
                        garage = EditGarage(garage, currentNumGarages);
                        break;
                    case '2':
                        mechanic = EditMechanic(mechanic, currentNumOfMechanics, garage, currentNumGarages);
                        break;
                    case '3':
                        printf("\nSelecione a oficina do material que quer editar");
                        searchResult = ChooseGarage(garage, currentNumGarages);
                        if (searchResult != -1) {

                            garage[searchResult].material = material_replace(garage[searchResult].material,
                                    garage[searchResult].numMaterial);

                        } else {
                            printf("\nOficina nao encontrada");
                        }
                        break;
                    default:
                        printf("Opção '%c' inválida", choice);
                        break;
                }

         
            
                break;

            case 'd':
                printf("\nSelecione a oficina do material que quer editar");
                        searchResult = ChooseGarage(garage, currentNumGarages);
                        if (searchResult != -1) {
                            garage[searchResult].enable = !garage[searchResult].enable;
                         } else {
                            printf("\nOficina nao encontrada");
                        }
                break;

            default: if (choice != 's') {
                    printf("Opção '%c' inválida", choice);
                }else {
                toFile_exportTGarage(garage, currentNumGarages);
                toFile_exportTMaterial(garage, currentNumGarages);
                toFile_exportTMechanic(mechanic, currentNumOfMechanics);
                freeMemory(garage, &currentNumGarages, mechanic, &currentNumOfMechanics);
                }
                break;
        }
    } while (choice != 's');
    //freeMemory(garage, &numGarage, mechanic, &numMechanic);
    return 0;
}

void SecondaryMenu() {
    printf("\n1 - Oficina");
    printf("\n2 - Mecanico");
    printf("\n3 - Material");
    printf("\nSelecione opcao: ");
}

void freeMemory(tGarage* garage, short unsigned int* numGarage, tMechanic* mechanic, unsigned int* numMechanic) {
    for ((*numGarage) -= 1; (*numGarage)<-1; (*numGarage)--) {
        freeMaterialMemory(garage[(*numGarage)].material, &garage[(*numGarage)].numMaterial);
    }
    free(garage);
    freeMechanicMemory(mechanic, numMechanic);
}

void freeMaterialMemory(tMaterial* material, unsigned int* nMaterial) {
    for ((*nMaterial) -= 1; (*nMaterial)<-1; (*nMaterial)--) {
        free(material[(*nMaterial)].denomination);
    }
    free(material);
}

void freeMechanicMemory(tMechanic* mechanic, unsigned int* nMechanic) {
    for ((*nMechanic) -= 1; (*nMechanic)<-1; (*nMechanic)--) {
        free(mechanic[(*nMechanic)].name);
        free(mechanic[(*nMechanic)].shift);
    }
    free(mechanic);
}
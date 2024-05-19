//Gonzalez Lopez Brian Joseph
//Guerra Vazquez Jose Luis
//Torres Buenrostro Zaira Patricia
//19-MAYO-2023

#include "agencia_viajes.h"

int main() {
    inicializarViajes();
    int opcion;
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Buscar un viaje\n");
        printf("2. Buscar un pasajero\n");
        printf("3. Mostrar lista de pasajeros por viaje\n");
        printf("4. Mostrar viajes incompletos\n");
        printf("5. Capturar pasajeros\n");
        printf("6. Cancelar pasajero\n");
        printf("7. Mostrar datos de un pasajero\n");
        printf("8. Modificar datos de un pasajero\n");
        printf("9. Generar lista de pasajeros\n");
        printf("0. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1: {
                mostrarMenuViajes();
                buscarViaje();
                break;
            }
            case 2: {
                char nombre[50];
                printf("Ingrese el nombre del pasajero: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strlen(nombre) - 1] = '\0';
                mostrarDatosPasajero(nombre);
                break;
            }
            case 3: {
                mostrarMenuViajes();
                int viaje;
                printf("Seleccione el numero del viaje: ");
                scanf("%d", &viaje);
                viaje--;
                mostrarListaPasajeros(viaje);
                break;
            }
            case 4: {
                int porcentaje;
                printf("Ingrese el porcentaje minimo de pasajeros: ");
                scanf("%d", &porcentaje);
                mostrarViajesIncompletos(porcentaje);
                break;
            }
            case 5: {
                capturarPasajero();
                break;
            }
            case 6: {
                cancelarPasajero();
                break;
            }
            case 7: {
                char nombre[50];
                printf("Ingrese el nombre del pasajero: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strlen(nombre) - 1] = '\0';
                mostrarDatosPasajero(nombre);
                break;
            }
            case 8: {
                char nombre[50];
                printf("Ingrese el nombre del pasajero: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strlen(nombre) - 1] = '\0';
                modificarDatosPasajero(nombre);
                break;
            }
            case 9: {
                generarListaPasajeros();
                break;
            }
            case 0: {
                printf("Fin del programa.¡Hasta luego!\n");
                break;
            }
            default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}

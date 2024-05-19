//Gonzalez Lopez Brian Joseph
//Guerra Vazquez Jose Luis
//Torres Buenrostro Zaira Patricia
//19-MAYO-2023


#ifndef AGENCIA_VIAJES_H_INCLUDED
#define AGENCIA_VIAJES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VIAJES 8
#define MAX_PASAJEROS 40

typedef struct {
    char nombre[50];
    char fechaNacimiento[11];
    char rfc[14];
    char telefono[15];
    char direccion[100];
    int edad;
    int viaje;
    int asiento;
    int pagoCompleto;
    char fechaRegistro[11];
} Pasajero;

typedef struct {
    char destino[50];
    char fecha[11];
    int costo;
    int asientosDisponibles;
    Pasajero pasajeros[MAX_PASAJEROS];
} Viaje;

Viaje viajes[MAX_VIAJES];

void inicializarViajes() {
    strcpy(viajes[0].destino, "Playa platanitos");
    strcpy(viajes[0].fecha, "26 de enero");
    viajes[0].costo = 720;
    viajes[0].asientosDisponibles = MAX_PASAJEROS;

    strcpy(viajes[1].destino, "Pelicano Borregon");
    strcpy(viajes[1].fecha, "12 de febrero");
    viajes[1].costo = 580;
    viajes[1].asientosDisponibles = MAX_PASAJEROS;

    strcpy(viajes[2].destino, "Santa Maria del Oro");
    strcpy(viajes[2].fecha, "19 de febrero");
    viajes[2].costo = 700;
    viajes[2].asientosDisponibles = MAX_PASAJEROS;

    strcpy(viajes[3].destino, "Mariposa Monarca");
    strcpy(viajes[3].fecha, "25 de febrero");
    viajes[3].costo = 950;
    viajes[3].asientosDisponibles = MAX_PASAJEROS;

    strcpy(viajes[4].destino, "Tequila");
    strcpy(viajes[4].fecha, "26 de febrero");
    viajes[4].costo = 500;
    viajes[4].asientosDisponibles = MAX_PASAJEROS;

    strcpy(viajes[5].destino, "El Manto");
    strcpy(viajes[5].fecha, "26 de marzo");
    viajes[5].costo = 780;
    viajes[5].asientosDisponibles = MAX_PASAJEROS;

    strcpy(viajes[6].destino, "Los Ayala");
    strcpy(viajes[6].fecha, "26 de marzo");
    viajes[6].costo = 720;
    viajes[6].asientosDisponibles = MAX_PASAJEROS;

    strcpy(viajes[7].destino, "Feria de la Pitaya");
    strcpy(viajes[7].fecha, "14 de mayo");
    viajes[7].costo = 550;
    viajes[7].asientosDisponibles = MAX_PASAJEROS;

}

void sugerirViajesAlAzar(int cantidad) {
    int viaje;
    printf("Otras opciones de viaje al azar:\n");
    srand(time(NULL));

    int viajesSugeridos = 0;
    int viajesIndices[3];
    while (viajesSugeridos < cantidad) {
        int indiceViaje = rand() % MAX_VIAJES;
        if (viajes[indiceViaje].asientosDisponibles > 0) {
            viajesIndices[viajesSugeridos] = indiceViaje;
            printf("%d. %s - %s\n", viajesSugeridos + 1, viajes[indiceViaje].destino, viajes[indiceViaje].fecha);
            viajesSugeridos++;
        }
    }
    int seleccion;
    printf("Seleccione uno de los viajes sugeridos (1-3): ");
    scanf("%d", &seleccion);
    int asiento;
        do {
            printf("Seleccione el numero de asiento (1-%d): ", MAX_PASAJEROS);
            scanf("%d", &asiento);

            if (viajes[viaje].pasajeros[asiento - 1].asiento != 0) {
                printf("El asiento seleccionado ya esta ocupado. Por favor, elija otro.\n");
            }

        } while (viajes[viaje].pasajeros[asiento - 1].asiento != 0);

}

void mostrarMenuViajes() {
    printf("Viajes disponibles:\n");
    for (int i = 0; i < MAX_VIAJES; i++) {
        printf("%d. %s - %s\n", i + 1, viajes[i].destino, viajes[i].fecha);
    }
}

void buscarViaje() {
    char destino[50];
    printf("Ingrese el destino del viaje a buscar: ");
    fgets(destino, sizeof(destino), stdin);
    destino[strlen(destino) - 1] = '\0';

    int encontrado = 0;

    for (int i = 0; i < MAX_VIAJES; i++) {
        if (strcmp(viajes[i].destino, destino) == 0) {
            printf("Viaje encontrado:\n");
            printf("Destino: %s\n", viajes[i].destino);
            printf("Fecha: %s\n", viajes[i].fecha);
            printf("Costo: %d\n", viajes[i].costo);
            printf("Asientos disponibles: %d\n", viajes[i].asientosDisponibles);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontro un viaje con el destino especificado.\n");
    }
}

void mostrarListaPasajeros(int viaje) {
    printf("Lista de pasajeros para el viaje a %s - %s:\n", viajes[viaje].destino, viajes[viaje].fecha);
    printf("Nombre\t\tAsiento\n");
    for (int i = 0; i < MAX_PASAJEROS; i++) {
        if (viajes[viaje].pasajeros[i].asiento != 0) {
            printf("%s\t%d\n", viajes[viaje].pasajeros[i].nombre, viajes[viaje].pasajeros[i].asiento);
        }
    }
}

int obtenerPorcentajePasajeros(int viaje) {
    int totalPasajeros = MAX_PASAJEROS - viajes[viaje].asientosDisponibles;
    return (totalPasajeros * 100) / MAX_PASAJEROS;
}

void mostrarViajesIncompletos(int porcentaje) {
    printf("Viajes con menos del %d%% de pasajeros:\n", porcentaje);
    for (int i = 0; i < MAX_VIAJES; i++) {
        int porcentajePasajeros = obtenerPorcentajePasajeros(i);
        if (porcentajePasajeros < porcentaje) {
            printf("%s - %s (%d%%)\n", viajes[i].destino, viajes[i].fecha, porcentajePasajeros);
        }
    }
}

void capturarPasajero() {
    char nombre[50], fechaNacimiento[11], rfc[14], telefono[15], direccion[100], fechaRegistro[11];
    int edad, viaje, pagoCompleto;

    printf("Ingrese el nombre del pasajero: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strlen(nombre) - 1] = '\0';
    fflush(stdin);

    printf("Ingrese la fecha de nacimiento del pasajero (DD/MM/AAAA): ");
    fgets(fechaNacimiento, sizeof(fechaNacimiento), stdin);
    fechaNacimiento[strlen(fechaNacimiento) - 1] = '\0';
    fflush(stdin);

    printf("Ingrese el RFC del pasajero: ");
    fgets(rfc, sizeof(rfc), stdin);
    rfc[strlen(rfc) - 1] = '\0';
    fflush(stdin);

    printf("Ingrese el telefono del pasajero: ");
    fgets(telefono, sizeof(telefono), stdin);
    telefono[strlen(telefono) - 1] = '\0';

    printf("Ingrese la direccion del pasajero: ");
    fgets(direccion, sizeof(direccion), stdin);
    direccion[strlen(direccion) - 1] = '\0';
    fflush(stdin);

    printf("Ingrese la edad del pasajero: ");
    scanf("%d", &edad);
    fflush(stdin);

    mostrarMenuViajes();

    printf("Seleccione el numero del viaje: ");
    scanf("%d", &viaje);
    viaje--;


    if (viajes[viaje].asientosDisponibles == 0) {
        printf("No hay asientos disponibles en este viaje. A continuacion, se muestran 3 opciones al azar:\n");
        printf("\n");

        sugerirViajesAlAzar(3);

    }
    else {

        int asiento;
        do {
            printf("Seleccione el numero de asiento (1-%d): ", MAX_PASAJEROS);
            scanf("%d", &asiento);


            if (viajes[viaje].pasajeros[asiento - 1].asiento != 0) {
                printf("El asiento seleccionado ya esta ocupado. Por favor, elija otro.\n");
            }

        } while (viajes[viaje].pasajeros[asiento - 1].asiento != 0);

        fflush(stdin);
        printf("Ingrese la fecha de registro (DD/MM/AAAA): ");
        fgets(fechaRegistro, sizeof(fechaRegistro), stdin);
        fechaRegistro[strlen(fechaRegistro) - 1] = '\0';
        fflush(stdin);

        strcpy(viajes[viaje].pasajeros[asiento - 1].nombre, nombre);
        strcpy(viajes[viaje].pasajeros[asiento - 1].fechaNacimiento, fechaNacimiento);
        strcpy(viajes[viaje].pasajeros[asiento - 1].rfc, rfc);
        strcpy(viajes[viaje].pasajeros[asiento - 1].telefono, telefono);
        strcpy(viajes[viaje].pasajeros[asiento - 1].direccion, direccion);
        strcpy(viajes[viaje].pasajeros[asiento - 1].fechaRegistro, fechaRegistro);

        viajes[viaje].pasajeros[asiento - 1].edad = edad;
        viajes[viaje].pasajeros[asiento - 1].asiento = asiento;
        viajes[viaje].pasajeros[asiento - 1].pagoCompleto = pagoCompleto;

        viajes[viaje].asientosDisponibles--;
        printf("Pasajero registrado exitosamente.\n");
    }
}

void cancelarPasajero() {
    char nombre[50];

    printf("Ingrese el nombre del pasajero a cancelar: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strlen(nombre) - 1] = '\0';

    for (int i = 0; i < MAX_VIAJES; i++) {
        for (int j = 0; j < MAX_PASAJEROS && j < MAX_PASAJEROS; j++) {
            if (strcmp(viajes[i].pasajeros[j].nombre, nombre) == 0) {
                viajes[i].pasajeros[j].asiento = 0;
                viajes[i].asientosDisponibles++;
                printf("Pasajero cancelado exitosamente.\n");
                return;
            }
        }
    }

    printf("No se encontró al pasajero especificado.\n");
}

void mostrarDatosPasajero(char* nombre);
void mostrarDatosPasajero(char* nombre) {
    printf("Datos del pasajero:\n");
    for (int i = 0; i < MAX_VIAJES; i++) {
        for (int j = 0; j < MAX_PASAJEROS; j++) {
            if (strcmp(viajes[i].pasajeros[j].nombre, nombre) == 0) {

                printf("Nombre: %s\n", viajes[i].pasajeros[j].nombre);
                printf("Fecha de nacimiento: %s\n", viajes[i].pasajeros[j].fechaNacimiento);
                printf("RFC: %s\n", viajes[i].pasajeros[j].rfc);
                printf("Telefono: %s\n", viajes[i].pasajeros[j].telefono);
                printf("Direccion: %s\n", viajes[i].pasajeros[j].direccion);
                printf("Edad: %d\n", viajes[i].pasajeros[j].edad);
                printf("Viaje al que asistira: %s - %s\n", viajes[i].destino, viajes[i].fecha);
                printf("Asiento: %d\n", viajes[i].pasajeros[j].asiento);
                printf("Pago completo: %s\n", viajes[i].pasajeros[j].pagoCompleto ? "Sí" : "No");
                printf("Fecha de registro: %s\n", viajes[i].pasajeros[j].fechaRegistro);
                return;
            }
        }
    }

    printf("No se encontro al pasajero especificado.\n");
}

void modificarDatosPasajero(char* nombre) {
    for (int i = 0; i < MAX_VIAJES; i++) {
        for (int j = 0; j < MAX_PASAJEROS; j++) {
            if (strcmp(viajes[i].pasajeros[j].nombre, nombre) == 0) {
                printf("Seleccione el dato a modificar:\n");
                printf("1. Nombre\n");
                printf("2. Fecha de nacimiento\n");
                printf("3. RFC\n");
                printf("4. Telefono\n");
                printf("5. Direccion\n");
                printf("6. Edad\n");
                printf("7. Viaje al que asistira\n");
                printf("8. Asiento\n");
                printf("9. Pago completo\n");
                printf("Ingrese el numero de la opcion: ");
                int opcion;
                scanf("%d", &opcion);
                getchar();

                switch (opcion) {
                    case 1: {
                        printf("Ingrese el nuevo nombre: ");
                        fgets(viajes[i].pasajeros[j].nombre, sizeof(viajes[i].pasajeros[j].nombre), stdin);
                        viajes[i].pasajeros[j].nombre[strlen(viajes[i].pasajeros[j].nombre) - 1] = '\0';
                        printf("El nombre se ha modificado exitosamente.\n");
                        break;
                    }
                    case 2: {
                        printf("Ingrese la nueva fecha de nacimiento (DD/MM/AAAA): ");
                        fgets(viajes[i].pasajeros[j].fechaNacimiento, sizeof(viajes[i].pasajeros[j].fechaNacimiento), stdin);
                        viajes[i].pasajeros[j].fechaNacimiento[strlen(viajes[i].pasajeros[j].fechaNacimiento) - 1] = '\0';
                        printf("La fecha de nacimiento se ha modificado exitosamente.\n");
                        break;
                    }
                    case 3: {
                        printf("Ingrese el nuevo RFC: ");
                        fgets(viajes[i].pasajeros[j].rfc, sizeof(viajes[i].pasajeros[j].rfc), stdin);
                        viajes[i].pasajeros[j].rfc[strlen(viajes[i].pasajeros[j].rfc) - 1] = '\0';
                        printf("El RFC se ha modificado exitosamente.\n");
                        break;
                    }
                    case 4: {
                        printf("Ingrese el nuevo telefono: ");
                        fgets(viajes[i].pasajeros[j].telefono, sizeof(viajes[i].pasajeros[j].telefono), stdin);
                        viajes[i].pasajeros[j].telefono[strlen(viajes[i].pasajeros[j].telefono) - 1] = '\0';
                        printf("El telefono se ha modificado exitosamente.\n");
                        break;
                    }
                    case 5: {
                        printf("Ingrese la nueva direccion: ");
                        fgets(viajes[i].pasajeros[j].direccion, sizeof(viajes[i].pasajeros[j].direccion), stdin);
                        viajes[i].pasajeros[j].direccion[strlen(viajes[i].pasajeros[j].direccion) - 1] = '\0';
                        printf("La direccion se ha modificado exitosamente.\n");
                        break;
                    }
                    case 6: {
                        printf("Ingrese la nueva edad: ");
                        scanf("%d", &viajes[i].pasajeros[j].edad);
                        getchar();  // Consumir el salto de línea
                        printf("La edad se ha modificado exitosamente.\n");
                        break;
                    }
                    case 7: {
                        mostrarMenuViajes();
                        printf("Seleccione el numero del nuevo viaje: ");
                        scanf("%d", &viajes[i].pasajeros[j].viaje);
                        viajes[i].pasajeros[j].viaje--;  // Ajustar el índice del array
                        printf("El viaje al que asistira se ha modificado exitosamente.\n");
                        break;
                    }
                    case 8: {
                        int nuevoAsiento;
                        do {
                            printf("Seleccione el nuevo numero de asiento (1-%d): ", MAX_PASAJEROS);
                            scanf("%d", &nuevoAsiento);

                            if (viajes[i].pasajeros[nuevoAsiento - 1].asiento != 0) {
                                printf("El asiento seleccionado ya esta ocupado. Por favor, elija otro.\n");
                            }
                        } while (viajes[i].pasajeros[nuevoAsiento - 1].asiento != 0);

                        viajes[i].pasajeros[j].asiento = 0;

                        viajes[i].pasajeros[j].asiento = nuevoAsiento;
                        printf("El asiento se ha modificado exitosamente.\n");
                        break;
                    }
                    case 9: {
                        printf("Ingrese si el pago está completo (1: Sí, 0: No): ");
                        scanf("%d", &viajes[i].pasajeros[j].pagoCompleto);
                        getchar();  // Consumir el salto de línea
                        printf("El estado de pago se ha modificado exitosamente.\n");
                        break;
                    }
                    default:
                        printf("Opcion invalida.\n");
                        break;
                }

                return;
            }
        }
    }

    printf("No se encontro al pasajero especificado.\n");
}



void generarListaPasajeros() {
    for (int i = 0; i < MAX_VIAJES; i++) {
        printf("Lista de pasajeros para el viaje %d (%s - %s):\n", i + 1, viajes[i].destino, viajes[i].fecha);
        printf("-------------------------------\n");

        int contador = 0;

        for (int j = 0; j < MAX_PASAJEROS; j++) {
            if (viajes[i].pasajeros[j].asiento != 0) {
                printf("Asiento %d: %s\n", viajes[i].pasajeros[j].asiento, viajes[i].pasajeros[j].nombre);
                contador++;
            }
        }

        if (contador == 0) {
            printf("No se han registrado pasajeros para este viaje.\n");
        }

        printf("-------------------------------\n\n");
    }
}


#endif // AGENCIA_VIAJES_H_INCLUDED

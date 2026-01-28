#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int version;
} Hijo;

typedef struct {
    int id;
    int numHijos;
    Hijo hijos[20];
} Padre;

Padre BaseDatosPadre;

void PedirDatosHijos();
void PedirDatosDimension(int *x, int *y, int *f_x);
int GeneradorID();
void MostrarResultado(int x, int y, int f_x, int version);
void Resumen(int id, int numHijos, int version);

int main() {
    srand(time(NULL));

    printf("Hola somos HighCap y esta es nuestra aplicacion que analiza cada caso para ver si sus hijos tienen altas capacidades.\n");
    printf("Sus hijos tienen entre 11 y 13 años? (Si = 1, No = 0) ");
    int verificacion;
    scanf("%d", &verificacion);

    if (verificacion == 1) {
        int id , numHijos, version;
        PedirDatosHijos();

        BaseDatosPadre.id = GeneradorID();
        printf("Su ID es %d\n", BaseDatosPadre.id);
        for (int i = 0; i < BaseDatosPadre.numHijos; i++) {
            int x, y, f_x;
            PedirDatosDimension(&x, &y, &f_x);
            MostrarResultado(x, y, f_x, BaseDatosPadre.hijos[i].version);   
        }
        Resumen(id, numHijos, version);
    } else {
        printf("No podemos deducir si su hijo tiene altas capacidades.\n");
    }

    return 0;
}

void PedirDatosHijos() {
    printf("Cuantos hijos desea registrar? ");
    scanf("%d", &BaseDatosPadre.numHijos);

    for (int i = 0; i < BaseDatosPadre.numHijos; i++) {
        printf("Desea pagar por el hijo %d ? (Si = 1, No = 0) ", i + 1);
        scanf("%d", &BaseDatosPadre.hijos[i].version);
    }
}

void PedirDatosDimension(int *x, int *y, int *f_x) {
    printf("Cual es el ancho del craneo de su hijo en (cm)? ");
    scanf("%d", x);

    printf("Cual es el largo del craneo de su hijo en (cm)? ");
    scanf("%d", y);

    *f_x = (*x) * (*x) - 2; // Asumiendo que esta es la formula deseada
}

int GeneradorID() {
    return rand() % 1000 + 1;
}

void MostrarResultado(int x, int y, int f_x, int version){
    if (version == 1)
    {
        if (y >= f_x  && f_x < 5)
        {
            printf("Su hijo tiene altas capacidades con un 95 %% de certeza. \n");
            printf("###########################################################\n");

        } else
        {
            printf("Su hijo no tiene altas capacidades. \n");
            printf("###########################################################\n");
        }
        
        
    } else
    {
        if (y >= f_x )
        {
            printf("Su hijo tiene altas capacidades con un 70 %% de certeza. \n");
            printf("###########################################################\n");
            printf("Quiere probar la versionde pago para asegurar el resultado? (Si = 1, No = 0) \n");
            int asegurarse;
            scanf("%d", &asegurarse);
            
            if (asegurarse == 1)
            {
                if (y >= f_x  && f_x < 5)
                {
                    printf("Su hijo tiene altas capacidades con un 95 %% de certeza. \n");
                    printf("###########################################################\n");
                } else
                {
                    printf("Su hijo no tiene altas capacidades. \n");
                    printf("###########################################################\n");

                }

            } else
            {
                printf("Gracias por utilizar nuestros servicion. \n");
            }
            
            
        } else
        {
            printf("Su hijo no tiene altas capacidades. \n");
        }
    } 
}

void Resumen(int id, int numHijos, int version){
    printf("Su ID es : %d\n", BaseDatosPadre.id);
    printf("Tiene %d hijos \n", BaseDatosPadre.numHijos);

    for (int i = 0; i < BaseDatosPadre.numHijos; i++)
    {
        printf("Hijo %d = Version: %d\n ", i + 1, BaseDatosPadre.hijos[i].version);
    }
    
}
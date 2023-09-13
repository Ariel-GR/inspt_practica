/*
Desarrollar un algoritmo que cargue una matriz que representa la notas de un
alumno determinado teniendo en cuenta que las filas representan las materias y las
columnas los trimestres:

Se pide:
Cargar la matriz y el nombre y apellido del alumno y luego informar: Nombre
completo del alumno y el siguiente reporte:
a. Promedio en cada una de las materias --> LISTO
b. Porcentaje de materias aprobadas por trimestres (nota >6).
c. Promedio general.

*/

#include <stdio.h>

void porcentaje_materias(int aprobadasTrim[],int trim){

    for(int i=0;i<trim;i++)
        printf("\nPorcenteje de materias aprobadas en el %d trimestre: %d %c ",i+1,aprobadasTrim[i]*100/5,37);
}


float promedio(int notas[][5],int col,int fila,int cont){

    float promedio=0;

    for(int i=0;i<col;i++){
        promedio+=notas[i][cont];
    }
    return (promedio/col);
}

void muestra_notas(int notas[][5],int col,int fila){

    printf("\t\t1-Matematicas\t2-Lengua\t3-Ingles\t4-Geografia\t5-Biologia\n\n");
    for(int i=0;i<3;i++){
        printf("Trim %d",i+1);
        for(int j=0;j<5;j++){
            printf("\t\t%d",notas[i][j]);
        }
        printf("\n\n");
    }
}

int main()
{
    int notas[3][5],cont=0,aprobadasTrim[3]={0,0,0},promedioGeneral=0;
    char nombre[50],apellido[50];
    
    //carga de datos
    printf("ingrese el nombre del alumno: ");
    gets(nombre);
    printf("ingrese el nombre del apellido: ");
    gets(apellido);
    
    printf("Orden de Las Notas: 1-Matematicas\t2-Lengua\t3-Ingles\t4-Geografia\t5-Biologia\n\n");
    for(int i=0;i<3;i++){
        printf("|%d %c Trimestre|\n\n",i+1,248);
        for(int j=0;j<5;j++){
            printf("\tMateria nro %d la nota es: ",j+1,i+1);
            scanf("%d",&notas[i][j]);
            if(notas[i][j]>6) aprobadasTrim[i]++;//contador punto b
        }
        printf("\n\n");
    }
    //punto a
    printf("\n\n**Los promedios del alumno: %s %s**\n\n",nombre,apellido);
    
    muestra_notas(notas,3,5);
    
    for(int i=0;i<5;i++){
        printf("Promedio materia nro %d es: %.2f\n",i+1,promedio(notas,3,5,cont));
        promedioGeneral+=promedio(notas,3,5,cont);//acumulador punto c
        cont++;
    }

    //punto b
    porcentaje_materias(aprobadasTrim,3);

    //punto c
    printf("\n\nEl promedio general fue de: %.2f\n",(float)promedioGeneral/5);

    return 0;
}

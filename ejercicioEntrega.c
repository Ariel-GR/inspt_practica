#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

void mostrarVector(int [], int);
void mostrarElementosRepetidos(int [], int);
void mostrarVectorSinRepetir(int [], int);
void mostrarUnionVectores(int [], int, int [], int);
void mostrarInterseccionVectores(int [], int, int [], int);
void mostrarRestaVectores(int [], int [], int);

int main()
{
    int opcion,v1[MAX],v2[MAX];
    int i;

    srand(time(NULL));
    for(i=0;i<MAX;i++)
    {
        v1[i]=rand()%(35+1-20)+20;
        v2[i]=rand()%(35+1-20)+20;
    }
    printf("SE HA REALIZADO LA CARGA DE 2 VECTORES DE TAMA%cO 10 ALEATORIAMENTE.\n\n",165);
	do
	{
	    printf("--------------MENU---------------\n\n");
	    printf("1-MOSTRAR VECTORES Y ELEMENTOS REPETIDOS\n");
	    printf("2-MOSTRAR VECTORES SIN DATOS REPETIDOS\n");
	    printf("3-MOSTRAR UNION\n");
	    printf("4-MOSTRAR INTERSECCION\n");
	    printf("5-MOSTRAR RESTA (PRIMERO-SEGUNDO)\n");
	    printf("6-MOSTRAR RESTA (SEGUNDO-PRIMERO)\n");
	    printf("7-SALIR\n");
	    do
	    {
	        printf("\nINGRESE UNA OPCION (1 a 7): ");
	        scanf("%d",&opcion);
	    } while (opcion<1||opcion>7);
	    printf("\n");
	    switch(opcion)
	    {
	        case 1:
	        	printf("\n----------VECTOR 1----------\n\n");
				mostrarVector(v1,MAX);
	            printf("\n----------VECTOR 2----------\n\n");
				mostrarVector(v2,MAX);
	            printf("\n----------PRIMER VECTOR-REPETIDOS----------\n\n");
	            mostrarElementosRepetidos(v1,MAX);
	            printf("\n----------SEGUNDO VECTOR-REPETIDOS----------\n\n");
	            mostrarElementosRepetidos(v2,MAX);
	            printf("\n");
	            break;
	        case 2:
	        	printf("\n----------PRIMER VECTOR-SIN REPETIDOS----------\n\n");
	        	mostrarVectorSinRepetir(v1,MAX);
	        	printf("\n----------SEGUNDO VECTOR-SIN REPETIDOS----------\n\n");
	        	mostrarVectorSinRepetir(v2,MAX);
	            printf("\n");
	        	break;
	        case 3:
	        	printf("\n----------UNION DE VECTORES----------\n\n");
	        	mostrarUnionVectores(v1,MAX,v2,MAX);
				printf("\n");
	        	break;
	        case 4:
	        	printf("\n----------INTERSECCION DE VECTORES----------\n\n");
	        	mostrarInterseccionVectores(v1,MAX,v2,MAX);
				printf("\n");
	        	break;
	        case 5:
	        	printf("\n----------VECTOR 1 - VECTOR 2----------\n\n");
	        	mostrarRestaVectores(v1,v2,MAX);
	        	printf("\n");
	        	break;
	        case 6:
	        	printf("\n----------VECTOR 2 - VECTOR 1----------\n\n");
	        	mostrarRestaVectores(v2,v1,MAX);
	        	printf("\n");
				break;
			case 7:
				printf("PROGRAMA TERMINADO");
	    }
	} while (opcion!=7);
	return 0;
}

void mostrarVector(int v[], int tam)
{
	int i;
	
	for (i=0;i<tam;i++) printf("ELEMENTO N%d = %d\n",i+1,v[i]);
}

void mostrarElementosRepetidos(int v[], int tam)
{
    int i,j,k,l=0,repetido,contado;
    int vr[tam];
	
	for (i=0;i<MAX;i++)
    {
        repetido=1;
        for(j=i+1;j<MAX;j++) if (v[j]==v[i]) repetido++;
        if (repetido>1) 
		{
			contado=0;
			for (k=0;k<l;k++) if (vr[k]==v[i]) contado=1;
			if (!contado)
			{
				vr[l]=v[i];
				l++;
				printf("El numero %d esta repetido %d veces.\n",v[i],repetido);
			}
		}
    }	
}

void mostrarVectorSinRepetir(int v[], int tam)
{
	int i,j,l=0,contado;
	int vsr[tam];
	
	for (i=0;i<tam;i++)
    {
        contado=0;
        for(j=i-1;j>=0;j--) if (v[j]==v[i]) contado=1;
        if (!contado) 
		{
			vsr[l]=v[i];
			printf("ELEMENTO N%d = %d\n",l+1,vsr[l]);
			l++;
		}
    }	
}

void mostrarUnionVectores(int v1[], int tam1, int v2[], int tam2)
{
	int i,j,k,l=0,contado;
	int vu[tam1+tam2];
	
	for (i=0;i<tam1;i++)
    {
        contado=0;
        for(j=i-1;j>=0;j--) if (v1[j]==v1[i]) contado=1;
        if (!contado) 
		{
			vu[l]=v1[i];
			l++;
		}
    }
    
    for (i=0;i<tam2;i++)
    {
        contado=0;
        for(j=i-1;j>=0;j--) if (v2[j]==v2[i]) contado=1;
        for(k=0;k<l;k++) if (vu[k]==v2[i]) contado=1;
        if (!contado) 
		{
			vu[l]=v2[i];
			l++;
		}
    }
    
	for(i=0;i<l;i++) printf("ELEMENTO N%d = %d\n",i+1,vu[i]);
}

void mostrarInterseccionVectores(int v1[], int tam1, int v2[], int tam2)
{
	int i,j,tam1sr=0,tam2sr=0,l=0,contado,repetido;
	int v1sr[tam1],v2sr[tam2];
	
	for (i=0;i<tam1;i++)
    {
        contado=0;
        for(j=i-1;j>=0;j--) if (v1[j]==v1[i]) contado=1;
        if (!contado) 
		{
			v1sr[tam1sr]=v1[i];
			tam1sr++;
		}
    }
	for (i=0;i<tam2;i++)
    {
        contado=0;
        for(j=i-1;j>=0;j--) if (v2[j]==v2[i]) contado=1;
        if (!contado) 
		{
			v2sr[tam2sr]=v2[i];
			tam2sr++;
		}
    }

	contado=0;
	repetido=1;
	for(i=0;i<tam1sr;i++)
	{
		for(j=i+1;j<tam1sr;j++) if (v1sr[i]==v1sr[j]) repetido++;
		for(j=0;j<tam2sr;j++) if (v1sr[i]==v2sr[j]) repetido++;
		for(j=i-1;j>=0;j--) if (v1sr[i]==v1sr[j]) contado=1;
		if (repetido>1&&!contado)
		{
			printf("ELEMENTO N%d = %d\n",l+1,v1sr[i]);
			l++;
		}
		contado=0;
		repetido=1;
	}
	for(i=0;i<tam2sr;i++)
	{
		for(j=i+1;j<tam2sr;j++) if (v2sr[i]==v2sr[j]) repetido++;
		for(j=i-1;j>=0;j--) if (v2sr[i]==v2sr[j]) contado=1;
		for(j=tam1sr-1;j>=0;j--) if (v2sr[i]==v1sr[j]) contado=1;
		if (repetido>1&&!contado)
		{
			printf("ELEMENTO N%d = %d\n",l+1,v2sr[i]);
			l++;
		}
		contado=0;
		repetido=1;
	}
}

void mostrarRestaVectores(int v1[], int v2[], int tam)
{
	int i;
	
	for (i=0;i<tam;i++) printf("RESTA ELEMENTOS N%d = %d\n",i+1,v1[i]-v2[i]);
}


#include <stdio.h>
#include <stdlib.h>

// Matrisi ekrana yazd�ran fonksiyon
void print_matrix(int **matrix, int n) {
	int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Matrisi sa�a 90 derece d�nd�ren fonksiyon
void rotate_right(int **matrix, int n) {
	int i,j;
    // bellekte fazla yer kaplayaca�� i�in yeni matrisi dinamik olarak olu�turuyorum
    int **new_matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        new_matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // Matrisin elemanlar�n� yerini de�i�tirerek yeni matrise aktar�yorum
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            new_matrix[j][n - i - 1] = matrix[i][j];
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j]=new_matrix[i][j];
        }
    }

    printf("Matrisin saga 90 derece dondurulmus hali:\n");
    print_matrix(new_matrix, n);

    // dinamik bellekte olu�turdu�um matrisi i�i bitince kald�r�yorum
    for (i = 0; i < n; i++) {
        free(new_matrix[i]);
    }
    free(new_matrix);
}

// Matrisi sola 90 derece d�nd�ren fonksiyon
void rotate_left(int **matrix, int n) {
	int i,j;
    // bellekte fazla yer kaplayaca�� i�in yeni matrisi dinamik olarak olu�turuyorum
    int **new_matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        new_matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // Matrisin elemanlar�n� yerini de�i�tirerek yeni matrise aktar�yorum
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            new_matrix[n - j - 1][i] = matrix[i][j];
        }
    }

	for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j]=new_matrix[i][j];
        }
    }
    
    printf("Matrisin sola 90 derece dondurulmus hali:\n");
    print_matrix(new_matrix, n);

    // dinamik bellekte olu�turdu�um matrisi i�i bitince kald�r�yorum
    for (i = 0; i < n; i++) {
        free(new_matrix[i]);
    }
    free(new_matrix);
}

int main() {
    int n,i,j,secim;
    int exit=1;
    printf("Matrisin boyutunu giriniz: ");
    scanf("%d", &n);

    // bellekte fazla yer kaplayaca�� i�in yeni matrisi dinamik olarak olu�turuyorum
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Matrisin elemanlarini giriniz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
	
    printf("orijinal matris:\n");
    print_matrix(matrix, n);
	do{
		printf("lutfen saga dondurmek icin 1, sola dondurmek icin 2 giriniz. cikmak istiyorsaniz 3 giriniz:");
		scanf("%d",&secim);
		switch(secim){
			case 1:
            	rotate_right(matrix, n);
				break;
		
			case 2:
				rotate_left(matrix, n);
				break;
			
			case 3:
				printf("cikis yapildi.");
				exit=0;
				break;
			default:
				printf("gecersiz harf girisi yapildi, tekrar deneyin.");
				break;
		}
	}while(exit==1);
	

    // dinamik bellekte olu�turdu�um ana matrisi i�i bitince kald�r�yorum
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}


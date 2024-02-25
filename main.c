//#include <stdio.h>
//#include "s21_matrix.h"
//
//int main() {
//    matrix_t matrix;
//    matrix_t matrix_1;
//    matrix_t sum_matrix;
//
//
//
//    int r =3;
//    int c =3;
//    double col = 0;
//    double col_1 = 0;
//    double  test= 0;
//
//
//    int res = s21_create_matrix(r,c,&matrix);
//    int res1 = s21_create_matrix(r,c,&matrix_1);
//
//
//    printf("%d\n",res);
//    printf("%d\n",res1);
//    for(int i=0; i<r;i++){
//        printf("Enter string for matrix %d\n",i+1);
//        for(int j=0; j<c;j++){
//            scanf("%lf",&col);
//            matrix.matrix[i][j] = col;
//        }
//    }
//
//
//
//
//    printf("MATRIX_1\n");
//    for(int i=0; i<r;i++){
//        for(int j=0; j<c;j++){
//           printf("%lf ",matrix.matrix[i][j]);
//        }
//        printf("\n");
//    }
////    printf("MATRIX_2\n");
////    for(int i=0; i<r;i++){
////        for(int j=0; j<c;j++){
////            printf("%lf ",matrix_1.matrix[i][j]);
////        }
////        printf("\n");
////    }
//    printf("MATRIX_SUM\n");
//    for(int i=0; i<r;i++){
//        for(int j=0; j<c;j++){
//            printf("%lf ",sum_matrix.matrix[i][j]);
//        }
//        printf("\n");
//    }
//
//
//    s21_remove_matrix(&matrix);
////    s21_remove_matrix(&matrix_1);
////    s21_remove_matrix(&sum_matrix);
//
//
//    return 0;
//}

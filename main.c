// #include <stdio.h>
// #include "s21_matrix.h"
//
// int main() {
//     matrix_t matrix;
//     matrix_t matrix_1;
//     matrix_t sum_matrix;
//
//
//
//     int r =3;
//     int c =3;
//     double col = 0;
//     double col_1 = 0;
//     double  a  = 0;
//
//
//     int res = s21_create_matrix(r,c,&matrix);
//     int res1 = s21_create_matrix(r,c,&sum_matrix);
//
//
//
//
//     printf("%d\n",res);
////    printf("%d\n",res1);
//    for(int i=0; i<r;i++){
//        printf("Enter string for matrix %d\n",i+1);
//        for(int j=0; j<c;j++){
//            scanf("%lf",&col);
//            matrix.matrix[i][j] = col;
//        }
//    }
//
//    int test = s21_inverse_matrix(&matrix,&sum_matrix);
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
//
//
//
//    return 0;
//}

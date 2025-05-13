#include <stdio.h>
void evaluate_gates(int A, int B) {
    printf("AND  (A & B)   = %d\n", A & B);
    printf("OR   (A | B)   = %d\n", A | B);
    printf("XOR  (A ^ B)   = %d\n", A ^ B);
}

int mux_4to1(int I0, int I1, int I2, int I3, int S0, int S1) {
    return (S0 == 0 && S1 == 0) ? I0 :
           (S0 == 0 && S1 == 1) ? I1 :
           (S0 == 1 && S1 == 0) ? I2 :
           (S0 == 1 && S1 == 1) ? I3 : -1;
}

void demux_1to4(int input, int S0, int S1) {
    printf("O0 = %d\n", (S0 == 0 && S1 == 0) ? input : 0);
    printf("O1 = %d\n", (S0 == 0 && S1 == 1) ? input : 0);
    printf("O2 = %d\n", (S0 == 1 && S1 == 0) ? input : 0);
    printf("O3 = %d\n", (S0 == 1 && S1 == 1) ? input : 0);
}

int main() {
    int A, B, S0, S1, I0, I1, I2, I3, input;
    printf("Enter two Boolean values (0 or 1):\n");
    scanf("%d %d", &A, &B);
    evaluate_gates(A, B);

    printf("Enter four inputs (0 or 1) for MUX:\n");
    scanf("%d %d %d %d", &I0, &I1, &I2, &I3);
    printf("Enter select lines S0 and S1 (0 or 1):\n");
    scanf("%d %d", &S0, &S1);
    printf("MUX Output = %d\n", mux_4to1(I0, I1, I2, I3, S0, S1));

    printf("Enter input for DEMUX:\n");
    scanf("%d", &input);
    printf("Enter select lines S0 and S1 (0 or 1):\n");
    scanf("%d %d", &S0, &S1);
    demux_1to4(input, S0, S1);

    return 0;
}

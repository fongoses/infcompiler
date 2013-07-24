int a = 5;
int b = 3;
int c = 0;

char x = 2;
char y = 9;
char z = 0;

void main(void) {

subtrai_int:
    c = a - b;

subtrai_byte:
    z = x - y;

subtrai_print:
    printf("Subtrai:\na = %d, b = %d, c = %d\nx = %d, y = %d, z = %d\n", a, b, c, x, y, z);



multiplica_int:
    c = a * b;

multiplica_byte:
    z = x * y;

multiplica_print:
    printf("Multiplica:\na = %d, b = %d, c = %d\nx = %d, y = %d, z = %d\n", a, b, c, x, y, z);



divide_int:
    c = a / b;
    a = c / b;

divide_byte:
    z = x / y;

divide_print:
    printf("Divide:\na = %d, b = %d, c = %d\nx = %d, y = %d, z = %d\n", a, b, c, x, y, z);

}

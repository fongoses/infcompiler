int a=10;
int b=5;

char x=1;
char y=20;

void main(void) {
equal_int:
    if(a == b) {
        printf("a, b igual\n");
    } else {
        printf("a, b diferente\n");
    }
equal_byte:
    if(x == y) {
        printf("x, y igual\n");
    } else {
        printf("x, y diferente\n");
    }

less_int:
    if(a < b) {
        printf("a < b ok\n");
    } else {
        printf("a < b falso\n");
    }
less_byte:
    if(x < y) {
        printf("x < y ok\n");
    } else {
        printf("x < y falso\n");
    }

greater_int:
    if(a > b) {
        printf("a > b ok\n");
    } else {
        printf("a > b falso\n");
    }
greater_byte:
    if(x > y) {
        printf("x > y ok\n");
    } else {
        printf("x > y falso\n");
    }

less_equal_int:
    if(a <= b) {
        printf("a <= b ok\n");
    } else {
        printf("a <= b falso\n");
    }
less_equal_byte:
    if(x <= y) {
        printf("x <= y ok\n");
    } else {
        printf("x <= y falso\n");
    }

greater_equal_int:
    if(a >= b) {
        printf("a => b ok\n");
    } else {
        printf("a => b falso\n");
    }
greater_equal_byte:
    if(x >= y) {
        printf("x => y ok\n");
    } else {
        printf("x => y falso\n");
    }

}

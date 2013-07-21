int x = 10;
int i = 0;
int v[10];
char ch = 'Z';
int *ptr;

void main(void) {
    i = 0;

    while(i < 10) {
        v[i] = x * i;
        printf("Valores I = %d, V[%d] = %d, X = %d\n", i, i, v[i], x);
        x = x + 5;
        i++;
    }
    
    ptr = &x;
    printf("PTR = %p, *PTR = %d, X = %d\n", ptr, *ptr, x);

    *ptr = 42;
    printf("PTR = %p, *PTR = %d, X = %d\n", ptr, *ptr, x);

    ptr = v;
    printf("PTR = %p, *PTR = %d, V[0] = %d\n", ptr, *ptr, v[0]);

    ptr = ptr + 3;
    printf("PTR = %p, *PTR = %d, V[3] = %d\n", ptr, *ptr, v[3]);

    printf("Fim, ch = %c\n", ch);
}

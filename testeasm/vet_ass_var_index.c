int v[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int a=20;
int i=5;

char w[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
char b=20;
char j=5;

void main(void) {
vet_ass_int:
    v[i] = a;

vet_ass_byte:
    w[j] = b;

vet_ass_int_Ibyte:
    v[j] = a;

vet_ass_byte_Iint:
    w[a] = b;

}

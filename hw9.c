#include <stdio.h>

struct Student {
    char fname[20], lname[20], id[10];
    float golch;
 };
typedef struct Student Student;
 // n оюутны мэдээллийг гараас авч a хүснэгтэд хадгална.
void read_students(Student a[], int n) {
    for (int i=0; i<n; i++) {
        printf("\n %d-r oyutnii medeelel:\n", i+1);
        printf("Ner: ");
        scanf("%s", a[i].fname);
        printf("Owog: ");
        scanf("%s", a[i].lname);
        printf("ID: ");
        scanf("%s", a[i].id);
        printf("Golch: ");
        scanf("%f", &a[i].golch);
    }
}
 // a хүснэгтэд хадгалсан n оюутны мэдээллийг хэвлэнэ.
void print_students(Student a[], int n) {
    printf("\n Oyutnuudiin medeelel \n");
    for (int i=0; i<n; i++) {
        printf("\n %d-r oyutan:\n", i+1);
        print(a[i]);
    }
}
 // st оюутны мэдээллийг хэвлэнэ.
void print(Student st) {
    printf("Ner: %s \n", st.fname);
    printf("Owog: %s \n", st.lname);
    printf("ID: %s \n", st.id);
    printf("Golch: %.2f \n", st.golch);
}
 // a хүснэгтэд хадгалсан n оюутны мэдээллээс fname нэрийг хайна.
 // Уг нэртэй оюутан олдож байгаа бол хүснэгтийн дугаарыг, үгүй бол -1 утгыг буцаана.
int search_by_fname(Student a[], int n, char fname[]) {
    for (int i=0; i<n; i++) {
        if (strcmp(a[i].fname, fname)==0)
            return i;
    }
    return -1;
}
 // a хүснэгтэд хадгалсан n оюутны мэдээллээс lname овгийг хайна.
 // Уг овогтой оюутан олдож байгаа бол хүснэгтийн дугаарыг, үгүй бол -1 утгыг буцаана.
int search_by_lname(Student a[], int n, char lname[])  {
    for (int i=0; i<n; i++) {
        if (strcmp(a[i].lname, lname)==0)
            return i;
    }
    return -1;
}
 // a хүснэгтэд хадгалсан n оюутны мэдээллээс id id-г хайна.
 // Уг id-тай оюутан олдож байгаа бол хүснэгтийн дугаарыг, үгүй бол -1 утгыг буцаана.
int search_by_id(Student a[], int n, char id[]) {
    for (int i=0; i<n; i++) {
        if (strcmp(a[i].id, id)==0)
            return i;
    }
    return -1;
}
 // a хүснэгтэд хадгалсан n оюутны мэдээллээс golch голчийг хайна.
 // Уг голчтой оюутан олдож байгаа бол хүснэгтийн дугаарыг, үгүй бол -1 утгыг буцаана.
int search_by_golch(Student a[], int n, float golch) {
    for (int i=0; i<n; i++) {
        if (a[i].golch==golch)
            return i;
    }
    return -1;
}
 // a хүснэгтэд хадгалсан n оюутны мэдээллээс голчоор нь эрэмбэлнэ.
void sort_by_golch(Student a[], int n) {
    Student temp;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (a[i].golch>a[j].golch) {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("\n Golchoor erembelsen ni \n");
    print_students(a, n);
}

 int main()
 {
    Student a[100];
    int n, cmd, idx;
    printf("Oyutnii too: ");
    scanf("%d",&n);
    read_students(a, n);
    print_students(a, n);
    char fname[20], lname[20], id[20];
    float golch;
    while (1) {
        printf("1: Nereer xaix, 2: Ovgoor xaix, 3: ID−aar xaix, 4: Golchoor xaix, 5: Golchoor erembelex, 6: Xevlex, 7: Garax\n");
        scanf("%d",&cmd);
        if (cmd==1) {
            printf("Xaix ner: ");
            scanf("%s", fname);
            idx=search_by_fname(a, n, fname);
            if (idx== -1)
                printf("Oyutan oldsongui \n");
            else
                print(a[idx]);
        } else if (cmd==2) {
            printf("Xaix ovog: ");
            scanf("%s", lname);
            idx=search_by_lname(a, n, lname);
            if (idx== -1)
                printf("Oyutan oldsongui \n");
            else
                print(a[idx]);
        } else if (cmd==3) {
            printf("Xaix id: ");
            scanf("%s", id);
            idx=search_by_id(a, n, id);
            if (idx== -1)
                printf("Oyutan oldsongui\n");
            else
                print(a[idx]) ;
        } else if (cmd == 4) {
            printf("Xaix golch: ");
            scanf("%f", &golch);
            idx = search_by_golch(a, n, golch);
            if (idx == -1)
                printf("Oyutan oldsongui\n");
            else
                print(a[idx]) ;
        } else if (cmd == 5)
            sort_by_golch(a, n);
        else if (cmd == 6)
            print_students(a, n);
        else
            break;
    }
    return 0;
}
void print(Student st)
{
    printf("Ner: %s\n", st.fname);
    printf("Ovog: %s\n", st.lname);
    printf("Id: %s\n", st.id);
    printf("Golch: %lf \n", st.golch);
}
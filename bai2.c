#include <stdio.h>


void menu() {
    printf("=====menu=====\n");
    printf("1.Gui yeu cau ho tro.\n");
    printf("2.Xu li yeu cau.\n");
    printf("3.Xem yeu cau gan nhat can xu li.\n");
    printf("4.Hien thi toan bo yeu cau.\n");
    printf("5.Thoat.\n");
}
int main() {
    int choice;
    do {
        menu();
        printf("Lua chon cua ban : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("....\n");
                break;
            case 2:
                printf("....\n");
                break;
            case 3:
                printf("....\n");
                break;
            case 4:
                printf("....\n");
                break;
            case 5:
                printf("Thoat thanh cong.\n");
                break;
            default:
                printf("khong co lua chon nay.\n");
        }
    }while (choice!=5);
}
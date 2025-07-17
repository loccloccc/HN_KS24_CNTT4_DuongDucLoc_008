#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
// Cấu trúc dữ liệu
typedef struct Student {
    int id;
    char name[100];
    char status[20];
    int avg;
} Student;

typedef struct DStudent {
    Student student;
    struct DStudent *next;
    struct DStudent *prev;
} DStudent;

Student activeList[MAX];
int count = 0;
DStudent* head = NULL;
DStudent* tail = NULL;
DStudent* createDStudent(Student s) {
    DStudent* dStudent = (DStudent*)malloc(sizeof(DStudent));
    dStudent->student = s;
    dStudent->next = NULL;
    dStudent->prev = NULL;
    return dStudent;
}
void addInactive(Student s) {
    DStudent* dStudent = createDStudent(s);
    if (head == NULL) {
        head = tail = dStudent;
    } else {
        tail->next = dStudent;
        dStudent->prev = tail;
        tail = dStudent;
    }
}
void addStudent() {
    if (count >= MAX) {
        printf("Danh sach đa đay.\n");
        return;
    }
    Student s;
    printf("Nhap thong tin sinh vien:\n");
    printf("ID: ");
    scanf("%d", &s.id);
    getchar();
    printf("Ten: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';
    printf("Trang thai (true/false): ");
    fgets(s.status, sizeof(s.status), stdin);
    s.status[strcspn(s.status, "\n")] = '\0';
    printf("Diem trung binh: ");
    scanf("%d", &s.avg);

    if (strcmp(s.status, "true") == 0 || strcmp(s.status, "TRUE") == 0) {
        activeList[count++] = s;
    } else {
        addInactive(s);
    }
}
void printS() {
    printf("=== Danh sach sinh vien hoat đong ===\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", activeList[i].id);
        printf("Ten: %s\n", activeList[i].name);
        printf("Diem TB: %d\n", activeList[i].avg);
        printf("Trang thai: %s\n\n", activeList[i].status);
    }

    printf("=== Danh sach sinh vien khong hoat đong ===\n");
    DStudent* cur = head;
    while (cur != NULL) {
        printf("ID: %d\n", cur->student.id);
        printf("Ten: %s\n", cur->student.name);
        printf("Diem TB: %d\n", cur->student.avg);
        printf("Trang thai: %s\n\n", cur->student.status);
        cur = cur->next;
    }
}
void deleS() {
    int id;
    printf("Nhap ID can xoa: ");
    scanf("%d", &id);
    int flag = 0;
    for (int i = 0; i < count; i++) {
        if (activeList[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                activeList[j] = activeList[j + 1];
            }
            count--;
            flag = 1;
            break;
        }
    }
    if (flag) {
        printf("Xea thanh cong.\n");
    } else {
        printf("Khong tìm thay sinh vien.\n");
    }
}
void updateInfor() {
    int id;
    printf("Nhap ID  cap nhat: ");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < count; i++) {
        if (activeList[i].id == id) {
            printf("Ten moi: ");
            fgets(activeList[i].name, sizeof(activeList[i].name), stdin);
            activeList[i].name[strcspn(activeList[i].name, "\n")] = '\0';
            printf("Diem TB moi: ");
            scanf("%d", &activeList[i].avg);
            getchar();
            printf("Cap nhat thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien.\n");
}
void updateStatus() {
    int id;
    printf("Nhap ID can cap nhat trang thai: ");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < count; i++) {
        if (activeList[i].id == id) {
            printf("Trang thai moi (true/flase): ");
            fgets(activeList[i].status, sizeof(activeList[i].status), stdin);
            activeList[i].status[strcspn(activeList[i].status, "\n")] = '\0';
            printf("Cap nhat trang thai thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien.\n");
}
void sort() {
    if (count == 0) {
        printf("Danh sach rong.\n");
        return;
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (activeList[j].avg > activeList[j + 1].avg) {
                Student temp = activeList[j];
                activeList[j] = activeList[j + 1];
                activeList[j + 1] = temp;
            }
        }
    }
    printf("Đa sap xep theo điem trung binh.\n");
}
void search() {
    if (count == 0) {
        printf("Danh sach rong.\n");
        return;
    }
    int id;
    printf("Nhap ID can tim: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (activeList[i].id == id) {
            printf("ID: %d\n", activeList[i].id);
            printf("Ten: %s\n", activeList[i].name);
            printf("Trang thai: %s\n", activeList[i].status);
            printf("Diem TB: %d\n", activeList[i].avg);
            return;
        }
    }
    printf("Khong tim thay sinh vien.\n");
}
void menu() {
    printf("=========== MENU ===========\n");
    printf("1. Them sinh vienn\n");
    printf("2. Hien thi danh sach sinh vien\n");
    printf("3. Xoa sinh vien\n");
    printf("4. Cap nhat thong tin sinh vien\n");
    printf("5. Cap nhat trang thai sinh vien\n");
    printf("6. Sap xep sinh vien\n");
    printf("7. Tim kiem sinh vien\n");
    printf("8. Thoat\n");
    printf("============================\n");
}

int main(void) {
    int choice;
    do {
        menu();
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                printS();
                break;
            case 3:
                deleS();
                break;
            case 4:
                updateInfor();
                break;
            case 5:
                updateStatus();
                break;
            case 6:
                sort();
                break;
            case 7:
                search();
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 8);
    return 0;
}
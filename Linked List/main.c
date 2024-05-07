#include <ctype.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

struct Single_List {
//    char name[30];
    float mark;
    struct Single_List *via;
};
/*
bool valid_name(char *data) {
    for (int i = 0; i < strlen(data); i++) {
        if (!isalpha(data[i]) && !isblank(data[i])) return false;
    }
    return true;
}

unsigned int sizeofList(struct Single_List **data) {
    unsigned int nodeCounter = 0;

    struct Single_List *temp = *data;
    while (temp != NULL) {
        nodeCounter++;
        temp = temp->via;
    }
    return nodeCounter;
}

void deleteNode(struct Single_List **data) {
    struct Single_List *temp = *data, *prev;
    char remove_name[30];

    try_another:
    do {
        printf("Nhap vao ten sinh vien can xoa:");
        gets(remove_name);
        if (!valid_name(remove_name)) printf("Chi cho phep cac ky tu Alphabet (tru dau cach) !\n");
    } while (!valid_name(remove_name));

    while (temp != NULL && temp->name != remove_name) { // tim ten can xoa
        prev = temp;
        temp = temp->via;
    }
    if (temp == NULL) {
        printf("Khong ton tai ten nay trong danh sach. Hay thu voi cai ten khac !\n");
        goto try_another;
    }
    printf("Da xoa ten khoi danh sach thanh cong !\n");
    prev->via = temp->via; // xoa ten khoi danh sach
}

void addNode(struct Single_List **data) {
    struct Single_List *insert = NULL;

    insert = (struct Single_List*)malloc(sizeof(struct Single_List));
    if (insert == NULL) {
        printf("Memory Allocating fail for this student's node !\n");
    } else {
        do {
            printf("Nhap vao ho va ten:");
            gets(insert->name);
            if (!valid_name(insert->name)) printf("Chi cho phep cac ky tu Alphabet (tru dau cach) !\n");
        } while (!valid_name(insert->name));
        do {
            printf("Nhap vao diem:");
            scanf_s("%f", &insert->mark);
            if (insert->mark < 0.0 || insert->mark > 10.0) printf("Diem cua ban khong hop le !\n");
        } while (insert->mark < 0.0 || insert->mark > 10.0);
        getchar(); // tuong tu cin.ignore();
        insert->via = *data; // ->...->insert->data->NULL, *data->via = NULL
        *data = insert;
    }
}

void createNode(struct Single_List **head) { // con tro cap 2 tiep nhan con tro cap 1
    int amount;

    do {
        printf("Nhap vao so luong sinh vien can them:");
        scanf_s("%d", &amount);
        if (amount < 0) printf("Gia tri khong phu hop !\n");
    } while (amount < 0);
    getchar(); // skip '\n' from buffer input
    for (int i = 0; i < amount; i++) {
        printf("Sinh vien thu %d\n", i + 1);
        addNode(head);
    }
    printf("Khoi tao danh sach thanh cong !\n");
}*/

void printNode(struct Single_List *data) {
    while (data != NULL) {
        printf("%f\n", data->mark);
        data = data->via;
    }
}

int main() {
    struct Single_List *head, **node_n = NULL;
    int n = 3;

    node_n = (struct Single_List**)malloc(n * sizeof(struct Single_List*));

    node_n[0]->mark = 1;
    node_n[1]->mark = 2;
    node_n[2]->mark = 3;

    head = node_n[0];
    node_n[0]->via = node_n[1];
    node_n[1]->via = node_n[2];
    node_n[2]->via = NULL;

    printNode(head);
    for (int i = 0; i < n; i++) free(node_n[i]);
    /*char menuSelections[6][30] = {"Them sinh vien",
                                  "Xoa sinh vien",
                                  "In danh sach diem sinh vien",
                                  "Tim diem cao nhat & thap nhat",
                                  "Tinh diem TB tat ca sinh vien",
                                  "Thoat chuong trinh"};
    int option, menuSize = sizeof(menuSelections) / sizeof(menuSelections[0]);

    menuLoop:
    do {
        printf("QUAN LI DANH SACH SINH VIEN (SINGLE LINKED LIST)\n"); // in ra menu cac lua chon
        for (int i = 0; i < menuSize; i++) printf("%d - %s\n", i, menuSelections[i]);
        printf("Lua chon cua ban la:");
        scanf_s("%d", &option);
        if (option < 0 || option > menuSize) printf("Ban nhap sai gia tri cmnr !\n");
    } while (option < 0 || option > menuSize);
    getchar(); // skip '\n'

    if (option != 0 && option != menuSize - 1 && sizeofList(&studentNode) == 1) {
        printf("Hien tai chua co sinh vien nao ca !\n");
        goto menuLoop;
    }
    switch (option) {
        case 0:
            createNode(&studentNode);
            break;
        case 1:
            deleteNode(&studentNode);
            break;
        case 2:
            printNode(studentNode);
            break;
        case 3:
            printf("%d", sizeofList(&studentNode));
            break;
        case 4:
            break;
        default:
            printf("Cam on ban da su dung chuong trinh !\n");
            system("pause");
    }
    if (option != menuSize - 1) {
        system("pause");
        system("cls");
        goto menuLoop;
    }*/
    return 0;
}

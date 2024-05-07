#include <stdio.h>
#include <string.h>
#include <malloc.h>

char *substr(char *data, int pos, int len) {
    char *new_data = NULL;
    int c = 0;

    new_data = (char*)malloc(strlen(data) * sizeof(char));
    if (new_data == NULL) return "ERROR";
    while (c < len) {
        new_data[c] = data[pos + c - 1];
        c++;
    }
    new_data[c] = '\0';
    return new_data;
}

char *tokenization_name(char *your_name) { // @gu/e3 Tr-'n^ Ph%c
    unsigned int index_amount = strlen(your_name);
    char *process_name = NULL, *new_name = NULL;
    int h = 0, cut_begin = 0, cut_len = 0, cut_pos;

    process_name = (char*)malloc(index_amount * sizeof(char));
    if (process_name == NULL) return "ERROR";
    new_name = process_name;
    for (int i = 0; i < strlen(your_name); i++) {
        if (your_name[i] != ' ') {
            if (cut_begin == 0) {
                cut_pos = i;
                cut_begin = 1;
            }
            cut_len++;
        } else {
            if (your_name[i - 1] == ' ' || i == 0) continue;
            process_name = substr(your_name, cut_pos, cut_len);
            for (int j = 0; j < strlen(process_name); j++) {
                if ((process_name[j] >= 'a' && process_name[j] <= 'z') || (process_name[j] >= 'A' && process_name[j] <= 'Z')) {
                    new_name += process_name[j];
//                    h++;
                }
            }
//            new_name[h] = ' ';
            cut_begin = 0;
            cut_len = 0;
        }
    }
    return new_name;
}

int main() {
    char your_name[30], option;

    try_other:
    printf("Nhap vao ho va ten:");
    gets(your_name);
    if (tokenization_name(your_name) != "ERROR") {
        printf("Co ve ban nhap sai dinh dang theo Alphabet\n");
        printf("Goi y: %s\n", tokenization_name(your_name));
        printf("Ban co dong y voi goi y tren ? (y - Co / !y - Khong) =>");
        scanf("%c", &option);
        if (option != 'y') {
            getchar();
            goto try_other;
        }
    }
    system("pause");
    return 0;
}

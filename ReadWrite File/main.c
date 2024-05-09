#include <stdio.h>

/*
 * mode: r, w, a, r+, w+, a+, rb, wb, ab, r+b, w+b, a+b
 * FILE* fopen(const char* filename, const char* mode) : mo file
 * int fclose(FILE* fp) : dong file
 * fscanf(FILE* fp, "%c") : doc vao file
 * fprintf(FILE* fp, "%c") : ghi vao file
 * fgets(char* text, size, FILE* fp) : doc tu file dang chuoi
 * fputs(char* text, FILE* fp) : ghi vao file dang chuoi
 * fread(char* text, sizeof(...), size, FILE* fp) : doc tu file binary
 * fwrite(char* text, sizeof(...), size, FILE* fp) : ghi vao file binary
 * fgetc(FILE* fp) : doc tu file dang ky tu
 * fputc(char c_text, FILE* fp) : ghi vao file dang ky tu
 * feof(FILE* fp) : nhan biet ket thuc noi dung trong file
 * ftell(FILE* fp) : doc vi tri con tro hien tai trong file
 * fseek(FILE* fp, fpos, _MODE_) : dich con tro den vi tri bat ki trong file, _MODE_ (SEEK_SET=BEG, SEEK_END, SEEK_CUR)
 */

int main() {
    FILE* fp;
    char arr[] = {1, 2,3, 4, 5}, appData[] = {8, 9}, readData[5];

    /*GHI VAO FILE*/
    fopen_s(&fp, "Test.bin", "wb"); // write mode
    if (fp == NULL) {
        printf("File error !\n");
        return 1;
    }
    printf("%ld\n", ftell(fp));
    fwrite(arr, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), fp);
    printf("%ld\n", ftell(fp));

    fseek(fp, 2, SEEK_SET); // ghi 2 so 8, 9 vao vi tri moi
    fwrite(appData, sizeof(appData[0]), sizeof(appData) / sizeof(appData[0]), fp);


    //  fopen_s(&fp, "Test.bin", "rb");
    fread(readData, sizeof(readData[0]), sizeof(readData) / sizeof(readData[0]), fp);
    for (int i = 0; i < ftell(fp) / sizeof(readData[0]); i++) printf("%d ", readData[i]);
    fclose(fp);

    /*DOC TU FILE*/
    fopen_s(&fp, "Test.bin", "rb"); // read mode
    if (fp == NULL) {
        printf("File error !\n");
        return 1;
    }
    fread(readData, sizeof(int), 2, fp);
    for (int i = 0; i < sizeof(readData) / sizeof(readData[0]); i++) printf("\n%d", readData[i]);

    /*RESET POINTER TO BEGIN*/
    rewind(fp); // dua con tro ve dau file
    fread(readData, sizeof(int), 2, fp);
    for (int i = 0; i < sizeof(readData) / sizeof(readData[0]); i++) printf("\n%d", readData[i]);
    fclose(fp);

    /*RENAME FILE*/
    if (rename("Test.bin", "Test2.bin") == 0) printf("\nFile renamed successfully !");
    else printf("\nError: unable to rename the file !");

    /*REMOVE FILE*/
    if (remove("Test2.bin") == 0) printf("\nFile removed successfully !");
    else printf("\nError: unable to remove the file !");
    return 0;
}

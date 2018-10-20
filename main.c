#include <stdio.h>
#include <mem.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char msv[7];
    char hoten[50];
    char sdt[20];
} Sinhvien;

Sinhvien mangsinhvien[10];
int sosinhvien = 0;

bool validateData() {
    if (strlen(mangsinhvien[sosinhvien].msv) != 6) {
        printf("ma sinh vien phai du 5 ki tu\n");
        return false;
    }
    return true;
}

void removestdchar(char array[]) {
    if (strchr(array, '\n') == NULL) {
        while (fgetc(stdin) != '\n');
    }
}

void menu() {
    printf("1.Them moi sinh vien\n");
    printf("2.Hien thi danh sach sinh vien\n");
    printf("3.Luu danh sach sinh vien ra file\n");
    printf("4.Doc danh sach sinh vien tu file\n");
    printf("5.Thoat chuong trinh\n");
    printf("Nhap lua chon cua ban 1|2|3|4|5\n");
}

void themsv() {
    if (sosinhvien == 9) {
        printf("Danh sach sinh vien da day");
        return;
    }
    printf("Nhap ma sinh vien: \n");
    fgets(mangsinhvien[sosinhvien].msv, sizeof(mangsinhvien[sosinhvien].msv) * sizeof(char), stdin);
    removestdchar(mangsinhvien[sosinhvien].msv);
    mangsinhvien[sosinhvien].msv[strlen(mangsinhvien[sosinhvien].msv) - 1] = ' ';
    bool isValidateData = validateData();
    if (isValidateData) {
        printf("Nhap ho va ten cua sinh vien:\n");
        fgets(mangsinhvien[sosinhvien].hoten, sizeof(mangsinhvien[sosinhvien].hoten) * sizeof(char), stdin);
        removestdchar(mangsinhvien[sosinhvien].hoten);
        mangsinhvien[sosinhvien].hoten[strlen(mangsinhvien[sosinhvien].hoten) - 1] = ' ';
        printf("Nhap so dien thoai cua sinh vien:\n");
        fgets(mangsinhvien[sosinhvien].sdt, sizeof(mangsinhvien[sosinhvien].sdt) * sizeof(char), stdin);
        removestdchar(mangsinhvien[sosinhvien].sdt);
        mangsinhvien[sosinhvien].sdt[strlen(mangsinhvien[sosinhvien].sdt) - 1] = ' ';
    }
    sosinhvien++;
}

void xuatsv() {
    printf("\t\tDANH SACH SINH VIEN\n");
    printf(" Ma sinh vien \tHo va ten \tSo dien thoai\n");
    for (int i = 0; i < sosinhvien; ++i) {
        printf("%-20s%-20s%-20s\n", mangsinhvien[i].msv, mangsinhvien[i].hoten, mangsinhvien[i].sdt);
    }
}

void ghidanhsacchsinhvienvaofile() {
    FILE *fp = fopen("../danhsachsinhvien.txt", "w+");
    if (fp != NULL) {
        fprintf(fp, "ma sinh vien \tho va ten \tso dien thoai\n");
        for (int i = 0; i < sosinhvien; ++i) {
            fprintf(fp, "%-20s%-20s%-20s\n", mangsinhvien[i].msv, mangsinhvien[i].hoten, mangsinhvien[i].sdt);
        }
        fclose(fp);
    } else { printf("khong mo duoc file\n"); }
}

void docdulieutufile() {
    char temporaryArray[250];
    FILE *fp = fopen("../danhsachsinhvien.txt", "r");
    printf("\tKET QUA DOC FILE\n");
    while (fgets(temporaryArray, 250, fp) != NULL) {
        printf("%s\n", temporaryArray);
    }
    fclose(fp);
}

int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                themsv();
                break;
            case 2:
                xuatsv();
                break;
            case 3:
                ghidanhsacchsinhvienvaofile();
                break;
            case 4:
                docdulieutufile();
                break;
            case 5:
                printf("ket thuc \n");
                exit(1);
            default:
                break;
        }
    } while (1);
    return 0;
}

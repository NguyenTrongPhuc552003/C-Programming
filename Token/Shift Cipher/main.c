#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * 1/ lower to upper
 * 2/ new_str[i] = 'A' + (str[i] + k) % 26 (k [0; 100], k // 5 == 0)
 * */

char* shift_cipher(char* data) {
    unsigned int myOffset = 1/*, min = 1, max = 100*/;

//    srand(time(0));
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] != ' ') {
            data[i] = (char)('A' + (data[i] + 'A' + myOffset) % 26);
        }
    }
    return data;
}

char* decoding_cipher(char* data) {
    for (int i = 0; i < strlen(data); i++) {

    }
    return data;
}

int main() {
    char name[] = "Theo em trinh bay quan diem cua Ho Chi Minh ve dai doan ket dan toc co tac dung "
                  "phat huy suc manh va tam quan trong cua khoi dai doan ket toan dan toc trong boi "
                  "canh ngay nay Ho Chi Minh nhan manh moi nguoi dan Viet Nam khong phan biet xuat "
                  "than dang phai chinh tri phai doan ket cung huong toi mot muc tieu chung la doc "
                  "lap va phat trien cua To quoc Thong diep nay van con phu hop cho den ngay nay khi "
                  "chung ta phai doi mat voi nhieu thach thuc ca trong nuoc va quoc te doi hoi chung "
                  "ta phai doan ket voi nhau nhu mot quoc gia Bang cach thuc day cac nguyen tac do Ho "
                  "Chi Minh vach ra chung ta co the khuyen khich su cong tac va hop tac lon hon giua "
                  "cac nhom khac nhau trong xa hoi dieu nay co the dan den cac giai phap hieu qua hon "
                  "duoc phat trien de giai quyet cac van de cua chung ta Cuoi cung dieu quan trong la "
                  "chung ta phai ghi nho va tiep tuc duoc truyen cam hung boi tam nhin ve doan ket va "
                  "tien bo do Ho Chi Minh de ra ngay ca sau khi Nguoi da qua doi No van la mot di san "
                  "lau dai tiep tuc dinh hinh tuong lai cua quoc gia chung ta";

    printf("%s", shift_cipher(name));
    return 0;
}

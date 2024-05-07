#include <stdio.h>

enum weekday {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
enum Symbols {
    ALPHA = -1,
    BETA = 1,
    GAMMA
};
// enum's elements => int type

int main() {
    int a = MONDAY;
    printf("%d", a);
}
#include <stdio.h>
#include <string.h>

int main(void) {
    /*strcmp(s1, s2):
     * < 0: the first non-matching character is lower
     * = 0: 2 strings are equal
     * > 0: the first non-matching character is higher*/
    char s1[] = "Hello world";
    char s2[] = "Hello world";
    if (strcmp(s1, s2) == 0) printf("s1 and s2 are equal\n");
    else if (strcmp(s1, s2) < 0) printf("s1 is less than s2\n");
    else printf("s1 is greater than s2\n");

    /*strpbrk(str, control):
     * != NULL: first matching character
     * else: no matching character*/
    char s3[] = "Hello world";
    char s4[] = "world";
    char *p = strpbrk(s3, s4);
    if (p != NULL) printf("First matching character: %c\n", *p);
    else printf("No matching character\n");

    /*strspn(str, control):
     * number of characters in str that are in control*/
    char s5[] = "Hello world";
    char s6[] = "Helo";
    unsigned long long n = strspn(s5, s6);
    printf("Number of characters in s5 that are in s6: %llu\n", n);

    /*strcspn(str, control):
     * number of characters in str that are not in control*/
    char s7[] = "Hello world";
    char s8[] = "Helo";
    unsigned long long m = strcspn(s7, s8);
    printf("Number of characters in s7 that are not in s8: %llu\n", m);

    /*strcat_s(str, size, control):
     * concatenate control to str*/
    char s12[] = "Hello";
    char s13[] = " world";
    strcat_s(s12, sizeof(s12), s13);
    printf("s12: %s\n", s12);

    /*strchr(str, control):
     * != NULL: first matching character
     * else: no matching character*/
    char s14[] = "Hello world";
    char *p2 = strchr(s14, 'o');
    if (p2 != NULL) printf("First 'o' character: %c\n", *p2);
    else printf("No 'o' character\n");

    /*strrchr(str, control):
     * != NULL: last matching character
     * else: no matching character*/
    char s15[] = "Hello world";
    char *p3 = strrchr(s15, 'o');
    if (p3 != NULL) printf("Last 'o' character: %c\n", *p3);
    else printf("No 'o' character\n");

    /*strstr(str, control):
     * != NULL: first matching substring
     * else: no matching substring*/
    char s9[] = "Hello world";
    char s10[] = "world";
    char *p4 = strstr(s9, s10);
    if (p4 != NULL) printf("First matching substring: %s\n", p4);
    else printf("No matching substring\n");

    /*strtok_s(str, control, saveptr):
     * != NULL: token
     * else: no token*/
    char s11[] = "Hello world";
    char *p5 = strtok_s(s11, " ", (char **) &s11);
    while (p5 != NULL) {
        printf("%s\n", p5);
        p5 = strtok_s(NULL, " ", (char **) &s11);
    }
    return 0;
}

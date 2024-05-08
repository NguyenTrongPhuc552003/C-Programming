#include <stdio.h>
#include <windows.h>
#include <time.h>

int main(void) {
    time_t now = time(NULL);

    printf("%lld\n", now); // number of seconds since 1970-01-01 00:00:00 UTC
    Sleep(3000); // sleep for 5 seconds
    time_t next = time(NULL);
    printf("%lld\n", next);

    double diff = difftime(next, now); // difference in seconds
    printf("%f\n", diff);

    struct tm *gm_time = gmtime(&now); // convert to UTC time (struct tm)
    printf("%d-%d-%d %d:%d:%d\n", gm_time->tm_year + 1900,
                                         gm_time->tm_mon + 1,
                                         gm_time->tm_mday,
                                         gm_time->tm_hour,
                                         gm_time->tm_min,
                                         gm_time->tm_sec);

    struct tm *local_time = localtime(&now); // convert to local time (struct tm)
    printf("%d-%d-%d %d:%d:%d\n", local_time->tm_year + 1900,
                                         local_time->tm_mon + 1,
                                         local_time->tm_mday,
                                         local_time->tm_hour,
                                         local_time->tm_min,
                                         local_time->tm_sec);

    char* other_string = asctime(gm_time); // convert to string
    printf("%s", other_string);

    gm_time->tm_sec += 5; // add 5 seconds
    time_t new_time = mktime(gm_time); // convert back to time_t
    printf("Now: %lld\n", now);
    printf("New: %lld\n", new_time);

    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", gm_time); // convert to string with custom format
    printf("%s\n", buffer);

    clock_t start, end;
    start = clock(); // get current time in clock ticks
    Sleep(2000); // sleep for 2 seconds
    end = clock(); // get current time in clock ticks
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC; // calculate elapsed time, CLOCKS_PER_SEC is the number of clock ticks per second
    printf("Elapsed: %f\n", elapsed);
    return 0;
}

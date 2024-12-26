
#define _CRT_SECURE_NO_WARNINGS
#include <catch.hpp>
#include <natural_merge_sort.h>
TEST_CASE("Testing natural function") {
    FILE* f = fopen("naturalTest.txt", "w");
    int a[] = { 0, 0, 0, 0, 0, 0 };
    int b[] = { 0, 0, 0, 0, 0, 0 };
    for (int i = 0; i < 6; i++) {
        fprintf(f, "%d ", a[i]);
    }
    const char* name = "naturalTest.txt";
    fclose(f);
    natural(name);
    fclose(f);
    f = fopen("naturalTest.txt", "r");
    int r = 0;
    int c;
    for (int i = 0; i < 6; i++) {
        fscanf(f, "%d ", &c);
        if (c != b[i])
            r = 1;
    }
    REQUIRE(r == 0);
}
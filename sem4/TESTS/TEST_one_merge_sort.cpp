
#define _CRT_SECURE_NO_WARNINGS
#include <catch.hpp>
#include <one_phase_merge_sort.h>
TEST_CASE("Testing onePhase function") {
    FILE* f = fopen("onePhaseTest.txt", "w");
    int a[] = { 0 };
    int b[] = { 0 };
    for (int i = 0; i < 1; i++) {
        fprintf(f, "%d ", a[i]);
    }
    const char* name = "naturalTest.txt";
    fclose(f);
    onePhase(name);
    fclose(f);
    f = fopen("naturalTest.txt", "r");
    int r = 0;
    int c;
    for (int i = 0; i < 1; i++) {
        fscanf(f, "%d ", &c);
        if (c != b[i])
            r = 1;
    }
    REQUIRE(r == 0);
}
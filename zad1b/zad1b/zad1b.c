#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

struct ProbaMocy {
    char czas[30];
    float moc_w;
};

int main() {

    srand(time(NULL));

    struct ProbaMocy p[8];

    for (int i = 0; i < 8; i++) {
        p[i].moc_w = 100.0f + (rand() % 701);
        time_t currentTime;
        time(&currentTime);
        strcpy(p[i].czas, ctime(&currentTime));
        p[i].czas[strcspn(p[i].czas, "\n")] = '\0';
    }

    float dt = 15.0, E[7];

    for (int i = 0; i < 7; i++) {
        E[i] = ((p[i].moc_w + p[i + 1].moc_w) / 2) * (dt / 60.0f) * 0.001f;
    }

    for (int i = 0; i < 8; i++) {
        printf("[%d] %s %.2f\n", i, p[i].czas, p[i].moc_w);
    }

    float Esuma=0, sumaMocy=0;

    for (int i = 0; i < 7; i++) {
        Esuma += E[i];
    }

    for (int i = 0; i < 8; i++) {
        sumaMocy += p[i].moc_w;
    }

    float EsredniejMocy = (sumaMocy / 8.0f) * ((7.0f * dt) / 60.0f) * 0.001f;

    printf("Laczna energia: %.2f kWh\n", Esuma);
    printf("Energia ze sredniej mocy: %.2f kWh\n", EsredniejMocy);
    
    return 0;
}
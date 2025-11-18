#include <stdio.h>
#include <conio.h>
int main() {
    int cost[3][4] = {
        { 4, 7, 6, 3 },
        { 8, 5, 9, 2 },
        { 1, 4, 3, 8 }
    };
    int supply[3] = { 40, 35, 45 };
    int demand[4] = { 30, 25, 50, 15 };
    int allocation[3][4];
    int i, j;
    int min_cost, min_i, min_j, alloc;
    long total_cost = 0;
    int items_to_alloc = 0;
    int supply_left[3];
    int demand_left[4];
    int temp_cost[3][4];
    clrscr();
    printf("=======TRANSPORTATION PROBLEM========\n\n");
    printf("Cost Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%4d", cost[i][j]);
        }
        printf("   | Supply: %d\n", supply[i]);
    }
    printf("\nDemand:");
    for (j = 0; j < 4; j++) {
        printf("%4d", demand[j]);
    }
    printf("\n\n");
    for (i = 0; i < 3; i++) {
        supply_left[i] = supply[i];
        items_to_alloc += supply[i];
        for (j = 0; j < 4; j++) {
            allocation[i][j] = 0;
            temp_cost[i][j] = cost[i][j];
        }
    }
    for (j = 0; j < 4; j++) {
        demand_left[j] = demand[j];
    }
    while (items_to_alloc > 0) {
        min_cost = 9999;
        min_i = -1;
        min_j = -1;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 4; j++) {
                if (temp_cost[i][j] < min_cost) {
                    min_cost = temp_cost[i][j];
                    min_i = i;
                    min_j = j;
                }
            }
        }
        if (supply_left[min_i] < demand_left[min_j]) {
            alloc = supply_left[min_i];
        } else {
            alloc = demand_left[min_j];
        }
        allocation[min_i][min_j] = alloc;
        total_cost += (long)alloc * cost[min_i][min_j];
        items_to_alloc -= alloc;
        supply_left[min_i] -= alloc;
        demand_left[min_j] -= alloc;
        if (supply_left[min_i] == 0) {
            for (j = 0; j < 4; j++) {
                temp_cost[min_i][j] = 9999;
            }
        }
        if (demand_left[min_j] == 0) {
            for (i = 0; i < 3; i++) {
                temp_cost[i][min_j] = 9999;
            }
        }
    }
    printf("=======LEAST COST METHOD SOLUTION=======\n\n");
    printf("Allocation Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            if (allocation[i][j] > 0) {
                printf("%4d", allocation[i][j]);
            } else {
                printf("%4s", "-");
            }
        }
        printf("\n");
    }
    printf("\nTotal Transportation Cost: %ld", total_cost);
    getch();
return 0;
}

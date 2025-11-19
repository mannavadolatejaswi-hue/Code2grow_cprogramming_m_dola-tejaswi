#include <stdio.h>
int main() 
{
    int n;
    printf("Enter number of vehicles: ");
    scanf("%d", &n);
    int vehicleId[n], speed[n], lane[n];
    printf("\n--- Enter Vehicle Details ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nVehicle %d\n", i + 1);
        printf("Enter Vehicle ID: ");
        scanf("%d", &vehicleId[i]);
        printf("Enter Speed (km/hr): ");
        scanf("%d", &speed[i]);
        printf("Enter Lane (1, 2, 3 or 4): ");
        scanf("%d", &lane[i]);
    }
    int speedViolators[n], speedViolationCount = 0;
    for (int i = 0; i < n; i++) {
        if (speed[i] > 80) {
            speedViolators[speedViolationCount] = vehicleId[i];
            speedViolationCount++;
        }
    }
    int laneViolators[n], laneViolationCount = 0;
    for (int i = 0; i < n; i++) {
        if (lane[i] < 1 || lane[i] > 4) {
            laneViolators[laneViolationCount] = vehicleId[i];
            laneViolationCount++;
        }
    }
    int lane1 = 0, lane2 = 0, lane3 = 0, lane4 = 0;
    for (int i = 0; i < n; i++) {
        if (lane[i] == 1) lane1++;
        else if (lane[i] == 2) lane2++;
        else if (lane[i] == 3) lane3++;
        else if (lane[i] == 4) lane4++;
    }
    int highestSpeed = speed[0];
    int lowestSpeed = speed[0];
    int highestSpeedID = vehicleId[0];
    int lowestSpeedID = vehicleId[0];
    for (int i = 1; i < n; i++) {
        if (speed[i] > highestSpeed) {
            highestSpeed = speed[i];
            highestSpeedID = vehicleId[i];
        }
        if (speed[i] < lowestSpeed) {
            lowestSpeed = speed[i];
            lowestSpeedID = vehicleId[i];
        }
    }
    int maxLane = 1;
    int maxVehicles = lane1;
    if (lane2 > maxVehicles) { maxVehicles = lane2; maxLane = 2; }
    if (lane3 > maxVehicles) { maxVehicles = lane3; maxLane = 3; }
    if (lane4 > maxVehicles) { maxVehicles = lane4; maxLane = 4; }
    printf("\n=====SMART CITY TRAFFIC REPORT=====\n");
    printf("\n1. SPEED VIOLATIONS ( >60 km/hr ):\n");
    if (speedViolationCount == 0)
        printf("No speed violations.\n");
    else
        for (int i = 0; i < speedViolationCount; i++)
            printf("Vehicle ID: %d\n", speedViolators[i]);
    printf("\n2. LANE VIOLATIONS (Invalid Lane):\n");
    if (laneViolationCount == 0)
        printf("No lane violations.\n");
    else
        for (int i = 0; i < laneViolationCount; i++)
            printf("Vehicle ID: %d\n", laneViolators[i]);
    printf("\n3. LANE-WISE VEHICLE COUNT:\n");
    printf("Lane 1 : %d vehicles\n", lane1);
    printf("Lane 2 : %d vehicles\n", lane2);
    printf("Lane 3 : %d vehicles\n", lane3);
    printf("Lane 4 : %d vehicles\n", lane4);
    printf("\n4. SPEED ANALYSIS:\n");
    printf("Highest Speed : %d km/hr (Vehicle ID: %d)\n", highestSpeed, highestSpeedID);
    printf("Lowest Speed  : %d km/hr (Vehicle ID: %d)\n", lowestSpeed, lowestSpeedID);
    printf("\n5. TRAFFIC DENSITY:\n");
    printf("Lane %d has the highest traffic with %d vehicles.\n", maxLane, maxVehicles);
    printf("\n=========== END OF REPORT ===========\n");
    return 0;
}

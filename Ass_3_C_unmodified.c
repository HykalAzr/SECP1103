#include <stdio.h>

/*
    Author:
    1. Haikal bin Azhar
    2. Wong Ngei Ming
*/

float calculateBill(float units) {
    float totalBill = 0.0;
    
    if (units <= 200) {
        totalBill = units * 0.218;
    } else if (units <= 300) {
        totalBill = 200 * 0.218 + (units - 200) * 0.334;
    } else {
        totalBill = 200 * 0.218 + 100 * 0.334 + (units - 300) * 0.516;
    }

    return totalBill;
}

int main() {
    float totalAmount = 0.0;

    while (1) {
        char choice;
        printf("\nMenu:\n");
        printf("1. Information on tariff charges\n");
        printf("2. Calculate power consumption (kWh) and display the total bill\n");
        printf("3. Exit the calculator\n");
        printf("Enter your choice: ");
        
        scanf(" %c", &choice);

        if (choice == '1') {
            printf("\nTariff Charges:\n");
            printf("0 - 200 units: RM 0.218 per unit\n");
            printf("201 - 300 units: RM 0.334 per unit\n");
            printf("Above 300 units: RM 0.516 per unit\n");
        } else if (choice == '2') {
            float units;
            printf("\nEnter power consumption (kWh): ");
            scanf("%f", &units);

            float bill = calculateBill(units);
            float tax = bill * 0.06;
            float totalBill = bill + tax;
            
            printf("Total Bill: RM %.2f\n", totalBill);

            if (totalBill <= 20.00) {
                printf("Your bill is free.\n");
            } else {
                printf("Total bill: RM %.2f\n", totalBill);
            }

            totalAmount += totalBill;
            printf("Accumulated total: RM %.2f\n", totalAmount);
        } else if (choice == '3') {
            printf("\nThank you for using the calculator!\n");
            break;
        } else {
            printf("\nOption unavailable\n");
        }
    }

    return 0;
}
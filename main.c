#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Player stats
int health = 100;
int hunger = 50;
int thirst = 50;
int wood = 0;
int food = 0;
int water = 0;
int day = 1;

// Function to display player stats
void displayStats() {
    printf("\nDay: %d\n", day);
    printf("Health: %d\n", health);
    printf("Hunger: %d\n", hunger);
    printf("Thirst: %d\n", thirst);
    printf("Wood: %d | Food: %d | Water: %d\n", wood, food, water);
}

// Function to handle random events
void randomEvent() {
    int event = rand() % 4; // Random event selection
    switch(event) {
        case 0:
            printf("\nA wild animal attacked you! You lost 10 health.\n");
            health -= 10;
            break;
        case 1:
            printf("\nYou found a small river and collected 3 water.\n");
            water += 3;
            break;
        case 2:
            printf("\nYou discovered a berry bush and collected 3 food.\n");
            food += 3;
            break;
        case 3:
            printf("\nStormy weather! You couldn't collect resources today.\n");
            break;
    }
}

// Function to collect resources
void collectResources() {
    printf("\nYou spent time collecting resources.\n");
    wood += 2;
    food += 1;
    water += 1;
    randomEvent();
}

// Function to craft a shelter
void craftShelter() {
    if (wood >= 5) {
        printf("\nYou built a shelter! It provides protection.");
        wood -= 5;
    } else {
        printf("\nNot enough wood to build a shelter!\n");
    }
}

// Function to manage eating and drinking
void eatDrink() {
    if (food > 0) {
        food--;
        hunger += 10;
        printf("\nYou ate food. Hunger restored.\n");
    } else {
        printf("\nNo food available!\n");
    }
    if (water > 0) {
        water--;
        thirst += 10;
        printf("You drank water. Thirst restored.\n");
    } else {
        printf("No water available!\n");
    }
}

// Function to handle end-of-day status
void endOfDay() {
    hunger -= 10;
    thirst -= 10;
    if (hunger <= 0 || thirst <= 0) {
        health -= 20;
        printf("\nYou are starving or dehydrated! Health is decreasing.\n");
    }
    day++;
}

int main() {
    srand(time(0)); // Seed random number generator
    int choice;

    while (health > 0) {
        displayStats();
        printf("\nChoose an action:\n");
        printf("1. Collect Resources\n");
        printf("2. Craft Shelter\n");
        printf("3. Eat & Drink\n");
        printf("4. End Day\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                collectResources();
                break;
            case 2:
                craftShelter();
                break;
            case 3:
                eatDrink();
                break;
            case 4:
                endOfDay();
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }

        if (health <= 0) {
            printf("\nYou did not survive. Game over.\n");
            break;
        }
    }
    return 0;
}

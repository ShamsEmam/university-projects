#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    // Initialize variables
    int inventory = 5; // Initial inventory
    int reorderPoint = 3; // Reorder point
    int orderQuantity = 5; // Order quantity
    int totalCost = 0; // Total cost
    int holdingCost; // Holding cost
    int orderingCost = 20; // Ordering cost per order
    int demand; // Random demand for the day
    int days = 30; // Number of days to simulate

    // Initialize random number generation
    srand(time(0)); // To get different random numbers each time

    // Simulate the days
    for (int day = 1; day <= days; day++) {
        // Generate random demand (from 0 to 3)
        demand = rand() % 4; // Random demand between 0 and 3
        cout << "Day " << day << " - Demand: " << demand << endl;

        // Update inventory
        inventory -= demand;
        cout << "Inventory after demand: " << inventory << endl;

        // If inventory is less than or equal to reorder point, place a new order
        if (inventory <= reorderPoint) {
            inventory += orderQuantity; // Place new order
            totalCost += orderingCost; // Add ordering cost
            cout << "Reorder placed. New inventory: " << inventory << endl;
        }

        // Calculate holding cost
        holdingCost = inventory * 0.10; // Holding cost per unit
        totalCost += holdingCost; // Add holding cost to total cost
        cout << "Holding cost for the day: " << holdingCost << endl;

        // Show total cost at the end of each day
        cout << "Total cost at the end of day " << day << ": " << totalCost << endl;
        cout << "---------------------------------" << endl;
    }

    // After the loop, display the final results
    cout << "Final inventory: " << inventory << endl;
    cout << "Total cost after " << days << " days: " << totalCost << endl;

    return 0;
}

#include <iostream>
using namespace std;

// Class representing an Item with a name, value, and weight
class Item {
private:
    char name[20];  // Item name
    int value;      // Item value
    int weight;     // Item weight

public:
    // Function to input item details
    void inputItem() {
        cout << "Enter name of the item: ";
        cin >> name;

        // Ensuring valid input for item value
        do {
            cout << "Enter value of the item (positive integer): ";
            cin >> value;
            if (value <= 0) {
                cout << "Value must be a positive integer. Please try again.\n";
            }
        } while (value <= 0);

        // Ensuring valid input for item weight
        do {
            cout << "Enter weight of the item (positive integer): ";
            cin >> weight;
            if (weight <= 0) {
                cout << "Weight must be a positive integer. Please try again.\n";
            }
        } while (weight <= 0);
    }

    // Function to display item details
    void displayItem() const {
        cout << name << " (Value: " << value << ", Weight: " << weight << ")\n";
    }

    // Getter for the item's weight
    int getWeight() const {
        return weight;
    }

    // Getter for the item's value
    int getValue() const {
        return value;
    }

    // Function to calculate value-to-weight ratio
    double getValueWeightRatio() const {
        return (double)value / weight;
    }

    // Getter for the item's name
    const char* getName() const {
        return name;
    }
};

// Function to maximize total value in the knapsack
void maximizeValueKnapsack(Item items[], int n, int maxWeight) {
    int totalValue = 0;  // Total value of selected items
    int totalWeight = 0; // Total weight of selected items
    cout << "\nSelected items for maximum value:\n";

    // Sorting items based on value in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].getValue() < items[j + 1].getValue()) {
                // Swap items
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    // Selecting items based on value while staying within weight limit
    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].getWeight() <= maxWeight) {
            totalWeight += items[i].getWeight();
            totalValue += items[i].getValue();
            cout << items[i].getName() << " (Value: " << items[i].getValue() << ", Weight: " << items[i].getWeight() << ")\n";
        } else {
            // Handling fractional item if weight limit is exceeded
            int remainingWeight = maxWeight - totalWeight;
            if (remainingWeight > 0) {
                double valueFraction = (double)items[i].getValue() * (remainingWeight / (double)items[i].getWeight());
                totalValue += valueFraction;
                totalWeight += remainingWeight;
                cout << items[i].getName() << " (Value: " << valueFraction << ", Weight: " << remainingWeight << " - Fractional)\n";
            }
            break; // No need to check further items
        }
    }

    // Displaying total value and weight
    cout << "Total value: " << totalValue << "\n";
    cout << "Total weight: " << totalWeight << "\n";
}

// Function to minimize total weight in the knapsack
void minimumWeightKnapsack(Item items[], int n, int maxWeight) {
    int totalValue = 0;  // Total value of selected items
    int totalWeight = 0; // Total weight of selected items
    cout << "\nSelected items for minimum weight:\n";

    // Sorting items based on weight in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].getWeight() > items[j + 1].getWeight()) {
                // Swap items
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    // Selecting items based on weight while staying within weight limit
    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].getWeight() <= maxWeight) {
            totalWeight += items[i].getWeight();
            totalValue += items[i].getValue();
            cout << items[i].getName() << " (Value: " << items[i].getValue() << ", Weight: " << items[i].getWeight() << ")\n";
        } else {
            // Handling fractional item if weight limit is exceeded
            int remainingWeight = maxWeight - totalWeight;
            if (remainingWeight > 0) {
                double valueFraction = (double)items[i].getValue() * (remainingWeight / (double)items[i].getWeight());
                totalValue += valueFraction;
                totalWeight += remainingWeight;
                cout << items[i].getName() << " (Value: " << valueFraction << ", Weight: " << remainingWeight << " - Fractional)\n";
            }
            break; // No need to check further items
        }
    }

    // Displaying total value and weight
    cout << "Total value: " << totalValue << "\n";
    cout << "Total weight: " << totalWeight << "\n";
}

// Function to maximize value-to-weight ratio in the knapsack
void maximizeValueWeightRatioKnapsack(Item items[], int n, int maxWeight) {
    int totalValue = 0;  // Total value of selected items
    int totalWeight = 0; // Total weight of selected items
    cout << "\nSelected items for maximum value/weight ratio:\n";

    // Sorting items based on value-to-weight ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].getValueWeightRatio() < items[j + 1].getValueWeightRatio()) {
                // Swap items
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    // Selecting items based on value-to-weight ratio while staying within weight limit
    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].getWeight() <= maxWeight) {
            totalWeight += items[i].getWeight();
            totalValue += items[i].getValue();
            cout << items[i].getName() << " (Value: " << items[i].getValue() << ", Weight: " << items[i].getWeight() << ")\n";
        } else {
            // Handling fractional item if weight limit is exceeded
            int remainingWeight = maxWeight - totalWeight;
            if (remainingWeight > 0) {
                double valueFraction = (double)items[i].getValue() * (remainingWeight / (double)items[i].getWeight());
                totalValue += valueFraction;
                totalWeight += remainingWeight;
                cout << items[i].getName() << " (Value: " << valueFraction << ", Weight: " << remainingWeight << " - Fractional)\n";
            }
            break; // No need to check further items
        }
    }

    // Displaying total value and weight
    cout << "Total value: " << totalValue << "\n";
    cout << "Total weight: " << totalWeight << "\n";
}

// Main function for the program
int main() {
    int n; // Number of items

    // Ensuring valid input for the number of items
    do {
        cout << "Enter the number of items (positive integer): ";
        cin >> n;
        if (n <= 0) {
            cout << "Number of items must be a positive integer. Please try again.\n";
        }
    } while (n <= 0);

    // Array to store items
    Item items[100];

    // Input details for each item
    for (int i = 0; i < n; i++) {
        cout << "\nItem " << i + 1 << ":\n";
        items[i].inputItem();
    }

    // Input maximum weight for the knapsack
    int maxWeight;
    do {
        cout << "\nEnter the maximum weight allowed for the knapsack (positive integer): ";
        cin >> maxWeight;
        if (maxWeight <= 0) {
            cout << "Maximum weight must be a positive integer. Please try again.\n";
        }
    } while (maxWeight <= 0);

    // User selects the strategy for the knapsack problem
    int choice;
    do {
        cout << "\nChoose a strategy:\n";
        cout << "1. Maximize Value\n";
        cout << "2. Minimize Weight\n";
        cout << "3. Maximize Value/Weight Ratio\n";
        cout << "4. Try All Strategies\n";
        cout << "Enter your choice (1/2/3/4): ";
        cin >> choice;
        if (choice < 1 || choice > 4) {
            cout << "Invalid choice. Please enter 1, 2, 3, or 4.\n";
        }
    } while (choice < 1 || choice > 4);

    // Displaying entered items
    cout << "\nItems entered:\n";
    for (int i = 0; i < n; i++) {
        items[i].displayItem();
    }
    cout << "Maximum weight allowed: " << maxWeight << endl;

    // Execute selected strategy
    switch (choice) {
        case 1:
            cout << "\nYou chose to maximize value.\n";
            maximizeValueKnapsack(items, n, maxWeight);
            break;
        case 2:
            cout << "\nYou chose to minimize weight.\n";
            minimumWeightKnapsack(items, n, maxWeight);
            break;
        case 3:
            cout << "\nYou chose to maximize value/weight ratio.\n";
            maximizeValueWeightRatioKnapsack(items, n, maxWeight);
            break;
        case 4:
            cout << "\nTrying all strategies...\n";
            maximizeValueKnapsack(items, n, maxWeight);
            minimumWeightKnapsack(items, n, maxWeight);
            maximizeValueWeightRatioKnapsack(items, n, maxWeight);
            break;
    }

    return 0;
}


# travelling_backpack_using-knapsack-problem
# Knapsack Traveling Backpack

## Project Overview
The **Knapsack Traveling Backpack** project is a C++ implementation of the knapsack problem, which involves selecting a subset of items with given weights and values to maximize the total value while staying within a specified weight limit. The project implements three different strategies to solve the knapsack problem:
1. **Maximizing Total Value**
2. **Minimizing Total Weight**
3. **Maximizing Value-to-Weight Ratio**

The project also includes an option to explore all strategies for comparison.

## Features
- **Multiple Knapsack Strategies**: Users can choose between three methods of filling the backpack.
- **Interactive Input**: The program prompts the user to input item details and the maximum weight the knapsack can carry.
- **Error Handling**: Ensures correct user input for item values and weights.
- **Equal Weight Fulfillment**: Adjustments are made to ensure the total weight of selected items matches the maximum weight provided by the user.

## How It Works
1. **Maximize Total Value**: The algorithm selects items in descending order of value to get the maximum value possible without exceeding the weight limit.
2. **Minimize Total Weight**: The algorithm selects items in ascending order of weight, ensuring the lightest items are chosen first.
3. **Maximize Value-to-Weight Ratio**: The algorithm selects items based on the highest value-to-weight ratio to ensure optimal value per unit of weight.

## Technologies Used
- **C++**: Core language used for implementation.

## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/knapsack-traveling-backpack.git
   cd knapsack-traveling-backpack

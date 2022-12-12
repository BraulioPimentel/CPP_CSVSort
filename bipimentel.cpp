/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function to sort array using selection sort
void selectionSort(vector<int>& numbers)
{
	int n = numbers.size();
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (numbers[j] < numbers[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(numbers[min_idx], numbers[i]);
    }
}

// Function to find the most common numbers
vector<int> findMostCommon(vector<int>& numbers)
{
    int n = numbers.size();
    vector<int> common;
    int curr_count = 1, max_count = 1; 
    for (int i = 1; i < n; i++)
    {
        if (numbers[i] == numbers[i - 1])
            curr_count++;
        else
        {
            if (curr_count > max_count)
            {
                max_count = curr_count;
                common.clear();
                common.push_back(numbers[i - 1]);
            }
            else if (curr_count == max_count)
                common.push_back(numbers[i - 1]);
            curr_count = 1;
        }
    }

    // If last element is most common
    if (curr_count > max_count)
    {
        max_count = curr_count;
        common.clear();
        common.push_back(numbers[n - 1]);
    }
    else if (curr_count == max_count)
        common.push_back(numbers[n - 1]);

    return common;
}

int main()
{
    // Open powerball.csv file
    ifstream file("powerball.csv");
    // Vector to store all numbers
    vector<int> numbers;

    // Read numbers from file
    string line;
    while (getline(file, line))
    {
        int num = stoi(line);
        numbers.push_back(num);
    }

    // Sort numbers using selection sort
    selectionSort(numbers);

    // Find the most common numbers
    vector<int> common = findMostCommon(numbers);

    // Print the most common numbers
    for (int num : common)
        cout << num << " ";
    cout << endl;

    return 0;
}

*/
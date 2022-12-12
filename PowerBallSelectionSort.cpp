
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;



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
    vector<vector<string>> powerballData; // 2D vector to store powerball data
    ifstream inputFile("powerball.csv"); // input file stream to read from powerball.csv
    // exit program if input file could not be opened
    if (!inputFile.is_open())
    {
        cout << "Error opening input file" << endl;
        return 1;
    }

    // read data from powerball.csv into 2D vector
    string line;
    while (getline(inputFile, line))
    {
        vector<string> data;
        size_t pos = 0;
        string token;

        // split line by comma and store each field in data vector
        while ((pos = line.find(',')) != string::npos)
        {
            token = line.substr(0, pos);
            data.push_back(token);
            line.erase(0, pos + 1);
        }
        data.push_back(line); // add last field to data vector
        powerballData.push_back(data); // add data vector to powerballData vector
    }

    // close input file
    inputFile.close();

    // selection sort on powerballData vector
    for (int i = 0; i < powerballData.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < powerballData.size(); j++)
        {
            // compare dates to find index of minimum date
            if (powerballData[j][0] < powerballData[minIndex][0])
                minIndex = j;
        }

        // swap rows at minIndex and i
        vector<string> temp = powerballData[i];
        powerballData[i] = powerballData[minIndex];
        powerballData[minIndex] = temp;
    }

    // print sorted powerball data
    cout << "Sorted Powerball Data: " << endl;
    for (int i = 0; i < powerballData.size(); i++)
    {
        for (int j = 0; j < powerballData[i].size(); j++)
            cout << powerballData[i][j] << ", ";
        cout << endl;
    }

    return 0;
}

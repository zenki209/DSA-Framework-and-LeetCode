#include <iostream>
#include "bits/stdc++.h"
using namespace std;

void solution(vector<int> A, int K){
    // Assume A[i] contains positive numbers
    int size = A.size();
    vector<string> numStr;
    int maxLength = -1;
    for(int i = 0; i < size; i++){
        string str = std::to_string(A[i]);
        numStr.push_back(str);
        int length = str.length();
        maxLength = max(maxLength, length);
    }
    
    // Implement horizontal
    string plus = "+";
    string minus = "";
    int digit = maxLength;
    
    // Case no input
    if(maxLength == -1) return; 
    while(digit > 0){
        minus += '-';
        digit--;
    }
    // Implement vertical
    string bar = "|";
    
    // Process string data
    for(int i = 0; i < size; i++){
        if(numStr[i].length() < maxLength){
            numStr[i] = std::string(maxLength - numStr[i].length(), ' ') + numStr[i];
        }
    }
    
    // Arrange K
    if(K > size) K = size;
    
    // Process horizontal
    string horizontal = "";
    for(int i = 0; i < K; i++){
        horizontal += plus;
        horizontal += minus; 
    }
    horizontal += plus; // final plus
    
    // Init some variables
    int totalPrint = (size % K  == 0) ? (size / K) : (size / K) + 1;
    int counter = 1;
    int index = 0;
    bool missing = 0;
    int missingLength = 0;
    
    // Print the horizontal
    cout << horizontal << endl;
    // Print the table
    for(int i = 0; i < totalPrint; i++){
        // Continue print the data
        while(counter % K != 0){
            if(index >= size) {
                break;
            }
            else cout << bar << numStr[index];
            counter++;
            index++;
        }
        // Conor table. Index is less than 1 by the Counter
        // If not the last element of row
        if(index >= size){
            cout << bar << endl;
            missing = 1;
            // Only the first will need 2, others will need 1.
            missingLength = maxLength  * (index % K) + ((index - 1) % K) + 2;
            break;
        }
        // Normal last element
        else cout << bar << numStr[index] << bar << endl;
        index++;
        counter++;
        // Print the horizontal
        cout << horizontal << endl;
    }
    cout << horizontal.substr(0, missingLength);
}

int main()
{
    vector<int> A = {4, 35, 80, 123, 12345, 44, 8, 5, 24, 3};
    solution(A, 4);

    return 0;
}
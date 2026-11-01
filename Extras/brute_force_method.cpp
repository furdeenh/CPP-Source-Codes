// Replace __ with your code
#include <iostream>
#include <vector>

using namespace std;

vector<int> occurences;

// Function to search for a pattern in the text using brute force method
void brute_force(string text, string pattern){
    // Write your code here
    for (int i = 0; i < text.length(); ++i)
    {
        for (int j = 0; j < pattern.length(); ++j)
        {
            bool match = text[i+j] == pattern[j];
            if (!match) break;
            if (j == pattern.length() - 1){
                occurences.emplace_back(i);
            }
        }
    }
}

int main(){
    string text =    "CODEWITHCODER";
    string pattern = "CODE";
    brute_force(text, pattern);
    
    for(const auto elt: occurences){
      std::cout  << "Matching pattern: index "<< elt <<  " to " << elt + pattern.length() - 1 << '\n';
    }
}
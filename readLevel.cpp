#include <iostream>
#include <cmath>
#include <string>

int checkLevel(std::string s); //prototyping function 

int main()
{
    //initializing variables
    std::string s;
    int check; 

    //prompt user for snippets and add it to the variable s
    std::cout << "enter snippets :" << std::endl; std::getline(std::cin, s);
    
    //checking..
    check = checkLevel(s);

    //mitigating edge cases for high number and very low number
    if(check < 1)
    {
        std::cout << "grade below 1" << std::endl;
    }
    else if(check >= 16)
    {
        std::cout << "grade higher than 16" << std::endl;
    }
    else
    {
        std::cout << "Grade " << check << std::endl;
    }

}

//logic for checking reading level
int checkLevel(std::string s)
{
    int words = 1;
    int sentences = 0;
    int letters = 0;

    for(int i = 0; i <= s.length() ; i++) // looping through the snippets
    {
        char character = s[i]; //adding the current character to a variable with type char

        if(isalpha(character))//checking for letters
        {
            letters++;
        }
        else if(isblank(character) && s[i+1] != ' ')//checking for words
        {
            words++;
        }
        else if(character == '.' || character == '?'|| character == '!')//checking for sentences
        {
            sentences++;
        }
    }

    //deciding the level with coleman-liau index
    float L = (letters /(float) words)* 100;
    float S = (sentences / (float) words) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    return index;
}  
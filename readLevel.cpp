#include <iostream>
#include <cmath>
#include <string>

int checkLevel(std::string s);

int main()
{
    std::string s;
    int check; 

    std::cout << "enter snippets :" << std::endl; std::getline(std::cin, s);
    
    check = checkLevel(s);

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

int checkLevel(std::string s)
{
    int words = 1;
    int sentences = 0;
    int letters = 0;

    for(int i = 0; i <= s.length(); i++)
    {
        char character = s[i];

        if(isalpha(character))
        {
            letters++;
        }
        else if(isblank(character) && s[i+1] != ' ')
        {
            words++;
        }
        else if(character == '.' || character == '?'|| character == '!')
        {
            sentences++;
        }
    }

    float L = (letters /(float) words)* 100;
    float S = (sentences / (float) words) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    return index;
}  
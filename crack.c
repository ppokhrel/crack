/*
 * Author: PJ Pokhrel
 * Purpose: A cryptography project program that takes a password hash that was generated using Unix/Linux crypt function and cracks some simple passwords which are upto five characters long composed of only upper and lowecase letters.
 * Language:  C
 */

#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>

bool stringcomp(string a, string b);
void extractSalt(string s);
bool checkCommonPasswords(string s, string hash);

char salt[] = "xx";

int main(int argc, string argv[])
{
    string key = "L";
    string hash = "";
    string letters = "abcdefghijklmnopqrstuvwzyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    // Validate command-line argument count
    if (argc != 2)
    {
        printf("Usage: /.crack hash\n");
        return 1;
    }
    
    // Assign user provided hash to a string
    hash = argv[1];
    
    // Call extractSalt function get the salt in the hash
    extractSalt(hash);
    
    // Check common passwords. If password already cracked then exit program, continue otherwise
    if (checkCommonPasswords(salt,hash))
    {
        return 0;
    }
    // Create a character array which will be used in the for loop below to create a string whose length will be one
    char oneletter[2];
    //printf("going to check password with 1 character\n");
    for (int i = 0; i < 52; i++)
    {
        oneletter[0] = letters[i];
        
        // Call crypt function, which returns a hash, then call stringcomp function to evaluate if hash is similar to the user provided hash
        if (stringcomp(crypt(oneletter, salt), hash))
        {
            printf("%s\n", oneletter);
            return 0;
        } 
    }
    // Create a character array which will be used in the for loop below to create a string of length two
    char twoletter[3];
    //printf("going to check password with 2 characters\n");
    for (int i = 0; i < 52; i++)
    {
        // Assign 1st character in our array to the 
        twoletter[0] = letters[i];
        for (int j = 0; j < 52; j++)
        {
            // Assign 2nd character in our array to the ith char in letters char array
            twoletter[1] = letters[j];
            if (stringcomp(crypt(twoletter, salt), hash))
            {
                printf("%s\n", twoletter);
                return 0;
            }
        }
    }
    // Create a char array that will be used to create a string thats three char long
    char threeletter[4];
    //printf("going to check password with 3 characters\n");
    for (int i = 0; i < 52; i++)
    {
        // Replace first char in our array with the ith char in the char array
        threeletter[0] = letters[i];
        for (int j = 0; j < 52; j++)
        {
            // Replace second char in our array with the jth char in the char array
            threeletter[1] = letters[j];
            for (int k = 0; k < 52; k++)
            {
                // Replace third char in our array with the kth char in the char array
                threeletter[2] = letters[k];
                // Call crypt and stringcomp function with the new string whose length is 3 letters
                if (stringcomp(crypt(threeletter, salt), hash))
                {
                    printf("%s\n", threeletter);
                    return 0;
                }
            }
         
        }
    }
    // Create an array whose length is 4 letters
    char fourletter[5];
    //printf("going to check password with 4 characters\n");
    for (int i = 0; i < 52; i++)
    {
        fourletter[0] = letters[i];
        for (int j = 0; j < 52; j++)
        {
            fourletter[1] = letters[j];
            for (int k = 0; k < 52; k++)
            {
                fourletter[2] = letters[k];
                for (int l = 0; l < 52; l++)
                {
                    fourletter[3] = letters[l];
                    // Call crypt and stringcomp function with the new string whose length is 4 letters
                    if (stringcomp(crypt(fourletter, salt), hash))
                    {
                        printf("%s\n", fourletter);
                        return 0;
                    }
                }
                
            }
         
        }
    }
    // Create an array whose length is 5 letters
    char fiveLetter[6];
    //printf("going to check password with 5 characters\n");
    for (int i = 0; i < 52; i++)
    {
        fiveLetter[0] = letters[i];
        for (int j = 0; j < 52; j++)
        {
            fiveLetter[1] = letters[j];
            for (int k = 0; k < 52; k++)
            {
                fiveLetter[2] = letters[k];
                for (int l = 0; l < 52; l++)
                {
                    fiveLetter[3] = letters[l];
                    for (int m = 0; m < 52; m++)
                    {
                        fiveLetter[4] = letters[m];
                        // Call crypt and stringcomp function with the new string whose length is 5 letters
                        if (stringcomp(crypt(fiveLetter, salt), hash))
                        {
                            printf("%s\n", fiveLetter);
                            return 0;
                        }
                    }
                    
                    
                }
                
            }
         
        }
    }
}

// Compares two strings for equality
bool stringcomp(string a, string b)
{ 
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

// Saves the first two characters in a string to a global variable
void extractSalt(string s)
{
    salt[0] = s[0];
    salt[1] = s[1];
}
// checks common keys and returns true if match found
bool checkCommonPasswords(string s, string hash)
{
    //printf("checkcommonpasswords\n");
    string passwords[20] = {"LOL","brian","bjbrown","emc","greg","jana","malan","rob","walk","LOL","qwert","abcde","yale","lloyd","loyd","abcde","malan","rob","abcde","loyd"};
    for (int i = 0; i < 20; i++)
    {
        string hash1 = crypt(passwords[0], salt);
        if (stringcomp(hash, hash1))
        {
            printf("%s\n",passwords[0]);
            return true;
        }
    }
    return false;
}

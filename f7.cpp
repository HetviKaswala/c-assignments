/*
* File          : f7.cpp
* Project       : SENG1000 Focused #7
* Programmer    : Hetvi Kaswala
* First Version : 2024-03-21
* Description   : This program will create a text file and a binary file.
*/

#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable : 4996)// for getting getNum()
// getting array from the requriements. 
const unsigned short kBinaryData[] = { 26946, 24942, 31090,25632, 29793,  8289, 28518,  8306, 28537,33141, 39308 };

int main() 
{
    // To reate Text File
    FILE* textFile = fopen("myTextFile.txt", "w");
    const char* textLines[] = { "This is line 1.", "This is line 2." };
    for (int i = 0; i < 2; i++) 
    {
        fprintf(textFile, "%s\n", textLines[i]);
    }
    fclose(textFile);

    // To Create Binary File
    FILE* binaryFile = fopen("myEvenDataList.data", "wb");
    for (size_t i = 0; i < sizeof(kBinaryData) / sizeof(kBinaryData[0]); i++) 
    {
        if (kBinaryData[i] % 2 == 0) 
        {
            fwrite(&kBinaryData[i], sizeof(unsigned short), 1, binaryFile);
        }
    }
    fclose(binaryFile);
    return 0;
}

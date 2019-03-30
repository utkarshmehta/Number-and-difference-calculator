/* UTKARSH MEHTA
Assignment 3
QUESTION 5
CURRENT TRENDS IN PROGRAMMING */
#include <iostream>
#include <iomanip>
#include <fstream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <unordered_map>
using namespace std;
//Globally declaring the Array with minimum length and increasing according the elements of the file
int *numbers = new int[1];

int *differenceArray = new int[1];

//unordered_map<int, int> hm;
int findFrequencyOfNumbers(int lengthOfArray, int x, int* arr)
{
    int count = 0;
    for (int i=0; i < lengthOfArray; i++)
        if (arr[i] == x)
            count++;
    return count;
}
//This function assigns values to the two dimesional array(length of array , position of the unique elements, frequency of elements , array)
void assigningValuesToTwoDimensionaArray(int totalLength, int length, int* positionArray, int* frequencyArray, int* arr)
{
//
    int twoDimensionalArray[length][3];
    for(int i=0; i<length; i++)
    {


        twoDimensionalArray[i][0]=arr[positionArray[i]];
        twoDimensionalArray[i][1]= frequencyArray[i];
        twoDimensionalArray[i][2]= differenceArray[i];

    }

    for(int i=0; i<length; i++)
    {
        cout<<twoDimensionalArray[i][0]<<"\t"<<twoDimensionalArray[i][1]<<"\t";
        if(i!=length-1)

            cout<<twoDimensionalArray[i][2]<<endl;
        else
            cout<<endl;

    }
}
//This function is used to check existence of unique elements, if exists returns false else true
bool checkExistanceOfANumberInArray(int length)
{

    bool result = true;
    for(int i=0; i<=length-1;i++)
    {

        if(numbers[length] == numbers[i])
        {
            result = false;
            break;
        }
    }

    return result;
}
int main() {
    int x;
    ifstream inFile;
    string filename;
    cout<<"Enter filename\n";
    cin>>filename;
    inFile.open(filename, std::ios_base::in);

    //Error checking
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    //initially , assigning length of numbers to '0'
    int checkLengthOfNumbers =0;

    //Reading file
    while (inFile >> x)
    {//
        numbers[checkLengthOfNumbers] =x;
        checkLengthOfNumbers++;
    }
    //Printing the values from the text file
    cout<<"The array is"<<endl;
    int arr[checkLengthOfNumbers];
    //size increases as per the elements
    cout<<"[ ";
    for(int arrayLength =0; arrayLength<checkLengthOfNumbers; arrayLength++)
    {
        arr[arrayLength] = numbers[arrayLength];
        cout<<numbers[arrayLength];
        //condition to check the last element
        if(arrayLength!=checkLengthOfNumbers-1)

            cout<<", ";
    }
    cout<<" ]"<<endl<<endl;
    //This stores the position(first) of unique elements of array
    int posArray[checkLengthOfNumbers];
    //This stores the frequency of unique elements of array
    int freqArray[checkLengthOfNumbers];

    int countNumbers=0;
    //This is for checking existence of multiple elements

    for(int checkExistance=0; checkExistance<checkLengthOfNumbers;checkExistance++)
    {
        bool result = checkExistanceOfANumberInArray(checkExistance);
        if(result)
        {
            posArray[countNumbers] =checkExistance;
            countNumbers++;
        }
    }
    //This is used for calculating the frequency of a number
    for(int frequencyCal=0; frequencyCal<countNumbers; frequencyCal++)
    {


        freqArray[frequencyCal] = findFrequencyOfNumbers(checkLengthOfNumbers, arr[posArray[frequencyCal]], arr);
    }

    //This is used to calculate frequency difference between consequitive elements
    for(int differenceCal =0; differenceCal < countNumbers-1; differenceCal++)
    {
        int difference  = freqArray[differenceCal] - freqArray[differenceCal+1];
        //It is used to assign positive value if difference comes out as a negative value
        if(difference<0)
            difference= -1 *difference;

        differenceArray[differenceCal] = difference;
    }
    //AssignvaluesToTwoDimensionalArray is called which takes in length, totalnumbers, array position, frequency & the whole array
    assigningValuesToTwoDimensionaArray(checkLengthOfNumbers, countNumbers, posArray, freqArray, arr);

    inFile.close();

    return 0;
}
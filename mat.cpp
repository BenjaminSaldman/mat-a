#include <string>
#include "mat.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

bool checkValid(char a){
    if(a=='\n' || a=='\t' || a==' '|| a=='\r'){
        return false;
    }
    return true;
}
namespace ariel{

string mat(int colmn, int row, char c1, char c2){
    if(checkValid(c1)==false || checkValid(c2)==false || row%2==0 || colmn%2==0 || row<=0 || colmn<=0){
        throw invalid_argument{"Invalid arguments!"};
    }
    string ans="";
    char** arr=new char*[row];
    for(int i=0;i<row;i++){
        arr[i]=new char[colmn];
    }
    char currChar=c1;
    int layers = row<colmn? row:colmn;
    layers/=2;
    layers++;
    for(int i=0;i<layers;i++)
    {
        for(int j=i;j<colmn-i;j++)
        {
            arr[i][j]=currChar;
            arr[row-i-1][j]=currChar;
        }
        for(int j=i;j<row-i;j++)
        {
            arr[j][i]=currChar;
            arr[j][colmn-i-1]=currChar;
        }
        if(currChar==c1)
            currChar=c2;
        else
        currChar=c1;
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<colmn;j++)
        {
            ans+=arr[i][j];
        }
        ans+='\n';
    }
    for(int i=0;i<row;i++){
        delete[] arr[i];
    }
    delete[] arr;
    return ans;
}
};
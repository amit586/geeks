#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'getMinInsertions' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY firstArray
 *  2. INTEGER_ARRAY secondArray
 */

int getMinInsertions(vector<int> firstArray, vector<int> secondArray) {
    unordered_map<int,vector<int>> um;
    for(int i=0;i<firstArray.size();i++)
    {
        if(um.find(firstArray[i])!=um.end())
        {
            um[firstArray[i]].push_back(i);
        }
        else
            {
                vector<int> temp;
                temp.push_back(i);
                um[firstArray[i]]=temp;
            }
    }

    int min_ind = -1;
    int count=0;
    for(int i=0;i<secondArray.size();i++)
    {
        if(um.find(secondArray[i])==um.end())
        {
            count++;
        }
        else{
            vector<int> temp = um[secondArray[i]];
            int j;
            for(int j=0;j<temp.size();j++)
            {
                if(temp[j]>min_ind)
                {
                    min_ind=temp[j];
                    break;
                }
            }
            if(j==(int)temp.size())
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string firstArray_count_temp;
    getline(cin, firstArray_count_temp);

    int firstArray_count = stoi(ltrim(rtrim(firstArray_count_temp)));

    vector<int> firstArray(firstArray_count);

    for (int i = 0; i < firstArray_count; i++) {
        string firstArray_item_temp;
        getline(cin, firstArray_item_temp);

        int firstArray_item = stoi(ltrim(rtrim(firstArray_item_temp)));

        firstArray[i] = firstArray_item;
    }

    string secondArray_count_temp;
    getline(cin, secondArray_count_temp);

    int secondArray_count = stoi(ltrim(rtrim(secondArray_count_temp)));

    vector<int> secondArray(secondArray_count);

    for (int i = 0; i < secondArray_count; i++) {
        string secondArray_item_temp;
        getline(cin, secondArray_item_temp);

        int secondArray_item = stoi(ltrim(rtrim(secondArray_item_temp)));

        secondArray[i] = secondArray_item;
    }

    int result = getMinInsertions(firstArray, secondArray);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

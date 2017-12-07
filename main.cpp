#include <iostream>
#include <fstream>
#include <cassert>

#include <stdlib.h>
#include <assert.h>
#include <string.h>

using namespace std;

int MAXIMUM_SIZE = 1000;
int MAXIMUM_LENGTH = 40;

char** create_array(void);
int read_input(char**, istream&);
bool is_unique(char**, char*, int);

int main(int argc, char** argv)
{
    assert(argc);

    ifstream input_text(argv[1]);
    if (input_text.fail())
    {
        cerr << "Unable to open file: " << argv[1] << endl;
        exit(1);
    }

    ofstream output_text(argv[2]);

    char** arrayTest = create_array();
    read_input(arrayTest, input_text);

    input_text.close();
    output_text.close();


}

char** create_array(void)
{
    return new char* [MAXIMUM_SIZE];
}

int read_input(char** words, istream& inp)
{
    char ch;
    int i = 0;

    while(!inp.eof())
    {
        words[i] = new char[MAXIMUM_LENGTH];

        for (int j = 0; j < MAXIMUM_LENGTH; j++)
        {
            ch = inp.get();

            if (ch == '\0' || ch == '+' || ch == '\n' || ch == ' ' || inp.eof() == true)
            {
                words[i][j] = '\0';

                if (!is_unique(words, words[i], i))
                {
                    delete[] words[i];
                    words[i] = 0;
                    break;
                }

                i++;
                break;
            }

            words[i][j] = ch;
        }
    }

    cout << i << endl;
    cout << words[0] << endl;
    cout << words[1] << endl;
    cout << words[2] << endl;

    return i;
}

bool is_unique(char** words, char* cur_word, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(words[i], cur_word) == 0)
            return false;
    }

    return true;
}

#include "main.h"

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
    int value = read_input(arrayTest, input_text);

    sort(arrayTest, value);
    write_output(arrayTest, output_text, value);
    removeArray(arrayTest, value);

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

void sort(char** array, int n)
{
    for (int i = 1; i < n; i++)
    {
        char* value = array[i];
        int hole = i;

        while (hole > 0 && *(array[hole - 1]) > *value)
        {
            array[hole] = array[hole -1];
            hole--;
        }

        array[hole] = value;
    }
}

void write_output(char** words, ostream& outp, int n)
{
    for (int i = 0; i < n; i++)
    {
        outp << words[i] << "   " << strlen(words[i]) << endl;;
    }
}

void removeArray(char** words, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] words[i];
    }
    delete[] words;
}

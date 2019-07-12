#include <iostream>
#include <istream>
#include <string>

using namespace std;

int num_words(string str);
void add_commas(string &str);
// finds commas in the pargraph and returns the words previous and next to it.
void get_words(int i, string &str);
// adds a comma before or after (where) a give `word` in a `paragraph`
void add_commas_to(string &paragraph, string word, char where);

// value to indicate whether or not you should perform the algorithm again.
int sentinel = 1;

int main(void)
{
    string paragraph;
    // get a string (min-length: 2) from the user
    do
    {
        getline(cin, paragraph);
    } while (paragraph.length() < 2);

    // need to store a copy to manipulate it.
    string paragraph_copy = paragraph;

    // Number of words in the paragraph
    int len = num_words(paragraph);

    do
    {
        add_commas(paragraph);
    } while (sentinel == 1);

    cout << paragraph << endl;

    return 0;
}

int num_words(string str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || (str[i] == '.' && str[i + 1] == ' '))
        {
            len++;
        }
    }

    return len;
}

void add_commas(string &paragraph)
{
    for (int i = 0, n = paragraph.length(); i < n; i++)
    {
        if (paragraph[i] == ',')
        {
            // get the before and after words.
            get_words(i, paragraph);
        }
    }
}

void get_words(int i, string &str)
{
    // or store results in global array with not duplicates.

    int j = i;
    while (str[j - 1] != ' ' && (j - 1) != -1)
    {
        j--;
    }
    // make a variable for it
    string prev;
    // get the previous word
    for (int k = j; k < i; k++)
    {
        prev.push_back(str[k]);
    }
    add_commas_to(str, prev, 'a');

    // get the next word
    int end = i + 1;
    while (str[end + 1] != ' ' && str[end + 1] != '.')
    {
        end++;
    }
    // next word variable
    string next;
    for (int k = i + 2; k < end + 1; k++)
    {
        next.push_back(str[k]);
    }
    add_commas_to(str, next, 'b');
    // store into global array;
    // TODO
}

void add_commas_to(string &paragraph, string word, char where)
{
    size_t found = paragraph.find(word);
    int k = 0;
    while (found != -1 && found < paragraph.length() - word.length())
    {
        if (where == 'b')
        {
            if (paragraph[found - 2] != ',' && paragraph[found - 2] != '.')
            {
                k = 1;
                paragraph.insert(found - 1, ",");
            }
        }
        else if (where == 'a')
        {
            if (paragraph[found + word.length()] != ',' && paragraph[found + word.length()] != '.')
            {
                k = 1;
                paragraph.insert(found + word.length(), ",");
            }
        }

        found = paragraph.find(word, found + word.length());
    }
    if (k == 0)
    {
        sentinel = 0;
    }
}

#include<iostream>
#include<string>

using namespace std;

 struct Node
    {
        string data;

        struct Node *next;
        struct Node *prev;

    };
struct Node* head= NULL;

void insert_data(string new_data)
{
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
   new_node->data = new_data; 
   new_node->next = head; 
   head = new_node;
}


//function to search for the longest word
string longest_word(string paragraph)
{
    int index=0;
    int longest_length=1;

    for (int i = 0; i < paragraph.length; i++)
    {
        if (paragraph[i] != ' ')
        {
            index++ ;
        }
        else if(paragraph[i] == ' ')
        {
            if(longest_length<index)
            {
                longest_length = index;
                index = 0;
            }
            
        }
    }
}





int main()
{
    //variable declaration
    int n; //number of words
    string paragraph; // paragraph input
    string big_word;    
   
    
    
    //get the number n of words
    do
    {
        cin>>n;

    }while (n<2||n>2500);

    cin>> paragraph;

  
    for(int i=0;i<n;i++) //maximum value of rows that the array can reach is the total number of letters -1
    {
       
    }

    //loop to get the different line width and the longest river
    for(int i=big_word.length;i<80;i++)
    {
        
    }
    
return 0;
}

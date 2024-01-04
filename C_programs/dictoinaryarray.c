#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct word
{
    char* w[100];
    int size;
};

typedef struct word *word;

word insert(word dict, char* w)
{
    if(dict->size == -1)
    {
        dict->w[0] = w;
        dict->size++;
        return dict;
    }
    int i = dict->size;
    if(strcmp(w, dict->w[i]) <= 0)
    {
        dict->w[i + 1] = dict->w[i];
        dict->w[i] = w;
        dict->size++;
        return dict;
    }
    else
    {
        dict->w[i + 1] = w;
        dict->size++;
        return dict;
    }
}

void search(word dict, char* w)
{
    int low = 0;
    int high = dict->size;
    int mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        int i = strcmp(w, dict->w[mid]);
        if(i == 0)
        {
            printf("Found");
            break;
        }
        else if(i < 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
}

int main()
{
    char* input;
    word dict;
    dict->size = -1;
    dict = insert(dict, "avacado");
    dict = insert(dict, "avacado");
    dict = insert(dict, "bengal");
    dict = insert(dict, "kakinda");
    //To make this not work uncomment the below code
    //dict = insert(dict, "tokyo");
    dict = insert(dict, "donkey");
    // and comment the following line
    dict = insert(dict, "tokyo");
    for(int i = 0; i < dict->size + 1; i++)
    {
        puts(dict->w[i]);
    }
    search(dict, "bengal");
    search(dict, "pain");
    return 0;   
}
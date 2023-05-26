#include<iostream>
using namespace std;

struct item
{
    /* data */
    char value;
    int freq;
    item *left = NULL;
    item *right = NULL;
};

void swap(item *a, item *b)
{
    item temp = *a;
    *a = *b;
    *b = temp;
}

void buildHeap(vector<item>& items(), int n)
{
    for(int i=n/2;i>=0;i--)
    {
        heapify(items, i, n);
    }
}

void heapify(vector<item>& items(), int i, int n)
{
    int c1 = i*2 + 1;
    int c2 = i*2 + 2;
    int min = i;
    if(items[i]->val > items[c1]->value)
    {
        min = c1;
    }
    if(items[i]->val > items[c2]->value)
    {
        min = c2;
    }
    if(i!=min)
    {
        swap(&items[i], &items[min]);
        hepify(items, min, n);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of items:"<<endl;
    cin>>n;
    vector<item> items(n);
    cout<<"Enter the values:"<<endl;
    for(int i=0;i<n;i++)
    {
        char val;
        int freq;
        cout<<"Enter the value:";
        cin>>val;
        cout<<"Enter the freq:";
        cin>>freq;
        items[i].value = val;
        items[i].freq = freq;
        items[i].left = NULL;
        items[i].right = NULL;
    }
    buildHeap(items, n);
    while(n!=1) // because we extract two numbers
    {
        item *temp1 = extractMax(items, n);
        item *temp2 = extractMax(items, n);
        item *mergedItem;
        mergedItem->val = '$';
        mergedItem->freq = temp1->freq + temp2->freq;
        mergedItem->left = NULL;
        mergedItem->right = NULL;
        insertItem(items, mergedItem, n);
    }
    printAns(items, n);
}
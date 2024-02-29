#include <iostream>
#include <vector>
using namespace std;

struct item
{
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

void heapify(vector<item> &items, int i, int n)
{
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    int min = i;
    if (c1 < n && items[c1].freq < items[min].freq)
    {
        min = c1;
    }
    if (c2 < n && items[c2].freq < items[min].freq)
    {
        min = c2;
    }
    if (i != min)
    {
        swap(&items[i], &items[min]);
        heapify(items, min, n);
    }
}

void buildHeap(vector<item> &items, int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(items, i, n);
    }
}

void parentHeapify(vector<item>& items, int i) {
    if (i == 0)
        return;
    int parent = (i - 1) / 2;
    if (items[i].freq < items[parent].freq) {
        swap(&items[i], &items[parent]);
        parentHeapify(items, parent);
    }
}

item *extractMin(vector<item> &items, int &n)
{
    item *minItem = new item();
    minItem->value = items[0].value;
    minItem->freq = items[0].freq;
    minItem->left = items[0].left;
    minItem->right = items[0].right;
    swap(&items[0], &items[n - 1]);
    n--;
    heapify(items, 0, n);
    return minItem;
}

void insertItem(vector<item> &items, item *newItem, int &n)
{
    if (items.size() == n)
    {
        items.push_back(*newItem);
    }
    else
    {
        items[n] = *newItem;
    }
    n++;
    parentHeapify(items, n - 1);
}

void printAns(item *root, const string& ans)
{
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->value << " " << ans << endl;
        return;
    }
    printAns(root->left, ans + "0");
    printAns(root->right, ans + "1");
}

int main()
{
    int n;
    cout << "Enter the number of items:" << endl;
    cin >> n;
    vector<item> items(n);
    cout << "Enter the values and frequencies:" << endl;
    for (int i = 0; i < n; i++)
    {
        char val;
        int freq;
        cout << "Enter the value: ";
        cin >> val;
        cout << "Enter the freq: ";
        cin >> freq;
        items[i].value = val;
        items[i].freq = freq;
        items[i].left = NULL;
        items[i].right = NULL;
    }
    buildHeap(items, n);
    while (n != 1)
    {
        item *temp1 = extractMin(items, n);
        item *temp2 = extractMin(items, n);
        item *mergedItem = new item;
        mergedItem->value = '$';
        mergedItem->freq = temp1->freq + temp2->freq;
        mergedItem->left = temp1;
        mergedItem->right = temp2;
        insertItem(items, mergedItem, n);
    }
    string ans = "";
    printAns(&items[0], ans);
    return 0;
}
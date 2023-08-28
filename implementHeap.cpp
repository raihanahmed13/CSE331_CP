#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    vector<int> v;
    int size;
    heap()
    {
        v.push_back(-1);
        size = 0;
    }
    void insert(int val)
    {
        size++;
        int indx = size;
        v[indx] = val;
        while (indx > 1)
        {
            int parent = indx / 2;
            if (v[parent] < v[indx])
            {
                swap(v[parent], v[indx]);
                indx = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deleteNode()
    {
        if (size == 0)
        {
            cout << "\nNothing to delete" << endl;
        }
        v[1] = v[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int left = 2 * i;
            int right = (2 * i) + 1;
            if (left < size && v[i] < v[left])
            {
                swap(v[i], v[left]);
                i = left;
            }
            else if (right < size && v[i] < v[right])
            {
                swap(v[i], v[right]);
                i = right;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << v[i] << " ";
        }
    }
};

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteNode();
    cout << "\nAfter deletion: " << endl;
    h.print();
}
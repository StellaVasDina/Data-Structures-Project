#include <iostream>

void insertion_sort(int list[], int n);
void selection_sort(int list[], int n);
void quick_sort(int list[], int first, int last);

int main()
{
    std::cout << "this language's pretty good but it can suck my ass and balls";
}

// insertion sort stuff
void insertion_sort(int list[], int n)
{
    int i, j, temp;
    for (i = 1; i <= n - 1; i++)
    {
        j = i;

        while (j > 0 && list[j] < list[j - 1])
        {
            temp = list[j];
            list[j] = list[j - 1];
            list[j - 1] = temp;

            j--;
        }
    }
}

// selection sort stuff
void selection_sort(int list[], int n)
{
    int i, j, swap, position;

    for (i = 0; i < (n - 1); i++)
    {

        position = i;

        for (j = i + 1; j < n; j++)
        {
            if (list[position] > list[j])
                position = j;
        }
        if (position != i)
        {
            swap = list[i];
            list[i] = list[position];
            list[position] = swap;
        }
    }
}

// quick sort stuff
void quick_sort(int list[], int first, int last)
{
    int pivot, j, temp, i;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (list[i] <= list[pivot] && i < last)
                i++;
            while (list[j] > list[pivot])
                j--;
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }

        temp = list[pivot];
        list[pivot] = list[j];
        list[j] = temp;
        quick_sort(list, first, j - 1);
        quick_sort(list, j + 1, last);

    }
}
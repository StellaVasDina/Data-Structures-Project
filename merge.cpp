#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void part(int array[], int min, int max);
void merge(int array[], int min, int mid, int max);

int main()
{
    srand(time(NULL));
    int array[1000];

	int s = 0;
    for (int sc = 100; sc <= 1000; sc+=100)
    {
    	for (int i = 0; i < sc; i++)
	    {
            array[i] = rand() % 1000000 + 1;
	    }
        part(array, 0, sc - 1);
        s++;
        cout << "Scenario " << s << endl;
    }

	return 0;
}

void part(int array[], int min, int max)
{
    int mid;
    if (min < max)
    {
        mid = (min + max) / 2;
        part(array, min, mid);
        part(array, mid + 1, max);
        merge(array, min, mid, max);
    }
}

void merge(int array[], int min, int mid, int max)
{
    int temp[1000];
    int i, j, k, m;
    j = min;
    m = mid + 1;
    for (i = min; j <= mid && m <= max; i++)
    {
        if (array[j] <= array[m])
        {
            temp[i] = array[j];
            j++;
        }
        else
        {
            temp[i] = array[m];
            m++;
        }
    }
    if (j > mid)
    {
        for (k = m; k <= max; k++)
        {
            temp[i] = array[k];
            i++;
        }
    }
    else
    {
        for (k = j; k <= mid; k++)
        {
            temp[i] = array[k];
            i++;
        }
    }
    for (k = min; k <= max; k++)
    {
        array[k] = temp[k];
    }
}

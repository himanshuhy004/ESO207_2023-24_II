#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int prev[n];

        int st[n];

        int j = -1;
        prev[0] = 1;
        for (int i = 0; i < n; i++)
        {
            while (j >= 0 && arr[st[j]] <= arr[i])
            {
                j--;
            }
            if (j >= 0)
                prev[i] = st[j];
            else
                prev[i] = -1;
            st[++j] = i;
        }

        for (int i = 0; i < n; i++)
        {
            if (prev[i] == -1)
                cout << i+1;
            else
                cout << i - prev[i];
            cout << '\n';
        }
    }
}
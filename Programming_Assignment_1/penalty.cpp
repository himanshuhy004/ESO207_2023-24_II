#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        char s[n];
        for (int i = 0; i < n; i++)
            cin >> s[i];

        int count = 0;

        char ans[n];

        int j = -1;
        for (int i = 0; i < n; i++)
        {   

            while (j >= 0 && ans[j]-'0' > s[i]-'0' && count < k)
            {
                j--;
                count++;
            }
            ans[++j] = s[i];
        }

        bool f = false;
        for (int i = 0; i < n - k; i++)
        {
            if (ans[i] == '0' && !f)
            {
                continue;
            }
            cout << ans[i];
            f = true;
        }

        if (!f)
            cout << '0';
        cout << '\n';
    }
}
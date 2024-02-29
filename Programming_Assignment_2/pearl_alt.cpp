#include <iostream>
#include <vector>
using namespace std;

class OST
{
    int MAX_VAL;
    vector<int> BIT;
    void update(int i, int add)
    {
        while (i > 0 && i < BIT.size())
        {
            BIT[i] += add;
            i = i + (i & (-i));
        }
    }

    int sum(int i)
    {
        int ans = 0;
        while (i > 0)
        {
            ans += BIT[i];
            i = i - (i & (-i));
        }
        return ans;
    }

public:
    OST(int val)
    {
        MAX_VAL = val;
        BIT.resize(MAX_VAL);
    }
    int find_by_order(int k)
    {
        int l = 0;
        int h = BIT.size();
        while (l < h)
        {
            int mid = (l + h) / 2;
            if (k <= sum(mid))
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    void insert(int x)
    {
        if (x <= 0 or x >= BIT.size())
            return;
        update(x, 1);
    }

    void erase(int x)
    {
        if (!find(x))
            return;
        update(x, -1);
    }

    bool find(int x)
    {
        if (x <= 0 or x >= BIT.size())
            return false;
        return sum(x) - sum(x - 1) > 0;
    }
};

int main()
{

    int n, k;
    cin >> n >> k;
    k--;
    OST s(n + 1);
    for (int i = 1; i <= n; i++)
        s.insert(i);

    int curr = 1;
    for (int i = 0; i < n; i++)
    {
        int rem = n - i;
        int k1 = (curr + k - 1) % rem + 1;
        int val = s.find_by_order(k1);
        s.erase(val);
        cout << val << " ";
        curr = k1;
    }
}
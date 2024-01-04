class Solution {
public:
    const int MOD = 1e9 + 7;
    int totalStrength(const vector<int>& strength) {
        if (strength.size() == 1)
            return (1LL * strength[0] * strength[0]) % MOD;
        int n = strength.size();
        vector <int> sum(n, 0);
        vector <int> sumOfSumLeft(n, 0);
        vector <int> sumOfSumRight(n, 0);
        vector <int> left(n, 0);
        vector <int> right(n, n - 1);
        sum[0] = strength[0];
        sumOfSumLeft[0] = sum[0];
        sumOfSumRight[n - 1] = strength[n - 1];
        stack <int> st;
        st.push(0);
        for (int i = 1; i < n; ++i)
        {
            sum[i] = sum[i - 1] + strength[i];
            if (sum[i] >= MOD)
                sum[i] -= MOD;
            right[i] = n - 1;
            sumOfSumLeft[i] = sumOfSumLeft[i - 1] + sum[i];
            if (sumOfSumLeft[i] >= MOD)
                sumOfSumLeft[i] -= MOD;
            while (!st.empty() && strength[st.top()] > strength[i])
            {
                right[st.top()] = i - 1;
                st.pop();
            }
            if (!st.empty())
                left[i] = st.top() + 1;
            st.push(i);
        }

        for (int i = n - 2; i >= 1; --i)
        {
            sumOfSumRight[i] = sumOfSumRight[i + 1] + ((sum[n - 1] - sum[i - 1] + MOD) % MOD);
            if (sumOfSumRight[i] >= MOD)
                sumOfSumRight[i] -= MOD;
        }
        sumOfSumRight[0] = sumOfSumRight[1] + sum[n - 1];
        if (sumOfSumRight[0] >= MOD)
            sumOfSumRight[0] -= MOD;

        long long total = 0;
        for (int i = 0; i < n; ++i)
        {
            long long rightAmplifier = i - left[i] + 1, leftAmplifier = right[i] - i + 1;
            long long addRight = 0;
            if (right[i] >= i + 1)
            {
                addRight = sumOfSumLeft[right[i]];
                addRight -= ((sumOfSumLeft[i] + 1LL * sum[i] * (right[i] - i))) % MOD;
                addRight += MOD;
                if (addRight >= MOD)
                    addRight -= MOD;
            }
            
            long long addLeft = 0;

            if (left[i] <= i - 1)
            {
                addLeft = sumOfSumRight[left[i]];
                addLeft -= (sumOfSumRight[i] + 1LL * (sum[n - 1] - sum[i - 1]) * (i - left[i])) % MOD;
                addLeft += MOD;
                if (addLeft >= MOD)
                    addLeft -= MOD;
            }


            total += ((((addRight * rightAmplifier) % MOD + (addLeft * leftAmplifier) % MOD) % MOD) * strength[i]) % MOD;       
            total %= MOD;

            if (rightAmplifier && leftAmplifier)
            {
                total += (((rightAmplifier * leftAmplifier) % MOD) * ((1LL * strength[i] * strength[i]) % MOD)) % MOD;
                total %= MOD;   
            }
        }

        return total;
    }
};

#include<stdio.h>
#include<string.h>

long long fact(long long n)
{
    long long i;
    long long product = 1;
    for(i=n;i>=1;i--)
    {
        product *= i;
    }
    return product;
}


long long number_of_max_palindromes(char a[])
{
    int frequency[26];
    int i;
    for(i=0;i<26;i++)
    {
        frequency[i] = 0;
    }
    for(i=0;i<strlen(a);i++)
    {
        frequency[a[i] - 'a']++;
    }
    int k = 0;
    long long numerator = 0;
    long long denominator = 1;
    for(i=0;i<26;i++)
    {
        if(frequency[i]%2 == 0)
        {
            frequency[i] /= 2;
        }
        else
        {
            frequency[i] = (frequency[i]-1)/2;
            k++;
        }
        numerator += frequency[i];
        denominator *= fact(frequency[i]);
    }
    if(numerator == 0)
    {
        return 0;
    }
    else
    {
        numerator = fact(numerator);
    }
    long long answer = numerator/denominator;
    if(k != 0)
    {
        answer *= k;
    }
    return answer;
}

int main()
{
    char s[100000];
    scanf("%s", s);
    int q;
    scanf("%d", &q);
    int i;
    int l[q];
    int r[q];
    for(i=0;i<q;i++)
    {
        scanf("%d %d", &l[i], &r[i]);
        l[i]--;
        r[i]--;
    }
    char temp[100000];
    for(i=0;i<q;i++)
    {
        int j,k;
        for(j=l[i],k=0;j<=r[i];j++,k++)
        {
            temp[k] = s[j];
        }
        temp[k] = '\0';
        long long answer = number_of_max_palindromes(temp);
        answer %= 1000000007;
        printf("%lld\n", answer);
    }
    return 0;
}

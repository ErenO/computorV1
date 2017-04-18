#include ""

void ftoa(double nb, char *output)
{
    int m;
    int digit;
    double precision;
    double weight;

    m = log10(nb);
    precision = 0.0001;
    weight = 0.0;
    while (nb > 0 + precision)
    {
        weight = ft_pow(10.0, m);
        digit = floor(nb / weight);
        nb -= (digit * weight);
        *(output++)= '0' + digit;
        if (m == 0)
            *(output++) = '.';
        m--;
    }
    *(output) = '\0';
}

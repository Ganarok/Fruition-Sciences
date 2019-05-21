int my_getnbr(char const *str)
{
    int count = 0;
    int value = 0;
    int count_neg = 0;

    while (str[count] == '-' || str[count] == '+') {
        if (str[count] == '-') {
            count_neg++;
        }
        count++;
    }
    while (str[count] >= 48 && str[count] <= 57) {
        value = value * 10;
        value = value + str[count++] - '0';
    }
    if (value < -2147483647 || value > 2147483647)
        return (0);
    return ((count_neg%2 == 1) ? (value * (-1)) : value);
}

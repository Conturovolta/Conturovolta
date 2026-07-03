char *gcdOfStrings(char *str1, char *str2, char *result)
{

    if (str1 == str2 || str2 == str1)
    {
        strcpy(result, str1);
    }
    else if (str1 + str2 == str2)
    {
        strcpy(result, str1);
     }
    else if (str2 + str1 == str1)
    {
        strcpy(result, str2);
    }
    else
    {
        strcpy(result, "");
    }
    return result;
}
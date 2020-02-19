#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Insert Key\n");
        return 1;
    }
    string key = argv[1];
    int n = strlen(key);

	if (n == 26)
	{
	    for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if ((key[j] == key[i]) || (key[j] +32 == key[i]) || (key[j] - 32 == key[i]) || (key[j] == key[i] + 32) || (key[j] == key[i] - 32))
                {
                    if (j != i)
                    {
                        printf("Invalid Key\n");
                        return 1;
                    }
                }
            }


        }
	}
	if (n != 26)
	{
	    printf("Invalid Key\n");
	    return 1;
	}
	string text = get_string("plaintext: ");
	if (text[0] == '\0')
	{
	    return 1;
	}
	int n2 = strlen(text);
	char cypher[n2];
    for (int i = 0; i < n2 ; i++)
	{
	    if (text[i] <= 90 && text[i] >= 65)
	    {
	        int d = text[i] - 65;
	        if (key[d] <= 122 && key[d] >= 97)
	        {
	            cypher[i] = key[d] - 32;
	        }
	        else
	        {
	            cypher[i] = key[d];
	        }
	    }
	    else if (text[i] <= 122 && text[i] >= 97)
	    {
	        int d = text[i] - 97;
	        if(key[d] <= 90 && key[d] >= 65)
	        {
	            cypher[i] = key[d] + 32;
	        }
	        else
	        {
	            cypher[i] = key[d];
	        }
	    }
	    else if (text[i] == '\0')
	    {
	    	cypher[i] = '\0';
	    }
	    else
	    {
	        cypher[i] = text[i];
	    }
	}
    printf("ciphertext: %s", cypher);
    printf("\n");
    return 0;
}

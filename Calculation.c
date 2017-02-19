
int calculation(int a, int b, char operation)
{
    int res = 0;

    switch(operation){

        case '+' : res = a + b;
        break;
        case '-' : res = a - b;
        break;
        case '*' : res = a * b;
        break;
        case '/' :
        if ( b == 0)
        {
            printf(" division par zero impossible");
            res = 0;
        }
        else
        {
            res = a / b;
        }
        break;
        default : printf(" operateur non accepte");
        break;
    }
    return res;
}

int main ()
{
    calculation(3, 5, '+');
    return 0;
}

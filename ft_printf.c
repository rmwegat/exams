#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int ft_printchar(int c)
{
    return (write(1, &c, 1));
}

int ft_print_digit(long n, int base, char *symbols)
{
    int count = 0;
    if (n < 0)
    {
        write(1, "-", 1);
        return (ft_print_digit(-n, base, symbols) + 1);
    }
    if (n < base)
    {
        return (ft_printchar(symbols[n]));
    }
    else
        count += ft_print_digit(n / base, base, symbols);
    return (count + ft_print_digit(n % base, base, symbols));
}
int ft_printstr(char *str)
{
    int count = 0;

    if(str==NULL)
        return (write(1, "(null)", 6));
    while (*str)
    {
        ft_printchar((int)*str);
        str++;
        count++;
    }
    return count;
}
int ft_printf(const char *string, ...)
{
    va_list pa;
    int count = 0;
    va_start (pa, string);

    while (*string)
    {
        if ((*string == '%') && (*(string + 1)=='s' || (*(string + 1)=='d') ||(*(string + 1)=='x')))
        {
            string++;
            if (*string == 's')
                count += ft_printstr(va_arg(pa, char *));
            else if (*string == 'd')
                count += ft_print_digit((long)(va_arg(pa, int)), 10, "0123456789");
            else if (*string == 'x')
                count += ft_print_digit((unsigned long)(va_arg(pa, unsigned int)), 16, "0123456789abcdef");
        }
        else
            count += write(1, string, 1);
        string++;
    }
    va_end(pa);
    return count;
}

// int	main(void)
// {

// 	int a = 11;
	
// 	ft_printf("Print string : Hello %s\n", "");
// 	printf("Print string : Hello %s\n", "");
	
// 	ft_printf("Print int %d chars\n", -2147483647);
// 	printf("Print int %d chars\n", -2147483647);

// 	ft_printf("Print hex_min %x\n", a);
// 	printf("Print hex_min %x\n", a);

// 	return (0);
// } 
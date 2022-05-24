#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: formats string that contains the characters and the specifiers
 * Description: this function calls the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of the formatted output string
 */

int _printf(const char *format, ...)
  
{

int (*pfunc)(va_list, args *);
const char *p;
va_list arguments;
args flags = {0, 0, 0};
  
register int count = 0;
va_start(arguments, format);

if (!format || (format[0] == '%' && !format[1]))
return (-1);

if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);

for (p = format; *p; p++)

{
if (*p == '%')
{
p++;
if (*p == '%')
{
count =count + _putchar('%');
continue;
}
while (get_flag(*p, &flags))
p++;
pfunc = get_print(*p);
count += (pfunc)
? pfunc(arguments, &flags)
: _printf("%%%c", *p);
}
else
count += _putchar(*p);
}

_putchar(-1);

va_end(arguments);

return (count);

}

#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt,...);

/**
 * 7.3 minprintf
 */
int main(int argc, char *argv[])
{
	
	minprintf("%dhoge\n",1);	
	minprintf("%shoge\n","moge");	
	return 0;
}

void minprintf(char *fmt,...)
{
	//argument pointer
	va_list	ap;
	
	char		*p, *sval;
	int		ival;
	double	dval;
	
	va_start(ap,fmt);
	
	for( p = fmt; *p; p++)
	{
		if(*p != '%'){
			putchar(*p);
			continue;
		}
		
		switch(*++p){
			case 'd':
				ival = va_arg(ap,int);
				printf("%d",ival);
				break;
			case 'f':
				dval = va_arg(ap,double);
				printf("%f",dval);
				break;
			case 's':
				for( sval = va_arg(ap, char *); *sval; sval++ ){
					putchar(*sval);
				}
				break;
			default:
				putchar(*p);
				break;
		}
	}
	
	//クリーンアップ(なぜ必要？)
	va_end(ap);
}


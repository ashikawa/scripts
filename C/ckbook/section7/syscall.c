#include <stdio.h>
#include <syscall.h>

/**
 * 8.2 低水準入出力
 * /usr/include/syscalls.h じゃなくて syscall.h でした。
 * 環境によって変わるのか.....
 * シンボリックリンクでも作っておくか。
 */
int main(int argc, char *argv[])
{
	char buf[BUFSIZ];
	
	int n;
	
	while ( (n = read(0, buf, BUFSIZ)) > 0 ){
		write(1, buf, n);
	}
	return 0;
}


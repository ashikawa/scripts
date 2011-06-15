#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/param.h>
#include <sys/uio.h>
#include <unistd.h>

#define BUF_LEN 256				/* バッファのサイズ */

int main(int argc, char *argv[])
{
	int s;							/* ソケットのためのファイルディスクリプタ */
	struct hostent *servhost;	/* ホスト名と IP アドレスを扱うための構造体 */
	struct sockaddr_in server;	/* ソケットを扱うための構造体 */
	struct servent *service;	/* サービス (http など) を扱うための構造体 */
	
	char send_buf[BUF_LEN];					/* サーバに送る HTTP プロトコル用バッファ */
	char host[BUF_LEN] = "localhost";	/* 接続するホスト名 */
	char path[BUF_LEN] = "/";				/* 要求するパス */
	unsigned short port = 0;				/* 接続するポート番号 */

	if ( argc > 1 ){							/* URLが指定されていたら */
		char host_path[BUF_LEN];
		
		if ( strlen(argv[1]) > BUF_LEN-1 ){
				fprintf(stderr, "URL が長すぎます。\n");
				return 1;
		}
		
		/* http:// から始まる文字列で */
		/* sscanf が成功して */
		/* http:// の後に何か文字列が存在するなら */
		if ( strstr(argv[1], "http://") &&
					sscanf(argv[1], "http://%s", host_path) &&
					strcmp(argv[1], "http://" ) ){
			char *p;

			p = strchr(host_path, '/');	/* ホストとパスの区切り "/" を調べる */
			if( p != NULL ){

				strcpy(path, p);					/* "/"以降の文字列を path にコピー */
				*p = '\0';
				strcpy(host, host_path);		/* "/"より前の文字列を host にコピー */
			}else{									/* "/"がないなら＝http://host という引数なら */
				strcpy(host, host_path);		/* 文字列全体を host にコピー */
			}

			p = strchr(host, ':');				/* ホスト名の部分に ":" が含まれていたら */

			if ( p != NULL ){
				port = atoi(p+1);		/* ポート番号を取得 */

				if ( port <= 0 ){		/* 数字でない (atoi が失敗) か、0 だったら */
					port = 80;			/* ポート番号は 80 に決め打ち */
				}
				*p = '\0';
			}

		} else {
			fprintf(stderr, "URL は http://host/path の形式で指定してください。\n");
			return 1;
		}
	}

	printf("http://%s%s を取得します。\n\n", host, path);

	/* ホストの情報(IPアドレスなど)を取得 */
	servhost = gethostbyname(host);
	if ( servhost == NULL ){
		fprintf(stderr, "[%s] から IP アドレスへの変換に失敗しました。\n", host);
		return 0;
	}
	bzero(&server, sizeof(server));	/* 構造体をゼロクリア */

	server.sin_family = AF_INET;

	/* IPアドレスを示す構造体をコピー */
	bcopy(servhost->h_addr, &server.sin_addr, servhost->h_length);

	if ( port != 0 ){		/* 引数でポート番号が指定されていたら */
		server.sin_port = htons(port);
	} else {					/* そうでないなら getservbyname でポート番号を取得 */
		service = getservbyname("http", "tcp");

		if ( service != NULL ){		/* 成功したらポート番号をコピー */
			server.sin_port = service->s_port;
		} else {							/* 失敗したら 80 番に決め打ち */
			server.sin_port = htons(80);
		}
	}

	/* ソケット生成 */
	if ( ( s = socket(AF_INET, SOCK_STREAM, 0) ) < 0 ){
		fprintf(stderr, "ソケットの生成に失敗しました。\n");
		return 1;
	}

	/* サーバに接続 */
	if ( connect(s, (struct sockaddr *)&server, sizeof(server)) == -1 ){
		fprintf(stderr, "connect に失敗しました。\n");
		return 1;
	}

	/* HTTP プロトコル生成 & サーバに送信 */
	sprintf(send_buf, "GET %s HTTP/1.0\r\n", path);
	write(s, send_buf, strlen(send_buf));

	sprintf(send_buf, "Host: %s:%d\r\n", host, port);
	write(s, send_buf, strlen(send_buf));

	sprintf(send_buf, "\r\n");
	write(s, send_buf, strlen(send_buf));

	/* あとは受信して、表示するだけ */
	while (1){
		char buf[BUF_LEN];
		int read_size;

		read_size = read(s, buf, BUF_LEN);
		if ( read_size > 0 ){
			write(1, buf, read_size);
		} else {
			break;
		}
	}
	/* 後始末 */
	close(s);

	printf("\n");
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "clowler.h"

/**
 * C言語からpostgresに接続
 * @see http://www.sraoss.co.jp/PostgreSQL/Manual/PostgreSQL-7.1-ja/libpq-exec.html
 */
int main(int argc,char **argv)
{
	/* 変数定義 */
	char dbName[] = "circle"; /* データベース名はハードコーディング */
	char sql[255];
	int rows;
	int i;
	PGconn *con;
	PGresult *res;
 	
	char *key,*pass,*name,*image,*mixi,*status;

	/* DBとの接続 */
	con = PQsetdb("localhost","5432",NULL,NULL,dbName);
	if ( PQstatus(con) == CONNECTION_BAD ) { /* 接続が失敗したときのエラー処理 */
		fprintf(stderr,"Connection to database '%s' failed.\n",dbName);
		fprintf(stderr,"%s",PQerrorMessage(con));
		exit(1);
	}

	/* select文の発行 */
	sprintf(sql,"SELECT * FROM member");
	res = PQexec(con,sql);
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		/* SQLの実行に失敗したときのエラー処理 */
		fprintf(stderr,"%s",PQerrorMessage(con));
		exit(1);
	}

	rows = PQntuples(res);
	
	for(i = 0; i < rows ;i++) {
		key		= PQgetvalue(res,i,0);
		pass		= PQgetvalue(res,i,1);
		name		= PQgetvalue(res,i,2);
		image		= PQgetvalue(res,i,3);
		mixi		= PQgetvalue(res,i,4);
		status	= PQgetvalue(res,i,5);

		printf("%s %s %s %s %s %s \n",key,pass,name,image,mixi,status);
	}
	PQclear(res);
}


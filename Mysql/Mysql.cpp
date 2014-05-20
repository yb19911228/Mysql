// Mysql.cpp : 定义控制台应用程序的入口点。
//

#include <windows.h>
#include "stdio.h"
#include "winsock.h" 
#include "mysql.h" 
#include"stdafx.h"
#include"iostream"

MYSQL * conn;//定义Mysql连接
MYSQL_RES * result;
MYSQL_ROW row;  
unsigned int t;  
using namespace std;  
int _tmain(int argc, _TCHAR* argv[])
{
	mysql_init(conn);//连接初始化
	if(!mysql_real_connect(conn, "localhost","root","","test",3306,NULL,0))  //测试数据库是否连接成功
	{  
	cout<<"weewe"; 
	}								   
	else//数据库连接成功
	{
		cout<<mysql_get_server_info(conn);
		char* query="DROP DATABASE yanbing";
		mysql_query(conn,query);
	mysql_query(conn,"SELECT * FROM yangbing");
	//MYSQL_RES * result = mysql_use_result(&conn);
	 result = mysql_store_result(conn);//将结果保存在res结构体中  

    while(row = mysql_fetch_row(result))    
    {    
        /**  
        * MYSQL_ROW STDCALL mysql_fetch_row(MYSQL_RES *result);  
         * 检索行  
        */    
   
       for(t=0;t<mysql_num_fields(result);t++)    
        {    
            printf("%s  ",row[t]);    
        }    
        
    }  


	}
	char*  Query = "SELECT user_id,user_name,user_second_sum FROM user_info";
	mysql_free_result(result);    
    mysql_close(conn);  


}


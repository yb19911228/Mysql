// Mysql.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <windows.h>
#include "stdio.h"
#include "winsock.h" 
#include "mysql.h" 
#include"stdafx.h"
#include"iostream"

MYSQL * conn;//����Mysql����
MYSQL_RES * result;
MYSQL_ROW row;  
unsigned int t;  
using namespace std;  
int _tmain(int argc, _TCHAR* argv[])
{
	mysql_init(conn);//���ӳ�ʼ��
	if(!mysql_real_connect(conn, "localhost","root","","test",3306,NULL,0))  //�������ݿ��Ƿ����ӳɹ�
	{  
	cout<<"weewe"; 
	}								   
	else//���ݿ����ӳɹ�
	{
		cout<<mysql_get_server_info(conn);
		char* query="DROP DATABASE yanbing";
		mysql_query(conn,query);
	mysql_query(conn,"SELECT * FROM yangbing");
	//MYSQL_RES * result = mysql_use_result(&conn);
	 result = mysql_store_result(conn);//�����������res�ṹ����  

    while(row = mysql_fetch_row(result))    
    {    
        /**  
        * MYSQL_ROW STDCALL mysql_fetch_row(MYSQL_RES *result);  
         * ������  
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


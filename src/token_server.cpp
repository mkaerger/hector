#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include "CardProcessor.h"
#include <libpq-fe.h>

using namespace std;
PGconn          *conn;
PGresult        *res;
int             rec_count;
int             row;
int             col;
std::string     token;
std::string     s1;
std::string     s2;
std::string     s3;


void CloseConn(PGconn *conn)
{
    PQfinish(conn);
}


std::string get_pan_by_token(CardProcessor, std::string cc) 
{
    s1 = "SELECT pan FROM cc_data WHERE token = '";
    s2 = "';";
    s3 = s1 + cc + s2;

    std::string pans;
    
    res = PQexec(conn, (char*)s3.c_str());
    
    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
                 puts("ERR NO DATA");
    } else {
 
         rec_count = PQntuples(res);
 
         for (row=0; row<rec_count; row++) {
                 for (col=0; col<1; col++) {
                         pans.append(PQgetvalue(res, row, col));
                 }
         }
      }

    if(pans.empty()) {
        puts("ERR NO PANS FOUND");
    } else { 	 
        return pans;
    }
}


std::string get_tokens_by_masked_pan(std::string cc) 
{
    std::string tokens;
    s1 = "SELECT token FROM cc_data WHERE masked_pan = '";
    s2 = "';";
    s3 = s1 + cc + s2;

    res = PQexec(conn, (char*)s3.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
                 puts("ERR NO DATA");
     } else {
 
         rec_count = PQntuples(res);
 
         for (row=0; row<rec_count; row++) {
                 for (col=0; col<1; col++) {
                         tokens.append(PQgetvalue(res, row, col));
                         tokens.append("\n");
                 }
         }
      }
 
    return tokens;
}


std::string get_card_type_by_token(std::string cc) 
{
    s1 = "SELECT card_type FROM cc_data WHERE token = '";
    s2 = "';";
    s3 = s1 + cc + s2;

    res = PQexec(conn, (char*)s3.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            puts("ERR NO DATA");
    } else {
        return PQgetvalue(res, 0, 0);
    }
}


std::string get_count_tokens_by_masked_pan(std::string cc) 
{
    s1 = "SELECT count(token) FROM cc_data WHERE masked_pan = '";
    s2 = "';";
    s3 = s1 + cc + s2;

    res = PQexec(conn, (char*)s3.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            puts("ERR NO DATA");
    } else {
        return PQgetvalue(res, 0, 0);
    }
}


std::string get_masked_pan_by_token(std::string cc) 
{
    s1 = "SELECT masked_pan FROM cc_data WHERE token = '";
    s2 = "';";
    s3 = s1 + cc + s2;

    res = PQexec(conn, (char*)s3.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            puts("ERR NO DATA");
    } else {
        return PQgetvalue(res, 0, 0);
    }
}


std::string get_provider_by_token(std::string cc) 
{
    s1 = "SELECT provider FROM cc_data WHERE token = '";
    s2 = "';";
    s3 = s1 + cc + s2;

    res = PQexec(conn, (char*)s3.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            puts("ERR NO DATA");
    } else {
        return PQgetvalue(res, 0, 0);
    }
}


std::string get_card_type_by_pan(CardProcessor cp) 
{

    s1 = "SELECT card_type FROM cc_data WHERE pan = '";
    s2 = "';";
    s3 = s1 + cp.machine_readable_card_number() + s2;

    res = PQexec(conn, (char*)s3.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            puts("ERR NO DATA");
    } else {
        return PQgetvalue(res, 0, 0);
    }
}



std::string get_token_by_pan(CardProcessor cp) 
{

    s1 = "SELECT token FROM cc_data WHERE pan = '";
    s2 = "';";
    s3 = s1 + cp.machine_readable_card_number() + s2;

    res = PQexec(conn, (char*)s3.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            puts("ERR NO DATA");
    } else {
        return PQgetvalue(res, 0, 0);
    }
}


std::string get_provider_by_pan(CardProcessor cp) 
{

    s1 = "SELECT provider FROM cc_data WHERE pan = '";
    s2 = "';";
    s3 = s1 + cp.machine_readable_card_number() + s2;

    res = PQexec(conn, (char*)s3.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            puts("ERR NO DATA");
    } else {
        return PQgetvalue(res, 0, 0);
    }
}


std::string set_token_by_pan(CardProcessor cp) 
{

    std::string stmnt;
    std::string hash = cp.get_salted_sha256_string();

    stmnt.append("INSERT INTO cc_data VALUES ('");
    stmnt.append(cp.machine_readable_card_number());
    stmnt.append("', '");
    stmnt.append(cp.get_masked_pan());
    stmnt.append("', '");
    stmnt.append(hash);
    stmnt.append("', '");
    stmnt.append("JCB");
    stmnt.append("', '");
    stmnt.append("Debit");
    stmnt.append("', '");
    stmnt.append("now()");
    stmnt.append("', '");
    stmnt.append("now()");
    stmnt.append("')");


    res = PQexec(conn, stmnt.c_str());

    if (PQresultStatus(res) == PGRES_COMMAND_OK)
    {
      return hash;
    } 
    else 
    {
      return PQerrorMessage(conn);
    } 
}


int main ( int argc, char *argv[] )
{
    std::cout << "HECTOR RUNNING.\n";


    // TODO: Put all postgres stuff to a factory
    conn = PQconnectdb("dbname=pcidss host=localhost user=postgres password=");
    if (PQstatus(conn) == CONNECTION_BAD) {
            puts("We were unable to connect to the database");
    }

    try
    {
      ServerSocket server (30000);

      while (true)
	{

	  ServerSocket new_sock;
	  server.accept (new_sock);

	  try
	    {
	      while (true)
		{
		  std::string data;
		  new_sock >> data;
		  
	          std::string s          = data;
		  std::string delimiter  = "|";
                  std::string service    = s.substr(0, s.find(delimiter));	
		  unsigned pos           = s.find("|"); 
                  std::string input_data = s.substr (pos + 1);  

		  if (service == "get_pan_by_token")
		  {
    		      CardProcessor cp(input_data); 
		      
		      if (!cp.validate_token_format(input_data)) {
		          new_sock << "Wrong token format";
  		      }	else {
		          new_sock << get_pan_by_token(cp, input_data);
		      }
		  }
		  else if (service == "get_token_by_pan")
		  {
    		      CardProcessor cp(input_data); 

		      if (!cp.validate_card_format()) {
		          new_sock << "Wrong credit card format";
  		      }	else {
		          new_sock << get_token_by_pan(cp);
		      }
		  }
		  else if (service == "get_card_type_by_pan")
		  {
    		      CardProcessor cp(input_data); 

		      if (!cp.validate_card_format()) {
		          new_sock << "Wrong credit card format";
  		      }	else {
		          new_sock << get_card_type_by_pan(cp);
		      }
		  }
	
		  else if (service == "get_provider_by_pan")
		  {
    		      CardProcessor cp(input_data); 

		      if (!cp.validate_card_format()) {
		          new_sock << "Wrong credit card format";
  		      }	else {
		          new_sock << get_provider_by_pan(cp);
		      }
		  }
	          
	  	  else if (service == "get_provider_by_token")
		  {
		      new_sock << get_provider_by_token(input_data);
		  }

	  	  else if (service == "get_count_tokens_by_masked_pan")
		  {
		      new_sock << get_count_tokens_by_masked_pan(input_data);
		  }
	  	  else if (service == "get_card_type_by_token")
		  {
		      new_sock << get_card_type_by_token(input_data);
		  }

	  	  else if (service == "get_masked_pan_by_token")
		  {
		      new_sock << get_masked_pan_by_token(input_data);
		  }
		  
	  	  else if (service == "get_tokens_by_masked_pan")
		  {
		      new_sock << get_tokens_by_masked_pan(input_data);
		  }


	          else if (service == "set_token_by_pan")
		  {
    		      CardProcessor cp(input_data); 

		      if (!cp.validate_card_format()) {
		          new_sock << "Wrong credit card format";
  		      }	else {
		          new_sock << set_token_by_pan(cp);
		      }
		  }
		  else 
		  {
		      new_sock << "No such service: " + service;
    		  }
		}
	    }
	  catch ( SocketException& ) {}

	}
    }
    catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }
    
    PQclear(res);
    CloseConn(conn);

  return 0;
}

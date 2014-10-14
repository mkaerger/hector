#include "PGDataSource.h"

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


PGDataSource::PGDataSource() 
{
    conn = PQconnectdb("dbname=hector host=localhost user=postgres password=");
    if (PQstatus(conn) == CONNECTION_BAD) {
            puts("We were unable to connect to the database");
    }
}


std::string PGDataSource::get_pan_by_token(CardProcessor cp) 
{
    s1 = "SELECT pan FROM cc_data WHERE token = '";
    s2 = "';";
    s3 = s1 + cp.token + s2;

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


std::string PGDataSource::get_tokens_by_masked_pan(CardProcessor cp) 
{
    std::string tokens;
    s1 = "SELECT token FROM cc_data WHERE masked_pan = '";
    s2 = "';";
    s3 = s1 + cp.xxx_token + s2;

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


std::string PGDataSource::get_card_type_by_token(CardProcessor cp) 
{
    s1 = "SELECT card_type FROM cc_data WHERE token = '";
    s2 = "';";
    s3 = s1 + cp.token + s2;

    res = PQexec(conn, (char*)s3.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    	puts("ERR NO DATA");
    } else {
        return PQgetvalue(res, 0, 0);
    }
}


std::string PGDataSource::get_count_tokens_by_masked_pan(CardProcessor cp) 
{
    s1 = "SELECT count(token) FROM cc_data WHERE masked_pan = '";
    s2 = "';";
    s3 = s1 + cp.xxx_token + s2;

    res = PQexec(conn, (char*)s3.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    	puts("ERR NO DATA");
    } else {
        return PQgetvalue(res, 0, 0);
    }
}


std::string PGDataSource::get_masked_pan_by_token(CardProcessor cp) 
{
    s1 = "SELECT masked_pan FROM cc_data WHERE token = '";
    s2 = "';";
    s3 = s1 + cp.token + s2;

    res = PQexec(conn, (char*)s3.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    	puts("ERR NO DATA");
    } else {
        return PQgetvalue(res, 0, 0);
    }
}


std::string PGDataSource::get_issuer_by_token(CardProcessor cp) 
{
    s1 = "SELECT issuer FROM cc_data WHERE token = '";
    s2 = "';";
    s3 = s1 + cp.token + s2;

    res = PQexec(conn, (char*)s3.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
   		puts("ERR NO DATA");
    } else {
        return PQgetvalue(res, 0, 0);
    }
}


std::string PGDataSource::get_card_type_by_pan(CardProcessor cp) 
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


std::string PGDataSource::get_token_by_pan(CardProcessor cp) 
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


std::string PGDataSource::get_issuer_by_pan(CardProcessor cp) 
{

    s1 = "SELECT issuer FROM cc_data WHERE pan = '";
    s2 = "';";
    s3 = s1 + cp.machine_readable_card_number() + s2;

    res = PQexec(conn, (char*)s3.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    	puts("ERR NO DATA");
    } else {
        return PQgetvalue(res, 0, 0);
    }
}


std::string PGDataSource::set_token_by_pan(CardProcessor cp) 
{

    std::string stmnt;
    std::string hash = cp.create_token();
    std::string iban = cp.iban;
	
    std::string esc;

	// escape issuer string	
    char* y = new char[iban.length() + 1];
    strcpy(y, iban.c_str());
    esc = PQescapeLiteral(conn, y, strlen(y));

    stmnt.append("INSERT INTO cc_data VALUES ('");
    stmnt.append(cp.machine_readable_card_number());
    stmnt.append("', '");
    stmnt.append(cp.get_masked_pan());
    stmnt.append("', '");
    stmnt.append(hash);
    stmnt.append("', ");
    stmnt.append(esc);
    stmnt.append(", '");
    stmnt.append(cp.card_type);
    stmnt.append("', '");
    stmnt.append("now()");
    stmnt.append("', '");
    stmnt.append("now()");
    stmnt.append("')");

    //std::cout<< stmnt << std::endl;;
    res = PQexec(conn, stmnt.c_str());

    PQclear(res);
    PQfinish(conn);

    if (PQresultStatus(res) == PGRES_COMMAND_OK)
    {
    	return hash;
    } else {
    	return PQerrorMessage(conn);
    } 
}


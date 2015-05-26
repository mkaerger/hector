#include "MySQLDataSource.h"

using namespace std;

sql::Driver *driver;
sql::Connection *conn;
sql::PreparedStatement *pstmt;
sql::ResultSet *res;
std::string mysql_result;

MySQLDataSource::MySQLDataSource() 
{
 	
	try {
		// Create a connection
    	driver = get_driver_instance();
    	conn = driver->connect("tcp://127.0.0.1:3306", "root", "root");

    	// Connect to the MySQL pcidss database
    	conn->setSchema("hector");

	} catch (sql::SQLException &e) {
    	std::cout << "# ERR: SQLException in " << __FILE__;
    	std::cout << "# ERR: " << e.what();
    	std::cout << " (MySQL error code: " << e.getErrorCode();
    	std::cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}


std::string MySQLDataSource::get_pan_by_token(CardProcessor cp) 
{
    std::string pans;

	try {
		pstmt = conn->prepareStatement(
			"SELECT pan FROM cc_data WHERE token = ?");
    	pstmt->setString(1, cp.token);
   
    	res = pstmt->executeQuery();
   
    	res->afterLast();
    	while (res->previous()) {
        	pans = res->getString("pan");
    	}

	} catch (sql::SQLException &e) {
    	std::cout << "# ERR: SQLException in " << __FILE__;
    	std::cout << "# ERR: " << e.what();
    	std::cout << " (MySQL error code: " << e.getErrorCode();
    	std::cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	// Cleanup
    delete res;
    delete pstmt;
    delete conn;
    
    if(pans.empty()) {
        puts("ERR NO PANS FOUND");
    } else { 	 
        return pans;
    }
}

std::string MySQLDataSource::get_tokens_by_masked_pan(CardProcessor cp) 
{
    std::string tokens;

	try {
		pstmt = conn->prepareStatement(
			"SELECT token FROM cc_data WHERE masked_pan = ?");
    	pstmt->setString(1, cp.xxx_token);
   
    	res = pstmt->executeQuery();
   
    	res->afterLast();
    	while (res->previous()) {
        	tokens = res->getString("token");
    	}

	} catch (sql::SQLException &e) {
    	std::cout << "# ERR: SQLException in " << __FILE__;
    	std::cout << "# ERR: " << e.what();
    	std::cout << " (MySQL error code: " << e.getErrorCode();
    	std::cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	// Cleanup
    delete res;
    delete pstmt;
    delete conn;
    
    if(tokens.empty()) {
        puts("ERR NO TOKEN FOUND");
    } else { 	 
        return tokens;
    }
}


std::string MySQLDataSource::get_card_type_by_token(CardProcessor cp) 
{
    std::string card_types;

	try {
		pstmt = conn->prepareStatement(
			"SELECT card_type FROM cc_data WHERE token = ?");
    	pstmt->setString(1, cp.token);
   
    	res = pstmt->executeQuery();
   
    	res->afterLast();
    	while (res->previous()) {
        	card_types = res->getString("card_type");
    	}

	} catch (sql::SQLException &e) {
    	std::cout << "# ERR: SQLException in " << __FILE__;
    	std::cout << "# ERR: " << e.what();
    	std::cout << " (MySQL error code: " << e.getErrorCode();
    	std::cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	// Cleanup
    delete res;
    delete pstmt;
    delete conn;
   
    if(card_types.empty()) {
    	mysql_result = "FIELD EMPTY";    
    } else { 	 
        mysql_result = card_types;
    }

	return mysql_result;
}


std::string MySQLDataSource::get_count_tokens_by_masked_pan(CardProcessor cp) 
{
    std::string count_tokens;

	try {
    	pstmt = conn->prepareStatement(
			"SELECT count(token) AS count_tokens FROM cc_data WHERE masked_pan = ? ");
    	pstmt->setString(1, cp.token);
   
    	res = pstmt->executeQuery();

    	while (res->next()) {
        	count_tokens = res->getString("count_tokens");
    	}
	} catch (sql::SQLException &e) {
    	std::cout << "# ERR: SQLException in " << __FILE__;
    	std::cout << "# ERR: " << e.what();
    	std::cout << " (MySQL error code: " << e.getErrorCode();
    	std::cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
	
	// Cleanup
    delete res;
    delete pstmt;
    delete conn;

    if(count_tokens.empty()) {
    	mysql_result = "FIELD EMPTY";    
    } else { 	 
        mysql_result = count_tokens;
    }

	return mysql_result;
}


std::string MySQLDataSource::get_masked_pan_by_token(CardProcessor cp) 
{
    std::string masked_pans;

	try {
		pstmt = conn->prepareStatement(
			"SELECT masked_pan FROM cc_data WHERE token = ?");
    	pstmt->setString(1, cp.token);
   
    	res = pstmt->executeQuery();
   
    	res->afterLast();
    	while (res->previous()) {
        	masked_pans = res->getString("masked_pan");
    	}

	} catch (sql::SQLException &e) {
    	std::cout << "# ERR: SQLException in " << __FILE__;
    	std::cout << "# ERR: " << e.what();
    	std::cout << " (MySQL error code: " << e.getErrorCode();
    	std::cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	// Cleanup
    delete res;
    delete pstmt;
    delete conn;

    if(masked_pans.empty()) {
    	mysql_result = "FIELD EMPTY";    
    } else { 	 
        mysql_result = masked_pans;
    }

	return mysql_result;
}


std::string MySQLDataSource::get_issuer_by_token(CardProcessor cp) 
{
    std::string issuers;

	try {
		pstmt = conn->prepareStatement(
			"SELECT issuer FROM cc_data WHERE token = ?");
    	pstmt->setString(1, cp.token);
   
    	res = pstmt->executeQuery();
   
    	res->afterLast();
    	while (res->previous()) {
        	issuers = res->getString("issuer");
    	}

	} catch (sql::SQLException &e) {
    	std::cout << "# ERR: SQLException in " << __FILE__;
    	std::cout << "# ERR: " << e.what();
    	std::cout << " (MySQL error code: " << e.getErrorCode();
    	std::cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	// Cleanup
    delete res;
    delete pstmt;
    delete conn;
    
    if(issuers.empty()) {
    	mysql_result = "FIELD EMPTY";    
    } else { 	 
        mysql_result = issuers;
    }

	return mysql_result;
}


std::string MySQLDataSource::get_card_type_by_pan(CardProcessor cp) 
{
    std::string card_types;

	try {
		pstmt = conn->prepareStatement(
			"SELECT card_type FROM cc_data WHERE pan = ?");
    	pstmt->setString(1, cp.machine_readable_card_number());
   
    	res = pstmt->executeQuery();
   
    	res->afterLast();
    	while (res->previous()) {
        	card_types = res->getString("card_type");
    	}

	} catch (sql::SQLException &e) {
    	std::cout << "# ERR: SQLException in " << __FILE__;
    	std::cout << "# ERR: " << e.what();
    	std::cout << " (MySQL error code: " << e.getErrorCode();
    	std::cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	// Cleanup
    delete res;
    delete pstmt;
    delete conn;

    if(card_types.empty()) {
    	mysql_result = "FIELD EMPTY";    
    } else { 	 
        mysql_result = card_types;
    }

	return mysql_result;
}


std::string MySQLDataSource::get_token_by_pan(CardProcessor cp) 
{
    std::string tokens;

	try {
		pstmt = conn->prepareStatement(
			"SELECT token FROM cc_data WHERE pan = ?");
    	pstmt->setString(1, cp.machine_readable_card_number());
   
    	res = pstmt->executeQuery();
   
    	res->afterLast();
    	while (res->previous()) {
        	tokens = res->getString("token");
    	}

	} catch (sql::SQLException &e) {
    	std::cout << "# ERR: SQLException in " << __FILE__;
    	std::cout << "# ERR: " << e.what();
    	std::cout << " (MySQL error code: " << e.getErrorCode();
    	std::cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	// Cleanup
    delete res;
    delete pstmt;
    delete conn;

    if(tokens.empty()) {
    	mysql_result = "FIELD EMPTY";    
    } else { 	 
        mysql_result = tokens;
    }

	return mysql_result;
}


std::string MySQLDataSource::get_issuer_by_pan(CardProcessor cp) 
{
    std::string issuers;

	try {
		pstmt = conn->prepareStatement(
			"SELECT issuer FROM cc_data WHERE pan = ?");
    	pstmt->setString(1, cp.machine_readable_card_number());
   
    	res = pstmt->executeQuery();
   
    	res->afterLast();
    	while (res->previous()) {
        	issuers = res->getString("issuer");
    	}

	} catch (sql::SQLException &e) {
    	std::cout << "# ERR: SQLException in " << __FILE__;
    	std::cout << "# ERR: " << e.what();
    	std::cout << " (MySQL error code: " << e.getErrorCode();
    	std::cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	// Cleanup
    delete res;
    delete pstmt;
    delete conn;

    if(issuers.empty()) {
    	mysql_result = "FIELD EMPTY";    
    } else { 	 
        mysql_result = issuers;
    }

	return mysql_result;
}


std::string MySQLDataSource::set_token_by_pan(CardProcessor cp) 
{

	// Time in sql "SELECT now();" format	
	time_t     now = time(0);
    struct tm  tstruct;
    char       now_time[80];
    tstruct = *localtime(&now);
    strftime(now_time, sizeof(now_time), "%Y-%m-%d.%X", &tstruct);

	std::string hash = cp.create_token();

	try 
	{
		pstmt = conn->prepareStatement(
			"INSERT INTO cc_data(pan, masked_pan, token, issuer, card_type, date_created, date_last_access) VALUES (?, ?, ?, ?, ?, ?, ?)");

    	pstmt->setString(1, cp.machine_readable_card_number()); // pan
    	pstmt->setString(2, cp.get_masked_pan()); // masked_pan
    	pstmt->setString(3, hash); // token
    	pstmt->setString(4, cp.iban); // issuer
    	pstmt->setString(5, cp.card_type); // card_type
    	pstmt->setString(6, now_time); // date_created
    	pstmt->setString(7, now_time); // date_last_access
    	pstmt->executeUpdate();

		conn->commit(); 
		conn->setAutoCommit(true); 
	
	} 
	catch(sql::SQLException &e) 
	{
    	std::cout << "# ERR: SQLException in " << __FILE__;
    	std::cout << "# ERR: " << e.what();
    	std::cout << " (MySQL error code: " << e.getErrorCode();
    	std::cout << ", SQLState: " << e.getSQLState() << " )" << endl;
		
		// Cleanup
    	delete pstmt;
    	delete conn;
		return e.what();
	}

	// Cleanup
    delete pstmt;
    delete conn;

	return hash;
}

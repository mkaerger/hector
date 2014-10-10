#include "MySQLDataSource.h"

using namespace std;

sql::Driver *driver;
sql::Connection *conn;
sql::PreparedStatement *pstmt;
sql::ResultSet *res;


MySQLDataSource::MySQLDataSource() 
{
 	
	try {
		/* Create a connection */
    	driver = get_driver_instance();
    	conn = driver->connect("tcp://127.0.0.1:3306", "root", "root");

    	/* Connect to the MySQL test database */
    	conn->setSchema("pcidss");

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
		pstmt = conn->prepareStatement("SELECT pan FROM cc_data WHERE token = ?");
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
		pstmt = conn->prepareStatement("SELECT token FROM cc_data WHERE masked_pan = ?");
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
		pstmt = conn->prepareStatement("SELECT card_type FROM cc_data WHERE token = ?");
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


    delete res;
    delete pstmt;
    delete conn;
    
    if(card_types.empty()) {
        puts("ERR NO CARD_TYPE FOUND");
    } else { 	 
        return card_types;
    }
}

// todo return of count
std::string MySQLDataSource::get_count_tokens_by_masked_pan(CardProcessor cp) 
{
}


std::string MySQLDataSource::get_masked_pan_by_token(CardProcessor cp) 
{
}


std::string MySQLDataSource::get_provider_by_token(CardProcessor cp) 
{
}


std::string MySQLDataSource::get_card_type_by_pan(CardProcessor cp) 
{
}


std::string MySQLDataSource::get_token_by_pan(CardProcessor cp) 
{
}


std::string MySQLDataSource::get_provider_by_pan(CardProcessor cp) 
{
}

std::string MySQLDataSource::set_token_by_pan(CardProcessor cp) 
{
	std::string hash = cp.create_token();

	pstmt = conn->prepareStatement("INSERT INTO cc_data(pan, masked_pan, token, provider, card_type, date_created, date_last_access) VALUES (?, ?, ?, ?, ?, ?, ?)");

	//pan
    pstmt->setString(1, cp.machine_readable_card_number());

    // masked_pan
    pstmt->setString(2, cp.get_masked_pan());

    // token
    pstmt->setString(3, hash);

    // provider
    pstmt->setString(4, cp.iban);

    // card_type
    pstmt->setString(5, cp.card_type);

    // date_created
    pstmt->setString(6, "now()");

    // date_last_access
    pstmt->setString(7, "now()");

    pstmt->executeUpdate();

	conn->commit(); 
	conn->setAutoCommit(true); 

    delete pstmt;
    delete conn;

	return hash;
}


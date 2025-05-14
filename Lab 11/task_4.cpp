#include <iostream>
#include <exception>
#include <string>

using namespace std;

class DatabaseException : public exception {
public:
    const char* what() const noexcept{
        return "A database error occurred";
    }
};

class ConnectionFailedException : public DatabaseException {};
class QueryTimeoutException : public DatabaseException {};


template <typename T>
class DatabaseConnector {
public:
    void connect(const string& dbName) {
        if (dbName == "invalid_db"){
            throw ConnectionFailedException();
        }
        else if (dbName == "slow_db"){
            throw QueryTimeoutException();
        }
        else{
            cout << "Connected to " << dbName << " successfully.\n";
        }
    }
};

int main() {
    DatabaseConnector<int> db;

    try {
        db.connect("invalid_db");
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    try {
        db.connect("slow_db");
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

}

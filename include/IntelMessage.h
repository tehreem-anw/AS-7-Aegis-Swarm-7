#pragma once
#include <iostream>
#include <string>
using namespace std;

// Class for encrypted communication and data merging between units
class IntelMessage {
private:
    string senderID;
    string encryptedData;
    int encryptionKey;

public:
    // Constructor
    IntelMessage(string id, string data, int key);
    
    // Display message details
    void displayMessage() const;

    // Overload (+) to combine drone data
    IntelMessage operator + (const IntelMessage& other) const;

    // Overload (==) to verify if encryption keys/IDs match to maintain security
    bool operator == (const IntelMessage& other) const;

    // Getters
    string getData() const { return encryptedData; }
    string getSender() const { return senderID; }
};

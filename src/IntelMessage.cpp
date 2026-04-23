#include "IntelMessage.h"
using namespace std;

// Parametrized Constructor: Initializes message with sender ID, data, and security key
IntelMessage::IntelMessage(string id, string data, int key): senderID(id), encryptedData(data), encryptionKey(key) {}

// Merges data from two different messages into a single intel object
IntelMessage IntelMessage::operator + (const IntelMessage& other) const {
    string combinedData = encryptedData + " | " + other.encryptedData;
    // Uses the primary sender's ID and key for the merged message
    return IntelMessage(senderID, combinedData, encryptionKey);
}

// Checks if two messages share the same encryption key for security
bool IntelMessage::operator == (const IntelMessage& other) const {
    return (encryptionKey == other.encryptionKey);
}

// Prints the encrypted packet information
void IntelMessage::displayMessage() const {
    cout<<"[INTEL]: Origin: "<<senderID<<" | Data: "<<encryptedData<<endl;
}

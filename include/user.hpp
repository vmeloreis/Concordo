#ifndef USER_HPP
#define USER_HPP
#include <string>
#include "server.hpp"

class Server;
class User
{
private:
    int id;
    std::string name;
    std::string email;
    std::string password;
    Server *currentServer;

public:
    User(std::string name, std::string email, std::string password)
    {
        this->name = name;
        this->email = email;
        this->password = password;
    }

    User() {}
    int GetID()
    {
        return id;
    }
    std::string GetName()
    {
        return name;
    }
    std::string GetEmail()
    {
        return email;
    }
    std::string GetPassword()
    {
        return password;
    }

    void SetID(int newID)
    {
        id = newID;
    }
    void SetName(std::string newName)
    {
        name = newName;
    }
    void SetEmail(std::string newEmail)
    {
        email = newEmail;
    }
    void SetPassword(std::string newPassword)
    {
        password = newPassword;
    }
    void SetCurrentServer(Server *newCurrentServer)
    {
        currentServer = newCurrentServer;
    }
};

#endif
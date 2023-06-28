#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "../include/system.hpp"

int main()
{
    MySystem system;

    std::ifstream inputFile("../data/commands.txt");
    if (!inputFile)
    {
        std::cout << "Erro ao abrir o arquivo commands.txt" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if (command == "create-user")
        {
            std::string email, password, name;
            iss >> email >> password >> name;
            system.CreateUser(email, password, name);
        }
        else if (command == "login")
        {
            std::string email, password;
            iss >> email >> password;
            system.EnterSystem(email, password);
        }
        else if (command == "quit")
        {
            system.ExitSystem();
            break;
        }
        else if (command == "disconnect")
        {
            system.Disconnect();
        }
        else if (command == "create-server")
        {
            std::string name;
            iss >> name;
            system.CreateServer(name);
        }
        else if (command == "set-server-desc")
        {
            std::string name, description;
            iss >> name;
            std::getline(iss, description);
            description = description.substr(1, description.length() - 2);
            system.ChangeDescription(name, description);
        }
        else if (command == "set-server-invitecode")
        {
            std::string name, inviteCode;
            iss >> name >> inviteCode;
            system.ChangeInviteCode(name, inviteCode);
        }
        else if (command == "list-servers")
        {
            system.GetAllServers();
        }
        else if (command == "remove-server")
        {
            std::string name;
            iss >> name;
            system.RemoveServer(name);
        }
        else if (command == "enter-server")
        {
            std::string name;
            iss >> name;
            system.EnterServer(name);
        }
        else if (command == "leave-server")
        {
            system.LeaveServer();
        }
        else if (command == "list-participants")
        {
            system.GetAllUsersServer();
        }
        else
        {
            std::cout << "Comando inválido: " << command << std::endl;
        }
    }

    inputFile.close();

    return 0;
}
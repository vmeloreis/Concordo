#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "../include/system.hpp"

int main()
{
    MySystem system;

    std::string command;
    std::cout << "Bem-vindo ao sistema!" << std::endl;
    system.Load();

    while (true)
    {
        std::cout << "Digite um comando: ";
        std::getline(std::cin, command);

        std::istringstream iss(command);
        std::string cmd;
        iss >> cmd;

        if (cmd == "create-user")
        {
            std::string email, password, name;
            iss >> email >> password >> name;
            system.CreateUser(email, password, name);
            system.Save();
        }
        else if (cmd == "login")
        {
            std::string email, password;
            iss >> email >> password;
            system.EnterSystem(email, password);
        }
        else if (cmd == "quit")
        {
            system.ExitSystem();
            system.Save();
            break;
        }
        else if (cmd == "disconnect")
        {
            system.Disconnect();
        }
        else if (cmd == "create-server")
        {
            std::string name;
            iss >> name;
            system.CreateServer(name);
            system.Save();
        }
        else if (cmd == "set-server-desc")
        {
            std::string name, description;
            iss >> name;
            std::getline(iss, description);
            description = description.substr(1, description.length() - 2);
            system.ChangeDescription(name, description);
            system.Save();
        }
        else if (cmd == "set-server-invitecode")
        {
            std::string name, inviteCode;
            iss >> name >> inviteCode;
            system.ChangeInviteCode(name, inviteCode);
            system.Save();
        }
        else if (cmd == "list-servers")
        {
            system.GetAllServers();
        }
        else if (cmd == "remove-server")
        {
            std::string name;
            iss >> name;
            system.RemoveServer(name);
            system.Save();
        }
        else if (cmd == "enter-server")
        {
            std::string name;
            iss >> name;
            system.EnterServer(name);
            system.Save();
        }
        else if (cmd == "leave-server")
        {
            system.LeaveServer();
            system.Save();
        }
        else if (cmd == "list-participants")
        {
            system.GetAllUsersServer();
        }
        else if (cmd == "create-channel")
        {
            std::string name, type;
            iss >> name >> type;
            system.GetCurrentServer()->CreateChannel(name, type);
            system.Save();
        }
        else if (cmd == "list-channels")
        {
            system.GetCurrentServer()->ListAllChannels();
        }
        else if (cmd == "enter-channel")
        {
            std::string name;
            iss >> name;
            system.EnterChannel(name);
            system.Save();
        }
        else if (cmd == "leave-channel")
        {
            system.LeaveChannel();
            system.Save();
        }
        else if (cmd == "send-message")
        {
            std::string message;
            std::getline(iss, message);
            message = message.substr(1, message.length() - 2);
            system.SendMessage(message);
            system.Save();
        }
        else if (cmd == "list-messages")
        {
            system.ViewAllMessages();
        }
        else
        {
            std::cout << "Comando inválido: " << cmd << std::endl;
        }
    }

    return 0;
}
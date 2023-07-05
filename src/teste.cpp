#include "../include/server.hpp"
#include "../include/system.hpp"

#include <iostream>

int main()
{
    MySystem sistema;

    sistema.CreateUser("dasuda", "dasjda", "1231");
    sistema.CreateServer("isso");
    sistema.EnterServer("isso");

    sistema.GetServer()[0].CreateChannel("grilos", "TextChannel");
    sistema.GetServer()[0].CreateChannel("grilos", "TextChanel");
    sistema.GetServer()[0].CreateChannel("bullocks", "TextChannel");

    sistema.EnterChannel("bullocks");
    sistema.SendMessage("oi pessoal");
    sistema.ViewAllMessages();

    return 0;
}
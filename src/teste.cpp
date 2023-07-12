#include "../include/server.hpp"
#include "../include/system.hpp"

#include <iostream>

int main()
{
    MySystem system;

    // Criar alguns usuários
    system.CreateUser("user1@example.com", "password1", "User 1");
    system.CreateUser("user2@example.com", "password2", "User 2");
    system.CreateUser("user3@example.com", "password3", "User 3");

    // Criar servidores
    system.CreateServer("Server 1");
    system.CreateServer("Server 2");

    // Entrar no sistema e em um servidor
    system.EnterSystem("user1@example.com", "password1");
    system.EnterServer("Server 1");

    // Adicionar usuários a servidores
    system.EnterSystem("user2@example.com", "password2");
    system.EnterServer("Server 1");

    system.EnterSystem("user3@example.com", "password3");
    system.EnterServer("Server 2");

    // Adicionar canais e enviar mensagens
    system.EnterChannel("General");
    system.SendMessage("Hello, everyone!");

    system.EnterChannel("Voice Channel");
    system.SendMessage("This is a voice message.");

    // Visualizar mensagens
    system.ViewAllMessages();

    // Salvar os dados do sistema
    system.Save();

    return 0;
}
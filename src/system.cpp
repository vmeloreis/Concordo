#include "../include/system.hpp"

void MySystem::ExitSystem()
{
    currentChannel = nullptr;
    currentServer = nullptr;

    std::cout << "Saindo Do Concordo";
}
void MySystem::CreateUser(std::string email, std::string password, std::string name)
{
    int idCount = 1;
    if (allUsers.empty())
    {

        allUsers.resize(idCount);
        allUsers[0].SetID(idCount);
        allUsers[0].SetEmail(email);
        allUsers[0].SetName(name);
        allUsers[0].SetPassword(password);

        currentUser = new User;
        currentUser = &allUsers[0];
        std::cout << "Usuario Criado!" << std::endl;
    }
    else
    {
        for (auto x : allUsers)
        {

            if (x.GetEmail() != email)
            {
                idCount++;

                allUsers.resize(idCount);
                allUsers.back().SetID(idCount);
                allUsers.back().SetEmail(email);
                allUsers.back().SetName(name);
                allUsers.back().SetPassword(password);

                currentUser = new User;
                currentUser = &allUsers.back();
                std::cout << "Usuario Criado!" << std::endl;
            }
            else
            {
                std::cout << "Usuario Ja Existe!" << std::endl;
            }
        }
    }
}
void MySystem::EnterSystem(std::string email, std::string password)
{

    for (auto &x : allUsers)
    {
        if (x.GetEmail() == email && x.GetPassword() == password)
        {
            currentUser = &x;
            std::cout << "Logado como " << x.GetEmail() << std::endl;
        }
        else
        {
            std::cout << "Senha ou Usuario Invalidos!" << std::endl;
        }
    }
}

void MySystem::Disconnect()
{

    if (IsLogged())
    {

        std::cout << "Desconectando usuario " << currentUser->GetEmail() << std::endl;
        currentUser = nullptr;
    }
    else
    {
        std::cout << "Nao esta conectado!" << std::endl;
    }
}

bool MySystem::IsLogged()
{
    return (currentUser != nullptr);
}

void MySystem::CreateServer(std::string name)
{

    int donoldID = currentUser->GetID();
    Server newServer(donoldID, name, "", "");
    for (auto x : allServers)
    {
        if (x.GetServerName() == name)
        {
            std::cout << "Servidor com esse nome já existe!" << std::endl;
            return;
        }
    }
    allServers.push_back(newServer);
    std::cout << "Servidor criado" << std::endl;
}

void MySystem::ChangeDescription(std::string name, std::string description)
{
    for (auto &x : allServers)
    {
        if (x.GetServerName() == name)
        {
            if (x.GetOwnerID() == currentUser->GetID())
            {
                x.SetDescription(description);
                std::cout << "Descricao do servidor " << x.GetServerName() << " modificada!" << std::endl;
                return;
            }
            else
            {
                std::cout << "Voce nao pode alterar a descricao de um servidor nao criado por voce" << std::endl;
                return;
            }
        }
    }

    std::cout << name << " nao existe!" << std::endl;
}

void MySystem::ChangeInviteCode(std::string name, std::string newInviteCode)
{
    for (auto x : allServers)
    {
        if (x.GetServerName() == name && x.GetOwnerID() == currentUser->GetID())
        {
            x.SetIniviteCode(newInviteCode);
            std::cout << "Codigo de convite do servidor " << x.GetServerName() << " modificado!" << std::endl;
        }
    }
}
void MySystem::ChangeInviteCode(std::string name)
{
    for (auto x : allServers)
    {
        if (x.GetServerName() == name && x.GetOwnerID() == currentUser->GetID())
        {
            x.SetIniviteCode("");
            std::cout << "Codigo de convite do servidor " << x.GetServerName() << " removido!" << std::endl;
        }
    }
}

void MySystem::GetAllServers()
{
    for (auto x : allServers)
    {
        std::cout << x.GetServerName() << std::endl;
    }
}

void MySystem::RemoveServer(std::string name)
{
    bool serverRemoved = false;

    for (int i = 0; i < allServers.size(); i++)
    {
        if (allServers[i].GetServerName() == name)
        {
            if (allServers[i].GetOwnerID() == currentUser->GetID())
            {
                allServers.erase(allServers.begin() + i);
                std::cout << "Servidor " << name << " removido!" << std::endl;
                serverRemoved = true;
                break;
            }
            else
            {
                std::cout << "Voce nao e dono do servidor " << name << std::endl;
                serverRemoved = true;
                break;
            }
        }
    }

    if (!serverRemoved)
    {
        std::cout << "Servidor " << name << " nao encontrado" << std::endl;
    }
}

void MySystem::EnterServer(std::string name)
{
    for (auto &x : allServers)
    {
        if (x.GetServerName() == name)
        {
            if (x.GetInviteCode() == "")
            {
                x.GetParticipants().push_back(currentUser->GetID());
                currentUser->SetCurrentServer(&x);
                std::cout << "Entrou no servidor com sucesso" << std::endl;
                currentServer = &x;
                return;
            }
            else
            {
                std::string code;
                std::cout << "Servidor requer código de convite: ";
                std::cin >> code;
                if (code == x.GetInviteCode())
                {
                    x.GetParticipants().push_back(currentUser->GetID());
                    currentUser->SetCurrentServer(&x);
                    std::cout << "Entrou no servidor com sucesso" << std::endl;
                    currentServer = &x;
                    return;
                }
                else
                {
                    std::cout << "Código de convite incorreto" << std::endl;
                    return;
                }
            }
        }
    }

    std::cout << "Servidor não encontrado" << std::endl;
}
void MySystem::LeaveServer()
{
    if (currentServer != nullptr)
    {
        std::cout << "Saindo do servidor " << currentServer->GetServerName();
        currentServer = nullptr;
        currentUser->SetCurrentServer(nullptr);
    }
    else
    {
        std::cout << "Voce nao esta visualizando nenhum servidor" << std::endl;
    }
}

void MySystem::GetAllUsersServer()
{
    if (currentServer != nullptr)
    {
        for (auto userID : currentServer->GetParticipants())
        {

            User *user = GetUserByID(userID);

            if (user != nullptr)
            {
                std::cout << "ID: " << user->GetID() << ", Nome: " << user->GetName() << ", Email: " << user->GetEmail() << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Voce nao esta visualizando nenhum servidor." << std::endl;
    }
}
User *MySystem::GetUserByID(int id)
{

    for (auto &x : allUsers)
    {
        if (x.GetID() == id)
        {
            return &x;
        }
    }

    return nullptr;
}

void MySystem::EnterChannel(std::string name)
{

    if (currentServer == nullptr)
    {
        return;
    }

    if (!IsLogged())
    {
        std::cout << "Nao esta logado no sistema!" << std::endl;
    }
    for (Channel *channel : currentServer->GetChannels())
    {
        if (channel->GetName() == name)
        {
            currentChannel = channel;
            std::cout << "Entrou no canal " << name << std::endl;
            return;
        }
    }
    std::cout << "Canal " << name << " nao existe" << std::endl;
}
void MySystem::LeaveChannel()
{
    if (currentChannel == nullptr)
    {
        std::cout << "Nao esta em nenhum canal" << std::endl;
    }
    if (!IsLogged())
    {
        std::cout << "Nao esta logado no sistema!" << std::endl;
    }
    currentChannel = nullptr;
    std::cout << "Saindo do canal" << std::endl;
}

void MySystem::SendMessage(std::string message)
{
    int currentUserID = currentUser->GetID();

    if (!IsLogged())
    {
        std::cout << "Nao esta logado no sistema!" << std::endl;
        return;
    }

    if (currentChannel == nullptr)
    {
        std::cout << "Nao esta em nenhum canal" << std::endl;
        return;
    }

    std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
    Message newMessage(currentTime, currentUserID, message);
    currentChannel->NewMessage(newMessage);
}
void MySystem::ViewAllMessages()
{

    TextChannel *textChannel;
    VoiceChannel *VoiceChannel;
    if (!IsLogged())
    {
        std::cout << "nao esta logado no sistema!" << std::endl;
        return;
    }
    if (currentChannel == nullptr)
    {
        std::cout << "nao esta em nenhum canal" << std::endl;
        return;
    }
    if (currentChannel->GetMessages().empty())
    {
        std::cout << "sem mensagens" << std::endl;
        return;
    }
    for (auto x : currentChannel->GetMessages())
    {
        std::time_t currentTime = std::chrono::system_clock::to_time_t(x.GetTime());
        std::string timeSent = std::ctime(&currentTime);

        if (!timeSent.empty() && timeSent[timeSent.length() - 1] == '\n')
        {
            timeSent.erase(timeSent.length() - 1);
        }
        std::cout << GetUserByID(x.GetAuthor())->GetName() << "< " << timeSent << " >" << x.GetMessage() << std::endl;
    }
}

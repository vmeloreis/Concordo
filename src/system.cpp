#include "../include/system.hpp"
#include "../include/timeUtils.hpp"
#include <fstream>

void MySystem::ExitSystem()
{
    currentChannel = nullptr;
    currentServer = nullptr;

    std::cout << "Saindo Do Concordo";
}
void MySystem::CreateUser(const std::string &email, const std::string &password, const std::string &name)
{
    bool userExists = false;

    for (auto &user : allUsers)
    {
        if (user.GetEmail() == email)
        {
            userExists = true;
            break;
        }
    }

    if (userExists)
    {
        std::cout << "Usuario ja existe!" << std::endl;
    }
    else
    {
        int idCount = allUsers.size() + 1;
        allUsers.emplace_back();
        allUsers.back().SetID(idCount);
        allUsers.back().SetEmail(email);
        allUsers.back().SetName(name);
        allUsers.back().SetPassword(password);

        currentUser = &allUsers.back();
        std::cout << "Usuario criado!" << std::endl;
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
            return;
        }
    }

    std::cout << "Senha ou Usuario Invalidos!" << std::endl;
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
    for (auto &server : allServers)
    {
        if (server.GetServerName() == name)
        {
            if (server.GetInviteCode() == "")
            {
                server.GetParticipants().push_back(currentUser->GetID());
                Server *copiedServer = new Server(server);
                currentUser->SetCurrentServer(copiedServer);
                std::cout << "Entrou no servidor com sucesso" << std::endl;
                currentServer = copiedServer;
                return;
            }
            else
            {
                std::string code;
                std::cout << "Servidor requer código de convite: ";
                std::cin >> code;
                if (code == server.GetInviteCode())
                {
                    server.GetParticipants().push_back(currentUser->GetID());
                    Server *copiedServer = new Server(server);
                    currentUser->SetCurrentServer(copiedServer);
                    std::cout << "Entrou no servidor com sucesso" << std::endl;
                    currentServer = copiedServer;
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
void MySystem::SaveUsers()
{
    std::ofstream arquivo("usuarios.txt");
    if (arquivo.is_open())
    {
        arquivo << allUsers.size() << '\n';
        for (auto &user : allUsers)
        {
            arquivo << user.GetID() << '\n';
            arquivo << user.GetName() << '\n';
            arquivo << user.GetEmail() << '\n';
            arquivo << user.GetPassword() << '\n';
        }
        arquivo.close();
        std::cout << "Arquivo 'usuarios.txt' salvo com sucesso." << std::endl;
    }
    else
    {
        std::cout << "Não foi possível abrir o arquivo 'usuarios.txt'." << std::endl;
    }
}

void MySystem::SaveServers()
{
    std::ofstream arquivo("servidores.txt");
    if (arquivo.is_open())
    {
        arquivo << allServers.size() << '\n';
        for (auto &server : allServers)
        {
            arquivo << server.GetOwnerID() << '\n';
            arquivo << server.GetServerName() << '\n';
            arquivo << server.GetDescription() << '\n';
            if (server.IsOpen())
            {
                arquivo << '\n';
            }
            else
            {
                arquivo << server.GetInviteCode() << '\n';
            }

            arquivo << server.GetParticipants().size() << '\n';
            for (auto &participant : server.GetParticipants())
            {
                arquivo << participant << '\n';
            }

            arquivo << server.GetChannels().size() << '\n';
            for (auto &channel : server.GetChannels())
            {
                arquivo << channel->GetName() << '\n';
                arquivo << channel->GetType() << '\n';

                std::vector<Message> messages = channel->GetMessages();
                arquivo << messages.size() << '\n';
                for (auto &message : messages)
                {
                    arquivo << message.GetAuthor() << '\n';

                    std::time_t time = std::chrono::system_clock::to_time_t(message.GetTime());
                    std::tm *timeInfo = std::localtime(&time);
                    char buffer[80];
                    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);
                    arquivo << buffer << '\n';

                    arquivo << message.GetMessage() << '\n';
                }
            }
        }

        arquivo.close();
        std::cout << "Arquivo 'servidores.txt' salvo com sucesso." << std::endl;
    }
    else
    {
        std::cout << "Não foi possível abrir o arquivo 'servidores.txt'." << std::endl;
    }
}

void MySystem::Save()
{
    SaveUsers();
    SaveServers();
}
void MySystem::LoadUsers()
{
    std::ifstream arquivoUsuarios("usuarios.txt");
    if (!arquivoUsuarios)
    {
        std::cout << "Erro ao abrir o arquivo usuarios.txt." << std::endl;
        return;
    }

    int totalUsuarios;
    arquivoUsuarios >> totalUsuarios;

    for (int i = 0; i < totalUsuarios; i++)
    {
        int id;
        std::string nome;
        std::string email;
        std::string senha;

        arquivoUsuarios >> id;
        arquivoUsuarios.ignore();
        std::getline(arquivoUsuarios, nome);
        std::getline(arquivoUsuarios, email);
        std::getline(arquivoUsuarios, senha);

        allUsers.push_back(User(id, nome, email, senha));
    }

    arquivoUsuarios.close();
}
void MySystem::LoadServers()
{
    std::ifstream arquivoServidores("servidores.txt");
    if (!arquivoServidores)
    {
        std::cout << "Erro ao abrir o arquivo servidores.txt." << std::endl;
        return;
    }

    int totalServidores;
    arquivoServidores >> totalServidores;

    for (int i = 0; i < totalServidores; i++)
    {
        int ownerID;
        std::string nome;
        std::string descricao;
        std::string codigoConvite;
        int totalParticipantes;

        arquivoServidores >> ownerID;
        arquivoServidores.ignore();
        std::getline(arquivoServidores, nome);
        std::getline(arquivoServidores, descricao);
        std::getline(arquivoServidores, codigoConvite);
        arquivoServidores >> totalParticipantes;

        std::vector<int> participantes;
        for (int j = 0; j < totalParticipantes; j++)
        {
            int userID;
            arquivoServidores >> userID;
            participantes.push_back(userID);
        }

        allServers.push_back(Server(ownerID, nome, descricao, codigoConvite, participantes));

        int totalCanais;
        arquivoServidores >> totalCanais;

        for (int j = 0; j < totalCanais; j++)
        {
            std::string nomeCanal;
            std::string tipoCanal;
            int totalMensagens;

            arquivoServidores.ignore(); // Ignorar o caractere de nova linha
            std::getline(arquivoServidores, nomeCanal);
            std::getline(arquivoServidores, tipoCanal);
            arquivoServidores >> totalMensagens;

            if (tipoCanal == "TextChannel")
            {
                TextChannel *textChannel = new TextChannel(nomeCanal, tipoCanal);

                for (int k = 0; k < totalMensagens; k++)
                {
                    int idUsuario;
                    std::chrono::system_clock::time_point dataHora;
                    std::string conteudo;

                    arquivoServidores >> idUsuario;
                    arquivoServidores >> dataHora;
                    arquivoServidores.ignore();
                    std::getline(arquivoServidores, conteudo);

                    textChannel->NewMessage(Message(dataHora, idUsuario, conteudo));
                }

                allServers[i].CreateChannel(textChannel->GetName(), "TextChannel");
            }
            else if (tipoCanal == "VoiceChannel")
            {
                VoiceChannel *voiceChannel = new VoiceChannel(nomeCanal, tipoCanal);

                for (int k = 0; k < totalMensagens; k++)
                {
                    int idUsuario;
                    std::chrono::system_clock::time_point dataHora;
                    std::string conteudo;

                    arquivoServidores >> idUsuario;
                    arquivoServidores >> dataHora;
                    arquivoServidores.ignore();
                    std::getline(arquivoServidores, conteudo);

                    voiceChannel->NewMessage(Message(dataHora, idUsuario, conteudo));
                }

                allServers[i].CreateChannel(voiceChannel->GetName(), "VoiceChannel");
            }
        }
    }

    arquivoServidores.close();
}

void MySystem::Load()
{
    LoadUsers();
    LoadServers();
}

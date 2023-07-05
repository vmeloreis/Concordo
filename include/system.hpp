#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#include "server.hpp"
#include <iostream>

/**
 * @brief classe sistema onde será gerenciado todo o funcionamento do sistema
 *
 */
class MySystem
{
private:
    std::vector<User> allUsers;     /** <vetor de todos os usuarios do sistema*/
    std::vector<Server> allServers; /** <vetor de todos os servidores do sistema*/
    User *currentUser;              /** ponteiro apontado para o usuario atual*/
    Server *currentServer;          /**< ponteiro apontado para o servidor atual*/
    Channel *currentChannel;        /** ponteiro apontado para o canal atual*/

public:
    Server *GetCurrentServer()
    {
        return currentServer;
    }
    std::vector<Server> &GetServer()
    {
        return allServers;
    }
    /**
     * @brief Construtor do objeto, inicializa as variaveis como nula logo que um sistema foi recém criado
     *
     */
    MySystem()
    {
        currentUser = nullptr;
        currentServer = nullptr;
        currentChannel = nullptr;
    }
    /**
     * @brief função para sair do sistema
     *
     */
    void ExitSystem();
    /**
     * @brief cria um objeto user e adiciona ele no vetor de usuarios do sistema com os parametros
     *
     * @param email string que representa o email
     * @param password string que representa a senha
     * @param name string que representa o nome
     */
    void CreateUser(std::string email, std::string password, std::string name);
    /**
     * @brief função para entrar em um sistema, fazer login de acordo com o email e a senha, confere se existe essas informações dentro do sistema
     *
     * @param email string que representa o email
     * @param password string que representa a senha
     */
    void EnterSystem(std::string email, std::string password);
    /**
     * @brief função que desconecta o usuario atual do sistema, coloca o current user para nulo, ao contrario da função exit que mantem o usuario atual logado
     *
     */
    void Disconnect();
    /**
     * @brief função booleana que confere se existe alguem logado no sistema
     *
     * @return true caso esteja
     * @return false  caso não esteja
     */
    bool IsLogged();
    /**
     * @brief função que cria um servidor novo em base no nome passado como parametro
     * @param name nome do servidor a ser criado
     *
     */
    void CreateServer(std::string name);
    /**
     * @brief função que muda a descrição do servidor em base no nome, faz uma busca pelo vetor de servidores
     *
     * @param name nome do servidor a ser mudada a descrição
     * @param description descrição nova a ser adicionada ao servidor
     */
    void ChangeDescription(std::string name, std::string description);
    /**
     * @brief função para mudar a chave de acesso de um servidor passado por parametro, também faz uma busca pelo nome do vetor de servidores
     *
     * @param name nome do servidor a ter seu codigod e acesso modificado
     * @param inviteCode novo codigo de acesso
     */
    void ChangeInviteCode(std::string name, std::string inviteCode);
    /**
     * @brief função para mudar a chave de acesso de um servidor para nula,deixando-o aberto(sobrecarga da função anterior)
     *
     * @param name nome do servidor que terá sua chave revogada
     */
    void ChangeInviteCode(std::string name);
    /**
     * @brief função que imprime todos os servidores do sistema pelo vector criado
     *
     */
    void GetAllServers();
    /**
     * @brief função que remove um servidor em base no seu nome
     *
     * @param name nome do servidor a ser removido, sofre uma busca por nome dentro da função
     */
    void RemoveServer(std::string name);
    /**
     * @brief função para entrar em um servidor, manipula a variavel currentserver para o servidor atualmente observado
     *
     * @param name nome do servidor a ser observado
     */
    void EnterServer(std::string name);
    /**
     * @brief função para sair do servidor, manipula a variavel currentserver
     *
     */
    void LeaveServer();
    /**
     * @brief função para imprimir todos os usuarios de um servidor observado, controlado pela variavel currentserver
     *
     */
    void GetAllUsersServer();

    /**
     * @brief retorna o usuario atual
     *
     * @return usuario a ser retornado
     */
    User *GetCurrentUser()
    {
        return currentUser;
    }
    /**
     * @brief Função para retornar o usuario pelo seu id.
     *
     * @param id id do usuario
     * @return User*
     */
    User *GetUserByID(int id);
    /**
     * @brief função para entrar em um canal baseado em seu nome
     *
     * @param name nome do canal a entrar
     */
    void EnterChannel(std::string name);
    /**
     * @brief sai do canal atual, seta a variavel responsavel pelo canal atual para nulo
     *
     */
    void LeaveChannel();
    /**
     * @brief cria uma mensagem para ser armazenado no vetor de mensagens do text channel
     *
     * @param message mensagem a ser enviada
     */
    void SendMessage(std::string message);
    /**
     * @brief lista todas as mensagens digitadas
     *
     */
    void ViewAllMessages();
};

#endif
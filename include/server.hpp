#ifndef SERVER_HPP
#define SERVER_HPP
#include "channel.hpp"
#include "message.hpp"
#include "textChannel.hpp"
#include "user.hpp"
#include "voiceChannel.hpp"
#include <iostream>

/**
 * @brief classe Server para representar o servidor
 *
 */
class Server
{
private:
    int ownerID;                     /** <ID do dono do servidor criado*/
    std::string name;                /** < nome do servidor*/
    std::string description;         /**< descrição do servidor*/
    std::string inviteCode;          /**< código de acesso do servidor*/
    std::vector<Channel *> channels; /**< vetor de canais do servidor, ponteiros*/
    std::vector<int> participantsID; /** <vetor de IDS dos participantes do servidor*/

public:
    /**
     * @brief constroi um objeto servidor com os parametros abaixo
     *
     * @param ownerID id do criador do servidor
     * @param name nome do servidor
     * @param description descrição do servidor
     * @param inviteCode código de acesso do servidor
     * @param participantsID vetor de participantes do servidor
     */
    Server(int ownerID, std::string name, std::string description, std::string inviteCode, std::vector<int> participantsID)
    {
        this->ownerID = ownerID;
        this->name = name;
        this->description = description;
        this->inviteCode = inviteCode;
        this->participantsID = participantsID;
    }
    Server(int ownerID, std::string name, std::string description, std::string inviteCode)
    {
        this->ownerID = ownerID;
        this->name = name;
        this->description = description;
        this->inviteCode = inviteCode;
    }

    /**
     * @brief Função que retorna o ID do criador do servidor
     *
     * @return int
     */
    int GetOwnerID()
    {
        return ownerID;
    }
    /**
     * @brief Função que retorna o nome do servidor
     *
     * @return std::string
     */
    std::string GetServerName()
    {
        return name;
    }
    /**
     * @brief função que retorna a descrição do servidor
     *
     * @return std::string
     */
    std::string GetDescription()
    {
        return description;
    }
    /**
     * @brief função que retorna o codigo de acesso do servidor
     *
     * @return std::string
     */
    std::string GetInviteCode()
    {
        return inviteCode;
    }

    /**
     * @brief função que retorna a lista de IDS do participante do servidor
     *
     * @return std::vector<int>
     */
    std::vector<int> GetParticipants()
    {
        return participantsID;
    }

    /**
     * @brief função para setar o nome do servidor
     *
     * @param newServerName novo nome
     */
    void SetServerName(std::string newServerName)
    {
        name = newServerName;
    }
    /**
     * @brief função para setar a descrição do servidor
     *
     * @param newDescription nova descrição
     */
    void SetDescription(std::string newDescription)
    {
        description = newDescription;
    }
    /**
     * @brief função para setar o código de acesso do servidor
     *
     * @param newInviteCode novo código de acesso
     */
    void SetIniviteCode(std::string newInviteCode)
    {
        inviteCode = newInviteCode;
    }
    /**
     * @brief Lista todos os canais dentro de um servidor de acordo com sua especificidade, se é de texto ou de voz
     *
     */
    void ListAllChannels();
    /**
     * @brief Cria um canal em servidor e seta seu tipo
     *
     * @param name nome do canal
     * @param type tipo do canal, texto ou voz
     */
    void CreateChannel(std::string name, std::string type);
    /**
     * @brief Retorna o objeto channels
     *
     * @return vetor de canais
     */
    std::vector<Channel *> GetChannels()
    {
        return channels;
    }
    /**
     * @brief função que pergunta se um servidor está aberta ou fechado em relação ao seu código de convite
     *
     * @return true caso esteja aberto
     * @return false caso esteja fechado
     */
    bool IsOpen() const;
};

#endif
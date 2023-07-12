# Concordo
UFRN-LP1 PROJECT

# Identificação
- Vinicius Melo Reis Do Nascimento

# Resumo
- Esse é um projeto que simula as aplicações do aplicativo discord em formato de comandos, os comandos aplicados e classes implementadas foram apenas em volta da parte 1 e 2 e 3 do projeto, com um menu de interação baseado em comandos, tive dificuldades em algumas funções e no arquivo.txt dos usuarios, de resto o programa está completo e funcionando normalmente.


# Como compilar e rodar o programa
- Tenha o cmake instalado em seu ambiente
- Navegue até o diretorio raiz do projeto e digite o seguinte comando: cmake . -B build cd build make 
- Ou navegue até a pasta build e digite o seguinte comando: make


# Funcionalidades
create-user <email> <password> <name> -- cria um usuario novo

login <email> <password> -- faz login no sistema

create-server <name> -- cria um servidor novo

set-server-desc <name> <description> --- cria uma descrição nova para um servidor

set-server-invitecode <name> <inviteCode> --- cria uma nova chave de acesso para um servidor 

list-servers -- lista os servidores

enter-server <name> -- entra em um servidor

list-participants -- lista os participantes de um servidor

leave-server -- lista todos os servers

create-channel -- cria um canal novo

list-channel -- lista os canais 

enter-channel -- entre em um canal

leave-channel -- sai de um canal

send-message -- envia uma mensagem

list-messages lista todas as mensagens

disconnect -- desconecta o usuario

quit -- fecha a aplicação



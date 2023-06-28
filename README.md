# Concordo
UFRN-LP1 PROJECT

#Identificação
- Vinicius Melo Reis Do Nascimento

#Como compilar e rodar o programa
-Tenha o cmake instalado em seu ambiente
-Navegue até o diretorio raiz do projeto e digite o seguinte comando: cmake . -B build cd build make 
-Ou navegue até a pasta build e digite o seguinte comando: make


#Funcionalidades
create-user <email> <password> <name> -- cria um usuario novo
login <email> <password> -- faz login no sistema
create-server <name> -- cria um servidor novo
set-server-desc <name> <description> --- cria uma descrição nova para um servidor
set-server-invitecode <name> <inviteCode> --- cria uma nova chave de acesso para um servidor 
list-servers -- lista os servidores
enter-server <name> -- entra em um servidor
list-participants -- lista os participantes de um servidor
leave-server -- lista todos os servers
disconnect -- desconecta o usuario
quit -- fecha a aplicação

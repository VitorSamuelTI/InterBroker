# InterBroker

Projeto em C/C++ para conexão TCP, processamento XML, gerenciamento de filas e gerenciamento de arquivos.

## Habilitar ubuntu para build:

$ sudo apt install -y build-essential

$ sudo apt install -y gdbserver

$ sudo apt install -y gdb

## Habilitar SSH Server:

$ sudo apt install -y openssh-server

$ sudo vim /etc/ssh/sshd_config

PasswordAuthentication = yes

## Gerar chaves:

$ sudo ssh-keygen -A

## Iniciar Serviço:

$ sudo service ssh start

OBS: Sempre que iniciar o Linux deverá iniciar o serviço para conectar-se.

------------------------------------------------------------------------------------------------
## Linker command Line

-pthread -pq

------------------------------------------------------------------------------------------------
## Instalar e configurar postgres

$ sudo apt-get install postgresql

$ sudo apt-get install libpq-dev

$ sudo service postgresql start

$ sudo -u postgres psql postgres

postgres=# \password postgres

$ sudo -u postgres createuser vitor

postgres=# ALTER USER vitor WITH password 'vitor123';

$ sudo -u postgres createdb broker --owner vitor

OBS: exit postgres \q

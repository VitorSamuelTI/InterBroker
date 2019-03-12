# InterBroker

Projeto em C/C++ para conexão TCP, processamento XML, gerenciamento de filas e gerenciamento de arquivos.

## Habilitar ubuntu para build:

$ sudo apt install -y build-essential

$ sudo apt install -y gdbserver

## Habilitar SSH Server:

$ sudo apt install -y openssh-server

$ sudo vim /etc/ssh/sshd_config

PasswordAuthentication = yes

## Gerar chaves:

$ sudo ssh-keygen -A

## Iniciar Serviço:

$ sudo service ssh start

OBS: Sempre que iniciar o Linux deverá iniciar o serviço para conectar-se.

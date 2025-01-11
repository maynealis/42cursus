# Born2beRoot

## Requisits
This project consists of having you set up your first server by following specific rules. 

Since it is a matter of setting up a server, you will install the minimum of services. For this reason, a graphical interface is of no use here. It is therefore forbidden to install X.org or any other
equivalent graphics server.

You must choose as an operating system either the latest stable version of Debian (no testing/unstable), or the latest stable version of Rocky.

You must create at least 2 encrypted partitions using LVM.

A SSH service will be running on the mandatory port 4242 in your virtual machine. For security reasons, it must not be possible to connect using SSH as root.

You have to configure your operating system with the UFW (or firewalld for Rocky) firewall and thus leave only port 4242 open in your virtual machine.

## Logs (What I'm doing)

1. Download the last stable version of Debian.

[Check the last stable version of Debian](https://www.debian.org/releases/)

2. Create a new VM using **Oracle VM Virtual Box**. RAM : 1024MB and 1 processor. 10GB on the disk (allocated dynamicaly) and choose the ISO downloaded on the disk.

Run and install with no graphic interface.

3. Install sudo.
- From the root with `apt install sudo`.
[!Question]
What is sudo
- Reboot
- From root add group with `sudo addgroup <name_group>` 
- To create a user: `sudo adduser <name_user>`
- To put the user in the group `sudo adduser <user> <group>`
- To see `getent group <group>`

Install openssh-server (si no lo hemos hecho antes)

- To check ssh: `sudo service ssh status`
- Editar el fichero /etc/ssh/sshd_config para modificar el puerto y el tema de que el root no se pueda conectar por seguridad.
- /etc/ssh/ssh_config tambien cambiar el puerto.
- para aplicar los cambios: `sudo service ssh restart` 

UFW
- `sudo apt install ufw`
- `sudo ufw enable`
- `sudo ufw allow 4242`
- `sudo ufw status`

[!note]
Donde puedo ver los logs del sudo?





### Script

about memory usage:

free --mega | grep Mem | awk '{printf("Memory Usage: %i/%i %.2f%%", $4, $2, 100*$4/$2)}'

df --total -h | grep total | awk {'printf("Disk usage %s/%s (%s)", $3, $2, $5)'}

## References

ABOUT OS
[Why Debian](https://www.debian.org/doc/manuals/debian-handbook/sect.why-debian.en.html#id-1.5.8.5)

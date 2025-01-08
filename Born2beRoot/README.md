# Born2beRoot

In this project I will set up a functional, secure and efficient server following some specific rules.

## Progress

| Research | Program | Test | Doc |
| -------- | ------- | ---- | --- |
| 1        | 4       |      |     |

| Date     | Hours | Progress                                        |
| -------- | ----- | ----------------------------------------------- |
| 06-01-25 | 5     | Doing research and first steps of configuration |
| 08-01-25 | 0.5   | Research                                        |

* TODO: He canviat la contrasenya varies vegades seguides de l'usuari. Tenia entes que havia de passar minim dos dies...

## Resources

[Medium](https://m4nnb3ll.medium.com/my-experience-with-the-born2beroot-project-42-ad19d738ad4f)

[TO READ MOOOOORE](https://github.com/RamonLucio/Born2beRoot)



###

## Logs (What I'm doing)

The first thing of all is to understand what I have to setup.&#x20;

#### What is a virtual server?

A virtual server is a virtual representation of a physical server. Like a physical server, a virtual server includes its own OS and applications. These are kept separate from any other virtual servers running on the physical server.

The process of creating VMs involves installing a lightweight software component called a hypervisor onto a physical server. The hypervisor's job is to enable the physical server to function as a virtualization host. The virtualization host makes the physical server's hardware resources (such as central processing unit (CPU) time, memory, storage and network bandwidth) available to one or more virtual machines.

\[Reference]\([https://www.techtarget.com/whatis/definition/server](https://www.techtarget.com/whatis/definition/server))

To create a virtual server we need an abstraction layer (virtualization software) between the hardware and the software of the physical server.

When doing so, the physical server translates it into one or more virtual machines and each one is assigned a certain amount of hardware resources (memory, CPU, storage, etc) according to the capacity of the physical server.

In this way, instead of using a lot of physical servers to run separately an email system, a database, etc, all those applications can be virtualized in a single server.

> Another advantage that a virtualized server has is its flexibility to migrate virtual machines. What does this mean? That you can move one or more VMs from one server to another without experiencing hardware problems since the VM can be adapted to the new virtualized server resources. There are cases in which you can even copy the virtual machines into USB drivers to move them to other locations.

So, what is a virtual machine? In simple terms, is an operating system or an application environment which is installed in software that emules dedicated hardware. Then, the user doesn´t need the resources of a server or computer exclusively dedicated to run a single OS.

![Virtualisation technology](https://www.masterdc.com/mydata/myuploads/2021/06/virtual.png)

In order for a VM to run Linux and Windows server OSs on the same physical host, the hypervisor must emulate several virtual hardware platforms.

A VM needs something called hypervisor. This special software is capable of full emulation of a PC client and all its hardware resources such as memory, hard disk, etc. This technique allows several virtual machines to share resources.

\[Reference]\([https://www.masterdc.com/blog/what-is-virtual-machine-server-network/](https://www.masterdc.com/blog/what-is-virtual-machine-server-network/))



> This project consists of having you set up your first server by following specific rules.\
> \
> Since it is a matter of setting up a server, you will install the minimum of services. For this reason, a graphical interface is of no use here. It is therefore forbidden to install X.org or any other equivalent graphics server.\
> \
> You must choose as an operating system either the latest stable version of Debian (no testing/unstable), or the latest stable version of Rocky.

#### How to decide the amount of space to use?

&#x20;[About virtualization](https://www.masterdc.com/blog/what-is-virtual-machine-server-network/)

Next, I have to choose wich OS to install. The requisists ask me to choose between Debian, or Rocky. ... TODO: Explain reasons and AppArmor/SELinux apt/aptitude...

Download [Debian](https://www.debian.org/distrib/index.es.html) --> Why debian?? Prepare VM Install things and partitions...



### Setting up the Virtual Machine

The software I'm using is [VirtualBox](https://www.virtualbox.org/manual/) because it was mandatory for the project.

The OS that I choose is [Debian](https://www.debian.org/distrib/) since it was recommended if you were new to system administration.

* To unlock dthe disk use the encryption phrase
* To access root use `su`
* To change the machine's hostname: `hostnamectl set-hostname mymachine`

ABOUT USER AND GROUPS

* To **create a new user** `sudo adduser user_name`
* To **create a new group** `sudo addgroup name_group`
* The list of all the groups is in `/etc/group`
* To visualize a particular group `getent group name_group`
* To **add a user to a group** `sudo adduser user_name group_name`

[Create and delete users](https://serverspace.io/es/support/help/managing-users-on-ubuntu-and-debian/)

ABOUT SSH

* To install OpenSSH (que es estoooo) `sudo apt install openssh-server`
* To check the connection `sudo service ssh status`
* Change the port number in /etc/ssh/ssh\_config and /etc/ssh/sshd\_config and run `sudo service ssh restart` to apply the changes.
* Change **PermitRootLogin no** in sshd\_config to make it more secure against external attacks [more info](https://wiki.debian.org/SSH#Configuration_Options)
* To connect use `ssh user@localhost -p XXXX`
* To disconnect user: `who` to see the connections and then `pkill -9 -t pts/0` \[!NOTE] Se envió la señal -9 que indica matar (KILL) el proceso, la opción -t indica que se basará en un atributo de nombre de terminal y se indica después el nombre de la terminal en si pts/0

ABOUT UFW Uncomplicated Firewall (UFW) is a program for managing a netfilter firewall designed to be easy to use. It uses a command-line interface consisting of a small number of simple commands, and uses iptables for configuration. UFW is available by default in all Ubuntu installations since 8.04 LTS.\[1] UFW has been available by default in all Debian installations since 10. [commands](https://es.wikipedia.org/wiki/Uncomplicated_Firewall)

* To install `sudo apt install ufw`
* To enable it `sudo ufw enable`
* To see the status `sudo ufw status`
* To enable anyone to connect to using the port 4242 `sudo ufw allow 4242`

ABOUT STRONG CONFIGURATIOSN FOR SUDO • Authentication using sudo has to be limited to 3 attempts in the event of an incor- rect password. • A custom message of your choice has to be displayed if an error due to a wrong password occurs when using sudo. • Each action using sudo has to be archived, both inputs and outputs. The log file has to be saved in the /var/log/sudo/ folder. • The TTY mode has to be enabled for security reasons. • For security reasons too, the paths that can be used by sudo must be restricted. Example: /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin

* Create a directory in /var/log/sudo because everything command have to be saved there.
* Create a file in /etc/sudoers.d called sudo\_config and edited like
  * Defaults passwd\_tries=3
  * Defaults badpass\_message="Wrong password!"
  * Defaults logfile="/var/log/sudo/sudo\_config"
  * Defaults log\_input, log\_output
  * Defaults iolog\_dir="/var/log/sudo"
  * Defaults requiretty
  * Defaults secure\_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"

ABOUT PASSWORD To set up a strong password policy, you have to comply with the following require- ments: • Your password has to expire every 30 days. • The minimum number of days allowed before the modification of a password will be set to 2. • The user has to receive a warning message 7 days before their password expires.

* In the file /etc/login.defs:
  * PASS\_MAX\_DAYS 30
  * PASS\_MIN\_DAYS 2
  * PASS\_WARN\_AGE 7 • Authentication using sudo has to be limited to 3 attempts in the event of an incor- rect password.
* In the file /etc/login.defs:
  * LOGIN\_RETRIES 3 • Your password must be at least 10 characters long. It must contain an uppercase letter, a lowercase letter, and a number. Also, it must not contain more than 3 consecutive identical characters. • The password must not include the name of the user. • The following rule does not apply to the root password: The password must have at least 7 characters that are not part of the former password. • Of course, your root password has to comply with this policy.
* Install a library to change some configurations for the password `apt install libpam-pwquality`
* In the file /etc/pam.d/common-password:
  * In the line password requisite add: minlen=10 (minim number of characters) ucredit=-1 (min 1 uppercase letter) dcredit=-1 (min 1 digit) lcredit=-1 (min 1 lowercase letter) maxrepeat=3 (max 3 same characters) reject\_username (not username) difok=7 (at least 7 characters different from old password) enforce\_for\_root (also to apply for root)
* To see the current user password politics `sudo chage -l <username>`
* To change the minimum days and maximum days use the flag `-m` or `-M`

## Information I learned

### What is a virtual server? What I'm building?



### How to choose the amount of space needed in the VM?

### What is LVM?

### What is sudo?

`sudo` is a command-line tool in Unix-based systems that allosw a user to execute commands with superuser (administrator) privileges. The name stands for "superuser do".

Advantages of sudo over root:

* **Reduces risk of major mistakes**: Users operate with normal permissions most of the time, which protects the system from accidental or harmful commands.
* **Tracks command usage**: Every time sudo is used, it is logged (e.g., in /var/log/auth.log on many systems), enabling administrators to monitor actions.
* **Specific permissions**: sudo allows granting access to only certain commands instead of full system access.

Mastering sudo is a fundamental step in this project, where security and proper server management are critical.

Deberás elegir como sistema operativo la última versión estable de Debian (no testing/unstable), o la última versión estable de Rocky.

https://github.com/gemartin99/Born2beroot-Tutorial

TODO Por que uno u otro? Y por que de 64 bits y no de 32?

***

Base Memory. Select the amount of RAM that Oracle VM VirtualBox should allocate every time the virtual machine is started. The amount of memory selected here will be taken away from your host machine and presented to the guest OS, which will report this size as the virtual machines installed RAM. Caution Choose this setting carefully. The memory you give to the VM will not be available to your host OS while the VM is running, so do not specify more than you can spare.

Always ensure that the host OS has enough RAM remaining. If insufficient RAM remains, the system might excessively swap memory to the hard disk, which effectively brings the host system to a standstill.

***

* No entiendo lo del disco duro virtual imagen?? VDI / VHD / VMDK?
* que es la ISO?
* Debes crear al menos 2 particiones cifradas usando LVM. P
* GRY boot loader.

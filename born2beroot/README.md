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

[hostname](https://www.cyberciti.biz/faq/debian-change-hostname-permanently/)&#x20;

### Script

* The architecture of your operating system and its kernel version: `uname -a`

```
Usage: uname [OPTION]...
Print certain system information.  With no OPTION, same as -s.

  -a, --all                print all information, in the following order,
                             except omit -p and -i if unknown:
  -s, --kernel-name        print the kernel name
  -n, --nodename           print the network node hostname
  -r, --kernel-release     print the kernel release
  -v, --kernel-version     print the kernel version
  -m, --machine            print the machine hardware name
  -p, --processor          print the processor type (non-portable)
  -i, --hardware-platform  print the hardware platform (non-portable)
  -o, --operating-system   print the operating system
      --help        display this help and exit
      --version     output version information and exit

```

* The number of physical processors: `grep "physical id" /proc/cpuinfo | uniq | wc -l`

The detailed information about the processors is in the file /proc/cpuinfo. To find out how many physical processors you have, you need to count the lines (using [wc](https://voidnull.es/wc-cuenta-el-numero-de-lineas-palabras-o-caracteres/)), but the way the physical processors are displayed is by it's id, so if the same id appears more than once, that doesn't mean that there are more processors, that is why I use the `uniq` to only count each processor once.

[More info here](https://www.networkworld.com/article/930786/counting-processors-on-your-linux-box.html).

* The number of virtual processors: `grep "processor" /proc/cpuinfo | uniq | wc -l`

Just as the last one, here it counts the virtual processors. You might have more virtual processors than physical ones because your processors are muli-core or hyper-threaded, or both. The way to tell how may cores you have is to look for "cpu cores" in your /proc/cpuinfo file. This line will show up for each virtual processor. If the number of cores shown is less than the number of virtual processors, your system is multi-threading.

* The current available RAM on your server and its utilization rate as a percentage.

\[!Note]

Even tho the subject says the current available RAM, the example looks like it's showing the used one?

[Manual page for free](https://man7.org/linux/man-pages/man1/free.1.html)

## Logs (What I'm doing)

> This project consists of having you set up your first server by following specific rules.\
> \
> Since it is a matter of setting up a server, you will install the minimum of services. For this reason, a graphical interface is of no use here. It is therefore forbidden to install X.org or any other equivalent graphics server.\
> \
> You must choose as an operating system either the latest stable version of Debian (no testing/unstable), or the latest stable version of Rocky.

The first thing to do is to understand what I'm building.&#x20;

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

## [#undefined](./#undefined "mention")

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

# Born2beRoot

In this project I will set up a functional, secure and efficien server following some specific rules.


## Progress
|Research|Program|Test|Doc|
|--------|-------|----|---|
|1       |4      |    |   |

|Date    |Hours|Progress|
|--------|-----|--------|
|06-01-25|5    |Doing research and first steps of configuration|
|08-01-25|0.5  |Research|

- TODO: He canviat la contrasenya varies vegades seguides de l'usuari. Tenia entes que havia de passar minim dos dies... 

## Resources
[Medium](https://m4nnb3ll.medium.com/my-experience-with-the-born2beroot-project-42-ad19d738ad4f)

[TO READ MOOOOORE](https://github.com/RamonLucio/Born2beRoot)

[^1]: [What is a server](https://www.techtarget.com/whatis/definition/server)
[Debian vs Rocky](https://amadla.medium.com/debian-linux-vs-rocky-os-exploring-the-best-choice-for-your-server-dfd6b3d80c1a)
[What is SELinux](https://www.redhat.com/en/topics/linux/what-is-selinux?source=post_page-----dfd6b3d80c1a--------------------------------)
[What is AppArmor](https://apparmor.net/?source=post_page-----dfd6b3d80c1a--------------------------------)
[AppArmor](https://gitlab.com/apparmor/apparmor/-/wikis/GettingStarted)
[apt and aptitude](https://blog.packagecloud.io/know-the-difference-between-apt-and-aptitude/)


## Logs (What I'm doing)
The first thing of all is to understand what I have to setup, and why?
[About virtualization](https://www.masterdc.com/blog/what-is-virtual-machine-server-network/)

... TODO: put here some more information about virtualization and some scheme

Next, I have to choose wich OS to install. The requisists ask me to choose between Debian, or Rocky.
... TODO: Explain reasons and AppArmor/SELinux apt/aptitude...

Download [Debian](https://www.debian.org/distrib/index.es.html) --> Why debian??
Prepare VM
Install things and partitions...

- To unlock dthe disk use the encryption phrase
- To access root use `su` 

- To change the machine's hostname: `hostnamectl set-hostname mymachine`

ABOUT USER AND GROUPS
- To **create a new user** `sudo adduser user_name`
- To **create a new group** `sudo addgroup name_group`
- The list of all the groups is in `/etc/group`
- To visualize a particular group `getent group name_group`
- To **add a user to a group** `sudo adduser user_name group_name`

[Create and delete users](https://serverspace.io/es/support/help/managing-users-on-ubuntu-and-debian/)


ABOUT SSH
- To install OpenSSH (que es estoooo) `sudo apt install openssh-server`
- To check the connection `sudo service ssh status`
- Change the port number in /etc/ssh/ssh_config and /etc/ssh/sshd_config and run `sudo service ssh restart` to apply the changes.
- Change **PermitRootLogin no** in sshd\_config to make it more secure against external attacks [more info](https://wiki.debian.org/SSH#Configuration_Options)


- To connect use `ssh user@localhost -p XXXX`

- To disconnect user: `who` to see the connections and then `pkill -9 -t pts/0`
[!NOTE] Se envió la señal -9 que indica matar (KILL) el proceso, la opción -t indica que se basará en un atributo de nombre de terminal y se indica después el nombre de la terminal en si pts/0

ABOUT UFW
Uncomplicated Firewall (UFW) is a program for managing a netfilter firewall designed to be easy to use. It uses a command-line interface consisting of a small number of simple commands, and uses iptables for configuration. UFW is available by default in all Ubuntu installations since 8.04 LTS.[1] UFW has been available by default in all Debian installations since 10. 
[commands](https://es.wikipedia.org/wiki/Uncomplicated_Firewall)
- To install `sudo apt install ufw`
- To enable it `sudo ufw enable`
- To see the status `sudo ufw status`
- To enable anyone to connect to using the port 4242 `sudo ufw allow 4242`

ABOUT STRONG CONFIGURATIOSN FOR SUDO
• Authentication using sudo has to be limited to 3 attempts in the event of an incor-
rect password.
• A custom message of your choice has to be displayed if an error due to a wrong
password occurs when using sudo.
• Each action using sudo has to be archived, both inputs and outputs. The log file
has to be saved in the /var/log/sudo/ folder.
• The TTY mode has to be enabled for security reasons.
• For security reasons too, the paths that can be used by sudo must be restricted.
Example:
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin

- Create a directory in /var/log/sudo because everything command have to be saved there.
- Create a file in /etc/sudoers.d called sudo_config and edited like 
	- Defaults  passwd_tries=3
	- Defaults  badpass_message="Wrong password!"
	- Defaults  logfile="/var/log/sudo/sudo_config"
	- Defaults  log_input, log_output
	- Defaults  iolog_dir="/var/log/sudo"
	- Defaults  requiretty
	- Defaults  secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"

ABOUT PASSWORD
To set up a strong password policy, you have to comply with the following require-
ments:
• Your password has to expire every 30 days.
• The minimum number of days allowed before the modification of a password will
be set to 2.
• The user has to receive a warning message 7 days before their password expires.
- In the file /etc/login.defs:
	- PASS\_MAX_DAYS 30
	- PASS\_MIN_DAYS 2
	- PASS\_WARN_AGE 7
• Authentication using sudo has to be limited to 3 attempts in the event of an incor-
rect password.
- In the file /etc/login.defs:
	- LOGIN_RETRIES 3
• Your password must be at least 10 characters long. It must contain an uppercase
letter, a lowercase letter, and a number. Also, it must not contain more than 3
consecutive identical characters.
• The password must not include the name of the user.
• The following rule does not apply to the root password: The password must have
at least 7 characters that are not part of the former password.
• Of course, your root password has to comply with this policy.
- Install a library to change some configurations for the password `apt install libpam-pwquality`
- In the file /etc/pam.d/common-password:
	- In the line password requisite add: 
		minlen=10 (minim number of characters)
		ucredit=-1 (min 1 uppercase letter)
		dcredit=-1 (min 1 digit)
		lcredit=-1 (min 1 lowercase letter) 
		maxrepeat=3 (max 3 same characters)
		reject_username (not username)
		difok=7 (at least 7 characters different from old password)
		enforce_for_root (also to apply for root)
		
- To see the current user password politics `sudo chage -l <username>`
- To change the minimum days and maximum days use the flag `-m` or `-M`

## Information I learned

### What is a virtual server? What I'm building?
A virtual server is a virtual representation of a physical server. Like a physical server, a virtual server includes its own OS and applications. These are kept separate from any other virtual servers running on the physical server.

The process of creating VMs involves installing a lightweight software component called a hypervisor onto a physical server. The hypervisor's job is to enable the physical server to function as a virtualization host. The virtualization host makes the physical server's hardware resources (such as central processing unit (CPU) time, memory, storage and network bandwidth) available to one or more virtual machines.[^1]

### How to choose the amount of space needed in the VM?

### What is LVM? 

### What is sudo?
`sudo` is a command-line tool in Unix-based systems that allosw a user to execute commands with superuser (administrator) privileges. The name stands for "superuser do".

Advantages of sudo over root:
- **Reduces risk of major mistakes**: Users operate with normal permissions most of the time, which protects the system from accidental or harmful commands.
- **Tracks command usage**: Every time sudo is used, it is logged (e.g., in /var/log/auth.log on many systems), enabling administrators to monitor actions.
- **Specific permissions**: sudo allows granting access to only certain commands instead of full system access.

Mastering sudo is a fundamental step in this project, where security and proper server management are critical.



Deberás elegir como sistema operativo la última versión estable de Debian (no testing/unstable), o la última versión estable de Rocky.

https://github.com/gemartin99/Born2beroot-Tutorial

TODO Por que uno u otro? Y por que de 64 bits y no de 32?

--------------------

Base Memory. Select the amount of RAM that Oracle VM VirtualBox should allocate every time the virtual machine is started. The amount of memory selected here will be taken away from your host machine and presented to the guest OS, which will report this size as the virtual machines installed RAM. 
Caution
Choose this setting carefully. The memory you give to the VM will not be available to your host OS while the VM is running, so do not specify more than you can spare. 

Always ensure that the host OS has enough RAM remaining. If insufficient RAM remains, the system might excessively swap memory to the hard disk, which effectively brings the host system to a standstill. 


-------
- No entiendo lo del disco duro virtual imagen?? VDI / VHD / VMDK?

- que es la ISO?

- Debes crear al menos 2 particiones cifradas usando LVM. P

- GRY boot loader.



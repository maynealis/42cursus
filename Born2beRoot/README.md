# Born2beRoot

## Requisits

This project consists of having you set up your first server by following specific rules.

Since it is a matter of setting up a server, you will install the minimum of services. For this reason, a graphical interface is of no use here. It is therefore forbidden to install X.org or any other equivalent graphics server.

* [ ] You must choose as an operating system either the latest stable version of Debian (no testing/unstable), or the latest stable version of Rocky.
* [ ] You must create at least 2 encrypted partitions using LVM.
* [ ] A SSH service will be running on the mandatory port 4242 in your virtual machine. For security reasons, it must not be possible to connect using SSH as root.
* [ ] You have to configure your operating system with the UFW (or firewalld for Rocky) firewall and thus leave only port 4242 open in your virtual machine.
* [ ] Set up a strong password policy.
* [ ] Configure sudo.
* [ ] Finally, you have to create a simple script called monitoring.sh. It must be developed in bash.

## Logs (What I'm doing)

{% hint style="warning" %}
What is .vdi? What is the signature and how to compare with diff
{% endhint %}

### Setting up the Virtual Machine

{% hint style="warning" %}
What is a virtual machine and how it works? The purpose of vm?
{% endhint %}

The software I'm using is [VirtualBox](https://www.virtualbox.org/manual/) because it was mandatory for the project.

The OS that I choose is [Debian](https://www.debian.org/distrib/) since it was recommended if you were new to system administration.

{% hint style="info" %}
Why choose Debian over Rocky?
{% endhint %}

> I choose Debian primarily because Rocky is a new release (2021) and there are more community resources on Debian. Additionally Rocky appears to focus more on enterprise environments, whereas Debian offers a more general-purpose approach. Since this is my first time setting up a server, I preferred something simpler, stable and well-supported, which made Debian the better choice for me.

<details>

<summary>About Debian</summary>

* **Stability and Reliability:** Debian is renowned for its rigorous testing processes, ensuring a highly stable and reliable operating system. This makes it a preferred choice for servers and critical applications where uptime is crucial.

- **Extensive Software Repositories:** With access to over 51,000 packages, Debian offers a vast selection of software, providing flexibility and a wide range of applications for various use cases.

* **Community-Driven Development:** Debian's development is driven by a large, active community, ensuring transparency, regular updates, and comprehensive support. This collaborative approach contributes to its robustness and adaptability.

Read more about [Debian](https://www.debian.org/doc/manuals/debian-handbook/sect.why-debian.en.html)

</details>

<details>

<summary>About Rocky</summary>

Rocky Linux is designed to be a bug-for-bug compatible rebuild of Red Hat Enterprise Linux (RHEL), providing a free alternative for users seeking RHEL compatibility without the associated costs.

Rocky Linux's target groups are private businesses and enterprises which need a reliable, user-friendly, and free Linux distribution. It also targets users looking for a viable alternative to CentOS, as it offers similar features.\
Rocky is also a good option for a web server since it is compatible with most control panels and it uses the Red Hat Enterprise Server resources. It can also function as an email server or VPN setup as it performs great in those areas, making it great for medium-sized businesses as well.

Read more about [Rocky](https://phoenixnap.es/kb/what-is-rocky-linux?utm_)

</details>

{% stepper %}
{% step %}
#### Download the last stable version of Debian

[Check the last stable version of Debian](https://www.debian.org/releases/)
{% endstep %}

{% step %}
#### Create a new VM using Oracle VM Virtual Box

<figure><img src="../.gitbook/assets/Screenshot from 2025-01-21 16-14-13.png" alt=""><figcaption></figcaption></figure>
{% endstep %}

{% step %}
#### Run and install Debian with no graphic interface
{% endstep %}
{% endstepper %}

### About SUDO

{% hint style="warning" %}
What is sudo? About the policy password?
{% endhint %}

* From the root with `apt install sudo`.&#x20;
* Reboot

### About user and groups

* To **create a new user** `sudo adduser <user_name>`
* To **create a new group** `sudo addgroup <name_group>`
* The list of all the groups is in `/etc/group`
* To visualize a particular group `getent group <name_group>`
* To **add a user to a group** `sudo adduser <user_name> <group_name>`

[Create and delete users](https://serverspace.io/es/support/help/managing-users-on-ubuntu-and-debian/)

ABOUT PASSWORD&#x20;

* In the file /etc/login.defs:
  * PASS\_MAX\_DAYS 30
  * PASS\_MIN\_DAYS 2
  * PASS\_WARN\_AGE 7&#x20;
* Install a library to change some configurations for the password `apt install libpam-pwquality`
* In the file /etc/pam.d/common-password:
  * In the line password requisite add: minlen=10 (minim number of characters) ucredit=-1 (min 1 uppercase letter) dcredit=-1 (min 1 digit) lcredit=-1 (min 1 lowercase letter) maxrepeat=3 (max 3 same characters) reject\_username (not username) difok=7 (at least 7 characters different from old password) enforce\_for\_root (also to apply for root)
* <mark style="background-color:yellow;">To see the current user password politics</mark> <mark style="background-color:yellow;"></mark><mark style="background-color:yellow;">`sudo chage -l <username>`</mark>
* To change the minimum days and maximum days use the flag `-m` or `-M`

### About SSH

Install openssh-server

* To install OpenSSH:`sudo apt install openssh-server`
* To check the connection: `sudo service ssh status`
* Change the port number in /etc/ssh/ssh\_config and /etc/ssh/sshd\_config and run `sudo service ssh restart` to apply the changes.
* Change **PermitRootLogin no** in sshd\_config to make it more secure against external attacks [more info](https://wiki.debian.org/SSH#Configuration_Options)
* To apply changes: `sudo service ssh restart`
* To connect use `ssh user@localhost -p XXXX`
* To disconnect user: `who` to see the connections and then `pkill -9 -t pts/0`&#x20;
* <mark style="background-color:yellow;">To check:</mark> <mark style="background-color:yellow;"></mark><mark style="background-color:yellow;">`sudo service ssh status`</mark>

{% hint style="info" %}
The signal `-9` (KILL) was sent to terminate the process. The `-t` option indicates that the action is based on a terminal attribute, and the name of the terminal, in this case, `pts/0`, is specified afterward.\
A terminal like`pts/0` represents a virtual or pseudo-terminal session in a Unix-like system, often associated with a user session or a shell.
{% endhint %}

### About UFW

Uncomplicated Firewall (UFW) is a program for managing a netfilter firewall designed to be easy to use. It uses a command-line interface consisting of a small number of simple commands, and uses iptables for configuration. UFW is available by default in all Ubuntu installations since 8.04 LTS.\[1] UFW has been available by default in all Debian installations since 10. [commands](https://es.wikipedia.org/wiki/Uncomplicated_Firewall)

* To install `sudo apt install ufw`
* To enable it `sudo ufw enable`
* To see the status `sudo ufw status`
* To enable anyone to connect to using the port 4242 `sudo ufw allow 4242`
* <mark style="background-color:yellow;">To chek:</mark> <mark style="background-color:yellow;"></mark><mark style="background-color:yellow;">`sudo service ufw status`</mark><mark style="background-color:yellow;">and</mark> <mark style="background-color:yellow;"></mark><mark style="background-color:yellow;">`sudo ufw status`</mark>



* To change the machine's hostname: `hostnamectl set-hostname mymachine`

### About SUDO

* Create a directory in /var/log/sudo because everything command have to be saved there.
* Create a file in /etc/sudoers.d called sudo\_config and edited like
  * Defaults passwd\_tries=3
  * Defaults badpass\_message="Wrong password!"
  * Defaults logfile="/var/log/sudo/sudo\_config"
  * Defaults log\_input, log\_output
  * Defaults iolog\_dir="/var/log/sudo"
  * Defaults requiretty
  * Defaults secure\_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"



### Script

<table data-full-width="true"><thead><tr><th width="199">Display information</th><th width="193">My solution</th><th>Explanation</th></tr></thead><tbody><tr><td>The architecture of your operating system and its kernel version.</td><td><code>uname -a</code></td><td><pre><code>Usage: uname [OPTION]...
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
</code></pre></td></tr><tr><td>The number of physical processors.</td><td><code>grep "physical id" /proc/cpuinfo | uniq | wc -l</code></td><td>The detailed information about the processors is in the file /proc/cpuinfo. To find out how many physical processors you have, you need to count the lines (using <a href="https://voidnull.es/wc-cuenta-el-numero-de-lineas-palabras-o-caracteres/">wc</a>), but the way the physical processors are displayed is by it's id, so if the same id appears more than once, that doesn't mean that there are more processors, that is why I use the uniq to only count each processor once.<br><a href="https://www.networkworld.com/article/930786/counting-processors-on-your-linux-box.html">More info here</a></td></tr><tr><td>The number of virtual processors.</td><td><code>grep "processor" /proc/cpuinfo | uniq | wc -l</code></td><td>Just as the last one, here it counts the virtual processors. You might have more virtual processors than physical ones because your processors are muli-core or hyper-threaded, or both. The way to tell how may cores you have is to look for "cpu cores" in your /proc/cpuinfo file. This line will show up for each virtual processor. If the number of cores shown is less than the number of virtual processors, your system is multi-threading.</td></tr><tr><td>The current available RAM on your server and its utilization rate as a percentage.</td><td><code>free --mega | grep Mem | awk '{printf("%i/%iMB (%.2f%%)", $4, $2, 100*$4/$2)}'</code></td><td><p></p><p><a href="https://man7.org/linux/man-pages/man1/free.1.html">free</a> displays the total amount of free and used physical and swap memory in the system, as well as the buffers and caches used by the kernel. The information is gathered by parsing /proc/meminfo. The displayed columns are:</p><pre><code>   total  Total usable memory (MemTotal and SwapTotal in
          /proc/meminfo). This includes the physical and swap memory
          minus a few reserved bits and kernel binary code.

   used   Used or unavailable memory (calculated as total -
          available)

   free   Unused memory (MemFree and SwapFree in /proc/meminfo)

   shared Memory used (mostly) by tmpfs (Shmem in /proc/meminfo)

   buffers
          Memory used by kernel buffers (Buffers in /proc/meminfo)

   cache  Memory used by the page cache and slabs (Cached and
          SReclaimable in /proc/meminfo)

   buff/cache
          Sum of buffers and cache

   available
          Estimation of how much memory is available for starting
          new applications, without swapping. Unlike the data
          provided by the cache or free fields, this field takes
          into account page cache and also that not all reclaimable
          memory slabs will be reclaimed due to items being in use
          (MemAvailable in /proc/meminfo, available on kernels 3.14,
          emulated on kernels 2.6.27+, otherwise the same as free)
</code></pre></td></tr><tr><td>The current available storage on your server and its utilization rate as a percentage.</td><td><code>df --total -h | grep total | awk '{printf("%s/%s (%i%%)", $4, $2, $4/$2*100)}'</code></td><td><p><a href="https://man7.org/linux/man-pages/man1/df.1.html">df</a> displays the amount of space available on the file system containing each file name argument. If no file name is given, the space available on all currently mounted file systems is shown. Space is shown in 1K blocks by default, unless the environment variable POSIXLY_CORRECT is set, in which case 512-byte blocks are used.</p><pre><code>   -h, --human-readable
          print sizes in powers of 1024 (e.g., 1023M)
   --total
          elide all entries insignificant to available space, and
          produce a grand total
</code></pre><p><a href="https://geekland.eu/uso-del-comando-awk-en-linux-y-unix-con-ejemplos/">awk</a></p></td></tr><tr><td>The current utilization rate of your processors as a percentage.</td><td><code>top -bn1 | grep "%Cpu" | awk -F',' '{print($4)}' | awk '{printf("%d%%", 100 - $1)}'</code></td><td><p></p><p><a href="https://man7.org/linux/man-pages/man1/top.1.html">top</a> -b, --batch Starts top in Batch mode, which could be useful for sending output from top to other programs or to a file. In this mode, top will not accept input and runs until the iterations limit you've set with the ‘-n’ command-line option or until killed.</p><pre><code>       us : time running un-niced user processes
       sy : time running kernel processes
       ni : time running niced user processes
       id : time spent in the kernel idle handler
       wa : time waiting for I/O completion
       hi : time spent servicing hardware interrupts
       si : time spent servicing software interrupts
       st : time stolen from this vm by the hypervisor
</code></pre></td></tr><tr><td>The date and time of the last reboot.</td><td><code>who -b</code></td><td>The command who shows who is logged on, and the flag -b (--boot) shows the last time the system boot.</td></tr><tr><td>Whether LVM is active or not.</td><td><code>if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo "yes"; else echo "no"; fi</code></td><td></td></tr><tr><td>The number of active connections.</td><td><code>ss -s | grep "TCP:" | awk '{print($4)}' | tr -d ','</code></td><td></td></tr><tr><td>The number of users using the server.</td><td><code>users | wc -w</code></td><td></td></tr><tr><td>The IPv4 address of your server and its MAC (Media Access Control) address. </td><td><code>hostname -I</code><br><code>ip link | grep "ether" | awk '{print($2)}'</code></td><td></td></tr><tr><td>The number of commands executed with the sudo program.</td><td><code>journalctl | grep sudo | wc -l</code></td><td></td></tr></tbody></table>

To change the script time: `sudo crontab -u root -e`

To stop cron: `sudo systemctl stop cron`or use disable/enable to make it not start on reboot.

### What is LVM?

### What is sudo?

`sudo` is a command-line tool in Unix-based systems that allosw a user to execute commands with superuser (administrator) privileges. The name stands for "superuser do".

Advantages of sudo over root:

* **Reduces risk of major mistakes**: Users operate with normal permissions most of the time, which protects the system from accidental or harmful commands.
* **Tracks command usage**: Every time sudo is used, it is logged (e.g., in /var/log/auth.log on many systems), enabling administrators to monitor actions.
* **Specific permissions**: sudo allows granting access to only certain commands instead of full system access.

Mastering sudo is a fundamental step in this project, where security and proper server management are critical.

## What I learned

### What is a virtual machine?

A **virtual machine (VM)** is a software-based emulation of a physical computer. It operates as an independent environment, capable of running its own operating system and applications just like a real computer. A VM is created and managed by a **hypervisor**, which handles the sharing of physical hardware resources between the host machine and the VM(s).

The hypervisor is the key software that enables virtualization. It abstracts the underlying hardware of the host system, allowing multiple VMs to share these resources.

The hypervisor allocates resources such as CPU, memory, storage, and network interfaces from the host to the VM. These resources can be adjusted dynamically in many cases.

#### Uses

* Run multiple servers on a single physical machine, reducing hardware costs and space usage in data centers.
* Test applications across different operating systems.
* To try software in an isolated environment, or to try viruses.
* Access different OS environments.

### Difference between apt and aptitude

<details>

<summary>What is apt?</summary>

**Apt** or **Advanced Packaging Tool** is a free and open source software which gracefully handles software installation and removal. Initially it was designed for Debian’s `.deb` packages.

**Apt** is whole command line with no GUI. Whenever invoked from command line along with specifying the name of package to be installed, it finds that package in configured list of sources specified in **‘/etc/apt/sources.list’** along with the list of dependencies for that package and sorts them and automatically installs them along with the current package thus letting user not to worry of installing dependencies.

[Read more](https://www.tecmint.com/difference-between-apt-and-aptitude/)

</details>

<details>

<summary>What is aptitude?</summary>

**Aptitude** is front-end to advanced packaging tool which adds a user interface to the functionality, thus allowing a user to interactively search for a package and install or remove it. Initially created for Debian, Aptitude extends its functionality to RPM based distributions as well.

In all, **Aptitude** is a higher-level package managers that abstracts low level details, and can operate in both text-based interactive UI mode and even in command line non-interactive mode.

</details>

| apt                                                                                                                                       | aptitude                                                                                                                                                |
| ----------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Operates through command-line commands without an interactive menu system                                                                 | Offers a text-based interactive user interface (TUI) powered by `ncurses`, allowing users to navigate and manage packages in a menu-driven environment. |
|                                                                                                                                           | Interactive conflict resolution                                                                                                                         |
| Handles dependencies effectively for standard operations but lacks the advanced conflict resolution suggestions that `aptitude` provides. | Robust dependency resolution capabilities. It can suggest multiple solutions when conflicts arise                                                       |

### What is AppArmor

AppArmor ("Application Armor") is a Linux kernel security module that allows the system administrator to restrict programs' capabilities with per-program profiles. Profiles can allow capabilities like network access, raw socket access, and the permission to read, write, or execute files on matching paths. AppArmor supplements the traditional Unix [discretionary access control](https://en.wikipedia.org/wiki/Discretionary_access_control) (DAC) model by providing [mandatory access control](https://en.wikipedia.org/wiki/Mandatory_access_control) (MAC).

In computer security, mandatory access control (MAC) refers to a type of access control by which a secured environment (e.g., an operating system or a database) constrains the ability of a _subject_ or _initiator_ to access or modify on an _object_ or _target_. In the case of operating systems, the subject is a process or thread, while objects are files, directories, [TCP](https://en.wikipedia.org/wiki/Transmission_Control_Protocol)/[UDP](https://en.wikipedia.org/wiki/User_Datagram_Protocol) ports, shared memory segments, or IO devices. Subjects and objects each have a set of security attributes. Whenever a subject attempts to access an object, the operating system kernel examines these security attributes, examines the authorization rules (aka _policy_) in place, and decides whether to grant access.

In mandatory access control, the security policy is centrally controlled by a policy administrator and is guaranteed (in principle) to be enforced for all users. Users cannot override the policy and, for example, grant access to files that would otherwise be restricted. By contrast, [discretionary access control](https://en.wikipedia.org/wiki/Discretionary_access_control) (DAC), which also governs the ability of subjects to access objects, allows users the ability to make policy decisions or assign security attributes.

[Read more.](https://en.wikipedia.org/wiki/AppArmor)





## Questions

* No entiendo lo del disco duro virtual imagen?? VDI / VHD / VMDK?
* que es la ISO?
* Debes crear al menos 2 particiones cifradas usando LVM. P
* GRY boot loader.
* TODO: He canviat la contrasenya varies vegades seguides de l'usuari. Tenia entes que havia de passar minim dos dies...

## Resources

Some pre-research:

* [What is a server](https://www.techtarget.com/whatis/definition/server)
* [About virtualization](https://www.masterdc.com/blog/what-is-virtual-machine-server-network/)

Tutorials:

* [Tutorial from gemartin](https://github.com/gemartin99/Born2beroot-Tutorial) (in Spanish)
* [Tutorial with more explanations](https://github.com/RamonLucio/Born2beRoot) (in English)
* [Medium](https://m4nnb3ll.medium.com/my-experience-with-the-born2beroot-project-42-ad19d738ad4f)

[hostname](https://www.cyberciti.biz/faq/debian-change-hostname-permanently/)

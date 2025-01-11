# Previous research

## What is a virtual server?

A virtual server is a virtual representation of a physical server. Like a physical server, a virtual server includes its own OS and applications. These are kept separate from any other virtual servers running on the physical server.

The process of creating VMs involves installing a lightweight software component called a hypervisor onto a physical server. The hypervisor's job is to enable the physical server to function as a virtualization host. The virtualization host makes the physical server's hardware resources (such as central processing unit (CPU) time, memory, storage and network bandwidth) available to one or more virtual machines.

\[[Read more](https://www.techtarget.com/whatis/definition/server)]

To create a virtual server we need an abstraction layer (virtualization software) between the hardware and the software of the physical server.

When doing so, the physical server translates it into one or more virtual machines and each one is assigned a certain amount of hardware resources (memory, CPU, storage, etc) according to the capacity of the physical server.

In this way, instead of using a lot of physical servers to run separately an email system, a database, etc, all those applications can be virtualized in a single server.

> Another advantage that a virtualized server has is its flexibility to migrate virtual machines. What does this mean? That you can move one or more VMs from one server to another without experiencing hardware problems since the VM can be adapted to the new virtualized server resources. There are cases in which you can even copy the virtual machines into USB drivers to move them to other locations.

So, what is a virtual machine? In simple terms, is an operating system or an application environment which is installed in software that emules dedicated hardware. Then, the user doesn´t need the resources of a server or computer exclusively dedicated to run a single OS.

![Virtualisation technology](https://www.masterdc.com/mydata/myuploads/2021/06/virtual.png)

In order for a VM to run Linux and Windows server OSs on the same physical host, the hypervisor must emulate several virtual hardware platforms.

A VM needs something called hypervisor. This special software is capable of full emulation of a PC client and all its hardware resources such as memory, hard disk, etc. This technique allows several virtual machines to share resources.

\[[Read more](https://www.masterdc.com/blog/what-is-virtual-machine-server-network/)]


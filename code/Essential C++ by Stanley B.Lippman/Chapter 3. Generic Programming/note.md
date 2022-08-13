@[TOC]([NOTE] PuTTYgen generate PublicKey and Configure SSH on RedHat7)

# Use PuTTYgen generate PublicKey and PrivateKey

using PuTTYgen generate a pair of RSA PublicKey and PrivateKey

## Step 1: generate and save PublicKey and PrivateKey

[note]Please generate some randomness by moving the mouse over the blank area.
 1. mouse left click the **"Generate"** botton;
 2. change the **"Key comment"** to **userdefine**-rsa-key-yyyymmdd；
 3. mouse click the **"Save private key"** botton, click **Yes** to save ***.ppk** file,**Not** save in the CN_zh characters path,file name **Not** need to setting sufix-filename to ***.ppk**,system automaticlly setting;
 4. mouse click the **"Conversions"-> "Export OpenSSH key"**,click **Yes** to save ***.pem**file,**NOTE** need manually setting sufix-filename to ***.pem**;
 5. Copy the contain in **"Public key for pasting into OpenSSH authorized_keys file:"**,such as:**"ssh-rsa XXXX+XXXX+XXXX+XXXX+XXXX+XXXX ==usedefine==-rsa-key-yyyymmdd"** to the system clipboard.

## Step 2: Create user and  change SSH configure
1. mouse click the **"Category"-> "Session"->"HostName(or IP address)** input window,enter the Public IP;**Not** click the **"Open"** botton or press the **"Enter"** in keyboard;
2. mouse click the **"Category"->"Connection"->"SSH"->"Auth"->"Browse..."**,select the associate ***.ppk** file in system path;

## Step 3:configure SSH Server in Redhat Linux
1. add username for Redhat
	> $ sudo /usr/sbin/useradd username_demo

2. switch user to this new username
	> $ sudo su - username_demo

3. copy and paste the PublicKey to the file: **~/.ssh/authorized_keys**
	> $ vim ~/.ssh/authorized_keys

	note, use **vi** to paste the PublicKey:
		1. press <kbd>i</kbd> enter the **insert** mode;
		2. press <kbd>Shift</kbd>+<kbd>Insert</kbd> to paste the PublicKeys from PuTTY in windows10 ;
		3. press <kbd>Esc</kbd> to exit **insert** mode;
		4. press **:wq!** to write to file + quit vi + force execute.
	
	change file to root read/write only
	> $ chmod 600 ~/.ssh/authorized_keys
4. enable username to the allow list in **sshd_config** file
	> $ sudo vim /etc/ssh/sshd_config

	add **"AllowUsers username_demo "** in the **sshd_config** file last line, such as:
	```
	# Exampl mple of overriding settings on a per-user basis
	#Match User anoncvs
	#       X11Forwarding no
	#       AllowTcpForwarding no
	#       PermitTTY no
	#       ForceCommand cvs server
	
	# Allow username list
	AllowUsers username_demo
	```
## Step 4: vncserver multiple users
1. create the associate config file for each username:
	The number in the symbol **@** is the vncserver dispaly number, the port 5900 + sequence number(such as 5901). each run ** systemctl start vncserver@:1**,start a new vncserver port increase 1 in the before.
	> $ cp /lib/systemd/system/vncserver@.service /etc/systemd/system/vncserver@:1.service
	> $ cp /lib/systemd/system/vncserver@.service /etc/systemd/system/vncserver@:2.service
2. replace the **<USER>** in the Template file:
	1. setting the vncserver@:1.service for the **root**
		> $ vim /etc/systemd/system/vncserver@:1.service

		press **":%s/\<USER\>/root/g"**, to replace all **\<USER\>** in this file, and press **":x"** to save and quit **vi**.
	2. the same operator to the **username_demo** in the **"/etc/systemd/system/vncserver@:2.service"** file.

3. start the service:
	type below command in terminal:
	```bash
	sudo systemctl daemon-reload
	sudo systemctl start vncserver@:1 # start a vncserver display for user: root
	sudo systemctl start vncserver@:2 # start a vncserver display for user: username_demo
	```

	other, vncserver common command:
	> vncserver -list
	> vncpasswd
	> vncserver -kill :1

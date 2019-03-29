Debian
======

This directory contains files used to package cobraxd/cobrax-qt
for Debian-based Linux systems. If you compile cobraxd/cobrax-qt yourself, there are some useful files here.

## cobrax: URI support ##

cobrax-qt.desktop (Gnome / Open Desktop)

To install:

	sudo desktop-file-install cobrax-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your cobrax-qt binary to `/usr/bin`
and the `../../share/pixmaps/cobrax128.png` to `/usr/share/pixmaps`

cobrax-qt.protocol (KDE)
ARCH := $(shell uname -s)
ifeq ($(ARCH), Linux)
MYSQL_CONFIG = /usr/bin/mysql_config
else ifeq ($(ARCH), Darwin)
MYSQL_CONFIG = /opt/local/bin/mysql_config5
endif
#INSTALL_PATH = /usr/local/bin

main: main.c
	gcc -o main main.c `$(MYSQL_CONFIG) --cflags --libs`
#install:main
#	mv main $(INSTALL_PATH)

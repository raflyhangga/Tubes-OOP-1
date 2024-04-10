# Tubes-OOP-1


## How to Run

### Install Dependencies
Make sure wsl is installed, then run this with wsl.
```
sudo apt install gcc make cmake qtbase5-dev
```

### Build and Run Executable
```
make
```
### Build Executable
```
make buildcli
```
### Run Executable
```
make runcli
```
### Initialize GUI and Unit Test
Execute this only once
```
chmod 0700  /run/user/1000/
make initbuild
```
### Build test
Execute this everytime a file has modification
```
make buildtest
```
### Run test
```
make runtest
```
### Build GUI
Execute this everytime a file has modification
```
make buildgui
```
### Run GUI
```
make rungui
```

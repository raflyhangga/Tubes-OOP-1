# <h1 style="text-align: center">Tugas Besar Pemrograman Berbasis Objek IF2211<h1/>

## 🛸 Project Overview
Welcome to the repository for our ***Object-Oriented Programming (IF2211)*** course project at Institut Teknologi Bandung. This project showcases our skills in building a *CLI / GUI game* that simulates the roles of a farmer, rancher, and mayor.

## 📝 Requirements
To run this project smoothly, ensure that your device has a **UNIX environment**. For Windows users, you'll need to utilize [Windows Subsystem For Linux (WSL)](https://learn.microsoft.com/en-us/windows/wsl/install) to run the project.

## 🏃🏻‍♂️ How to Run
❗KEEP IN MIND❗ that all of the following script should be run in an **UNIX Environment**.

### Install Dependencies
For the initial setup, execute the following command to install necessary dependencies:
```
sudo apt install gcc make cmake qtbase5-dev
```

For setting up the Graphical User Interface and Unit Tests, execute:
```
chmod 0700  /run/user/1000/
make initbuild
```
### 🛠️ Build and Run Executable
To build and run the program, use the following command:
```
make
```
#### Build Executable (CLI Mode)
If you prefer only to build the program in CLI mode, run:
```
make buildcli
```
#### Run Executable (CLI Mode)
To directly run the program in CLI mode, use:
```
make runcli
```
#### Build GUI
For building the program in GUI mode, use:
```
make buildgui
```
#### Run GUI
Finally, to run the program in GUI mode, execute:

```
make rungui
```
### 📋 Build and Run Test
After any file modifications, rebuild the tests with:
```
make buildtest
```
To run the unit tests, execute:
```
make runtest
```
# 🤵🏻 Contributors
Appearance in order of ascending NIM:
| Contributors                     	| NIM      	|
|----------------------------------	|----------	|
| Raden Rafly Hanggaraksa Budiarto 	| 13522014 	|
| Moh Fairuz Alauddin Yahya        	| 13522057 	|
| Nyoman Ganadipa Narayana         	| 13522066 	|
| Dhafin Fawwaz Ikramullah         	| 13522084 	|
| Rayhan Fadhlan Azka              	| 13522095 	|
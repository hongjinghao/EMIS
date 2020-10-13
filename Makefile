CC=g++
FLAG=-Wall -Werror
BIN=emis
OBJ=main.o emis.o manager_view_impl.o manager_ctrl_impl.o manager_mode_impl.o manager.o service_view_impl.o service_ctrl_impl.o service_mode_impl.o department.o employee.o tools.o md5.o

all:$(OBJ)
	$(CC) $(OBJ) -o $(BIN)

%.o:%.cpp
	$(CC) $(FLAG) -c $?

clean:
	del $(OBJ) *.h.gch

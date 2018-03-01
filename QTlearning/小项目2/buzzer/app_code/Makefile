SRC =${wildcard *.c}
OBJ =${patsubst %.c,%.o,$(SRC)}
TARGET = buzzer
CROSS = arm-linux-
CC =$(CROSS)gcc
.phony:clean echo
$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ) $(LIBM) $(LDLIBS) $(LIBGCC) -lm
clean:
	$(RM)	$(OBJ)  $(TARGET) *.elf *.gdb 
echo:
	@echo $(OBJ) $(TARGET)		
